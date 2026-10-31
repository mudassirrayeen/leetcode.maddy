
class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int flowers = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                flowers++;

                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1LL * m * k > bloomDay.size()) {
            return -1;
        }

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
