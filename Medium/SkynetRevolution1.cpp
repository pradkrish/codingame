#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
  int src, dest;
};

// class to represent a graph 
class Graph
{
public:
  vector<vector<int>> adjList;

  Graph(vector<Edge> const &edges, int N) {
    adjList.resize(N);
    
    for (auto &edge: edges) {
      adjList[edge.src].push_back(edge.dest);
      adjList[edge.dest].push_back(edge.src);
    }
  }
};

int BFS(Graph const &graph, int v, int gateway,
        vector<int>& leftLink, vector<int>& rightLink)
{
  queue<int> q;
  q.push(v);
  
  int distance = -1;
  while (!q.empty()) {
    distance += 1;
    v = q.front();
    q.pop();
  
    for (int u : graph.adjList[v]) {
      q.push(u);

      if (u==gateway) {
	leftLink.push_back(v);
	rightLink.push_back(u);
	return distance;
      }
    }
  }
}

int main()
{
  int N; // the total number of nodes in the level, including the gateways
  int L; // the number of links
  int E; // the number of exit gateways
  cin >> N >> L >> E; cin.ignore();

  vector<Edge> edges;
  for (int i = 0; i < L; i++) {
    int N1; // N1 and N2 defines a link between these nodes
    int N2;
    cin >> N1 >> N2; cin.ignore();
    edges.push_back({N1,N2});
  }

  int EI; // the index of a gateway node
  vector<int> gateway;
  
  for (int i = 0; i < E; i++) {
    cin >> EI; cin.ignore();
    gateway.push_back(EI);
  }

  Graph graph(edges, N);

  // game loop
  while (1) {
    int SI; // The index of the node on which the Skynet agent is positioned this turn
    cin >> SI; cin.ignore();
    
    vector<int> distToGateway;
    vector<int> leftLink;
    vector<int> rightLink;
    
    // start BFS traversal from vertex i
    for (auto g : gateway) {
      distToGateway.push_back(BFS(graph, SI, g,
                              leftLink, rightLink));
    };
    int minIndex = std::min_element(distToGateway.begin(),distToGateway.end()) - 
                                    distToGateway.begin();
    cout << leftLink.at(minIndex) << " " << rightLink.at(minIndex) << endl;
  }

}
