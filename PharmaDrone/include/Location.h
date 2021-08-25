/********************************    Location class declaration     ***********************************

                            Stores information about a patient's location

*******************************************************************************************************/

#ifndef LOCATION_H
#define LOCATION_H

class Location
{
   public:

      int distance, angle;
      float cX, cY;                //Cartesian coordinates

   public:

      Location();                  //Constructor
      void setCoordinates();       //Calculates coordinates of given location
      int getDistance();
      void setDistance(int dist);
      int getAngle();
      void setAngle(int ang);


};

#endif // LOCATION_H
