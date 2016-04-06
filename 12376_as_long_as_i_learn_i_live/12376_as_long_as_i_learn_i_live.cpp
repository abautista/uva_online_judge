#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    vector<int> neighbors;
};

void print_adj_list(const vector<Node>& adj_list)
{
    for (int i = 0; i < (int)adj_list.size(); i++) {
        int node_value = adj_list[i].value;
        vector<int> node_neighbors = adj_list[i].neighbors;
        cout << node_value << ": ";
        for (int j = 0; j < (int)node_neighbors.size(); j++) {
            cout << node_neighbors[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void greed_traversal(const vector<Node>& adj_list)
{
    int total_value = 0;
    int current_node_index = 0;
    
    for (;;) {
        Node current_node = adj_list[current_node_index];
        if (current_node.neighbors.size() == 0) {
            break;
        }
        
        int max_value = 0;
        
        for (int i = 0; i < (int)current_node.neighbors.size(); i++) {
            Node neighbour_node = adj_list[current_node.neighbors[i]];
            if (neighbour_node.value > max_value) {
                max_value = neighbour_node.value;
                current_node_index = current_node.neighbors[i];
            }
        }

        total_value += max_value;
    }

    cout << total_value << " " << current_node_index << endl;
}

int main(int argc, char *argv[])
{
    int num_test_cases;
    int num_nodes, num_edges;
    int u, v;
    
    vector<Node> adj_list;
    
    cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; i++) {
        cin >> num_nodes;
        cin >> num_edges;

        adj_list.assign(num_nodes, {});
        
        for (int j = 0; j < num_nodes; j++) {
            cin >> adj_list[j].value;
        }

        for (int j = 0; j < num_edges; j++) {
            cin >> u;
            cin >> v;
            adj_list[u].neighbors.push_back(v);
        }
        
        //print_adj_list(adj_list);
        cout << "Case " << i + 1 << ": ";
        greed_traversal(adj_list);
    }
    return 0;
}
