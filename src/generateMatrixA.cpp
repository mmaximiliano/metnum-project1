#include <iostream>
#include <fstream>
#include <string>

#include "matriz/Tipos.h"
#include "matriz/MatrizRala.h"
#include "matriz/resolver.h"

using namespace std;

// Argc deberia ser 3
// Argv[0] = ./tp1
// Argv[1] = <p>
// Argv[2] = <archivo entrada>
// Argv[3] = <archivo salida>
int main(int argc, char const *argv[]) {
    if (argc != 4) {
        cerr << "El formato de entrada debe ser: \n    ./generateMatrixA <p> <archivo entrada> <archivo salida>\n" << endl;
        return 1;
    } else {
        ld p = stold(argv[1]);
        string archivoEntrada(argv[2]);
        string archivoSalida(argv[3]);
        //cout << "Archivo: " << archivo << endl;
        //cout << "Probabilidad: " << p << endl;
        ifstream fin(archivoEntrada);

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

        MatrizRala W(n, conexiones, "normal");

        MatrizRala res(n, "normal");
        for (ll x = 0; x < n; x++) {
            for (ll y = 0; y < n; y++) {
                ld val = (c[y] == 0)? (1/(ld)n): ((1-p)/(ld)n + (p * W.elem(x, y)) /(ld) c[y]);
                res.agregar(x, y, val);
            }
        }

        ofstream fout(archivoSalida);

        fout << res.toString();
        return 0;
    }
}
