#include "GraphType.h"
#include <iostream>
using namespace std;

int main(){
    GraphType<int> graph;
    int computers, pairs;
    cin >> computers;
    for (int i = 0; i < computers; i++){
        graph.AddVertex(i);
    }
    cin >> pairs;
    int from, to;
    for (int i = 0; i < pairs; i++){
        cin >> from; cin >> to;
        graph.AddEdge(from, to, 1);
    }

    int count = 1;  // 0번 포함
    for (int i = 1; i < computers; i++){
        if (graph.DepthFirstSearch(0,i))
            count ++;
    }

    cout << endl << count << endl;

    
    return 0;
}