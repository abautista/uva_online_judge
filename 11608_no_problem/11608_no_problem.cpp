#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int n_problems_available, case_number = 1;
    vector<int> v;
    int n_problems_created, n_problems_required;

    while (cin >> n_problems_available) {
        if (n_problems_available < 0) break;

        v.clear();
        cout << "Case " << case_number++ << ":" << endl;
        for (int i = 0; i < 12; i++) {
            cin >> n_problems_created;
            v.push_back(n_problems_created);
        }

        for (int i= 0; i < 12; i++) {
            cin >>  n_problems_required;
            if (n_problems_available >= n_problems_required) {
                n_problems_available -= n_problems_required;
                cout << "No problem! :D";
            } else {
                cout << "No problem. :(";
            }
            n_problems_available = n_problems_available + v[i];
            cout << endl;
        }
    }
    return 0;
}
