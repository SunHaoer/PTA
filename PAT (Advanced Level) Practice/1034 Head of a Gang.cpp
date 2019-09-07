#include<iostream>
#include<map>
using namespace std;
const int MAX = 2010;
const int INF = 1000000000;
map<int, string> idToName;
map<string, int> nameToId;
map<string, int> gang;              // head->节点数
int table[MAX][MAX] = { 0 };
int weight[MAX] = { 0 };            // 点权重weight
bool visited[MAX] = { false };
int n, k, numPerson = 0;            // 边数n, 阈值k, 总人数numPerson

int change(string str) {            // name->id
    if(nameToId.find(str) != nameToId.end()) {      // str已存在nameToId
        return nameToId[str];
    } else {
        nameToId[str] = numPerson;                  // 将str编号为numPerson
        idToName[numPerson] = str;                 // numPerson对应str
        return numPerson++;
    }
}

void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
    numMember++;
    visited[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) {       // 当前访问节点权重大于head权重, 更新head节点
        head = nowVisit;
    }
    for(int i = 0; i < n; i++) {
        if(table[nowVisit][i] > 0) {            // nowVisit->i成立
            totalValue += table[nowVisit][i];   // 更新连通块的总权重
            table[nowVisit][i] = table[i][nowVisit] = 0;        // 删除已访问的节点
            if(visited[i] == false) {               // 递归搜索未访问的节点
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {               // 遍历整个图
    for(int i = 0; i < n; i++) {            // 遍历所有节点
        if(visited[i] == false) {           // 不再访问已访问的节点, 提高程序效率
            int head = i, numMember = 0, totalValue = 0;        // 头目head, 成员数numMember, 总权重tatalValue
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k) {              // 成员数大于2, 总权重大于k
                gang[idToName[head]] = numMember;
            }
        }
    }
}

int main()
{
    int w;
    string str1, str2;
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        cin>>str1>>str2>>w;             // str1->str2 = w
        int id1 = change(str1);
        int id2 = change(str2);
        table[id1][id2] += w;           // 建立邻接矩阵的边
        table[id2][id1] += w;
        weight[id1] += w;               // 每个节点的权重
        weight[id2] += w;
    }
    DFSTrave();
    cout<<gang.size()<<endl;
    for(map<string,int>::iterator it = gang.begin(); it != gang.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
