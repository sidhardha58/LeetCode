class Solution {
public:
    int possibleStringCount(string word, int k) {
         const int MOD = 1e9 + 7;
        if (word.empty()) return 0;

        vector<int> groups;
        int count = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        long long total = 1;
        for (int num : groups) {
            total = (total * num) % MOD;
        }

        if (k <= groups.size()) return static_cast<int>(total);

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int freq : groups) {
            vector<int> tempDp(k, 0);
            long long sum = 0;
            for (int i = 0; i < k; i++) {
                if (i > 0) sum = (sum + dp[i - 1]) % MOD;
                if (i > freq) sum = (sum - dp[i - freq - 1] + MOD) % MOD;
                tempDp[i] = static_cast<int>(sum);
            }
            dp = tempDp;
        }

        long long invalidCount = 0;
        for (int i = groups.size(); i < k; i++) {
            invalidCount = (invalidCount + dp[i]) % MOD;
        }

        return static_cast<int>((total - invalidCount + MOD) % MOD);
    }
};