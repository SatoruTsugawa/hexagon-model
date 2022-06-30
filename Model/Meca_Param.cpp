//////////////////////////////////////////////////
//////////////////////////////////////////////////
//                                              //
//                 Freefem++ script             //
//                                              //
//  author: Mathilde Dumond                     //
//                                              //
//  Supplemental Information of the paper:      //
//  Variable cell growth yields reproducible    //
//  organ development through spatiotemporal    //
//  averaging                                   //
//                                              //
//  Hong et al.                                 //
//  Dev Cell 2016                               //
//                                              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////

// define the number of temporal steps
int step;
//int maxstep=1000;
//int maxstep=60;
int maxstep=100;
//int maxstep=150;
//int maxstep=30;

//output parameter: output dynamics if output==1
int output=0;
//int output=1;

//size of the triangles
//int side=4;
real TriangleSize = 1./20.; // all figures except fig 2H and fig 7D
//real TriangleSize = 1./10.; // all figures except fig 2H and fig 7D
//real TriangleSize = 2./10.; // all figures except fig 2H and fig 7D
//real TriangleSize = side*1./10.; // fig 2H
//real TriangleSize = 1./3.5; // fig 7D

// define the mechanical parameters
//real p=2e4;
real p=10.8e4;
//real p=2.e5;
//real p=(2.5)*100000;
//real p=1.e5;
real nu = 0.45;  // Poisson Coef
// parameter for mechanical properties
real rho = 0.9; //beta
//real rho = 1.0; //beta

// define the parameters of the gaussian distrib of the elasticity
//real ElastMean = 3270000;
real ElastMean = 3270000;
//real ElastSd = 0; // fig 2A; fig 7B

//2000000~3000000‚Å•Ï‚¦‚é
//real ElastSd = 1000000 + 100000*step00; // all figures except fig 2A and fig 7B
real ElastSd = 1200000 + 400000*step00; // all figures except fig 2A and fig 7B
//real ElastSd = 0.0; // all figures except fig 2A and fig 7B
int ElastSd1 = step00; // all figures except fig 2A and fig 7B

real MinElast = 100000;
// how fast is the change from the
// current value to the new random
// value ElastCoelTimeVar = 1 = Full resampling, = 0 = No resampling
//real ElastCoefTimeVar = 1.; // no memory
//real ElastCoefTimeVar = 0.; // full memory

//0~1‚ð10•ªŠ„‚Å•Ï‚¦‚é0.1ŠÔŠu
//real ElastCoefTimeVar = 0.005*step000;
real ElastCoefTimeVar = 0.01+0.02*step000;
//real ElastCoefTimeVar = 0.0;
int ElastCoefTimeVar1 = step000;

// real ElastCoefTimeVar = 0.999;
// real ElastCoefTimeVar = 0.9;
// real ElastCoefTimeVar = 0.5;
// real ElastCoefTimeVar = 0.1;
// real ElastCoefTimeVar = 0.03; 
// real ElastCoefTimeVar = 0.003; 
// real ElastCoefTimeVar = 0.00003; 


// define the anisotropy parameters
//real Anis = 0.25;
real Anis = 0.15;
//real Anis = 0.05;
//real Anis = 0.0;
real Theta = 0; // orientation of the anisotropy

// Growth Front Arrest:
bool frontArrest = 1; // boolean: is the simulation stopping because of the growth front arrest or another factor (MaxArea)
real frontArrHeightIni = 3.; // all figures except fig 7B(ii)and fig 7D
// real frontArrHeightIni = 2.7; // fig 7B(ii); 7D
real frontArrHeightIniSD = 0.; // all figures except fig 7B; fig 7C and fig 7D
//real frontArrHeightIniSD = 0.05; // fig 7B(i)
//real frontArrHeightIniSD = 0.5; // fig 7B(ii)
//real frontArrHeightIniSD = 0.08; // fig 7C
//real frontArrHeightIniSD = 0.15; // fig 7D
// Adding Variation
real fAa = randreal1();
real fAb = randreal1();
real fAheight = max(frontArrHeightIni + sqrt(-2*log(fAa))*cos(2*pi*fAb)*frontArrHeightIniSD, 0.01); // Box-Muller transform
real fAspeed = 0.05; // speed of the growth front arrest towards the bottom

// if the simulation does not end with the growth front arrest
// at which area the simulation ends
//real MaxArea = 40.0; //ŽOŠpŒ`adaptmesh‚È‚µ
//real MaxArea = 20.0;
real MaxArea = 1000.0;

// save/plot the data or not, and the frequency of saving/plotting
int savePic=1;
int picturestep=1;
