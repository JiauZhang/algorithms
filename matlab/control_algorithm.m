function [sys,x0,str,ts] = control_algorithm(t,x,u,flag)
switch flag,
   case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
   case 3,
    sys=mdlOutputs(t,x,u);
   case {1,2,4,9}
    sys=[];
   otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 5;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1; 
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];
function sys=mdlOutputs(t,x,u)
%% input
x_e = u(1);
y_e = u(2);
theta_e = u(3);
v_d = u(4);
omega_d = u(5);
%% algorithm
k_0 = 1; k_1 = 6; k_2 = 5;
v = -k_1*x_e + v_d * cos(theta_e);
%% \rho(t)
rho_t = 0; 
%% h(t)
h_t = 8 * tanh(x_e*x_e + y_e*y_e) * sin(t);
dh_dt = 8 * tanh(x_e*x_e + y_e*y_e) * cos(t);
dh_dxe = 8 * (1 - (tanh(x_e^2 + y_e^2))^2) * 2 * x_e * sin(t);
dh_dye = 8 * (1 - (tanh(x_e^2 + y_e^2))^2) * 2 * y_e * sin(t);
%% \alpha(t)
alpha = rho_t * h_t;
theta_e_hat = theta_e - alpha;
dalpha_dt = -(abs(v_d) + abs(omega_d)) * alpha + rho_t * dh_dt;
dot_alpha = dalpha_dt + rho_t * (dh_dxe * (v - v_d*cos(theta_e)) + dh_dye * v_d * sin(theta_e));
%% f_1
if theta_e_hat >= 0.0001
    f_1 = (sin(theta_e_hat)*cos(alpha) + (cos(theta_e_hat) - 1) * sin(alpha)) / theta_e_hat;
else
    f_1 = cos(alpha);
end
%% omega
omega = -k_2 * theta_e_hat + omega_d - k_0 * v_d * y_e * f_1 + dot_alpha;
%% output
sys(1)=v;
sys(2)=omega;