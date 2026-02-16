#include "Vial.h"
#include <iostream>
#include <string>

using namespace std;

//Empty Vial
Vial::Vial() : filled(0), label(0) {
    for (int i = 0; i < SIZE; ++i) contents[i] = ' ';
}

