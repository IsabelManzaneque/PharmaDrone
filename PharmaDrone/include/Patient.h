/**************************************    Patient class declaration    ***************************************

                        Registers a new patient and stores its personal details

***************************************************************************************************************/


#ifndef PATIENT_H
#define PATIENT_H
#include "Location.h"
#include "ExceptionManager.h"
#include <string>

class Patient
{
     private:

        int patientID;
        std::string name;
        Location location;

     public:

        Patient();                                    //Constructor
        void newPatient();                            //reads a new patient form input
        bool operator==(const Patient& other) const;  //defines == operator
        bool operator<(const Patient& other) const;   //defines < operator

        int getID();                                  // getters and setters of the attributes
        void setID(int id);
        std::string getName();
        void setName(std::string n);
        Location getLocation();
        void setLocation(int d, int a);
};

#endif // PATIENT_H
