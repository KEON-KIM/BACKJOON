// #14226
#include<iostream>
#include<queue>
#include<deque>
#include<vector>

#define MAX 1001

using namespace std;
int n, cost[MAX], result;



int minValDivisor(int x)
{
	int minimum = 987654321;
	vector<int> tmp;
	for(int i = 2; i < x; i++)
		if(x%i == 0)
			tmp.push_back(i);

	

	if(tmp.size() > 0)
	{
		// cout << (tmp.size()%2 == 0) << endl;
		// cout << tmp.size() << endl;
		int i=0, j = tmp.size()-1;
		while(i < j)
		{
			cout <<"!VALUE : "  << x<<" LOW : " <<cost[tmp[i]] + cost[tmp[j]] << " I : " << tmp[i] << " J : " << tmp[j] << endl;
			minimum = min(minimum, cost[tmp[i]] + cost[tmp[j]]);
			i++;
			j--;
		}
		// cout << i << endl;
		if(tmp.size()%2!=0 ){
			cout <<"@VALUE : "  << x<<" LOW : " <<cost[tmp[i]] + cost[tmp[j]] << " I : " << tmp[i] << " J : " << tmp[j] << endl;
			minimum = min(minimum, cost[tmp[i]] + cost[tmp[j]]);
		}
	}

	// // minimum = min(minimum, x);
	cout << "MINIMUM : " << minimum << endl; 
	return  min(minimum, x);
}

void bfs()
{
	int cur, time;
	deque<int> Que;

	Que.push_back(1);
	// visited[1] = 1;

	// for(int i = 1; i <= 3; i++)
	// cost[1] = 0;

	while(!Que.empty())
	{
		cur = Que.front();
		// time = Que.front().second;
		Que.pop_front();
		cout << "CURRENT : " << cur << endl;
		
		if(cur == n)
			return;	
		
		// if(cur*2 < MAX){
		// 	if (!cost[cur*2])
		// 	{
		// 		cost[cur*2] = cost[cur] + 2;
		// 		Que.push_front(cur* 2);
		// 	}
		// 	else{
		// 		cost[cur*2] = min(cost[cur] + 2, cost[cur*2]);
		// 		Que.push_front(cur*2);
		// 	}
			
		// }
		if(cur * 2 < MAX && !cost[cur*2])
		{
			// cost[cur * 2] = minValDivisor(min(cur*2, cost[cur]+2));
			cost[cur * 2] = min(minValDivisor(cur*2), cost[cur]+2);
			// cout << cost[cur*2];
			Que.push_front(cur*2);
		}
		if(cur-1 > 0 && !cost[cur-1])
		{
			// cost[cur-1] = minValDivisor(min(cur-1, cost[cur]+1));
			cost[cur-1] = min(minValDivisor(cur-1), cost[cur]+1);
			// cout << cost[cur-1];
			Que.push_back(cur-1);
		}
		// if(cur - 1 > 0 )
		// {
		// 	if(cur-1 != 3)
		// 	{
		// 		if(!cost[cur-1])
		// 		{
		// 			cost[cur-1] = cost[cur] + 1;
		// 			Que.push_back(cur-1);
		// 		}
		// 		else
		// 		{
		// 			cost[cur-1] = min(cur,min(cost[cur] + 1, cost[cur-1]));
		// 			Que.push_back(cur-1);
		// 		}
		// 	} 
		// 	else
		// 	{
		// 		cost[cur - 1] = 3;
		// 		Que.push_back(cur-1);
		// 	}

			
		// }

	}
}


int main()
{
	cin >> n;

	bfs();

	cout << cost[n] << endl;
	return 0;
}