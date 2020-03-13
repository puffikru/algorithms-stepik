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
    if (x < y) {
        std::swap(x, y);
    }

    // Если кол-во страниц == 1, то время равно минимуму.
    if (N == 1) {
        return y;
    }

    // Получаем кол-во и время 1 копии
    int first_page_count = 1;
    int first_page_time = first_page_count * y;

    // Находим нок
    int nok = NOK(x, y);

    // Считаем сколько страниц напечатает каждый принтер за nok секунд
    int page_count_min = nok / x;
    int page_count_max = nok / y;

    int main_part_pages = 0;
    int main_part_time = 0;

    // Если кол-во оставшихся страниц больше или равно, чем сумма страниц, которые можно распечатать на 2х принтерах
    if (N - first_page_count >= page_count_min + page_count_max) {
        // Считаем сколько страниц напечатается при полной загрузке обоих принтеров и время печати
        main_part_pages = (N - first_page_count) / (page_count_min + page_count_max);
        main_part_time = main_part_pages * nok;
    } else {
        // Если меньше, то загружаем принтеры последовательно
        main_part_pages = N - first_page_count;
        main_part_time = y;
        main_part_pages--;
        int max = x;
        while (main_part_pages > 0) {
            main_part_time += y;
            main_part_pages--;
            // Если сумма секунд больше, чем скорость медленного принтера, 1 страницу печатаем на нем
            if (main_part_time >= max) {
                max += x;
                main_part_pages--;
            }
        }
        // Тогда время равно основное + 1 страница
        return main_part_time + first_page_time;
    }

    // Считаем остаток страниц, которого не хватает для полной загрузки обоих принтеров
    int last_part_pages = (N - first_page_count) % (page_count_min + page_count_max);

    // Если остаток страниц больше, чем максимальное кол-во страниц может напечатать быстрый принтер
    int last_pages_time = 0;
    // Если есть остаток
    // if (last_part_pages > 0) {
    //     if (last_part_pages > page_count_max) {
    //         // То оставшееся время будет равно максимальному кол-ву страниц * на время быстрого принтера
    //         last_pages_time = page_count_max * y;
    //     } else {
    //         // Если нет, тогда просто умножаем кол-во оставшихся страниц на время быстрого принтера
    //         last_pages_time = last_part_pages * y;
    //     }
    // }

    if (last_part_pages > 0) {
        if (last_part_pages < y) {
            // last_pages_time = y;
            // last_part_pages--;
            // int max = x;
            // while (last_part_pages > 0) {
            //     last_pages_time += y;
            //     last_part_pages--;
            //     // Если сумма секунд больше, чем скорость медленного принтера, 1 страницу печатаем на нем
            //     if (last_pages_time >= max) {
            //         max += x;
            //         last_part_pages--;
            //     }
            // }
            if (last_part_pages % 2 == 0) {
                int p1 = last_part_pages / 2 * x;
                int p2 = last_part_pages / 2 * y;
                if (p1 - p2 < y) {
                    last_pages_time = p1;
                } else {
                    while (p1 - p2 >= y) {
                        p1 -= x;
                        p2 += y;
                    }
                    last_pages_time = p1 > p2 ? p1 : p2;
                }
            } else {
                int p1 = last_part_pages / 2 * x;
                int p2 = last_part_pages / 2 * y;
                if (p1 - p2 < y) {
                    last_pages_time = p2 + y;
                } else {
                    while (p1 - p2 >= y) {
                        p1 -= x;
                        p2 += y;
                    }
                    last_pages_time = p1 > p2 ? p2 + y : p1 + y;
                }
            }

        } else if (last_part_pages > y && last_part_pages < x) {
            last_pages_time = y;
            last_part_pages--;
            int max = x;
            while (last_part_pages > 0) {
                last_pages_time += y;
                last_part_pages--;
                // Если сумма секунд больше, чем скорость медленного принтера, 1 страницу печатаем на нем
                if (last_pages_time >= max) {
                    max += x;
                    last_part_pages--;
                }
            }
        } else if (last_part_pages > x) {
            if (last_part_pages % 2 == 0) {
                int p1 = last_part_pages / 2 * x;
                int p2 = last_part_pages / 2 * y;
                if (p1 - p2 < y) {
                    last_pages_time = p1;
                } else {
                    while (p1 - p2 >= y) {
                        p1 -= x;
                        p2 += y;
                    }
                    last_pages_time = p1 > p2 ? p1 : p2;
                }
            } else {
                int p1 = last_part_pages / 2 * x;
                int p2 = last_part_pages / 2 * y;
                if (p1 - p2 < y) {
                    last_pages_time = p2 + y;
                } else {
                    while (p1 - p2 >= y) {
                        p1 -= x;
                        p2 += y;
                    }
                    last_pages_time = p1 > p2 ? p2 + y : p1 + y;
                }
            }
        } else if (last_part_pages == y) {
            last_pages_time = last_part_pages * y;
        } else if (last_part_pages == x) {
            last_pages_time = last_part_pages * x;
        }
    }

    // Общее время складывается из времени 1й страницы, основной части и остатка
    return first_page_time + main_part_time + last_pages_time;
}


