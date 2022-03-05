// #17612
// @Reference yabmoons <https://yabmoons.tistory.com/699>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001
#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
int N, K, answer = 0;

pair<int, int> Customer[MAX];
struct CUSTOMMER
{
	int custom_num;
	int cal_time;
	int cnt_num;
};
 
struct custom_cmp
{
    bool operator()(CUSTOMMER A, CUSTOMMER B)
    {
        if (A.cal_time == B.cal_time)
        	return A.cnt_num > B.cnt_num;
        else
        	return A.cal_time > B.cal_time;
    }
};

bool cmp(CUSTOMMER A, CUSTOMMER B)
{
	if(A.cal_time == B.cal_time)
		return A.cnt_num > B.cnt_num;
	return A.cal_time < B.cal_time; 
}

int main()
{
	priority_queue <CUSTOMMER, vector<CUSTOMMER>, custom_cmp> pQue;
	vector<CUSTOMMER> result;

	cin >> N >> K;
	FOR(i, N)
	{
		int x, y;
		cin >> x >> y;
		Customer[i] = {x, y};
	}

	FOR(i, K)
    {
        int num = Customer[i].first;
        int time = Customer[i].second;
        pQue.push({ num, time, i+1});
    }

	for (int i = K; i < N; i++)
    {
        int num = Customer[i].first;
        int time = Customer[i].second;

        pQue.push({ num, time + pQue.top().cal_time, pQue.top().cnt_num });
        result.push_back(pQue.top());
        pQue.pop();
    }

    while (!pQue.empty())
    {
        result.push_back(pQue.top());
        pQue.pop();
    }    

    sort(result.begin(), result.end(), cmp);
    FOR(i, N)
    	answer += (i+1) * result[i].custom_num;

    cout << answer << endl;

/*
	int T = 0;
	while(!pQue.empty())
	{
		int time = pQue.top().first;
		int num = pQue.top().second;
		pQue.pop();
		cout << time << endl;
		counter.push({time, num});
	}
	while(!counter.empty())
	{
		int time = counter.top().first;
		int num = counter.top().second;
		counter.pop();

		result.push_back(num);
	}
	FOR(i, N)
	{
		answer += i * result[i];
	}

	cout << answer << endl;
*/

	return 0;
}