#include <gtest/gtest.h>
#include "matriz/Tipos.h"
#include "matriz/MatrizDiagonal.h"

TEST(test_matriz_diagonal, constructor_vector) {
    vector<ll> v = {2, 5, 3, 9, 0};
    MatrizDiagonal md(v);

    EXPECT_NEAR(md.elem(0), 1 / (ld) 2, 0.00001);
    EXPECT_NEAR(md.elem(1), 1 / (ld) 5, 0.00001);
    EXPECT_NEAR(md.elem(2), 1 / (ld) 3, 0.00001);
    EXPECT_NEAR(md.elem(3), 1 / (ld) 9, 0.00001);
    EXPECT_NEAR(md.elem(4), 0, 0.00001);
}

TEST(test_matriz_diagonal, constructor_copia) {
    vector<ll> v = {2, 5, 3, 9, 0};
    MatrizDiagonal md(v);

    MatrizDiagonal mdCopia(md);

    EXPECT_NEAR(mdCopia.elem(0), 1 / (ld) 2, 0.00001);
    EXPECT_NEAR(mdCopia.elem(1), 1 / (ld) 5, 0.00001);
    EXPECT_NEAR(mdCopia.elem(2), 1 / (ld) 3, 0.00001);
    EXPECT_NEAR(mdCopia.elem(3), 1 / (ld) 9, 0.00001);
    EXPECT_NEAR(mdCopia.elem(4), 0, 0.00001);
}
