// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip>
#include <iostream>
using namespace std;


int main()
{
    int* f;
    
    char* ptr[2];
    int* iarrPtr[10];
    
    char h = '3';
    char j = '5';
    
    ptr[0] = &h;
    ptr[1] = &j;


   // printf("%p\n", &h);

    //cout << &h << endl;

    //cout << setbase(8)<<&h<<endl;

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        iarrPtr[i] = arr + i;
    }
    std::cout << "The array values are: " << endl;
    for (int i = 0; i <= 10; i++)
    {
        cout << *(arr+i)<< "\t";
        

    }

    cout << endl<<"Address:"<<endl;
    
    for (int i = 0; i < 10; i++)
    {
        cout << iarrPtr[i]<< "\t";
        


    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        f = &arr[i];
        cout << *f << "\t";
    }

}



/*
#include <iostream>
#include <string>
using std::cout;
using std::endl;
void print(std::string* url) {
    std::string url_1 = "http://example.com";
    cout << url << endl;
    cout << *url << endl;
    cout << "Adress: " << &url << endl;
    *url = url_1;
    cout << "Adress: " << &url << endl;
    cout << url << endl;
    cout << *url << endl;
}
int main() {

    std::string a = "http://google.com";
    print(&a);
    cout << a << endl;
    cout << &a << endl;
    return 0;
}

*/