#include <iostream>
#include <map>

using namespace std;
map<string, int> tree;

int main() {
    int count = 0;
    char name[31];

    while(cin.getline(name, 31)) {
        count++;
        if(tree.find(name) == tree.end()) tree.insert({name, 1});
        else tree[name]++;
    }

    cout<<fixed;
    cout.precision(4);
    for(auto & iter : tree)
        cout << iter.first << " " << (double) iter.second/count * 100 << '\n';
    return 0;
}