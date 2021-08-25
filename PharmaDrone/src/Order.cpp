
/**********************************   Order class implementation    *************************************/


#include "Order.h"
#include <iostream>
#include <string.h>

using namespace std;


/* Class constructor */

Order::Order()
   : orderWeight{0}, medicineCounter{0}, patientID{0}, numOfOrders{0}, daysBetweenOrders{0}{}

/* Reads the details of a new order and checks if the input is valid. An order cannot
   exceed the maximum weight or medicine number*/

void Order::newOrder(std::array<Patient, 20> patientArray)
{
    ExceptionManager eManager;
    char aux = ' ';
    bool match = false;


 do{

      printf("\n --------------------------------------------------------------\n");
      printf(" |                 New order registration form                |\n");
      printf(" --------------------------------------------------------------\n");
   // Lee la referencia y la compara con vector pacientes

      cout<<"\n     Enter patient's ID: ";
      do{
         cin>>patientID;
      }while(!eManager.cinExceptionB());


      for(auto patient :  patientArray){
         if(patientID == patient.getID()){
           match = true;
         }
       }

    // If there is a match allows to book a new order

      if(match){

            cout<<"\n     Insert number of orders (between 1 and 100 orders): ";
            do{
                cin>>numOfOrders;
                if ( !cin || numOfOrders < 1 || numOfOrders > 100){
                   eManager.cinException();
                }
            }while(numOfOrders < 1 || numOfOrders > 100);


            if(numOfOrders > 1){
                cout<<"\n     Days in between orders? (between 1 and 15 days)?: ";
                do{
                    cin>>daysBetweenOrders;
                    if( !cin || daysBetweenOrders < 1 || daysBetweenOrders > 15 ){
                       eManager.cinException();
                    }
                }while(daysBetweenOrders < 1 || daysBetweenOrders > 15 );
                cout<<"\n     Insert date of first delivery: "<<endl;

            }else{
                cout<<"\n     Insert date of delivery: "<<endl;
            }

            do{
               date.readDate();
               if(!date.isCorrect()){
                   cout<<"\n     Enter a valid date:\n\n";
               }
            }while(!date.isCorrect());


      //If inserted date is correct, reads the details of a new medicine
      //Up to 5 medicines are allowed as long as the maximum capacity of the drone is not reached

             do{

                  do{

                     medicineArray[medicineCounter].newMedicine();
                     if((orderWeight + medicineArray[medicineCounter].getTotalWeight())>3000){
                       cout<<"     The max weight the drone can carry has been exceeded, try again: \n";
                     }
                  }while((orderWeight + medicineArray[medicineCounter].getTotalWeight())>3000);

                   orderWeight += medicineArray[medicineCounter].getTotalWeight();
                   medicineCounter ++;

                   if(orderWeight == 3000){
                      cout<<"     The max weight the drone can carry has been reached\n";
                      continue;
                   }
                   if(medicineCounter == 5){
                      cout<<"     The max capacity of the drone has been reached\n";
                      continue;
                   }

                   cout<<"\n Do you wish to add another medicine to the order(Y/N)? ", cin>>aux;

             }while ((aux == 'Y')&&(orderWeight < 3000)&&(medicineCounter<5));

      }else{
         cout<<"     Unable to find a patient with the inserted ID\n";
      }
  }while(!match);

}


/* returns a reference to a position of the medicineArray */

Medicine& Order::getMedicine(int position)
{
    return medicineArray[position];
}

/* updates the ID of the patient that placed the order */

void Order::setPatientID(int id)
{
   patientID = id;
}

/* returns the ID of the patient that placed the order */

int Order::getPatientID()
{
    return patientID;
}

/* updates the order's weight */

void Order::setOrderWeight(int w)
{
   orderWeight = w;
}

/* returns the order's weight */

int Order::getOrderWeight()
{
    return orderWeight;
}

/* returns the number of elements stored in medicineArray */

int Order::getMedicineCounter()
{
    return medicineCounter;
}

/* updates the number of elements stored in medicineArray */

void Order::setMedicineCounter(int c)
{
   medicineCounter = c;
}

/* returns a Calendar variable with the order's date */

Calendar Order::getOrderDate()
{
    return date;
}

/* updates the order's date */

void Order::setOrderDate(int d, int m, int y)
{
   date.setDate(d,m,y);
}


