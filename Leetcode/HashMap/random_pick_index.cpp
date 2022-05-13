class Solution {
public:
    Solution(vector<int>& nums) {  
       
        srand((unsigned int)time(NULL));
        int idx=0;
        for(int ele:nums){
         if(mappah.find(ele)==mappah.end()){
             mappah[ele] = vector<int>();
         }
            mappah[ele].push_back(idx);
            idx++;
        }
    }
    int random(int n){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distn(0,n);
    return distn(rng);
    }
    int pick(int target) {
        if(mappah.find(target)!=mappah.end()){
            int idx= random(mappah[target].size()-1);
            return mappah[target][idx];
        }
        return -1;
    }
    
    unordered_map<int, vector<int>>mappah;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
