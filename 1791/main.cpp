/* 1791. Find Center of Star Graph
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

class Solution2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> heap;
        for (vector<int> edge : edges) {
            for (int ed : edge) {
                heap.push_back(ed);
            }
        }
        sort(heap.begin(), heap.end());
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == heap [i+1]) {
                return heap[i];
            }
        }
    return -1;
    }
};


class Solution1 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> connections;

        for (vector<int> edge : edges) {
            connections[edge[0]]++;
            connections[edge[1]]++;
        }

        for (pair<int,int> nodes : connections) {
            int node = nodes.first;
            int nodeConnections = nodes.second;

            if (nodeConnections == edges.size()) {
                return node;
            }
        }
        return -1;
    }
};
