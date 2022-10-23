
#ifndef discretFilter_h_
#define discretFilter_h_
#ifndef discretFilter_COMMON_INCLUDES_
# define discretFilter_COMMON_INCLUDES_
#include "rtwtypes.h"

#endif                                 // discretFilter_COMMON_INCLUDES_
class CParamSmoothFilter
{
public:
    CParamSmoothFilter() { a = 0.99; b = 1. - a; z = 0.; };
    ~CParamSmoothFilter() {};
    inline double Process(double in) { z = (in * b) + (z * a); return z; }
private:
    double a, b, z;
};

typedef struct {
  real_T Filter_FILT_STATES[8];        // '<Root>/Filter'
} D_WorkLp2;



class discretFilterModelClass {
  // public data and function members
 public:
     inline double minmaxcutoff(double a) {
         double result = 0; result = a;
         if (result > 0.99) { result = 0.99; }
         if (result < 0.01) { result = 0.01; }
         return result;
     }
 

  // model initialize function
  void initialize();

  // model step function
  void setMode(float m) { mode = m; }

  void setcutoff(double c)  { cutoff=(c);cutoffM=c; }
  void setCutoffMod(double m){cutoffMod=m;}
  void setResonance(double r){resonance=r;}

  void cutofflfo(double p){
      if (cutoffMod > 0.1) {
          cutoff = cutoffM * 1 - (p * cutoffMod);
      }
      else
          cutoff = cutoffM;
  }
  double mPrev = 0;
  void cutoffStepper(double in) {
      double a = in;
      const double STEP_ATTACK = 0.02, STEP_DECAY = 0.03;
      double xL = (a < mPrev ? STEP_DECAY : STEP_ATTACK);
      a = a * xL + mPrev * (1.0 - xL);
      mPrev = a;
      const double y = a;
      v1= mPrev;
      cutoff = minmaxcutoff(cutoffM *  (y * 0.903));

  }
  void step(float in,float &out);
  double getValue() { return v1; }
  // Constructor
  discretFilterModelClass();

  // Destructor
  ~discretFilterModelClass();

  

 private:
     int mode;
  // Block signals and states
    D_WorkLp2 rtDWork;
    double buffout ;
    double cutoff;
    double cutoffMod;
    double cutoffM;
    double resonance;
    double v1;
    CParamSmoothFilter cutsm, modsm;
};



#endif                                 // discretFilter_h_


