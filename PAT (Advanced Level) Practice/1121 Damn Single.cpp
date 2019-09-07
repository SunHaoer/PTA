#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100000;

int main()
{
    vector<int> dog;
    int n, m;
    int cat[MAX], guest[MAX];
    bool isVisit[MAX];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {      // 输入cat
        int id1, id2;
        scanf("%d%d", &id1, &id2);
        cat[id1] = id2;
        cat[id2] = id1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {      // 输入参加的人
        scanf("%d", &guest[i]);
        isVisit[guest[i]] = true;
    }
    for(int i = 0; i < m; i++) {      // 筛选
        if(!isVisit[cat[guest[i]]]) {   // dog
            dog.push_back(guest[i]);
        }
    }
    sort(dog.begin(), dog.end());
    printf("%d\n", dog.size());     // 输出
    for(int i = 0; i < dog.size(); i++) {
        if(i != 0) printf(" ");
        printf("%05d", dog[i]);
    }
    return 0;
}
