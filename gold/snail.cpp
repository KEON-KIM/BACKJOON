//#1022
#include<iostream>
#include<cmath>

using namespace std;

int r1,c1,r2,c2,x,y;
int map[50][5];

int gen_corner(int x, int y, int cmp)
{
	if ((x > 0 && x > y) || (y < 0 && x > y) || ( abs(x) == abs(y) && (y < 0 && x > 0) ) )  // south_line || west_line
		return pow(cmp*2+1,2) - (cmp * 2);
	
	else if ((x < 0 && x < y)||(y > 0 && x < y) || (abs(x) == abs(y) && (y > 0 && x < 0) ) ) // north_line || east_line
		return pow(cmp*2+1,2) - ( (cmp * 2) * 3 );
	
	else{
		if(x < 0)
			return pow(abs(cmp*2)+1,2) - ( (cmp * 2) * 2 );
		
		else
			return pow(cmp*2+1,2);	
	}
}
int solution(int x, int y, int cmp)
{
	int corner = gen_corner(x,y, cmp);
	if( x > y )
	{
		if(x > 0 && (abs(x) >= abs(y)) )// south
			return corner + (cmp + y);

		else if(y < 0 && (abs(x) < abs(y)) ) // west
			return corner - (cmp - x);
		
	}
	else if(x < y)
	{
		if(x < 0 && abs(x) >= abs(y)) // north
			return corner + (cmp - y);

		else if(y > 0 && abs(x) < abs(y)) // east 
			return corner - (cmp + x);
	}
	else // corner
		return corner;
}

int main()
{
	int cmp,size = 0;
	string blink = "";
	
	cin >> r1 >> c1 >> r2 >> c2;
	for(int i = 0, r = r1; r <= r2; r++,i++)
	{
		for(int j = 0, c = c1; c <= c2; c++, j++)
		{
			if(r==c && r== 0) map[i][j] = 1;
			cmp = (abs(r)>abs(c))?r:c;
			map[i][j] = solution(r,c,abs(cmp));
			
			if(to_string(map[i][j]).size() > size) size = to_string(map[i][j]).size();
		}
	}
	int x = r2 - r1, y = c2 - c1; // Total length

	//print
	for(int i = 0; i <= x; i++)
	{
		for(int j = 0; j <= y; j++)
		{
			blink = "";
			int tmp = size - to_string(map[i][j]).size();
			if(tmp)
			{
				for(int k = 0; k < tmp; k++) blink += " ";
				cout << blink << map[i][j] << " ";
			}
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}