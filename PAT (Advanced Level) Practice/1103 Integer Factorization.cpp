#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, ans, temp;         //最优底数序列ans, 临时存放底数序列temp

void init(){
    int i = 0, temp = 0;
    while(temp<=n){
        fac.push_back(temp);
        temp = (int)(pow(++i, p)+0.1);
    }
}

void DFS(int index, int nowK, int sum, int facSum){
    if(sum==n&&nowK==k){         //满足
        if(facSum>maxFacSum){      //底数更优
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if(sum>n||nowK>k) return;    //不存在
    if(index-1>=0){            //fac[0]不需要选择
        temp.push_back(index);
        DFS(index, nowK+1, sum+fac[index], facSum+index);      //"选"
        temp.pop_back();         //出结果后把刚刚进去的数删掉
        DFS(index-1, nowK, sum, facSum);       //"不选"
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    DFS(fac.size()-1, 0, 0, 0);
    if(maxFacSum==-1) printf("Impossible\n");
    else{
        printf("%d = %d^%d", n, ans[0], p);
        for(int i=1; i<ans.size(); i++){
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}
