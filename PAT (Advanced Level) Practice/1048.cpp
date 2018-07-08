#include<iostream>
#include<cstdio>
using namespace std;
int hashTable[100010] = {0};

int main()
{
    int n, m, temp;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        hashTable[temp]++;
    }
    for(int i=0; i<m; i++){
        if(hashTable[i]&&hashTable[m-i]){
            if(i==m-i&&hashTable[i]<=1){
                continue;
            }
            printf("%d %d", i, m-i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
