//Mat4x4.h
#include <cstdlib>
#include <istream>
#include <ostream>
#include <string>

#ifndef MAT4X4_H
#define MAT4X4_h

using namespace std;

class Mat4x4 {
    public:
// Default constructor
    Mat4x4();
// Constructar complex from its given real and imaginary parts
    Mat4x4(const double coefficients[4][4]);

// destructor
    ~Mat4x4();

// assignment operator
    Mat4x4& operator= (const Mat4x4& other);

// Refer to each element of the other
    double& operator() (int i, int j);
    double operator() (int i, int j) const;

// addition
    Mat4x4& operator+= (const Mat4x4& other);
// subtraction
    Mat4x4& operator-= (const Mat4x4& other);
// multiplication
    Mat4x4& operator*= (const Mat4x4& other);

    const Mat4x4 operator- ();

    friend ostream&
        operator<<(ostream& os, const Mat4x4& m);

    private:
        double data[4][4];
};

// C=A+B
    Mat4x4 operator+ (const Mat4x4& otherA, const Mat4x4& otherB); // 行列の加算
    Mat4x4 operator- (const Mat4x4& otherA, const Mat4x4& otherB); // 行列の減算
    Mat4x4 operator* (const Mat4x4& otherA, const Mat4x4& otherB); // 行列の乗算

// if(A==B)
    bool operator== (const Mat4x4& otherA, const Mat4x4& otherB);

#endif
