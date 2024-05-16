#ifndef MATRIX_TEMPLATE_H
#define MATRIX_TEMPLATE_H

#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);
    void set(int row, int col, T value);
    T get(int row, int col) const;
};

#include "matrix_template.cpp"

#endif // MATRIX_TEMPLATE_H
