# -*- coding: utf-8 -*-
"""
Created on Mon Jul 15 17:03:41 2024

@author: Isabel
"""

from Almacen import Almacen
from Paciente import Paciente 
from Pedido import Pedido
from Farmaco import Farmaco
import datetime

almacenes = {i: None for i in range(1,6)}

    
def insertarDatos():
    """ Inserta los datos de 3 almacenes """
        
    almacenes[1] = Almacen(1, "Villanueva 14", "Zarzaquemada", "Madrid", "Entrada sur")
    almacenes[3] = Almacen(3, "3 Tintern Street", "Clapham", "London", "Almacen de Reino Unido")
    almacenes[5] = Almacen(5, "Chile 17", "Leganes", "Madrid", "Entrada norte")     
    
    almacenes[1].addPaciente(Paciente.getCounter(), Paciente("Isabel", 3000, 45))
    Paciente.increaseCounter()
    
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
                idAlmacen = input("\nIdentificador del almacen: ")                
                if (not todosOcupados and almacenes[int(idAlmacen)] is None) or todosOcupados:   
                    break                    
                if not todosOcupados and almacenes[int(idAlmacen)] is not None:
                    print(f"El almacen {idAlmacen} ya está siendo utilizado. Elegir otro")
                     
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
            
            if almacen.getPacientes():
                print(f"\nPacientes asociados a almacen {almacen.getId()}:")                
                for paciente in almacen.getPacientes().values():
                    paciente.mostrarInfo()
                    
            if almacen.getPedidos():
                print(f"\nPedidos asociados a almacen {almacen.getId()}:")                
                for pedido in almacen.getPedidos().values():
                    pedido.mostrarInfo()
                        
    
def altaPaciente():
    """ Da de alta un nuevo paciente en un almacen """
    
    while True:
        print("\n---------- Alta nuevo paciente ----------")      
        while True:  
                       
            try:
                idAlmacen = int(input("\nIdentificador de almacen (1 - 5): "))
                if not (0<idAlmacen<6):
                    raise ValueError            
            except ValueError:
                print("El identificador de almacen debe ser un numero entre 1 y 5") 
                continue
            
            nombrePaciente = input("Nombre del paciente: ")
            distanciaPaciente = input("Distancia (hasta 10000 metros a plena carga): ")
            anguloPaciente = input("Angulo (entre 0 y 2000 milesimas de pi radianes): ")                                 
            answer = input("\nDatos correctos? (y/n): ")
            
            while answer not in ['y', 'n']:
                answer = input("Seleccione 'y' o 'n': ") 
            
            if answer == 'y':  
                try:
                    newPaciente = Paciente(nombrePaciente, distanciaPaciente, anguloPaciente)
                    almacenes[idAlmacen].addPaciente(Paciente.getCounter(), newPaciente) 
                    Paciente.increaseCounter()
                    break
                except ValueError as e:
                    print(e)                
            
        answer = input("Anadir otro paciente? (y/n): ")
        while answer not in ['y', 'n']:
            answer = input("Seleccione 'y' o 'n': ") 
        if answer == 'n':
            break
        
        
def displayPacientes():
    """ Muestra la informacion de de los pacientes dados de alta en un almacen"""
    
    print("\n---------- Informacion pacientes ----------")  
    while True:
        try:
            idAlmacen = Almacen.checkIdAlmacen(input("\nIdentificador de almacen (1 - 5): "))            
            break
        except ValueError as e:
            print(e)                   
       
    for paciente in almacenes[idAlmacen].getPacientes().values():
        paciente.mostrarInfo()
            

