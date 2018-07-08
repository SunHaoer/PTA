#include<iostream>
using namespace std;

int main()
{
    int n, hashTable[100010] = {0}, temp[100010];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp[i];
        hashTable[temp[i]]++;
    }
    for(int i=0; i<n; i++){
        if(hashTable[temp[i]]==1){
            cout<<temp[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}

/*
非hashTable最好不要初始化{0}
*/
