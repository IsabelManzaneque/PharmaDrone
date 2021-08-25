/************************************    Medicine class declaration    ***************************************

                                  Stores the details of a new medicine

*************************************************************************************************************/

#ifndef MEDICINE_H
#define MEDICINE_H
#include "ExceptionManager.h"
#include <string>

class Medicine
{
   private:

       std::string name;
       int weight;
       int units;

   public:

      Medicine();                             //Constructor
      void newMedicine();                     //reads a new medicine from input
      getTotalWeight();                       //returns total weight of a medication

      std::string getName();                  //getters and setters
      int getWeight();
      int getUnits();
      void setMedicineInfo(std::string n, int w, int u);

};

#endif // MEDICINE_H
