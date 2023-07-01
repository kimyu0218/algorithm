#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    map<string, int> idx = {{"-", -1}}; // (판매원 이름 : 판매원 번호)
    for(int i = 0; i < n; i++) {
        idx[enroll[i]] = i;
    }
    map<int, int> parent; // (판매원 번호 : 상위 판매원 번호)
    for(int i = 0; i < referral.size(); i++) {
        parent[i] = idx[referral[i]];
    }

    vector<int> answer (n, 0);
    for(int i = 0; i < seller.size(); i++) {
        int id = idx[seller[i]]; // 판매원 번호
        int p = amount[i] * 100; // 판매 수익
        while(id != -1 && p > 0) {
            int div = p * 0.1;
            answer[id] += (p - div);
            p = div;
            id = parent[id];
        }
    }
    return answer;
}