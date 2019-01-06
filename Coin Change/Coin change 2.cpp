#include<bits/stdc++.h>
using namespace std;
#define INF 999999



int MinNumOfCoins(int coins[], int SIZE, int money)
{
    int values[money + 1];
    for(int i =0; i<=money; i++)
    {
        values[i] = INF;
    }
    values[0] = 1;

    for(int i = 0; i<=money; i++)
    {
        for(int j = 0; j<SIZE; j++)
        {
            if(coins[j] <= i)
            {
                int temp = values[i-coins[j]];
                if(temp != INF && temp+1 < values[i])
                    values[i] = temp + 1;
            }
        }
    }
    return values[money];
}

int main()
{
    int coins[] = {9,6,5,1};
    int money = 11;
    int SIZE = 4;

    cout<<MinNumOfCoins(coins, SIZE, money)<<endl;

    return 0;
}
