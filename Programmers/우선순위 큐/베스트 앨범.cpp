#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct g_info {
    string genre;
    int cnt;
};

struct p_info {
    int cnt, idx;
};

bool cmp_genre(g_info &i1, g_info &i2) {
    return i1.cnt > i2.cnt;
}

struct cmp_play {
    bool operator()(p_info &p1, p_info &p2) {
        if(p1.cnt != p2.cnt) {
            return p1.cnt < p2.cnt;
        }
        return p1.idx > p2.idx;
    }
};

vector<g_info> sort_genres(int n, vector<string> genres, vector<int> plays) {
    vector<g_info> result;
    map<string, int> m;

    for(int i = 0; i < n; i++) {
        m[genres[i]] += plays[i];
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        result.push_back({iter->first, iter->second});
    }
    sort(result.begin(), result.end(), cmp_genre);
    return result;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    vector<g_info> sorted_g = sort_genres(n, genres, plays);

    for(int i = 0; i < sorted_g.size(); i++) {
        priority_queue<p_info, vector<p_info>, cmp_play> pq;

        for(int j = 0; j < n; j++) {
            if(genres[j] == sorted_g[i].genre) {
                pq.push({plays[j], j});
            }
        }

        int cnt = 2;
        while(!pq.empty() && cnt--) {
            answer.push_back(pq.top().idx);
            pq.pop();
        }
    }
    return answer;
}