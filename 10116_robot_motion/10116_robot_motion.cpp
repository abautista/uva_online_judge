#include <iostream>
#include <vector>

using namespace std;

int rows, columns, starting_column, grid_size;

bool check_exit_from_grid(int position, char grid_value)
{
    if (0 <= position && position < columns && grid_value == 'N') {
        return true;
    }
    if ((grid_size - columns) <= position && position < grid_size && grid_value == 'S') {
        return true;
    }
    if (position % columns == 0 && grid_value == 'W') {
        return true;
    }
    if (position % columns == (columns -1) && grid_value == 'E') {
        return true;
    }
    return false;
}

int update_position(int position, char grid_value)
{
    if (grid_value == 'N') {
        position -= columns;
    } else if (grid_value == 'S') {
        position += columns;
    } else if (grid_value == 'E') {
        position += 1;
    } else if (grid_value == 'W') {
        position -= 1;
    }
    return position;
}

int main(int argc, char *argv[])
{
    cin >> rows >> columns >> starting_column;
    grid_size = rows * columns;
    
    vector<char> grid;
    vector<int> step_visited;
    
    while (rows != 0 && columns != 0 && starting_column != 0) {
        for (int i = 0; i < grid_size; i++) {
            char cell;
            cin >> cell;
            grid.push_back(cell);
        }

        step_visited.assign(grid_size, -1);
        int steps = 0;
        int position = starting_column - 1;
 
        while (true) {
            char grid_value = grid[position];
        
            if (check_exit_from_grid(position, grid_value)) {
                cout << steps + 1 << " step(s) to exit" << endl;
                break;
            }
    
            if (step_visited[position] != -1) {
                cout << step_visited[position] << " step(s) before a loop of ";
                cout << steps - step_visited[position]<< " step(s)" << endl;
                break;
            } else {
                step_visited[position] = steps;
            }
            
            position = update_position(position, grid_value);            
            steps += 1;            
        }
        
        cin >> rows >> columns >> starting_column;
        position = starting_column - 1;
        grid_size = rows * columns;
        grid.clear();
    }
}
