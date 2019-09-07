#include <iostream>
#include<math.h>

using namespace std;

long long get_pisano_period(long long m) 
{
    long long a = 0, b = 1, c = a + b;
    for (long long int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (long long i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}


 

int main()

{

    int t;
    cin>>t;
    while(t--)
    {
        long long n, m ,p;
        cin >> n;
        p = (int)log2(n);
        n = (long long int)pow(2,p);
        cout<<n<<endl;
        cout << get_fibonacci_huge(n-1, 10) << '\n';
    }

    return 0;
}
