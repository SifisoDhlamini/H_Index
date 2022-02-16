// H_Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    vector<int> h_index;
    int papers = 0;
    // TODO: Calculate and return h-index score for each paper.
    for (auto i = citations_per_paper.begin(); i != citations_per_paper.end(); ++i) 
    {
        papers++;
        int citations = 1;
        if (i == citations_per_paper.begin())
            h_index.push_back(1);
        else
        {
            int smallest = *min_element(citations_per_paper.begin(), --i);
            int largest = *max_element(citations_per_paper.begin(), --i);
            if (*i > largest) {

            }

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