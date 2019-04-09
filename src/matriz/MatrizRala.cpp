#include "MatrizRala.h"

MatrizRala::MatrizRala(ll tam, string sumatoria) {
    this->filas.resize(tam);
    this->sumatoria = sumatoria;
}

MatrizRala::MatrizRala(ll tam, vector<pair<ll, ll> > mat, string sumatoria) {
    this->filas.resize(tam);
    for (auto e : mat) {
        this->agregar(e.first, e.second, 1);
    }
    this->sumatoria = sumatoria;
}

MatrizRala MatrizRala::identidad(ll tam, string sumatoria) {
    MatrizRala mr(tam, sumatoria);
    for (unsigned int i = 0; i < tam; i++) {
        mr.filas[i].push_back({i, 1});
    }
    return mr;
}

MatrizRala::MatrizRala(const MatrizRala &m, string sumatoria) {
    this->filas.resize(m.filas.size());

    auto itNuevo = this->filas.begin();
    auto itViejo = m.filas.begin();

    while (itNuevo != this->filas.end()) {
        for (Elemento e:*itViejo) {
            itNuevo->push_back(e);
        }

        itNuevo++;
        itViejo++;
    }

    this->sumatoria = sumatoria;
}

MatrizRala &MatrizRala::operator-(const MatrizRala &omr) {

    for (ll fila = 0; fila < this->filas.size(); fila++) {
        vector<Elemento> nuevaFila;
        auto itA = this->filas[fila].begin();
        auto itB = omr.fila(fila).begin();

        while (itA != this->filas[fila].end() && itB != omr.fila(fila).end()) {
            if (itA->first < itB->first) {
                nuevaFila.push_back({itA->first, itA->second});
                itA++;
            } else if (itA->first > itB->first) {
                nuevaFila.push_back({itB->first, -itB->second});
                itB++;
            } else {
                nuevaFila.push_back({itA->first, itA->second - itB->second});
                itA++;
                itB++;
            }
        }

        while (itA != this->filas[fila].end()) {
            nuevaFila.push_back({itA->first, itA->second});
            itA++;
        }
        while (itB != omr.fila(fila).end()) {
            nuevaFila.push_back({itB->first, -itB->second});
            itB++;
        }
        this->filas[fila] = nuevaFila;
    }

    return *this;
}

MatrizRala &MatrizRala::operator*(const ld &x) {
    for (auto &itFila:this->filas) {
        for (auto &itElem:itFila) {
            itElem.second *= x;
        }
    }

    return *this;
}

MatrizRala &MatrizRala::operator*(const MatrizDiagonal &md) {
    for (auto itFila = this->filas.begin(); itFila != this->filas.end(); itFila++) {
        for (auto itElem = itFila->begin(); itElem != itFila->end(); itElem++) {
            itElem->second *= md.elem(itElem->first);
        }
    }
    return *this;
}

void MatrizRala::agregar(ll x, ll y, ld e) {
    if (abs(e) > EPSILON) {
        vector<Elemento> &v = this->filas[x];
        auto insertIt = lower_bound(v.begin(), v.end(), (Elemento) {y, e});

        if (insertIt != v.end() && insertIt->first == y) {
            insertIt->second = e;
        } else {
            v.insert(insertIt, {y, e});
        }
    }
}

const vector<Elemento> &MatrizRala::fila(ll i) const {
    return this->filas[i];
}

vector<Elemento> &MatrizRala::fila(ll i) {
    return this->filas[i];
}

ld MatrizRala::elem(ll x, ll y) const {
    const vector<Elemento> &v = this->filas[x];
    auto it = lower_bound(v.begin(), v.end(), (Elemento) {y, numeric_limits<double>::lowest()});

    if (it != v.end() && it->first == y)
        return it->second;

    return 0;
}

