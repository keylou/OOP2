#include "matrix.h"
#include <iostream>
#include <ctime>

Matrix::Matrix() 
{
    size = 0;
    m_values = nullptr;
}

Matrix::Matrix(int n)
{
    size = n;
    m_values = new int * [size];
    for (int i = 0; i < size; i++) 
        m_values[i] = new int[size];
}

Matrix::Matrix(const Matrix& other) 
{
    size = other.size;
    m_values = new int* [size];
    for (int i = 0; i < size; i++)
        m_values[i] = new int[size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            m_values[i][j] = other.m_values[i][j];
}

Matrix::~Matrix() 
{
    if (nullptr != m_values)
    {
        for (int i = 0; i < size; i++)
            delete[] m_values[i];
        delete[] m_values;
    }
}

int Matrix::get(int i, int j) const
{
    return m_values[i][j];
}

bool Matrix::read_random()
{
    if (m_values == nullptr)
    {
        cout << "memory not allocated";
        return false;
    }
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            m_values[i][j] = rand() % 10;
        }
    return true;
}

bool Matrix::equal_size(const Matrix& other) 
{
    return size == other.size;
}

Matrix Matrix::transpose() 
{
    Matrix other(size);
    for (size_t i = 0; i < size; i++) 
        for (size_t j = 0; j < size; j++)
            other.m_values[j][i] = m_values[i][j];
    return other;
}

void Matrix::resize(int n) 
{
    for (int i = 0; i < size; i++)
        delete[] m_values[i];
    delete[] m_values;
    size = n;
    m_values = new int* [size];
    for (int i = 0; i < size; i++)
        m_values[i] = new int[size];
}

bool Matrix::operator==(Matrix& other) const {
    bool flag = true;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (m_values[i][j] != other.m_values[i][j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    return flag;
}

Matrix& Matrix::operator=(const Matrix& p) {
    if (this == &p)
        return *this;
    if (m_values)
    {
        for (int i = 0; i < size; i++)
            delete[] m_values[i];
        delete[] m_values;
        size = 0;
    }
    if (p.m_values)
    {
        size = p.size;
        m_values = new int* [size];
        for (int i = 0; i < size; i++)
            m_values[i] = new int[size];
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                m_values[i][j] = 0;
                m_values[i][j] = p.m_values[i][j];
            }
    }
    else
        m_values = nullptr;
    return *this;
}

Matrix Matrix::operator*(int value)
{
    Matrix result(*this);
    for (int i = 0; i < result.size; ++i)
        for (int j = 0; j < result.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = get(i, j) * value;
        }
    return result;
}

Matrix operator*(int value, Matrix& p)
{
    Matrix result(p);
    for (int i = 0; i < result.size; ++i)
        for (int j = 0; j < result.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = p.get(i, j) * value;
        }
    return result;
}

Matrix Matrix::operator+(int value)
{
    Matrix result(*this);
    for (int i = 0; i < result.size; ++i)
        for (int j = 0; j < result.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = get(i, j) + value;
        }
    return result;
}

Matrix Matrix::operator*(const Matrix& other)
{
    if (equal_size(other))
    {
        Matrix result(other);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                result.m_values[i][j] = 0;
                for (int k = 0; k < size; k++)
                    result.m_values[i][j] += get(i, k) * other.get(k, j);
            }
        return result;
    }
}


Matrix Matrix::operator+(const Matrix& other)
{
    if (equal_size(other))
    {
        Matrix result(other);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                result.m_values[i][j] = 0;
                result.m_values[i][j] = get(i, j) + other.get(i,j);
            }
        return result;
    }
}

Matrix Matrix::operator-(const Matrix& other)
{
    if (equal_size(other))
    {
        Matrix result(other);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                result.m_values[i][j] = 0;
                result.m_values[i][j] = get(i, j) - other.get(i, j);
            }
        return result;
    }
}

Matrix operator+(int value, Matrix& p)
{
    Matrix result(p);
    for (int i = 0; i < p.size; ++i)
        for (int j = 0; j < p.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = p.get(i, j) + value;
        }
    return result;
}

Matrix Matrix::operator-(int value)
{
    Matrix result(*this);
    for (int i = 0; i < result.size; ++i)
        for (int j = 0; j < result.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = get(i, j) - value;
        }
    return result;
}

Matrix operator-(int value, Matrix& p)
{
    Matrix result(p);
    for (int i = 0; i < p.size; ++i)
        for (int j = 0; j < p.size; ++j)
        {
            result.m_values[i][j] = 0;
            result.m_values[i][j] = -p.get(i, j) + value;
        }
    return result;
}

std::istream& operator>>(std::istream& in, Matrix& p) 
{
    p.size = 0;
    if (p.m_values) {
        for (int i = 0; i < p.size; i++)
            delete[] p.m_values[i];
        delete[] p.m_values;
        p.m_values = nullptr;
    }
    in >> p.size;
    for (int i(0); i < p.size; i++)
    {
        int a;
        for (int i = 0; i < p.size; ++i)
            for (int j = 0; j < p.size; ++j)
            {
                in >> a;
                p.m_values[i][j] = a;
            }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrix& p) 
{
    for (int i = 0; i < p.size; ++i)
    {
        for (int j = 0; j < p.size; ++j)
            out << p.m_values[i][j] << " ";
        out << endl;
    }
    return out;
}