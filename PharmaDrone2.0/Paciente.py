# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:26 2024

@author: Isabe
"""

class Paciente:
    def __init__(self, idPaciente, nombre, distancia, angulo):
        self.idPaciente = idPaciente
        self.nombre = nombre
        self.distancia = distancia
        self.angulo = angulo
        self.pedidos = {} # pedidos del paciente
        
    def addPedido(self, idPedido, pedido):
        self.pedidos[idPedido] = pedido            
        
    def getPedidos(self):
        return self.pedidos
            
    def mostrarInfo(self):
        print(f'Paciente {self.idPaciente}:\n - Nombre: {self.nombre}\n - Distancia: {self.distancia}\n - Angulo: {self.angulo}')

