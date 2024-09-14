// namespace_examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace test
{
    class subrata
    {
    private:
        int age;
    public:
        int getAge()
        {
            return age;
        }

        subrata()
        {
            age = 45;
        }
    };

    subrata sub;
}

using namespace test;
int main()
{
   // int a = 50;
//    test::subrata sub;
    std::cout << "\nValue  = "<<test::sub.getAge();

    std::cout << "\nValue  = " << 2*sub.getAge();

}
