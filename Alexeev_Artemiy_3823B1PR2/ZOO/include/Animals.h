#pragma once

#include <string>
#include <iostream>

using std::string;

class Animals{
protected:
    string alias;
    string type;
    string breed;
    unsigned int age;
    string place;
public:
    string get_place(){
        return place;
    }
    void set_place(string p){
        place = p;
    }
    virtual void give_voice() = 0;
    virtual void replace(Animals& a) = 0;
    virtual int get_age() = 0;
};

class Cat:public Animals{
private:

public:
    Cat(string alias, string breed, unsigned int age, string place);
    int get_age();
    void replace(Animals& a);
    void give_voice();
};

class Dog:public Animals{
private:

public:
    Dog(string alias, string breed, unsigned int age, string place);
    int get_age();
    void replace(Animals& a);
    void give_voice();
};

class A{
public:
    int a = 10;
};