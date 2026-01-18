#include <iostream>
#include "counter.hpp"




int main() {
    setlocale(LC_ALL, "Russian");
    

    Counter c;
    std::cout << c.get_count() << std::endl;
    c.count_plus();
    std::cout << c.get_count() << std::endl;
    c.multiply_count(19);
    
    Counter c2(500);
    std::cout << c2.get_count() << std::endl;
    c2.reset_count();
    std::cout << c2.get_count() << std::endl;

}