#include <iostream>
#include <vector>

void permutation(std::vector<int> &vector, int n) {
    for (int i = 0; i < n; i++) {
        vector.push_back(i);
    }
    std::srand(time(0));
    for (int i = 0; i < vector.size(); i++) {
        int j = i + rand() % (vector.size() - i);
        std::swap(vector[i], vector[j]);
    }
}

void print(std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

void quicksort(std::vector<int> &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    std::vector<int> vector;
    std::cout << "Random permutation:" << std::endl;
    permutation(vector, 100);
    print(vector);
    std::cout << "Quicksort:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(vector, 0, vector.size() - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    print(vector);
    std::cout << "Execution time of Quicksort:" << std::endl;
    std::cout << duration.count() << " microseconds" << std::endl;
    return 0;
}
