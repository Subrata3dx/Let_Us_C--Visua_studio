// SingletonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

class Singleton
{
private:
    static Singleton* instance;
    Singleton();

public:
    static Singleton* getInstance();
};

Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance()
{
    if (instance == NULL)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}

int main()
{
    Singleton* one = Singleton::getInstance();
    Singleton* two = Singleton::getInstance();

    if (one == two)
        std::cout << "Both pointers hold same object";
    else
        std::cout << "They don't hold same object";

    return 0;
}