#include <gtest/gtest.h>
#include "matriz/Tipos.h"
#include "matriz/MatrizRala.h"

TEST(test_matriz_rala, constructor_tamanio) {
    MatrizRala m(3, "normal");

    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            EXPECT_FALSE(m.distintoACero(i, j));
            EXPECT_EQ(m.elem(i, j), 0);
        }
    }
}

TEST(test_matriz_rala, constructor_conexiones) {
    vector<pair<ll, ll> > conexiones = {{0, 1},
                                        {1, 2},
                                        {2, 0}};
    MatrizRala m(3, conexiones, "normal");

    EXPECT_TRUE(m.distintoACero(0, 1));
    EXPECT_TRUE(m.distintoACero(1, 2));
    EXPECT_TRUE(m.distintoACero(2, 0));
}

TEST(test_matriz_rala, identidad) {
    MatrizRala m = MatrizRala::identidad(4, "normal");

    for (ll i = 0; i < 4; i++) {
        for (ll j = 0; j < 4; j++) {
            if (i == j) {
                EXPECT_TRUE(m.distintoACero(i, j));
                EXPECT_EQ(m.elem(i, j), 1);
            } else {
                EXPECT_FALSE(m.distintoACero(i, j));
                EXPECT_EQ(m.elem(i, j), 0);
            }
        }
    }
}

TEST(test_matriz_rala, ceros) {
    MatrizRala m(3, "normal");

    ld x = 0.1 + 0.2;
    x -= 0.3;

    ld y = 0.5;
    y *= 0.0;

    m.agregar(1, 1, x);
    m.agregar(2, 1, 0.0);
    m.agregar(2, 2, y);

    EXPECT_FALSE(m.distintoACero(1, 1));
    EXPECT_FALSE(m.distintoACero(2, 1));
    EXPECT_FALSE(m.distintoACero(2, 2));
}

TEST(test_matriz_rala, resta) {
    MatrizRala A(4, "normal");
    MatrizRala B(4, "normal");

    A.agregar(1, 1, 0.35);
    A.agregar(2, 2, 0.5);
    A.agregar(1, 3, 0.6);

    B.agregar(1, 1, 0.2);
    B.agregar(2, 2, 0.8);
    B.agregar(2, 1, 0.9);

    MatrizRala &C = A - B;
    EXPECT_NEAR(C.elem(1, 1), 0.15, 0.00001);
    EXPECT_NEAR(C.elem(2, 2), -0.3, 0.00001);
    EXPECT_NEAR(C.elem(1, 3), 0.6, 0.00001);
    EXPECT_NEAR(C.elem(2, 1), -0.9, 0.00001);
}

TEST(test_matriz_rala, mutiplicacion_por_escalar) {
    MatrizRala A(4, "normal");

    A.agregar(1, 1, 0.35);
    A.agregar(2, 2, 0.5);
    A.agregar(1, 3, 0.6);

    MatrizRala &C = A * 2.3;
    EXPECT_NEAR(A.elem(1, 1), 0.805, 0.00001);
    EXPECT_NEAR(A.elem(2, 2), 1.15, 0.00001);
    EXPECT_NEAR(A.elem(1, 3), 1.38, 0.00001);
}
