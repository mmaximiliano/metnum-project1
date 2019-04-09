#ifndef __RESOLVER_H__
#define __RESOLVER_H__

#include <string>
#include <vector>

#include "Tipos.h"
#include "MatrizRala.h"

using namespace std;

MatrizRala generarMatriz(ld p, string fileName);

vector<ld> resolver(ld p, string fileName, string sumatoria);

#endif
