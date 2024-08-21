# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 10:23:42 2024

@author: Isabe
"""

class Farmaco:
    def __init__(self, nombre, peso, unidades):
        
        try:
            peso = int(peso)
        except ValueError:
            raise ValueError("El peso del farmaco debe ser un valor numerico")
            
        try:
            unidades = int(unidades)
        except ValueError:
            raise ValueError("Las unidades del farmaco deben ser un valor numerico")
            
        self.nombre = nombre
        self.peso = peso
        self.unidades = unidades
    
    def mostrarInfo(self):
        print(f'{self.nombre} - {self.peso} gramos, {self.unidades} unidades')
        

