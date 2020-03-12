#include <iostream>
#include <vector>

// 4 1 1    3
// 5 1 2    4
// 40 2 3   50
// 1 1 1    1
// 2 1 1    1
// 7 1 7    7
// 7 10 5   25
// 7 10 2   12
// 20 10 10  110
// 20 9 10  99
// 21 10 9  108

int SearchMinTime(int N, int x, int y) {
    int max = x > y ? x : y;
    int min = x < y ? x : y;
    int l = 0;
    int r = N * max + min;

    int pages = x + y;
    int seconds = x * y;
    int first_page = min;
    int first_page_count = 1;

    int main_pages_count = N - first_page_count;
    int main_pages;

    int last_pages_count;

    if (main_pages_count % pages > 0) {
        main_pages_count = main_pages_count / pages;
        last_pages_count = main_pages_count % pages;
    }

    int main_pages_time = main_pages_count * seconds;
    int last_pages_time;

    if (last_pages_count * min > max && last_pages_count < max) {
        int common_size = max - (max - min);
        int last_pages_time = last_pages_count * common_size;
    }

    return 0;
}

void SimpleTest() {
    {
        std::vector<int> test= {4, 1, 1};
        int expected = 3;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 1 is OK" << std::endl;
        } else {
            std::cout << "test 1 is FAILED" << std::endl;
            std::cout << "expected: 3, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {5, 1, 2};
        int expected = 4;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 2 is OK" << std::endl;
        } else {
            std::cout << "test 2 is FAILED" << std::endl;
            std::cout << "expected: 4, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {40, 2, 3};
        int expected = 50;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 3 is OK" << std::endl;
        } else {
            std::cout << "test 3 is FAILED" << std::endl;
            std::cout << "expected: 50, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {1, 1, 1};
        int expected = 1;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 4 is OK" << std::endl;
        } else {
            std::cout << "test 4 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {2, 1, 1};
        int expected = 2;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 5 is OK" << std::endl;
        } else {
            std::cout << "test 5 is FAILED" << std::endl;
            std::cout << "expected: 2, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 1, 7};
        int expected = 7;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 6 is OK" << std::endl;
        } else {
            std::cout << "test 6 is FAILED" << std::endl;
            std::cout << "expected: 7, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 10, 5};
        int expected = 25;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 7 is OK" << std::endl;
        } else {
            std::cout << "test 7 is FAILED" << std::endl;
            std::cout << "expected: 25, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 10, 2};
        int expected = 12;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 8 is OK" << std::endl;
        } else {
            std::cout << "test 8 is FAILED" << std::endl;
            std::cout << "expected: 12, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {20, 10, 10};
        int expected = 110;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 9 is OK" << std::endl;
        } else {
            std::cout << "test 9 is FAILED" << std::endl;
            std::cout << "expected: 110, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {20, 9, 10};
        int expected = 99;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 10 is OK" << std::endl;
        } else {
            std::cout << "test 10 is FAILED" << std::endl;
            std::cout << "expected: 99, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {21, 10, 9};
        int expected = 108;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 11 is OK" << std::endl;
        } else {
            std::cout << "test 11 is FAILED" << std::endl;
            std::cout << "expected: 108, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }

}


int main() {
    int N;
    int x;
    int y;
    std::cin >> N >> x >> y;
    // SimpleTest();
    // std::cout << SearchMinTime(N, x, y) << std::endl;
    SearchMinTime(N, x, y);
    return 0;
}