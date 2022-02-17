#include <iostream>
#include <vector>

int binarySearch(std::vector<int> vector, int i, int j, int k) {
    if (j >= i) {
        int mid = i + (j - i) / 2;
        if (vector[mid] == k) {
            return mid;
        }
        if (vector[mid] > k) {
            return binarySearch(vector, i, mid - 1, k);
        }
        return binarySearch(vector, mid + 1, j, k);
    }
    return -1;
}

int main() {
    std::vector<int> vector = {1, 2, 4, 7, 11, 16, 22, 29, 37};
    int k = 1;
    int n = vector.size();
    int result = binarySearch(vector, 0, n - 1, k);
    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element found at index " << result << std::endl;
    }
    return 0;
}
