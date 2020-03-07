#include <iostream>
#include <vector>

//  -2 1 3 3 7 8 8 8 9
//   2 4 8 1 6 3 5 7 9
//   2 4 5 1 4 2 4 4 8

//   3 3 3 3 3
//   1 4 3 2 5
//   0 5 0 0 5

//   5
//   2 4 7 1 3
//   0 0 1 0 0


int BinarySearch(const std::vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (x <= arr[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    if (x < arr[0]) {
        return 0;
    } else if (x > arr[arr.size() - 1]) {
        return arr.size();
    }

    if (r + 1 < arr.size() && l < arr.size() && arr[r + 1] <= x) {
        return r + 1;
    } else if (r >= 0 && arr[r] < x && arr[r + 1] > x) {
        return r + 1;
    }
    return -1;
}

bool SimpleTest() {
    std::vector<int> values = {-2, 1, 3, 3, 7, 8, 8, 8, 9};
    std::vector<int> check = {2, 4, 8, 1, 6, 3, 5, 7, 9};
    std::vector<int> expected = {2, 4, 5, 1, 4, 2, 4, 4, 8};
    std::vector<int> result;
    result.reserve(check.size());
    for (int& item : check) {
        result.push_back(BinarySearch(values, item));
    }
    for (int& i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return expected == result;
}

bool SimilarHeightTest() {
    std::vector<int> values = {3, 3, 3, 3, 3};
    std::vector<int> check = {1, 4, 3, 2, 5};
    std::vector<int> expected = {0, 5, 0, 0, 5};
    std::vector<int> result;
    result.reserve(check.size());
    for (int& item : check) {
        result.push_back(BinarySearch(values, item));
    }
    for (int& i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return expected == result;
}

bool OneValueTest() {
    std::vector<int> values = {5};
    std::vector<int> check = {2, 4, 7, 1, 3};
    std::vector<int> expected = {0, 0, 1, 0, 0};
    std::vector<int> result;
    result.reserve(check.size());
    for (int& item : check) {
        result.push_back(BinarySearch(values, item));
    }
    for (int& i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return expected == result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> meerkats(n);
    std::vector<int> marmots(k);
    for (int& m : meerkats) {
        std::cin >> m;
    }
    for (int& m : marmots) {
        std::cin >> m;
    }
    for (int& m : marmots) {
        std::cout << BinarySearch(meerkats, m) << std::endl;
    }

    // if (SimpleTest()) {
    //     std::cout << "OK" << std::endl;
    // } else {
    //     std::cout << "NO" << std::endl;
    // }

    // if (SimilarHeightTest()) {
    //     std::cout << "OK" << std::endl;
    // } else {
    //     std::cout << "NO" << std::endl;
    // }

    // if (OneValueTest()) {
    //     std::cout << "OK" << std::endl;
    // } else {
    //     std::cout << "NO" << std::endl;
    // }
    
    return 0;
}
