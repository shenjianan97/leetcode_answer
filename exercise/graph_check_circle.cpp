#define MAX_VALUE 10000

#include <iostream>
#include <vector>

using namespace std;

int parents[MAX_VALUE];

struct edge{
    int s;
    int e;
    edge(int start, int end){
        s = start;
        e = end;
    }
};

int find_parent(int x);
void unionn(int start, int end);

int main(){
    int edge_num;

    for(int i=0; i<MAX_VALUE; i++){
        parents[i] = i;
    }

    cout << "请输入边数: ";
    cin >> edge_num;
    for(int i=1; i<=edge_num; i++){
        cout << "请输入第" << i << "条边的两个端点 (例如 1 2):";
        int start, end;
        cin >> start >> end;
        int x = find_parent(start);
        cout << "起始点父亲: " << x << endl;
        int y = find_parent(end);
        cout << "终点父亲: " << y << endl;
        if(x == y){
            cout << "这个图有环" << endl;
            break;
        }else{
            unionn(x, y);
        }
    }

    return 0;
}

int find_parent(int x){
    if(x != parents[x]){
        parents[x] = find_parent(parents[x]);
    }
    return parents[x];
}

void unionn(int start, int end){
    parents[end] = find_parent(start);
}