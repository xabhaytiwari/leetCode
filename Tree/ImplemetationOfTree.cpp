#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree {
    vector<vector<int>> adjMatrix;
    int Root;
    public:

        Tree(int N, int Root) {
            adjMatrix.resize(N + 1);
            this->Root = Root;
        }

        // Fucntion to add an edge between vertices x and y
        void addEdge (int x, int y) {
            adjMatrix[x].push_back(y);
            adjMatrix[y].push_back(x);
        }

        // Fucntion to print the parents of each node
        void printParents (int node, int parent) {
            // current node is Root, thus, has no parent
            if (parent == 0) {
                cout << node << " -> Root" << "\n";
            } else {
                cout << node << " -> " << parent << "\n";
            }

            for (const auto cur : adjMatrix[node]) {
                if (cur != parent) {
                    printParents(cur, node);
                }
            }
        }

        // Function to print the children of each node
        void printChildren () {
            queue<int> q;

            q.push(Root);

            int visited[adjMatrix.size()] = {0};

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                visited[node] = 1;
                cout << node << " -> ";
                for (const auto cur : adjMatrix[node]) {
                    if(!visited[cur]) {
                        cout << cur << " ";
                        q.push(cur);
                    }
                }
                cout << "\n";
            }
        }

        //Function to print the leaf nodes
        void printLeafNodes () {
            for (int i = 1; i < adjMatrix.size(); i++) {
                if (adjMatrix[i].size() == 1 && i != Root) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
};

int main () {
    Tree object(7, 1);

    object.addEdge(1, 2);
    object.addEdge(1, 3);
    object.addEdge(1, 4);
    object.addEdge(2, 5);
    object.addEdge(2, 6);
    object.addEdge(4, 7);

    object.printParents(1, 0);
    object.printChildren();
    object.printLeafNodes();

    return 0;
}