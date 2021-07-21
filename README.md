# PharmaDrone

Simulation Software that manages medicine delivery using drones located in 10 warehouses.

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info

The software has the following functionalities:

#### Load and show data base:
Loads and shows a set of fixed patients and orders into the system. If this operation is not entered, the system will be empty.

#### Set up a new warehouse:
Allows the user to set up a new warehouse in the system with a maximum of 10 warehouses. If the maximum of warehouses has been reached, the user will be able to overwrite one.

#### Set up a new client in a warehouse:
Allows to register up to 20 new patients into an existing warehouse.The patient’s location is calculated using the distance (up to 10000m) and angle (up to 2000 pi/1000 rad). 

#### Show registered patients:
Shows a list of all the registered patients and their locations of a selected warehouse.

#### New Order:
Allows to place a new order for an existing patient in a warehouse with a maximum of 100 scheduled orders. Each order can contain up to 5 different medicines and weigh a maximum of 3 kilos.

#### Daily list of orders:
Shows a list of the scheduled deliveries of a warehouse for a given date

#### Program daily drone routes:
Calculates the most efficient route for the drone to follow for a given date, the locations of clients to visit and the weight of their orders. Then, it prints out the programmed information. 
Based on the carried weight the drone can travel up to 20km when its fully loaded and 25km when its empty, having the degree of autonomy a linear increase

#### Show drone routes:
2D graphic representation of the programmed daily routes using the GLFW openGL library. The routes have to be previously programmed with the “Program daily routes” function. 


## Technologies
Project is created with:
* Code::Blocks IDE version: 20.03
* GLFW version 3.3.4

	
## Setup
To run this project in Code::Blocks IDE:

```
Download and install the GLFW openGL library
Download PharmaDrone.zip
Run Code::Blocks IDE
File > open > Browse to find the location of the Project
select FarmaDron.cbp
Compiler settings > Linker settings > add the correct GLFW libraries

```
