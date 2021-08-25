/**************************************    Order class declaration    ***************************************

                        Registers a new patient and stores its personal details

***************************************************************************************************************/

#ifndef ORDER_H
#define ORDER_H
#include "Medicine.h"
#include "Calendar.h"
#include "Patient.h"
#include "ExceptionManager.h"
#include <array>

class Order
{
    private:

        Calendar date;
        int patientID;
        int orderWeight;
        int daysBetweenOrders;
        int numOfOrders;
        int medicineCounter;                   // counts the number of elements stored in medicineArray
        std::array<Medicine, 5> medicineArray; // stores up to 5 medicines per order

    public:

        Order();                                              //Constructor
        void newOrder(std::array<Patient, 20> patientArray);  //reads the details of a new order
        Medicine& getMedicine(int position);                  //returns a reference to a medicineArray's position

        void setPatientID(int id);                            //getters and setters of the attributes
        int getPatientID();
        void setOrderWeight(int w);
        int getOrderWeight();
        void setMedicineCounter(int id);
        int getMedicineCounter();
        void setOrderDate(int d, int m, int y);
        Calendar getOrderDate();


};

#endif // ORDER_H
