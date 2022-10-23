
#include "discretFilter.h"
#include<math.h>

inline double fastClipLp(double x, double low, double high)
{
    double x1 = fabs(x - low);
    double x2 = fabs(x - high);
    x = x1 + low + high - x2;

    return x * 0.5;
}

// Model step function
void discretFilterModelClass::step(float in,float &out)
{
  real_T denAccum;
  real_T rtb_Filter;

  // S-Function (sdspbiquad): '<Root>/Filter' incorporates:


    if(mode==0){out=in;}

        if(mode ==1){
    
  denAccum = ((0.004371082803126829 * in) - (-1.9316967727627514*
    rtDWork.Filter_FILT_STATES[0])) - (0.94918110397525879 *
    rtDWork.Filter_FILT_STATES[1]);
  rtb_Filter = ((2.0 * rtDWork.Filter_FILT_STATES[0]) + denAccum) +
    rtDWork.Filter_FILT_STATES[1];
  rtDWork.Filter_FILT_STATES[1] = rtDWork.Filter_FILT_STATES[0];
  rtDWork.Filter_FILT_STATES[0] = denAccum;
  denAccum = ((0.0041750614235184251 * rtb_Filter) - (-1.8450697552852537 *
    rtDWork.Filter_FILT_STATES[2])) - (0.86177000097932777 *
    rtDWork.Filter_FILT_STATES[3]);
  rtb_Filter = ((4.0 * rtDWork.Filter_FILT_STATES[2]) + denAccum) +
    rtDWork.Filter_FILT_STATES[3];
  rtDWork.Filter_FILT_STATES[3] = rtDWork.Filter_FILT_STATES[2];
  rtDWork.Filter_FILT_STATES[2] = denAccum;
  denAccum = ((0.0040365164448040369 * rtb_Filter) - (-1.7838430752338896 *
    rtDWork.Filter_FILT_STATES[4])) - (0.79998914101310581 *
    rtDWork.Filter_FILT_STATES[5]);
  rtb_Filter = ((8.0 * rtDWork.Filter_FILT_STATES[4]) + denAccum) +
    rtDWork.Filter_FILT_STATES[5];
  rtDWork.Filter_FILT_STATES[5] = rtDWork.Filter_FILT_STATES[4];
  rtDWork.Filter_FILT_STATES[4] = denAccum;
  denAccum = ((0.0039653034890946215 * rtb_Filter) - (-1.7523721919496904 *
    rtDWork.Filter_FILT_STATES[6])) - (0.76823340590606892 *
    rtDWork.Filter_FILT_STATES[7]);


  buffout = ((((resonance * 30) * rtDWork.Filter_FILT_STATES[6]) + denAccum) +

      rtDWork.Filter_FILT_STATES[7]) * (1 - (cutoff));


  out = fastClipLp(in * cutoff + (buffout * cutoff), -1, 1);



  rtDWork.Filter_FILT_STATES[7] = rtDWork.Filter_FILT_STATES[6];
  rtDWork.Filter_FILT_STATES[6] = denAccum;

    }
  if(mode ==2){
    denAccum = ((0.0011080444613539764 * in) - (-1.9697742374694833 *
    rtDWork.Filter_FILT_STATES[0])) - (0.97420641531489915 *
    rtDWork.Filter_FILT_STATES[1]);
    rtb_Filter = ((2.0 * rtDWork.Filter_FILT_STATES[0]) + denAccum) +
    rtDWork.Filter_FILT_STATES[1];
    rtDWork.Filter_FILT_STATES[1] = rtDWork.Filter_FILT_STATES[0];
    rtDWork.Filter_FILT_STATES[0] = denAccum;
    denAccum = ((0.001082254166047697 * rtb_Filter) - (-1.9239267457461253 *
    rtDWork.Filter_FILT_STATES[2])) - (0.928255762410316 *
    rtDWork.Filter_FILT_STATES[3]);
    rtb_Filter = ((2.0 * rtDWork.Filter_FILT_STATES[2]) + denAccum) +
    rtDWork.Filter_FILT_STATES[3];
    rtDWork.Filter_FILT_STATES[3] = rtDWork.Filter_FILT_STATES[2];
    rtDWork.Filter_FILT_STATES[2] = denAccum;
    denAccum = ((0.0010633120060087413 * rtb_Filter) - (-1.8902532063277107 *
    rtDWork.Filter_FILT_STATES[4])) - (0.89450645435174569 *
    rtDWork.Filter_FILT_STATES[5]);
    rtb_Filter = ((2.0 * rtDWork.Filter_FILT_STATES[4]) + denAccum) +
    rtDWork.Filter_FILT_STATES[5];
    rtDWork.Filter_FILT_STATES[5] = rtDWork.Filter_FILT_STATES[4];
    rtDWork.Filter_FILT_STATES[4] = denAccum;
    denAccum = ((0.001053334518101291 * rtb_Filter) - (-1.8725161936714287 *
    rtDWork.Filter_FILT_STATES[6])) - (0.876729531743834 *
    rtDWork.Filter_FILT_STATES[7]);

    buffout = ((((resonance * 24) * rtDWork.Filter_FILT_STATES[6]) + denAccum) +

        rtDWork.Filter_FILT_STATES[7]) * (1 - (cutoff));


    out = fastClipLp(in * cutoff + (buffout * cutoff), -1, 1);



    rtDWork.Filter_FILT_STATES[7] = rtDWork.Filter_FILT_STATES[6];
    rtDWork.Filter_FILT_STATES[6] = denAccum;

  }
    if(mode ==3){
    
    denAccum = ((0.48480157505051247 * in) - (-0.26232243101142766 *
    rtDWork.Filter_FILT_STATES[0])) - (0.67688386919062227 *
    rtDWork.Filter_FILT_STATES[1]);
    rtb_Filter = ((-2.0 * rtDWork.Filter_FILT_STATES[0]) + denAccum) +
    rtDWork.Filter_FILT_STATES[1];
    rtDWork.Filter_FILT_STATES[1] = rtDWork.Filter_FILT_STATES[0];
    rtDWork.Filter_FILT_STATES[0] = denAccum;
    denAccum = ((0.37334922313323943 * rtb_Filter) - (-0.20201641427904798 *
    rtDWork.Filter_FILT_STATES[2])) - (0.29138047825390978 *
    rtDWork.Filter_FILT_STATES[3]);
    rtb_Filter= ((-2.0 * rtDWork.Filter_FILT_STATES[2]) + denAccum) +
    rtDWork.Filter_FILT_STATES[3];
    rtDWork.Filter_FILT_STATES[3] = rtDWork.Filter_FILT_STATES[2];
    rtDWork.Filter_FILT_STATES[2] = denAccum;
    denAccum = ((0.31748671520907257 * rtb_Filter) - (-0.17178963772714476 *
    rtDWork.Filter_FILT_STATES[4])) - (0.098157223109145458 *
    rtDWork.Filter_FILT_STATES[5]);
    rtb_Filter = ((-2.0 * rtDWork.Filter_FILT_STATES[4]) + denAccum) +
    rtDWork.Filter_FILT_STATES[5];
    rtDWork.Filter_FILT_STATES[5] = rtDWork.Filter_FILT_STATES[4];
    rtDWork.Filter_FILT_STATES[4] = denAccum;
    denAccum = ((0.29370358146567149 * rtb_Filter) - (-0.15892076563243498 *
    rtDWork.Filter_FILT_STATES[6])) - (0.015893560230250979 *
    rtDWork.Filter_FILT_STATES[7]);

    buffout = ((((resonance * 24) * rtDWork.Filter_FILT_STATES[6]) + denAccum) +

        rtDWork.Filter_FILT_STATES[7]) * (1 - (cutoff));


    out = fastClipLp(in * cutoff + (buffout * cutoff), -1, 1);



    rtDWork.Filter_FILT_STATES[7] = rtDWork.Filter_FILT_STATES[6];
    rtDWork.Filter_FILT_STATES[6] = denAccum;

    }
    if(mode ==4){
        
        
        denAccum = ((0.7500800767933764 * in - (-1.2427733626946766 *
        rtDWork.Filter_FILT_STATES[0])) - (0.75754694447882909 *
        rtDWork.Filter_FILT_STATES[1]));
        rtb_Filter = ((-2.0 * rtDWork.Filter_FILT_STATES[0]) + denAccum) +
        rtDWork.Filter_FILT_STATES[1];
        rtDWork.Filter_FILT_STATES[1] = rtDWork.Filter_FILT_STATES[0];
        rtDWork.Filter_FILT_STATES[0] = denAccum;
        denAccum = ((0.61281181417471153 * rtb_Filter) - (-1.0153398584545057 *
        rtDWork.Filter_FILT_STATES[2])) - (0.4359073982443406 *
        rtDWork.Filter_FILT_STATES[3]);
        rtb_Filter = ((-2.0 * rtDWork.Filter_FILT_STATES[2]) + denAccum) +
        rtDWork.Filter_FILT_STATES[3];
        rtDWork.Filter_FILT_STATES[3] = rtDWork.Filter_FILT_STATES[2];
        rtDWork.Filter_FILT_STATES[2] = denAccum;
        denAccum = ((0.53752318884470351 * rtb_Filter) - (-0.89059757963804209 *
        rtDWork.Filter_FILT_STATES[4])) - (0.2594951757407718 *
        rtDWork.Filter_FILT_STATES[5]);
        rtb_Filter = ((-2.0 * rtDWork.Filter_FILT_STATES[4]) + denAccum) +
        rtDWork.Filter_FILT_STATES[5];
        rtDWork.Filter_FILT_STATES[5] = rtDWork.Filter_FILT_STATES[4];
        rtDWork.Filter_FILT_STATES[4] = denAccum;
        denAccum = ((0.50401142565365409 * rtb_Filter) - (-0.83507347238696961 *
        rtDWork.Filter_FILT_STATES[6])) - (0.18097223022764669 *
        rtDWork.Filter_FILT_STATES[7]);


        buffout = ((((resonance * 48) * rtDWork.Filter_FILT_STATES[6]) + denAccum) +

            rtDWork.Filter_FILT_STATES[7]) * (1 - (cutoff));


        out = fastClipLp(in * cutoff + (buffout * cutoff), -1, 1);



        rtDWork.Filter_FILT_STATES[7] = rtDWork.Filter_FILT_STATES[6];
        rtDWork.Filter_FILT_STATES[6] = denAccum;
        
    }

   


}

// Model initialize function
void discretFilterModelClass::initialize()
{
    mode = 0;
   buffout = 0;
   rtDWork.Filter_FILT_STATES[0] = 0;
   rtDWork.Filter_FILT_STATES[1] = 0;
   rtDWork.Filter_FILT_STATES[2] = 0;
   rtDWork.Filter_FILT_STATES[3] = 0;
   rtDWork.Filter_FILT_STATES[4] = 0;
   rtDWork.Filter_FILT_STATES[5] = 0;
   rtDWork.Filter_FILT_STATES[6] = 0;
   rtDWork.Filter_FILT_STATES[7] = 0;
   cutoff = 1;
   cutoffM = 0;
   cutoffMod = 0;
   resonance = 0;
   buffout = 0;
   v1 = 0;
}

// Constructor
discretFilterModelClass::discretFilterModelClass()
{
    v1 = 0;
    mode = 0;
    cutoff=1;
    cutoffM=0;
    cutoffMod=0;
    resonance=0;
    buffout = 0;
}

// Destructor
discretFilterModelClass::~discretFilterModelClass()
{

}


