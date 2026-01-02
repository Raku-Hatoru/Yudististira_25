#include <Fuzzy.h>
#include "variabel.h"

// FuzzySet input motor 1
// error kecepatan
FuzzySet *NB_e1 = new FuzzySet(-1,-1,-0.9,-0.7);
FuzzySet *NM_e1 = new FuzzySet(-0.9,-0.7,-0.6,-0.4);
FuzzySet *NS_e1 = new FuzzySet(-0.6,-0.4,-0.3,-0.1);
FuzzySet *Z_e1 = new FuzzySet(-0.3,-0.1,-0.1,0.3);
FuzzySet *PS_e1 = new FuzzySet(0.1,0.3,0.4,0.6);
FuzzySet *PM_e1 = new FuzzySet(0.4,0.6,0.7,0.9);
FuzzySet *PB_e1 = new FuzzySet(0.7,0.9,1,1);

FuzzySet *NB_e2 = new FuzzySet(-1,-1,-0.9,-0.7);
FuzzySet *NM_e2 = new FuzzySet(-0.9,-0.7,-0.6,-0.4);
FuzzySet *NS_e2 = new FuzzySet(-0.6,-0.4,-0.3,-0.1);
FuzzySet *Z_e2 = new FuzzySet(-0.3,-0.1,-0.1,0.3);
FuzzySet *PS_e2 = new FuzzySet(0.1,0.3,0.4,0.6);
FuzzySet *PM_e2 = new FuzzySet(0.4,0.6,0.7,0.9);
FuzzySet *PB_e2 = new FuzzySet(0.7,0.9,1,1);

FuzzySet *NB_e3 = new FuzzySet(-1,-1,-0.9,-0.7);
FuzzySet *NM_e3 = new FuzzySet(-0.9,-0.7,-0.6,-0.4);
FuzzySet *NS_e3 = new FuzzySet(-0.6,-0.4,-0.3,-0.1);
FuzzySet *Z_e3 = new FuzzySet(-0.3,-0.1,-0.1,0.3);
FuzzySet *PS_e3 = new FuzzySet(0.1,0.3,0.4,0.6);
FuzzySet *PM_e3 = new FuzzySet(0.4,0.6,0.7,0.9);
FuzzySet *PB_e3 = new FuzzySet(0.7,0.9,1,1);

FuzzySet *NB_e4 = new FuzzySet(-1,-1,-0.9,-0.7);
FuzzySet *NM_e4 = new FuzzySet(-0.9,-0.7,-0.6,-0.4);
FuzzySet *NS_e4 = new FuzzySet(-0.6,-0.4,-0.3,-0.1);
FuzzySet *Z_e4 = new FuzzySet(-0.3,-0.1,-0.1,0.3);
FuzzySet *PS_e4 = new FuzzySet(0.1,0.3,0.4,0.6);
FuzzySet *PM_e4 = new FuzzySet(0.4,0.6,0.7,0.9);
FuzzySet *PB_e4 = new FuzzySet(0.7,0.9,1,1);

// delta error kecepatan
FuzzySet *NB_de1 = new FuzzySet(-0.2,-0.2,-0.18,-0.14);
FuzzySet *NM_de1 = new FuzzySet(-0.18,-0.14,-0.12,-0.08);
FuzzySet *NS_de1 = new FuzzySet(-0.12,-0.08,-0.06,-0.02);
FuzzySet *Z_de1 = new FuzzySet(-0.06,-0.02,0.02,0.06);
FuzzySet *PS_de1 = new FuzzySet(0.02,0.06,0.08,0.12);
FuzzySet *PM_de1 = new FuzzySet(0.08,0.12,0.14,0.18);
FuzzySet *PB_de1 = new FuzzySet(0.14,0.18,0.2,0.2);

FuzzySet *NB_de2 = new FuzzySet(-0.2,-0.2,-0.18,-0.14);
FuzzySet *NM_de2 = new FuzzySet(-0.18,-0.14,-0.12,-0.08);
FuzzySet *NS_de2 = new FuzzySet(-0.12,-0.08,-0.06,-0.02);
FuzzySet *Z_de2 = new FuzzySet(-0.06,-0.02,0.02,0.06);
FuzzySet *PS_de2 = new FuzzySet(0.02,0.06,0.08,0.12);
FuzzySet *PM_de2 = new FuzzySet(0.08,0.12,0.14,0.18);
FuzzySet *PB_de2 = new FuzzySet(0.14,0.18,0.2,0.2);

