//total number of subarrays having a given XOR k
//if TLE, use vector instead of map
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
};


int main()
{   vector<int> A{ 4,2,2,6,4 };
    Solution obj;
    int totalCount= obj.solve(A,6);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}
