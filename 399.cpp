#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> fa;
    vector<double> value;
    map<string, int> nameid;
    
    int getid(string &s){
        map<string, int>::iterator it = nameid.find(s);
        if(it == nameid.end()){
            nameid[s] = nameid.size();
        }
        return nameid[s];
    }
    
    void merge(int u, int v, double w){
        int fu = findroot(u);
        int fv = findroot(v);
        if(fu != fv){
            fa[v] = u;
            value[v] = w;
            compress(v);
        }
    }

    void compress(int u){
        int start = u;
        int v = value[u];
        while(fa[u] != u){
            v = v * value[fa[u]];
            u = fa[u]; 
        }
        value[start] = v;
        fa[start] = u;
    }

    int findroot(int u){
        while(fa[u] != u){
            u = fa[u];
        }
        return u;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n;
        for(int i=0; i<equations.size(); i++){
            int u = getid(equations[i][0]);
            int v = getid(equations[i][1]);
        }
        n = nameid.size();
        //遍历后可知道节点个数
        fa.resize(n);
        value.resize(n);
        for(int i=0; i<n; i++){
            fa[i] = i;
            value[i] = 1;
        }
        
        for(int i=0; i<equations.size(); i++){
            int v = getid(equations[i][0]);
            int u = getid(equations[i][1]);
            merge(u, v, values[i]);
            for(int o=0; o<value.size(); o++){
                cout << o << " ";
            }
            cout << endl;
        }
        
        vector<double> ans;
        for(int i=0; i<queries.size(); i++){
            int u= getid(queries[i][0]);
            int v= getid(queries[i][1]);
            double tmp = -1;
            if(u<n && v<n && findroot(u) == findroot(v)){
                //计算
                //a/c
                tmp = value[u]/value[v];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main(){
    vector<vector<string>> equations;
    vector<string> e1 = {"a", "b"};
    vector<string> e2 = {"e", "f"};
    vector<string> e3 = {"b", "e"};
    equations.push_back(e1);
    equations.push_back(e2);
    equations.push_back(e3);
    vector<double> values = {3.4, 1.4, 2.3};
    vector<vector<string>> queries;
    vector<string> q1 = {"b", "a"};
    vector<string> q2 = {"a", "f"};
    vector<string> q3 = {"f", "f"};
    vector<string> q4 = {"e", "e"};
    vector<string> q5 = {"c", "c"};
    vector<string> q6 = {"a", "c"};
    vector<string> q7 = {"f", "e"};
    queries.push_back(q1);
    queries.push_back(q2);
    queries.push_back(q3);
    queries.push_back(q4);
    queries.push_back(q5);
    queries.push_back(q6);
    queries.push_back(q7);

    Solution().calcEquation(equations, values, queries);
}




// class Solution {
// public:
//     vector<int> fa;
//     vector<double> value;
//     map<string, int> nameid;
    
//     int getid(string &s){
//         map<string, int>::iterator it = nameid.find(s);
//         if(it == nameid.end()){
//             nameid[s] = nameid.size();
//         }
//         return nameid[s];
//     }
    
//     void merge(int u, int v, double w){
//         int fu = getfa(u);
//         int fv = getfa(v);
//         if(fu != fv){
//             fa[v] = u;
//             value[v] = w;
//         }
//         getfa(u);
//         getfa(v);
//         cout << "u: " << u << " v; " << v << endl;
//         cout << value[v] << endl;
//     }
    
//     int getfa(int u){
//         if(fa[u] != u){
//             int newfa = getfa(fa[u]);
//             value[u] = value[u] * value[fa[u]];
//             fa[u] = newfa;
//         }
//         return fa[u];
//     }
    
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         int n;
//         for(int i=0; i<equations.size(); i++){
//             int u = getid(equations[i][0]);
//             int v = getid(equations[i][1]);
//         }
//         n = nameid.size();
//         //遍历后可知道节点个数
//         fa.resize(n);
//         value.resize(n);
//         for(int i=0; i<n; i++){
//             fa[i] = i;
//             value[i] = 1;
//         }
        
//         for(int i=0; i<equations.size(); i++){
//             int v = getid(equations[i][0]);
//             int u = getid(equations[i][1]);
//             merge(u, v, values[i]);
//         }
        
//         vector<double> ans;
//         for(int i=0; i<queries.size(); i++){
//             int u= getid(queries[i][0]);
//             int v= getid(queries[i][1]);
//             double tmp = -1;
//             if(u<n && v<n && getfa(u) == getfa(v)){
//                 //计算
//                 //a/c
//                 tmp = value[u]/value[v];
//             }
//             ans.push_back(tmp);
//         }
//         return ans;
//     }
// };