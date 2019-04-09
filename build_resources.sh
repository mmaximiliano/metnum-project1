# !/bin/bash

mkdir -p experimentacion/cuantitativo/matrices

./generateMatrixA 0.9 experimentacion/cuantitativo/outputs/test_15_segundos.txt experimentacion/cuantitativo/matrices/test_15_segundos_matriz.txt
./generateMatrixA 0.8 experimentacion/cuantitativo/outputs/test_30_segundos.txt experimentacion/cuantitativo/matrices/test_30_segundos_matriz.txt
./generateMatrixA 0.85 experimentacion/cuantitativo/outputs/test_aleatorio.txt experimentacion/cuantitativo/matrices/test_aleatorio_matriz.txt
./generateMatrixA 0.5 experimentacion/cuantitativo/outputs/test_completo.txt experimentacion/cuantitativo/matrices/test_completo_matriz.txt
./generateMatrixA 0.64 experimentacion/cuantitativo/outputs/test_sin_links.txt experimentacion/cuantitativo/matrices/test_sin_links_matriz.txt
./generateMatrixA 0.3 experimentacion/cuantitativo/outputs/test_trivial.txt experimentacion/cuantitativo/matrices/test_trivial_matriz.txt
./generateMatrixA 0.76 experimentacion/cuantitativo/outputs/test_aleatorio_desordenado.txt experimentacion/cuantitativo/matrices/test_aleatorio_desordenado_matriz.txt
