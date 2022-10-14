class Main {
public:
    int threeSumwhichisClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int N = nums.size();
        int diff = INT_MAX, answer;
        for(int i=0;i<N;i++)
        {
            int low = i+1;
            int high = N-1;
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(abs(sum-target)<diff)
                {
                    diff = abs(sum-target);
                    answer = sum;
                }
                if(sum==target)
                {
                    break;
                }
                else if(sum < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
       return answer;
    }
};
