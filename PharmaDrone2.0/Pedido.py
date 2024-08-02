# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:48 2024

@author: Isabel
"""

class Pedido:
    def __init__(self, idPedido, idPaciente, numEnvios, day, month, year):
        self.idPedido = idPedido
        self.idPaciente = idPaciente
        self.numEnvios = numEnvios
        self.diasEntreEnvio = 0
        self.day = day
        self.month = month
        self.year = year
        self.getDiasEntreEnvio()        
        
    def getDiasEntreEnvio(self):
                  
        if self.numEnvios > 1:
            diasEntreEnvio = input("Numero de dias entre envio (entre 1 y 6): ")            
            while diasEntreEnvio < 1 or diasEntreEnvio > 6:
                diasEntreEnvio = input("Introduzca un numero entre 1 y 6: ")
            self.diasEntreEnvio = diasEntreEnvio    
            
    
    def mostrarInfo(self):
        print(f'Pedido {self.idPedido}:\n - Paciente: {self.idPaciente}\n - Num Envios: {self.numEnvios}\n - Fecha: {self.day}/{self.month}/{self.year}')
        
        
