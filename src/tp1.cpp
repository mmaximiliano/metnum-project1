#include <iostream>
#include <string>
#include <fstream>

#include "matriz/Tipos.h"
#include "matriz/resolver.h"

using namespace std;

// Argc deberia ser 3
// Argv[0] = ./tp1
// Argv[1] = <archivo>
// Argv[2] = <p>
// Argv[3] = <tipo-sumatoria> (opcional)
int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        cerr << "El formato de entrada debe ser: \n    ./tp1 <archivo> <p> \n" << endl;
        return 1;
    } else {
        string archivo(argv[1]);
        ld p = stold(argv[2]);

        string sumatoria = "normal";
        if (argc == 4) {
            sumatoria = argv[3];
        }

        vector<ld> res = resolver(p, archivo, sumatoria);

        ofstream fout(archivo + ".out");

        fout << p << endl;
        for (ld e:res) {
            fout << e << "\n";
        }
        return 0;
    }
}
