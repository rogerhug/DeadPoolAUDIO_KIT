#include "binary.h"


#define PI 3.1415926536f

binaryFiles::binaryFiles()
{
	fixv = 0;
	sizedev = WAVESIZEMAX;

	mSampleLenght = WAVESIZEMAX;
	mBuffer.resize(WAVESIZEMAX);
	mBufferVcfRelease.resize(WAVESIZEMAX);
	mSubChunk2Size = WAVESIZEMAX;
	mBitsPerSample = 8;
	mNumChannels = 1;

	for (int i = 0; i < WAVESIZEMAX; i++)
	{
		mBufferVcfRelease[i] =  1 - (i / (double)WAVESIZEMAX);
	    mBuffer[i] = sin(i / (double)WAVESIZEMAX*6*PI);
        
	}


	}

binaryFiles::~binaryFiles()
{
	
}



const int binaryFiles::getSampleLength()
{
	mSampleLenght = mSubChunk2Size / (mNumChannels * (mBitsPerSample / 8));

	return minmaxbinS(mSampleLenght);
	
}
const int binaryFiles::setSampelFix(int f)
{
	fixv =f;
	if (fixv == 0) { sizedev = getSampleLength() / 4; }
	if (fixv == 1) { sizedev = getSampleLength() / 3; }
	if (fixv == 2) { sizedev = getSampleLength() / 2; }
	if (fixv == 3) { sizedev = getSampleLength();}
	return sizedev;
}




void binaryFiles::loadWaveFile(const char * fname,int st)
{
	
		
	myfile.open(fname, std::ios::binary | std::ios::in);
 if (myfile.good() > 0) {

    
	if (myfile.is_open() )
	{



		//Should have 'RIFF'.
		myfile.read(buf, 4);

		if (!strcmp(buf, "RIFF"))
		{
			//We had 'RIFF', so let's continue.

			//Size of the rest of the chunk following this number.
			myfile.read(buf, 4);
  
			 mChunkSize = *(reinterpret_cast<unsigned int*>(buf));

			//Should contain 'WAVE'.
			myfile.read(buf, 4);

			if (!strcmp(buf, "WAVE"))
			{
				//This is probably a wave file since it contained "WAVE".

				//Should contain 'fmt '.
				myfile.read(buf, 4);

				//Size of the rest of the Subchunk following this number.
				myfile.read(buf, 4);
				//mSubChunk1Size = minmaxbin(*(reinterpret_cast<unsigned int*>(buf)));
                mSubChunk1Size = *(reinterpret_cast<unsigned int*>(buf));
				
				//PCM = 1, other values mean there is some type of file compression.
				myfile.read(buf, 2);
				mAudioFormat = *(reinterpret_cast<unsigned short*>(buf));

				//1 mono, 2 stereo, etc.
				myfile.read(buf, 2);
				mNumChannels = *(reinterpret_cast<unsigned short*>(buf));

				//The sample rate of the audio.
				myfile.read(buf, 4);
				mSampleRate = *(reinterpret_cast<unsigned int*>(buf));


				//mSampleRate * mNumChannels * mBitsPerSample / 8.
				myfile.read(buf, 4);
				mByteRate = *(reinterpret_cast<unsigned int*>(buf));

				//mNumChannels * mBitsPerSample / 8.
				myfile.read(buf, 2);
				mBlockAlign = *(reinterpret_cast<unsigned short*>(buf));

				//8 bits = 8, 16 bits = 16, 24 bits = 24, etc.
				myfile.read(buf, 2);
				mBitsPerSample = *(reinterpret_cast<unsigned int*>(buf));


				//Skip until we find the data chunk.
				myfile.read(buf, 4);
				while (strcmp(buf, "data"))
				{

					unsigned int extraChunkSize = 0;
					myfile.read(buf, 4);
				
					extraChunkSize = *(reinterpret_cast<unsigned int*>(buf));
		
					myfile.seekg(extraChunkSize, std::ios::cur);

					myfile.read(buf, 4);


				}

				//Size of the data.
				myfile.read(buf, 4);

               mSubChunk2Size = *(reinterpret_cast<unsigned int*>(buf));

				//Read in the data.
				
				setBuffer(fixv);

			 // getSampleLength();
				

				//Close the file.
				myfile.close();

	
			}
			else
				std::cerr << "Error: RIFF file but not a wave file" << std::endl;
		}
		else
			std::cerr << "Error: not a RIFF file" << std::endl;
	}
	else
		std::cerr << "Error: Could not open the file!" << std::endl;
    
    
    
}
	

}



void binaryFiles::setBuffer(int st)
{
	const unsigned char bytesPerSample = 2;
	char buf[bytesPerSample];

	const int ch = 1;
		//1-Dimensional vector to hold all samples.

         //   mBuffer.resize((double)setSampelFix(fixv) * mNumChannels ) ;
		 //   mBufferVcfRelease.resize((double)setSampelFix(fixv) * mNumChannels);

	      mBuffer.resize(getSampleLength()+mNumChannels );
		  mBufferVcfRelease.resize(getSampleLength() + mNumChannels);

		//Iterate through each channel every sample.
		for (int sample = 0; sample < getSampleLength() + mNumChannels; ++sample)
		{
		
			

			for (int channel = 0; channel < mNumChannels; ++channel)
			{


				//Read data into the temporary buffer.
				myfile.read(buf, bytesPerSample);

				//Reinterpret cast the temporary buffer into a short int value.
				//This will have to be changed with different bytes per sample,
				//but I'm not sure quite how to do it yet.

				
				short int outputValue = *(reinterpret_cast<short int*>(buf));
				//Check if the value is positive or negative and scale it between
				//-1 to 1 accordingly. After scaling it, put it in the buffer.
               mBufferVcfRelease[sample] = 1-((sample ) /  double(getSampleLength()));
				if (outputValue >= 0)
				{

					mBuffer[sample] = static_cast<double>(outputValue) / 32767.0;
				

				}

				else
				{

					mBuffer[sample ] = static_cast<double>(outputValue) / 32767.0;
					

				}
			
                   // mBuffer[sample ] *= mBufferVcfRelease.data()[sample ];

			}
		

	}
		getSample();
}



 const double * binaryFiles::getSample()
{
	
	
		return mBuffer.data();

	
	
}




