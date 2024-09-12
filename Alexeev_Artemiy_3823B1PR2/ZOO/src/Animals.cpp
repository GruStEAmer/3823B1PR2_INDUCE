#include "Animals.h"

Cat::Cat(string alias, string breed, unsigned int age, string place){
    alias = alias;
    breed = breed;
    age = age;
    place = place;
    type = "cat";
}
int Cat::get_age(){
    return age;
}
void Cat::replace(Animals& a){
    string k = place;
    place = a.get_place();
    a.set_place(k);
}
void Cat::give_voice(){
    std::cout << "Miow";
}
//---------------------------
Dog::Dog(string alias, string breed, unsigned int age, string place)
{
    alias = alias;
    breed = breed;
    age = age;
    place = place;
    type = "dog";
}
int Dog::get_age()
{
    return age;
}
void Dog::replace(Animals &a)
{
    string k = place;
    place = a.get_place();
    a.set_place(k);
}
void Dog::give_voice()
{
    std::cout << "Wof";
}
