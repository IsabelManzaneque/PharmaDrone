# -*- coding: utf-8 -*-
"""
Created on Mon Jul 15 17:03:41 2024

@author: Isabel
"""

from Almacen import Almacen
from Paciente import Paciente 


almacenes = {i: None for i in range(1,6)}
patientCounter = 0


def insertarDatos():
    """ Inserta los datos de 3 almacenes """
    
    almacenes[1] = Almacen(1, "Villanueva 14", "Zarzaquemada", "Madrid", "Entrada sur")
    almacenes[3] = Almacen(3, "3 Tintern Street", "Clapham", "London", "Almacen de Reino Unido")
    almacenes[5] = Almacen(5, "Chile 17", "Leganes", "Madrid", "Entrada norte") 
    
    
def altaAlmacen():
    """
    Da de alta un nuevo almacen. Si todos los almacenes estan ocupados, se debera
    borrar un almacen existente antes de anadir uno nuevo
    """       
              
    todosOcupados = True
    answer = ''
    
    for key, value in almacenes.items():
        if value is None:
            todosOcupados = False
            break
    
    if todosOcupados:
        answer = input("Todos los almacenes estan ocupados, desea borrar uno? (y/n): ")
        while answer not in ['y', 'n']:
            answer = input("Seleccione 'y' o 'n': ")   
    
    if not todosOcupados or answer == 'y':            
        print("\n---------- Alta nuevo almacen ----------")  
        
        while True:             
            while True:            
                try:
                    idAlmacen = int(input("\nIdentificador de almacen (1 - 5): "))
                    if idAlmacen not in range(1,6) or (not todosOcupados and almacenes[idAlmacen] is not None):  
                        if idAlmacen not in range(1, 6):
                            raise ValueError
                        if not todosOcupados and almacenes[idAlmacen] is not None:
                            print(f"El almacen {idAlmacen} ya está siendo utilizado. Elegir otro")
                    else:
                        break        
                except ValueError:
                    print("El identificador debe ser un número entre 1 y 5")                           
                
            dirAlmacen = input("Direccion de almacen: ")
            munAlmacen = input("Municipio almacen: ")
            provAlmacen = input("Provincia almacen: ")
            descAlmacen = input("Descripcion almacen: ")   
            
            answer = input("\nDatos correctos? (y/n): ")
            while answer not in ['y', 'n']:
                answer = input("Seleccione 'y' o 'n': ") 
            
            if answer == 'y':
                newAlmacen = Almacen(idAlmacen, dirAlmacen, munAlmacen, provAlmacen, descAlmacen)
                almacenes[idAlmacen] = newAlmacen  
                break
    

def displayAlmacenes():    
    """
    Muestra la informacion de todos los almacenes y de todos los pacientes y
    pedidos registrados en ellos, si los hubiera. 
    """   
    
    print("\n---------- Informacion almacenes ----------")  
    for almacen in almacenes.values():
        if almacen is not None:
            almacen.mostrarInfo()
            
            if len(almacen.getPacientes()) > 0:
                print(f"\nPacientes asociados a almacen {almacen.getId()}")                
                for paciente in almacen.getPacientes():
                    paciente.mostrarInfo()
                    
            if len(almacen.getPedidos()) > 0:
                print(f"\nPedidos asociados a almacen {almacen.getId()}")                
                for pedido in almacen.getPedidos():
                    pedido.mostrarInfo()
    
    
def altaPaciente():
    """ Da de alta un nuevo paciente en un almacen """
    
    global patientCounter
    
    while True:
        print("\n---------- Alta nuevo paciente ----------")      
        while True:   
            while True:
                try:
                    idAlmacen = int(input("\nIdentificador del almacen: "))
                    if idAlmacen not in range(1,6) or almacenes[idAlmacen] == None:
                        print("Ese almacen no existe, intentelo de nuevo")
                        continue
                    nombrePaciente = input("Nombre del paciente: ")
                    distanciaPaciente = int(input("Distancia (hasta 10000 metros a plena carga): "))
                    anguloPaciente = int(input("Angulo (entre 0 y 2000 milesimas de pi radianes): "))    
                    break
                except ValueError:
                    print("Error en la entrada, asegurese de estar introduciendo valores validos")
                    
            answer = input("\nDatos correctos? (y/n): ")
            while answer not in ['y', 'n']:
                answer = input("Seleccione 'y' o 'n': ") 
            
            if answer == 'y':            
                patientCounter += 1
                newPaciente = Paciente(patientCounter, nombrePaciente, distanciaPaciente, anguloPaciente)
                almacenes[idAlmacen].addPaciente(newPaciente)            
                break
            
        answer = input("Anadir otro paciente? (y/n): ")
        while answer not in ['y', 'n']:
            answer = input("Seleccione 'y' o 'n': ") 
        if answer == 'n':
            break
        
        
def displayPacientes():
    """ Muestra la informacion de de los pacientes dados de alta en un almacen"""
    
    
  
funDict = {
    
    'E' : insertarDatos,
    'M' : altaAlmacen,
    'I' : displayAlmacenes,
    'A' : altaPaciente,
    'U' : displayPacientes,
    
    }  

while True:
    print("\n#############################################")
    print("#                FarmaDron                  #")
    print("#############################################\n")
    print(" *   Insertar datos:                        E")      
    print(" *   Alta almacen:                          M")
    print(" *   Mostrar info almacenes:                I")
    print(" *   Alta paciente almacen:                 A")
    print(" *   Mostrar info pacientes:                U")
    print(" *   Nuevo pedido:                          N")
    print(" *   Lista diaria de pedidos:               L")
    print(" *   Programar rutas diarias del dron:      P")
    print(" *   Mostrar rutas diarias del dron:        R")
    print(" *   Salir                                  S")  
    try:
        userInput = input("\nSeleccionar una opcion valida: ")
        if userInput in ['M','I','A','U','N','L','P','R','E']:
            funDict[userInput]()  
        elif userInput == 'S':
            print("Saliendo de la aplicacion...")
            break  
        else:
            raise ValueError
    except ValueError:
        print("Error! Seleccionar opcion valida:")
        
    
        