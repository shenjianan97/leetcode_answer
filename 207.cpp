#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int map[100][100];
    
    int visited[100];
    
    int num;
    
    int findIn(){
        for(int i=0; i<num; i++){
            if(visited[i] == 1)
                continue;
            bool allZero = true;
            for(int n=0; n<num; n++){
                if(map[n][i] != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero == true){
                visited[i] = 1;
                return i;
            }
        }
        return -1;
    }
    
    void setToZero(int n){
        for(int i=0; i<num; i++){
            map[n][i] = 0;
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        num = numCourses;
        for(int i=0; i<prerequisites.size(); i++){
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            map[x][y] = 1;
        }
        for(int i=0; i<numCourses; i++){
            int start = findIn();
            if(start == -1)
                return false;
            setToZero(start);
        }
        
        return true;
    }
};

int main(){
    vector<int> line1 = {0, 1};
    vector<int> line2 = {0, 2};
    vector<int> line3 = {2, 0};
    vector<vector<int>> input;
    input.push_back(line1);
    input.push_back(line2);
    input.push_back(line3);

    cout << Solution().canFinish(3, input);
}