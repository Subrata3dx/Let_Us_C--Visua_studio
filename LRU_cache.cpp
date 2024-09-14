// LRU_cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <initializer_list>
#include <unordered_map>
using namespace std;


class LRUCache
{
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size)
        {
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({ key,value });
        m[key] = l.begin();
    }
};


int main()
{
    
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout<< obj->get(1)<<endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    
}
