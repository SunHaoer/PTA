#include<iostream>
#include<vector>
using namespace std;
const int MAX = 20;
int arr1[MAX] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
vector<string> vec;

int main()
{
    int n;
    cin>>n;
    string str;
    for(int i = 0; i < n; i++) {
        cin>>str;
        int cnt = 0;
        for(int j = 0; j < str.length() - 1; j++) {
            if(str[j] >= '0' && str[j] <= '9') {
                cnt += (str[j] - '0') * arr1[j];
            } else {
                vec.push_back(str);
                cnt = -1;
                break;
            }
        }
        if(cnt != -1) {
            if(M[cnt % 11] != str[str.length() - 1]) {
                vec.push_back(str);
            }
        }
    }
    if(vec.size() != 0) {
        for(int i = 0; i < vec.size(); i++) {
            cout<<vec[i]<<endl;
        }
    } else {
        cout<<"All passed"<<endl;
    }
    return 0;
}
