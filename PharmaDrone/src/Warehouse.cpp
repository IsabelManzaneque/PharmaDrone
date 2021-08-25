
/**********************************   Warehouse class implementation    *************************************/


#include "Warehouse.h"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

/* Class constructor */

Warehouse::Warehouse()
    : warehouseID{0} {}

/* Reads the details of a new warehouse and checks if the input is valid*/

void Warehouse::newWarehouse()
{

   ExceptionManager eManager;
   char aux = ' ';


   do{


        printf("\n --------------------------------------------------------------\n");
        printf(" |               New warehouse registration form              |\n");
        printf(" --------------------------------------------------------------\n");
       //Reads the warehouse ID from input

        cout<<"\n     Enter warehouse ID (1 - 10): ";
         do{
            cin>>warehouseID;
            if ( !cin || warehouseID < 1 || warehouseID > 10 ){
               eManager.cinException();
            }
        }while(warehouseID < 1 || warehouseID > 10);

       //Reads the address from input

        cout<<"\n     Enter the address: ";
        do{
            getline(cin, address);
        }while(!eManager.checkString(address));

        //Reads the postcode from input and checks if the format is valid

        cout<<"\n     Enter the postcode: ";
        do{
            getline(cin, postcode);
        }while(!eManager.checkString(postcode));

        //Reads the borough from input

        cout<<"\n     Enter the borough: ";
        do{
            getline(cin, borough);
        }while(!eManager.checkString(borough));


        cout << "\n\n Are these details correct? (Y/N): ", cin >> aux;

    }while (aux == 'N');

}


/* returns a reference to the drone variable's location in memory */

Drone& Warehouse::getDrone()
{
    return drone;
}

/* Returns the warehouse's ID */

int Warehouse::getWarehouseID()
{
    return warehouseID;
}

/* Updates he warehouse's ID */

void Warehouse::setWarehouseID(int id)
{
    warehouseID = id;
}

/* updates the warehouse's info */

void Warehouse::setWarehouseInfo(string a, string p, string b)
{
    address = a;
    postcode = p;
    borough = b;
}

/* Returns the warehouse's info */

string Warehouse::getWarehouseInfo()
{
   ostringstream os;
    os << address << " - " << postcode << " - "<< borough ;
    return os.str();
}



