#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Message {
    char name[10];
    int ranked;
    friend bool operator < (Message m1, Message m2) {
        return m1.ranked > m2.ranked;
    }
};
priority_queue<Message> q;

int main()
{
    int n;
    char str[10];
    Message temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(strcmp(str, "PUT") == 0) {           // strcmp±È½Ïchar[]µÄ×ÖµäÐò
            scanf("%s%d", temp.name, &temp.ranked);
            q.push(temp);
        } else if(strcmp(str, "GET") == 0) {
            if(!q.empty()) {
                printf("%s\n", q.top().name);
                q.pop();
            } else {
                printf("EMPTY QUEUE!\n");
            }
        }
    }
    return 0;
}
