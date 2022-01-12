#include<iostream>
#include<queue>
#include<set>

using namespace std;

struct Data
{
    int x, y, z;
    Data(int a, int b, int c)
    {
    	x = a;
    	y = b;
    	z = c;
    }
    bool operator<(const Data &ref) const
	{
		if (x != ref.x){
			if(y != ref.y)
				return y < ref.y;

			return z < ref.z;
		}
		else
		{
			if(y != ref.y)
				return y < ref.y;

			return z < ref.z;
		}
	}
};
 
set<Data> group;
void bfs(int a, int b, int c)
{
	int size, cmp = 0;
	queue<Data> Que;
	Que.push(Data(a, b, c));

	if(!((a+b+c)%3)) 
		cmp = (a + b + c) / 3;

	else 
	{
		cout << 0 << endl;
		return;
	}

	while(!Que.empty() && cmp)
	{
		int x = Que.front().x;
		int y = Que.front().y;
		int z = Que.front().z;
		Que.pop();

		if(cmp == x && cmp == y && cmp == z) {
			cout << 1 << endl;
			return;
		}

		// cout << x << " " << y << " " << z << endl; //DEBUG
		//#1 1,2
		if(x!=y)
		{
			if(x > y)
			{
				size = group.size();
				group.insert(Data(x-y, y*2, z));
				if(group.size() != size && x != y)
					Que.push(Data(x-y, y*2, z));
			}
			else
			{
				size = group.size();
				group.insert(Data(x*2, y-x, z));
				if(group.size() != size && x != y)
					Que.push(Data(x*2, y-x, z));
			}	
		}
		
		//#2 1,3
		if(x != z)
		{
			if(x > z)
			{
				size = group.size();
				group.insert(Data(x-z, y, z*2));
				if(group.size() != size && x != z)
					Que.push(Data(x-z, y, z*2));
			}
			else
			{
				size = group.size();
				group.insert(Data(x*2, y, z-x));
				if(group.size() != size && x != z)
					Que.push(Data(x*2, y, z-x));
			}	
		}
		
		//#3 2,3
		if(y != z )
		{
			if(y > z)
			{
				size = group.size();
				group.insert(Data(x, y-z, z*2));
				if(group.size() != size && z != y)
					Que.push(Data(x, y-z, z*2));
			}
			else
			{
				size = group.size();
				group.insert(Data(x, y*2, z-y));
				if(group.size() != size && z != y)
					Que.push(Data(x, y*2, z-y));
			}
		}
		
	}

	cout << 0 << endl;
}

int main()
{
	int N, M, K;

	cin >> N >> M >> K;

	group.insert(Data(N, M, K));
	bfs(N, M, K);

	return 0;
}