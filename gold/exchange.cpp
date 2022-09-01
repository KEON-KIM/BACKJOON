#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 11
using namespace std;

int K, result = -1;
map<string, int> visited[MAX];
string swap(string str, char i, char j)
{
    char tmp = str[i-'0'];
    str[i-'0'] = str[j-'0'];
    str[j-'0'] = tmp;

    return str;
}

void dfs(int dep, string str, vector<string> &combination)
{
    if(str[0] == '0') return;
    if (dep == K) {result = max(result, stoi(str)); return;}
    for(int i = 0; i < combination.size(); i++)
    {
        if(!(combination[i][0] - '0') && !(str[combination[i][1] - '0'] - '0')) continue;
        string tmp = swap(str, combination[i][0], combination[i][1]);
        if(!visited[dep+1][tmp])
        {
            visited[dep+1][tmp]++;
            dfs(dep+1, tmp, combination);
        }
    }
}

int main() {
    const int ec = 2;
    string n;
    cin >> n >> K;

    vector<bool> temp(n.size(), false);
    for(int i = 0; i < ec; i ++)    
        temp[i] = true;
    
    vector<string> combination;
    do {
        string combi = "";
        for (int i = 0; i < n.size(); i++)     
            if (temp[i])
                combi += (i+'0');
        combination.push_back(combi);
    } while (prev_permutation(temp.begin(), temp.end()));
    
    if(n.size() > 1)
        dfs(0, n, combination);
    cout << result << endl;

    return 0;
}
