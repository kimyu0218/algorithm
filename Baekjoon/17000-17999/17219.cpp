#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, string> sitemap;

void set_sitemap(vector<vector<string>> passwords) {
    int n = passwords.size();
    for(int i = 0; i < n; i++) {
        sitemap[passwords[i][0]] = passwords[i][1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string input;
    vector<vector<string>> passwords;

    cin >> n >> m;

    passwords.assign(n, vector<string> (2, ""));
    for(int i = 0; i < n; i++) {
        cin >> passwords[i][0] >> passwords[i][1];
    }

    set_sitemap(passwords);

    while(m--) {
        cin >> input;

        cout << sitemap[input] << '\n';
    }
    return 0;
}