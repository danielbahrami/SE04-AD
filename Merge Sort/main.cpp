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

void merge(std::vector<int> &A, int p, int q, int r) {
    int n1 = q - p;
    int n2 = r - q;
    std::vector<int> L;
    std::vector<int> R;
    for (int i = 0; i < n1; i++) {
        L.push_back(A[p + i]);
    }
    for (int j = 0; j < n2; j++) {
        R.push_back(A[q + j]);
    }
    L.push_back(std::numeric_limits<int>::max());
    R.push_back(std::numeric_limits<int>::max());
    int i = 0;
    int j = 0;
    for (int k = p; k < r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(std::vector<int> &A, int p, int r) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q, r);
        merge(A, p, q, r);
    }
}

int main() {
    std::cout << "Random permutation:" << std::endl;
    permutation(100);
    std::cout << "Merge Sort:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(vector, 0, vector.size());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Execution time of Merge Sort:" << std::endl;
    std::cout << duration.count() << " microseconds" << std::endl;
    return 0;
}
