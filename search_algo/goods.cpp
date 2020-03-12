#include <iostream>


int main() {
    int sum, first_product_price, second_product_price;
    std::cin >> sum >> first_product_price >> second_product_price;
    int set_count = 0;
    int first_product_count = sum / first_product_price;
    int second_product_count = sum / second_product_price;
    if (first_product_count >= second_product_count) {
        for (int i = first_product_count; i >= 0; --i) {
            if ((sum - i * first_product_price) % second_product_price == 0) {
                set_count++;
            }
        }
    } else {
        for (int i = second_product_count; i >= 0; --i) {
            if ((sum - i * second_product_price) % first_product_price == 0) {
                set_count++;
            }
        }
    }

    std::cout << set_count << std::endl;

    return 0;
}