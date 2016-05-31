#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int duration, number_of_tracks, track;
vector<int> tracks;

int sum(vector<int> v)
{
    return accumulate(v.begin(), v.end(), 0);
}

vector<int> backtrack(int n, vector<int> current_selection)
{
    if (sum(current_selection) == duration) {
        return current_selection;
    }
    vector<int> max_selection = current_selection;
    for (int i = n; i < tracks.size(); i++) {
        if (sum(current_selection) + tracks[i] <= duration) {
            vector<int> new_selection(current_selection);
            new_selection.push_back(tracks[i]);
            vector<int> selection = backtrack(i+1, new_selection);
            if (sum(selection) > sum(max_selection)) {
                max_selection = selection;
            }
        }
    }
    return max_selection;
}

int main(int argc, char *argv[])
{
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        tracks.clear();

        ss >> duration >> number_of_tracks;

        for (int i = 0; i < number_of_tracks; i++) {
            ss >> track;
            tracks.push_back(track);
        };
        vector<int> selection;
        vector<int> result;
        result = backtrack(0, selection);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "sum:"<< sum(result) << endl;
    }
}
