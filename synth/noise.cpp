
#include "noise.h"
#define Seed                           (67.0)
#define NumBitsPerChar                 8U

static void rate_scheduler(RT_MODEL *const rtM);
extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    return (boolean_T)((value!=value) ? 1U : 0U);
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    return (boolean_T)(((value!=value) ? 1U : 0U));
  }
}
  extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}
//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
  static void rate_scheduler(RT_MODEL *const rtM)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > TABELSIZENOISE-1) {// Sample time: [0.512s, 0.0s]
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

void noiseModelClass::genrand_uint32_vector_k(const uint32_T mt[625], uint32_T
  b_mt[625], uint32_T u[2])
{
  uint32_T mti;
  uint32_T y;
  int32_T b_j;
  int32_T b_kk;
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));
  for (b_j = 0; b_j < 2; b_j++) {
    mti = b_mt[624] + 1U;
    if (mti >= 625U) {
      for (b_kk = 0; b_kk < 227; b_kk++) {
        y = (b_mt[b_kk + 1] & 2147483647U) | (b_mt[b_kk] & 2147483648U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk] = b_mt[b_kk + 397] ^ y;
      }

      for (b_kk = 0; b_kk < 396; b_kk++) {
        y = (b_mt[b_kk + 227] & 2147483648U) | (b_mt[b_kk + 228] & 2147483647U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk + 227] = b_mt[b_kk] ^ y;
      }

      y = (b_mt[623] & 2147483648U) | (b_mt[0] & 2147483647U);
      mti = 1U;
      if (((int32_T)(y & 1U)) == 0) {
        y >>= 1U;
      } else {
        y = (y >> 1U) ^ 2567483615U;
      }

      b_mt[623] = b_mt[396] ^ y;
    }

    y = b_mt[((int32_T)mti) - 1];
    b_mt[624] = mti;
    y ^= (y >> 11U);
    y ^= (y << 7U) & 2636928640U;
    y ^= (y << 15U) & 4022730752U;
    u[b_j] = (y >> 18U) ^ y;
  }
}

void noiseModelClass::genrandu_k(const uint32_T mt[625], uint32_T b_mt[625],
  real_T *r)
{
  uint32_T b_u[2];
  uint32_T b_mt_0[625];
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  do {
    memcpy(&b_mt_0[0], &b_mt[0], 625U * (sizeof(uint32_T)));
    genrand_uint32_vector_k(b_mt_0, b_mt, b_u);
    *r = ((((real_T)(b_u[0] >> 5U)) * 6.7108864E+7) + ((real_T)(b_u[1] >> 6U))) *
      1.1102230246251565E-16;
  } while ((*r) == 0.0);
}

