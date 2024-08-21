# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 16:09:23 2024

@author: Isabe
"""

import unittest
import coverage
import main
from main import almacenes

class TestMain(unittest.TestCase):    
    
    def test_isValidInt(self):             
        
        # si no recibe un int, atrapa la excepcion y devuelve false
        self.assertFalse(main.isValidInt(idAlmacen=1, testPAram1=1000, testParam2="notAnInt" ))        
        # si recibe solo ints y idAlmacen no esta en almacenes.keys() devuelve false
        self.assertFalse(main.isValidInt(idAlmacen=15, testPAram1=1000, testParam2=50 ))            
        # si recibe solo ints y idAlmacen esta en almacenes.keys() devuelve true
        self.assertTrue(main.isValidInt(idAlmacen=1, testPAram1=1000, testParam2=50 ))                

    def test_insertarDatos(self):
        
        main.insertarDatos()
        self.assertFalse(almacenes[1] is None)
        self.assertFalse(almacenes[3] is None)
        self.assertFalse(almacenes[5] is None)
        self.assertFalse(almacenes[1].getPacientes()[1] is None)
        
    def test_altaAlmacen(self):
        
        # rama "todosOcupados"
        
        # rama not "todosOcupados"
        

if __name__ == '__main__':
    
    # Iniciar la cobertura
    cov = coverage.Coverage()
    cov.start()
    
    unittest.main(exit=False)
    
    # Detener, guardar la cobertura y mostrar reporte
    cov.stop()
    cov.save()
    cov.report()