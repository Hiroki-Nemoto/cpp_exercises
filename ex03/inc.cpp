#include <iostream>
#include "inc.h"

void inc(double& i) {i++;}

void inc(double* j) {*j = *j +1;}