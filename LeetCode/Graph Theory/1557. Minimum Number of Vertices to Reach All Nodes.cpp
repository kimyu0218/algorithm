class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> fan_in(n, false);
        for(int i = 0; i < edges.size(); i++) {
            fan_in[edges[i][1]] = true;
        }

        vector<int> answer;
        for(int i = 0; i < n; i++) {
            if(!fan_in[i]) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};