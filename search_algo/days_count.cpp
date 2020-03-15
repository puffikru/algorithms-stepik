#include <iostream>
#include <vector>

bool CheckDays(uint64_t days, uint64_t X, uint64_t A, uint64_t B, uint64_t K, uint64_t M) {

    uint64_t holiday_1 = days / K;
    uint64_t holiday_2 = days / M;

    uint64_t workdays_1 = days - holiday_1;
    uint64_t workdays_2 = days - holiday_2;

    uint64_t worker_half_count_1 = holiday_2;
    uint64_t worker_half_count_2 = holiday_1;

    uint64_t common_days_1 = workdays_1 - worker_half_count_1;
    uint64_t common_days_2 = workdays_2 - worker_half_count_2;

    uint64_t common_trees = (A + B) * common_days_1;
    uint64_t worker_half_trees_1 = worker_half_count_1 * A;
    uint64_t worker_half_trees_2 = worker_half_count_2 * B;

    uint64_t total_trees = common_trees + worker_half_trees_1 + worker_half_trees_2;

    if (total_trees - X > 0) {
        if (X % K == 0) {
            if (total_trees - X <= B) {
                return true;
            }
            // return total_trees;
        } else if (X % M == 0) {
            if (total_trees - X <= A) {
                return true;
            }
            // return total_trees;
        } else if (X % K == 0 && X % M == 0) {
            // return total_trees;
        } else {
            if (total_trees - X <= A || total_trees - X <= B) {
                return true;
            }
        }
    }

    return total_trees >= X;
}

uint64_t Productivity(uint64_t X, uint64_t trees_per_day, uint64_t holidays) {
    uint64_t w = X / trees_per_day;
    uint64_t h = + w / holidays;
    if (X % trees_per_day > 0) w++;
    if (w % holidays > 0) h++;
    return w + h;
}

uint64_t BinarySearch(uint64_t A, uint64_t K, uint64_t B, uint64_t M, uint64_t X) {
    uint64_t days_wo_h_1 = X / A;
    uint64_t holidays_1 = days_wo_h_1 / K;
    uint64_t wdays_1 = days_wo_h_1 + holidays_1;

    uint64_t days_wo_h_2 = X / B;
    uint64_t holidays_2 = days_wo_h_2 / M;
    uint64_t wdays_2 = days_wo_h_2 + holidays_2;

    uint64_t prod_1 = Productivity(X, A, K);
    uint64_t prod_2 = Productivity(X, B, M);

    uint64_t l = 0;
    uint64_t r = prod_1 > prod_2 ? prod_1 : prod_2;
    
    while (l <= r) {
        uint64_t m = l + (r - l) / 2;
        if (CheckDays(m, X, A, B, K, M)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return r + 1;
}


void SimpleTest() {
    {
        std::vector<uint64_t> test = {2, 4, 3, 3, 25};
        uint64_t expected = 7;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 1 is OK" << std::endl;
        } else {
            std::cout << "test 1 is FAILED" << std::endl;
            std::cout << "expected: 7, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1, 2, 1, 2, 14};
        uint64_t expected = 13;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 2 is OK" << std::endl;
        } else {
            std::cout << "test 2 is FAILED" << std::endl;
            std::cout << "expected: 13, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {3, 2, 4, 3, 37};
        uint64_t expected = 9;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 3 is OK" << std::endl;
        } else {
            std::cout << "test 3 is FAILED" << std::endl;
            std::cout << "expected: 9, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {4, 2, 4, 2, 36};
        uint64_t expected = 9;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 4 is OK" << std::endl;
        } else {
            std::cout << "test 4 is FAILED" << std::endl;
            std::cout << "expected: 9, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1, 4, 2, 3, 19};
        uint64_t expected = 9;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 5 is OK" << std::endl;
        } else {
            std::cout << "test 5 is FAILED" << std::endl;
            std::cout << "expected: 9, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {23, 3, 13, 5, 150};
        uint64_t expected = 6;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 6 is OK" << std::endl;
        } else {
            std::cout << "test 6 is FAILED" << std::endl;
            std::cout << "expected: 6, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1, 2, 1, 2, 1};
        uint64_t expected = 1;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 7 is OK" << std::endl;
        } else {
            std::cout << "test 7 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1, 2, 1, 2, 2};
        uint64_t expected = 1;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 8 is OK" << std::endl;
        } else {
            std::cout << "test 8 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1, 2, 1, 2, 3};
        uint64_t expected = 3;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 9 is OK" << std::endl;
        } else {
            std::cout << "test 9 is FAILED" << std::endl;
            std::cout << "expected: 3, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {5, 5, 5, 5, 5};
        uint64_t expected = 1;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 10 is OK" << std::endl;
        } else {
            std::cout << "test 10 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {5, 5, 5, 5, 1};
        uint64_t expected = 1;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 11 is OK" << std::endl;
        } else {
            std::cout << "test 11 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {5, 5, 5, 5, 3};
        uint64_t expected = 1;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 12 is OK" << std::endl;
        } else {
            std::cout << "test 12 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {4, 2, 5, 3, 11};
        uint64_t expected = 2;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 13 is OK" << std::endl;
        } else {
            std::cout << "test 13 is FAILED" << std::endl;
            std::cout << "expected: 2, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<uint64_t> test = {1000000000, 1000000000000000000, 1000000000, 1000000000000000000, 1000000000000000000};
        uint64_t expected = 2;
        if (BinarySearch(test[0], test[1], test[2], test[3], test[4]) == expected) {
            std::cout << "test 13 is OK" << std::endl;
        } else {
            std::cout << "test 13 is FAILED" << std::endl;
            std::cout << "expected: 2, " << "got: " << BinarySearch(test[0], test[1], test[2], test[3], test[4]) << std::endl;
        }
        std::cout << std::endl;
    }
}


int main() {
    uint64_t A, K, B, M, X;
    std::cin >> A >> K >> B >> M >> X;
    // SimpleTest();
    std::cout << BinarySearch(A, K, B, M, X) << std::endl; 
    
    return 0;
}


