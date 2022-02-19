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
    std::vector<int> vector = {-86, -75, -27, 7, 8, 14, 21, 34, 75, 83};
    int n = vector.size();
    int x = -86;
    int result = binarySearch(vector, 0, n - 1, x);
    if (result == -1) {
        std::cout << x << " not found" << std::endl;
    } else {
        std::cout << x << " found at index " << result << std::endl;
    }
    return 0;
}
