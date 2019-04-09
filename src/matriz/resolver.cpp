#include "resolver.h"

#include <fstream>
#include <utility>

#include "MatrizDiagonal.h"
#include "MatrizRala.h"

MatrizRala generarMatriz(ld p, string fileName, string sumatoria) {
    ifstream fin(fileName);

    ll n, m;
    fin >> n >> m;

    ll i, j;
    vector<pair<ll, ll> > conexiones;
    vector<ll> c;
    c.resize(n);
    for(ll x = 0; x < m ; x++) {
        fin >> i >> j;
        conexiones.push_back({j - 1, i - 1});
        c[i - 1]++;
    }

    MatrizRala W(n, conexiones, sumatoria);
    MatrizDiagonal D(c);

    MatrizRala resultado = W * D;
    resultado = resultado * p;

    return resultado;
}

vector<ld> resolver(ld p, string fileName, string sumatoria) {
    MatrizRala res = generarMatriz(p, fileName, sumatoria);
    MatrizRala I = MatrizRala::identidad(res.size(), sumatoria);
    res = I - res;
    return res.resolver(1);
}
