#include <iostream>

int main() {
    int last_before_number = 0;
    int last_number = 1;

    for(int i = 0; i < 17; i++) {
        int result = last_before_number + last_number;
        std::cout << result << std::endl;
        last_before_number = last_number;
        last_number = result;       

    }
    
}