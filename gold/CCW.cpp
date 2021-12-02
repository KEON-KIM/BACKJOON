//#11758
#include<iostream>
#include<cmath>
#include<vector>
#include<stdio.h>

using namespace std;

vector<pair<float, float>> cache;
// int solution()
// {
// 	float a1, a2, b;
// 	a1 = (cache[1].first - cache[0].first) == 0 ? 0 : 
// 		(cache[1].second - cache[0].second) / (cache[1].first - cache[0].first);
// 	a2 = (cache[2].first - cache[1].first) == 0 ? 0 : 
// 		(cache[2].second - cache[1].second) / (cache[2].first - cache[1].first);
// 	b = cache[0].second - a1*cache[0].first;

// 	if (cache[0].first == cache[1].first && cache[1].first == cache[2].first) return 0;
// 	if (cache[0].second == cache[1].second && cache[1].second == cache[2].second) return 0;
// 	if (a1 == a2) return 0;
	
// 	if(a1*cache[2].first+b < cache[2].second) return 1;
// 	else if (a1*cache[2].first+b > cache[2].second) return -1;
// 	else return 0;
	
	
// 	// cout << "LEAN 1 : " << lean1  << " LEAN2 : " << lean2 <<endl;
// 	// printf("LEAN1 : %.2f, LEAN2 : %.2f\n", a, b);
// 	// return 1;
// }
int CCW()
{
	double x1 = cache[0].first, y1 = cache[0].second, x2 = cache[1].first, y2 = cache[1].second, x3 = cache[2].first, y3 = cache[2].second;
	double ccw = (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
	if(ccw > 0) return 1;
	else if (ccw < 0) return -1;
	else return 0;
}
 

int main()
{
	float a, b;
	for(int i = 0; i < 3; i++){
		cin >> a >> b;
		cache.push_back(make_pair(a, b));
	}

	cout << CCW() << endl;
	
	return 0;
}