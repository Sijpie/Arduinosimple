#pragma once

#include "ofMain.h"
#include "Balls.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		int arduiButton;

	

private:
	ofArduino arduino;
	//openframeworks arduino class
	
	void setupArduino(const int& version);
	// je hoeft niet te weten wat deze functies
	//doen, je hebt ze gewoon nodig

	void analogPinChanged(const int& pin);
	void digitalPinChanged(const int& pin);


	//Balls
	vector<Balls> balllist;

	Balls balls;

};

//firmata connecten
//arduino - examples - firamata - standardfirmata
//klik op pijtje (kan zijn dat je nog bij tools
//post op port moet klikken