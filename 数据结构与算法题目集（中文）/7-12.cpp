#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vt;

int main()
{
    int n, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        vt.push_back(data);
    }
    sort(vt.begin(), vt.end());
    printf("%d", vt[0]);
    for(int i = 1; i < vt.size(); i++) {
        printf(" %d", vt[i]);
    }
    return 0;
}
