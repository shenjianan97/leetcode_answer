#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > save;

    int search(int ix, int iy, vector<char> &x, vector<char> &y){
        if(ix >= x.size() || iy >= y.size()){
            return 0;
        }
        if(save[ix][iy] >= 0){
            return save[ix][iy];
        }
        if(x[ix] == y[iy]){
            int a = search(ix+1, iy+1, x, y) + 1;
            save[ix][iy] = a;
            return a;
        }else{
            int a = max(search(ix+1, iy, x, y), search(ix, iy+1, x, y));
            save[ix][iy] = a;
            return save[ix][iy];
        }
    }

    int longest_subrequence(vector<char> &x, vector<char> &y){
        save.assign(x.size(), vector<int> (y.size(), -1));
        return search(0, 0, x, y);
    }
};

int main(){
    vector<char> x = {'x', 'c', 'd', 'g', 'q', 'x', 'l', 'a', 'p'};
    vector<char> y = {'c' ,'x', 'b', 'd', 'g', 'l', 'a'};
    cout << Solution().longest_subrequence(x, y);
}