# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 09:31:42 2024

@author: Isabe
"""

class Almacen:
    def __init__(self, idAlmacen, direccion, municipio, provincia, descripcion):
        self.idAlmacen = idAlmacen
        self.direccion = direccion
        self.municipio = municipio
        self.provincia = provincia
        self.descripcion = descripcion 
        self.pacientes = []
        self.pedidos = [] # pedidos del almacen
        
    def addPaciente(self, paciente):
        self.pacientes.append(paciente)
    
    def addPedido(self, pedido):
        self.pedido.append(pedido)
        
    def getId(self):
        return self.idAlmacen
    
    def getPacientes(self):
        return self.pacientes
    
    def getPedidos(self):
        return self.pedidos
    
    
    def mostrarInfo(self):
        print(f'\nAlmacen {self.idAlmacen}:\n - Calle: {self.direccion}\n - Municipio: {self.municipio}\n - Provincia: {self.provincia}\n - Descripccion: {self.descripcion}')
        




