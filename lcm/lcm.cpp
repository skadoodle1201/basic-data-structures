

#include <iostream>
#include<vector>
using namespace std;

int GCD_NO(long long n, long long m)
{
    long long lcm = m * n;
    long long rem = 1;
    while (rem)
    {
        rem = n % m;
        n = m;
        m = rem;
    }
    lcm = lcm / n;
    cout << lcm;
    return 0;
}
int main()
{
    long long N, M;
    cin >> N >> M;
    GCD_NO(N, M);
}
