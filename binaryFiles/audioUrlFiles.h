/*
  ==============================================================================

    audioUrlFiles.h
    Created: 8 Oct 2021 5:32:00pm
    Author:  r7

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"


class  PluginWaves
{
public:
    PluginWaves(AudioProcessorValueTreeState& vts);

    static String getSystemNameInfo()
    {
        String systemInfo;

        systemInfo
            << File::getSpecialLocation(File::commonDocumentsDirectory).getFullPathName();

        //   DBG (systemInfo);
        return systemInfo;
    }
     File fileAudioTemp(String s) {
        return url1v[1].toString();
}
  
            const char* Sp1Names(int n);
            const String* Sp1SetNames();
            const char* Sp2Names(int n);
            const String* Sp2SetNames();
            const char* Sp3Names(int n);
            const String* Sp3SetNames();
            const char* Sp4Names(int n);
            const String* Sp4SetNames();
            const char* Sp5Names(int n);
            const String* Sp5SetNames();
            const char* Sp6Names(int n);
            const String* Sp6SetNames();
            const  char* Sp7Names(int n);
            const String* Sp7SetNames();
        
    
    void createAllParameters();
    void serial1(AudioProcessorValueTreeState& valueTreeState, File fileAudio, int m,int e);


   
    void loadInit1(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit2(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit3(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit4(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit5(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit6(AudioProcessorValueTreeState& valueTreeState, int n);
    void loadInit7(AudioProcessorValueTreeState& valueTreeState, int n);

   
    Value url1v[77];
    Value url2v[77];
    Value url3v[77];
    Value url4v[77];
    Value url5v[77];
    Value url6v[77];
    Value url7v[77];


    Value* getUrl1V() { return url1v; getUrlNb(0);  }
    Value* getUrl2V() { return url2v; getUrlNb(1);  }
    Value* getUrl3V() { return url3v; getUrlNb(2);  }
    Value* getUrl4V() { return url4v; getUrlNb(3);  }
    Value* getUrl5V() { return url5v; getUrlNb(4);  }
    Value* getUrl6V() { return url6v; getUrlNb(5);  }
    Value* getUrl7V() { return url7v; getUrlNb(6);  }

    Value* getUrlNb(int nb) {

        if (nb == 0)
            return url1v;
        if (nb == 1)
            return url2v;
        if (nb == 2)
            return url3v;
        if (nb == 3)
            return url4v;
        if (nb == 4)
               return url5v;
        if (nb == 5)
            return url6v;
        if (nb == 6)
            return url7v;



    }
   

    void unserial(AudioProcessorValueTreeState& valueTreeState,int i);
 
private: 


};