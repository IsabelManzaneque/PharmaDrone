# -*- coding: utf-8 -*-
"""
Created on Tue Aug  6 16:49:14 2024

@author: Isabe
"""

class Dron:
    def __init__(self):
        self.cargaMaxima = 3
        self.cargaActual = 0
        
    
    def programarRutas(self, listaPedidos):
        pass
    
    def getAutonomia(self):
        # 20km sin repostar a plena carga, 25km en vacio
        if self.cargaActual == 0:
            return 25 
        else:
            pass
        
    def getCargaActual(self):
        return self.cargaActual