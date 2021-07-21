/********************************    Location class declaration     ***********************************

                            Stores information about a patient's location

*******************************************************************************************************/

#ifndef LOCATION_H
#define LOCATION_H

class Location
{
   public:

      int distance, angle;
      float cX, cY;      //Cartesian coordinates

   public:

      Location()
      {
          distance, angle = 0;
          cX, cY = 0.0;
      }

      int getDistance();
      void setDistance(int dist);
      int getAngle();
      void setAngle(int ang);
      void setCoordinates();                           //Calculates coordinates of given location

};

#endif // LOCATION_H
