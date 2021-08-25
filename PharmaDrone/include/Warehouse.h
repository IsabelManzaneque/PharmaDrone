/**********************************    Warehouse class declaration    *******************************************

              Manages the information about a new Warehouse and stores it in the system

*****************************************************************************************************************/

#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Drone.h"
#include <string.h>
#include "ExceptionManager.h"


class Warehouse
{
    private:

        int warehouseID;
        std::string address;
        std::string postcode;
        std::string borough;
        Drone drone;

    public:

        Warehouse();                     //Constructor
        void newWarehouse();             //reads the details of a new warehouse from input
        Drone& getDrone();               //returns a reference to the drone variable
        int getWarehouseID();            //getters and setters of the attributes
        void setWarehouseID(int id);
        std::string getWarehouseInfo();
        void setWarehouseInfo(std::string a, std::string p, std::string b);

};

#endif // WAREHOUSE_H
