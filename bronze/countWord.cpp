#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	int result = 0;
	char *context = NULL;
	string str;
	getline(cin, str);
	char input[str.size()+1];
	strcpy(input, str.c_str());
	char *token =  strtok_r(input, " ", &context);

	while(token)
	{
		token = strtok_r(NULL, " ", &context);
		result += 1;
	}

	cout << result << endl;

	return 0;
}