FuzzySet *NB_de3 = new FuzzySet(-0.2,-0.2,-0.18,-0.14);
FuzzySet *NM_de3 = new FuzzySet(-0.18,-0.14,-0.12,-0.08);
FuzzySet *NS_de3 = new FuzzySet(-0.12,-0.08,-0.06,-0.02);
FuzzySet *Z_de3 = new FuzzySet(-0.06,-0.02,0.02,0.06);
FuzzySet *PS_de3 = new FuzzySet(0.02,0.06,0.08,0.12);
FuzzySet *PM_de3 = new FuzzySet(0.08,0.12,0.14,0.18);
FuzzySet *PB_de3 = new FuzzySet(0.14,0.18,0.2,0.2);

FuzzySet *NB_de4 = new FuzzySet(-0.2,-0.2,-0.18,-0.14);
FuzzySet *NM_de4 = new FuzzySet(-0.18,-0.14,-0.12,-0.08);
FuzzySet *NS_de4 = new FuzzySet(-0.12,-0.08,-0.06,-0.02);
FuzzySet *Z_de4 = new FuzzySet(-0.06,-0.02,0.02,0.06);
FuzzySet *PS_de4 = new FuzzySet(0.02,0.06,0.08,0.12);
FuzzySet *PM_de4 = new FuzzySet(0.08,0.12,0.14,0.18);
FuzzySet *PB_de4 = new FuzzySet(0.14,0.18,0.2,0.2);

//FuzzySet output motor
//delta PWM
FuzzySet *NB_dp1 = new FuzzySet(-30,-30,-25,-20);
FuzzySet *NM_dp1 = new FuzzySet(-25,-20,-15,-10);
FuzzySet *NS_dp1 = new FuzzySet(-15,-12,-9,-6);
FuzzySet *Z_dp1 = new FuzzySet(-9,-5,5,9);
FuzzySet *PS_dp1 = new FuzzySet(6,9,12,15);
FuzzySet *PM_dp1 = new FuzzySet(10,15,20,25);
FuzzySet *PB_dp1 = new FuzzySet(20,25,30,30);

FuzzySet *NB_dp2 = new FuzzySet(-30,-30,-25,-20);
FuzzySet *NM_dp2 = new FuzzySet(-25,-20,-15,-10);
FuzzySet *NS_dp2 = new FuzzySet(-15,-12,-9,-6);
FuzzySet *Z_dp2 = new FuzzySet(-9,-5,5,9);
FuzzySet *PS_dp2 = new FuzzySet(6,9,12,15);
FuzzySet *PM_dp2 = new FuzzySet(10,15,20,25);
FuzzySet *PB_dp2 = new FuzzySet(20,25,30,30);

FuzzySet *NB_dp3 = new FuzzySet(-30,-30,-25,-20);
FuzzySet *NM_dp3 = new FuzzySet(-25,-20,-15,-10);
FuzzySet *NS_dp3 = new FuzzySet(-15,-12,-9,-6);
FuzzySet *Z_dp3 = new FuzzySet(-9,-5,5,9);
FuzzySet *PS_dp3 = new FuzzySet(6,9,12,15);
FuzzySet *PM_dp3 = new FuzzySet(10,15,20,25);
FuzzySet *PB_dp3 = new FuzzySet(20,25,30,30);

FuzzySet *NB_dp4 = new FuzzySet(-30,-30,-25,-20);
FuzzySet *NM_dp4 = new FuzzySet(-25,-20,-15,-10);
FuzzySet *NS_dp4 = new FuzzySet(-15,-12,-9,-6);
FuzzySet *Z_dp4 = new FuzzySet(-9,-5,5,9);
FuzzySet *PS_dp4 = new FuzzySet(6,9,12,15);
FuzzySet *PM_dp4 = new FuzzySet(10,15,20,25);
FuzzySet *PB_dp4 = new FuzzySet(20,25,30,30);

