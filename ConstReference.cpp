#include <iostream>
#include<string>
using namespace std;

/*
int main()
{
	 //const int i = 10;
	//int& j = i; // this is not allowed because of binding error
	int i = 10, k = 5;
	const int& j = i;
	
	 i = 25;
	//j = k;
	cout << "i = " << i << "	j = " << j<<endl;
	//j = 20;
	cout << "i = " << i << "	j = " << j << endl;
	return 0;
}

*/



//The same applies to string values too

const string fun(string str)
{
	return str + "world";
}
int main()
{
	 string str = "Hello ";
	  const string fun(string);

	  const string& str2 = str;
	  const string& str3 = str2;// fun(str);
	  //str3 = str2;
	  
	
	 string str1 = " Cool"; //this is not similar to const int var = int var, where once const defined with left side variable we cannot change right side's variable value
	
	cout << str<<str2<<endl;
	//str2 = str3;
//str2 = str1;
	str = str + "Namaste";
	cout << str<< str3<< endl;
	return 0;
}

 
