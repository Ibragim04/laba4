#include <iostream>
#include <vector>

template<typename T>
class Vector {
private:
    std::vector<T> data;
    int size;

public:
    Vector(int size) : size(size) {
        data.resize(size);
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range." << std::endl;
            return;
        }
        data[index] = value;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range." << std::endl;
            return T();
        }
        return data[index];
    }

    // Векторное произведение
    T dot_product(const Vector<T>& other) const {
        T result = 0;
        for (int i = 0; i < size; ++i) {
            result += data[i] * other.get(i);
        }
        return result;
    }

    // Скалярное произведение
    Vector<T> scalar_product(T scalar) const {
        Vector<T> result(size);
        for (int i = 0; i < size; ++i) {
            result.set(i, data[i] * scalar);
        }
        return result;
    }

    // Получение размера вектора
    int get_size() const {
        return size;
    }
};

int main() {
    Vector<int> int_vector(3);
    int_vector.set(0, 1);
    int_vector.set(1, 2);
    int_vector.set(2, 3);

    Vector<int> scalar_product_result = int_vector.scalar_product(2);
    std::cout << "Scalar product result: ";
    for (int i = 0; i < scalar_product_result.get_size(); ++i) {
        std::cout << scalar_product_result.get(i) << " ";
    }
    std::cout << std::endl;

    Vector<int> other_int_vector(3);
    other_int_vector.set(0, 2);
    other_int_vector.set(1, 3);
    other_int_vector.set(2, 4);

    int dot_product_result = int_vector.dot_product(other_int_vector);
    std::cout << "Dot product result: " << dot_product_result << std::endl;

    return 0;
}
