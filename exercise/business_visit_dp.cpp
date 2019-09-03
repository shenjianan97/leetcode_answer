//一个商人要不重复的访问N个城市，允许从任意城市出发，在任意城市借书。现已知任意两个城市之间的道路长度
//求城市的访问序列，使得商人走过的路程最短
//例：N=4，访问序列3，4，1，2

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Solution{
public:
    vector<bool> visited;
    stack<int> trace;

    int visit(int index, vector<vector<int> > &dis, int count){
        cout << "index " << index << endl;
        if(count == dis.size() - 1){
            return 0;
        }
        int min = 0x7fffffff;
        int min_position;
        for(int i=1; i<=dis.size()-1; i++){
            if(visited[i] == false){
                visited[i] = true;
                int a = visit(i, dis, count+1) + dis[index][i];
                visited[i] = false;
                if(min > a){
                    min_position = i;
                    min = a;
                }
            }
        }
        cout << "*" << endl;
        trace.push(min_position);

        return min;
    }

    int visit_outer(vector<vector<int> > &dis){
        int min = 0x7ffffff;
        int min_position;
        for(int i=1; i<dis.size(); i++){
            visited[i] = true;
            int a = visit(i, dis, 1);
            visited[i] = false;
            if(min > a){
                min_position = i;
                min = a;
            }
        }
        cout << "*" << endl;
        trace.push(min_position);

        return min;
    }

    int business_visit(vector<vector<int> > &dis){
        visited.assign(dis.size(), false);
        int output = visit_outer(dis);
        cout << "trace is: ";
        for(int i=0; i<trace.size(); i++){
            cout << trace.top() << " ";
            trace.pop();
        }
        cout << endl;
        return output;
    }
};

int main(){
    vector<int> line0 = {0, 0, 0, 0};
    vector<int> line1 = {0, 0, 2, 3};
    vector<int> line2 = {0, 1, 0, 4};
    vector<int> line3 = {0, 5, 1, 0};
    vector<vector<int> > input;
    input.push_back(line0);
    input.push_back(line1);
    input.push_back(line2);
    input.push_back(line3);

    cout << "solution:" << Solution().business_visit(input) << endl;

    return 0;
}