
#ifndef __BINARY__
#define __BINARY__

#include <iostream>
#include <fstream>
#include <vector>
#include"math.h"



#define WAVESIZEMAX 88200

class binaryFiles
{
public:
	binaryFiles();
	~binaryFiles();
	

	inline int minmaxbinS(int a) {
		int result = 0; result = a;
		if (result > WAVESIZEMAX) { result = WAVESIZEMAX; }
		if (result < WAVESIZEMAX/16) { result = WAVESIZEMAX / 16; }
		return result;
	}

	const int getSampleLength();
    const int setSampelFix(int f);
	const int getNumberChannel() { return mNumChannels; }
	void loadWaveFile(const char *fname,int st);
    void setBuffer(int st);
    const double * getSample();// { return mBuffer.data(); }
	
private:
    int fixv;
	int sizedev;
	char buf[5] = { 0 };
	std::ifstream myfile;
	unsigned int mChunkSize, mSubChunk1Size, mSampleRate,
		mByteRate, mSubChunk2Size;
	unsigned short int mAudioFormat, mNumChannels,
		mBlockAlign, mBitsPerSample;
	int mSampleLenght;
	std::vector<double> mBuffer;
	std::vector<double> mBufferVcfRelease;



   

};

#endif  defined(__BINARY__) 
