#include <iostream>
#include <vector>

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
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
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
    std::vector<int> vector = {100, 46, 75, 66, 17, 93, 11, 95, 87, 55, 3332, 2, 9, -9};
    mergeSort(vector, 0, vector.size());
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    return 0;
}
