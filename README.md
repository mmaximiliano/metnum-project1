# Métodos Numéricos - TP1
El proyecto consta de un ejecutable para resolver un PageRank concreto, y una suite de tests.

## Ejecutable
Para compilar el ejecutable, correr
```
cmake .
make tp1
```

Luego, este se puede correr de la siguiente manera:
```
./tp1 <archivo> <p>
```
La misma corresponde a lo requerido en el enunciado del TP.

Además, el ejecutable acepta la opción customizar el tipo de sumatoria. Se corre de la siguiente manera:
```
./tp1 <archivo> <p> <tipo-sumatoria>
```
Los tipos sumatoria disponibles son: `normal`, `kahan`, `ordenada`. Es un parámetro opcional, y por default tiene el valor de `normal`

Ejemplo:
```
echo "1\n0" > test.txt
./tp1 test.txt 0.3
```
Luego de esto, en test.txt.out se podrá encontrar el resultado del PageRank.

## Suite de tests
Para correr la suite de tests:
```
cmake .
make correrTests
./correrTests
```
La suite está compuesta por 3 conjuntos de tests:
- Tests de clase MatrizDiagonal (correrTestsMatrizDiagonal)
- Tests de clase MatrizRala (correrTestsMatrizRala)
- Tests de la cátedra (correrTestsCatedra)

Estos pueden ser compilados y ejecutados por separado usando el nombre puesto entre paréntesis.
```
cmake .
make <nombre de test>
./<nombre de test>
```
