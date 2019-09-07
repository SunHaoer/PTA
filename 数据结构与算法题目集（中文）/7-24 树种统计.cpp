#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Tree {
    string name;
    int num;
};

bool cmp(Tree tree1, Tree tree2) {
    return tree1.name < tree2.name;
}

int main()
{
    int n;
    map<string, Tree> m;
    vector<Tree> tree;
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++) {            // ������ֲ�
        string name;
        getline(cin, name);                 // ��������
        m[name].name = name;
        m[name].num++;
    }
    for(map<string, Tree>::iterator it = m.begin(); it != m.end(); it++) {          // map->vector��������
        tree.push_back(it->second);
    }
    sort(tree.begin(), tree.end(), cmp);
    for(int i = 0; i < tree.size(); i++) {          // ������ֲ�
        cout<<tree[i].name<<" ";
        printf("%.4f%%\n", tree[i].num * 1.0 / n * 100);
    }
    return 0;
}
