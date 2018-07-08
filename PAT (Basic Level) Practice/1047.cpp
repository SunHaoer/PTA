#include<cstdio>
using namespace std;
const int MAX = 1010;
int hashTable[MAX] = { 0 };             // hashTabel[num] = score

int main()
{
    int n;
    int maxn = -1, maxg = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num, score, member;
        scanf("%d - %d", &num, &member);
        scanf("%d", &score);
        hashTable[num] += score;
    }
    for(int i = 0; i < MAX; i++) {
        if(hashTable[i] > maxn) {
            maxn = hashTable[i];
            maxg = i;
        }
    }
    printf("%d %d\n", maxg, maxn);
    return 0;
}
