/************************************    Drone class declaration    *********************************************

 Class that manages each warehouse's drone. Contains its functionalities, a list of patients and a list of orders

*****************************************************************************************************************/

#ifndef DRONE_H
#define DRONE_H
#include "Calendar.h"
#include "Patient.h"
#include "Order.h"
#include "Route.h"
#include <vector>
#include <array>



class Drone
{
    private:

        std::vector<Route> routeVector;       //stores the drone's daily routes
        std::array<Order, 100> orderArray;    //stores up to 100 orders
        std::array<Patient, 20> patientArray; //stores up to 20 patients
        int orderCounter, patientCounter;

    public:

        Drone()
        {
            orderCounter = 0;
            patientCounter = 0;
        }

        void addPatient();                  //stores a patient in the patients array
        void showPatients();                //prints out the drone's list of registered patients
        void addOrder();                    //stores an order in the orders array
        void showOrders();                  //prints out the drone's list of scheduled deliveries
        void planRoute();                   //calculates and shows the routes the drone will follow
        int showRoutes();                   //graphic representation of the routes
        Patient& getPatient(int position);  //returns a reference to a patientArray's position
        Order& getOrder(int position);      //returns a reference to a orderArray's position

        int getOrderCounter();              //getters and setters of the attributes
        void setOrderCounter(int n);
        int getPatientCounter();
        void setPatientCounter(int n);
};

#endif // DRONE_H
