class Solution {
public:
    const int IDX = 1e4, SIZE = 2 * 1e4+ 1;
    typedef pair<int, int> pi;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer, freq (SIZE, 0);
        priority_queue<pi> pq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]+IDX]++;
            pq.push({freq[nums[i]+IDX], nums[i]});
        }

        while(k--) {
            while(true) {
                int num = pq.top().second;
                int fq = pq.top().first;
                pq.pop();
                if(fq == freq[num+IDX]) {
                    answer.push_back(num);
                    break;
                }
            }
        }
        return answer;
    }
};