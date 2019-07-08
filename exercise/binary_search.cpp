#include <cstdio>
#include <iostream> 

using namespace std;

int binary_search(int nums[], int start, int end, int elem);
int upper_bound(int nums[], int start, int end, int elem);
int lower_bound(int nums[], int start, int end, int elem);


int main(){
    int nums[] = {1, 3, 6, 7, 8, 13, 16, 20};
    cout << binary_search(nums, 0, 8, 20) << endl;
    cout << upper_bound(nums, 0, 8, 7) << endl;
    cout << lower_bound(nums, 0, 8, 7) << endl;
    return 0;
}

int binary_search(int nums[], int start, int end, int elem){
    int L = start;
    int R = end - 1;
    while(L <= R){
        int mid = (L + R) / 2;
        if(nums[mid] == elem){
            return mid;
        }
        else if(nums[mid] < elem){
            L = mid + 1;
        }else{
            R = mid - 1;
        }
    }
    return -1;
}

int upper_bound(int nums[], int start, int end, int elem){
    int L = start;
    int R = end;
    while(L < R){
        int mid = (L + R) / 2;
        if(nums[mid] <= elem){
            L = mid + 1;
        }else{
            R = mid;
        }
    }
}

int lower_bound(int nums[], int start, int end, int elem){
    int L = start;
    int R = end;
    while(L < R){
        int mid = (L + R) / 2;
        if(nums[mid] < elem){
            L = mid + 1;
        }else{
            R = mid;
        }
    }
}