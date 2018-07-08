#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 100010;
int cat[MAX], dog[MAX];         // ��dog, ��Ϊcat
bool peo[MAX];                  // ���г�ϯ��Ա����

int main()
{
    int n, m, id, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        scanf("%d", &cat[id]);
        cat[cat[id]] = id;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {     // �ѵ������˱��Ϊtrue
        scanf("%d", &id);
        peo[id] = true;
    }
    for(int i = 0; i < MAX; i++) {
        if(peo[i] == true && peo[cat[i]] == false) {        // ����, ͬ�鲻��������
            dog[ans++] = i;
        }
    }
    sort(dog, dog + ans);
    printf("%d\n", ans);
    if(ans == 0) return 0;
    for(int i = 0; i < ans - 1; i++) {
        printf("%05d ", dog[i]);
    }
    printf("%d", dog[ans-1]);
    return 0;
}
