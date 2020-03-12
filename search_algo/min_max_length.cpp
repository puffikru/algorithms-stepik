#include <iostream>
#include <vector>
#include <algorithm>



int FindMin(std::vector<int> arr) {
    std::sort(begin(arr), end(arr));
    return arr[0];
}

int FindMax(std::vector<int> arr) {
    std::sort(begin(arr), end(arr));
    return arr[arr.size() - 1];
}


int LinearSearch(const std::vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> val(N);
    for (int& item : val) {
        std::cin >> item;
    }
    int min = LinearSearch(val, FindMin(val));
    int max = LinearSearch(val, FindMax(val));
    if (min < max) {
        std::cout << max - min - 1 << std::endl;;
    } else {
        std::cout << min - max - 1 << std::endl;
    }
    return 0;
}