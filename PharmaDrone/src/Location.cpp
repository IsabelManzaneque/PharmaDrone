
/****************************    Location class implementation   ******************************/



#include "Location.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Class constructor */

Location::Location()
   : distance{0}, angle{0}, cX{0.0}, cY{0.0} {}

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

  float beta = static_cast<float>(angle)*M_PI/1000.0;    //converts an angle expressed in pi/1000 radians to radians

  cX = static_cast<float>(distance)*cosf(beta);
  cY = static_cast<float>(distance)*sinf(beta);

}

