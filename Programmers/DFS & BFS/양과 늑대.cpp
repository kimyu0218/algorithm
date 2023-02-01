#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int node, int sheep, int wolf, vector<int> next_node, vector<vector<int>> adj_list, vector<int> info, vector<vector<int>> edges) {
    if(info[node]) wolf++;
    else sheep++;

    if(sheep <= wolf) return; // 양이 다 잡아 먹히는 경우 탐색 종료
    answer = max(answer, sheep);

    // node에서 방문 가능한 노드 순차적으로 방문
    for(int i = 0; i < next_node.size(); i++) {
        int node2 = next_node[i];
        vector<int> next = next_node;
        next.erase(next.begin() + i);

        for(int j = 0; j < adj_list[node2].size(); j++)
            next.push_back(adj_list[node2][j]);

        // node에서 방문할 수 있는 노드 & node2에서 방문할 수 있는 노드 방문
        dfs(node2, sheep, wolf, next, adj_list, info, edges);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    // 인접 리스트 만들기
    vector<vector<int>> adj_list(info.size(), vector<int> (0));
    for(int i = 0; i < edges.size(); i++)
        adj_list[edges[i][0]].push_back(edges[i][1]);

    vector<int> next_node;
    for(int i = 0; i < adj_list[0].size(); i++) // 루트 노드와 연결된 노드 push
        next_node.push_back(adj_list[0][i]);

    dfs(0, 0, 0, next_node, adj_list, info, edges);
    return answer;
}