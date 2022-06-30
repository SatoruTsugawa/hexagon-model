include "main-prop.edp"
int simnumber=0;
int seed=0;
randinit(seed); 

string h0,h00,h001,h000,h0001,h1,h11,h2,h3,h4;
real[int] colors=(0.5e6:2e5:9e6);

// define the geometric variables and parameters
real psizex=5,psizey=10;

real step=0;

// compute the mesh
border box1(t=-1,psizex){x=t;y=-1;label=10000;} // the box for the plot
border box2(t=-1,psizex){x=t;y=psizey;label=10000;}
border box3(t=-1,psizey){x=psizex;y=t;label=10000;}
border box4(t=-1,psizey){x=-1;y=t;label=10000;}

int Dirichlet=1; //Fixed boundary
int Free=2; //Free boundary
int Neumann=3; //Force-added boundary

//cell aspect ratio
real asp=1.0;

border a11(t=0,0.0001){x=asp*cos(pi/6)*t;y=sin(pi/6)*t;label=Neumann;} 
border a12(t=0.0001,1){x=asp*cos(pi/6)*t;y=sin(pi/6)*t;label=Neumann;} 
border a2(t=0,1){x=asp*cos(pi/6);y=t+sin(pi/6);label=Neumann;} 
border a3(t=0,0.95){x=asp*(cos(pi/6)+cos(pi*5/6)*t);y=1+sin(pi/6)+sin(5*pi/6)*t;label=Neumann;} 
border a41(t=0.95,1){x=asp*(cos(pi/6)+cos(pi*5/6)*t);y=1+sin(pi/6)+sin(5*pi/6)*t;label=Neumann;} 
border a42(t=0,0.05){x=asp*(cos(pi*7/6)*t);y=1+2*sin(pi/6)+sin(7*pi/6)*t;label=Neumann;} 
border a5(t=0.05,1){x=asp*(cos(pi*7/6)*t);y=1+2*sin(pi/6)+sin(7*pi/6)*t;label=Neumann;} 
border a6(t=0,1){x=asp*(cos(pi*7/6));y=1+sin(pi/6)-t;label=Neumann;} 
border a71(t=0,0.9999){x=asp*(cos(pi*7/6)+cos(pi*11/6)*t);y=sin(pi/6)+sin(11*pi/6)*t;label=Neumann;} 
border a72(t=0.9999,1){x=asp*(cos(pi*7/6)+cos(pi*11/6)*t);y=sin(pi/6)+sin(11*pi/6)*t;label=Neumann;} 

//slit aspect ratio
//real sasp=1.4;
//real rx = 0.030;
//real ry = 0.15;
//real ry = 0.144;
//real ry = 0.138;
//real ry = 0.132;
//real ry = 0.126;
//real ry = 0.12001;
//real ry = 0.114;
//real ry = 0.108;
//real ry = 0.102;
//real ry = 0.096;
//real ry = 0.090;
//real ry = 0.084;
//real ry = 0.078;
//real ry = 0.072;
//real ry = 0.066;
//real ry = 0.060;
//real ry = 0.054;
//real ry = 0.048;
//real ry = 0.042;
//real ry = 0.036;
//real ry = 0.030;
//real rx = 0.15*0.030/ry;

//number of slits
//string ccc="caseA1-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA2-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(pi)+rx*cos(2*pi*t);y=1+0.5*sin(pi)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA3-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/3)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/3)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/3)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/3)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA4-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/4)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/4)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/4)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/4)+ry*sin(2*pi*t);label=Free;}
//border b5(t=0,1){x=0+0.5*cos(6*pi/4)+rx*cos(2*pi*t);y=1+0.5*sin(6*pi/4)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA5-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/5)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/5)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/5)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/5)+ry*sin(2*pi*t);label=Free;}
//border b5(t=0,1){x=0+0.5*cos(6*pi/5)+rx*cos(2*pi*t);y=1+0.5*sin(6*pi/5)+ry*sin(2*pi*t);label=Free;}
//border b6(t=0,1){x=0+0.5*cos(8*pi/5)+rx*cos(2*pi*t);y=1+0.5*sin(8*pi/5)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA6-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/6)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/6)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/6)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/6)+ry*sin(2*pi*t);label=Free;}
//border b5(t=0,1){x=0+0.5*cos(6*pi/6)+rx*cos(2*pi*t);y=1+0.5*sin(6*pi/6)+ry*sin(2*pi*t);label=Free;}
//border b6(t=0,1){x=0+0.5*cos(8*pi/6)+rx*cos(2*pi*t);y=1+0.5*sin(8*pi/6)+ry*sin(2*pi*t);label=Free;}
//border b7(t=0,1){x=0+0.5*cos(10*pi/6)+rx*cos(2*pi*t);y=1+0.5*sin(10*pi/6)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA7-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/7)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/7)+ry*sin(2*pi*t);label=Free;}
//border b5(t=0,1){x=0+0.5*cos(6*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(6*pi/7)+ry*sin(2*pi*t);label=Free;}
//border b6(t=0,1){x=0+0.5*cos(8*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(8*pi/7)+ry*sin(2*pi*t);label=Free;}
//border b7(t=0,1){x=0+0.5*cos(10*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(10*pi/7)+ry*sin(2*pi*t);label=Free;}
//border b8(t=0,1){x=0+0.5*cos(12*pi/7)+rx*cos(2*pi*t);y=1+0.5*sin(12*pi/7)+ry*sin(2*pi*t);label=Free;}
//string ccc="caseA8-0";
//border b2(t=0,1){x=0+0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
//border b3(t=0,1){x=0+0.5*cos(2*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(2*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b4(t=0,1){x=0+0.5*cos(4*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(4*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b5(t=0,1){x=0+0.5*cos(6*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(6*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b6(t=0,1){x=0+0.5*cos(8*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(8*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b7(t=0,1){x=0+0.5*cos(10*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(10*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b8(t=0,1){x=0+0.5*cos(12*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(12*pi/8)+ry*sin(2*pi*t);label=Free;}
//border b9(t=0,1){x=0+0.5*cos(14*pi/8)+rx*cos(2*pi*t);y=1+0.5*sin(14*pi/8)+ry*sin(2*pi*t);label=Free;}

