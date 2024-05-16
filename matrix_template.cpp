#include <iostream>
#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, std::vector<T>(cols));
    }

    void set(int row, int col, T value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cerr << "Index out of range." << std::endl;
            return;
        }
        matrix[row][col] = value;
    }

    T get(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cerr << "Index out of range." << std::endl;
            return T();
        }
        return matrix[row][col];
    }
};

int main() {
    Matrix<float> float_matrix(3, 3);
    float_matrix.set(0, 0, 1.2f);
    float_matrix.set(1, 1, 3.5f);
    std::cout << "Value at (1, 1): " << float_matrix.get(1, 1) << std::endl;

    Matrix<double> double_matrix(2, 2);
    double_matrix.set(0, 0, 2.5);
    double_matrix.set(1, 1, 4.7);
    std::cout << "Value at (1, 1): " << double_matrix.get(1, 1) << std::endl;

    Matrix<int> int_matrix(2, 3);
    int_matrix.set(0, 0, 5);
    int_matrix.set(1, 2, 8);
    std::cout << "Value at (1, 2): " << int_matrix.get(1, 2) << std::endl;

    return 0;
}
