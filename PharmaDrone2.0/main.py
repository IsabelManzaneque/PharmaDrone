# -*- coding: utf-8 -*-
"""
Created on Mon Jul 15 17:03:41 2024

@author: Isabel
"""

from Almacen import Almacen

almacenes = {i: None for i in range(1,11)}

def altaAlmacen():
    
    print("\nAlta nuevo almacen: ")
    
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
        
        idAlmacen = -1
        while idAlmacen not in range(1,11):
            idAlmacen = int(input("Identificador de almacen (1 - 10): "))
        
        if not todosOcupados:            
            while almacenes[idAlmacen] is not None:
                idAlmacen = int(input("Ese identificador esta ocupado, elegir otro: "))
                
        dirAlmacen = input("Direccion de almacen: ")
        munAlmacen = input("Municipio almacen: ")
        provAlmacen = input("Provincia almacen: ")
        descAlmacen = input("Descripcion almacen: ")
        
        newAlmacen = Almacen(idAlmacen, dirAlmacen, munAlmacen, provAlmacen, descAlmacen)
        almacenes[idAlmacen] = newAlmacen   
    

def displayAlmacenes():
    
    for almacen in almacenes.values():
        if almacen is not None:
            almacen.mostrarInfo()
    
    
def altaPaciente():
    print("Alta pacientes")

def displayPacientes():
    print("Display pacientes")
  
funDict = {
    
    'M' : altaAlmacen,
    'I' : displayAlmacenes,
    'A' : altaPaciente,
    'U' : displayPacientes,
    
    }  

while True:
    print("\n#############################################")
    print("#                FarmaDron                  #")
    print("#############################################\n")          
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
        if userInput in ['M','I','A','U','N','L','P','R']:
            funDict[userInput]()  
        elif userInput == 'S':
            print("Saliendo de la aplicacion...")
            break  
        else:
            raise ValueError
    except ValueError:
        print("Error! Seleccionar opcion valida:")
        
    
        