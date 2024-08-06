# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:48 2024

@author: Isabel
"""

from Farmaco import Farmaco

class Pedido:
    def __init__(self, idPedido, idPaciente, numEnvios, fecha):
        self.idPedido = idPedido
        self.idPaciente = idPaciente
        self.numEnvios = numEnvios
        self.diasEntreEnvio = 0
        self.fecha = fecha
        self.getDiasEntreEnvio()        
        self.farmacos = []        
        
    def getDiasEntreEnvio(self):
                  
        if self.numEnvios > 1:
            diasEntreEnvio = input("Numero de dias entre envio (entre 1 y 6): ")            
            while diasEntreEnvio < 1 or diasEntreEnvio > 6:
                diasEntreEnvio = input("Introduzca un numero entre 1 y 6: ")
            self.diasEntreEnvio = diasEntreEnvio         
    
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
