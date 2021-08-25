/*********************************    ExceptionManager class declaration    ***********************************

                           Manages exceptions that may appear in the software

***************************************************************************************************************/


#ifndef EXCEPTIONMANAGER_H
#define EXCEPTIONMANAGER_H
#include <string>


class ExceptionManager
{
    public:
        void cinException();                        // manages an input exception
        bool cinExceptionB();                       // manages an input exception returning true or false
        bool checkString(std::string alphaString);  // checks that a string has alphabetic characters
};

#endif // EXCEPTIONMANAGER_H
