#include <iostream>
#include <fstream>

int main() {
    int a = 1;
    int b = 99 * 99;

    std::cout << (static_cast<float>(a) / static_cast<float> (b)) << "\n";

    std::ofstream file_stream;
    file_stream.open("1_81.txt");


    bool has_decimal = false;

    int i = 0;
    int max_iters = 1'000;

    while ((a != 0) and (i < max_iters)) {
        if (has_decimal) {
            a *= 10;
        }

        int c = a / b;
        a -= c * b;

        if ((c == 0) and (!has_decimal)) {
            if (i == 0) {
                std::cout << "0";
                file_stream << "0";
            }

            std::cout << ".";
            file_stream << ".";
            has_decimal = true;
            continue;
        }

        std::cout << c;
        file_stream << c;

        i++;
    }

    std::cout << "\n";
    file_stream << "\n";

    file_stream.close();
}
