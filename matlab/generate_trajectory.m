function [sys,x0,str,ts] = robot(t,x,u,flag)
switch flag,
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
  case 1,
    sys=mdlDerivatives(t,x,u);
   case 3,
    sys=mdlOutputs(t,x,u);
   case {2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 3;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;   
sys = simsizes(sizes);
x0  = [-0.5 0 pi/4];
% x0 = [0.5 0.2 0];
str = [];
ts  = [0 0];
function sys=mdlDerivatives(t,x,u)
v=u(1);
w=u(2);
dx1=v*cos(x(3));
dx2=v*sin(x(3));
dx3=w;

sys(1)=dx1;
sys(2)=dx2;
sys(3)=dx3;
function sys=mdlOutputs(t,x,u)
sys=x;