def nuevoPedido():
    """ Procesa un nuevo pedido para un cliente en un almacen """
        
    print("\n---------- Nuevo pedido ----------")  
    while True:
        try:
            idAlmacen = Almacen.checkIdAlmacen(input("\nIdentificador de almacen (1 - 5): "))            
            break
        except ValueError as e:
            print(e)    
        
    for paciente in almacenes[idAlmacen].getPacientes().values():        
        paciente.mostrarInfo()    
       
    while True:        
        idPaciente = input("Seleccione un paciente del almacen: ")        
        numEnvios = input("Seleccione numero de envios: ")
        diaEnvio = input("Seleccione el dia del envio: ")
        mesEnvio = input("Seleccione el mes del envio: ")
        anioEnvio = input("Seleccione el anio del envio: ")          
               
        try:
            if int(idPaciente) in almacenes[idAlmacen].getPacientes().keys():
                newPedido = Pedido(idPaciente,numEnvios,diaEnvio,mesEnvio,anioEnvio)
                Pedido.increaseCounter()
                break
            else:
                print("No existe un paciente con el identificador seleccionado")
        except ValueError as e:
            print(e)
    
    while True:        
        nombreFarmaco = input ("\nNombre del farmaco: ")    
        pesoFarmaco = input("Peso del farmaco: ")
        unidadesFarmaco = input("Unidades del farmaco: ")

        try:
            newPedido.addFarmaco(Farmaco(nombreFarmaco, pesoFarmaco, unidadesFarmaco))  
        except ValueError as e:
            print (e)
            continue          
             
        answer = input("Anadir otro farmaco al pedido? (y/n): ")        
        if answer not in ['y', 'n']:
            answer = input("Seleccionar 'y' o 'n': ")
        if answer == 'n':
            break 
    
    almacenes[idAlmacen].addPedido(Pedido.getCounter(), newPedido)
    almacenes[idAlmacen].getPacientes()[idPaciente].addPedido(Pedido.getCounter(), newPedido)    
    

def listaDiariaPedidos():
    """ Dado un almacen y una fecha, muestra los pedidos programados """
    
    print("\n---------- Lista diaria de pedidos ----------")     
    while True: 
        
        try: 
            idAlmacen = int(input("\nIdentificador de almacen (1 - 5): "))
            dia = int(input("Seleccione el dia: "))
            mes = int(input("Seleccione el mes: "))
            anio = int(input("Seleccione el anio: "))
            fecha = datetime.date(anio,mes,dia)
            break
        except ValueError:
            print("Error en la entrada")        
                        
    
    if not almacenes[idAlmacen].getPedidos():
        print("\nNo se han encontrado pedidos para el almacen y fecha indicados")
    else:
        for pedido in almacenes[idAlmacen].getPedidos().values():
            if pedido.getFecha() == fecha:
                pedido.mostrarInfo()        


def programarRutas():
    
    print("\n---------- Programar rutas diarias del dron ----------")            
    while True:        
        idAlmacen = int(input("\nIdentificador de almacen (1 - 5): "))
        dia = int(input("Seleccione el dia: "))
        mes = int(input("Seleccione el mes: "))
        anio = int(input("Seleccione el anio: "))             
        fecha = datetime.date(anio, mes, dia)
        
        if almacenes[int(idAlmacen)] == None:
            print("Ese almacen no existe, intentelo de nuevo")
            continue        
        break                   
    
    listaPedidos = []
    if not almacenes[idAlmacen].getPedidos():
        print("\nNo se han encontrado pedidos para el almacen y fecha indicados")
    else:
        for pedido in almacenes[idAlmacen].getPedidos().values():
            if pedido.getFecha() == fecha:
                listaPedidos.append(pedido)
                
    ## Ahora pasar listaPedidos al dron para que genere las rutas
    print("pasar lista de pedidos a dron")
    
    
    
funDict = {
    
    'E' : insertarDatos,
    'M' : altaAlmacen,
    'I' : displayAlmacenes,
    'A' : altaPaciente,
    'U' : displayPacientes,
    'N' : nuevoPedido,
    'L' : listaDiariaPedidos,
    'P' : programarRutas,
    
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
        
    
        