bool isSlow(int time, int N, int x, int y) {
    if (time > SearchMinTime(N, x, y)) {
        return true;
    }
    return false;
}


int CheckTime(int N, int x, int y) {
    uint64_t l = 0;
    uint64_t r = x * N;
    while (l <= r) {
        uint64_t m = l + (r - l) / 2;
        if (isSlow(m, N, x, y)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l - 1;
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
    {
        std::vector<int> test= {200000000, 5, 4};
        int expected = 444444448;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 12 is OK" << std::endl;
        } else {
            std::cout << "test 12 is FAILED" << std::endl;
            std::cout << "expected: 444444448, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {4, 10, 9};
        int expected = 27;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 13 is OK" << std::endl;
        } else {
            std::cout << "test 13 is FAILED" << std::endl;
            std::cout << "expected: 27, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {200000000, 10, 10};
        int expected = 1000000010;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 14 is OK" << std::endl;
        } else {
            std::cout << "test 14 is FAILED" << std::endl;
            std::cout << "expected: 1000000010, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {28, 9, 8};
        int expected = 125;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 15 is OK" << std::endl;
        } else {
            std::cout << "test 15 is FAILED" << std::endl;
            std::cout << "expected: 125, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {23, 9, 8};
        int expected = 104;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 16 is OK" << std::endl;
        } else {
            std::cout << "test 16 is FAILED" << std::endl;
            std::cout << "expected: 104, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {28, 9, 7};
        int expected = 113;
        if (SearchMinTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 17 is OK" << std::endl;
        } else {
            std::cout << "test 17 is FAILED" << std::endl;
            std::cout << "expected: 113, " << "got: " << SearchMinTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
}

void SimpleTest2() {
    {
        std::vector<int> test= {4, 1, 1};
        int expected = 3;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 1 is OK" << std::endl;
        } else {
            std::cout << "test 1 is FAILED" << std::endl;
            std::cout << "expected: 3, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {5, 1, 2};
        int expected = 4;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 2 is OK" << std::endl;
        } else {
            std::cout << "test 2 is FAILED" << std::endl;
            std::cout << "expected: 4, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {40, 2, 3};
        int expected = 50;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 3 is OK" << std::endl;
        } else {
            std::cout << "test 3 is FAILED" << std::endl;
            std::cout << "expected: 50, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {1, 1, 1};
        int expected = 1;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 4 is OK" << std::endl;
        } else {
            std::cout << "test 4 is FAILED" << std::endl;
            std::cout << "expected: 1, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {2, 1, 1};
        int expected = 2;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 5 is OK" << std::endl;
        } else {
            std::cout << "test 5 is FAILED" << std::endl;
            std::cout << "expected: 2, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 1, 7};
        int expected = 7;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 6 is OK" << std::endl;
        } else {
            std::cout << "test 6 is FAILED" << std::endl;
            std::cout << "expected: 7, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 10, 5};
        int expected = 25;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 7 is OK" << std::endl;
        } else {
            std::cout << "test 7 is FAILED" << std::endl;
            std::cout << "expected: 25, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {7, 10, 2};
        int expected = 12;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 8 is OK" << std::endl;
        } else {
            std::cout << "test 8 is FAILED" << std::endl;
            std::cout << "expected: 12, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {20, 10, 10};
        int expected = 110;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 9 is OK" << std::endl;
        } else {
            std::cout << "test 9 is FAILED" << std::endl;
            std::cout << "expected: 110, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {20, 9, 10};
        int expected = 99;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 10 is OK" << std::endl;
        } else {
            std::cout << "test 10 is FAILED" << std::endl;
            std::cout << "expected: 99, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {21, 10, 9};
        int expected = 108;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 11 is OK" << std::endl;
        } else {
            std::cout << "test 11 is FAILED" << std::endl;
            std::cout << "expected: 108, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {200000000, 5, 4};
        int expected = 444444448;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 12 is OK" << std::endl;
        } else {
            std::cout << "test 12 is FAILED" << std::endl;
            std::cout << "expected: 444444448, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {4, 10, 9};
        int expected = 27;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 13 is OK" << std::endl;
        } else {
            std::cout << "test 13 is FAILED" << std::endl;
            std::cout << "expected: 27, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> test= {200000000, 10, 10};
        int expected = 1000000010;
        if (CheckTime(test[0], test[1], test[2]) == expected) {
            std::cout << "test 14 is OK" << std::endl;
        } else {
            std::cout << "test 14 is FAILED" << std::endl;
            std::cout << "expected: 1000000010, " << "got: " << CheckTime(test[0], test[1], test[2]) << std::endl;
        }
        std::cout << std::endl;
    }
}


int main() {
    int N, x, y;
    // std::cin >> N >> x >> y;
    SimpleTest();
    // SimpleTest2();
    // std::cout << SearchMinTime(N, x, y) << std::endl;
    // std::cout << CheckTime(N, x, y) << std::endl;
    return 0;
}