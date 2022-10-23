/*
  ==============================================================================

    audioUrlFiles.cpp
    Created: 8 Oct 2021 5:32:00pm
    Author:  r7

  ==============================================================================
*/

#include "audioUrlFiles.h"

PluginWaves::PluginWaves(AudioProcessorValueTreeState& valueTreeState)
{

	
	
		

}

void PluginWaves::createAllParameters()
{
	
	getUrl1V();
	getUrl2V();
	getUrl3V();
	getUrl4V();
	getUrl5V();
	getUrl6V();
	getUrl7V();

}









char ec1[13] = { "" };


const char* PluginWaves::Sp1Names(int n)
{sprintf(ec1, "S1_url%.2i", n);
return ec1;
}
String ef1[77] = { "" };
const String* PluginWaves::Sp1SetNames()
{
	for (int i = 0; i < 72; i++)
		ef1[i] = Sp1Names(i);
	return ef1;
}
char ec2[13] = { "" };
const char* PluginWaves::Sp2Names(int n)
{sprintf(ec2, "S2_url%.2i", n);
return ec2;
}
String ef2[77] = { "" };
const String* PluginWaves::Sp2SetNames()
{
	for (int i = 0; i < 72; i++)
		ef2[i] = Sp2Names(i);
	return ef2;
}
	char ec3[13] = { "" };
const char* PluginWaves::Sp3Names(int n)
{
	sprintf(ec3, "S3_url%.2i", n);
	return ec3;
}
String ef3[77] = { "" };
const String* PluginWaves::Sp3SetNames()
{
	for (int i = 0; i < 72; i++)
		ef3[i] = Sp3Names(i);
	return ef3;
}
char ec4[13] = { "" };
const char* PluginWaves::Sp4Names(int n)
{	sprintf(ec4, "S4_url%.2i", n);
    return ec4;
}
String ef4[77] = { "" };
const String* PluginWaves::Sp4SetNames()
{
	for (int i = 0; i < 72; i++)
		ef4[i] = Sp4Names(i);
	return ef4;
}
char ec5[13] = { "" };
const char* PluginWaves::Sp5Names(int n)
{	sprintf(ec5, "S5_url%.2i", n);
	return ec5;
}
String ef5[77] = { "" };
const String* PluginWaves::Sp5SetNames()
{
	for (int i = 0; i < 72; i++)
		ef5[i] = Sp5Names(i);
	return ef5;
}
char ec6[13] = { "" };
const char* PluginWaves::Sp6Names(int n)
{	sprintf(ec6 ,"S6_url%.2i", n);
	return ec6;
}
String ef6[77] = { "" };
const String* PluginWaves::Sp6SetNames()
{
	for (int i = 0; i < 72; i++)
		ef6[i] = Sp6Names(i);
		return ef6;
}

char ec7[13] = { "" };
const char* PluginWaves::Sp7Names(int n)
{ 	sprintf(ec7, "S7_url%.2i", n);
	return ec7;
}


String ef7[100] = { "" };
const String* PluginWaves::Sp7SetNames()
{
	for (int i = 0; i < 72; i++)
		ef7[i] = Sp7Names(i);
	return  ef7;
}


void PluginWaves::serial1(AudioProcessorValueTreeState& valueTreeState, File fileAudio, int m,int e)
{
	if (e == 0) {
		valueTreeState.state.setProperty(Sp1SetNames()[m], var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url1v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp1SetNames()[m], nullptr, true));
	}
	if (e == 1) {
		valueTreeState.state.setProperty(Sp2Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url2v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp2Names(m), nullptr, true));
	}
	if (e == 2) {
		valueTreeState.state.setProperty(Sp3Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url3v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp3Names(m), nullptr, true));
	}
	if (e == 3) {

		valueTreeState.state.setProperty(Sp4Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url4v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp4Names(m), nullptr, true));

	}
	if (e == 4) {
		valueTreeState.state.setProperty(Sp5Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url5v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp5Names(m), nullptr, true));
	}
	if (e == 5) {
		valueTreeState.state.setProperty(Sp6Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url6v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp6Names(m), nullptr, true));
	}
	if (e == 6) {
		valueTreeState.state.setProperty(Sp7Names(m), var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
		url7v[m].referTo(valueTreeState.state.getPropertyAsValue(Sp7Names(m), nullptr, true));
	}
}



