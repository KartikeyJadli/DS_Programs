/* PROBLEM STATEMENT 
   There are n
 people in a row. The height of the i
-th person is ai
. You can choose any subset of these people and try to arrange them into a balanced circle.

A balanced circle is such an order of people that the difference between heights of any adjacent people is no more than 1
. For example, let heights of chosen people be [ai1,ai2,…,aik], where k is the number of people you choose. Then the condition |a(ij)−a(ij+1)|≤1 should be satisfied for
all j from 1 to k−1 and the condition |a(i1)−a(ik)| ≤ 1 should be also satisfied. |x| means the absolute value of x.It is obvious that the circle consisting of one 
person is balanced.
Your task is to choose the maximum number of people and construct a balanced circle consisting of all chosen people. 
It is obvious that the circle consisting of one person is balanced so the answer always exists.

Input
The first line of the input contains one integer n(1 ≤ n ≤ 2*10^5) — the number of people.

The second line of the input contains n integers a1,a2,…,an (1 ≤ ai ≤ 2*10^5), where ai is the height of the i-th person.

Output
In the first line of the output print k
 — the number of people in the maximum balanced circle.

In the second line print k integers res1,res2,…,resk , where resj is the height of the j-th person in the maximum balanced circle. The condition |resj−resj+1|≤1
 should be satisfied for all j from 1 to k−1 and the condition |res1−resk|≤1 should be also satisfied.
 
 Examples
input
7
4 3 5 1 2 2 1
output
5
2 1 1 2 3

input
5
3 7 5 1 5
output
2
5 5 

input
3
5 1 4
output
2
4 5 

input
7
2 2 3 2 1 2 2
output
7
1 2 2 2 2 3 2
*/

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
