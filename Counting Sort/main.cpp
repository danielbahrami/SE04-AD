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

void countingSort(std::vector<int> A, std::vector<int> &B, int k) {
    std::vector<int> C(k + 1, 0);
    for (int j = 0; j < A.size(); j++) {
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i < C.size(); i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = A.size() - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}

int main() {
    std::vector<int> vector;
    std::cout << "Random permutation:" << std::endl;
    permutation(vector, 100);
    std::vector<int> vector1(vector.size(), 0);
    print(vector);
    std::cout << "Counting Sort:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    countingSort(vector, vector1, 99);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    print(vector1);
    std::cout << "Execution time of Counting Sort:" << std::endl;
    std::cout << duration.count() << " microseconds" << std::endl;
    return 0;
}
