#ifndef __MATRIZ_DIAGONAL_H__
#define __MATRIZ_DIAGONAL_H__

#include <vector>
#include "Tipos.h"

using namespace std;

class MatrizDiagonal {
public:
    MatrizDiagonal(const vector<ll> &);

    MatrizDiagonal(const MatrizDiagonal &);

    ld elem(ll) const;

private:
    vector<ld> diagonal;
};

#endif
