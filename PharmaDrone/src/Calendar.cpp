
/****************************    Calendar class implementation   ******************************/

#include "Calendar.h"
#include <iostream>
#include <string.h>
#include <sstream>


using namespace std;

/* Reads a new date from input */

void Calendar::readDate()
{
  bool aux;
  ExceptionManager eManager;


  cout << "     Enter day: ";
  do{
      aux = true;
      cin >> day;
      if(!cin){
          aux = false;
          eManager.cinException();
      }
  }while(!aux);

  cout << "     Enter month: ";
  do{
      aux = true;
      cin >> month;
      if(!cin){
          aux = false;
          eManager.cinException();
      }
  }while(!aux);

  cout << "     Enter year ";
  do{
      aux = true;
      cin >> year;
      if(!cin){
          aux = false;
          eManager.cinException();
      }
  }while(!aux);

}


/* Checks if the inserted date is valid and has a correct format. If the inserted date is not
   valid, returns false */

bool Calendar::isCorrect()
{
    if((day <=0 || day> 31) || (month <=0 || month > 12) || (year < 1601)||(year > 3000)){
        cout<<"\n     The inserted date is not valid"<<endl;
        return false;
    }

  switch (month){

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
       return (day <= 31);
       break;
    case 4:
    case 6:
    case 9:
    case 11:
       return (day <= 30);
       break;
    case 2:
      if (year%4 == 0 && year%100 != 0 ||year%400){   //checks if is a leap year
      return (day <= 29);
      }else{
      return (day <= 28);
      };
      break;
    default:
      cout<<"\n     The inserted date is not valid"<<endl;
      return false;
  }
}

/* Checks if the stored date is equal to another passed as parameter. If its not, returns false */

bool Calendar::isSame(int d)
{
    if(day+month+year == d){
      return true;
  }else{
      return false;
  }
}

/* Updates the object attributes */

void Calendar::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

/* Returns an integer with the concatenated values of the attributes */

int Calendar::getDate()
{
    return day+month+year;
}


/* Returns a string of the values of the attributes */

string Calendar::getDateString()
{
    ostringstream os;
    os << day << "/" << month << "/"<< year ;
    return os.str();

}

