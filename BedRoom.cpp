#include<iostream>
using namespace std;

class BedRoom
{
	int bed, chair, tv;
public:
	BedRoom()
	{
		bed = 1;
		chair = 1;
		tv = 1;
	}
	void updateItems(int x, int y)
	{
		chair = x;

	}
	void getItems(void)
	{
		cout << "The bed room items are:";
		cout << "Bed: " << bed << endl;
		cout << "Chair: " << chair << endl;
		cout << "TV: " << tv << endl;
	}
};