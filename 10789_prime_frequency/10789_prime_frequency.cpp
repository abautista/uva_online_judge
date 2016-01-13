#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
        return false;

    int m = static_cast<int>(sqrt(n)) + 1;
    for (int i = 2; i < m; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    map<char, int> freqs;

    int number_inputs;
    string sample;

    cin >> number_inputs;

    for (int i = 0; i < number_inputs; ++i) {
        freqs.clear();
        cin >> sample;
        for (auto c : sample) {
            auto it = freqs.find(c);
            if (it != freqs.end()) {
                freqs[c] += 1;
            } else {
                freqs[c] = 1;
            }
        }

        cout << "Case " << i + 1 << ": ";
        string output = "";

        for (auto it : freqs) {
            if (is_prime(it.second)) {
                output += it.first;
            }
        }

        output.size() > 0? cout << output : cout << "empty";
        cout << endl;
    }
}
