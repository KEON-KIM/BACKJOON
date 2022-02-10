//#1990
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string A, B;
bool Recursion(string input)
{
	cout << "recur : " << input << endl;

	if(input == A) return true;

	if(input[0] == 'B' && input[input.length()-1] == 'A')
	{
		string temp = input;
		temp.erase(temp.end()-1);

		input.erase(input.begin());
		reverse(input.begin(), input.end());

		return Recursion(input) || Recursion(temp);
	}

	else if(input[0] == 'B'){
		input.erase(input.begin());
		reverse(input.begin(), input.end());
		return Recursion(input);
	}

	else if(input[input.length()-1] == 'A'){
		input.erase(input.end()-1);
		return Recursion(input);
	}

	else 
		return false;
}

int main()
{

	cin >> A >> B;
	if(Recursion(B))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}