#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int x,y,w,h;
	vector<int> temp;
	cin >> x >> y >> w >> h;

	temp.push_back(x);
	temp.push_back(y);
	temp.push_back(w-x);
	temp.push_back(h-y);

	sort(temp.begin(), temp.end(), greater<int>());

	cout << temp[3] << endl;
	return 0;
}