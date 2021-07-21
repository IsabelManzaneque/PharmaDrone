/********************************    Calendar class declaration     ***********************************

                           Reads a new date and check if the format is valid

*******************************************************************************************************/

#ifndef CALENDAR_H
#define CALENDAR_H
#include "ExceptionManager.h"
#include <string.h>


class Calendar
{
 private:

    int day, month, year;

 public:

    void readDate();                    //read a new date from input
    bool isCorrect();                   //checks that a new date is of a valid format
    bool isSame(int d);                 //checks if the stored date is equal to another

    void setDate(int d, int m, int y);  //getters and setters of the attributes
    int getDate();
    std::string getDateString();

};

#endif // CALENDAR_H
