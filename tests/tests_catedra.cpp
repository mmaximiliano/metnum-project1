#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <vector>
#include "matriz/Tipos.h"
#include "matriz/resolver.h"

string archivoIn(string fileName) {
    return "tests/txt/" + fileName + ".txt";
}

string archivoOut(string fileName) {
    return "tests/txt/" + fileName + ".txt.out";
}

TEST(test_catedra, trivial) {
    string file = "test_trivial";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, sin_links) {
    string file = "test_sin_links";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, completo) {
    string file = "test_completo";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, aleatorio) {
    string file = "test_aleatorio";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, aleatorio_desordenado) {
    string file = "test_aleatorio_desordenado";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, quince_segundos) {
    string file = "test_15_segundos";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}

TEST(test_catedra, treinta_segundos) {
    string file = "test_30_segundos";
    ifstream fin(archivoOut(file));

    ld p;
    fin >> p;
    vector<ld> res = resolver(p, archivoIn(file), "normal");

    ld r;
    for (ld e:res) {
        fin >> r;
        EXPECT_NEAR(e, r, 0.00001);
    }
}
