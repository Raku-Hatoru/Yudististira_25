#include "variabel.h"

void fuzzy_setup(Fuzzy *fuzzy_wheel) {

// FuzzySet input motor
// error kecepatan
FuzzySet *NB_e = new FuzzySet(-1,-1,-0.9,-0.7);
FuzzySet *NM_e = new FuzzySet(-0.9,-0.7,-0.6,-0.4);
FuzzySet *NS_e = new FuzzySet(-0.6,-0.4,-0.3,-0.1);
FuzzySet *Z_e = new FuzzySet(-0.3,-0.1,-0.1,0.3);
FuzzySet *PS_e = new FuzzySet(0.1,0.3,0.4,0.6);
FuzzySet *PM_e = new FuzzySet(0.4,0.6,0.7,0.9);
FuzzySet *PB_e = new FuzzySet(0.7,0.9,1,1);

// delta error kecepatan
FuzzySet *NB_de = new FuzzySet(-0.2,-0.2,-0.18,-0.14);
FuzzySet *NM_de = new FuzzySet(-0.18,-0.14,-0.12,-0.08);
FuzzySet *NS_de = new FuzzySet(-0.12,-0.08,-0.06,-0.02);
FuzzySet *Z_de = new FuzzySet(-0.06,-0.02,0.02,0.06);
FuzzySet *PS_de = new FuzzySet(0.02,0.06,0.08,0.12);
FuzzySet *PM_de = new FuzzySet(0.08,0.12,0.14,0.18);
FuzzySet *PB_de = new FuzzySet(0.14,0.18,0.2,0.2);

//FuzzySet output motor
//delta PWM
FuzzySet *NB_dp = new FuzzySet(-30,-30,-25,-20);
FuzzySet *NM_dp = new FuzzySet(-25,-20,-15,-10);
FuzzySet *NS_dp = new FuzzySet(-15,-12,-9,-6);
FuzzySet *Z_dp = new FuzzySet(-9,-5,5,9);
FuzzySet *PS_dp = new FuzzySet(6,9,12,15);
FuzzySet *PM_dp = new FuzzySet(10,15,20,25);
FuzzySet *PB_dp = new FuzzySet(20,25,30,30);

FuzzyInput *speed_error = new FuzzyInput(1);
speed_error->addFuzzySet(NB_e);
speed_error->addFuzzySet(NM_e);
speed_error->addFuzzySet(NS_e);
speed_error->addFuzzySet(Z_e);
speed_error->addFuzzySet(PS_e);
speed_error->addFuzzySet(PM_e);
speed_error->addFuzzySet(PB_e);
fuzzy_wheel->addFuzzyInput(speed_error);

FuzzyInput *delta_error = new FuzzyInput(2);
delta_error->addFuzzySet(NB_de);
delta_error->addFuzzySet(NM_de);
delta_error->addFuzzySet(NS_de);
delta_error->addFuzzySet(Z_de);
delta_error->addFuzzySet(PS_de);
delta_error->addFuzzySet(PM_de);
delta_error->addFuzzySet(PB_de);
fuzzy_wheel->addFuzzyInput(delta_error);

FuzzyOutput *delta_pwm = new FuzzyOutput(1);
delta_pwm->addFuzzySet(NB_dp);
delta_pwm->addFuzzySet(NM_dp);
delta_pwm->addFuzzySet(NS_dp);
delta_pwm->addFuzzySet(Z_dp);
delta_pwm->addFuzzySet(PS_dp);
delta_pwm->addFuzzySet(PM_dp);
delta_pwm->addFuzzySet(PB_dp);
fuzzy_wheel->addFuzzyOutput(delta_pwm);

// Rules
FuzzyRuleAntecedent *IF_NBE_AND_NBDE = new FuzzyRuleAntecedent();
IF_NBE_AND_NBDE->joinWithAND(NB_e, NB_de);
FuzzyRuleConsequent *THEN_NBDP = new FuzzyRuleConsequent();
THEN_NBDP->addOutput(NB_dp);
FuzzyRule *fuzzy_rule1 = new FuzzyRule(1, IF_NBE_AND_NBDE, THEN_NBDP);

FuzzyRuleAntecedent *IF_NBE_AND_NMDE = new FuzzyRuleAntecedent();
IF_NBE_AND_NMDE->joinWithAND(NB_e, NM_de);
THEN_NBDP->addOutput(NB_dp);
FuzzyRule *fuzzy_rule2 = new FuzzyRule(2, IF_NBE_AND_NMDE, THEN_NBDP);

FuzzyRuleAntecedent *IF_NBE_AND_NSDE = new FuzzyRuleAntecedent();
IF_NBE_AND_NSDE->joinWithAND(NB_e, NS_de);
FuzzyRuleConsequent *THEN_NMDP = new FuzzyRuleConsequent();
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule3 = new FuzzyRule(3, IF_NBE_AND_NSDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NBE_AND_ZDE = new FuzzyRuleAntecedent();
IF_NBE_AND_ZDE->joinWithAND(NB_e, Z_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule4 = new FuzzyRule(4, IF_NBE_AND_ZDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NBE_AND_PSDE = new FuzzyRuleAntecedent();
IF_NBE_AND_PSDE->joinWithAND(NB_e, PS_de);
FuzzyRuleConsequent *THEN_NSDP = new FuzzyRuleConsequent();
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule5 = new FuzzyRule(5, IF_NBE_AND_PSDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NBE_AND_PMDE = new FuzzyRuleAntecedent();
IF_NBE_AND_PMDE->joinWithAND(NB_e, PM_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule6 = new FuzzyRule(6, IF_NBE_AND_PMDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NBE_AND_PBDE = new FuzzyRuleAntecedent();
IF_NBE_AND_PBDE->joinWithAND(NB_e, PB_de);
FuzzyRuleConsequent *THEN_ZDP = new FuzzyRuleConsequent();
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule7 = new FuzzyRule(7, IF_NBE_AND_PBDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_NME_AND_NBDE = new FuzzyRuleAntecedent();
IF_NME_AND_NBDE->joinWithAND(NM_e, NB_de);
THEN_NBDP->addOutput(NB_dp);
FuzzyRule *fuzzy_rule8 = new FuzzyRule(8, IF_NME_AND_NBDE, THEN_NBDP);

FuzzyRuleAntecedent *IF_NME_AND_NMDE = new FuzzyRuleAntecedent();
IF_NME_AND_NMDE->joinWithAND(NM_e, NM_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule9 = new FuzzyRule(9, IF_NME_AND_NMDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NME_AND_NSDE = new FuzzyRuleAntecedent();
IF_NME_AND_NSDE->joinWithAND(NM_e, NS_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule10 = new FuzzyRule(10, IF_NME_AND_NSDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NME_AND_ZDE = new FuzzyRuleAntecedent();
IF_NME_AND_ZDE->joinWithAND(NM_e, Z_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule11 = new FuzzyRule(11, IF_NME_AND_ZDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NME_AND_PSDE = new FuzzyRuleAntecedent();
IF_NME_AND_PSDE->joinWithAND(NM_e, PS_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule12 = new FuzzyRule(12, IF_NME_AND_PSDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NME_AND_PMDE = new FuzzyRuleAntecedent();
IF_NME_AND_PMDE->joinWithAND(NM_e, PM_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule13 = new FuzzyRule(13, IF_NME_AND_PMDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_NME_AND_PBDE = new FuzzyRuleAntecedent();
IF_NME_AND_PBDE->joinWithAND(NM_e, PB_de);
FuzzyRuleConsequent *THEN_PSDP = new FuzzyRuleConsequent();
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule14 = new FuzzyRule(14, IF_NME_AND_PBDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_NSE_AND_NBDE = new FuzzyRuleAntecedent();
IF_NSE_AND_NBDE->joinWithAND(NS_e, NB_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule15 = new FuzzyRule(15, IF_NSE_AND_NBDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NSE_AND_NMDE = new FuzzyRuleAntecedent();
IF_NSE_AND_NMDE->joinWithAND(NS_e, NM_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule16 = new FuzzyRule(16, IF_NSE_AND_NMDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_NSE_AND_NSDE = new FuzzyRuleAntecedent();
IF_NSE_AND_NSDE->joinWithAND(NS_e, NS_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule17 = new FuzzyRule(17, IF_NSE_AND_NSDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NSE_AND_ZDE = new FuzzyRuleAntecedent();
IF_NSE_AND_ZDE->joinWithAND(NS_e, Z_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule18 = new FuzzyRule(18, IF_NSE_AND_ZDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_NSE_AND_PSDE = new FuzzyRuleAntecedent();
IF_NSE_AND_PSDE->joinWithAND(NS_e, PS_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule19 = new FuzzyRule(19, IF_NSE_AND_PSDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_NSE_AND_PMDE = new FuzzyRuleAntecedent();
IF_NSE_AND_PMDE->joinWithAND(NS_e, PM_de);
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule20 = new FuzzyRule(20, IF_NSE_AND_PMDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_NSE_AND_PBDE = new FuzzyRuleAntecedent();
IF_NSE_AND_PBDE->joinWithAND(NS_e, PB_de);
FuzzyRuleConsequent *THEN_PMDP = new FuzzyRuleConsequent();
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule21 = new FuzzyRule(21, IF_NSE_AND_PBDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_ZE_AND_NBDE = new FuzzyRuleAntecedent();
IF_ZE_AND_NBDE->joinWithAND(Z_e, NB_de);
THEN_NMDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule22 = new FuzzyRule(22, IF_ZE_AND_NBDE, THEN_NMDP);

FuzzyRuleAntecedent *IF_ZE_AND_NMDE = new FuzzyRuleAntecedent();
IF_ZE_AND_NMDE->joinWithAND(Z_e, NM_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule23 = new FuzzyRule(23, IF_ZE_AND_NMDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_ZE_AND_NSDE = new FuzzyRuleAntecedent();
IF_ZE_AND_NSDE->joinWithAND(Z_e, NS_de);
THEN_NSDP->addOutput(NM_dp);
FuzzyRule *fuzzy_rule24 = new FuzzyRule(24, IF_ZE_AND_NSDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_ZE_AND_ZDE = new FuzzyRuleAntecedent();
IF_ZE_AND_ZDE->joinWithAND(Z_e, Z_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule25 = new FuzzyRule(25, IF_ZE_AND_ZDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_ZE_AND_PSDE = new FuzzyRuleAntecedent();
IF_ZE_AND_PSDE->joinWithAND(Z_e, PS_de);
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule26 = new FuzzyRule(26, IF_ZE_AND_PSDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_ZE_AND_PMDE = new FuzzyRuleAntecedent();
IF_ZE_AND_PMDE->joinWithAND(Z_e, PM_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule27 = new FuzzyRule(27, IF_ZE_AND_PMDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_ZE_AND_PBDE = new FuzzyRuleAntecedent();
IF_ZE_AND_PBDE->joinWithAND(Z_e, PB_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule28 = new FuzzyRule(28, IF_ZE_AND_PBDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PSE_AND_NBDE = new FuzzyRuleAntecedent();
IF_PSE_AND_NBDE->joinWithAND(PS_e, NB_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule29 = new FuzzyRule(29, IF_PSE_AND_NBDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_PSE_AND_NMDE = new FuzzyRuleAntecedent();
IF_PSE_AND_NMDE->joinWithAND(PS_e, NM_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule30 = new FuzzyRule(30, IF_PSE_AND_NMDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_PSE_AND_NSDE = new FuzzyRuleAntecedent();
IF_PSE_AND_NSDE->joinWithAND(PS_e, NS_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule31 = new FuzzyRule(31, IF_PSE_AND_NSDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_PSE_AND_ZDE = new FuzzyRuleAntecedent();
IF_PSE_AND_ZDE->joinWithAND(PS_e, Z_de);
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule32 = new FuzzyRule(32, IF_PSE_AND_ZDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_PSE_AND_PSDE = new FuzzyRuleAntecedent();
IF_PSE_AND_PSDE->joinWithAND(PS_e, PS_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule33 = new FuzzyRule(33, IF_PSE_AND_PSDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PSE_AND_PMDE = new FuzzyRuleAntecedent();
IF_PSE_AND_PMDE->joinWithAND(PS_e, PM_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule34 = new FuzzyRule(34, IF_PSE_AND_PMDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PSE_AND_PBDE = new FuzzyRuleAntecedent();
IF_PSE_AND_PBDE->joinWithAND(PS_e, PB_de);
FuzzyRuleConsequent *THEN_PBDP = new FuzzyRuleConsequent();
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule35 = new FuzzyRule(35, IF_PSE_AND_PBDE, THEN_PBDP);

FuzzyRuleAntecedent *IF_PME_AND_NBDE = new FuzzyRuleAntecedent();
IF_PME_AND_NBDE->joinWithAND(PM_e, NB_de);
THEN_NSDP->addOutput(NS_dp);
FuzzyRule *fuzzy_rule36 = new FuzzyRule(36, IF_PME_AND_NBDE, THEN_NSDP);

FuzzyRuleAntecedent *IF_PME_AND_NMDE = new FuzzyRuleAntecedent();
IF_PME_AND_NMDE->joinWithAND(PM_e, NM_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule37 = new FuzzyRule(37, IF_PME_AND_NMDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_PME_AND_NSDE = new FuzzyRuleAntecedent();
IF_PME_AND_NSDE->joinWithAND(PM_e, NS_de);
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule38 = new FuzzyRule(38, IF_PME_AND_NSDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_PME_AND_ZDE = new FuzzyRuleAntecedent();
IF_PME_AND_ZDE->joinWithAND(PM_e, Z_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule39 = new FuzzyRule(39, IF_PME_AND_ZDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PME_AND_PSDE = new FuzzyRuleAntecedent();
IF_PME_AND_PSDE->joinWithAND(PM_e, PS_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule40 = new FuzzyRule(40, IF_PME_AND_PSDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PME_AND_PMDE = new FuzzyRuleAntecedent();
IF_PME_AND_PMDE->joinWithAND(PM_e, PM_de);
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule41 = new FuzzyRule(41, IF_PME_AND_PMDE, THEN_PBDP);

FuzzyRuleAntecedent *IF_PME_AND_PBDE = new FuzzyRuleAntecedent();
IF_PME_AND_PBDE->joinWithAND(PM_e, PB_de);
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule42 = new FuzzyRule(42, IF_PME_AND_PBDE, THEN_PBDP);

FuzzyRuleAntecedent *IF_PBE_AND_NBDE = new FuzzyRuleAntecedent();
IF_PBE_AND_NBDE->joinWithAND(PB_e, NB_de);
THEN_ZDP->addOutput(Z_dp);
FuzzyRule *fuzzy_rule43 = new FuzzyRule(43, IF_PBE_AND_NBDE, THEN_ZDP);

FuzzyRuleAntecedent *IF_PBE_AND_NMDE = new FuzzyRuleAntecedent();
IF_PBE_AND_NMDE->joinWithAND(PB_e, NM_de);
THEN_PSDP->addOutput(PS_dp);
FuzzyRule *fuzzy_rule44 = new FuzzyRule(44, IF_PBE_AND_NMDE, THEN_PSDP);

FuzzyRuleAntecedent *IF_PBE_AND_NSDE = new FuzzyRuleAntecedent();
IF_PBE_AND_NSDE->joinWithAND(PB_e, NS_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule45 = new FuzzyRule(45, IF_PBE_AND_NSDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PBE_AND_ZDE = new FuzzyRuleAntecedent();
IF_PBE_AND_ZDE->joinWithAND(PB_e, Z_de);
THEN_PMDP->addOutput(PM_dp);
FuzzyRule *fuzzy_rule46 = new FuzzyRule(46, IF_PBE_AND_ZDE, THEN_PMDP);

FuzzyRuleAntecedent *IF_PBE_AND_PSDE = new FuzzyRuleAntecedent();
IF_PBE_AND_PSDE->joinWithAND(PB_e, PS_de);
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule47 = new FuzzyRule(47, IF_PBE_AND_PSDE, THEN_PBDP);

FuzzyRuleAntecedent *IF_PBE_AND_PMDE = new FuzzyRuleAntecedent();
IF_PBE_AND_PMDE->joinWithAND(PB_e, PM_de);
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule48 = new FuzzyRule(48, IF_PBE_AND_PMDE, THEN_PBDP);

FuzzyRuleAntecedent *IF_PBE_AND_PBDE = new FuzzyRuleAntecedent();
IF_PBE_AND_PBDE->joinWithAND(PB_e, PB_de);
THEN_PBDP->addOutput(PB_dp);
FuzzyRule *fuzzy_rule49 = new FuzzyRule(49, IF_PBE_AND_PBDE, THEN_PBDP);

fuzzy_wheel->addFuzzyRule(fuzzy_rule1);
fuzzy_wheel->addFuzzyRule(fuzzy_rule2);
fuzzy_wheel->addFuzzyRule(fuzzy_rule3);
fuzzy_wheel->addFuzzyRule(fuzzy_rule4);
fuzzy_wheel->addFuzzyRule(fuzzy_rule5);
fuzzy_wheel->addFuzzyRule(fuzzy_rule6);
fuzzy_wheel->addFuzzyRule(fuzzy_rule7);

fuzzy_wheel->addFuzzyRule(fuzzy_rule8);
fuzzy_wheel->addFuzzyRule(fuzzy_rule9);
fuzzy_wheel->addFuzzyRule(fuzzy_rule10);
fuzzy_wheel->addFuzzyRule(fuzzy_rule11);
fuzzy_wheel->addFuzzyRule(fuzzy_rule12);
fuzzy_wheel->addFuzzyRule(fuzzy_rule13);
fuzzy_wheel->addFuzzyRule(fuzzy_rule14);

fuzzy_wheel->addFuzzyRule(fuzzy_rule15);
fuzzy_wheel->addFuzzyRule(fuzzy_rule16);
fuzzy_wheel->addFuzzyRule(fuzzy_rule17);
fuzzy_wheel->addFuzzyRule(fuzzy_rule18);
fuzzy_wheel->addFuzzyRule(fuzzy_rule19);
fuzzy_wheel->addFuzzyRule(fuzzy_rule20);
fuzzy_wheel->addFuzzyRule(fuzzy_rule21);

fuzzy_wheel->addFuzzyRule(fuzzy_rule22);
fuzzy_wheel->addFuzzyRule(fuzzy_rule23);
fuzzy_wheel->addFuzzyRule(fuzzy_rule24);
fuzzy_wheel->addFuzzyRule(fuzzy_rule25);
fuzzy_wheel->addFuzzyRule(fuzzy_rule26);
fuzzy_wheel->addFuzzyRule(fuzzy_rule27);
fuzzy_wheel->addFuzzyRule(fuzzy_rule28);

fuzzy_wheel->addFuzzyRule(fuzzy_rule29);
fuzzy_wheel->addFuzzyRule(fuzzy_rule30);
fuzzy_wheel->addFuzzyRule(fuzzy_rule31);
fuzzy_wheel->addFuzzyRule(fuzzy_rule32);
fuzzy_wheel->addFuzzyRule(fuzzy_rule33);
fuzzy_wheel->addFuzzyRule(fuzzy_rule34);
fuzzy_wheel->addFuzzyRule(fuzzy_rule35);

fuzzy_wheel->addFuzzyRule(fuzzy_rule36);
fuzzy_wheel->addFuzzyRule(fuzzy_rule37);
fuzzy_wheel->addFuzzyRule(fuzzy_rule38);
fuzzy_wheel->addFuzzyRule(fuzzy_rule39);
fuzzy_wheel->addFuzzyRule(fuzzy_rule40);
fuzzy_wheel->addFuzzyRule(fuzzy_rule41);
fuzzy_wheel->addFuzzyRule(fuzzy_rule42);

fuzzy_wheel->addFuzzyRule(fuzzy_rule43);
fuzzy_wheel->addFuzzyRule(fuzzy_rule44);
fuzzy_wheel->addFuzzyRule(fuzzy_rule45);
fuzzy_wheel->addFuzzyRule(fuzzy_rule46);
fuzzy_wheel->addFuzzyRule(fuzzy_rule47);
fuzzy_wheel->addFuzzyRule(fuzzy_rule48);
fuzzy_wheel->addFuzzyRule(fuzzy_rule49);
}

void fuzzy_process(Fuzzy *fuzzy_wheel, Encoder &wheel, float error, float d_error) {
    fuzzy_wheel->setInput(1,error);
    fuzzy_wheel->setInput(2,d_error);

    fuzzy_wheel->fuzzify();

    wheel.dpwm = fuzzy_wheel->defuzzify(1);
}