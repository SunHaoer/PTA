#include<iostream>
#include<map>
using namespace std;
const int MAX = 2010;
const int INF = 1000000000;
map<int, string> idToName;
map<string, int> nameToId;
map<string, int> gang;              // head->�ڵ���
int table[MAX][MAX] = { 0 };
int weight[MAX] = { 0 };            // ��Ȩ��weight
bool visited[MAX] = { false };
int n, k, numPerson = 0;            // ����n, ��ֵk, ������numPerson

int change(string str) {            // name->id
    if(nameToId.find(str) != nameToId.end()) {      // str�Ѵ���nameToId
        return nameToId[str];
    } else {
        nameToId[str] = numPerson;                  // ��str���ΪnumPerson
        idToName[numPerson] = str;                 // numPerson��Ӧstr
        return numPerson++;
    }
}

void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
    numMember++;
    visited[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) {       // ��ǰ���ʽڵ�Ȩ�ش���headȨ��, ����head�ڵ�
        head = nowVisit;
    }
    for(int i = 0; i < n; i++) {
        if(table[nowVisit][i] > 0) {            // nowVisit->i����
            totalValue += table[nowVisit][i];   // ������ͨ�����Ȩ��
            table[nowVisit][i] = table[i][nowVisit] = 0;        // ɾ���ѷ��ʵĽڵ�
            if(visited[i] == false) {               // �ݹ�����δ���ʵĽڵ�
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {               // ��������ͼ
    for(int i = 0; i < n; i++) {            // �������нڵ�
        if(visited[i] == false) {           // ���ٷ����ѷ��ʵĽڵ�, ��߳���Ч��
            int head = i, numMember = 0, totalValue = 0;        // ͷĿhead, ��Ա��numMember, ��Ȩ��tatalValue
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k) {              // ��Ա������2, ��Ȩ�ش���k
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
        table[id1][id2] += w;           // �����ڽӾ���ı�
        table[id2][id1] += w;
        weight[id1] += w;               // ÿ���ڵ��Ȩ��
        weight[id2] += w;
    }
    DFSTrave();
    cout<<gang.size()<<endl;
    for(map<string,int>::iterator it = gang.begin(); it != gang.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
