cmake_minimum_required(VERSION 3.5)
project(solucion)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O2")

include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Leemos todos los archivos fuentes en ./src/matriz/
file(GLOB SOURCE_FILES src/matriz/*.cpp src/matriz/*.h)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)

# Creamos el ejecutable para correr los tests
add_executable(tp1 src/tp1.cpp ${SOURCE_FILES})
add_executable(generateMatrixA src/generateMatrixA.cpp ${SOURCE_FILES})
add_executable(correrTests ${TEST_SOURCES} ${SOURCE_FILES})
add_executable(correrTestsMatrizRala tests/tests_matriz_rala.cpp ${SOURCE_FILES})
add_executable(correrTestsMatrizDiagonal tests/test_matriz_diagonal.cpp ${SOURCE_FILES})
add_executable(correrTestsCatedra tests/tests_catedra.cpp ${SOURCE_FILES})

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)
target_link_libraries(correrTestsMatrizRala gtest gtest_main)
target_link_libraries(correrTestsMatrizDiagonal gtest gtest_main)
target_link_libraries(correrTestsCatedra gtest gtest_main)

add_test(correrTests correrTests)
add_test(correrTestsMatrizRala correrTestsMatrizRala)
add_test(correrTestsMatrizDiagonal correrTestsMatrizDiagonal)
add_test(correrTestsCatedra correrTestsCatedra)

# Target para correr Valgrind
add_custom_target(correrValgrind
        valgrind --leak-check=full -v ./correrTests 2>&1
        DEPENDS correrTests)
