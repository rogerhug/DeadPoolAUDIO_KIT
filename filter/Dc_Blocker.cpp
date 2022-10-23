
#include "Dc_Blocker.h"



void dc_block_Fir8::SystemCore_release(dspcodegen_FIRFilter *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

void dc_block_Fir8::DCBlocker_releaseImpl(dsp_DCBlocker *obj)
{
  SystemCore_release(&obj->pFilter);
  obj->pNumChannels = -1;
}

void dc_block_Fir8::SystemCore_releaseWrapper_n(dsp_DCBlocker *obj)
{

  if (obj->isSetupComplete) {
    DCBlocker_releaseImpl(obj);
  }

}

void dc_block_Fir8::SystemCore_release_n(dsp_DCBlocker *obj)
{
  if (obj->isInitialized == 1) {
    SystemCore_releaseWrapper_n(obj);
  }

}

void dc_block_Fir8::SystemCore_delete_n(dsp_DCBlocker *obj)
{
  SystemCore_release_n(obj);
}

void dc_block_Fir8::step(double in,double&out,double dc)
{
  dsp_DCBlocker *obj;
  real_T varargout_1;
  dspcodegen_FIRFilter *obj_0;
  dsp_FIRFilter_0 *obj_1;
  real_T acc1;
  real_T acc2;
  int32_T j;

  obj = &rtDWork_Dc_Fir8.obj;
  obj_0 = &rtDWork_Dc_Fir8.obj.pFilter;


    
    // System object Initialization function: dsp.FIRFilter

    for (int i = 0; i < 8; i++) {
        obj_0->cSFunObject.P1_Coefficients[i] = 0.2151115;
    }
    if (obj->pFilter.isInitialized != 1) {
    obj->pFilter.isSetupComplete = true;
    obj->pFilter.isInitialized = 1;
    obj->pFilter.isSetupComplete = true;
   
    for (j = 0; j < 7; j++) {
        obj_0->cSFunObject.W0_states[j] =  obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj->pFilter.cSFunObject;

  // System object Outputs function: dsp.FIRFilter
  acc1 = obj->pFilter.cSFunObject.W0_states[0];
  acc2 = in * obj->pFilter.cSFunObject.P1_Coefficients[0U];
  varargout_1 = acc1 + acc2;
  for (j = 0; j < 6; j++) {
    acc1 = obj_1->W0_states[j + 1];
    acc2 = obj_1->P1_Coefficients[j + 1] * in;
    acc1 += acc2;
    obj_1->W0_states[j] = acc1;
  }

  acc1 = in * obj->pFilter.cSFunObject.P1_Coefficients[7U];
  obj->pFilter.cSFunObject.W0_states[6] = acc1;


  out = in - varargout_1;
}

// Model initialize function
void dc_block_Fir8::initialize()
{
  {
    dsp_DCBlocker *obj;
    dspcodegen_FIRFilter *obj_0;
    int32_T i;


    rtDWork_Dc_Fir8.obj.isInitialized = 0;
    rtDWork_Dc_Fir8.obj.pNumChannels = -1;
    obj = &rtDWork_Dc_Fir8.obj;
    rtDWork_Dc_Fir8.obj.isSetupComplete = false;
    rtDWork_Dc_Fir8.obj.isInitialized = 1;
    rtDWork_Dc_Fir8.obj.pNumChannels = 1;
    obj_0 = &rtDWork_Dc_Fir8.obj.pFilter;
    obj->pFilter.isInitialized = 0;

    // System object Constructor function: dsp.FIRFilter
    obj_0->cSFunObject.P0_InitialStates = 0.0;
    
    for (i = 0; i < 8; i++) {
      obj_0->cSFunObject.P1_Coefficients[i] = 0.325;
    }

      rtDWork_Dc_Fir8.obj.isSetupComplete = true;

    obj = &rtDWork_Dc_Fir8.obj;
    obj_0 = &rtDWork_Dc_Fir8.obj.pFilter;
    if (obj->pFilter.isInitialized == 1) {
      // System object Initialization function: dsp.FIRFilter
      for (i = 0; i < 7; i++) {
        obj_0->cSFunObject.W0_states[i] = obj_0->cSFunObject.P0_InitialStates;
      }
    }
  }
}

// Constructor
dc_block_Fir8::dc_block_Fir8()
{
}

// Destructor
dc_block_Fir8::~dc_block_Fir8()
{
  // Currently there is no destructor body generated.
}

