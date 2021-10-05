#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	int x,y, dis;
	vector<pair<int, int>> cache;
	for(int i = 0; i < N ; i++)
	{
		cin >> x >> y;
		cache.push_back(make_pair(x,y));
	}
	for(int i = 0; i < N; i++)
	{
		x = cache[i].first;
		y = cache[i].second;
		dis = y - x ;
		if(dis <= 3) cout << dis << endl;
		else if(dis < 5) cout << 3 << endl;
		else
		{
			int a = sqrt(dis);
			if(a < 3 && dis < 7) cout << 4 << endl;
			else if(pow(a,2) != dis)
			{
				// int a = sqrt()
				int b = pow(a+1,2) - pow(a,2); 
				int c = (b-1)/2 + 1;

				if (pow(a+1,2) - (a+1) < dis) cout <<  (a*2) +1 <<  endl;
				else cout <<  (a*2) <<  endl;
			}
			else 
			{
				cout << (a*2)-1  << endl;
			}
		}

	}

	return 0;
}