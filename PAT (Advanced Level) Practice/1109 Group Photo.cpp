#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 10100;
string table[MAX];

struct People {
    string name;
    int heigh;
};
vector<People> peo;

bool cmp(People a, People b) {
    if(a.heigh != b.heigh) return a.heigh < b.heigh;
    else return a.name > b.name;
}

void print(int m) {      // 输出
    for(int i = 0; i < m; i++) {
        cout<<table[i];
        if(i == m - 1) cout<<endl;
        else cout<<" ";
    }
}

void fun1(int m, int index) {       // 排队
    fill(table, table + MAX, "");
    if(m % 2 != 0) {    // 奇数, 2 3 1
        for(int i = 0; i < m; i++) {
            if(i % 2 == 0) {    // 右
                table[m - 1 - i / 2] = peo[index + i].name;
            } else {            // 左
                table[i / 2] = peo[index + i].name;
            }
        }
    } else {            // 偶数,  1 3 4 2
        for(int i = 0; i < m; i++) {
            if(i % 2 == 0) {    // 左
                table[i / 2] = peo[index + i].name;
            } else {            // 右
                table[m - 1 - i / 2] = peo[index + i].name;
            }
        }
    }
    print(m);
    peo.erase(peo.begin() + index, peo.end());
}

int main()
{
    int n, k, m;
    cin>>n>>k;
    for(int i = 0; i < n; i++) {    // 输入
        People temp;
        cin>>temp.name>>temp.heigh;
        peo.push_back(temp);
    }
    sort(peo.begin(), peo.end(), cmp);
    for(int i = 0; i < k; i++) {    // 排队
        if(i == 0) m = n / k + n % k;       // 每排的人数
        else m = n / k;
        fun1(m, peo.size() - m);
    }
    return 0;
}
