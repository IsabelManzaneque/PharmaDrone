/**********************************   Drone class implementation    *************************************/


#include "Drone.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <GLFW/glfw3.h>
#include <thread>


using namespace std;


/* Class constructor */

Drone::Drone()
    : orderCounter{0}, patientCounter{0}{}


/* Calls the setPatientInfo() function from Patient Class on the "patientCounter" position of the
   patientArray. The user can continue adding patients until the counter reaches 20. */

void Drone::addPatient()
{

   char aux;

    do{

           patientArray[patientCounter].newPatient();
           patientArray[patientCounter].setID(patientCounter + 1);
           patientCounter ++;

           if (patientCounter == 20){
             cout<<"\n       The maximum of registered patients has been reached in this warehouse\n\n"<<endl;
             continue;
           }

           cout << " Register another patient in this warehouse (Y/N)?: ", cin >> aux;


     }while((aux == 'Y')&&(patientCounter<20));
}

/* Prints out the patients stored in the patientArray of a given warehouse */

void Drone::showPatients()
{
    if(patientCounter != 0){
        cout<<"\n     Registered Patients:\n\n";
        cout<<"     ID      Name                Distance      Angle\n"<<endl;
        for (int i=0; i < patientCounter; i++){
            printf ("     %-7d %-19s %-13d %d\n", patientArray[i].getID(), patientArray[i].getName().c_str(),
                    patientArray[i].getLocation().getDistance(), patientArray[i].getLocation().getAngle());
         }
   }else{
      printf("\n     There are no patients registered in this warehouse\n\n");
    }

}


/* Calls the setOrderInfo() function from Order Class on the orderCounter position of the
   orderArray. The user can continue adding orders until the counter reaches 100. */

void Drone::addOrder()
{

    char aux;

    do{

        orderArray[orderCounter].newOrder(patientArray);
        orderCounter ++;

        if (orderCounter == 100){
          cout<<"\n       The maximum of scheduled deliveries have been registered in the drone\n"<<endl;
          continue;
        }

        cout << " Place another order (Y/N)?: ", cin >> aux;

    }while ((aux == 'Y')&&(orderCounter<100));
}


/* Prints out the orders stored in the ordersArray of a given warehouse */

void Drone::showOrders()
{

    Calendar date;
    int dailyOrders = 0;
    bool match = false;

    date.readDate();
    if(date.isCorrect()){
        cout<<"\n\n     Scheduled Orders:\n"<<endl;
        for (int i=0; i < orderCounter; i++){

             if(date.isSame(orderArray[i].getOrderDate().getDate())){

                  match = true;
                  dailyOrders ++;
                  printf("\n ------------------- Order %d -------------------\n", dailyOrders);
                  printf(" Patient's location:  Distance %dm | Angle %dr\n\n", patientArray[orderArray[i].getPatientID()-1].getLocation().getDistance(),
                         patientArray[orderArray[i].getPatientID()-1].getLocation().getAngle());

                  for (int j=0; j < orderArray[i].getMedicineCounter(); j++){
                       printf("  %3d Units   %-15s  Weight:  %d grams\n", orderArray[i].getMedicine(j).getUnits(),
                              orderArray[i].getMedicine(j).getName().c_str(), orderArray[i].getMedicine(j).getTotalWeight());
                   }
                  printf("                   Total order weight:  %d grams\n\n\n", orderArray[i].getOrderWeight());
              }
         }
         if (!match){
             cout<<"\n     No scheduled deliveries for the inserted date\n"<<endl;
         }
    }
}


/* Calculates and prints put the routes for a given day and stores them in the routeVector */