//slit area
//string ccc="caseB-10";
//real rx = 0.030;
//real ry = 0.15;
//real rx = 0.032;
//real rx = 0.034;
//real rx = 0.036;
//real rx = 0.038;
//real rx = 0.040;
//real rx = 0.042;
//real rx = 0.044;
//real rx = 0.046;
//real rx = 0.048;
real rx = 0.050;
real ry = (0.15/0.03)*rx;


//file name
string ccc="case-5G-1";
//real ry = 0.15;
//real rx = 0.15*0.030/ry;

border b2(t=0,1){x=0+asp*0.5*cos(0.0)+rx*cos(2*pi*t);y=1+0.5*sin(0.0)+ry*sin(2*pi*t);label=Free;}
border b3(t=0,1){x=0+asp*0.5*cos(pi/2)+rx*cos(2*pi*t);y=1+0.5*sin(pi/2)+ry*sin(2*pi*t);label=Free;}
border b5(t=0,1){x=0+asp*0.5*cos(pi)+rx*cos(2*pi*t);y=1+0.5*sin(pi)+ry*sin(2*pi*t);label=Free;}
border b6(t=0,1){x=0+asp*0.5*cos(3*pi/2)+rx*cos(2*pi*t);y=1+0.5*sin(3*pi/2)+ry*sin(2*pi*t);label=Free;}

//center of coordinate is fixed
border c1(t=0,1){x=0.0+0.02*cos(2*pi*t);y=1.0+0.02*sin(2*pi*t);label=Dirichlet;}

mesh Th=buildmesh(a11(1)+a12(14)+a2(15)+a3(14)+a41(1)+a42(1)+a5(14)+a6(15)+a71(14)+a72(1)+b2(-10)+b3(-10)+b5(-10)+b6(-10)+c1(5)); 
//mesh Th=buildmesh(a11(1)+a12(14)+a2(15)+a3(14)+a41(1)+a42(1)+a5(14)+a6(15)+a71(14)+a72(1)+c1(5)); 

mesh box=buildmesh(box1(1)+box3(1)+box2(-1)+box4(-1)); //the box for the plot

//有限要素空間
fespace fbox(box,P2); 
fespace Vh1(Th,P1);
fespace Vh2(Th,[P2,P2]);

Vh2 [u1,u2],[vf1,vf2],[V1,V2],[V01,V02],[V11,V12],[Vf1,Vf2],[u3,u4],[vf3,vf4];
Vh2 [g1,g2]=[0,-100]; //片持ち梁の端に与える力

//plot(Th,wait=1,ps="test.eps");

real p =100000.0;

problem elasticity([u1,u2],[vf1,vf2])=
	int2d(Th)(dW(u,vf))
	-int1d(Th,Neumann)(p*N.x*vf1+p*N.y*vf2)
	+on(Dirichlet,u1=0,u2=0);

elasticity;
	
//Output file
h2 = "../Data/" + "Model1-" + ccc + "-triangle-step0.txt";
ofstream f2(h2);
h0 = "../Data/" + "Model1-" + ccc + "-Stress-test.txt";
ofstream f0(h0);
h00 = "../Data/" + "Model1-" + ccc + "-Strain-test.txt";
ofstream f00(h00);
h001 = "../Data/" + "Model1-" + ccc + "-Strain-test1.txt";
ofstream f001(h001);
h000 = "../Data/" + "Model1-" + ccc + "-Displace-test.txt";
ofstream f000(h000);
h0001 = "../Data/" + "Model1-" + ccc + "-Displace-test1.txt";
ofstream f0001(h0001);
h1 = "../Data/" + "Model1-" + ccc + "-triangle-step1.txt";
ofstream f1(h1);
h11 = "../Data/" + "Model1-" + ccc + "-maxmin.txt";
ofstream f11(h11);

include "CalculateStressStrain.cpp"


if (step==0){
	
include "SaveData.cpp"
}
	Th=movemesh(Th,[x+u1,y+u2]);

step +=1;

if (step==1){

include "SaveData.cpp"
}
