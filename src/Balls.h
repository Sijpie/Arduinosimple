#pragma once
#include "ofMain.h"


class Balls
{
public:
	Balls();

	void newball(ofColor mycolor, int myradius);


	void updateball();
	void drawball();


private:
	float xpos;
	float ypos;
	int xspeed;
	int yspeed;

	ofColor color;
	//float color?
	float radius;

};

