#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int MAX = 10000000;

void print(vector<int> resultVec, int n) {
    if(resultVec.size() == 0) {
        printf("1\n%d\n", n);
    } else {
        printf("%d\n", resultVec.size());
        for(int i = 0; i < resultVec.size(); i++) {
            if(i != 0) printf("*");
            printf("%d", resultVec[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> resultVec;
    for(int i = 2; i <= sqrt(n); i++) {
        int temp = 1;
        vector<int> tempVec;
        for(int j = i; j <= sqrt(n); j++) {     // 若i为因子，则继续搜索
            temp *= j;
            if(n % temp == 0) tempVec.push_back(j);
            else break;
        }
        if(tempVec.size() > resultVec.size()) {     // 更新最大长度vec
            resultVec = tempVec;
        }
    }
    print(resultVec, n);
    return 0;
}
