
/****************************    Location class implementation   ******************************/



#include "Location.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Location::getDistance()
{
  return distance;
}

void Location::setDistance(int dist)
{
  distance = dist;
}

int Location::getAngle()
{
  return angle;
}

void Location::setAngle(int ang)
{
  angle = ang;
}
/* Calculates Y coordinate of a given location multiplying the distance by the angle's sin.
   Calculates X coordinate multiplying the distance by the angle's cos. */

void Location::setCoordinates(){

  float beta = float(angle)*M_PI/1000.0;    //converts an angle expressed in pi/1000 radians to radians

  cX = float(distance)*cosf(beta);
  cY = float(distance)*sinf(beta);

}

