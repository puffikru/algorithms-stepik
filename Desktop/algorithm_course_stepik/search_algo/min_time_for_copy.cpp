#include <iostream>
#include <vector>
#include <utility>


int NOD(int a, int b){
    while (a != b){
        if (a > b){
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int NOK(int a, int b){
    return abs(a * b) / NOD(a, b);
}

int SearchMinTime(int N, int x, int y) {
    int max = x > y ? x : y;
    int min = x < y ? x : y;

    int first_page_count = 1;
    int first_page_time = first_page_count * min;

    int pages_count = x + y;
    int pages_time = x * y;

    int main_part_pages = N - first_page_count;
    int main_part_time = 0;

    int nok = NOK(x, y);

    int max_pages_count = nok / min; 
    int min_pages_count = nok / max;

    main_part_time = (main_part_pages / (min_pages_count + max_pages_count) * nok);

    int last_pages_count = 0;
    int last_pages_time = 0;

    

    if (main_part_pages % (min_pages_count + max_pages_count) > 0) {
        last_pages_count = main_part_pages % (min_pages_count + max_pages_count);
        // std::cout << last_pages_count << std::endl;
        last_pages_time = last_pages_count >= (min_pages_count + max_pages_count) ?
         last_pages_count / (min_pages_count + max_pages_count) * nok : last_pages_count * min;
        // std::cout << last_pages_time << std::endl;
    }

    /*

    */

    // if (main_part_pages % nok > 0) {
    //     last_pages_count = main_part_pages % nok;
    //     // std::cout << last_pages_count << std::endl;
    //     last_pages_time = last_pages_count >= nok ?
    //      last_pages_count / nok : last_pages_count * min;
    //     // std::cout << last_pages_time << std::endl;
    // }

    int total_min_time = first_page_time + main_part_time + last_pages_time;
    // std::cout << total_min_time << std::endl;
    return total_min_time;
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
    int N, x, y;
    // std::cin >> N >> x >> y;
    SimpleTest();
    // std::cout << SearchMinTime(N, x, y) << std::endl;
    return 0;
}



