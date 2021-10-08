//© 2021 hidercpp <https://www.acmicpc.net/source/34029188>

#include <iostream>

int f(int x, int y){
  if (abs(x) >= abs(y)){
    if (x >= 0) return 4 * x * x + 3 * x + y + 1;
    else return 4 * x * x + x - y + 1;
  }
  else{
    if (y > 0) return 4 * y * y - 3 * y - x + 1;
    else return 4 * y * y - y + x + 1; 
  }
}

int dig(int x){
  int ans = 0;
  while(x != 0){
    x /= 10;
    ans++;
  }
  return ans;
}

int main(){
  using namespace std;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d, print = 1;
  cin >> a >> b >> c >> d;
  for (int i = a; i <= c; i++){
    for (int j = b; j <= d; j++) print = max(print, dig(f(i, j)));
  }
  for (int i = a; i <= c; i++){
    for (int j = b; j <= d; j++){
      for (int k = 0; k < print - dig(f(i, j)); k++) cout << ' ';
      cout << f(i, j) << ' ';
    }
    cout << '\n';
  }
  return 0;
}