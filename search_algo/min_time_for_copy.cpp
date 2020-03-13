#include <vector>
#include <iostream>
#include <utility>
#include <random>
#include <string>


bool CheckPages(int time, int N, int max, int min) {
    if (time < min) {
        return false;
    }
    time -= min;
    int p1 = time / max;
    int p2 = time / min;
    return p1 + p2 + 1 >= N;
}

int SearchMinTime(int N, int x, int y) {
    if (x < y) {
        std::swap(x, y);
    }
    int l = 0;
    uint64_t r = N * x;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (CheckPages(m, N, x, y)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return r + 1;
}


std::string RedText(std::string& text) {
    return "\033[1;31m" + text + "\033[0m";
}

std::string GreenText(std::string& text) {
    return "\033[1;32m" + text + "\033[0m";
}

std::string YellowText(std::string& text) {
    return "\033[1;33m" + text + "\033[0m";
}

void AutoTest() {
    std::mt19937_64 eng{std::random_device{}()};
    std::uniform_int_distribution<> pages{1, 200000000};
    std::uniform_int_distribution<> x{1, 10};
    std::uniform_int_distribution<> y{1, 10};
    
    for (size_t i = 0; i < 1000; ++i) {
        int p = pages(eng);
        int xPrint = x(eng);
        int yPrint = y(eng);
        if (xPrint < yPrint) {
            std::swap(xPrint, yPrint);
        }
        int expected = ((SearchMinTime(p, xPrint, yPrint) - yPrint) / xPrint) + 
                        ((SearchMinTime(p, xPrint, yPrint) - yPrint) / yPrint) + 1;
        std::string s = "Test " + std::to_string(i + 1);
        std::cout << RedText(s) << std::endl;
        std::cout << p << " " << xPrint << " " << yPrint << std::endl;
        std::string success = "Test #" + std::to_string(i + 1) + " OK!";
        std::string error = "Test #" + std::to_string(i + 1) + " ERROR!";
        std::string exp = std::to_string(p);
        std::string got = std::to_string(expected);
        if (p == expected) {
            std::cout << GreenText(success) << std::endl;
        } else {
            std::cout << RedText(error) << std::endl;
            std::cout << "Expected: " << YellowText(exp) << ", got: " << YellowText(got) << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    int N, x, y;
    std::cin >> N >> x >> y;
    // SimpleTest();
    // AutoTest();
    std::cout << SearchMinTime(N, x, y) << std::endl;
    return 0;
}