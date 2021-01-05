#pragma once
#include <cmath>
#include <string>

long long fib_recursive(long long n)
{
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long fib_iterative(long long n)
{
    long long a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fib_formula(long long n) {
    double phi = (1 + sqrt(5)) / 2;
    return (long long)round(pow(phi, n) / sqrt(5));
}

static std::string hanoians = "";
void hanoi(int n, int from, int to, int mid)
{
    if (n == 1)
    {
        hanoians += "disk " + std::to_string(n) + " -> " + char('A' + to) + "; ";
        return;
    }
    hanoi(n - 1, from, mid, to);
    hanoians += "disk " + std::to_string(n) + " -> " + char('A' + to) + "; ";
    hanoi(n - 1, mid, to, from); 
}

std::string hanoi(int n)
{
   hanoi(n, 0, 2, 1);
   return hanoians;
}