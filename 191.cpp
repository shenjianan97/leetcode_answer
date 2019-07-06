class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_1 = 0;
        for(int i=0; i < 32; i++){
            num_1 += n & 1;
            n = n >> 1;
        }
        return num_1;
    }
};