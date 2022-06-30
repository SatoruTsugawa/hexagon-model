func Lambda1Stress = (S11(u)+S22(u) + sqrt((S11(u)-S22(u))^2 + 4*S12(u)^2))/2.;
func Lambda2Stress = (S11(u)+S22(u) - sqrt((S11(u)-S22(u))^2 + 4*S12(u)^2))/2.;
func LambdaRatio =  (Lambda1Stress -Lambda2Stress)/(Lambda1Stress+Lambda2Stress);
func Lambda1StressVectx = S12(u)*1.0/(sqrt((S12(u))^2+(S11(u) - Lambda1Stress )^2));
func Lambda1StressVecty = (Lambda1Stress - S11(u))/(sqrt((S12(u))^2+(Lambda1Stress - S11(u))^2));
func Lambda2StressVectx = cos(pi/2)*Lambda1StressVectx-sin(pi/2)*Lambda1StressVecty;
func Lambda2StressVecty = sin(pi/2)*Lambda1StressVectx+cos(pi/2)*Lambda1StressVecty;
func ThetaStress = atan2(Lambda2StressVecty, Lambda2StressVectx);
Vh1 Lambda1Stressh = Lambda1Stress;
Vh1 Lambda2Stressh = Lambda2Stress;
Vh1 Lambda1StressVectxh = Lambda1StressVectx;
Vh1 Lambda1StressVectyh = Lambda1StressVecty;
Vh1 Lambda2StressVectxh = Lambda2StressVectx;
Vh1 Lambda2StressVectyh = Lambda2StressVecty;
Vh1 ThetaStressh = ThetaStress;

//Strain direction
//ひずみテンソル（わかりやすいver）
func Rxx = dx(u1);
Vh1 Rxxh = Rxx;
func Rxy = 0.5*(dx(u2)+dy(u1));
Vh1 Rxyh = Rxy;
func Ryy = dy(u2);
Vh1 Ryyh = Ryy;
func Lambda1Strain = (Rxx+Ryy + sqrt((Rxx-Ryy)^2 + 4*Rxy^2))/2.;
func Lambda2Strain = (Rxx+Ryy - sqrt((Rxx-Ryy)^2 + 4*Rxy^2))/2.;
func Lambda1StrainVectx = Rxy*1.0/(sqrt((Rxy)^2+(Rxx - Lambda1Strain )^2));
func Lambda1StrainVecty = (Lambda1Strain - Rxx)/(sqrt((Rxy)^2+(Lambda1Strain - Rxx)^2));
func Lambda2StrainVectx = cos(pi/2)*Lambda1StrainVectx-sin(pi/2)*Lambda1StrainVecty;
func Lambda2StrainVecty = sin(pi/2)*Lambda1StrainVectx+cos(pi/2)*Lambda1StrainVecty;
func ThetaStrain = atan2(Lambda2StrainVecty, Lambda2StrainVectx);
Vh1 Lambda1Strainh = Lambda1Strain;
Vh1 Lambda2Strainh = Lambda2Strain;
Vh1 Lambda1StrainVectxh = Lambda1StrainVectx;
Vh1 Lambda1StrainVectyh = Lambda1StrainVecty;
Vh1 Lambda2StrainVectxh = Lambda2StrainVectx;
Vh1 Lambda2StrainVectyh = Lambda2StrainVecty;

Vh1 ThetaStrainh = ThetaStrain;
