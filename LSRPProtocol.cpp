#include "LSRPProtocol.hpp"

LSRPProtocol::LSRPProtocol() {

}

void LSRPProtocol::printSolution(vector<int> dis, vector<int> parent, int src) {
    int V = dis.size();
    
    for (int i = 0; i < V; i++) {
        int current = i;
        string path = "";
        while (current != src) {
            if (current == i) {
            path += to_string(current + 1);
            current = parent[current];
            }
            else {
                path += " <- " + to_string(current + 1);
                current = parent[current];
            }
        }
        path += " <- " + to_string(src + 1);

        cout << "Destination: " << i + 1 << "\t" << "Distance: " <<dis[i] << endl;
        cout << "Path: " << path << endl;
        cout << endl;
    }
}

void LSRPProtocol::print_iter(vector<int> dis) {
    int V = dis.size();
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i + 1 << " \t\t"<< dis[i] << endl;
    cout << endl;
}

void LSRPProtocol::perform_lsrp(vector<vector<int>> matrix, int src) {

    int V = matrix.size();

    // The output array. dist[i] is shortest distance from src to i
    vector<int> dist(V); 

    // If vertex i is included in shortest path tree or shortest distance from src to i is finalized
    vector<bool> sptSet(V); 

    // Initializing
    for (int i = 0; i < V; i++)
        dist[i] = MAX_NUM, sptSet[i] = false;

    dist[src] = 0;

    vector<int> parent(V, -1);

    // Find shortest path for all vertices
    for (int i = 0; i < V - 1; i++) {

        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        // Update distance value of the adjacent vertices of the chosen vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if is not in sptSet
            if (!sptSet[v] && matrix[u][v] && dist[u] != MAX_NUM && dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
                parent[v] = u;
            }
            
        }

        cout << "Iter " << i <<" Src:" << src + 1 << endl;
        cout << "-----------------------------" << endl;
        print_iter(dist);
                
    }

    cout << "Final iter, Src:" << src + 1 << endl;
    cout << "-----------------------------" << endl;
    printSolution(dist, parent, src);
}

int LSRPProtocol::minDistance(vector<int> dist, vector<bool> sptSet) {  
    int V = dist.size();
    // Initialize min value
    int min = MAX_NUM, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}