#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 10;
vector<double> vec;
int arr[MAX];

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; i++) {
        fill(arr, arr + MAX, 0);
        for(int j = 0; j < k; j++) {
            scanf("%d", &arr[j]);
        }
        sort(arr, arr + k);
        arr[0] = arr[k - 1] = 0;
        double cnt = 0;
        for(int j = 0; j < k; j++) {
            cnt += arr[j];
        }
        vec.push_back(cnt);
    }
    sort(vec.begin(), vec.end());
    for(int i = vec.size() - m; i < vec.size(); i++) {
        if(i != vec.size() - m) printf(" ");
        printf("%.3f", (vec[i] * 1.0) / (k - 2));
    }
    return 0;
}
