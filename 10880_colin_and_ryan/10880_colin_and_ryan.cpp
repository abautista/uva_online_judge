#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int number_of_cases;
    cin >> number_of_cases;
    set<int> q;

    for (int i = 0; i < number_of_cases; ++i) {
        q.clear();
        int C, R, p;
        cin >> C >> R;
        p = C - R;

        cout << "Case #" << i + 1 << ":";
        if (p == 0) {
            cout << " 0";
        } else {
            for (int j = 1; j <= (int)sqrt(p) + 1; ++j) {
                if (p % j == 0) {
                    if (j > R) q.insert(j);
                    if (p / j > R) q.insert(p / j);
                }
            }
        }

        for (auto it = q.begin(); it != q.end(); ++it) {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
