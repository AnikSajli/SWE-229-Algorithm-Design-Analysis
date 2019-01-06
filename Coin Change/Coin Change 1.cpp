#include<bits/stdc++.h>
using namespace std;

int CoinChange(int coins[], int money, int SIZE)
{
    int values[money + 1];
    for(int i =0; i<=money; i++)
    {
        values[i] = 0;
    }

    values[0] = 1;

    for(int i = 0; i<SIZE; i++)
    {
        for(int j = coins[i]; j<=money; j++)
        {
            values[j] = values[j] + values[j - coins[i]];
        }
    }
    return values[money];
}

int main()
{
    int coins[] = {1,2};
    int money = 6;
    int SIZE = 2;

    cout<<CoinChange(coins, money, SIZE);

    return 0;
}
