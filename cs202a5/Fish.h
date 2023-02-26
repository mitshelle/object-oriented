/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 5
	*Description: program to practice pointers, arrays, classes for virtual aquarium
	*Input: height & width
	*Output: fish tank with fish swimming 
*/
#ifndef FISH_H
#define FISH_H

#include "Tank.h"

//Abstract base class for all fish that will be in our tank. Inherits from TankSpace since all Fish will inhabit a space in the tank
class Fish : public TankObject
{
	public:
		//Abstract function called by the Tank when a Fish collides with a wall
		virtual void onWallCollision() = 0; 
		//TODO: Make an abstract swim function for all fish to implement
    virtual void swim(Tank*) = 0;
	  virtual ~Fish() {};
	protected:
		static int count; //Count of all of the fish in the tank
		//Constructor for all types of Fish
		Fish(int x, int y, char drawChar) : TankObject(x, y, drawChar) { count++; }
};

//Class for fish that move vertically every frame
class VertiFish : public Fish
{
	bool facingUp;

	protected:
		virtual void onWallCollision(); //onWallCollision override. You can use this as reference for how to declare the other virtual functions...

	public:
		//TODO: Override the abstract swim function from the Fish class
    virtual void swim(Tank*);
		VertiFish(int x, int y, bool direction = true) : Fish(x, y, '^') { facingUp = direction; drawChar = facingUp ? '^' : 'V'; }
};

//Class for fish that move horizontally every frame
class HorizontaFish : public Fish
{
	bool facingRight;

	protected:
		virtual void onWallCollision();

	public:
		//TODO: Override the abstract swim function from the Fish class
    virtual void swim(Tank*);
		HorizontaFish(int x, int y, bool direction = true) : Fish(x, y, '>') { facingRight = direction; drawChar = facingRight ? '>' : '<'; }
};

class WallFish : public Fish 
{
	protected:
		virtual void onWallCollision();
	public:
		//TODO: Override the abstract swim function from the Fish class
    virtual void swim(Tank*);
		WallFish(int x, int y) : Fish(x, y, 'W') {}
};

#endif
