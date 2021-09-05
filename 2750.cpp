#include <iostream>
#include <vector>

using namespace std;
vector<int> arr; // 정렬할 배열

void bubbleSort(int n) {
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                flag = false;
                swap(arr[j], arr[j+1]);
            }
        }
        if(flag) break;
    }
}

int main() {
    int n;
    cin >> n; // 입력

    arr.assign(n,0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    return 0;
}