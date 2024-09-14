// seekg_seekp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
//using namespace std;


int main()
{
    /*int pos;
    //std::streampos pos;
    std::ifstream fin;
    fin.open("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\test.txt", std::ios:: ate| std::ios::app);
    pos = fin.tellg(); // returns a int value, I have done this for checking check
    std::cout << pos;
    std::cout << "\n"<<(char)fin.get();
    std::cout << (char)fin.get();
    std::cout << '\n'<<fin.tellg();
    fin.seekg(6);
    std::cout << "\n" << fin.tellg();
    std::cout << "\n" << (char)fin.get();
    fin.seekg(2, std::ios_base::cur);
    std::cout << "\n" << fin.tellg();
    std::cout << "\n" << (char)fin.get();
    fin.seekg(2, std::ios_base::cur);
    std::cout << "\n" << fin.tellg();
    std::cout << "\n" <<(char) fin.get();
    fin.seekg(0, std::ios_base::end);
   // std::cout << "\n" << (char)fin.get();
    fin.seekg(0);
    std::cout << "\n" << (char)fin.get();
    */

    
    
    std::ofstream fout;
    fout.open("C:\\Users\\Subrata.Shil\\Desktop\\LetUsC++\\CfileOpen\\test1.txt", std::ios_base::ate | std::ios_base::app);
    fout.seekp(0, std::ios_base::end);
    std::cout << fout.tellp();
    fout << " Hero"; 
    fout.tellp();
    fout.close(); //if you dont use close function the editing will nat be saved. The file should be closed if it is already existing
    
    
   
    return 0;
}

