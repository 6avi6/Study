#include <iostream>

using namespace std;


int fib(int n)
{
    if (n < 3)
        return 1;

    return fib(n - 2) + fib(n - 1);
}

int main()
{
    
    int sum1 = 1, sum2 = 1,temp, n = 100;
    for (int i = 0; i < n; i++) {
        temp = sum1;
        sum1 = sum1 + sum2;
        cout << sum1<<endl;
            sum2 = temp;
    }
   // cout<<fib(100);
    
}

