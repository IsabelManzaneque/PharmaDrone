/**********************************   SysManager class implementation    *************************************/

#include "SysManager.h"
#include <iostream>

using namespace std;


/* Class constructor */

SysManager::SysManager()
   : warehouseCounter {0} {}

/* Adds the following fixed data: 5 warehouses, 12 patients and 15 orders */

void SysManager::dataBase()
{
   /* WAREHOUSE 1 */

   warehouseArray[0].setWarehouseID(1);
   warehouseArray[0].setWarehouseInfo("3 Tintern Street","SW4 7QQ","Lambeth");

   //patient 1 and its orders

   warehouseArray[0].getDrone().getPatient(0).setID(1);
   warehouseArray[0].getDrone().getPatient(0).setName("Manolo Garcia");
   warehouseArray[0].getDrone().getPatient(0).setLocation(7300, 120);

     warehouseArray[0].getDrone().getOrder(0).setPatientID(1);
     warehouseArray[0].getDrone().getOrder(0).setOrderDate(2, 11, 2020);
     warehouseArray[0].getDrone().getOrder(0).getMedicine(0).setMedicineInfo("Nolotil",100,3);

     warehouseArray[0].getDrone().getOrder(0).getMedicine(1).setMedicineInfo("Ibuprofen",50,2);
     warehouseArray[0].getDrone().getOrder(0).setMedicineCounter(2);
     warehouseArray[0].getDrone().getOrder(0).setOrderWeight(400);


  // patient 2 and its orders

   warehouseArray[0].getDrone().getPatient(1).setID(2);
   warehouseArray[0].getDrone().getPatient(1).setName("Isabel Manzaneque");
   warehouseArray[0].getDrone().getPatient(1).setLocation(4750, 400);

     warehouseArray[0].getDrone().getOrder(1).setPatientID(2);
     warehouseArray[0].getDrone().getOrder(1).setOrderDate(14, 12, 2020);
     warehouseArray[0].getDrone().getOrder(1).getMedicine(0).setMedicineInfo("Armodafinil",80,5);
     warehouseArray[0].getDrone().getOrder(1).setMedicineCounter(1);
     warehouseArray[0].getDrone().getOrder(1).setOrderWeight(400) ;

   // patient 3 and its orders

   warehouseArray[0].getDrone().getPatient(2).setID(3);
   warehouseArray[0].getDrone().getPatient(2).setName("Roberto Fernandez");
   warehouseArray[0].getDrone().getPatient(2).setLocation(1000, 250);

     warehouseArray[0].getDrone().getOrder(2).setPatientID(3);
     warehouseArray[0].getDrone().getOrder(2).setOrderDate(14, 12, 2020);
     warehouseArray[0].getDrone().getOrder(2).getMedicine(0).setMedicineInfo("Clonazepam",75,1);
     warehouseArray[0].getDrone().getOrder(2).setMedicineCounter(1);
     warehouseArray[0].getDrone().getOrder(2).setOrderWeight(75);

     warehouseArray[0].getDrone().getOrder(3).setPatientID(3);
     warehouseArray[0].getDrone().getOrder(3).setOrderDate(23, 1, 2021);
     warehouseArray[0].getDrone().getOrder(3).getMedicine(0).setMedicineInfo("Clonazepam",75,1);
     warehouseArray[0].getDrone().getOrder(3).getMedicine(1).setMedicineInfo("Ibuprofen",50,2);
     warehouseArray[0].getDrone().getOrder(3).setMedicineCounter(2);
     warehouseArray[0].getDrone().getOrder(3).setOrderWeight(175);

   // patient 4 and its orders

   warehouseArray[0].getDrone().getPatient(3).setID(4);
   warehouseArray[0].getDrone().getPatient(3).setName("Elisa Nunez");
   warehouseArray[0].getDrone().getPatient(3).setLocation(825, 145);

     warehouseArray[0].getDrone().getOrder(4).setPatientID(4);
     warehouseArray[0].getDrone().getOrder(4).setOrderDate(25, 1, 2021);
     warehouseArray[0].getDrone().getOrder(4).getMedicine(0).setMedicineInfo("Orfidal",250,3);
     warehouseArray[0].getDrone().getOrder(4).setMedicineCounter(1);
     warehouseArray[0].getDrone().getOrder(4).setOrderWeight(750);


   /* WAREHOUSE 2 */

   warehouseArray[1].setWarehouseID(2);
   warehouseArray[1].setWarehouseInfo("31 Clapham high street","SW4 7TR", "Lambeth");

   // This warehouse doesn't have any registered patients


   /* WAREHOUSE 3 */

   warehouseArray[2].setWarehouseID(5);
   warehouseArray[2].setWarehouseInfo(" 445 King Henrys Drive","CR5 0AB","Croydon");

   // patient 1 and its orders

   warehouseArray[2].getDrone().getPatient(0).setID(1);
   warehouseArray[2].getDrone().getPatient(0).setName("Tyke Pillay");
   warehouseArray[2].getDrone().getPatient(0).setLocation(2450, 600);

     warehouseArray[2].getDrone().getOrder(0).setPatientID(1);
     warehouseArray[2].getDrone().getOrder(0).setOrderDate(4, 10, 2020);
     warehouseArray[2].getDrone().getOrder(0).getMedicine(0).setMedicineInfo("Aspirin",90,1);
     warehouseArray[2].getDrone().getOrder(0).setMedicineCounter(1);
     warehouseArray[2].getDrone().getOrder(0).setOrderWeight(90);

     warehouseArray[2].getDrone().getOrder(1).setPatientID(1);
     warehouseArray[2].getDrone().getOrder(1).setOrderDate(1, 11, 2020);
     warehouseArray[2].getDrone().getOrder(1).getMedicine(0).setMedicineInfo("Aspirin",90,3);
     warehouseArray[2].getDrone().getOrder(1).setMedicineCounter(1);
     warehouseArray[2].getDrone().getOrder(1).setOrderWeight(270);


   // patient 2 and its orders

   warehouseArray[2].getDrone().getPatient(1).setID(2);
   warehouseArray[2].getDrone().getPatient(1).setName("Luis Fernando Nunez");
   warehouseArray[2].getDrone().getPatient(1).setLocation(200, 650);

     warehouseArray[2].getDrone().getOrder(2).setPatientID(2);
     warehouseArray[2].getDrone().getOrder(2).setOrderDate(8, 11, 2020);
     warehouseArray[2].getDrone().getOrder(2).getMedicine(0).setMedicineInfo("Viagra",45,5);
     warehouseArray[2].getDrone().getOrder(2).setMedicineCounter(1);
     warehouseArray[2].getDrone().getOrder(2).setOrderWeight(225);


   // patient 3 and its orders

   warehouseArray[2].getDrone().getPatient(2).setID(3);
   warehouseArray[2].getDrone().getPatient(2).setName("Paco Alonso");
   warehouseArray[2].getDrone().getPatient(2).setLocation(3000, 425);

     warehouseArray[2].getDrone().getOrder(3).setPatientID(3);
     warehouseArray[2].getDrone().getOrder(3).setOrderDate(8, 11, 2020);
     warehouseArray[2].getDrone().getOrder(3).getMedicine(0).setMedicineInfo("Cocodamol",200,2);
     warehouseArray[2].getDrone().getOrder(3).getMedicine(1).setMedicineInfo("Ibuprofeno",50,1);
     warehouseArray[2].getDrone().getOrder(3).setMedicineCounter(2);
     warehouseArray[2].getDrone().getOrder(3).setOrderWeight(450);


   /* WAREHOUSE 4 */

   warehouseArray[3].setWarehouseID(6);
   warehouseArray[3].setWarehouseInfo("2 Grantham Road","E12 5AE","Newham");


   // This warehouse doesn't have any registered patients


   /* WAREHOUSE 5 */

   warehouseArray[4].setWarehouseID(7);
   warehouseArray[4].setWarehouseInfo("64 Christchurch Way","SE10 5AA","GreenWich");

   // patient 1 and its orders

   warehouseArray[4].getDrone().getPatient(0).setID(1);
   warehouseArray[4].getDrone().getPatient(0).setName("Loli Martinez");
   warehouseArray[4].getDrone().getPatient(0).setLocation(2789, 867);

     warehouseArray[4].getDrone().getOrder(0).setPatientID(1);
     warehouseArray[4].getDrone().getOrder(0).setOrderDate(3, 1, 2021);
     warehouseArray[4].getDrone().getOrder(0).getMedicine(0).setMedicineInfo("Orfidal",35,6);
     warehouseArray[4].getDrone().getOrder(0).getMedicine(1).setMedicineInfo("Paracetamol",50,2);
     warehouseArray[4].getDrone().getOrder(0).setMedicineCounter(2);
     warehouseArray[4].getDrone().getOrder(0).setOrderWeight(310);


   // patient 2 and its orders

   warehouseArray[4].getDrone().getPatient(1).setID(2);
   warehouseArray[4].getDrone().getPatient(1).setName("Alba Perales");
   warehouseArray[4].getDrone().getPatient(1).setLocation(8876, 1356);

     warehouseArray[4].getDrone().getOrder(1).setPatientID(2);
     warehouseArray[4].getDrone().getOrder(1).setOrderDate(3, 1, 2021);
     warehouseArray[4].getDrone().getOrder(1).getMedicine(0).setMedicineInfo("Keppra",100,5);
     warehouseArray[4].getDrone().getOrder(1).setMedicineCounter(1);
     warehouseArray[4].getDrone().getOrder(1).setOrderWeight(500);


   // patient 3 and its orders

   warehouseArray[4].getDrone().getPatient(2).setID(3);
   warehouseArray[4].getDrone().getPatient(2).setName("Carlos Torres Beas");
   warehouseArray[4].getDrone().getPatient(2).setLocation(9550, 800);

     warehouseArray[4].getDrone().getOrder(2).setPatientID(3);
     warehouseArray[4].getDrone().getOrder(2).setOrderDate(3, 1, 2021);
     warehouseArray[4].getDrone().getOrder(2).getMedicine(0).setMedicineInfo("Probanthine",75,1);
     warehouseArray[4].getDrone().getOrder(2).setMedicineCounter(1);
     warehouseArray[4].getDrone().getOrder(2).setOrderWeight(75);

     warehouseArray[4].getDrone().getOrder(3).setPatientID(3);
     warehouseArray[4].getDrone().getOrder(3).setOrderDate(25, 1, 2021);
     warehouseArray[4].getDrone().getOrder(3).getMedicine(0).setMedicineInfo("Probanthine",75,1);
     warehouseArray[4].getDrone().getOrder(3).getMedicine(1).setMedicineInfo("Cocodamol",260,2);
     warehouseArray[4].getDrone().getOrder(3).setMedicineCounter(2);
     warehouseArray[4].getDrone().getOrder(3).setOrderWeight(595);


   // patient 4 and its orders

   warehouseArray[4].getDrone().getPatient(3).setID(4);
   warehouseArray[4].getDrone().getPatient(3).setName("Amy Smith");
   warehouseArray[4].getDrone().getPatient(3).setLocation(9000, 1400);

     warehouseArray[4].getDrone().getOrder(4).setPatientID(4);
     warehouseArray[4].getDrone().getOrder(4).setOrderDate(3, 1, 2021);
     warehouseArray[4].getDrone().getOrder(4).getMedicine(0).setMedicineInfo("Mint",10,1);
     warehouseArray[4].getDrone().getOrder(4).setMedicineCounter(1);
     warehouseArray[4].getDrone().getOrder(4).setOrderWeight(10);


   // patient 5 and its orders

   warehouseArray[4].getDrone().getPatient(4).setID(5);
   warehouseArray[4].getDrone().getPatient(4).setName("Laura Lopez");
   warehouseArray[4].getDrone().getPatient(4).setLocation(9500, 1800);

     warehouseArray[4].getDrone().getOrder(5).setPatientID(5);
     warehouseArray[4].getDrone().getOrder(5).setOrderDate(3, 1, 2021);
     warehouseArray[4].getDrone().getOrder(5).getMedicine(0).setMedicineInfo("Lamotrigine",10,7);
     warehouseArray[4].getDrone().getOrder(5).setMedicineCounter(1);
     warehouseArray[4].getDrone().getOrder(5).setOrderWeight(70);


   // Total of warehouses, patients and orders

   warehouseArray[0].getDrone().setOrderCounter(5);
   warehouseArray[0].getDrone().setPatientCounter(4);
   warehouseArray[1].getDrone().setOrderCounter(0);
   warehouseArray[1].getDrone().setPatientCounter(0);
   warehouseArray[2].getDrone().setOrderCounter(4);
   warehouseArray[2].getDrone().setPatientCounter(3);
   warehouseArray[3].getDrone().setOrderCounter(0);
   warehouseArray[3].getDrone().setPatientCounter(0);
   warehouseArray[4].getDrone().setOrderCounter(6);
   warehouseArray[4].getDrone().setPatientCounter(5);
   warehouseCounter = 5;


   // print out of the saved data"

   printf("\n ------------------------------------------------------------\n");
   printf(" |                     System Data Base                     |\n");
   printf(" ------------------------------------------------------------\n\n");

   for(int k=0; k<warehouseCounter; k++){
       printf("     Warehouse %2d: %s\n", warehouseArray[k].getWarehouseID(), warehouseArray[k].getWarehouseInfo().c_str());

       if (warehouseArray[k].getDrone().getPatientCounter() > 0){

           warehouseArray[k].getDrone().showPatients();

           printf("\n\n     Scheduled Orders:\n\n");
           printf("     Patient     Date        Medicine        Weight   Units\n\n");

           for (int i=0; i < warehouseArray[k].getDrone().getOrderCounter(); i++){
               for (int j=0; j < warehouseArray[k].getDrone().getOrder(i).getMedicineCounter(); j++){

                 printf("     %d          %-10s   %-13s   %3d      %d\n", warehouseArray[k].getDrone().getOrder(i).getPatientID(),warehouseArray[k].getDrone().getOrder(i).getOrderDate().getDateString().c_str(),
                        warehouseArray[k].getDrone().getOrder(i).getMedicine(j).getName().c_str(), warehouseArray[k].getDrone().getOrder(i).getMedicine(j).getWeight(),warehouseArray[k].getDrone().getOrder(i).getMedicine(j).getUnits());
               }
            }

        }else{
            cout<<"\n     - No patients or orders registered in this warehouse -";
        }
        cout<<"\n\n\n";
     }

}


