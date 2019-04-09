#include "MatrizDiagonal.h"

MatrizDiagonal::MatrizDiagonal(const vector<ll> &c) {
    for (ll cj:c) {
        if (cj == 0) {
            this->diagonal.push_back(0);
        } else {
            this->diagonal.push_back(1 / (ld) cj);
        }
    }
}

MatrizDiagonal::MatrizDiagonal(const MatrizDiagonal &omd) {
    for (ld e:omd.diagonal) {
        this->diagonal.push_back(e);
    }
}

ld MatrizDiagonal::elem(ll i) const {
    return this->diagonal[i];
}
