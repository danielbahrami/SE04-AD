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

int main() {
    permutation(10);
    return 0;
}
