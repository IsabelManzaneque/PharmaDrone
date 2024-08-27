# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 16:13:57 2024

@author: Isabe
"""

import unittest
import coverage
import datetime
from Almacen import Almacen
from Paciente import Paciente
from Pedido import Pedido
from Dron import Dron
from unittest.mock import patch

class TestAlmacen(unittest.TestCase):
    
    @classmethod
    def setUpClass(cls):
        # util para hacer algo una sola vez antes de correr todos los test
        # a diferencia de setUp que se ejecuta antes de cada test. Ej: rellenar
        # una BBDD para ser utilizada en los test
        pass
        
    @classmethod
    def tearDownClass(cls):
        # util para hacer algo una sola vez despues de correr todos los test
        # a diferencia de tearDown que se ejecuta despues de cada test. Ej: 
        # eliminar la BBDD tras ser utilizada en los test
        pass
    
    def setUp(self):
        self.newAlmacen = Almacen(1, "newDir", "newMun", "newPro", "newDesc")    
        
    def test_init_success(self):
        testAmlacen = Almacen(2, "testDir", "testMun", "testPro", "testDesc")
        self.assertEquals(testAmlacen.idAlmacen, 2)
        self.assertEquals(testAmlacen.direccion, "testDir")
        self.assertEquals(testAmlacen.municipio, "testMun")
        self.assertEquals(testAmlacen.provincia, "testPro")
        self.assertEquals(testAmlacen.descripcion, "testDesc")
        self.assertIsInstance(testAmlacen.pacientes, dict)
        self.assertIsInstance(testAmlacen.pedidos, dict)
        self.assertIsInstance(testAmlacen.dron, Dron)
        
    def test_init_failure_noNumId(self):        
        with self.assertRaises(ValueError):
            testAlmacen = Almacen("testId", "testDir", "testMun", "testPro", "testDesc")
    
    def test_init_failure_idNotIn1to5(self):
        with self.assertRaises(ValueError):
            testAlmacen = Almacen(0, "testDir", "testMun", "testPro", "testDesc")           
   
    def test_addPaciente(self):
        newPaciente = Paciente("name", 2, 2)        
        self.newAlmacen.addPaciente(1, newPaciente)
        pacientes = self.newAlmacen.getPacientes()        
        self.assertEqual(pacientes[1], newPaciente)
        
    def test_addPedido(self):
        newPedidoId = 1
        newPedido = Pedido(1,1,1,3,2025)      
        self.newAlmacen.addPedido(newPedidoId, newPedido)
        pedidos = self.newAlmacen.getPedidos()
        self.assertEqual(pedidos[newPedidoId], newPedido)
        
    def test_getId(self):        
        self.assertIsInstance(self.newAlmacen.getId(), int)
        
    def test_getPacientes(self):        
        self.assertIsInstance(self.newAlmacen.getPacientes(), dict)
        
    def test_getPedidos(self):        
        self.assertIsInstance(self.newAlmacen.getPedidos(), dict)
        
    def test_getDron(self):        
        self.assertIsInstance(self.newAlmacen.getDron(), Dron)
        
    @patch('builtins.print')
    def test_mostrarInfo(self, mock_print):
        self.newAlmacen.mostrarInfo() 
        mock_print.assert_called_with('\nAlmacen 1:\n - Calle: newDir\n - Municipio: newMun\n - Provincia: newPro\n - Descripccion: newDesc')
        
        
if __name__ == '__main__':
    
    # Iniciar la cobertura
    cov = coverage.Coverage()
    cov.start()
    
    unittest.main(exit=False)
    
    # Detener, guardar la cobertura y mostrar reporte
    cov.stop()
    cov.save()
    cov.report()


        
        