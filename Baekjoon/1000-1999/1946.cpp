#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(int n, vector<pi> applicants) {
    int result = 1;
    sort(applicants.begin(), applicants.end());

    int lowest_interview_rank = applicants[0].second;
    for(int i = 1; i < n; i++) {
        int interview_rank = applicants[i].second;
        if(interview_rank < lowest_interview_rank) {
            result++;
            lowest_interview_rank = interview_rank;
        }
    }
    return result;
}

int main() {
    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;

        vector<pi> applicants(n, {0, 0});
        for(int i = 0; i < n; i++) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        cout << solution(n, applicants) << '\n';
    }
    return 0;
}