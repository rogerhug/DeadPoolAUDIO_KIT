
#include "rtwtypes.h"
                                // dc_block_Fir8_COMMON_INCLUDES_


#ifndef struct_firParas
#define struct_firParas

struct firParas
{
  int32_T S0_isInitialized;
  real_T W0_states[7];
  real_T P0_InitialStates;
  real_T P1_Coefficients[8];
};

#endif                                 //struct_firParas

#ifndef typedef_dsp_FIRFilter_0
#define typedef_dsp_FIRFilter_0

typedef struct firParas dsp_FIRFilter_0;

#endif                                 //typedef_dsp_FIRFilter_0

#ifndef struct_Dsp_DcInit
#define struct_Dsp_DcInit

struct Dsp_DcInit
{
;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  dsp_FIRFilter_0 cSFunObject;
};

#endif                                 //struct_Dsp_DcInit

#ifndef typedef_dspcodegen_FIRFilter
#define typedef_dspcodegen_FIRFilter

typedef struct Dsp_DcInit dspcodegen_FIRFilter;

#endif                                 //typedef_dspcodegen_FIRFilter

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct {
  uint32_T f1[8];
} cell_wrap;

#endif                                 //typedef_cell_wrap

#ifndef struct_Dsp_Dc
#define struct_Dsp_Dc

struct Dsp_Dc
{

  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap inputVarSize;
  dspcodegen_FIRFilter pFilter;
  int32_T pNumChannels;
};

#endif                                 //struct_Dsp_Dc

#ifndef typedef_dsp_DCBlocker
#define typedef_dsp_DCBlocker

typedef struct Dsp_Dc dsp_DCBlocker;

#endif                                 //typedef_dsp_DCBlocker

typedef struct {
  dsp_DCBlocker obj;                   // '<Root>/DC Blocker'
  boolean_T isInitialized;             // '<Root>/DC Blocker'
} DSP_Work_Dc_fir8;



class dc_block_Fir8 {

 public:
  dc_block_Fir8();
  ~dc_block_Fir8();
  void initialize();
  void step(double in,double&out,double dc);
 private:
  DSP_Work_Dc_fir8 rtDWork_Dc_Fir8;
  void SystemCore_release(dspcodegen_FIRFilter *obj);
  void DCBlocker_releaseImpl(dsp_DCBlocker *obj);
  void SystemCore_releaseWrapper_n(dsp_DCBlocker *obj);
  void SystemCore_release_n(dsp_DCBlocker *obj);
  void SystemCore_delete_n(dsp_DCBlocker *obj);

};

