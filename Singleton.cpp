//

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
private:
    
    Singleton& operator=(const Singleton&) = delete; //so that "=" operator cannot be used to assignment operator 
    Singleton(const Singleton &) = delete; //so that copy consttructor cannot be used
    Singleton()
    {}
   // static Singleton* obj;
    static mutex m;
    static int val;

public:
    static void getInstance()
    {
        static Singleton* obj;// = nullptr; //just remove ststic and see the output
        cout << "Address of object: " << obj << endl;
        if (obj == nullptr)
        {
            //m.lock(); //it makes the creating instance thread safe
            //lock_guard <mutex> lock(m);
            obj = new Singleton();            
            //m.unlock();
            cout << ++val<<endl;
            cout << "Address of object: " << obj << endl;
        }
        //return obj;
    }

    void increaseVal() 
    {
        val++;
    }

    //to check whether val is changed if we create several objects
    int show()
    {
        return val;
    }

};

//Singleton* Singleton::obj = nullptr;
mutex Singleton::m;
int Singleton::val = 100;


int main()
{
    /*Singleton* ptr = Singleton::getInstance();
    
    cout << ptr<<endl;
    cout << ptr->show()<<endl;
    
    */
    thread t1(Singleton::getInstance);
    thread t2(Singleton::getInstance);
    thread t3(Singleton::getInstance);
    t1.join();
    t2.join();
    t3.join();
    
    /*
    Singleton* ptr2 = Singleton::getInstance();
    cout << ptr2<<endl;
    cout << ptr2->show() << endl;*/
    
    
    return 0;


}
