#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
const int MAX = 1010;
int table[MAX][MAX];

struct Point {          // 像素点
    int x, y, num;
};

int main()
{
    int m, n, tol, ans = 0;
    Point point;
    map<int, int> flag;         // 每个像素点出现的次数
    scanf("%d%d%d", &m, &n, &tol);
    swap(m, n);                         // m行n列, 看着不顺眼swap
    for(int i = 0; i < m; i++) {        // 输入
        for(int j = 0; j < n; j++) {
            scanf("%d", &table[i][j]);
            flag[table[i][j]]++;
        }
    }
    for(int i = 0; i < m; i++) {        // 判断
        for(int j = 0; j < n; j++) {
            if(flag[table[i][j]] > 1) continue;        // 多个点
            int tempI1 = i - 1, tempI2 = i + 1, tempJ1 = j - 1, tempJ2 = j + 1;     // 待比较的坐标tempI, tempJ
            if(tempI1 < 0) tempI1 = tempI2;
            if(tempI2 >= m) tempI2 = tempI1;
            if(tempJ1 < 0) tempJ1 = tempJ2;
            if(tempJ2 >= n) tempJ2 = tempJ1;
            if( (abs(table[i][j] - table[i][tempJ1]) > tol) && (abs(table[i][j] - table[tempI1][j]) > tol)              // 此处要绝对值
             && (abs(table[i][j] - table[i][tempJ2]) > tol) && (abs(table[i][j] - table[tempI2][j]) > tol)
             && (abs(table[i][j] - table[tempI1][tempJ1]) > tol) && (abs(table[i][j] - table[tempI1][tempJ2]) > tol)
             && (abs(table[i][j] - table[tempI2][tempJ2]) > tol) && (abs(table[i][j] - table[tempI2][tempJ1]) > tol)) {
                    point.x = j + 1;
                    point.y = i + 1;
                    point.num = table[i][j];
                    ans++;
                    if(ans > 1) break;              // 已经存在
                }
        }
    }
    if(ans == 0) printf("Not Exist\n");             // 不存在
    else if(ans > 1) printf("Not Unique\n");        // 不唯一
    else printf("(%d, %d): %d\n", point.x, point.y, point.num);
    return 0;
}


