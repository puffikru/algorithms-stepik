#include <iostream>
#include <vector>
#include <algorithm>

// Число Х есть в массиве
// Несколько чисел Х
// Есть число Х в массиве и оно последнее
// Есть несколько чисел Х и они все последние
// Массив только из этих чисел
// Число Х является нулевым элементом


int BinarySearch(const std::vector<int>& data, int x) {
    int l = 0;
    int r = data.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (x >= data[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (l - 1 >= 0 && data[l - 1] == x) {
        return data.size() - 1 - (l - 1);
    } else if (data[r] <= x && data[l] > x) {
        return data.size() - l;
    } else if (l - 1 <= data.size() && data[l - 1] < x) {
        return 0;
    } else {
        return data.size();
    }
    return -1;
}


bool SimpleTest() {
    std::vector<int> values = {1, 3, 4, 6, 8};
    std::vector<int> test = {3, 0, 9};
    std::vector<int> expected = {3, 5, 0};
    std::vector<int> result;
    result.reserve(expected.size());
    for (int item : test) {
        result.push_back(BinarySearch(values, item));
    }
    return result == expected;
}


bool IsFindXTest() {
    std::vector<int> values = {-2, 1, 4, 7, 9};
    int x = 7;
    int expected = 1;
    return BinarySearch(values, x) == expected;
}

bool IsMenyXTest() {
    std::vector<int> values = {-4, -2, 0, 0, 0, 2, 5, 6};
    int x = 0;
    int expected = 3;
    return BinarySearch(values, x) == expected;
}

bool LastNumberTest() {
    std::vector<int> values = {-4, -2, 0, 0, 0, 2, 5, 6};
    int x = 6;
    int expected = 0;
    return BinarySearch(values, x) == expected;
}

bool LastNumbersTest() {
    std::vector<int> values = {-4, -2, 0, 0, 0, 2, 5, 6, 7, 7, 7, 7, 7};
    int x = 7;
    int expected = 0;
    return BinarySearch(values, x) == expected;
}

bool AllNumbersTest() {
    std::vector<int> values = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int x = 7;
    int expected = 0;
    return BinarySearch(values, x) == expected;
}

bool ZeroElementTest() {
    std::vector<int> values = {-4, -2, 0, 0, 0, 2, 5, 6};
    int x = -4;
    int expected = 7;
    return BinarySearch(values, x) == expected;
}

bool NoElementTest() {
    std::vector<int> values = {-4, -2, 0, 0, 0, 2, 5, 6};
    int x = -7;
    int expected = 8;
    return BinarySearch(values, x) == expected;
}

bool TestBinSearch() {
    std::vector<int> test_nums = {-10, -8, -7, 0, 1, 6};
    std::vector<int> values = {-20, -11, -6, -9, -4, 5};
    std::vector<int> expected = {6, 6, 3, 5, 3, 1};
    std::vector<int> result;
    result.reserve(expected.size());
    for (int item : values) {
        result.push_back(BinarySearch(test_nums, item));
    }

    return expected == result;
}


int main() {
    // int N;
    // int M;
    // std::cin >> N;
    // std::vector<int> arr;
    // arr.reserve(N);
    // int temp;
    // for (size_t i = 0; i < N; ++i) {
    //     std::cin >> temp;
    //     arr.push_back(temp);
    // }
    // std::cin >> M;
    // sort(arr.begin(), arr.end());
    // std::vector<int> val;
    // val.reserve(M);
    // for (size_t i = 0; i < M; ++i) {
    //     std::cin >> temp;
    //     val.push_back(temp);
    // }
    // for (int item : val) {
    //     std::cout << BinarySearch(arr, item) << std::endl;
    // }
    std::cout << "SimpleTest: " << SimpleTest() << std::endl;
    std::cout << "IsFindXTest: " << IsFindXTest() << std::endl;
    std::cout << "IsMenyXTest: " << IsMenyXTest() << std::endl;
    std::cout << "LastNumberTest: " << LastNumberTest() << std::endl;
    std::cout << "LastNumbersTest: " << LastNumbersTest() << std::endl;
    std::cout << "AllNumbersTest: " << AllNumbersTest() << std::endl;
    std::cout << "ZeroElementTest: " << ZeroElementTest() << std::endl;
    std::cout << "NoElementTest: " << NoElementTest() << std::endl;
    std::cout << "TestBinSearch: " << TestBinSearch() << std::endl;

    return 0;
}