void noiseModelClass::eml_rand_mt19937ar_k(const uint32_T state[625], uint32_T
  b_state[625], real_T *r)
{
  real_T xi[257];
  int32_T i;
  real_T x;
  uint32_T c_mt[625];
  uint32_T u32[2];
  real_T d_u;
  static const real_T tmp[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  const real_T *fitab;
  int32_T exitg1;
  memcpy(&b_state[0], &state[0], 625U * (sizeof(uint32_T)));
  xi[0] = 0.0;
  xi[1] = 0.215241895984875;
  xi[2] = 0.286174591792068;
  xi[3] = 0.335737519214422;
  xi[4] = 0.375121332878378;
  xi[5] = 0.408389134611989;
  xi[6] = 0.43751840220787;
  xi[7] = 0.46363433679088;
  xi[8] = 0.487443966139235;
  xi[9] = 0.50942332960209;
  xi[10] = 0.529909720661557;
  xi[11] = 0.549151702327164;
  xi[12] = 0.567338257053817;
  xi[13] = 0.584616766106378;
  xi[14] = 0.601104617755991;
  xi[15] = 0.61689699000775;
  xi[16] = 0.63207223638606;
  xi[17] = 0.646695714894993;
  xi[18] = 0.660822574244419;
  xi[19] = 0.674499822837293;
  xi[20] = 0.687767892795788;
  xi[21] = 0.700661841106814;
  xi[22] = 0.713212285190975;
  xi[23] = 0.725446140909999;
  xi[24] = 0.737387211434295;
  xi[25] = 0.749056662017815;
  xi[26] = 0.760473406430107;
  xi[27] = 0.771654424224568;
  xi[28] = 0.782615023307232;
  xi[29] = 0.793369058840623;
  xi[30] = 0.80392911698997;
  xi[31] = 0.814306670135215;
  xi[32] = 0.824512208752291;
  xi[33] = 0.834555354086381;
  xi[34] = 0.844444954909153;
  xi[35] = 0.854189171008163;
  xi[36] = 0.863795545553308;
  xi[37] = 0.87327106808886;
  xi[38] = 0.882622229585165;
  xi[39] = 0.891855070732941;
  xi[40] = 0.900975224461221;
  xi[41] = 0.909987953496718;
  xi[42] = 0.91889818364959;
  xi[43] = 0.927710533401999;
  xi[44] = 0.936429340286575;
  xi[45] = 0.945058684468165;
  xi[46] = 0.953602409881086;
  xi[47] = 0.96206414322304;
  xi[48] = 0.970447311064224;
  xi[49] = 0.978755155294224;
  xi[50] = 0.986990747099062;
  xi[51] = 0.99515699963509;
  xi[52] = 1.00325667954467;
  xi[53] = 1.01129241744;
  xi[54] = 1.01926671746548;
  xi[55] = 1.02718196603564;
  xi[56] = 1.03504043983344;
  xi[57] = 1.04284431314415;
  xi[58] = 1.05059566459093;
  xi[59] = 1.05829648333067;
  xi[60] = 1.06594867476212;
  xi[61] = 1.07355406579244;
  xi[62] = 1.0811144097034;
  xi[63] = 1.08863139065398;
  xi[64] = 1.09610662785202;
  xi[65] = 1.10354167942464;
  xi[66] = 1.11093804601357;
  xi[67] = 1.11829717411934;
  xi[68] = 1.12562045921553;
  xi[69] = 1.13290924865253;
  xi[70] = 1.14016484436815;
  xi[71] = 1.14738850542085;
  xi[72] = 1.15458145035993;
  xi[73] = 1.16174485944561;
  xi[74] = 1.16887987673083;
  xi[75] = 1.17598761201545;
  xi[76] = 1.18306914268269;
  xi[77] = 1.19012551542669;
  xi[78] = 1.19715774787944;
  xi[79] = 1.20416683014438;
  xi[80] = 1.2111537262437;
  xi[81] = 1.21811937548548;
  xi[82] = 1.22506469375653;
  xi[83] = 1.23199057474614;
  xi[84] = 1.23889789110569;
  xi[85] = 1.24578749554863;
  xi[86] = 1.2526602218949;
  xi[87] = 1.25951688606371;
  xi[88] = 1.26635828701823;
  xi[89] = 1.27318520766536;
  xi[90] = 1.27999841571382;
  xi[91] = 1.28679866449324;
  xi[92] = 1.29358669373695;
  xi[93] = 1.30036323033084;
  xi[94] = 1.30712898903073;
  xi[95] = 1.31388467315022;
  xi[96] = 1.32063097522106;
  xi[97] = 1.32736857762793;
  xi[98] = 1.33409815321936;
  xi[99] = 1.3408203658964;
  xi[100] = 1.34753587118059;
  xi[101] = 1.35424531676263;
  xi[102] = 1.36094934303328;
  xi[103] = 1.36764858359748;
  xi[104] = 1.37434366577317;
  xi[105] = 1.38103521107586;
  xi[106] = 1.38772383568998;
  xi[107] = 1.39441015092814;
  xi[108] = 1.40109476367925;
  xi[109] = 1.4077782768464;
  xi[110] = 1.41446128977547;
  xi[111] = 1.42114439867531;
  xi[112] = 1.42782819703026;
  xi[113] = 1.43451327600589;
  xi[114] = 1.44120022484872;
  xi[115] = 1.44788963128058;
  xi[116] = 1.45458208188841;
  xi[117] = 1.46127816251028;
  xi[118] = 1.46797845861808;
  xi[119] = 1.47468355569786;
  xi[120] = 1.48139403962819;
  xi[121] = 1.48811049705745;
  xi[122] = 1.49483351578049;
  xi[123] = 1.50156368511546;
  xi[124] = 1.50830159628131;
  xi[125] = 1.51504784277671;
  xi[126] = 1.521803020761;
  xi[127] = 1.52856772943771;
  xi[128] = 1.53534257144151;
  xi[129] = 1.542128153229;
  xi[130] = 1.54892508547417;
  xi[131] = 1.55573398346918;
  xi[132] = 1.56255546753104;
  xi[133] = 1.56939016341512;
  xi[134] = 1.57623870273591;
  xi[135] = 1.58310172339603;
  xi[136] = 1.58997987002419;
  xi[137] = 1.59687379442279;
  xi[138] = 1.60378415602609;
  xi[139] = 1.61071162236983;
  xi[140] = 1.61765686957301;
  xi[141] = 1.62462058283303;
  xi[142] = 1.63160345693487;
  xi[143] = 1.63860619677555;
  xi[144] = 1.64562951790478;
  xi[145] = 1.65267414708306;
  xi[146] = 1.65974082285818;
  xi[147] = 1.66683029616166;
  xi[148] = 1.67394333092612;
  xi[149] = 1.68108070472517;
  xi[150] = 1.68824320943719;
  xi[151] = 1.69543165193456;
  xi[152] = 1.70264685479992;
  xi[153] = 1.7098896570713;
  xi[154] = 1.71716091501782;
  xi[155] = 1.72446150294804;
  xi[156] = 1.73179231405296;
  xi[157] = 1.73915426128591;
  xi[158] = 1.74654827828172;
  xi[159] = 1.75397532031767;
  xi[160] = 1.76143636531891;
  xi[161] = 1.76893241491127;
  xi[162] = 1.77646449552452;
  xi[163] = 1.78403365954944;
  xi[164] = 1.79164098655216;
  xi[165] = 1.79928758454972;
  xi[166] = 1.80697459135082;
  xi[167] = 1.81470317596628;
  xi[168] = 1.82247454009388;
  xi[169] = 1.83028991968276;
  xi[170] = 1.83815058658281;
  xi[171] = 1.84605785028518;
  xi[172] = 1.8540130597602;
  xi[173] = 1.86201760539967;
  xi[174] = 1.87007292107127;
  xi[175] = 1.878180486293;
  xi[176] = 1.88634182853678;
  xi[177] = 1.8945585256707;
  xi[178] = 1.90283220855043;
  xi[179] = 1.91116456377125;
  xi[180] = 1.91955733659319;
  xi[181] = 1.92801233405266;
  xi[182] = 1.93653142827569;
  xi[183] = 1.94511656000868;
  xi[184] = 1.95376974238465;
  xi[185] = 1.96249306494436;
  xi[186] = 1.97128869793366;
  xi[187] = 1.98015889690048;
  xi[188] = 1.98910600761744;
  xi[189] = 1.99813247135842;
  xi[190] = 2.00724083056053;
  xi[191] = 2.0164337349062;
  xi[192] = 2.02571394786385;
  xi[193] = 2.03508435372962;
  xi[194] = 2.04454796521753;
  xi[195] = 2.05410793165065;
  xi[196] = 2.06376754781173;
  xi[197] = 2.07353026351874;
  xi[198] = 2.0833996939983;
  xi[199] = 2.09337963113879;
  xi[200] = 2.10347405571488;
  xi[201] = 2.11368715068665;
  xi[202] = 2.12402331568952;
  xi[203] = 2.13448718284602;
  xi[204] = 2.14508363404789;
  xi[205] = 2.15581781987674;
  xi[206] = 2.16669518035431;
  xi[207] = 2.17772146774029;
  xi[208] = 2.18890277162636;
  xi[209] = 2.20024554661128;
  xi[210] = 2.21175664288416;
  xi[211] = 2.22344334009251;
  xi[212] = 2.23531338492992;
  xi[213] = 2.24737503294739;
  xi[214] = 2.25963709517379;
  xi[215] = 2.27210899022838;
  xi[216] = 2.28480080272449;
  xi[217] = 2.29772334890286;
  xi[218] = 2.31088825060137;
  xi[219] = 2.32430801887113;
  xi[220] = 2.33799614879653;
  xi[221] = 2.35196722737914;
  xi[222] = 2.36623705671729;
  xi[223] = 2.38082279517208;
  xi[224] = 2.39574311978193;
  xi[225] = 2.41101841390112;
  xi[226] = 2.42667098493715;
  xi[227] = 2.44272531820036;
  xi[228] = 2.4592083743347;
  xi[229] = 2.47614993967052;
  xi[230] = 2.49358304127105;
  xi[231] = 2.51154444162669;
  xi[232] = 2.53007523215985;
  xi[233] = 2.54922155032478;
  xi[234] = 2.56903545268184;
  xi[235] = 2.58957598670829;
  xi[236] = 2.61091051848882;
  xi[237] = 2.63311639363158;
  xi[238] = 2.65628303757674;
  xi[239] = 2.68051464328574;
  xi[240] = 2.70593365612306;
  xi[241] = 2.73268535904401;
  xi[242] = 2.76094400527999;
  xi[243] = 2.79092117400193;
  xi[244] = 2.82287739682644;
  xi[245] = 2.85713873087322;
  xi[246] = 2.89412105361341;
  xi[247] = 2.93436686720889;
  xi[248] = 2.97860327988184;
  xi[249] = 3.02783779176959;
  xi[250] = 3.08352613200214;
  xi[251] = 3.147889289518;
  xi[252] = 3.2245750520478;
  xi[253] = 3.32024473383983;
  xi[254] = 3.44927829856143;
  xi[255] = 3.65415288536101;
  xi[256] = 3.91075795952492;
  fitab = &tmp[0];
  do {
    exitg1 = 0;
    genrand_uint32_vector_k(b_state, c_mt, u32);
    memcpy(&b_state[0], &c_mt[0], 625U * (sizeof(uint32_T)));
    i = (int32_T)((u32[1] >> 24U) + 1U);
    *r = ((((((real_T)(u32[0] >> 3U)) * 1.6777216E+7) + ((real_T)(((int32_T)u32
               [1]) & 16777215))) * 2.2204460492503131E-16) - 1.0) * xi[i];
    if (std::abs(*r) <= xi[i - 1]) {
      exitg1 = 1;
    } else if (i < 256) {
      genrandu_k(c_mt, b_state, &x);
      if ((((fitab[i - 1] - fitab[i]) * x) + fitab[i]) < std::exp((-0.5 * (*r)) *
           (*r))) {
        exitg1 = 1;
      }
    } else {
      do {
        genrandu_k(b_state, c_mt, &x);
        x = std::log(x) * 0.273661237329758;
        genrandu_k(c_mt, b_state, &d_u);
      } while (!((-2.0 * std::log(d_u)) > (x * x)));

      if ((*r) < 0.0) {
        *r = x - 3.65415288536101;
      } else {
        *r = 3.65415288536101 - x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void noiseModelClass::ColoredNoise_getExcitationNoi_k
  (dsp_simulink_ColoredNoise_k *obj, real_T whiteNoise[TABELSIZENOISE])
{
  uint32_T state[625];
  int32_T b_rowIdx;
  uint32_T state_0[625];
  memcpy(&state[0], &obj->pWNState[0], 625U * (sizeof(uint32_T)));
  for (b_rowIdx = 0; b_rowIdx < TABELSIZENOISE; b_rowIdx++) {
    memcpy(&state_0[0], &state[0], 625U * (sizeof(uint32_T)));
    eml_rand_mt19937ar_k(state_0, state, &whiteNoise[b_rowIdx]);
  }

  memcpy(&obj->pWNState[0], &state[0], 625U * (sizeof(uint32_T)));
}

void noiseModelClass::SystemCore_step_k(dsp_simulink_ColoredNoise_k *obj, real_T
  varargout_1[TABELSIZENOISE])
{
  real_T whiteNoise[TABELSIZENOISE];
  real_T b[63];
  real_T b_0;
  real_T a[64];
  real_T as;
  int32_T naxpy;
  int32_T k;
  int32_T j;
  int32_T varargout_1_tmp;
  ColoredNoise_getExcitationNoi_k(obj, whiteNoise);
  b_0 = obj->pNumFilterCoef;
  memcpy(&a[0], &obj->pDenFilterCoef[0], (sizeof(real_T)) << 6U);
  if ((((!rtIsInf(obj->pDenFilterCoef[0])) && (!rtIsNaN(obj->pDenFilterCoef[0])))
       && (!(obj->pDenFilterCoef[0] == 0.0))) && (obj->pDenFilterCoef[0] != 1.0))
  {
    b_0 = obj->pNumFilterCoef / obj->pDenFilterCoef[0];
    for (k = 0; k < 63; k++) {
      a[k + 1] /= obj->pDenFilterCoef[0];
    }

    a[0] = 1.0;
  }

  for (k = 0; k < 63; k++) {
    b[k] = 0.0;
    varargout_1[k] = obj->pFilterStates[k];
  }

  memset(&varargout_1[63], 0, TABELSIZENOISE-63U * (sizeof(real_T)));
  for (k = 0; k < TABELSIZENOISE; k++) {
    for (j = 0; j < 1; j++) {
      varargout_1_tmp = k + j;
      varargout_1[varargout_1_tmp] += whiteNoise[k] * b_0;
    }

    naxpy = TABELSIZENOISE-1 - k;
    if (!(naxpy < 63)) {
      naxpy = 63;
    }

    as = -varargout_1[k];
    for (j = 1; j <= naxpy; j++) {
      varargout_1_tmp = k + j;
      varargout_1[varargout_1_tmp] += as * a[j];
    }
  }

  for (k = 0; k < 63; k++) {
    for (naxpy = 0; naxpy < (k + 1); naxpy++) {
      b[naxpy] += a[(naxpy - k) + 63] * (-varargout_1[k + TABELSIZENOISE-63]);
    }
  }

  memcpy(&obj->pFilterStates[0], &b[0], 63U * (sizeof(real_T)));
}

void noiseModelClass::genrand_uint32_vector_k3(const uint32_T mt[625], uint32_T
  b_mt[625], uint32_T u[2])
{
  uint32_T mti;
  uint32_T y;
  int32_T b_j;
  int32_T b_kk;

  // Start for MATLABSystem: '<Root>/Colored Noise'
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));
  for (b_j = 0; b_j < 2; b_j++) {
    mti = b_mt[624] + 1U;
    if (mti >= 625U) {
      for (b_kk = 0; b_kk < 227; b_kk++) {
        y = (b_mt[b_kk + 1] & 2147483647U) | (b_mt[b_kk] & 2147483648U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk] = b_mt[b_kk + 397] ^ y;
      }

      for (b_kk = 0; b_kk < 396; b_kk++) {
        y = (b_mt[b_kk + 227] & 2147483648U) | (b_mt[b_kk + 228] & 2147483647U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk + 227] = b_mt[b_kk] ^ y;
      }

      y = (b_mt[623] & 2147483648U) | (b_mt[0] & 2147483647U);
      mti = 1U;
      if (((int32_T)(y & 1U)) == 0) {
        y >>= 1U;
      } else {
        y = (y >> 1U) ^ 2567483615U;
      }

      b_mt[623] = b_mt[396] ^ y;
    }

    y = b_mt[((int32_T)mti) - 1];
    b_mt[624] = mti;
    y ^= (y >> 11U);
    y ^= (y << 7U) & 2636928640U;
    y ^= (y << 15U) & 4022730752U;
    u[b_j] = (y >> 18U) ^ y;
  }

  // End of Start for MATLABSystem: '<Root>/Colored Noise'
}

void noiseModelClass::genrandu_k3(const uint32_T mt[625], uint32_T b_mt[625],
  real_T *r)
{
  uint32_T b_u[2];
  uint32_T b_mt_0[625];

  // Start for MATLABSystem: '<Root>/Colored Noise'
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  // =============================   END   =================================
  do {
    memcpy(&b_mt_0[0], &b_mt[0], 625U * (sizeof(uint32_T)));
    genrand_uint32_vector_k3(b_mt_0, b_mt, b_u);
    *r = ((((real_T)(b_u[0] >> 5U)) * 6.7108864E+7) + ((real_T)(b_u[1] >> 6U))) *
      1.1102230246251565E-16;
  } while ((*r) == 0.0);
}

void noiseModelClass::eml_rand_mt19937ar_k3(const uint32_T state[625], uint32_T
  b_state[625], real_T *r)
{
  real_T xi[257];
  int32_T i;
  real_T x;
  uint32_T c_mt[625];
  uint32_T u32[2];
  real_T d_u;
  static const real_T tmp[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  const real_T *fitab;
  int32_T exitg1;

  // Start for MATLABSystem: '<Root>/Colored Noise'
  memcpy(&b_state[0], &state[0], 625U * (sizeof(uint32_T)));
  xi[0] = 0.0;
  xi[1] = 0.215241895984875;
  xi[2] = 0.286174591792068;
  xi[3] = 0.335737519214422;
  xi[4] = 0.375121332878378;
  xi[5] = 0.408389134611989;
  xi[6] = 0.43751840220787;
  xi[7] = 0.46363433679088;
  xi[8] = 0.487443966139235;
  xi[9] = 0.50942332960209;
  xi[10] = 0.529909720661557;
  xi[11] = 0.549151702327164;
  xi[12] = 0.567338257053817;
  xi[13] = 0.584616766106378;
  xi[14] = 0.601104617755991;
  xi[15] = 0.61689699000775;
  xi[16] = 0.63207223638606;
  xi[17] = 0.646695714894993;
  xi[18] = 0.660822574244419;
  xi[19] = 0.674499822837293;
  xi[20] = 0.687767892795788;
  xi[21] = 0.700661841106814;
  xi[22] = 0.713212285190975;
  xi[23] = 0.725446140909999;
  xi[24] = 0.737387211434295;
  xi[25] = 0.749056662017815;
  xi[26] = 0.760473406430107;
  xi[27] = 0.771654424224568;
  xi[28] = 0.782615023307232;
  xi[29] = 0.793369058840623;
  xi[30] = 0.80392911698997;
  xi[31] = 0.814306670135215;
  xi[32] = 0.824512208752291;
  xi[33] = 0.834555354086381;
  xi[34] = 0.844444954909153;
  xi[35] = 0.854189171008163;
  xi[36] = 0.863795545553308;
  xi[37] = 0.87327106808886;
  xi[38] = 0.882622229585165;
  xi[39] = 0.891855070732941;
  xi[40] = 0.900975224461221;
  xi[41] = 0.909987953496718;
  xi[42] = 0.91889818364959;
  xi[43] = 0.927710533401999;
  xi[44] = 0.936429340286575;
  xi[45] = 0.945058684468165;
  xi[46] = 0.953602409881086;
  xi[47] = 0.96206414322304;
  xi[48] = 0.970447311064224;
  xi[49] = 0.978755155294224;
  xi[50] = 0.986990747099062;
  xi[51] = 0.99515699963509;
  xi[52] = 1.00325667954467;
  xi[53] = 1.01129241744;
  xi[54] = 1.01926671746548;
  xi[55] = 1.02718196603564;
  xi[56] = 1.03504043983344;
  xi[57] = 1.04284431314415;
  xi[58] = 1.05059566459093;
  xi[59] = 1.05829648333067;
  xi[60] = 1.06594867476212;
  xi[61] = 1.07355406579244;
  xi[62] = 1.0811144097034;
  xi[63] = 1.08863139065398;
  xi[64] = 1.09610662785202;
  xi[65] = 1.10354167942464;
  xi[66] = 1.11093804601357;
  xi[67] = 1.11829717411934;
  xi[68] = 1.12562045921553;
  xi[69] = 1.13290924865253;
  xi[70] = 1.14016484436815;
  xi[71] = 1.14738850542085;
  xi[72] = 1.15458145035993;
  xi[73] = 1.16174485944561;
  xi[74] = 1.16887987673083;
  xi[75] = 1.17598761201545;
  xi[76] = 1.18306914268269;
  xi[77] = 1.19012551542669;
  xi[78] = 1.19715774787944;
  xi[79] = 1.20416683014438;
  xi[80] = 1.2111537262437;
  xi[81] = 1.21811937548548;
  xi[82] = 1.22506469375653;
  xi[83] = 1.23199057474614;
  xi[84] = 1.23889789110569;
  xi[85] = 1.24578749554863;
  xi[86] = 1.2526602218949;
  xi[87] = 1.25951688606371;
  xi[88] = 1.26635828701823;
  xi[89] = 1.27318520766536;
  xi[90] = 1.27999841571382;
  xi[91] = 1.28679866449324;
  xi[92] = 1.29358669373695;
  xi[93] = 1.30036323033084;
  xi[94] = 1.30712898903073;
  xi[95] = 1.31388467315022;
  xi[96] = 1.32063097522106;
  xi[97] = 1.32736857762793;
  xi[98] = 1.33409815321936;
  xi[99] = 1.3408203658964;
  xi[100] = 1.34753587118059;
  xi[101] = 1.35424531676263;
  xi[102] = 1.36094934303328;
  xi[103] = 1.36764858359748;
  xi[104] = 1.37434366577317;
  xi[105] = 1.38103521107586;
  xi[106] = 1.38772383568998;
  xi[107] = 1.39441015092814;
  xi[108] = 1.40109476367925;
  xi[109] = 1.4077782768464;
  xi[110] = 1.41446128977547;
  xi[111] = 1.42114439867531;
  xi[112] = 1.42782819703026;
  xi[113] = 1.43451327600589;
  xi[114] = 1.44120022484872;
  xi[115] = 1.44788963128058;
  xi[116] = 1.45458208188841;
  xi[117] = 1.46127816251028;
  xi[118] = 1.46797845861808;
  xi[119] = 1.47468355569786;
  xi[120] = 1.48139403962819;
  xi[121] = 1.48811049705745;
  xi[122] = 1.49483351578049;
  xi[123] = 1.50156368511546;
  xi[124] = 1.50830159628131;
  xi[125] = 1.51504784277671;
  xi[126] = 1.521803020761;
  xi[127] = 1.52856772943771;
  xi[128] = 1.53534257144151;
  xi[129] = 1.542128153229;
  xi[130] = 1.54892508547417;
  xi[131] = 1.55573398346918;
  xi[132] = 1.56255546753104;
  xi[133] = 1.56939016341512;
  xi[134] = 1.57623870273591;
  xi[135] = 1.58310172339603;
  xi[136] = 1.58997987002419;
  xi[137] = 1.59687379442279;
  xi[138] = 1.60378415602609;
  xi[139] = 1.61071162236983;
  xi[140] = 1.61765686957301;
  xi[141] = 1.62462058283303;
  xi[142] = 1.63160345693487;
  xi[143] = 1.63860619677555;
  xi[144] = 1.64562951790478;
  xi[145] = 1.65267414708306;
  xi[146] = 1.65974082285818;
  xi[147] = 1.66683029616166;
  xi[148] = 1.67394333092612;
  xi[149] = 1.68108070472517;
  xi[150] = 1.68824320943719;
  xi[151] = 1.69543165193456;
  xi[152] = 1.70264685479992;
  xi[153] = 1.7098896570713;
  xi[154] = 1.71716091501782;
  xi[155] = 1.72446150294804;
  xi[156] = 1.73179231405296;
  xi[157] = 1.73915426128591;
  xi[158] = 1.74654827828172;
  xi[159] = 1.75397532031767;
  xi[160] = 1.76143636531891;
  xi[161] = 1.76893241491127;
  xi[162] = 1.77646449552452;
  xi[163] = 1.78403365954944;
  xi[164] = 1.79164098655216;
  xi[165] = 1.79928758454972;
  xi[166] = 1.80697459135082;
  xi[167] = 1.81470317596628;
  xi[168] = 1.82247454009388;
  xi[169] = 1.83028991968276;
  xi[170] = 1.83815058658281;
  xi[171] = 1.84605785028518;
  xi[172] = 1.8540130597602;
  xi[173] = 1.86201760539967;
  xi[174] = 1.87007292107127;
  xi[175] = 1.878180486293;
  xi[176] = 1.88634182853678;
  xi[177] = 1.8945585256707;
  xi[178] = 1.90283220855043;
  xi[179] = 1.91116456377125;
  xi[180] = 1.91955733659319;
  xi[181] = 1.92801233405266;
  xi[182] = 1.93653142827569;
  xi[183] = 1.94511656000868;
  xi[184] = 1.95376974238465;
  xi[185] = 1.96249306494436;
  xi[186] = 1.97128869793366;
  xi[187] = 1.98015889690048;
  xi[188] = 1.98910600761744;
  xi[189] = 1.99813247135842;
  xi[190] = 2.00724083056053;
  xi[191] = 2.0164337349062;
  xi[192] = 2.02571394786385;
  xi[193] = 2.03508435372962;
  xi[194] = 2.04454796521753;
  xi[195] = 2.05410793165065;
  xi[196] = 2.06376754781173;
  xi[197] = 2.07353026351874;
  xi[198] = 2.0833996939983;
  xi[199] = 2.09337963113879;
  xi[200] = 2.10347405571488;
  xi[201] = 2.11368715068665;
  xi[202] = 2.12402331568952;
  xi[203] = 2.13448718284602;
  xi[204] = 2.14508363404789;
  xi[205] = 2.15581781987674;
  xi[206] = 2.16669518035431;
  xi[207] = 2.17772146774029;
  xi[208] = 2.18890277162636;
  xi[209] = 2.20024554661128;
  xi[210] = 2.21175664288416;
  xi[211] = 2.22344334009251;
  xi[212] = 2.23531338492992;
  xi[213] = 2.24737503294739;
  xi[214] = 2.25963709517379;
  xi[215] = 2.27210899022838;
  xi[216] = 2.28480080272449;
  xi[217] = 2.29772334890286;
  xi[218] = 2.31088825060137;
  xi[219] = 2.32430801887113;
  xi[220] = 2.33799614879653;
  xi[221] = 2.35196722737914;
  xi[222] = 2.36623705671729;
  xi[223] = 2.38082279517208;
  xi[224] = 2.39574311978193;
  xi[225] = 2.41101841390112;
  xi[226] = 2.42667098493715;
  xi[227] = 2.44272531820036;
  xi[228] = 2.4592083743347;
  xi[229] = 2.47614993967052;
  xi[230] = 2.49358304127105;
  xi[231] = 2.51154444162669;
  xi[232] = 2.53007523215985;
  xi[233] = 2.54922155032478;
  xi[234] = 2.56903545268184;
  xi[235] = 2.58957598670829;
  xi[236] = 2.61091051848882;
  xi[237] = 2.63311639363158;
  xi[238] = 2.65628303757674;
  xi[239] = 2.68051464328574;
  xi[240] = 2.70593365612306;
  xi[241] = 2.73268535904401;
  xi[242] = 2.76094400527999;
  xi[243] = 2.79092117400193;
  xi[244] = 2.82287739682644;
  xi[245] = 2.85713873087322;
  xi[246] = 2.89412105361341;
  xi[247] = 2.93436686720889;
  xi[248] = 2.97860327988184;
  xi[249] = 3.02783779176959;
  xi[250] = 3.08352613200214;
  xi[251] = 3.147889289518;
  xi[252] = 3.2245750520478;
  xi[253] = 3.32024473383983;
  xi[254] = 3.44927829856143;
  xi[255] = 3.65415288536101;
  xi[256] = 3.91075795952492;
  fitab = &tmp[0];
  do {
    exitg1 = 0;
    genrand_uint32_vector_k3(b_state, c_mt, u32);
    memcpy(&b_state[0], &c_mt[0], 625U * (sizeof(uint32_T)));
    i = (int32_T)((u32[1] >> 24U) + 1U);
    *r = ((((((real_T)(u32[0] >> 3U)) * 1.6777216E+7) + ((real_T)(((int32_T)u32
               [1]) & 16777215))) * 2.2204460492503131E-16) - 1.0) * xi[i];
    if (std::abs(*r) <= xi[i - 1]) {
      exitg1 = 1;
    } else if (i < 256) {
      genrandu_k3(c_mt, b_state, &x);
      if ((((fitab[i - 1] - fitab[i]) * x) + fitab[i]) < std::exp((-0.5 * (*r)) *
           (*r))) {
        exitg1 = 1;
      }
    } else {
      do {
        genrandu_k3(b_state, c_mt, &x);
        x = std::log(x) * 0.273661237329758;
        genrandu_k3(c_mt, b_state, &d_u);
      } while (!((-2.0 * std::log(d_u)) > (x * x)));

      if ((*r) < 0.0) {
        *r = x - 3.65415288536101;
      } else {
        *r = 3.65415288536101 - x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void noiseModelClass::ColoredNoise_getExcitationNo_k3
  (dsp_simulink_ColoredNoise_k3 *obj, real_T whiteNoise[TABELSIZENOISE])
{
  uint32_T state[625];
  int32_T b_rowIdx;
  uint32_T state_0[625];

  // Start for MATLABSystem: '<Root>/Colored Noise'
  memcpy(&state[0], &obj->pWNState[0], 625U * (sizeof(uint32_T)));
  for (b_rowIdx = 0; b_rowIdx < TABELSIZENOISE; b_rowIdx++) {
    memcpy(&state_0[0], &state[0], 625U * (sizeof(uint32_T)));
    eml_rand_mt19937ar_k3(state_0, state, &whiteNoise[b_rowIdx]);
  }

  memcpy(&obj->pWNState[0], &state[0], 625U * (sizeof(uint32_T)));

  // End of Start for MATLABSystem: '<Root>/Colored Noise'
}

void noiseModelClass::SystemCore_step_k3(dsp_simulink_ColoredNoise_k3 *obj,
  real_T varargout_1[TABELSIZENOISE])
{
  real_T whiteNoise[TABELSIZENOISE];
  real_T b[255];
  real_T b_0[256];
  int32_T k;
  int32_T b_j;

  // Start for MATLABSystem: '<Root>/Colored Noise'
  ColoredNoise_getExcitationNo_k3(obj, whiteNoise);
  memcpy(&b_0[0], &obj->pNumFilterCoef[0], (sizeof(real_T)) << 8U);
  if ((((!rtIsInf(obj->pDenFilterCoef)) && (!rtIsNaN(obj->pDenFilterCoef))) && (
        !(obj->pDenFilterCoef == 0.0))) && (obj->pDenFilterCoef != 1.0)) {
    for (k = 0; k < 256; k++) {
      b_0[k] /= obj->pDenFilterCoef;
    }
  }

  for (k = 0; k < 255; k++) {
    b[k] = 0.0;
    varargout_1[k] = obj->pFilterStates[k];
  }

  memset(&varargout_1[255], 0, 257U * (sizeof(real_T)));
  for (k = 0; k < 256; k++) {
    for (b_j = k + 1; b_j < TABELSIZENOISE+1; b_j++) {
      varargout_1[b_j - 1] += whiteNoise[(b_j - k) - 1] * b_0[k];
    }
  }

  for (k = 0; k < 255; k++) {
    for (b_j = 0; b_j < (k + 1); b_j++) {
      b[b_j] += b_0[(b_j - k) + 255] * whiteNoise[k + 257];
    }
  }

  memcpy(&obj->pFilterStates[0], &b[0], 255U * (sizeof(real_T)));

  // End of Start for MATLABSystem: '<Root>/Colored Noise'
}

void noiseModelClass::genrand_uint32_vector(const uint32_T mt[625], uint32_T
  b_mt[625], uint32_T u[2])
{
  uint32_T mti;
  uint32_T y;
  int32_T b_j;
  int32_T b_kk;
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));
  for (b_j = 0; b_j < 2; b_j++) {
    mti = b_mt[624] + 1U;
    if (mti >= 625U) {
      for (b_kk = 0; b_kk < 227; b_kk++) {
        y = (b_mt[b_kk + 1] & 2147483647U) | (b_mt[b_kk] & 2147483648U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk] = b_mt[b_kk + 397] ^ y;
      }

      for (b_kk = 0; b_kk < 396; b_kk++) {
        y = (b_mt[b_kk + 227] & 2147483648U) | (b_mt[b_kk + 228] & 2147483647U);
        if (((int32_T)(y & 1U)) == 0) {
          y >>= 1U;
        } else {
          y = (y >> 1U) ^ 2567483615U;
        }

        b_mt[b_kk + 227] = b_mt[b_kk] ^ y;
      }

      y = (b_mt[623] & 2147483648U) | (b_mt[0] & 2147483647U);
      mti = 1U;
      if (((int32_T)(y & 1U)) == 0) {
        y >>= 1U;
      } else {
        y = (y >> 1U) ^ 2567483615U;
      }

      b_mt[623] = b_mt[396] ^ y;
    }

    y = b_mt[((int32_T)mti) - 1];
    b_mt[624] = mti;
    y ^= (y >> 11U);
    y ^= (y << 7U) & 2636928640U;
    y ^= (y << 15U) & 4022730752U;
    u[b_j] = (y >> 18U) ^ y;
  }
}

void noiseModelClass::genrandu(const uint32_T mt[625], uint32_T b_mt[625],
  real_T *r)
{
  uint32_T b_u[2];
  uint32_T b_mt_0[625];
  memcpy(&b_mt[0], &mt[0], 625U * (sizeof(uint32_T)));

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  do {
    memcpy(&b_mt_0[0], &b_mt[0], 625U * (sizeof(uint32_T)));
    genrand_uint32_vector(b_mt_0, b_mt, b_u);
    *r = ((((real_T)(b_u[0] >> 5U)) * 6.7108864E+7) + ((real_T)(b_u[1] >> 6U))) *
      1.1102230246251565E-16;
  } while ((*r) == 0.0);
}

void noiseModelClass::eml_rand_mt19937ar(const uint32_T state[625], uint32_T
  b_state[625], real_T *r)
{
  real_T xi[257];
  int32_T i;
  real_T x;
  uint32_T c_mt[625];
  uint32_T u32[2];
  real_T d_u;
  static const real_T tmp[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  const real_T *fitab;
  int32_T exitg1;
  memcpy(&b_state[0], &state[0], 625U * (sizeof(uint32_T)));
  xi[0] = 0.0;
  xi[1] = 0.215241895984875;
  xi[2] = 0.286174591792068;
  xi[3] = 0.335737519214422;
  xi[4] = 0.375121332878378;
  xi[5] = 0.408389134611989;
  xi[6] = 0.43751840220787;
  xi[7] = 0.46363433679088;
  xi[8] = 0.487443966139235;
  xi[9] = 0.50942332960209;
  xi[10] = 0.529909720661557;
  xi[11] = 0.549151702327164;
  xi[12] = 0.567338257053817;
  xi[13] = 0.584616766106378;
  xi[14] = 0.601104617755991;
  xi[15] = 0.61689699000775;
  xi[16] = 0.63207223638606;
  xi[17] = 0.646695714894993;
  xi[18] = 0.660822574244419;
  xi[19] = 0.674499822837293;
  xi[20] = 0.687767892795788;
  xi[21] = 0.700661841106814;
  xi[22] = 0.713212285190975;
  xi[23] = 0.725446140909999;
  xi[24] = 0.737387211434295;
  xi[25] = 0.749056662017815;
  xi[26] = 0.760473406430107;
  xi[27] = 0.771654424224568;
  xi[28] = 0.782615023307232;
  xi[29] = 0.793369058840623;
  xi[30] = 0.80392911698997;
  xi[31] = 0.814306670135215;
  xi[32] = 0.824512208752291;
  xi[33] = 0.834555354086381;
  xi[34] = 0.844444954909153;
  xi[35] = 0.854189171008163;
  xi[36] = 0.863795545553308;
  xi[37] = 0.87327106808886;
  xi[38] = 0.882622229585165;
  xi[39] = 0.891855070732941;
  xi[40] = 0.900975224461221;
  xi[41] = 0.909987953496718;
  xi[42] = 0.91889818364959;
  xi[43] = 0.927710533401999;
  xi[44] = 0.936429340286575;
  xi[45] = 0.945058684468165;
  xi[46] = 0.953602409881086;
  xi[47] = 0.96206414322304;
  xi[48] = 0.970447311064224;
  xi[49] = 0.978755155294224;
  xi[50] = 0.986990747099062;
  xi[51] = 0.99515699963509;
  xi[52] = 1.00325667954467;
  xi[53] = 1.01129241744;
  xi[54] = 1.01926671746548;
  xi[55] = 1.02718196603564;
  xi[56] = 1.03504043983344;
  xi[57] = 1.04284431314415;
  xi[58] = 1.05059566459093;
  xi[59] = 1.05829648333067;
  xi[60] = 1.06594867476212;
  xi[61] = 1.07355406579244;
  xi[62] = 1.0811144097034;
  xi[63] = 1.08863139065398;
  xi[64] = 1.09610662785202;
  xi[65] = 1.10354167942464;
  xi[66] = 1.11093804601357;
  xi[67] = 1.11829717411934;
  xi[68] = 1.12562045921553;
  xi[69] = 1.13290924865253;
  xi[70] = 1.14016484436815;
  xi[71] = 1.14738850542085;
  xi[72] = 1.15458145035993;
  xi[73] = 1.16174485944561;
  xi[74] = 1.16887987673083;
  xi[75] = 1.17598761201545;
  xi[76] = 1.18306914268269;
  xi[77] = 1.19012551542669;
  xi[78] = 1.19715774787944;
  xi[79] = 1.20416683014438;
  xi[80] = 1.2111537262437;
  xi[81] = 1.21811937548548;
  xi[82] = 1.22506469375653;
  xi[83] = 1.23199057474614;
  xi[84] = 1.23889789110569;
  xi[85] = 1.24578749554863;
  xi[86] = 1.2526602218949;
  xi[87] = 1.25951688606371;
  xi[88] = 1.26635828701823;
  xi[89] = 1.27318520766536;
  xi[90] = 1.27999841571382;
  xi[91] = 1.28679866449324;
  xi[92] = 1.29358669373695;
  xi[93] = 1.30036323033084;
  xi[94] = 1.30712898903073;
  xi[95] = 1.31388467315022;
  xi[96] = 1.32063097522106;
  xi[97] = 1.32736857762793;
  xi[98] = 1.33409815321936;
  xi[99] = 1.3408203658964;
  xi[100] = 1.34753587118059;
  xi[101] = 1.35424531676263;
  xi[102] = 1.36094934303328;
  xi[103] = 1.36764858359748;
  xi[104] = 1.37434366577317;
  xi[105] = 1.38103521107586;
  xi[106] = 1.38772383568998;
  xi[107] = 1.39441015092814;
  xi[108] = 1.40109476367925;
  xi[109] = 1.4077782768464;
  xi[110] = 1.41446128977547;
  xi[111] = 1.42114439867531;
  xi[112] = 1.42782819703026;
  xi[113] = 1.43451327600589;
  xi[114] = 1.44120022484872;
  xi[115] = 1.44788963128058;
  xi[116] = 1.45458208188841;
  xi[117] = 1.46127816251028;
  xi[118] = 1.46797845861808;
  xi[119] = 1.47468355569786;
  xi[120] = 1.48139403962819;
  xi[121] = 1.48811049705745;
  xi[122] = 1.49483351578049;
  xi[123] = 1.50156368511546;
  xi[124] = 1.50830159628131;
  xi[125] = 1.51504784277671;
  xi[126] = 1.521803020761;
  xi[127] = 1.52856772943771;
  xi[128] = 1.53534257144151;
  xi[129] = 1.542128153229;
  xi[130] = 1.54892508547417;
  xi[131] = 1.55573398346918;
  xi[132] = 1.56255546753104;
  xi[133] = 1.56939016341512;
  xi[134] = 1.57623870273591;
  xi[135] = 1.58310172339603;
  xi[136] = 1.58997987002419;
  xi[137] = 1.59687379442279;
  xi[138] = 1.60378415602609;
  xi[139] = 1.61071162236983;
  xi[140] = 1.61765686957301;
  xi[141] = 1.62462058283303;
  xi[142] = 1.63160345693487;
  xi[143] = 1.63860619677555;
  xi[144] = 1.64562951790478;
  xi[145] = 1.65267414708306;
  xi[146] = 1.65974082285818;
  xi[147] = 1.66683029616166;
  xi[148] = 1.67394333092612;
  xi[149] = 1.68108070472517;
  xi[150] = 1.68824320943719;
  xi[151] = 1.69543165193456;
  xi[152] = 1.70264685479992;
  xi[153] = 1.7098896570713;
  xi[154] = 1.71716091501782;
  xi[155] = 1.72446150294804;
  xi[156] = 1.73179231405296;
  xi[157] = 1.73915426128591;
  xi[158] = 1.74654827828172;
  xi[159] = 1.75397532031767;
  xi[160] = 1.76143636531891;
  xi[161] = 1.76893241491127;
  xi[162] = 1.77646449552452;
  xi[163] = 1.78403365954944;
  xi[164] = 1.79164098655216;
  xi[165] = 1.79928758454972;
  xi[166] = 1.80697459135082;
  xi[167] = 1.81470317596628;
  xi[168] = 1.82247454009388;
  xi[169] = 1.83028991968276;
  xi[170] = 1.83815058658281;
  xi[171] = 1.84605785028518;
  xi[172] = 1.8540130597602;
  xi[173] = 1.86201760539967;
  xi[174] = 1.87007292107127;
  xi[175] = 1.878180486293;
  xi[176] = 1.88634182853678;
  xi[177] = 1.8945585256707;
  xi[178] = 1.90283220855043;
  xi[179] = 1.91116456377125;
  xi[180] = 1.91955733659319;
  xi[181] = 1.92801233405266;
  xi[182] = 1.93653142827569;
  xi[183] = 1.94511656000868;
  xi[184] = 1.95376974238465;
  xi[185] = 1.96249306494436;
  xi[186] = 1.97128869793366;
  xi[187] = 1.98015889690048;
  xi[188] = 1.98910600761744;
  xi[189] = 1.99813247135842;
  xi[190] = 2.00724083056053;
  xi[191] = 2.0164337349062;
  xi[192] = 2.02571394786385;
  xi[193] = 2.03508435372962;
  xi[194] = 2.04454796521753;
  xi[195] = 2.05410793165065;
  xi[196] = 2.06376754781173;
  xi[197] = 2.07353026351874;
  xi[198] = 2.0833996939983;
  xi[199] = 2.09337963113879;
  xi[200] = 2.10347405571488;
  xi[201] = 2.11368715068665;
  xi[202] = 2.12402331568952;
  xi[203] = 2.13448718284602;
  xi[204] = 2.14508363404789;
  xi[205] = 2.15581781987674;
  xi[206] = 2.16669518035431;
  xi[207] = 2.17772146774029;
  xi[208] = 2.18890277162636;
  xi[209] = 2.20024554661128;
  xi[210] = 2.21175664288416;
  xi[211] = 2.22344334009251;
  xi[212] = 2.23531338492992;
  xi[213] = 2.24737503294739;
  xi[214] = 2.25963709517379;
  xi[215] = 2.27210899022838;
  xi[216] = 2.28480080272449;
  xi[217] = 2.29772334890286;
  xi[218] = 2.31088825060137;
  xi[219] = 2.32430801887113;
  xi[220] = 2.33799614879653;
  xi[221] = 2.35196722737914;
  xi[222] = 2.36623705671729;
  xi[223] = 2.38082279517208;
  xi[224] = 2.39574311978193;
  xi[225] = 2.41101841390112;
  xi[226] = 2.42667098493715;
  xi[227] = 2.44272531820036;
  xi[228] = 2.4592083743347;
  xi[229] = 2.47614993967052;
  xi[230] = 2.49358304127105;
  xi[231] = 2.51154444162669;
  xi[232] = 2.53007523215985;
  xi[233] = 2.54922155032478;
  xi[234] = 2.56903545268184;
  xi[235] = 2.58957598670829;
  xi[236] = 2.61091051848882;
  xi[237] = 2.63311639363158;
  xi[238] = 2.65628303757674;
  xi[239] = 2.68051464328574;
  xi[240] = 2.70593365612306;
  xi[241] = 2.73268535904401;
  xi[242] = 2.76094400527999;
  xi[243] = 2.79092117400193;
  xi[244] = 2.82287739682644;
  xi[245] = 2.85713873087322;
  xi[246] = 2.89412105361341;
  xi[247] = 2.93436686720889;
  xi[248] = 2.97860327988184;
  xi[249] = 3.02783779176959;
  xi[250] = 3.08352613200214;
  xi[251] = 3.147889289518;
  xi[252] = 3.2245750520478;
  xi[253] = 3.32024473383983;
  xi[254] = 3.44927829856143;
  xi[255] = 3.65415288536101;
  xi[256] = 3.91075795952492;
  fitab = &tmp[0];
  do {
    exitg1 = 0;
    genrand_uint32_vector(b_state, c_mt, u32);
    memcpy(&b_state[0], &c_mt[0], 625U * (sizeof(uint32_T)));
    i = (int32_T)((u32[1] >> 24U) + 1U);
    *r = ((((((real_T)(u32[0] >> 3U)) * 1.6777216E+7) + ((real_T)(((int32_T)u32
               [1]) & 16777215))) * 2.2204460492503131E-16) - 1.0) * xi[i];
    if (std::abs(*r) <= xi[i - 1]) {
      exitg1 = 1;
    } else if (i < 256) {
      genrandu(c_mt, b_state, &x);
      if ((((fitab[i - 1] - fitab[i]) * x) + fitab[i]) < std::exp((-0.5 * (*r)) *
           (*r))) {
        exitg1 = 1;
      }
    } else {
      do {
        genrandu(b_state, c_mt, &x);
        x = std::log(x) * 0.273661237329758;
        genrandu(c_mt, b_state, &d_u);
      } while (!((-2.0 * std::log(d_u)) > (x * x)));

      if ((*r) < 0.0) {
        *r = x - 3.65415288536101;
      } else {
        *r = 3.65415288536101 - x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void noiseModelClass::ColoredNoise_getExcitationNoise(dsp_simulink_ColoredNoise *
  obj, real_T whiteNoise[TABELSIZENOISE])
{
  uint32_T state[625];
  int32_T b_rowIdx;
  uint32_T state_0[625];
  memcpy(&state[0], &obj->pWNState[0], 625U * (sizeof(uint32_T)));
  for (b_rowIdx = 0; b_rowIdx < TABELSIZENOISE; b_rowIdx++) {
    memcpy(&state_0[0], &state[0], 625U * (sizeof(uint32_T)));
    eml_rand_mt19937ar(state_0, state, &whiteNoise[b_rowIdx]);
  }

  memcpy(&obj->pWNState[0], &state[0], 625U * (sizeof(uint32_T)));
}

void noiseModelClass::SystemCore_step(dsp_simulink_ColoredNoise *obj, real_T
  varargout_1[TABELSIZENOISE])
{
  real_T whiteNoise[TABELSIZENOISE];
  int32_T j;
  real_T b_idx_1;
  real_T b_idx_0;
  ColoredNoise_getExcitationNoise(obj, whiteNoise);
  b_idx_0 = obj->pNumFilterCoef[0];
  b_idx_1 = obj->pNumFilterCoef[1];
  if ((((!rtIsInf(obj->pDenFilterCoef)) && (!rtIsNaN(obj->pDenFilterCoef))) && (
        !(obj->pDenFilterCoef == 0.0))) && (obj->pDenFilterCoef != 1.0)) {
    b_idx_0 = obj->pNumFilterCoef[0] / obj->pDenFilterCoef;
    b_idx_1 = obj->pNumFilterCoef[1] / obj->pDenFilterCoef;
  }

  varargout_1[0] = obj->pFilterStates;
  memset(&varargout_1[1], 0, TABELSIZENOISE-1U * (sizeof(real_T)));
  for (j = 1; j < TABELSIZENOISE+1; j++) {
    varargout_1[j - 1] += whiteNoise[j - 1] * b_idx_0;
  }

  for (j = 2; j < TABELSIZENOISE+1; j++) {
    varargout_1[j - 1] += whiteNoise[j - 2] * b_idx_1;
  }

  obj->pFilterStates = whiteNoise[TABELSIZENOISE-1] * b_idx_1;
}

void noiseModelClass::ColoredNoise_resetImpl_k(dsp_simulink_ColoredNoise_k *obj)
{
  uint32_T b_state[625];
  uint32_T r;
  int32_T i;
  memset(&obj->pFilterStates[0], 0, 63U * (sizeof(real_T)));
  for (i = 0; i < 625; i++) {
    obj->pWNState[i] = 0U;
    b_state[i] = obj->pWNState[i];
  }

  r = (uint32_T)Seed;
  b_state[0] = 67U;
  for (i = 0; i < 623; i++) {
    r = ((((r >> 30U) ^ r) * 1812433253U) + i) + 1U;
    b_state[i + 1] = r;
  }

  b_state[624] = 624U;
  memcpy(&obj->pWNState[0], &b_state[0], 625U * (sizeof(uint32_T)));
}

void noiseModelClass::ColoredNoise_resetImpl_k3(dsp_simulink_ColoredNoise_k3
  *obj)
{
  uint32_T b_state[625];
  uint32_T r;
  int32_T i;

  // Start for MATLABSystem: '<Root>/Colored Noise'
  memset(&obj->pFilterStates[0], 0, 255U * (sizeof(real_T)));
  for (i = 0; i < 625; i++) {
    obj->pWNState[i] = 0U;
    b_state[i] = obj->pWNState[i];
  }

  r = (uint32_T)Seed;
  b_state[0] = 67U;
  for (i = 0; i < 623; i++) {
    r = ((((r >> 30U) ^ r) * 1812433253U) + i) + 1U;
    b_state[i + 1] = r;
  }

  b_state[624] = 624U;
  memcpy(&obj->pWNState[0], &b_state[0], 625U * (sizeof(uint32_T)));

  // End of Start for MATLABSystem: '<Root>/Colored Noise'
}

void noiseModelClass::ColoredNoise_resetImpl(dsp_simulink_ColoredNoise *obj)
{
  uint32_T b_state[625];
  uint32_T r;
  int32_T i;
  obj->pFilterStates = 0.0;
  for (i = 0; i < 625; i++) {
    obj->pWNState[i] = 0U;
    b_state[i] = obj->pWNState[i];
  }

  r = (uint32_T)Seed;
  b_state[0] = 67U;
  for (i = 0; i < 623; i++) {
    r = ((((r >> 30U) ^ r) * 1812433253U) + i) + 1U;
    b_state[i + 1] = r;
  }

  b_state[624] = 624U;
  memcpy(&obj->pWNState[0], &b_state[0], 625U * (sizeof(uint32_T)));
}

// Model step function
void noiseModelClass::step(double*whitenoise,double *bluenoise,double *pinknoise,double*purplenoise)
{
  if ((&rtM)->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<Root>/Colored Noise1' incorporates:
    //   Outport: '<Root>/Out1'

    SystemCore_step_k(&rtDWork.obj_l, whitenoise);

    // Start for MATLABSystem: '<Root>/Colored Noise' incorporates:
    //   Outport: '<Root>/Out2'

    SystemCore_step_k3(&rtDWork.obj, bluenoise);

    // MATLABSystem: '<Root>/Colored Noise2' incorporates:
    //   Outport: '<Root>/Out3'

    SystemCore_step_k(&rtDWork.obj_n, pinknoise);

    // MATLABSystem: '<Root>/Colored Noise3' incorporates:
    //   Outport: '<Root>/Out4'

    SystemCore_step(&rtDWork.obj_lf, purplenoise);
  }

  rate_scheduler((&rtM));
}

// Model initialize function
void noiseModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T den[64];
    int32_T b_idx;
    real_T num[256];

    // Start for MATLABSystem: '<Root>/Colored Noise1'
    rtDWork.obj_l.isInitialized = 0;
    rtDWork.obj_l.isInitialized = 1;
    for (b_idx = 0; b_idx < 64; b_idx++) {
      den[b_idx] = 1.0;
    }

    for (b_idx = 0; b_idx < 63; b_idx++) {
      den[b_idx + 1] = (((2.0 + ((real_T)b_idx)) - 2.0) * den[b_idx]) / ((2.0 +
        ((real_T)b_idx)) - 1.0);
    }

    rtDWork.obj_l.pNumFilterCoef = 1.0;
    memcpy(&rtDWork.obj_l.pDenFilterCoef[0], &den[0], (sizeof(real_T)) << 6U);
    memset(&rtDWork.obj_l.pFilterStates[0], 0, 63U * (sizeof(real_T)));

    // End of Start for MATLABSystem: '<Root>/Colored Noise1'

    // Start for MATLABSystem: '<Root>/Colored Noise'
    rtDWork.obj.isInitialized = 0;
    rtDWork.obj.isInitialized = 1;
    for (b_idx = 0; b_idx < 256; b_idx++) {
      num[b_idx] = 1.0;
    }

    for (b_idx = 0; b_idx < 255; b_idx++) {
      num[b_idx + 1] = ((((2.0 + ((real_T)b_idx)) + -0.5) - 2.0) * num[b_idx]) /
        ((2.0 + ((real_T)b_idx)) - 1.0);
    }

    memcpy(&rtDWork.obj.pNumFilterCoef[0], &num[0], (sizeof(real_T)) << 8U);
    rtDWork.obj.pDenFilterCoef = 1.0;
    memset(&rtDWork.obj.pFilterStates[0], 0, 255U * (sizeof(real_T)));

    // Start for MATLABSystem: '<Root>/Colored Noise2'
    rtDWork.obj_n.isInitialized = 0;
    rtDWork.obj_n.isInitialized = 1;
    for (b_idx = 0; b_idx < 64; b_idx++) {
      den[b_idx] = 1.0;
    }

    for (b_idx = 0; b_idx < 63; b_idx++) {
      den[b_idx + 1] = ((((2.0 + ((real_T)b_idx)) - 2.0) - 0.5) * den[b_idx]) /
        ((2.0 + ((real_T)b_idx)) - 1.0);
    }

    rtDWork.obj_n.pNumFilterCoef = 1.0;
    memcpy(&rtDWork.obj_n.pDenFilterCoef[0], &den[0], (sizeof(real_T)) << 6U);
    memset(&rtDWork.obj_n.pFilterStates[0], 0, 63U * (sizeof(real_T)));

    // End of Start for MATLABSystem: '<Root>/Colored Noise2'

    // Start for MATLABSystem: '<Root>/Colored Noise3'
    rtDWork.obj_lf.isInitialized = 0;
    rtDWork.obj_lf.isInitialized = 1;
    rtDWork.obj_lf.pNumFilterCoef[0] = 1.0;
    rtDWork.obj_lf.pNumFilterCoef[1] = -1.0;
    rtDWork.obj_lf.pDenFilterCoef = 1.0;
    rtDWork.obj_lf.pFilterStates = 0.0;

    // InitializeConditions for MATLABSystem: '<Root>/Colored Noise1'
    ColoredNoise_resetImpl_k(&rtDWork.obj_l);

    // Start for MATLABSystem: '<Root>/Colored Noise'
    ColoredNoise_resetImpl_k3(&rtDWork.obj);

    // InitializeConditions for MATLABSystem: '<Root>/Colored Noise2'
    ColoredNoise_resetImpl_k(&rtDWork.obj_n);

    // InitializeConditions for MATLABSystem: '<Root>/Colored Noise3'
    ColoredNoise_resetImpl(&rtDWork.obj_lf);
  }
}

// Constructor
noiseModelClass::noiseModelClass()
{
}

// Destructor
noiseModelClass::~noiseModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * noiseModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