/* Adds a new warehouse to the warehouseArray. If the maximum of registered warehouses (10) has been reached,
   asks the user if an existing warehouse should be removed. The new warehouse will overwrite the old one */

void SysManager::addWarehouse()
{
    int id;
    bool match;
    char aux = ' ';

   // If maximum of registered warehouses has not been reached, allows to register a new one
   // If the warehouse ID is being used, a different one will be requested

     if(warehouseCounter < 10){

         do{
             match = false;
             warehouseArray[warehouseCounter].newWarehouse();

             for (int i = 0; i<warehouseCounter; i++){
               if (warehouseArray[i].getWarehouseID() == warehouseArray[warehouseCounter].getWarehouseID()){
               match = true;
               }
             }
             if (match){
               printf("\n     The inserted ID is already in use, use a different one\n");
             }
         }while(match);

         warehouseCounter ++;

    // At this point, the maximum of registered warehouses has been reached

     }else{
        cout << " There are already 10 registered warehouses, delete an existing one?(Y/N) ", cin >> aux;

        if(aux == 'Y'){
           cout << "\n Enter the ID of the warehouse to delete: ", cin >> id;

           for(int i=0; i<10; i++){
              if( id == warehouseArray[i].getWarehouseID()){
                   warehouseArray[i].newWarehouse();
                   warehouseArray[i].getDrone().setOrderCounter(0);
                   warehouseArray[i].getDrone().setPatientCounter(0);
              }
            }
         }
      }
}



