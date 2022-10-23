// #2981
#include<iostream>
#include<algorithm>

#define MAX_SIZE 101
using namespace std;

int n, arr[MAX_SIZE], sol[MAX_SIZE];

int GCD(int x, int y)
{
	return x%y ? GCD(y, x%y) : y ;
}

void solution()
{
	int gcd = arr[1] - arr[0], count(0);

	for(int i = 2; i < n; i++)
		gcd = GCD(gcd, arr[i] - arr[i-1]);

	for(int i = 1; i*i <= gcd; i++) // Devisior Of GCD;
		if(gcd%i == 0){
			sol[count++] = i;
            if (i != gcd/i) sol[count++] = gcd / i;
        }

    sort(sol, sol + count);

    for(int i = 0; i < count; i++)
    	if(sol[i] != 1)
    		cout << sol[i] << " ";   
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int tmp;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
		// Input.push_back(tmp);
	
	sort(arr, arr+n);
	// sort(Input.begin(), Input.end());

	solution();	
	// answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return 0;
}