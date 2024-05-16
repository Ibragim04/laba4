#include <iostream>

template<typename T>
int find_second_max_index(T *array, int size) {
    if (size < 2) {
        std::cerr << "Array size must be at least 2." << std::endl;
        return -1;
    }
    
    int max_index = 0;
    int second_max_index = -1;
    
    for (int i = 1; i < size; ++i) {
        if (array[i] > array[max_index]) {
            second_max_index = max_index;
            max_index = i;
        } else if (second_max_index == -1 || array[i] > array[second_max_index]) {
            second_max_index = i;
        }
    }
    
    return second_max_index;
}

int main() {
    float float_array[] = {1.2f, 3.5f, 2.1f, 4.7f};
    double double_array[] = {1.2, 3.5, 2.1, 4.7};
    int int_array[] = {5, 8, 2, 10};
    char char_array[] = {'a', 'c', 'b', 'e'};
    
    int float_second_max_index = find_second_max_index(float_array, 4);
    int double_second_max_index = find_second_max_index(double_array, 4);
    int int_second_max_index = find_second_max_index(int_array, 4);
    int char_second_max_index = find_second_max_index(char_array, 4);
    
    std::cout << "Second max index in float array: " << float_second_max_index << std::endl;
    std::cout << "Second max index in double array: " << double_second_max_index << std::endl;
    std::cout << "Second max index in int array: " << int_second_max_index << std::endl;
    std::cout << "Second max index in char array: " << char_second_max_index << std::endl;
    
    return 0;
}
