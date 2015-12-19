#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int current_channel, desired_channel, button_presses;

    while (cin >> current_channel >> desired_channel) {
        if (current_channel == -1 && desired_channel == -1) {
            break;
        }

        if (desired_channel > current_channel) {
            button_presses = min(desired_channel - current_channel, 100 - desired_channel + current_channel);
        } else {
            button_presses = min(current_channel - desired_channel, 100 - current_channel + desired_channel);
        }

        cout << button_presses << endl;

    }
}