void Drone::planRoute()
{

    vector<Patient> unattendedP;
    Calendar date;
    bool aux = false;
    int routeCounter = 0;
    routeVector.clear();


    date.readDate();
    if(date.isCorrect()){

         //A route is calculated and the patients that could not be seen are stored in unattendedP
         //the process repeats whilst unattendedP contains any patients

         Route route(date, orderArray, patientArray);
         unattendedP = route.newRoute();
         routeVector.push_back(route);

         if(!unattendedP.empty()){

              do{
                    array<Patient, 20> arr;

                    for(int i = 0; i < unattendedP.size(); i++){
                        arr[i] = unattendedP[i];
                    }

                    //newRoute() is called again, now with the patients that were not attended on the last route
                    Route route(date, orderArray, arr);
                    unattendedP = route.newRoute();
                    routeVector.push_back(route);

                    for(int i = 0; i < arr.size(); i++){
                        arr[i] = arr[arr.size()-1];
                     }

              }while(!unattendedP.empty());
         }



         //prints out the calculated routes

         for (auto route : routeVector){
              if(!route.getPathVector().empty()){
                  aux = true;
                  routeCounter ++;
                  printf("\n\n ------------------------------ Route %d -----------------------------\n\n", routeCounter);

                  for (int i=0; i < route.getPathVector().size(); i++){
                      if (i == 0){
                          printf(" Warehouse to client %d    -- Distance: %-5d Angle: %-4d  Weight: %-4d\n", route.getPath(i).pB.getID(),
                                 route.getPath(i).distanceAtoB, route.getPath(i).angleAtoB, route.getPath(i).descWeight);
                      }else if (i == route.getPathVector().size()-1) {
                          printf(" Client %d to warehouse    -- Distance: %-5d Angle: %-4d  Weight: %-4d\n", route.getPath(i).pA.getID(),
                                 route.getPath(i).distanceAtoB, route.getPath(i).angleAtoB, route.getPath(i).descWeight);
                      }else{
                          printf(" Client %d to client %d     -- Distance: %-5d Angle: %-4d  Weight: %-4d\n", route.getPath(i).pA.getID(),
                                 route.getPath(i).pB.getID(), route.getPath(i).distanceAtoB, route.getPath(i).angleAtoB,
                                 route.getPath(i).descWeight);
                      }

                  }
                  printf(" Total distance:  %d m\n", route.getTotalDistance());
               }
         }
         if (!aux){
             printf(" There are no programmed routes for the inserted date\n");
         }
    }
}



/* Shows a graphic representation of the drone's routes using openGL and GLFW. In order to show this,
   the routes must be previously calculated by the planRoute() methods */

int Drone::showRoutes()
{

     Calendar date;
     bool match = false;
     GLFWwindow* window;


     if (!glfwInit()){
         return -1;
     }
     date.readDate();
     if(date.isCorrect()){

         window = glfwCreateWindow(1000, 1000, "Drone's programmed routes", NULL, NULL);
         if (!window){
                glfwTerminate();
                return -1;
         }
         glfwMakeContextCurrent(window);

         while (!glfwWindowShouldClose(window)){
              //setup view
              glClear(GL_COLOR_BUFFER_BIT);

              //drawing axis
              glColor3f(1.0,1.0,1.0);
              glBegin(GL_LINES);
                glVertex2i(-1, 0);
                glVertex2i(1, 0);
                glVertex2i(0, -1);
                glVertex2i(0, 1);
              glEnd();

              //drawing warehouse
              glBegin(GL_POLYGON);
                glVertex2f(0, 0.075);
                glVertex2f(-0.040, 0.030);
                glVertex2f(-0.040, -0.030);
                glVertex2f(0.040, -0.030);
                glVertex2f(0.040, 0.030);
              glEnd();

              //drawing drone routes
              glColor3f(1.0,0.0,0.0);
              for (auto route : routeVector){
                  if(date.isSame(route.getRouteDate().getDate())){
                      match = true;

                       for (int i=0; i < route.getPathVector().size(); i++){
                           glBegin(GL_LINES);
                           glVertex2f((route.getPath(i).pA.getLocation().cX/10000.0), (route.getPath(i).pA.getLocation().cY/10000.0));
                           glVertex2f((route.getPath(i).pB.getLocation().cX/10000.0), (route.getPath(i).pB.getLocation().cY/10000.0));
                           glEnd();
                        }
                    }
               }
               if (!match){
                  printf("    There are no programmed routes for the entered date\n\n"); // Si no hay rutas se notifica y se muestra el almacen solo
               }

               //swap buffer and check for events
               glfwSwapBuffers(window);
               glfwPollEvents();

          }
     }

     glfwTerminate();
     return 0;
}


/* returns a reference to a position of the patientArray */

Patient& Drone::getPatient(int position)
{
    return patientArray[position];
}


/* returns a reference to a position of the orderArray */

Order& Drone::getOrder(int position)
{
    return orderArray[position];
}


/* returns the number of orders stored in the orderArray */

int Drone::getOrderCounter()
{
    return orderCounter;
}

/* updates the number of orders stored in the orderArray */

void Drone::setOrderCounter(int n)
{
   orderCounter = n;
}

/* returns the number of patients stored in the patientArray */

int Drone::getPatientCounter()
{
    return patientCounter;
}

/* updates the number of patients stored in the patientArray */

void Drone::setPatientCounter(int n)
{
   patientCounter = n;
}


