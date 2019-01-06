#include<bits/stdc++.h>
using namespace std;

int mx(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int knapsack(int weights[],int values[],int allowedWeight,int n)
{
    int table[n+1][allowedWeight+1];
    for(int row = 0; row<=n; row++)
    {
        for(int w = 0; w<=allowedWeight; w++)
        {
            if(row == 0 || w == 0)
                table[row][w] = 0;

            else if(weights[row-1]<=w)
            {
                table[row][w] = mx(table[row-1][w], values[row-1] + table[row-1][w-weights[row-1]]);
            }

            else
                table[row][w] = table[row-1][w];
        }
    }
    return table[n][allowedWeight];
}


int main()
{
    int weights[20];
    int values[20];
    int n, allowedWeight;

    cout<<"Enter number of elements"<<endl;
    cin>>n;

    cout<<"Enter the weights"<<endl;

    for(int i = 0; i<n; i++)
    {
        cin>>weights[i];
    }

    cout<<"Enter the values"<<endl;

    for(int i = 0; i<n; i++)
    {
        cin>>values[i];
    }

    cout<<"Enter the allowed weight"<<endl;
    cin>>allowedWeight;

    cout<<knapsack(weights, values, allowedWeight, n);


    return 0;
}
