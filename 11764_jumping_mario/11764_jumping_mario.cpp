#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int num_cases, num_walls, last_number, current_number, hight_jumps, low_jumps;
    scanf("%d", &num_cases);

    for (int i = 1; i <= num_cases; i++) {
        hight_jumps = 0;
        low_jumps = 0;

        scanf("%d", &num_walls);
        scanf("%d", &current_number);

        for (int j = 1; j < num_walls; j++) {
            last_number = current_number;
            scanf("%d", &current_number);

            if (current_number > last_number) {
                hight_jumps++;
            }
            if (current_number < last_number) {
                low_jumps++;
            }
        }

        printf("Case %d: %d %d\n", i, hight_jumps, low_jumps);
    }
    return 0;
}
