#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> cmp)
{
	vector<int> temp;
	for(int i = 0; i < cmp[cmp.size()-1].size(); i++)
	{
		if(cmp[cmp.size()-1][i] == 1) return 0;
		else
		{
			if(cmp[cmp.size()-1][i]%3 == 0) {
				temp.push_back(cmp[cmp.size()-1][i]/3);
				if(cmp[cmp.size()-1][i]/3 == 1) return cmp.size();
			}
					
			if(cmp[cmp.size()-1][i]%2 == 0){
				temp.push_back(cmp[cmp.size()-1][i]/2);	
				if(cmp[cmp.size()-1][i]/2 == 1) return cmp.size();
			} 
			if(cmp[cmp.size()-1][i] > 1){
				temp.push_back(cmp[cmp.size()-1][i] -1);
				if(cmp[cmp.size()-1][i] -1 == 1) return cmp.size();
			}
		}
		
	}
	cmp.push_back(temp);
	return solution(cmp);
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> cmp = {{N}};
	
	cout << solution(cmp) << endl;
	
	return 0;
}