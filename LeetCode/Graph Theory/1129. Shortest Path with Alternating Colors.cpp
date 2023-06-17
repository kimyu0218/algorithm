class Solution {
public:
    // answer[x] : the length of the shortest path from 0 to x
    struct info {
        int node, color, dist;
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red_edges (n, vector<int> (0)), blue_edges (n, vector<int> (0));
        for(int i = 0; i < redEdges.size(); i++) {
            red_edges[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i = 0; i < blueEdges.size(); i++) {
            blue_edges[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        vector<int> answer(n, -1);
        queue<info> q;

        answer[0] = 0;
        for(int i = 0; i < red_edges[0].size(); i++) {
            q.push({red_edges[0][i], 1, 1});
            red_edges[0][i] = -1;
        }
        for(int i = 0; i < blue_edges[0].size(); i++) {
            q.push({blue_edges[0][i], 2, 1});
            blue_edges[0][i] = -1;
        }

        while(!q.empty()) {
            int node = q.front().node;
            int color = q.front().color;
            int dist = q.front().dist;
            q.pop();

            if(answer[node] == -1) {
                answer[node] = dist;
            }

            if(color == 1) { // use blue edge
                for(int i = 0; i < blue_edges[node].size(); i++) {
                    int next_node = blue_edges[node][i];
                    if(next_node == -1) {
                        continue;
                    }
                    q.push({next_node, 2, dist+1});
                    blue_edges[node][i] = -1;
                }
            }
            else { // use red edge
                for(int i = 0; i < red_edges[node].size(); i++) {
                    int next_node = red_edges[node][i];
                    if(next_node == -1) {
                        continue;
                    }
                    q.push({next_node, 1, dist+1});
                    red_edges[node][i] = -1;
                }
            }
        }
        return answer;
    }
};