#include <string>
#include <vector>
#include <map>

using namespace std;

const int HIT = 1;
const int MISS = 5;

string to_lower(string str) {
    int n = str.length();

    for(int i = 0; i < n; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void swap_out(map<string, int> &cache) {
    auto iter = cache.begin();
    auto out = iter;

    while(iter != cache.end()) {
        if(iter->second < out->second) {
            out = iter;
        }
        iter++;
    }
    cache.erase(out);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int n = cities.size();

    map<string, int> cache;

    for(int i = 0; i < n; i++) {
        string city = to_lower(cities[i]);
        int used = i + 1;

        if(cache[city]) {
            answer += HIT;
        }
        else {
            answer += MISS;
        }
        cache[city] = used;

        if(cache.size() > cacheSize) {
            swap_out(cache);
        }
    }
    return answer;
}