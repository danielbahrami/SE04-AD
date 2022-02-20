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

int cycles(std::vector<int> vector) {
    int count = 0;
    std::vector<int> checked;
    for (int i = 0; i < vector.size(); i++) {
        if (std::find(checked.begin(), checked.end(), i) != checked.end()) {
            continue;
        }
        for (int j = vector[i]; j != i; j = vector[j]) {
            checked.push_back(j);
        }
        count++;
    }
    return count;
}

int main() {
    std::vector<int> vector;
    std::cout << "Random permutation:" << std::endl;
    permutation(vector, 10);
    print(vector);
    std::cout << "Number of cycles:" << std::endl;
    std::cout << cycles(vector) << std::endl;
    return 0;
}
