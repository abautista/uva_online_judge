#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num_test_cases, relevance, max_relevance;    
    vector<string> chosen_urls;
    string url;
    
    cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; i++) {
        chosen_urls.clear();
        max_relevance = 0;
        
        for (int j = 0; j < 10; j ++) {            
            cin >> url >> relevance;
            if (relevance > max_relevance) {
                chosen_urls.clear();
                chosen_urls.push_back(url);
                max_relevance = relevance;
            } else if (relevance == max_relevance) {
                chosen_urls.push_back(url);
            }                                     
        }
        
        cout << "Case #" << i + 1 << ":" << endl;
        
        for (auto it : chosen_urls) {
            cout << it << endl;
        }
    }    
}
