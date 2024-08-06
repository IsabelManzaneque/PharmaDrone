# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 10:23:42 2024

@author: Isabe
"""

class Farmaco:
    def __init__(self, nombre, peso, unidades):
        self.nombre = nombre
        self.peso = peso
        self.unidades = unidades
    
    def mostrarInfo(self):
        print(f'{self.nombre} - {self.peso} gramos, {self.unidades} unidades')
        

