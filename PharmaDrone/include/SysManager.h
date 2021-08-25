/**********************************    SysManager class declaration    *******************************************

                  Manages the different actions that can be carried out by the software

*****************************************************************************************************************/


#ifndef SYSMANAGER_H
#define SYSMANAGER_H
#include "Warehouse.h"
#include "Calendar.h"
#include "ExceptionManager.h"


class SysManager
{
    private:

        std::array<Warehouse, 10> warehouseArray; // stores up to 10 warehouses
        int warehouseCounter;

    public:

        SysManager();                   //Constructor
        void dataBase();                // adds fixed costumers and orders into the system
        void addWarehouse();            // adds a new warehouse to the system
        void selectAction(char option); // selects one of the warehouse's drone actions

};

#endif // SYSMANAGER_H
