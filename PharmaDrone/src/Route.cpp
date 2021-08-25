
/**********************************   Route class implementation    *************************************/

#include "Route.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/* Class constructor */

Route::Route(Calendar d, std::array<Order, 100> orderArray, std::array<Patient, 20> patientArray )
   : date{d}{

   setOrders(orderArray);
   setPatients(patientArray);
}

/* Given a vector of patients and their orders, calculates the most efficient route for
   the maximum distance the drone can travel whilst carrying those orders */

vector<Patient> Route::newRoute()
{

    Path path;
    Patient warehouse, p;
    vector<Patient> unattendedPatients;
    totalDistance = 0;
    totalWeight = 0;

    // inserts a Patient element in the vector's first position to simulate the warehouse

    warehouse.setName("Warehouse");
    patients.insert(patients.begin(), warehouse);

    //sorts the vector by distance

    for (int i = 0; i < (patients.size()-1); ++i) {
        for (int j = i+2; j < patients.size() ; ++j) {

              if ( findDistanceAB(patients[i], patients[i+1]) > findDistanceAB(patients[i], patients[j])) {
                p = patients[i+1];
                patients[i+1] = patients[j];
                patients[j] = p;
              }
         }

         // If the drone can't, at least, go to the next patient and back to the warehouse
         // jumps to else
         if (((totalDistance+findDistanceAB(patients[i], patients[i+1])+ findDistanceAB(patients[i+1],warehouse)) < getMaxDistance())
             && ((totalWeight + findWeightAB(path.pB)) < 3000)){

                 path.pA = patients[i];
                 path.pB = patients[i+1];
                 path.distanceAtoB = findDistanceAB(patients[i], patients[i+1]);
                 path.angleAtoB = findAngleAB(patients[i], patients[i+1]);
                 path.weightAtoB = findWeightAB(path.pB);
                 pathVector.push_back(path);

                 totalDistance += path.distanceAtoB;
                 totalWeight += path.weightAtoB;

         }else{

                 unattendedPatients.push_back(patients[i+1]);
                 patients[i+1] = warehouse;
         }
     }

     //return trip back to the warehouse
     path.pA = pathVector[pathVector.size()-1].pB;
     path.pB = warehouse;
     path.distanceAtoB = findDistanceAB(path.pA, warehouse);
     path.angleAtoB = findAngleAB(path.pA, warehouse);
     path.weightAtoB = findWeightAB(path.pB);
     pathVector.push_back(path);


     totalDistance += path.distanceAtoB;

     pathVector[0].descWeight = totalWeight;
     for(int j = 1; j<pathVector.size(); j++){
         pathVector[j].descWeight = pathVector[j-1].descWeight - pathVector[j-1].weightAtoB;
     }

     return unattendedPatients;

}

/* Calculates the distance between two locations using the vector's module */

int Route::findDistanceAB(Patient pA, Patient pB)
{

    float d;

    d = round(sqrt(((pB.getLocation().cX - pA.getLocation().cX)*(pB.getLocation().cX - pA.getLocation().cX))+
                   ((pB.getLocation().cY - pA.getLocation().cY)*(pB.getLocation().cY - pA.getLocation().cY))));

    return static_cast<int>(d);

}

/* Calculates the angle between the vector of two locations and the X axis */

int Route::findAngleAB(Patient pA, Patient pB)
{
     int a;

     a = static_cast<int>(round(atan2((pB.getLocation().cY - pA.getLocation().cY),(pB.getLocation().cX - pA.getLocation().cX))*1000.0/3.1416));

    (a >= 0)? a = a+0 : a= a+2000;  // If the angle is negative, adding 2000 will result in an equivalent positive angle

     return a;

   /*  if (a >= 0){
        return a;
     }else{
        return a+2000;
     }*/
}


/* Iterates through the orders array to add the weight of all the orders of a given patient  */

int Route::findWeightAB(Patient patient)
{
     int totalW = 0;
     for(auto order : orders){
        if(patient.getID() == order.getPatientID()){
            totalW += order.getOrderWeight();
        }
     }
     return totalW;

}


/* Calculates the maximum distance the drone can travel while carrying a certain weight */

int Route::getMaxDistance(){

 return  25000-((totalWeight*5000)/3000);

}


/* returns a reference to a position of the pathVector */

Route::Path& Route::getPath(int position)
{
    return pathVector[position];
}


/* Compares the stored date with the dates of a number of orders. If there is a match, the order
   is stored in the orders variable */

void Route::setOrders(std::array<Order, 100> orderArray)
{

 for(auto order : orderArray){
      if(date.isSame(order.getOrderDate().getDate())){
         orders.push_back(order);
      }
  }
}


/* Compares the ID of a number of patients with the patient ID of the orders stored in the orders vector.
   If there is a match, the patient is first inserted in a set to avoid duplicates and then
   stored in the patients variable */

void Route::setPatients(std::array<Patient, 20> patientArray){

  set<Patient> s;
  for (int i = 0; i < orders.size(); i++){
       for (int k = 0; k<20; k++){
            if(orders.at(i).getPatientID() == patientArray[k].getID()){
                s.insert(patientArray[k]);
             }
        }
   }
  patients.assign(s.begin(), s.end());
}

/* Returns the date for when the route is programmed */

Calendar Route::getRouteDate()
{
    return date;
}


/* Returns the sum of the distance of each path of the route */

int Route::getTotalDistance(){

 return  totalDistance;

}

/* Returns the pathVector */

vector<Route::Path> Route::getPathVector()
{
   return pathVector;
}





