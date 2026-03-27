#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

template <typename T>
T absolute(T x)
{
    if (x >= 0)
        return x;
    else
        return -x;
}

template <typename T>
T power(T x, int n)
{
    T result = 1;

    for (int i = 0; i < n; i++)
    {
        result *= x;
    }

    return result;
}

long long factorial(int n)
{
    if (n == 0)
        return 1;

    long long result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}


template <typename T>
double squareRoot(T x)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return nan("");

    double guess = static_cast<double>(x);
    int count = 0;

    while (absolute(guess * guess - x) > 0.00001 && count < 100)
    {
        guess = 0.5 * (guess + x / guess);
        count++;
    }

    return guess;
}

double pi()
{
    double sum = 0;

    for (int n = 0; n < 15; n++)
    {
        double term = (1.0 / power(16.0, n)) *
            (4.0 / (8 * n + 1)
                - 2.0 / (8 * n + 4)
                - 1.0 / (8 * n + 5)
                - 1.0 / (8 * n + 6));

        sum += term;
    }

    return sum;
}

template <typename T>
double sine(T x)
{
    double PI = pi();
    double val = static_cast<double>(x);

    int sign = (val < 0) ? -1 : 1;
    val *= sign;

    while (val > PI)
    {
        val -= PI;
        sign *= -1;
    }

    double sum = 0;

    for (int n = 0; n < 9; n++)
    {
        double term = power(-1.0, n) *
            power(val, 2 * n + 1) /
            factorial(2 * n + 1);

        sum += term;
    }

    return sign * sum;
}

template <typename T>
double cosine(T x)
{
    return sine(pi() / 2 - x);
}

template <typename T>
double tangent(T x)
{
    return sine(x) / cosine(x);
}

int main(){
    
    
    
    // Square roots
    cout << "squareRoot(2): " << squareRoot(2) << "\n";
    cout << "squareRoot(-1): " << squareRoot(-1) << "\n";
    cout << "squareRoot(15.99): " << squareRoot(15.99) << "\n";
    cout << "squareRoot('a'): " << squareRoot('a') << "\n";
    cout << "squareRoot(0): " << squareRoot(0) << "\n";
    cout << "squareRoot(-1): " << squareRoot(-1) << "\n";

    cout << endl;

    // Sine
    cout << "sine(1): " << sine(1) << "\n";
    cout << "sine(5.25f): " << sine(5.25f) << "\n";
    cout << "sine(pi()): " << sine(pi()) << "\n";
    cout << "sine(-5*pi()/2): " << sine(-5 * pi() / 2) << "\n";
    cout << "sine('a'): " << sine('a') << "\n";

    cout << endl;
    
    // Cosine
    cout << "cosine(1): " << cosine(1) << "\n";
    cout << "cosine(5.25f): " << cosine(5.25f) << "\n";
    cout << "cosine(pi()): " << cosine(pi()) << "\n";
    cout << "cosine(-5*pi()/2): " << cosine(-5 * pi() / 2) << "\n";
    cout << "cosine('a'): " << cosine('a') << "\n";
    
    cout << endl;

    // Cosine
    cout << "tangent(1): " << tangent(1) << "\n";
    cout << "tangent(5.25f): " << tangent(5.25f) << "\n";
    cout << "tangent(pi()): " << tangent(pi()) << "\n";
    cout << "tangent(-5*pi()/2): " << tangent(-5 * pi() / 2) << "\n";
    cout << "tangent('a'): " << tangent('a') << "\n";




}



