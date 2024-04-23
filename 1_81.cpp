#include <iostream>
#include <fstream>
#include <set>

int main() {
    int a = 1;
    int b = 999 * 999;

    std::cout << (static_cast<float>(a) / static_cast<float> (b)) << "\n";

    std::ofstream file_stream;
    file_stream.open("1_81.txt");

    bool has_decimal = false;
    std::set<int> remainders = {}; 

    int i = 0;
    while (a != 0) {
        if (has_decimal) {
            a *= 10;
        }

        int c = a / b;
        a -= c * b;

        if (remainders.count(a) == 1) {
            // Repeating decimal.
            std::cout << "\n" << "Found repeating decimal.";
            break;
        }

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

        remainders.insert(a);

        i++;
    }

    std::cout << "\n";
    file_stream << "\n";

    file_stream.close();
}
