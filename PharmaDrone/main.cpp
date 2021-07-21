/************************************************************************************************
 * Name of the application: PharmaDrone                                                         *
 *                                                                                              *
 * Description: Software that manages medicine delivery and distribution using drones           *
 * located in 10 warehouses                                                                     *
 *                                                                                              *
 * Author:  Isabel Manzaneque                                                                   *
 * Version: 0.1                                                                                 *
 ************************************************************************************************/


#include <iostream>
#include <string>
#include "Warehouse.h"
#include "SysManager.h"

using namespace std;

/* Main method that allows the user to choose one of the program's actions. If the inserted input
   is not valid, a valid input will be requested in a loop*/

int main()
{

    SysManager manager;
    char option;

    do{
        fflush(stdin);
        option = ' ';

        cout<<"\n   _____________________________________________________________\n";
        cout<<"  |                                                             |\n";
        cout<<"  |  PharmaDrone system for medicine distribution and delivery: |\n";
        cout<<"  |                                                             |\n";
        cout<<"  |      Load and show data base                     (Press I)  |\n";
        cout<<"  |      Set up a new warehouse                      (Press W)  |\n";
        cout<<"  |      Set up new client in a warehouse            (Press C)  |\n";
        cout<<"  |      Show registered patients                    (Press L)  |\n";
        cout<<"  |      New order                                   (Press N)  |\n";
        cout<<"  |      Daily list of orders                        (Press O)  |\n";
        cout<<"  |      Program daily drone routes                  (Press P)  |\n";
        cout<<"  |      Show drone routes                           (Press R)  |\n";
        cout<<"  |      Exit                                        (Press E)  |\n";
        cout<<"  |_____________________________________________________________|\n\n";

        cout<< "     Insert a valid option (I|W|C|L|N|O|P|R|E): ", cin>>option;
        switch (option){
          case 'I':
            system("cls");
            manager.dataBase();
            break;
          case 'W':
            system("cls");
            manager.addWarehouse();
            break;
          case 'C':
          case 'L':
          case 'N':
          case 'O':
          case 'P':
          case 'R':
            manager.selectAction(option);
            break;
          case 'E':
            cout<<"\n     Logging out"<<endl;
            break;
          default:
            cout<<"\n     The inserted option is not valid \n"<<endl;
        }

       }while (option!='E');

    return 0;
}