void fuzzy_setup() {

    // Set input
    FuzzyInput *speed_error1 = new FuzzyInput(1);
    speed_error1->addFuzzySet(NB_e1);
    speed_error1->addFuzzySet(NM_e1);
    speed_error1->addFuzzySet(NS_e1);
    speed_error1->addFuzzySet(Z_e1);
    speed_error1->addFuzzySet(PS_e1);
    speed_error1->addFuzzySet(PM_e1);
    speed_error1->addFuzzySet(PB_e1);
    fuzzy_wheel1->addFuzzyInput(speed_error1);

    FuzzyInput *delta_error1 = new FuzzyInput(2);
    delta_error1->addFuzzySet(NB_de1);
    delta_error1->addFuzzySet(NM_de1);
    delta_error1->addFuzzySet(NS_de1);
    delta_error1->addFuzzySet(Z_de1);
    delta_error1->addFuzzySet(PS_de1);
    delta_error1->addFuzzySet(PM_de1);
    delta_error1->addFuzzySet(PB_de1);
    fuzzy_wheel1->addFuzzyInput(delta_error1);

    FuzzyInput *speed_error2 = new FuzzyInput(3);
    speed_error2->addFuzzySet(NB_e2);
    speed_error2->addFuzzySet(NM_e2);
    speed_error2->addFuzzySet(NS_e2);
    speed_error2->addFuzzySet(Z_e2);
    speed_error2->addFuzzySet(PS_e2);
    speed_error2->addFuzzySet(PM_e2);
    speed_error2->addFuzzySet(PB_e2);
    fuzzy_wheel2->addFuzzyInput(speed_error2);

    FuzzyInput *delta_error2 = new FuzzyInput(4);
    delta_error2->addFuzzySet(NB_de2);
    delta_error2->addFuzzySet(NM_de2);
    delta_error2->addFuzzySet(NS_de2);
    delta_error2->addFuzzySet(Z_de2);
    delta_error2->addFuzzySet(PS_de2);
    delta_error2->addFuzzySet(PM_de2);
    delta_error2->addFuzzySet(PB_de2);
    fuzzy_wheel2->addFuzzyInput(delta_error2);

    FuzzyInput *speed_error3 = new FuzzyInput(5);
    speed_error3->addFuzzySet(NB_e3);
    speed_error3->addFuzzySet(NM_e3);
    speed_error3->addFuzzySet(NS_e3);
    speed_error3->addFuzzySet(Z_e3);
    speed_error3->addFuzzySet(PS_e3);
    speed_error3->addFuzzySet(PM_e3);
    speed_error3->addFuzzySet(PB_e3);
    fuzzy_wheel3->addFuzzyInput(speed_error3);

    FuzzyInput *delta_error3 = new FuzzyInput(6);
    delta_error3->addFuzzySet(NB_de3);
    delta_error3->addFuzzySet(NM_de3);
    delta_error3->addFuzzySet(NS_de3);
    delta_error3->addFuzzySet(Z_de3);
    delta_error3->addFuzzySet(PS_de3);
    delta_error3->addFuzzySet(PM_de3);
    delta_error3->addFuzzySet(PB_de3);
    fuzzy_wheel3->addFuzzyInput(delta_error3);

    FuzzyInput *speed_error4 = new FuzzyInput(7);
    speed_error4->addFuzzySet(NB_e4);
    speed_error4->addFuzzySet(NM_e4);
    speed_error4->addFuzzySet(NS_e4);
    speed_error4->addFuzzySet(Z_e4);
    speed_error4->addFuzzySet(PS_e4);
    speed_error4->addFuzzySet(PM_e4);
    speed_error4->addFuzzySet(PB_e4);
    fuzzy_wheel4->addFuzzyInput(speed_error4);

    FuzzyInput *delta_error4 = new FuzzyInput(8);
    delta_error4->addFuzzySet(NB_de4);
    delta_error4->addFuzzySet(NM_de4);
    delta_error4->addFuzzySet(NS_de4);
    delta_error4->addFuzzySet(Z_de4);
    delta_error4->addFuzzySet(PS_de4);
    delta_error4->addFuzzySet(PM_de4);
    delta_error4->addFuzzySet(PB_de4);
    fuzzy_wheel4->addFuzzyInput(delta_error4);

    // Set output
    FuzzyOutput *delta_pwm1 = new FuzzyOutput(1);
    delta_pwm1->addFuzzySet(NB_dp1);
    delta_pwm1->addFuzzySet(NM_dp1);
    delta_pwm1->addFuzzySet(NS_dp1);
    delta_pwm1->addFuzzySet(Z_dp1);
    delta_pwm1->addFuzzySet(PS_dp1);
    delta_pwm1->addFuzzySet(PM_dp1);
    delta_pwm1->addFuzzySet(PB_dp1);
    fuzzy_wheel1->addFuzzyOutput(delta_pwm1);

    FuzzyOutput *delta_pwm2 = new FuzzyOutput(2);
    delta_pwm2->addFuzzySet(NB_dp2);
    delta_pwm2->addFuzzySet(NM_dp2);
    delta_pwm2->addFuzzySet(NS_dp2);
    delta_pwm2->addFuzzySet(Z_dp2);
    delta_pwm2->addFuzzySet(PS_dp2);
    delta_pwm2->addFuzzySet(PM_dp2);
    delta_pwm2->addFuzzySet(PB_dp2);
    fuzzy_wheel2->addFuzzyOutput(delta_pwm2);

    FuzzyOutput *delta_pwm3 = new FuzzyOutput(3);
    delta_pwm3->addFuzzySet(NB_dp3);
    delta_pwm3->addFuzzySet(NM_dp3);
    delta_pwm3->addFuzzySet(NS_dp3);
    delta_pwm3->addFuzzySet(Z_dp3);
    delta_pwm3->addFuzzySet(PS_dp3);
    delta_pwm3->addFuzzySet(PM_dp3);
    delta_pwm3->addFuzzySet(PB_dp3);
    fuzzy_wheel3->addFuzzyOutput(delta_pwm3);

    FuzzyOutput *delta_pwm4 = new FuzzyOutput(4);
    delta_pwm4->addFuzzySet(NB_dp4);
    delta_pwm4->addFuzzySet(NM_dp4);
    delta_pwm4->addFuzzySet(NS_dp4);
    delta_pwm4->addFuzzySet(Z_dp4);
    delta_pwm4->addFuzzySet(PS_dp4);
    delta_pwm4->addFuzzySet(PM_dp4);
    delta_pwm4->addFuzzySet(PB_dp4);
    fuzzy_wheel4->addFuzzyOutput(delta_pwm4);
}

