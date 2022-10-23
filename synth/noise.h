
#ifndef RTW_HEADER_noise_h_
#define RTW_HEADER_noise_h_
#include <stddef.h>
#include "../Source/rtwtypes.h"
#include <cmath>
#include <string.h>
#ifndef noise_COMMON_INCLUDES_
# define noise_COMMON_INCLUDES_
#include "../Source/rtwtypes.h"
#endif                                 // noise_COMMON_INCLUDES_
#define TABELSIZENOISE 1024
// Macros for accessing real-time model data structure

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#ifndef typedef_dsp_simulink_ColoredNoise
#define typedef_dsp_simulink_ColoredNoise

typedef struct {
  int32_T isInitialized;
  real_T pNumFilterCoef[2];
  real_T pDenFilterCoef;
  real_T pFilterStates;
  uint32_T pWNState[625];
} dsp_simulink_ColoredNoise;

#endif                                 //typedef_dsp_simulink_ColoredNoise

#ifndef typedef_dsp_simulink_ColoredNoise_k
#define typedef_dsp_simulink_ColoredNoise_k

typedef struct {
  int32_T isInitialized;
  real_T pNumFilterCoef;
  real_T pDenFilterCoef[64];
  real_T pFilterStates[63];
  uint32_T pWNState[625];
} dsp_simulink_ColoredNoise_k;

#endif                                 //typedef_dsp_simulink_ColoredNoise_k

#ifndef typedef_dsp_simulink_ColoredNoise_k3
#define typedef_dsp_simulink_ColoredNoise_k3

typedef struct {
  int32_T isInitialized;
  real_T pNumFilterCoef[256];
  real_T pDenFilterCoef;
  real_T pFilterStates[255];
  uint32_T pWNState[625];
} dsp_simulink_ColoredNoise_k3;

#endif                                 //typedef_dsp_simulink_ColoredNoise_k3

// Block signals and states (default storage) for system '<Root>'
typedef struct {
  dsp_simulink_ColoredNoise_k3 obj;    // '<Root>/Colored Noise'
  dsp_simulink_ColoredNoise_k obj_l;   // '<Root>/Colored Noise1'
  dsp_simulink_ColoredNoise_k obj_n;   // '<Root>/Colored Noise2'
  dsp_simulink_ColoredNoise obj_lf;    // '<Root>/Colored Noise3'
} D_WorkNoise;


// Real-time Model Data Structure
struct tag_RTM {
  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

// Class declaration for model noise
class noiseModelClass {
  // public data and function members
 public:
  // External outputs


  // model initialize function
  void initialize();

  // model step function
  void step(double*whitenoise,double *bluenoise,double *pinknoise,double*purplenoise);

  // Constructor
  noiseModelClass();

  // Destructor
  ~noiseModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Block signals and states
  D_WorkNoise rtDWork;

  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>'
  void genrand_uint32_vector_k(const uint32_T mt[625], uint32_T b_mt[625],
    uint32_T u[2]);
  void genrandu_k(const uint32_T mt[625], uint32_T b_mt[625], real_T *r);
  void eml_rand_mt19937ar_k(const uint32_T state[625], uint32_T b_state[625],
    real_T *r);
  void ColoredNoise_getExcitationNoi_k(dsp_simulink_ColoredNoise_k *obj, real_T
    whiteNoise[TABELSIZENOISE]);
  void SystemCore_step_k(dsp_simulink_ColoredNoise_k *obj, real_T varargout_1
    [TABELSIZENOISE]);
  void genrand_uint32_vector_k3(const uint32_T mt[625], uint32_T b_mt[625],
    uint32_T u[2]);
  void genrandu_k3(const uint32_T mt[625], uint32_T b_mt[625], real_T *r);
  void eml_rand_mt19937ar_k3(const uint32_T state[625], uint32_T b_state[625],
    real_T *r);
  void ColoredNoise_getExcitationNo_k3(dsp_simulink_ColoredNoise_k3 *obj, real_T
    whiteNoise[TABELSIZENOISE]);
  void SystemCore_step_k3(dsp_simulink_ColoredNoise_k3 *obj, real_T varargout_1
    [TABELSIZENOISE]);
  void genrand_uint32_vector(const uint32_T mt[625], uint32_T b_mt[625],
    uint32_T u[2]);
  void genrandu(const uint32_T mt[625], uint32_T b_mt[625], real_T *r);
  void eml_rand_mt19937ar(const uint32_T state[625], uint32_T b_state[625],
    real_T *r);
  void ColoredNoise_getExcitationNoise(dsp_simulink_ColoredNoise *obj, real_T
    whiteNoise[TABELSIZENOISE]);
  void SystemCore_step(dsp_simulink_ColoredNoise *obj, real_T varargout_1[TABELSIZENOISE]);
  void ColoredNoise_resetImpl_k(dsp_simulink_ColoredNoise_k *obj);
  void ColoredNoise_resetImpl_k3(dsp_simulink_ColoredNoise_k3 *obj);
  void ColoredNoise_resetImpl(dsp_simulink_ColoredNoise *obj);
};



#endif                                 // RTW_HEADER_noise_h_

