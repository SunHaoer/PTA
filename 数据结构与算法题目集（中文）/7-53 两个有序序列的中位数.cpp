#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1000010;
map<int, bool> mp;
int result[MAX] = { 0 };

int main()
{
    int n, data, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; i++) {
        scanf("%d", &data);
        result[ans++] = data;
    }
    sort(result, result + ans);
    printf("%d\n", result[(1 + ans) / 2 - 1]);
    return 0;
}


/*
 * ����ֻ�Ǽ򵥺ϲ�, ����ȥ���ظ�
 */
