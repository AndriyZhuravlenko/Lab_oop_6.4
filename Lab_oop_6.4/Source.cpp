#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <class T>
class Matrix
{
    T* v;
    int size;
public:
    Matrix(int newsize);
    Matrix(Matrix&);
    ~Matrix();
    T& operator [] (int index);
    Matrix operator + (const Matrix&);
    Matrix operator - (const Matrix&);


    friend ostream& operator << <>(ostream&, Matrix&);
    friend istream& operator >> <>(istream&, Matrix&);

    int getSize() const;
    void print() const;
};

template <class T>
Matrix<T>::Matrix(int newsize)
{
    size = newsize;
    v = new T[size * size];
}

template <class T>
Matrix<T>::Matrix(Matrix& m)
{
    size = m.getSize();
    v = new T[size * size];
    for (int i = 0; i < size * size; i++)
        v[i] = m.v[i];
}

template <class T>
Matrix<T>::~Matrix()
{
    delete[] v;
}

template <class T>
T& Matrix<T>::operator [] (int index)
{
    return v[index];
}

template <class T>
int Matrix<T>::getSize() const
{
    return size;
}

template <class T>
void Matrix<T>::print() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << v[i * size + j] << " ";
        cout << endl;
    }
}

template <class T>
ostream& operator << (ostream& os, Matrix<T>& m)
{
    for (int i = 0; i < m.getSize(); i++)
    {
        for (int j = 0; j < m.getSize(); j++)
            os << m[i * m.getSize() + j] << " ";

        os << endl;
    }
    return os;
}

template <class T>
istream& operator >> (istream& is, Matrix<T>& m)
{
    for (int i = 0; i < m.getSize(); i++)
    {
        for (int j = 0; j < m.getSize(); j++)
            is >> m[i * m.getSize() + j];
    }
    return is;
}

template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix& m)
{
    Matrix<T> result(size);
    for (int i = 0; i < size * size; i++)
        result.v[i] = v[i] + m.v[i];
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator - (const Matrix& m)
{
    Matrix<T> result(size);
    for (int i = 0; i < size * size; i++)
        result.v[i] = v[i] - m.v[i];
    return result;
}

int main()
{
    int size;
    cout << "Enter size of matrix ";
    cin >> size;
    Matrix<int> m1(size);
    cout << "Enter matrix " << endl;
    cin >> m1;
    cout << endl;
    Matrix<int> m2(size);
    cout << "Enter matrix " << endl;
    cin >> m2;
    cout << endl;
    cout << "Matrix 1 " << endl;
    m1.print();
    cout << endl;
    cout << "Matrix 2 " << endl;
    m2.print();
    cout << endl;

    cout << "Matrix 1 + Matrix 2 " << endl;
    (m1 + m2).print();
    cout << endl;
    cout << "Matrix 1 - Matrix 2 " << endl;
    (m1 - m2).print();
    cout << endl;

    return 0;
}