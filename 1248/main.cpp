/* 1248. Count Number of Nice Subarrays
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/

class DidNotWorkSolution {
public:
    int oddCount(vector<int> subNums, int k){
        int subCount = 0;
        int count = 0;
        for (int num : subNums)
        {
            if (num % 2 != 0)
            {
                subCount++;
            }

            if (subCount % k == 0)
            {
                count++;
            }
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        int winStart = -1, winEnd = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - winEnd; i++)
        {
            for (int j = 0; j < nums.size() - winEnd; j++)
            {
                winStart++;
                winEnd++;
                cout << "winStart: " << winStart << " winEnd: " << winEnd << endl;
                vector<int> subNums(nums.begin()+winStart, nums.begin()+winEnd);
                for (int a = 0; a < subNums.size(); a++){cout << subNums[a] << " ";}
                cout << endl;
                ans += oddCount(subNums,k);
                cout << "ans: " << ans << endl;
            }
        winStart = -1;
        winEnd = i;
        if (winEnd > k)
        {
            break;
        }
        }
        return ans;
    }
};

class leetCodeSolution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);    // make a new vector (cnt) using constructor of nums.size()+1, 0...
        cnt[0] = 1;                   // set first value of cnt to 1
        int ans = 0, t = 0;           // initialize answer (ans) and t...emp (t)
        for (int v : nums) {          // for each integer (int v) in the nums vector
            t += v & 1;               // add v & 1 (operator integer & 1 == true (1) or false (0)
            if (t - k >= 0) {         // compare difference of t - k (# number of odd #s in substring) to whether it's >= 0
                ans += cnt[t - k];    // when it is >= then add the cnt value at iterator [t-k] to ans
            }
            cnt[t]++;                 // increment "cnt[t]" which moves t... forwards?
        }
        return ans;
    }
};
