//#3933
//@Reference restudycafe <https://restudycafe.tistory.com/m/455>
#include<iostream>
#include<cmath>

#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;

    while(true) {
        int N; cin >> N;
        if(N == 0) break;

        int cnt = 0, sqrtN = sqrt(N);
        FOR(i, sqrtN) {
            if(i*i == N) { cnt++; continue; }
            for(int j=i; j<=sqrtN; j++) {
                if(i*i + j*j == N) { cnt++; break; }
                for(int k=j; k<=sqrtN; k++) {
                    if(i*i + j*j + k*k == N) { cnt++; break; }
                    for(int l=k; l<=sqrtN; l++) {
                        if(i*i + j*j + k*k + l*l == N) { cnt++; break; }
                        if(i*i + j*j + k*k + l*l > N) break;
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
}
/*
void dfs(int depth, int dest)
{
	
	int len = (int)sqrt(dest);

	for(int i = 1; i <= len; i++)
	{
		if(i * i == dest){
			result++;
			continue;
		}
		if(dest > (i*i) && depth < 3) 
			dfs(depth + 1, dest - (i*i));
	}
}
int main()
{
	int input = -1;
	// Init();
	while(input)
	{
		result = 0;
		cin >> input;
		dfs(1, input);
		cout << result << endl;
	}
	return 0;
}*/