bool MatrizRala::distintoACero(ll x, ll y) const {
    const vector<Elemento> &v = this->filas[x];
    auto it = lower_bound(v.begin(), v.end(), (Elemento) {y, numeric_limits<double>::lowest()});

    return (it != v.end() && it->first == y);
}

vector<ld> MatrizRala::resolver(ll gamma) {
    vector<ld> b(this->filas.size(), gamma);

    // Eliminacion gaussiana
    for (unsigned int i = 0; i < this->filas.size() - 1; i++) {
        for (unsigned int j = i + 1; j < this->filas.size(); j++) {
            this->restarFila(i, j, b);
        }
    }

    // Sustituyo para atras
    vector<ld> x;
    x.push_back(b.back() / this->elem(this->filas.size() - 1, this->filas.size() - 1));
    for (int i = this->filas.size() - 2; i >= 0; i--) {
        ld sum = 0;

        for (unsigned int j = i + 1; j < this->filas.size(); j++) {
            sum += this->elem(i, j) * x[this->filas.size() - j - 1];
        }
        x.push_back((b[i] - sum) / this->elem(i, i));
    }

    reverse(x.begin(), x.end());
    this->normalizar(x);
    return x;
}

void MatrizRala::restarFila(ll i, ll j, vector<ld> &b) {

    ld m = this->elem(j, i) / this->elem(i, i);

    b[j] -= m * b[i];

    if (abs(m) < EPSILON) {
        return;
    }

    vector<Elemento> &filai = this->fila(i);
    vector<Elemento> &filaj = this->fila(j);

    vector<Elemento> nuevaFila;

    auto itI = filai.begin();
    vector<Elemento>::iterator itJ = filaj.begin();

    unsigned int indexFilaJ = 0;

    while (itI != filai.end() && itJ != filaj.end()) {
        if (itI->first < itJ->first) {
            ld resultado = 0 - m * itI->second;
            if (abs(resultado) > EPSILON) {
                filaj.insert(filaj.begin() + indexFilaJ, {itI->first, resultado});
                indexFilaJ++;
                itJ = filaj.begin() + indexFilaJ;
            }
            itI++;
        } else if (itI->first > itJ->first) {
            itJ++;
            indexFilaJ++;
        } else {
            ld resultado = itJ->second - m * itI->second;
            if (abs(resultado) > EPSILON) {
                itJ->second = resultado;
                indexFilaJ++;
                itJ++;
            } else {
                filaj.erase(itJ);
            }

            itI++;
        }
    }

    while (itI != filai.end()) {
        ld resultado = 0 - m * itI->second;
        if (abs(resultado) > EPSILON) {
            filaj.insert(filaj.begin() + indexFilaJ, {itI->first, resultado});
            indexFilaJ++;
        }
        itI++;
    }
}

string MatrizRala::toString() const {
    ostringstream s;

    for (auto f:this->filas) {
        unsigned int i = 0;
        for (Elemento e:f) {
            while (i < e.first) {
                s << "0 ";
                i++;
            }
            s << e.second << " ";
            i++;
        }

        while (i < this->filas.size()) {
            s << "0 ";
            i++;
        }
        s << "\n";
    }
    return s.str();
}

unsigned int MatrizRala::size() const {
    return this->filas.size();
}

void MatrizRala::normalizar(vector<ld> &v) const {
    ld sum = norma_1(v);

    for (auto &e : v) {
        e = e / sum;
    }
}

ld MatrizRala::norma_1(vector<ld> &v) const{
  if (sumatoria == "normal") {
    // Suma normal
    ld sum = 0;
    for (auto e : v) {
        sum += abs(e);
    }

    return sum;
  } else if (sumatoria == "kahan") {
    // Suma kahan
    ld sum = 0;
    ld c = 0;

    for (auto e : v) {
        ld y = abs(e) - c;
        ld t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return sum;

  } else {
    // Suma ordenado
    sort(v.begin(), v.end()); 
    ld sum = 0;
    for (auto e : v) {
        sum += abs(e);
    }

    return sum;

  }
}
