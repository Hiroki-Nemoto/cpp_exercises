//Mat4x4.cpp
#include <cstring>
#include <iostream>
#include <cmath>
#include "Mat4x4.h"

#define MAT_SIZE 4

using namespace std;

Mat4x4::Mat4x4() {
    data[0][0] = 1.0;  data[0][1] = 0.0;  data[0][2] = 0.0; data[0][3] = 0.0;
    data[1][0] = 0.0;  data[1][1] = 1.0;  data[1][2] = 0.0; data[1][3] = 0.0;
    data[2][0] = 0.0;  data[2][1] = 0.0;  data[2][2] = 1.0; data[2][3] = 0.0;
    data[3][0] = 0.0;  data[3][1] = 0.0;  data[3][2] = 0.0; data[3][3] = 1.0;
    }

Mat4x4::Mat4x4(const double coefficients[MAT_SIZE][MAT_SIZE]) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            data[i][j] = coefficients[i][j];
        }
    }
}

// destructor
Mat4x4::~Mat4x4() {}

Mat4x4& Mat4x4::operator= (const Mat4x4& other) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

double& Mat4x4::operator() (int i, int j) {
    return data[i][j];
}

double Mat4x4::operator() (int i, int j) const {
    return data[i][j];
}

Mat4x4& Mat4x4::operator+= (const Mat4x4& other) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return *this;
}

Mat4x4& Mat4x4::operator-= (const Mat4x4& other) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return *this;
}

Mat4x4& Mat4x4::operator*= (const Mat4x4& other) {
    Mat4x4 c = *this;
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            data[i][j] = 0.0;
            for (int s = 0; s < MAT_SIZE; ++s) {
                data[i][j] += c.data[i][s] * other.data[s][j];
            }
        }
    }
    return *this;
}

const Mat4x4 Mat4x4::operator- ()  {
    Mat4x4 r;
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            if (data[i][j] != 0) {
                r.data[i][j] = -data[i][j];
            }
        }
    }
    return r.data;
}

Mat4x4 operator+ (const Mat4x4& otherA, const Mat4x4& otherB) {
    return Mat4x4(otherA) += otherB;
}

Mat4x4 operator- (const Mat4x4& otherA, const Mat4x4& otherB) {
    return Mat4x4(otherA) -= otherB;
}

Mat4x4 operator* (const Mat4x4& otherA, const Mat4x4& otherB) {
    return Mat4x4(otherA) *= otherB;
}

bool operator== (const Mat4x4& otherA, const Mat4x4& otherB) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            if (otherA(i, j) != otherB(i, j)) return false;
        }
    }
    return true;
}

std::ostream& operator<< (std::ostream& os, const Mat4x4& c) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            os << c.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

