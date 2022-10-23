#include <iostream>
#include <algorithm>
#include <climits> //LLONG_MAX

using namespace std;

const int MAX = 5000; 

int N, idx1, idx2, idx3;
long long minimum;
long long liquid[MAX];

void print3Liquid(void)
{
        for (int i = 0; i < N; i++)
        {
                 //양방향에서

                 int j = i + 1;

                 int k = N - 1;

 

                 while (1)

                 {

                         if (j >= k)

                                 break;

 

                         long long sum = liquid[i] + liquid[j] + liquid[k];
                         cout << sum << endl;
                         //최소값 갱신 때마다 idx1~idx3 초기화

                         if (llabs(sum) < minimum)

                         {

                                 minimum = llabs(sum);

                                 idx1 = i;

                                 idx2 = j;

                                 idx3 = k;

                         }

 

                         //오름차순 정렬을 했으므로

                         if (sum < 0)

                                 j++;

                         else

                                 k--;

                 }

        }
 

        cout << liquid[idx1] << " " << liquid[idx2] << " " << liquid[idx3] << endl;

}

 

int main(void)

{

        cin >> N;

 

        for (int i = 0; i < N; i++)

                 cin >> liquid[i];

 

        sort(liquid, liquid + N);

 

        minimum = LLONG_MAX;

        print3Liquid();

 

        return 0;
}
