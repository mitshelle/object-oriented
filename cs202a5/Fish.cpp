/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 5
	*Description: program to practice pointers, arrays, classes for virtual aquarium
	*Input: height & width
	*Output: fish tank with fish swimming 
*/
#include "Fish.h"

//******************* VertiFish function implementations *******************
//Flips direction on collision with a wall and changes drawing char
void VertiFish::onWallCollision() 
{ 

  // flip direction because going to hit wall 
  if(facingUp){
    facingUp = false;
  }else{
    facingUp = true;
  }
  
  // change drawChar
  if(facingUp){
    drawChar = '^';
  }else{
    drawChar = 'V';
  }
}

//Moves the fish either up or down every frame, depending on which direction it is facing
void VertiFish::swim(Tank* tank) 
{ 
  // declared var 
  int upDownPos = 0;

  // check direction fish facing 
  if(facingUp){ // move down because last col is biggest num
    upDownPos -= 1; // need to subtract to get to 0 which is 1st row
  }else{ // move up 
    upDownPos += 1; // need to add to get to last col which is width - 1 
  }
  
  // call to func to actually move 
  tank->moveFish(this, 0, upDownPos);
}

//******************* HorizontaFish function implementations *******************
//Turns around on collision with a wall and changes drawing char
void HorizontaFish::onWallCollision() 
{
  // flip direction 
  if(facingRight){
    facingRight = false;
  }else{
    facingRight = true;
  }

  // change char
	if(facingRight){
    drawChar = '>';
  }else{
    drawChar = '<';
  }
}

//Moves the fish either right or left every frame depending on the direction it is facing
void HorizontaFish::swim(Tank* tank) 
{
  // declared var 
	int rightLeftPos = 0;

  // check direction fish facing 
  if(facingRight){ // move right
    rightLeftPos += 1;
  }else{ // move left 
    rightLeftPos -= 1;
  }
  
  // call to func to actually move 
  tank->moveFish(this, rightLeftPos, 0);
}

//******************* WallFish function implementations *******************
void WallFish::onWallCollision() { /*Do nothing. This needs to exist for WallFish to not be abstract */ }



void WallFish::swim(Tank*) { /*Do nothing. This needs to exist for WallFish to not be abstract */ }