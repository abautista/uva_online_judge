#include <iostream>

using namespace std;

void group_reverse(int n, string& s)
{
    for (int i = 0; i < s.size(); i+=n) {    
        string temp = s.substr(i, n);
        int k = i;
        string::reverse_iterator curr;
        for (curr = temp.rbegin(); curr != temp.rend(); curr++) {
            s[k++] = *curr;
        }    
    }
}

int main(int argc, char *argv[])
{
    string s;
    int groups_number;
    
    cin >> groups_number;
    while ( groups_number !=0) {
        cin >> s;
        int group_size = s.size() / groups_number;
        group_reverse(group_size , s);
        cout << s << endl;
        cin >> groups_number;
    }

    return 0;
}
