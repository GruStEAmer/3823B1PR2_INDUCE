#include "../include/Animals.h"
int main(){
    Animals* a;
    a = new Dog("12","23",213,"23");
    std::cout << a->get_age();
}