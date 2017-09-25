#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this, 
		&ofApp::setupArduino);
// functie van OFW om te luisteren naar arduino(class). Op moment dat signaal van
//EInitialized (opstart signaal arduino) in de lucht is, wordt &ofApp::SetupArduino aangeroepen

	arduino.connect("COM4");
	arduino.sendFirmwareVersionRequest();
//super belangrijk om te connecten	

	arduiButton = 12;

}

//--------------------------------------------------------------
void ofApp::update(){
	arduino.update();
	//communiceren met arduino - checken met arduino

	for (int i = 0; i < balllist.size(); i++)
	{
		balllist[i].updateball();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < balllist.size(); i++)
	{
		balllist[i].drawball();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	arduino.sendDigital(11, ARD_HIGH);



//pin aan
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	arduino.sendDigital(11, ARD_LOW);

//pin uit
}

void ofApp::setupArduino(const int& versoin) {
	ofLog() << "Arduino firmware found" << arduino.getFirmwareName()
										<< arduino.getMajorFirmwareVersion()
										<< arduino.getMinorFirmwareVersion() 
										<< endl;
//checken of arduino goed opstart enz

	arduino.sendDigitalPinMode(11, ARD_OUTPUT); //digitaal output led
	arduino.sendDigitalPinMode(arduiButton, ARD_INPUT);	//digitaal input knopje
	arduino.sendAnalogPinReporting(0, ARD_ANALOG); //analog input sensor
	arduino.sendAnalogPinReporting(1, ARD_ANALOG); //analog input draaiknop


	ofAddListener(arduino.EAnalogPinChanged, this,
					&ofApp::analogPinChanged);

	ofAddListener(arduino.EDigitalPinChanged, this,
					&ofApp::digitalPinChanged);
	//kijken of een waarde veranderd, zo ja roep deze functies aan

	

}


void ofApp::analogPinChanged(const int& pin) {
   	ofLog() << "Analog pin" << pin << "value: " << arduino.getAnalog(pin) << endl;


}

void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "Digital pin" << pin << "value: " << arduino.getDigital(pin) << endl;

	if (arduino.getDigital(arduiButton) == 1) {
		balls.newball(ofColor::aqua, 50);
		balllist.push_back(balls);
	}

}