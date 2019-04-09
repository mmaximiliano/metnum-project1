# !/bin/bash

echo "Test trivial"
./tp1 experimentacion/cuantitativo/outputs/test_trivial.txt 0.3

echo "Test sin links"
./tp1 experimentacion/cuantitativo/outputs/test_sin_links.txt 0.64

echo "Test 15s"
./tp1 experimentacion/cuantitativo/outputs/test_15_segundos.txt 0.9

echo "Test 30s"
./tp1 experimentacion/cuantitativo/outputs/test_30_segundos.txt 0.8

echo "Test aleatorio desordenado"
./tp1 experimentacion/cuantitativo/outputs/test_aleatorio_desordenado.txt 0.76

echo "Test aleatorio"
./tp1 experimentacion/cuantitativo/outputs/test_aleatorio.txt 0.85

echo "Test completo"
./tp1 experimentacion/cuantitativo/outputs/test_completo.txt 0.5
