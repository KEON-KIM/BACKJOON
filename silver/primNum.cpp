#include<iostream>
#include<vector>

using namespace std;
int N, M;

void prime(int N, int M)
{
	vector<int> pri_vector;
	for(int i = 2; i <= M; i++)
	{
		if(i == 2||i == 3){
			if(i >= N){
				pri_vector.push_back(i); cout << i << endl;
			}
			else
				pri_vector.push_back(i);
		} 

		else
		{
			if(i%2 != 0 && i%3 != 0)
			{
				bool nPrime = false;
				for(int j = 0; j < pri_vector.size(); j++)
					if(!(i % pri_vector[j])) {nPrime= true; break;}
				if (!nPrime) {
					if(i >= N){
						pri_vector.push_back(i); cout << i << endl;
					}
					else
						pri_vector.push_back(i);
				}
			}
		}
	}	

	// for(int i : pri_vector) cout << i << endl;
}
int main()
{
	cin >> N >> M;

	prime(N, M);
	return 0;
}