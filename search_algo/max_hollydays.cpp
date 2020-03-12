#include <iostream>

int main() {
    uint64_t N;
    uint64_t M;
    uint64_t w;
    std::cin >> N >> M >> w;
    uint64_t wc = (M + w - 1) / w;
    uint64_t last = M - (wc - 1) * w;
    uint64_t W = (N - last) / (wc - 1);
    uint64_t h = W - w;
    std::cout << h << std::endl;
    return 0;
}


/*
#include <iostream>

int BinarySearch(uint64_t days_total, uint64_t min_w_d, uint64_t working_days_per_w) {
    uint64_t l = 0;
    uint64_t r = days_total - min_w_d;

    while (l <= r) {
        uint64_t holidays_per_week = l + (r - l) / 2;
        uint64_t week_count = days_total / (working_days_per_w + holidays_per_week);
        uint64_t last_week = days_total % (working_days_per_w + holidays_per_week);


        if (week_count * working_days_per_w + last_week < min_w_d) {
            r = holidays_per_week - 1;
        } else {
            l = holidays_per_week + 1;
        }
    
    }

    return l - 1;
}

int main() {
    uint64_t days_total;
    uint64_t min_working_days;
    uint64_t working_days_per_week;
    std::cin >> days_total >> min_working_days >> working_days_per_week;
    std::cout << BinarySearch(days_total, min_working_days, working_days_per_week) << std::endl;
    return 0;
}
*/