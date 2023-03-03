// Longest Common Subsequence
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
    string str1,str2;
    cout << "Enter the two strings: ";
    cin >> str1 >> str2;

    int n = str1.length() + 1,m = str2.length() + 1;
    vector<vector<int>> v(n,vector<int>(m,0));

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(str1[i] == str2[j]){
                v[i][j] = 1 + v[i-1][j-1];
            }

            else{
                v[i][j] = max(v[i-1][j],v[i][j-1]);
            }
        }
    }

    cout << "The longest common subsequence count is: " << v[n-1][m-1] << endl;
    return 0;
}