class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1){
            return 0;
        }
        int num[n];
        for(int i=0; i<n; i++){
            num[i] = i;
        }
        //notate number
        for(int i=2; i<n; i++){
            if(num[i] != 0){
                for(int j=2; i*j < n; j++){
                    num[i*j] = 0;
                }
            }
        }
        //count number
        int count = 0;
        for(int i=2; i<n; i++){
            if(num[i] != 0)
                count++;
        }
        
        return count;
    }
};