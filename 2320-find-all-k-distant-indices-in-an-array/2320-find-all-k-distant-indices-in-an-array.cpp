class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int n=nums.size();
        vector<int> ans;
        short sweep[1001]={0}, maxS=-1;
        for(int i=0; i<n; i++){
            if (nums[i]==key){
                const int up=min(n, i+k+1), low=max(0, i-k);
                sweep[low]++;// interval starts
                sweep[up]--; // interval ends
                maxS=up;
            }
        }

        int cnt=0;
        for(int x=0; x<=maxS; x++){
            cnt+=sweep[x];
            if (cnt>0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};