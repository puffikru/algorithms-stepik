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

    // Получаем кол-во и время 1 копии
    int first_page_count = 1;
    int first_page_time = first_page_count * y;

    // Находим нок
    int nok = NOK(x, y);

    // Считаем сколько страниц напечатает каждый принтер за nok секунд
    int page_count_min = nok / x;
    int page_count_max = nok / y;

    // Считаем сколько страниц напечатается при полной загрузке обоих принтеров и время печати
    int main_part_pages = (N - first_page_count) / (page_count_min + page_count_max);
    int main_part_time = main_part_pages * nok;

    // Считаем остаток страниц, которого не хватает для полной загрузки обоих принтеров
    int last_part_pages = (N - first_page_count) % (page_count_min + page_count_max);

    // Если остаток страниц больше, чем максимальное кол-во страниц может напечатать быстрый принтер
    int last_pages_time = 0;
    if (last_part_pages > page_count_max) {
        // То оставшееся время будет равно максимальному кол-ву страниц * на время быстрого принтера
        last_pages_time = page_count_max * y;
    } else {
        // Если нет, тогда просто умножаем кол-во оставшихся страниц на время быстрого принтера
        last_pages_time = last_part_pages * y;
    }

    // Общее время складывается из времени 1й страницы, основной части и остатка
    int total_min_time = first_page_time + main_part_time + last_pages_time;
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
    std::cin >> N >> x >> y;
    // SimpleTest();
    std::cout << SearchMinTime(N, x, y) << std::endl;
    return 0;
}