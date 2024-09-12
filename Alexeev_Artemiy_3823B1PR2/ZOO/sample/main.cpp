#include"Animals.h"
int main(){
    Animals* a;
    a = new Cat("Steve","Persian",13,"home");
    a->get_age();
    a->get_place();
    a->give_voice();
}