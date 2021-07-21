/**************************************    Route class declaration    ***************************************

                        Calculates the most efficient routes for the drone to follow

***************************************************************************************************************/

#ifndef ROUTE_H
#define ROUTE_H
#include "Patient.h"
#include "Order.h"
#include "Calendar.h"
#include <vector>
#include <array>


class Route
{
    private:

        struct Path
        {
             Patient pA, pB;
             int distanceAtoB;
             int angleAtoB;
             int weightAtoB;
             int descWeight;
        };
        std::vector<Order> orders;                   //orders placed by the patients stored in patients vector
        std::vector<Patient> patients;               //patients to be seen before return trip to the warehouse
        std::vector<Path> pathVector;                //stores a route's paths from point A to point B
        int totalDistance, totalWeight;
        Calendar date;

    public:

        Route(Calendar d, std::array<Order, 100> orderArray, std::array<Patient, 20> patientArray )
        {
            date = d;
            setOrders(orderArray);
            setPatients(patientArray);
        }


        std::vector<Patient> newRoute();                     //calculates the most efficient route
        int findDistanceAB(Patient pA, Patient pB);          //finds the distance between 2 patients
        int findAngleAB(Patient pA, Patient pB);             //finds the angle between 2 patients
        int findWeightAB(Patient patient);                   //finds the weight between 2 patients
        int getMaxDistance();                                //calculates max distance the drone can travel
        Path& getPath(int position);                         //returns a reference to a pathVector's position

        void setOrders(std::array<Order, 100> orderArray);   //getters and setters of the attributes
        void setPatients(std::array<Patient, 20> patientArray);
        std::vector<Path> getPathVector();
        Calendar getRouteDate();
        int getTotalDistance();



};

#endif // ROUTE_H
