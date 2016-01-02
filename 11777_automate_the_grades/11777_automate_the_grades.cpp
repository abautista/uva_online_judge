#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    float term_1, term_2, final;
    float attendance;
    float test[3];

    int n_lines;

    cin >> n_lines;
    for (int i = 0; i < n_lines; i++) {
        cin >> term_1 >> term_2 >> final >> attendance;
        cin >> test[0] >> test[1] >> test[2];
        sort(test, test + 3);

        int total = term_1 + term_2 + final + attendance + (test[1] + test[2]) / 2;
        cout << "Case " << i + 1 << ": ";
        if (total >= 90) {
            cout << "A";
        } else if (total >= 80) {
            cout << "B";
        } else if (total >= 70) {
            cout << "C";
        } else if (total >= 60) {
            cout << "D";
        } else {
            cout << "F";
        }
        cout << endl;
    }


}
