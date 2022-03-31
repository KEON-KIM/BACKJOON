//#1451
//@Reference doorrock <https://doorrock.tistory.com/9>
#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
int main() {
	
	int N,M;
	cin >> N >> M;
	
	vector<int> temp1;
	vector<int> temp2;
	for(int i=0;i<N;i++){
		int input;
		cin >> input;
		if(input < 0) temp1.push_back(input);
		else temp2.push_back(-input);
	}
	
	if(!temp1.empty()) sort(temp1.begin(), temp1.end());
	if(!temp2.empty()) sort(temp2.begin(), temp2.end());
	
	int result=0;
	if(!temp1.empty())
	{
		for(int i=0;i<temp1.size();i=i+M){
			int v = -temp1[i];
			result+=2*v;
		}		
	}
	
	if(!temp2.empty())
	{
		for(int i=0;i<temp2.size();i=i+M){
			int v = -temp2[i];
			result+=2*v;
		}
	}
	
	if(temp1[0] < temp2[0]) result -= -temp1[0];
	else result -= -temp2[0];

	cout << result << endl;
	return 0;
}

/*// #1461
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51

using namespace std;

int N, M, result = 0;
vector<int> leftVector;
vector<int> rightVector;
int main()
{

	cin >> N >> M;
	for(int i = 0 ; i < N; i++)
	{
		int input;
		cin >> input;
		if(input < 0) leftVector.push_back(abs(input));
		else rightVector.push_back(input);
	}

	int lpoint = 0, rpoint = 0;
	sort(leftVector.begin(), leftVector.end(), greater<int>());
	sort(rightVector.begin(), rightVector.end(), greater<int>());
	if(leftVector[0] < rightVector[0]){
		rpoint += M;
		result += rightVector[0];
	}
	else{
		lpoint += M;
		result += leftVector[0];
	}
	bool isLeftEnd = false, isrightEnd = false;
	while(!isLeftEnd)
	{
		result += leftVector[lpoint] * 2;
		lpoint+=M;

		if(lpoint >= leftVector.size()-1){
			isLeftEnd = true;
			result += leftVector[lpoint] * 2;
		}
	}
	while(!isrightEnd)
	{
		result += rightVector[rpoint] * 2;
		rpoint+=M;

		if(rpoint >= rightVector.size()-1){
			isrightEnd = true;
			result += rightVector[rpoint] * 2;
		}
	}
	cout << result << endl;
	return 0;
}
*/