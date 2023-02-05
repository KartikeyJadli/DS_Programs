#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    int n,count = 0;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> v(n);
    int val;
    for (int i=0;i<n;i++) {
        cin >> v[i];
        // v.push_back(val);
        mp[v[i]]++;
    }
    
    sort(v.begin(),v.end());
    int ansleft = 0, ansrright = 0, len = 0;
    int l = 0, r = 0;

    // for(auto i: mp){
    //     cout << i.first << " " << i.second << endl;
    //     if(i.second <= 1){
    //         count += i.second;
    //     }

    //     if(i.second == 1){
    //         count++;
    //         break;
    //     }
    // }

    // cout << count << endl;

    for(int i=0;i<n;i++) {
        if (abs(v[i] - v[i - 1]) <= 1 && mp[v[i]] > 1){
            r = i;
        }

        else {
            if (abs(v[i] - v[i - 1]) <= 1 && mp[v[i]] == 1){
                r = i;
            }

            if (len < r - l + 1) {
                len = r - l + 1;
                ansleft = l;
                ansrright = r;
            }

            l = i;
        }
    }

    if (len < r - l + 1) {
        len = r - l + 1;
        ansleft = l;
        ansrright = r;
    }

    cout << len << endl;
    multiset<int> s;
    for (int i = ansleft; i <= ansrright; ++i) {
        s.insert(v[i]);
    }

    int temp = 0;

    while(s.size()) {
        auto pos = s.upper_bound(temp);
        if (pos == s.end()){
            break;
        }

        else {
            cout << *pos << " ";
        }

        temp = *pos;
        s.erase(pos);
    }

    while(s.size()) {
        auto pos = --s.end();
        cout << *pos << " ";
        s.erase(pos);
    }

    return 0;
}