class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
// sorting -> willbe needed for our approach
        std::sort(nums.begin() , nums.end());

// Base Case
        if(nums.size() < 3)
            return {};
        if(nums[0] > 0)
            return {};
       
// Result vector defined
        std::vector<std::vector<int>> answer;
        
        for(int i = 0 ; i < nums.size() ; ++i){
// no. is positive continueing is useless
            if(nums[i] > 0)
                break;
// duplicate needs to be ignored
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

// initialize pointer and sum
            int low = i + 1 , high = nums.size() - 1, sum = 0;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
// sum is +ve so reduce higher val
                if(sum > 0)
                    high--;
// sum is -ve so increase lower value
                else if(sum < 0)
                    low++;
// we got the result string -> push to answer
                else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high]; 
// Avoid duplicate by traversing to last occurance of low and high
                    while(low < high && nums[low] == last_low_occurence)
                        low++;
                    while(low < high && nums[high] == last_high_occurence)
                        high--;
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};