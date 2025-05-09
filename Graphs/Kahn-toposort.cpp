/*
Step-by-Step Implementation

Calculate the in-degree (number of incoming edges) for each vertex
Add all vertices with in-degree 0 to a queue
While the queue is not empty:

Remove a vertex from the queue and add it to the result
For each neighbor of this vertex, reduce its in-degree by 1
If any neighbor's in-degree becomes 0, add it to the queue


If the result list contains all vertices, it's a valid topological sort; otherwise, the graph has a cycle
*/

#include <bits/stdc++.h>
using namespace std;

class MyClass {
private:

    vector<long long> ans;
    vector<long long> inDegree;
    queue<long long> nodeQ;
    vector<vector<long long>> children;

public:

    void reduceInDegreeOfChildren(long long curr) {
        for (long long child : children[curr]) {

            inDegree[child]--;
            if (!inDegree[child])
                nodeQ.push(child);
        }
    }

    void khansTopoSort() {

        while (!nodeQ.empty()) {
            long long curr = nodeQ.front(); nodeQ.pop();
            ans.push_back(curr);

            reduceInDegreeOfChildren(curr);
        }

    }

};