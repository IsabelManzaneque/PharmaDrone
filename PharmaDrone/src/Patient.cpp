
/**********************************   Patient class implementation    *************************************/

#include "Patient.h"
#include <iostream>
#include <string.h>


using namespace std;


/* Reads the details of a new patient and checks if the input is valid*/

void Patient::newPatient()
{

    ExceptionManager eManager;
    char aux = ' ';

    do{
        printf("\n --------------------------------------------------------------\n");
        printf(" |                New patient registration form               |\n");
        printf(" --------------------------------------------------------------\n");

       //Checks if a patients's name is of a valid format
        fflush(stdin);
        cout<<"\n     Enter the patient's Full Name: ";
        do{
            getline(cin, name);
        }while(!eManager.checkString(name));


       //Checks if the location's distance is of a valid format

         cout<<"\n     Distance (up to 10000 meters when fully loaded): ";
         do{
            cin>>location.distance;
            if ( !cin || location.distance < 1 || location.distance > 10000 ){
               eManager.cinException();
            }
        }while((location.distance < 1)||(location.distance > 10000));


        //Checks if the location's angle is of a valid format

        cout<<"\n     Angle (between 0 and 2000 pi/1000 radians): ";
        do{
            cin>>location.angle;
            if ( !cin || location.angle < 1 || location.angle > 2000 ){
              eManager.cinException();
            }
        }while((location.angle < 1)||(location.angle > 2000));


        //Calculates coordinates of given location

        location.setCoordinates();

        cout << "\n\n Are these details correct? (Y/N): ", cin >> aux;

    }while (aux == 'N');
}


/* defines == operator: two patients are the same if they have the same ID */

bool Patient::operator==(const Patient& other) const
{
    return patientID == other.patientID;
}


/* defines < operator: two patients are different if they have different ID */

bool Patient::operator<(const Patient& other) const
{
    return patientID < other.patientID;
}

/* returns integer of the patient's ID */

int Patient::getID()
{
    return patientID;
}

/* updates the patient's ID */

void Patient::setID(int id)
{
   patientID = id;
}

/* returns a string of the patient's name */

string Patient::getName()
{
    return name;
}

/* updates the patient's name */

void Patient::setName(string n)
{
    name = n;
}

/* returns a Location variable with information about the patient's location */

Location Patient::getLocation()
{
    return location;
}

/* Updates the patients location */

void Patient::setLocation(int d, int a)
{
    location.setDistance(d);
    location.setAngle(a);
    location.setCoordinates();
}


