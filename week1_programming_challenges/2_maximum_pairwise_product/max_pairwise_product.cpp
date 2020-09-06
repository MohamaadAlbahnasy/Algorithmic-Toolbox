#include <iostream>

using namespace std ;
int fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n)
{
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
