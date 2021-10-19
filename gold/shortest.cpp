#include<iostream>
#include<map>
#include<vector>
#define MAX 20001;
using namespace std;


int main()
{
	vector<pair<int,int>> insert_;
	insert_.push_back(make_pair(0,6));
	insert_.push_back(make_pair(0,5));
	insert_.push_back(make_pair(0,1));
	map<int, int> test;
	// map<int, int> :: iterator itr;
	for(int i = 0; i < insert_.size(); i++)
	{
		auto itr = test.insert({insert_[i].first, insert_[i].second});
		if (!itr.second){ // not exist
		    itr.first ->second = insert_[i].second;
		}
		else
		{
			if(itr.second > insert_[i].second)
				itr.second = insert_[i].second;
		}
	}
	
	
	test.insert({0,2});
	test.insert({0,3});
	test.insert({0,4});
	
	
	// iter = test.begin();
	cout << test.find(0)->second << endl;
	return 0;
}