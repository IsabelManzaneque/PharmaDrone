# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:26 2024

@author: Isabe
"""

class Paciente:
    
    counter = 1
    
    def __init__(self, nombre, distancia, angulo):
        
        try:
            distancia = int(distancia)
            if not(0<distancia<=10000):
                raise ValueError
        except ValueError:
            raise ValueError("La distancia debe ser un numero entre 0 y 10000")       
        
        try:
            angulo = int(angulo)
            if not(0<angulo<=2000):
                raise ValueError
        except ValueError:
            raise ValueError("El angulo debe ser un numero entre 0 y 2000")
            
        self.idPaciente = Paciente.counter 
        self.nombre = nombre
        self.distancia = distancia
        self.angulo = angulo
        self.pedidos = {} # pedidos del paciente
        self.increaseCounter()
        
    @staticmethod
    def increaseCounter():
        Paciente.counter += 1
    
    @staticmethod
    def getCounter():
        return Paciente.counter     
    
    def addPedido(self, idPedido, pedido):
        self.pedidos[idPedido] = pedido            
        
    def getPedidos(self):
        return self.pedidos
            
    def mostrarInfo(self):
        print(f'Paciente {self.idPaciente}:\n - Nombre: {self.nombre}\n - Distancia: {self.distancia}\n - Angulo: {self.angulo}')

