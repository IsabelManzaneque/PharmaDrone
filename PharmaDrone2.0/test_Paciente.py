# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 15:43:37 2024

@author: Isabe
"""

import unittest
import coverage
from Paciente import Paciente
from Pedido import Pedido
from unittest.mock import patch

class TestPaciente(unittest.TestCase):
    
    def setUp(self):
        self.newPaciente = Paciente("newPaciente", 1000, 1000)
    
    def test_init_success(self):
        patientCounter = Paciente.getCounter()
        testPaciente = Paciente("testPaciente", 2000, 500)        
        self.assertEqual(testPaciente.idPaciente, patientCounter)        
        self.assertEqual(testPaciente.nombre, "testPaciente")
        self.assertEqual(testPaciente.distancia, 2000)
        self.assertEqual(testPaciente.angulo, 500)
        self.assertEqual(Paciente.counter, patientCounter+1)
        
    def test_init_failure(self):          
        failParams = [
            ("testPaciente", "testDistancia", 500),
            ("testPaciente", 0, 500),
            ("testPaciente", 10001, 500),
            ("testPaciente", 1000, "testAngulo"),
            ("testPaciente", 1000, 0),
            ("testPaciente", 1000, 2001),
        ]
        
        for params in failParams:
            with self.assertRaises(ValueError):
                Paciente(*params)           
 
    def test_getCounter(self):
        self.assertIsInstance(Paciente.getCounter(), int)
    
    def test_addPedido(self):
        newPedido = Pedido(1,1,1,3,2025)   
        self.newPaciente.addPedido(1, newPedido)
        pedidos = self.newPaciente.getPedidos()
        self.assertEqual(pedidos[1], newPedido)
    
    def test_getPedidos(self):
        self.assertIsInstance(self.newPaciente.getPedidos(), dict)
    
    @patch('builtins.print')
    def test_mostrarInfo(self, mock_print):
        self.newPaciente.mostrarInfo()
        mock_print.assert_called_with('Paciente 7:\n - Nombre: newPaciente\n - Distancia: 1000\n - Angulo: 1000')
    

if __name__ == '__main__':
    
    # Iniciar la cobertura
    cov = coverage.Coverage()
    cov.start()
    
    unittest.main(exit=False)
    
    # Detener, guardar la cobertura y mostrar reporte
    cov.stop()
    cov.save()
    cov.report()