// H_Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    vector<int> h_index;
    // TODO: Calculate and return h-index score for each paper.
    int papers = 0;
    int citations = 1;
    for (auto i = citations_per_paper.begin(); i != citations_per_paper.end(); ++i) 
    {
        papers++;
        
        int most_citations;
        //if it is the first element
        if (i == citations_per_paper.begin()) {
            h_index.push_back(1);
        }           
        else
        {  


            auto largest = citations_per_paper.begin();
            for (auto j = citations_per_paper.begin(); j != i; ++j) {
                if (*i > *j && *j <= papers && *j > citations && *j >= *largest) {
                    citations = *j;
                    largest = j;
                }
                else if (*i < *j && *i <= papers && *i > citations && *i <= *largest) {
                    citations = *i;
                    largest = i;
                }
                else if (*i == *j && *i <= papers && *i > citations) {
                    citations++;
                }
            }
            h_index.push_back(citations);
        }
    }
    return h_index;
}

int main() {
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++) {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}