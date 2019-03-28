#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 10010;
vector<int> vec[MAX];

int main()
{
    int n, arr[MAX], cnt = 0, ans = 1, last = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i] *= 10;
        cnt += arr[i];
    }
    while(cnt > 0) {
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) continue;
            if(last == i) ans++;
            vec[i].push_back(ans);
            ans++, last = i, arr[i]--, cnt--;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("#%d\n", i + 1);
        for(int j = 0; j < vec[i].size(); j++) {
            printf("%d", vec[i][j]);
            if((j + 1) % 10 == 0) printf("\n");
            else if(j != vec[i].size() - 1) printf(" ");
        }
    }
    return 0;
}
