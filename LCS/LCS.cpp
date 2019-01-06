#include<bits/stdc++.h>
using namespace std;

int mx(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int lcs(char a[], char b[], int a_len, int b_len)
{
    int table[a_len+1][b_len+1];

    for(int i = 0; i <= a_len; i++)
    {
        for(int j = 0; j <= b_len; j++)
        {
            if(i == 0 || j == 0)
            {
                table[i][j] = 0;
            }

            else if(a[i-1] == b[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }

            else
                table[i][j] = mx(table[i-1][j], table[i][j-1]);
        }
    }

    int lcs_len = table[a_len][b_len];
    int index = lcs_len;

    char lcs_arr[lcs_len];

    int i = a_len;
    int j = b_len;

    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            lcs_arr[index-1] = a[i-1];
            i--;
            j--;
            index--;

        }

        else if(table[i-1][j] > table[i][j-1])
        {
            i--;
        }

        else
            j--;
    }

    cout<<"LCS length:"<<lcs_len<<endl;

    cout<<"LCS array:"<<endl;
    for(int i = 0; i<lcs_len; i++)
    {
        cout<<lcs_arr[i];
    }
}

int main()
{
    char a[20];
    char b[20];
    cout<<"Enter first string:"<<endl;
    cin>>a;
    cout<<"Enter second string:"<<endl;
    cin>>b;

    int a_len = strlen(a);
    int b_len = strlen(b);
    lcs(a,b,a_len,b_len);

    return 0;
}
