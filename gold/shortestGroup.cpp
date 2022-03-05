#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int arr[1001], n, k; 

void INPUT()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
}

vector<string> INIT()
{
	vector<string> v;

	for(int i = 0; i <= k; i++)
	{
		string tmp = "";
		if(i == k) {
			for(int j = i; j < n; j++ )
				tmp += arr[j] + '0';
			v.push_back(tmp);
		}
		else {
			tmp+= arr[i] + '0';
			v.push_back(tmp);
		}
	}

	return v;
}

int sumCal(vector<string> str)
{
	int result = 0;
	for(int i = 0; i < str.size(); i++)
		result += stoi(str[i]);

	return result;
}

int solution(vector<string> &str)
{
	int cur_result, min_sum, pivot;
	int A, B, b, len;
	// for(int i = 0; i < str.size(); i++)
	// 	cout << str[i] << ", ";
	// cout << result << endl;
	for(int i = 0; i < k; i++)
	{
		pivot = k;
		while(pivot)
		{
			A = stoi(str[pivot-1]);
			B = stoi(str[pivot]);
			b = str[pivot][0] - '0';
			len = str[pivot].size();
			
			if(A + B < A*10 + b + B - b*pow(10,len-1))
				pivot--;

			else{
				// min_sum = cur_result;
				str[pivot-1] += str[pivot][0];
				str[pivot] = str[pivot].substr(1);
				min_sum = min(sumCal(str), min_sum);
			}
			
			for(int i = 0; i < str.size(); i++)
				cout << str[i] << ", ";
			cout << min_sum << endl;
		}
	}
	

	return min_sum;
	// if(pivot == 0) return result;

	// str[pivot-1] += str[pivot][0];
	// str[pivot] = str[pivot].substr(1);

	// cur_result = sumCal(str);

	// if(cur_result >= result)
	// 	return solution(str, pivot-1, result);
	// else
	// 	return solution(str, pivot, cur_result);
}

int main()
{
	vector<string> v;
	int result;

	INPUT();
	v = INIT();

	result = sumCal(v);
	cout << solution(v)<<endl;
		
	return 0;
}