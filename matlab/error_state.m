function [sys,x0,str,ts] = error_state(t,x,u,flag)
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
sizes.NumOutputs     = 3;
sizes.NumInputs      = 6;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];
function sys=mdlOutputs(t,x,u)
%% input
x_d = u(1);
y_d = u(2);
theta_d = u(3);
x_cur = u(4);
y_cur = u(5);
theta_cur = u(6);
%% error state
cos_theta = cos(theta_cur);
sin_theta = sin(theta_cur);
x_temp = x_cur - x_d;
y_temp = y_cur - y_d;
theta_temp = theta_cur - theta_d;
x_e = x_temp * cos_theta + y_temp * sin_theta;
y_e = -x_temp * sin_theta + y_temp * cos_theta;
theta_e = theta_temp;
%% output
sys(1)=x_e;
sys(2)=y_e;
sys(3) = theta_e;