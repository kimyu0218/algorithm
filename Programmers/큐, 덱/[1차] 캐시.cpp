#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct info {
    string city;
    int order;
};

char toLowerCase(char c) { // 소문자 변환
    if(c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int lru(int size, vector<string> &cities) {
    int time = 0;
    queue<info> q; // 큐
    map<string, int> cache; // 캐시

    for(int i = 0; i < cities.size(); i++) {
        string city = "";
        for(int j = 0; j < cities[i].length(); j++) {
            city += toLowerCase(cities[i][j]);
        }

        if(cache[city]) { // cache hit
            time += 1;
        }
        else { // cache miss
            time += 5;
            cache.erase(city); // (cache[city]로 인해 캐시에 city가 들어갔기 때문에 제거 필요)
            if(cache.size() == size) { // 캐시 교체 필요
                while(!q.empty()) {
                    string pre = q.front().city;
                    int order = q.front().order;
                    q.pop();

                    if(order == cache[pre]) { // lru 발견
                        cache.erase(pre); // pre 도시 삭제
                        break;
                    }
                }
            }
        }
        if(size == 0) { // 캐시 사이즈가 0인 경우 캐시에 넣지 않음
            continue;
        }

        // 캐시에 city 저장하기
        cache[city] = i+1;
        q.push({city, i+1});
    }
    return time;
}

int solution(int cacheSize, vector<string> cities) {
    return lru(cacheSize, cities);
}