/*******************************   ExceptionManager class implementation    **********************************/



#include "exceptionManager.h"
#include <iostream>
#include <stdexcept>
#include <limits>


using namespace std;

/* Manages an exception in which an unexpected input is entered and cin fails, not reading any more input
   into the variables */

void ExceptionManager::cinException()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"     Please enter valid input: ";
}

/* Manages an exception in which an unexpected input is entered and cin fails, not reading any more input
   into the variables. If cin fails, returns false */

bool ExceptionManager::cinExceptionB()
{
    if(!cin){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"     Please enter valid input: ";
        return false;
    }else{
        return true;
    }
}

/* Returns true if the string passed as parameter has alphabetic characters. If the string
   is numeric only, returns false */

bool ExceptionManager::checkString(string alphaString){


    for(string::size_type i = 0; i < alphaString.size(); ++i) {
        if(isalpha(alphaString[i])){
            return true;
        }else{
            cout<<"     Please insert alphabetical characters: ";
            return false;
            continue;
        }
    }
}

