# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:48 2024

@author: Isabel
"""


import datetime

class Pedido:
    
    counter = 1
    
    def __init__(self, idPaciente, numEnvios, dia, mes, anio):
        
        try:
            idPaciente = int(idPaciente)
        except ValueError:
            raise ValueError("El identificador de paciente debe ser un numero entero")
            
        try:
            numEnvios = int(numEnvios)
        except ValueError:
            raise ValueError("El numero de envios debe ser un numero entero")
            
        try:
            dia, mes, anio = int(dia), int(mes), int(anio)
        except ValueError:
            raise ValueError("El dia, mes y anio del pedido deben ser numeros enteros")
        
        fecha = datetime.date(anio,mes,dia)
        if fecha < datetime.datetime.today().date():
            raise ValueError("Error! Introduzca una fecha de envio futura.")
          
        
        self.idPedido = Pedido.counter
        self.idPaciente = idPaciente
        self.numEnvios = numEnvios
        self.diasEntreEnvio = 0
        self.fecha = fecha
        self.getDiasEntreEnvio()        
        self.farmacos = []      
        self.increaseCounter()
        
    @staticmethod
    def increaseCounter():
        Pedido.counter += 1
    
    @staticmethod
    def getCounter():
        return Pedido.counter 
        
    def getDiasEntreEnvio(self):
                  
        if self.numEnvios > 1:            
            while True:
                try:                    
                    diasEntreEnvio = int(input("Numero de dias entre envio (entre 1 y 6): "))  
                    if not(1 < diasEntreEnvio < 7):
                        continue
                    self.diasEntreEnvio = diasEntreEnvio 
                    break
                except ValueError:
                    pass       
    
    def addFarmaco(self, farmaco):
        self.farmacos.append(farmaco)   
        
    def getFarmacos(self):
        return self.farmacos
            
    def getFecha(self):
        return self.fecha
        
    def mostrarInfo(self):
        print(f'\nPedido {self.idPedido}:\n - Paciente: {self.idPaciente}\n - Num Envios: {self.numEnvios}\n - Fecha: {self.fecha}\nFarmacos:')                         
        for farmaco in self.farmacos:
            farmaco.mostrarInfo()          
