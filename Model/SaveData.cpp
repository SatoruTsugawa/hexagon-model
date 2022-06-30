//‰Šútriangleo—Í
if(step==0){
for (int i=0;i<Th.nt;i++){
	for (int j=0;j<3;j++){
		f2   <<
		Th[i][j].x << " " <<
		Th[i][j].y << " " <<
		endl;
	}
	f2   <<
	Th[i][0].x << " " <<
	Th[i][0].y << " " <<
	endl;
f2  << 	 endl;
f2   << 	 endl;
}
}
if(step==1){
/*//Mises stress output
real S1,S2,S3,Stri;
for (int i=0; i<Th.nt; i++) {
//	S1=sqrt(0.5*(Lambda1Stressh(Th[i][0].x,Th[i][0].y)*Lambda1Stressh(Th[i][0].x,Th[i][0].y)+Lambda2Stressh(Th[i][0].x,Th[i][0].y)*Lambda2Stressh(Th[i][0].x,Th[i][0].y)+(Lambda2Stressh(Th[i][0].x,Th[i][0].y)-Lambda1Stressh(Th[i][0].x,Th[i][0].y))*(Lambda2Stressh(Th[i][0].x,Th[i][0].y)-Lambda1Stressh(Th[i][0].x,Th[i][0].y)) ));
//	S2=sqrt(0.5*(Lambda1Stressh(Th[i][1].x,Th[i][1].y)*Lambda1Stressh(Th[i][1].x,Th[i][1].y)+Lambda2Stressh(Th[i][1].x,Th[i][1].y)*Lambda2Stressh(Th[i][1].x,Th[i][1].y)+(Lambda2Stressh(Th[i][1].x,Th[i][1].y)-Lambda1Stressh(Th[i][1].x,Th[i][1].y))*(Lambda2Stressh(Th[i][1].x,Th[i][1].y)-Lambda1Stressh(Th[i][1].x,Th[i][1].y)) ));
//	S3=sqrt(0.5*(Lambda1Stressh(Th[i][2].x,Th[i][2].y)*Lambda1Stressh(Th[i][2].x,Th[i][2].y)+Lambda2Stressh(Th[i][2].x,Th[i][2].y)*Lambda2Stressh(Th[i][2].x,Th[i][2].y)+(Lambda2Stressh(Th[i][2].x,Th[i][2].y)-Lambda1Stressh(Th[i][2].x,Th[i][2].y))*(Lambda2Stressh(Th[i][2].x,Th[i][2].y)-Lambda1Stressh(Th[i][2].x,Th[i][2].y)) ));
	Stri=sqrt(0.5*(Lambda1Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)*Lambda1Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)+Lambda2Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)*Lambda2Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)+(Lambda2Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)-Lambda1Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3))*(Lambda2Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)-Lambda1Stressh((Th[i][0].x+Th[i][1].x+Th[i][2].x)/3,(Th[i][0].y+Th[i][1].y+Th[i][2].y)/3)) ));
    f0 << Th[i][0].x << " " << Th[i][0].y << " " << Stri << endl;
    f0 << Th[i][1].x << " " << Th[i][1].y << " " << Stri << endl;
    f0 << endl;
    f0 << Th[i][2].x << " " << Th[i][2].y << " " << Stri << endl;
    f0 << Th[i][1].x << " " << Th[i][1].y << " " << Stri << endl;
    f0 << endl << endl;
}*/
//stress output
for (int i=0;i<Th.nt;i++){
	real sumxx=0.0,sumyy=0.0,xx,yy;
	for (int j=0;j<3;j++){
		sumxx=sumxx+Th[i][j].x;
		sumyy=sumyy+Th[i][j].y;
	}
	xx=sumxx/3.0;
	yy=sumyy/3.0;
	f0   <<
	xx-0.5*0.005*Lambda1Stressh(xx,yy)*Lambda1StressVectxh(xx,yy) << " " <<
	yy-0.5*0.005*Lambda1Stressh(xx,yy)*Lambda1StressVectyh(xx,yy) << " " <<
	0.005*Lambda1Stressh(xx,yy)*Lambda1StressVectxh(xx,yy) << " " <<
	0.005*Lambda1Stressh(xx,yy)*Lambda1StressVectyh(xx,yy) << " " <<
	0.005*Lambda1Stressh(xx,yy) << " " <<
	xx-0.5*0.005*Lambda2Stressh(xx,yy)*Lambda2StressVectxh(xx,yy) << " " <<
	yy-0.5*0.005*Lambda2Stressh(xx,yy)*Lambda2StressVectyh(xx,yy) << " " <<
	0.005*Lambda2Stressh(xx,yy)*Lambda2StressVectxh(xx,yy) << " " <<
	0.005*Lambda2Stressh(xx,yy)*Lambda2StressVectyh(xx,yy) << " " <<
	0.005*Lambda2Stressh(xx,yy) << " " <<
	endl;
f0   << 	 endl;
f0   << 	 endl;
}
//strain output1 two direction and thier length
/*for (int i=0;i<Th.nt;i++){
	real sumxx1=0.0,sumyy1=0.0,xx1,yy1;
	for (int j=0;j<3;j++){
		sumxx1=sumxx1+Th[i][j].x;
		sumyy1=sumyy1+Th[i][j].y;
	}
	xx1=sumxx1/3.0;
	yy1=sumyy1/3.0;
	f00   <<
	xx1-0.5*0.5*Lambda1Strainh(xx1,yy1)*Lambda1StrainVectxh(xx1,yy1) << " " <<
	yy1-0.5*0.5*Lambda1Strainh(xx1,yy1)*Lambda1StrainVectyh(xx1,yy1) << " " <<
	0.5*Lambda1Strainh(xx1,yy1)*Lambda1StrainVectxh(xx1,yy1) << " " <<
	0.5*Lambda1Strainh(xx1,yy1)*Lambda1StrainVectyh(xx1,yy1) << " " <<
	0.5*Lambda1Strainh(xx1,yy1) << " " <<
	xx1-0.5*0.5*Lambda2Strainh(xx1,yy1)*Lambda2StrainVectxh(xx1,yy1) << " " <<
	yy1-0.5*0.5*Lambda2Strainh(xx1,yy1)*Lambda2StrainVectyh(xx1,yy1) << " " <<
	0.5*Lambda2Strainh(xx1,yy1)*Lambda2StrainVectxh(xx1,yy1) << " " <<
	0.5*Lambda2Strainh(xx1,yy1)*Lambda2StrainVectyh(xx1,yy1) << " " <<
	0.5*Lambda2Strainh(xx1,yy1) << " " <<
	endl;
f00   << 	 endl;
f00   << 	 endl;
}*/
//strain output2 strainY/strainX
for (int i=0;i<Th.nt;i++){
	real sumxx1=0.0,sumyy1=0.0,xx1,yy1;
	for (int j=0;j<3;j++){
		sumxx1=sumxx1+Th[i][j].x;
		sumyy1=sumyy1+Th[i][j].y;
	}
	xx1=sumxx1/3.0;
	yy1=sumyy1/3.0;
	f00   <<	Th[i][0].x  << " " <<   Th[i][0].y   << " " <<   abs(Lambda1StrainVectyh(xx1,yy1))/abs(Lambda1StrainVectxh(xx1,yy1)) << endl;
	f00   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   abs(Lambda1StrainVectyh(xx1,yy1))/abs(Lambda1StrainVectxh(xx1,yy1)) << endl;
	f00   <<   endl;
	f00   <<	Th[i][2].x  << " " <<   Th[i][2].y   << " " <<   abs(Lambda1StrainVectyh(xx1,yy1))/abs(Lambda1StrainVectxh(xx1,yy1)) << endl;
	f00   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   abs(Lambda1StrainVectyh(xx1,yy1))/abs(Lambda1StrainVectxh(xx1,yy1)) << endl;
f00   << 	 endl;
f00   << 	 endl;
}
//strain output3 length
for (int i=0;i<Th.nt;i++){
	real sumxx1=0.0,sumyy1=0.0,xx1,yy1;
	for (int j=0;j<3;j++){
		sumxx1=sumxx1+Th[i][j].x;
		sumyy1=sumyy1+Th[i][j].y;
	}
	xx1=sumxx1/3.0;
	yy1=sumyy1/3.0;
	f001   <<	Th[i][0].x  << " " <<   Th[i][0].y   << " " <<   Lambda1Strainh(xx1,yy1) << endl;
	f001   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   Lambda1Strainh(xx1,yy1) << endl;
	f001   <<   endl;
	f001   <<	Th[i][2].x  << " " <<   Th[i][2].y   << " " <<   Lambda1Strainh(xx1,yy1) << endl;
	f001   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   Lambda1Strainh(xx1,yy1) << endl;
f001   << 	 endl;
f001   << 	 endl;
}
//displacement output1
real minx=10000;
real maxx=-10000;
real miny=10000;
real maxy=-10000;
for (int i=0;i<Th.nt;i++){
	for (int j=0;j<3;j++){
//		f000   <<
//		Th[i][j].x-u1(Th[i][j].x,Th[i][j].y) << " " <<
//		Th[i][j].y-u2(Th[i][j].x,Th[i][j].y) << " " <<
//		u1(Th[i][j].x,Th[i][j].y) << " " <<
//		u2(Th[i][j].x,Th[i][j].y) << " " <<
//		endl;
		if(maxx<Th[i][j].x)maxx=Th[i][j].x;
		if(minx>Th[i][j].x)minx=Th[i][j].x;
		if(maxy<Th[i][j].y)maxy=Th[i][j].y;
		if(miny>Th[i][j].y)miny=Th[i][j].y;
	}
//f000   << 	 endl;
//f000   << 	 endl;
}
f11   <<
(maxx-minx)/(asp*sqrt(3))-1 << " " <<
(maxy-miny)/2.0-1 << " " <<
endl;

//displacement output2 atan(disY/disX)
for (int i=0;i<Th.nt;i++){
	real sumxx1=0.0,sumyy1=0.0,xx1,yy1;
	for (int j=0;j<3;j++){
		sumxx1=sumxx1+Th[i][j].x;
		sumyy1=sumyy1+Th[i][j].y;
	}
	xx1=sumxx1/3.0;
	yy1=sumyy1/3.0;
	f000   <<	Th[i][0].x  << " " <<   Th[i][0].y   << " " <<   atan2(abs(u2(xx1,yy1)),abs(u1(xx1,yy1))) << endl;
	f000   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   atan2(abs(u2(xx1,yy1)),abs(u1(xx1,yy1))) << endl;
	f000   <<   endl;
	f000   <<	Th[i][2].x  << " " <<   Th[i][2].y   << " " <<   atan2(abs(u2(xx1,yy1)),abs(u1(xx1,yy1))) << endl;
	f000   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   atan2(abs(u2(xx1,yy1)),abs(u1(xx1,yy1))) << endl;
f000   << 	 endl;
f000   << 	 endl;
}
//strain output3 length
for (int i=0;i<Th.nt;i++){
	real sumxx1=0.0,sumyy1=0.0,xx1,yy1;
	for (int j=0;j<3;j++){
		sumxx1=sumxx1+Th[i][j].x;
		sumyy1=sumyy1+Th[i][j].y;
	}
	xx1=sumxx1/3.0;
	yy1=sumyy1/3.0;
	f0001   <<	Th[i][0].x  << " " <<   Th[i][0].y   << " " <<   sqrt(u1(xx1,yy1)*u1(xx1,yy1)+u2(xx1,yy1)*u2(xx1,yy1)) << endl;
	f0001   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   sqrt(u1(xx1,yy1)*u1(xx1,yy1)+u2(xx1,yy1)*u2(xx1,yy1)) << endl;
	f0001   <<   endl;
	f0001   <<	Th[i][2].x  << " " <<   Th[i][2].y   << " " <<   sqrt(u1(xx1,yy1)*u1(xx1,yy1)+u2(xx1,yy1)*u2(xx1,yy1)) << endl;
	f0001   <<	Th[i][1].x  << " " <<   Th[i][1].y   << " " <<   sqrt(u1(xx1,yy1)*u1(xx1,yy1)+u2(xx1,yy1)*u2(xx1,yy1)) << endl;
f0001   << 	 endl;
f0001   << 	 endl;
}
	
//Ÿ‚Ìtriangleo—Í
for (int i=0;i<Th.nt;i++){
	for (int j=0;j<3;j++){
		f1   <<
		Th[i][j].x << " " <<
		Th[i][j].y << " " <<
		endl;
	}
	f1   <<
	Th[i][0].x << " " <<
	Th[i][0].y << " " <<
	endl;
f1  << 	 endl;
f1   << 	 endl;
}
}
	