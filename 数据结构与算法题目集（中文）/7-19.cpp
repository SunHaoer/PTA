#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int> num;
    int n, data;
    scanf("%d", &n);
    while(scanf("%d", &data) >= 0) {
        if(data < 0) break;
        num.push_back(data);
    }
    if(n <= num.size()) printf("%d\n", num[num.size() - n]);
    else printf("NULL");
    return 0;
}
