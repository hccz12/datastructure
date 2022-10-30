#include <iostream>
using namespace std;

void search(char* S, char* T)   //S search sequence, T target sequence
{
    int M = strlen(S);      //可以重写strlen的实现
    int N = strlen(T);

    /* A loop to slide S[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
        {
            if (T[i + j] != S[j])
                break;
        }
        if (j == M)  // if S[0...M-1] = T[i, i+1, ...i+M-1]
        {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main()
{
    char* T = "AABAACAADAABAAABAA";
    char* S = "AABA";
    search(S, T);
    return 0;
}