void fuzzy_rules() {
    FuzzyRuleAntecedent *IF_NBE1_AND_NBDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_NBDE1->joinWithAND(NB_e1, NB_de1);
    FuzzyRuleConsequent *THEN_NBP1 = new FuzzyRuleConsequent();
    THEN_NBP1->addOutput(NB_dp1);
    FuzzyRule *fuzzy_rule1_w1 = new FuzzyRule(1, IF_NBE1_AND_NBDE1, THEN_NBP1);
    FuzzyRuleAntecedent *IF_NBE1_AND_NMDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_NMDE1->joinWithAND(NB_e1, NM_de2);
    FuzzyRuleAntecedent *IF_NBE1_AND_NSDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_NSDE1->joinWithAND(NB_e1, NS_de1);
    FuzzyRuleAntecedent *IF_NBE1_AND_ZDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_ZDE1->joinWithAND(NB_e1, Z_de1);
    FuzzyRuleAntecedent *IF_NBE1_AND_PSDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_PSDE1->joinWithAND(NB_e1, PS_de1);
    FuzzyRuleAntecedent *IF_NBE1_AND_PMDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_PMDE1->joinWithAND(NB_e1, PM_de1);
    FuzzyRuleAntecedent *IF_NBE1_AND_PBDE1 = new FuzzyRuleAntecedent();
    IF_NBE1_AND_PBDE1->joinWithAND(NB_e1, PB_de1);
}