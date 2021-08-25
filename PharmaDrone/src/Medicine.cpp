
/**********************************   Medicine class implementation    *************************************/

#include "Medicine.h"
#include <iostream>
#include <string.h>


using namespace std;



/* Class constructor */

Medicine::Medicine()
     : weight{0},units{0}{}

/* Reads the details of a new medicine and checks that the entered input is valid */

 void Medicine::newMedicine()
 {
      ExceptionManager eManager;

     // Checks if a medicine's name is of a valid format
       fflush(stdin);
       cout<<"\n     Name of the medicine: ";
        do{
            getline(cin, name);
        }while(!eManager.checkString(name));


     //Checks if a medicine's weight is of a valid format

        cout<<"\n     Medicine's weight (between 1g and 3000g): ";
         do{
            cin>>weight;
            if ( !cin || weight < 1 || weight > 3000){
               eManager.cinException();
            }
        }while((weight < 1)||(weight > 3000));


     //Checks if a medicine's total of units is of a valid format

        cout<<"\n     Number of units (between 1 and 100 units): ";
         do{
            cin>>units;
            if ( !cin || units < 1 || units > 100 ){
              eManager.cinException();
            }
        }while((units < 1)||(units > 100));

 }


/*Returns total weight of a medication multiplying the weight by the units*/

int Medicine::getTotalWeight()
{
    return units*weight;
}

/* Updates the medicine's information */

void Medicine::setMedicineInfo(string n, int w, int u)
{
    name = n;
    weight = w;
    units = u;
}

/* Returns a string of the medicine's name */

string Medicine::getName()
{
    return name;
}

/* Returns an integer of the medicine's weight */

int Medicine::getWeight()
{
    return weight;
}

/* Returns an integer of the requested doses */

int Medicine::getUnits()
{
    return units;
}
