#include<iostream>
#include<vector>

using namespace std;

// typedef struct dic
// {
// 	float distance; int speed; int x; int y; 
// }dic;

// int main()
// {
// 	dic test;
// 	test.speed = 3;
// 	cout << test.speed << endl;

// 	vector<dic> testdic;
// 	testdic.push_back(test);

// 	cout << " FUCK : "<<testdic[0].speed << endl;
// }
void iterprint(vector<int> &v)
{
	vector<int> :: iterator iter = v.begin();
	for(iter = v.begin(); iter != v.end(); ++iter)
	{
		if(*iter == 3)
		{
			v.erase(iter);
		}
		cout << *iter << "|";
	}
	cout << endl;
}

void forprint(vector<int> &v)
{
	for(int j = 0; j < v.size(); j++)
	{
		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] == 2)
			{
				v.erase(v.begin()+i);
			}
			cout << v[i] << "|";
		}
		cout << endl;
	}
		

}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.push_back(5);

	forprint(v);
	iterprint(v);
	return 0;
}