class Solution {
public:
    const int INF = 1e8 + 1;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> relation(n, vector<int> (0));
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                relation[manager[i]].push_back(i);
            }
        }

        int answer = 0;
        queue<int> q;
        vector<int> time(n, INF);

        time[headID] = 0;
        q.push(headID);

        while(!q.empty()) {
            int emp = q.front();
            q.pop();

            for(int i = 0; i < relation[emp].size(); i++) {
                int sub = relation[emp][i];
                int tmp = time[emp] + informTime[emp];
                if(time[sub] == INF) {
                    time[sub] = tmp;
                    answer = max(answer, time[sub]);
                    q.push(sub);
                }
            }
        }
        return answer;
    }
};