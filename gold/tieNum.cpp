#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, zero = 0;
vector<int> minusVec, plusVec;
vector<int> answer;
void print()
{
	FOR(i, answer.size())
		cout << answer[i] << endl;
	cout << endl;
	cout << "===" << endl;
}
int main()
{
	cin >> N;
	int input;
	FOR(i, N){
		cin >> input;
		if(!input)
			zero++;
		else if(input == 1)
			answer.push_back(input);
		else if (input < 0) 
			minusVec.push_back(input);
		else
			plusVec.push_back(input);
	}
	sort(minusVec.begin(), minusVec.end());
	sort(plusVec.begin(), plusVec.end(), greater<int>());
	
	int pSize = plusVec.size();
    if (pSize%2) 
        answer.push_back(plusVec[pSize-1]);

    for (int i = 0; i < pSize - 1; i+=2) 
        answer.push_back(plusVec[i] * plusVec[i+1]);
   
    int mSize = minusVec.size();
    if (mSize%2) {
        if (zero) 
            zero--;
        else 
            answer.push_back(minusVec[mSize-1]);
    }

    for (int i = 0; i < mSize-1; i += 2) 
        answer.push_back(minusVec[i] * minusVec[i+1]);
 
   
    int result = 0;
    FOR(i, answer.size())
    	result += answer[i];
    cout << result;
	return 0;
}