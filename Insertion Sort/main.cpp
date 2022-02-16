#include <iostream>
#include <vector>

std::vector<int> vector;

void permutation(int n) {
    for (int i = 0; i < n; i++) {
        vector.push_back(i);
    }
    std::srand(time(0));
    for (int i = 0; i < vector.size(); i++) {
        int j = i + rand() % (vector.size() - i);
        std::swap(vector[i], vector[j]);
    }
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int> vector) {
    for (int i = 1; i < vector.size(); i++) {
        int key = vector[i];
        int j = i - 1;
        while (j >= 0 && vector[j] > key) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Random permutation:" << std::endl;
    permutation(100);
    std::cout << "Insertion Sort:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(vector);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Execution time of Insertion Sort:" << std::endl;
    std::cout << duration.count() << " microseconds" << std::endl;
    return 0;
}
