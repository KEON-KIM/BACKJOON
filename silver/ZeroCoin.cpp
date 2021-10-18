#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N, K, coin[10];
vector<int> answer;

int cal(int money, int index, int count)
{
	if(index < 0 ) return -1;

	int mok = money==0? 0: money/coin[index], remain = money==0 ? 0 : money%coin[index];
	if(remain == 0) return count+mok;
	else return cal(money - (coin[index] * mok), index-1, count + mok);
	
}

int main()
{	cin >> N >> K;
	int index = N;
	for(int i = 0; i < N; i++){
		cin >> coin[i]; 
		if(coin[i] > K) index = i; 
	}
	for(int i = index - 1; i >= 0; i--)
	{
		int cmp = cal(K, i, 0);
		if(cmp > 0)answer.push_back(cmp);
	}

	sort(answer.begin(), answer.end());
	if(answer.size()>0)cout << answer[0] <<endl;
	else cout << -1 << endl;

	return 0;
}