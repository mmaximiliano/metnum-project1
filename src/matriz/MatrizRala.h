#ifndef __MATRIZ_RALA_H__
#define __MATRIZ_RALA_H__

#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include "Tipos.h"
#include "MatrizDiagonal.h"
#include <algorithm>
#include <math.h>

#define EPSILON 0.0000001

using namespace std;

typedef pair<ll, ld> Elemento;

class MatrizRala {
public:
    MatrizRala(ll, string sumatoria);

    MatrizRala(ll, vector<pair<ll, ll> >, string sumatoria); // Genera una matriz de 1s y 0s
    MatrizRala(const MatrizRala &, string sumatoria);

    static MatrizRala identidad(ll, string sumatoria);

    MatrizRala &operator-(const MatrizRala &);

    MatrizRala &operator*(const ld &);

    MatrizRala &operator*(const MatrizDiagonal &);

    void agregar(ll, ll, ld); // Agrega un elemento
    const vector<Elemento> &fila(ll) const;

    vector<Elemento> &fila(ll);

    ld elem(ll, ll) const;

    bool distintoACero(ll, ll) const;

    unsigned int size() const;

    vector<ld> resolver(ll gamma);

    string toString() const;

private:
    vector<vector<Elemento> > filas;

    string sumatoria;

    void restarFila(ll, ll, vector<ld> &);

    void normalizar(vector<ld> &) const;

    ld norma_1(vector<ld> &) const;
};

#endif