/* Depending on the received parameter: adds a new patient to a selected warehouse, shows its registered patients,
   adds a new order for an existing patient, shows the scheduled orders for a given date, programs the drone's
   routes or shows a graphic representation of these routes.
   If the warehouse ID is not found, the application returns
   to the main menu */

void SysManager::selectAction(char option)
{
    int id;
    ExceptionManager eManager;
    bool match = false;

    cout<<"\n     Select a warehouse to proceed (1 - 10): ", cin >> id;
    if(eManager.cinExceptionB()){

        for(int i=0; i<warehouseCounter; i++){
           if(id == warehouseArray[i].getWarehouseID()){

                match = true;
                switch (option){
                  case 'C':
                    system("cls");
                    warehouseArray[i].getDrone().addPatient();
                    break;
                  case 'L':
                    warehouseArray[i].getDrone().showPatients();
                    break;
                  case 'N':
                    system("cls");
                    warehouseArray[i].getDrone().addOrder();
                    break;
                  case 'O':
                    warehouseArray[i].getDrone().showOrders();
                    break;
                  case 'P':
                    warehouseArray[i].getDrone().planRoute();
                    break;
                  case 'R':
                    warehouseArray[i].getDrone().showRoutes();
                    break;
                 }
             }
         }
         if (!match){
             cout<<"\n     Unable to find a warehouse with the entered ID\n\n";
         }
    }
}