void PluginWaves::loadInit1(AudioProcessorValueTreeState& valueTreeState, int n)
{
	if (n == 1) {
		valueTreeState.state.setProperty(Sp1SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-002.wav"), nullptr);
	    valueTreeState.state.setProperty(Sp1SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-003.wav"), nullptr);
	    valueTreeState.state.setProperty(Sp1SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-025.wav"), nullptr);

		
		valueTreeState.state.setProperty(Sp1SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-048.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_1-065.wav"), nullptr);

	}
	if (n == 2) {
		valueTreeState.state.setProperty(Sp1SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-025.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-048.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Kickr7/kickr7_2-065.wav"), nullptr);

	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp1SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-025.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-048.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_1-065.wav"), nullptr);

	
	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp1SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-025.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-048.wav"), nullptr);


		valueTreeState.state.setProperty(Sp1SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp1SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-065.wav"), nullptr);
	}
	for (int i = 0; i < 64; i++) {

			url1v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp1SetNames()[i].toRawUTF8(), nullptr, true));
	
	}
}

void PluginWaves::loadInit2(AudioProcessorValueTreeState& valueTreeState, int n)
{
	if (n == 1) {
		valueTreeState.state.setProperty(Sp2SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_1-065.wav"), nullptr);

	}

	if (n == 2) {
		valueTreeState.state.setProperty(Sp2SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Snares7/snr7_2-065.wav"), nullptr);
	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp2SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-023.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-046.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-048.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_2-066.wav"), nullptr);

	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp2SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-023.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-024.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-046.wav"), nullptr);

		valueTreeState.state.setProperty(Sp2SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-048.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp2SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-066.wav"), nullptr);
	}

	for (int i = 0; i < 64; i++) {

		url2v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp2SetNames()[i].toRawUTF8(), nullptr, true));

	}
	

}

void PluginWaves::loadInit3(AudioProcessorValueTreeState& valueTreeState, int n)
{
	if (n == 1) {
		valueTreeState.state.setProperty(Sp3SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_1-066.wav"), nullptr);

	}
	if (n == 2) {
		valueTreeState.state.setProperty(Sp3SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Hats7/Hats7_2-066.wav"), nullptr);
	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp3SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-066.wav"), nullptr);

	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp3SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp3SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp3SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-066.wav"), nullptr);
	}
	

	for (int i = 0; i < 64; i++) {

		url3v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp3SetNames()[i].toRawUTF8(), nullptr, true));

	}

}

void PluginWaves::loadInit4(AudioProcessorValueTreeState& valueTreeState, int n)
{

	if (n == 1) {
		valueTreeState.state.setProperty(Sp4SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-065.wav"), nullptr);

	}
	if (n == 2) {
		valueTreeState.state.setProperty(Sp4SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-065.wav"), nullptr);
	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp4SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_1-065.wav"), nullptr);
	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp4SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp4SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp4SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_4-066.wav"), nullptr);

	}
	for (int i = 0; i < 64; i++) {

		url4v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp4SetNames()[i].toRawUTF8(), nullptr, true));

	}

}

void PluginWaves::loadInit5(AudioProcessorValueTreeState& valueTreeState, int n)
{
	
	if (n == 1) {
		                                                                           
		valueTreeState.state.setProperty(Sp5SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-065.wav"), nullptr);
	}
	if (n == 2) {
		valueTreeState.state.setProperty(Sp5SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-065.wav"), nullptr);
	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp5SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_2-065.wav"), nullptr);
	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp5SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp5SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp5SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-066.wav"), nullptr);
	}
	for (int i = 0; i < 64; i++) {

		url5v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp5SetNames()[i].toRawUTF8(), nullptr, true));

	}
	
}

void PluginWaves::loadInit6(AudioProcessorValueTreeState& valueTreeState, int n)
{
	
	if (n == 1) {
		valueTreeState.state.setProperty(Sp6SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-065.wav"), nullptr);
	}
	if (n == 2) {
		valueTreeState.state.setProperty(Sp6SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-065.wav"), nullptr);
	}

	if (n == 3) {
		valueTreeState.state.setProperty(Sp6SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_3-065.wav"), nullptr);
	}

	if (n == 4) {
		valueTreeState.state.setProperty(Sp6SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp6SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp6SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_5-066.wav"), nullptr);
	}

	for (int i = 0; i < 64; i++) {

		url6v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp6SetNames()[i].toRawUTF8(), nullptr, true));

	}
	
}

void PluginWaves::loadInit7(AudioProcessorValueTreeState& valueTreeState, int n)
{
	
	if (n == 1) {
		                                                                              
		valueTreeState.state.setProperty(Sp7SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-065.wav"), nullptr);
	}
	
	if (n == 2) {
		valueTreeState.state.setProperty(Sp7SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/Percs7/Perc7_4-065.wav"), nullptr);
	}
	if (n == 3) {
		valueTreeState.state.setProperty(Sp7SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_6-066.wav"), nullptr);
	}
	if (n == 4) {
		valueTreeState.state.setProperty(Sp7SetNames()[0], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-001.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[1], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-002.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[2], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-003.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[3], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-004.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[4], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-005.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[5], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-006.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[6], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-007.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[7], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-008.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[8], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-009.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[9], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-010.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[10], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-011.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[11], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-012.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[12], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-013.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[13], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-014.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[14], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-015.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[15], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-016.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[16], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-017.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[17], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-018.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[18], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-019.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[19], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-020.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[20], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-021.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[21], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-022.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[22], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-023.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[23], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-024.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[24], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-025.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[25], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-026.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[26], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-027.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[27], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-028.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[28], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-029.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[29], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-030.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[30], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-031.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[31], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-032.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[32], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-033.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[33], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-034.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[34], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-035.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[35], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-036.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[36], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-037.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[37], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-038.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[38], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-039.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[39], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-040.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[40], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-041.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[41], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-042.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[42], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-043.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[43], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-044.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[44], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-045.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[45], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-046.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[46], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-047.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[47], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-048.wav"), nullptr);

		valueTreeState.state.setProperty(Sp7SetNames()[48], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-049.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[49], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-050.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[50], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-051.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[51], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-052.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[52], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-053.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[53], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-054.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[54], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-055.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[55], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-056.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[56], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-057.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[57], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-058.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[58], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-059.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[59], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-060.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[60], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-061.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[61], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-062.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[62], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-063.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[63], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-064.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[64], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-065.wav"), nullptr);
		valueTreeState.state.setProperty(Sp7SetNames()[65], var(getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Sampels/SynthCuts_r7/synthCuts_3-066.wav"), nullptr);
	}

	for (int i = 0; i < 64; i++) {

		url7v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp7SetNames()[i].toRawUTF8(), nullptr, true));

	}
	
}

void PluginWaves::unserial(AudioProcessorValueTreeState& valueTreeState,int n)
{

		for (int i = 0; i < 63; i++) {
			url1v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp1SetNames()[i].toRawUTF8(), nullptr, true));
			url2v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp2SetNames()[i].toRawUTF8(), nullptr, true));
			url3v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp3SetNames()[i].toRawUTF8(), nullptr, true));
			url4v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp4SetNames()[i].toRawUTF8(), nullptr, true));
			url5v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp5SetNames()[i].toRawUTF8(), nullptr, true));
			url6v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp6SetNames()[i].toRawUTF8(), nullptr, true));
		    url7v[i].referTo(valueTreeState.state.getPropertyAsValue(Sp7SetNames()[i].toRawUTF8(), nullptr, true));
			
		}
		
			getUrl1V();
			getUrl2V();
			getUrl3V();
			getUrl4V();
			getUrl5V();
			getUrl6V();
			getUrl7V();
			
}

