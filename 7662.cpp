#include <iostream>
#include <queue>

using namespace std;
bool visited[1000001] = {false, }; // 삭제 여부 표시하는 배열
typedef pair<int, int> op;

void insert_num(int i, int n, priority_queue<op, vector<op>> &max_queue, priority_queue<op, vector<op>, greater<>> &min_queue) { // 데이터 삽입
    max_queue.push({n, i});
    min_queue.push({n, i});
    visited[i] = true;
}

void delete_max(priority_queue<op, vector<op>> &max_queue) { // 최댓값 pop
    while(!visited[max_queue.top().second] && !max_queue.empty()) max_queue.pop();
    if(!max_queue.empty()) {
        visited[max_queue.top().second] = false;
        max_queue.pop();
    }
}

void delete_min(priority_queue<op, vector<op>, greater<>> &min_queue) { // 최솟값 pop
    while(!visited[min_queue.top().second] && !min_queue.empty()) min_queue.pop();
    if(!min_queue.empty()) {
        visited[min_queue.top().second] = false;
        min_queue.pop();
    }
}

void delete_num(int n, priority_queue<op, vector<op>> &max_queue, priority_queue<op, vector<op>, greater<>> &min_queue) { // 데이터 삭제
    if(n == 1 && !max_queue.empty()) delete_max(max_queue); // 최댓값 pop
    else if(n == -1 && !min_queue.empty()) delete_min(min_queue); // 최솟값 pop
}

void operation(int k, priority_queue<op, vector<op>> &max_queue, priority_queue<op, vector<op>, greater<>> &min_queue) {
    char cmd;
    int num;
    for(int i = 0; i < k; i++) { // 연산
        cin >> cmd >> num;
        if (cmd == 'I') insert_num(i, num, max_queue, min_queue);
        else if (cmd == 'D') delete_num(num, max_queue, min_queue);
    }
}

void print_result(priority_queue<op, vector<op>> &max_queue, priority_queue<op, vector<op>, greater<>> &min_queue) {
    while(!max_queue.empty()) { // 최댓값 출력하기
        if(visited[max_queue.top().second]) {
            cout << max_queue.top().first  << ' ';
            break;
        }
        max_queue.pop();
    }

    if(max_queue.empty()) {
        cout << "EMPTY\n";
        return;
    }

    while(!min_queue.empty()) { // 최솟값 출력하기
        if(visited[min_queue.top().second]) {
            cout << min_queue.top().first << '\n';
            break;
        }
        min_queue.pop();
    }
}

int main() {
    int t, k;
    cin >> t;

    while(t--) {
        cin >> k;
        priority_queue<op, vector<op>> max_queue;
        priority_queue<op, vector<op>, greater<>> min_queue;
        operation(k, max_queue, min_queue); // 연산
        print_result(max_queue, min_queue); // 결과 출력
    }
    return 0;
}