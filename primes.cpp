#include <iostream>
#include <cmath>
#include <chrono>
#include <array>

using namespace std;

void timeDiff(auto begin, auto end)
{
    cout << chrono::duration<double, std::nano>(end - begin).count()/1000 << "\n";
}

int aPrime(int n)
{
    bool dividerFound = false;
    int count = 0;

    for(int i = 2; i <= n; i++)
    {
        dividerFound = false;
        for(int j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                dividerFound = true;
                break;
            }
        }
        if(!dividerFound)
            count++;
    }

    return count;
}


int bPrime(int n)
{
    bool dividerFound = false;
    int count = 1;

    for(int i = 3; i <= n; i+=2)
    {
        dividerFound = false;
        for(int j = 3; j < i; j+=2)
        {
            if(i%j == 0)
            {
                dividerFound = true;
                break;
            }
        }
        if(!dividerFound)
            count++;
    }

    return count;
}


int cPrime(int n)
{
    bool dividerFound = false;
    int count = 1;

    for(int i = 3; i <= n; i+=2)
    {
        dividerFound = false;
        for(int j = 3; j < (int)(sqrt(i))+1; j+=2)
        {
            if(i%j == 0)
            {
                dividerFound = true;
                break;
            }
        }
        if(!dividerFound)
            count++;
    }

    return count;
}


int nextPrime(int n) 
{
  if (n == 2)
    return 3;

  if (n == 3)
    return 5;

  int dividers = 1;
  while (dividers != 0) 
  {
    n += 2;
    dividers = 0;
    for (int i = 3; i < (int)(sqrt(n)) + 1; i += 2) {
      if (n % i == 0) {
        dividers++;
        break;
      }
    }
  }
  return n;
}

int dPrime(int n)
{
    bool mNumbers[n+1];
    for(int i = 0; i < n; i++)
    {
        mNumbers[i] = true;
    }
    int prime = 2;

    for(int i = 0; i < (int)(sqrt(n)) + 1; i++)
    {
        for(int j = 2*prime; j < n+1; j+=prime)
        {
            mNumbers[j] = false;
        }
        prime = nextPrime(prime);
    }

    int count = -1;

    for(int i = 1; i < n; i++)
    {
        if(mNumbers[i])
            count++;
    }
    
    return count;
}




int main()
{
    for(int i = 100; i < 1000001; i*=10)
    {
        cout << "Ilosc liczb: " << i << "\n"; 

        auto aBegin = chrono::high_resolution_clock::now();
        cout << aPrime(i) << " ";
        auto aEnd = chrono::high_resolution_clock::now();
        timeDiff(aBegin, aEnd);

        auto bBegin = chrono::high_resolution_clock::now();
        cout << bPrime(i) << " ";
        auto bEnd = chrono::high_resolution_clock::now();
        timeDiff(bBegin, bEnd);

        auto cBegin = chrono::high_resolution_clock::now();
        cout << cPrime(i) << " ";
        auto cEnd = chrono::high_resolution_clock::now();
        timeDiff(cBegin, cEnd);

        auto dBegin = chrono::high_resolution_clock::now();
        cout << dPrime(i) << " ";
        auto dEnd = chrono::high_resolution_clock::now();
        timeDiff(dBegin, dEnd);

        cout << "\n";
    }

    
}