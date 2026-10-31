
class Solution {
public:
    int mySqrt(int n) {
        int ans = 0;
        int start = 0;
        int end = n;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(1LL * mid * mid <= n) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
