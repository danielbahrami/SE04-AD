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
    std::cout << "Random permutation:" << std::endl;
    permutation(100);
    std::cout << "Number of cycles:" << std::endl;
    std::cout << cycles(vector) << std::endl;
    return 0;
}
