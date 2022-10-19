#pragma once
#include <fstream>
#include <ctime>

using namespace std;
class Matrix {
    int size;
    int** m_values;
    friend Matrix operator*(int, Matrix&);
    friend Matrix operator+(int, Matrix&);
    friend Matrix operator-(int, Matrix&);
    friend std::ostream& operator<<(std::ostream&, Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
public:
    Matrix();
    Matrix(int n);
    Matrix(const Matrix& other);
    ~Matrix();
    bool can_multiply(const Matrix& other);
    int get(int i, int j) const;
    bool read_random();
    bool equal_size(const Matrix& other);
    Matrix transpose();
    void resize(int n);
    void sub(int value);
    bool operator==(Matrix& p) const;
    Matrix& operator=(const Matrix&);
    Matrix operator*(int value);
    Matrix operator+(int value);
    Matrix operator-(int value);
    Matrix operator*(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
};