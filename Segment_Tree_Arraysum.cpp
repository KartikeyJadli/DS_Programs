#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int buildtreeutils(vector<int> &segTree,vector<int> &v,int ss,int sr,int index){
    if(ss == sr){
        segTree[index] = v[ss];
        return v[ss];
    }

    int mid = (ss + sr)/2;
    segTree[index] = buildtreeutils(segTree,v,ss,mid,2*index + 1) + buildtreeutils(segTree,v,mid+1,sr,2*index + 2);
    return segTree[index];
}

void buildtree(vector<int> &segTree,int s,vector<int> &v,int n){
    buildtreeutils(segTree,v,0,n-1,0);
}

void updation(vector<int> &segTree,int sl,int sr,int index,int value,int i){
    if(index < sl || index > sr)
        return;
    
    segTree[i] += value;

    if(sl != sr){
        int mid = (sl + sr)/2;
        updation(segTree,sl,mid,index,value,2*i + 1);
        updation(segTree,mid+1,sr,index,value,2*i + 2);
    }
}

void update(vector<int> &v,vector<int> &segTree,int n,int index,int value){
    int changedvalue = value - v[index];
    v[index] = value;

    updation(segTree,0,n-1,index,changedvalue,0);
}

int getsum(vector<int> &segTree,int sl,int sr,int ql,int qr,int i){
    if(qr < sl || sr < ql){
        return 0;
    }

    else if(ql <= sl && sr <= qr){
        return segTree[i];
    }

    else{
        int mid = (sl + sr)/2;
        return getsum(segTree,sl,mid,ql,qr,2*i + 1) + getsum(segTree,mid+1,sr,ql,qr,2*i + 2);
    }
}

int sum(vector<int> &segTree,int n,int left,int right){
    return getsum(segTree,0,n-1,left,right,0);
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v(n);
    
    cout << "Enter Vector elements: ";
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    size_t s = pow(2,ceil(log2(n)) + 1) - 1;
    cout << "Maximum size of segment Tree: " << s << endl;

    vector<int> segTree(s,0);
    buildtree(segTree,s,v,n);
    
    cout << "Segment Tree: ";
    for(int i=0;i<s;i++){
        cout << segTree[i] << " ";
    }
    cout << endl;
    
    int choice;
    int left,right,index,value;
    char ch;

    while(ch != 'n'){
        cout << endl;
        cout << "1. Update\t 2. Range-Sum\t 3. Print Segment Tree" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            cout << "Enter Index and Value: ";
            cin >> index >> value;
            update(v,segTree,n,index,value);
            break;
        
        case 2:
            cout << "Enter left-right range to find the sum: "; 
            cin >> left >> right;
            cout << "The sum in the range is: " << sum(segTree,n,left,right) << endl;
            break;

        case 3:
            // buildtree(segTree,s,v,n);
            cout << "Segment Tree after operations: ";
            for(int i=0;i<s;i++){
                cout << segTree[i] << " ";
            }
            cout << endl;
            break;
        }

        cout << "Do you want to continue(y/n): ";
        cin >> ch;
    }

    cout << "Program Finished" << endl;

    return 0;
}