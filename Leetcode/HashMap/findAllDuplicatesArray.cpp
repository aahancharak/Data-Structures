#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>retVal;
        //O(n) time and O(n) space easy with hashmap
        //will use self marking to do O(1) time complexity
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0) retVal.push_back(abs(nums[i]));
            else{
                nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1];
            }
        }
        return retVal;
    }
};