#include<iostream>
int main(int argc, char* argv[])
{
	int i;
	std::cout << "The args count: "<<argc<<std::endl;
	for (i=0;i<argc;i++)
	{
		std::cout <<"Value of argv: "<<argv[i]<< std::endl;
	}
	
}