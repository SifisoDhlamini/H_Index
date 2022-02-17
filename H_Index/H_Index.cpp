// H_Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int fits_in(vector<int> v, int x) {
    int count = 0;
    for (auto i = v.begin(); i != v.end(); ++i) {
        bool fits = ((*i / x) >= 1) ? true : false;
        if (fits) count++;
    }
    return count;
}

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    vector<int> h_index;
    // TODO: Calculate and return h-index score for each paper.
    int papers = 0;
    int max = 0;
    for (auto i = citations_per_paper.begin(); i != citations_per_paper.end(); ++i)
    {
        papers++;
        //if it is the first element
        if (i == citations_per_paper.begin()) {
            h_index.push_back(1);
        }
        else
        {
            //create copy of sub vector up to i
            vector<int> newVec{ citations_per_paper.begin(), citations_per_paper.begin() + papers };
            map<int, int> mCit;
            for (auto j : newVec) {
                mCit.insert({j, fits_in(newVec, j)});
            }
            for (auto j : mCit) {
                if (j.second > max && j.first >= j.second)
                    max = j.second;
                else if (j.second > max && j.first < j.second) {
                    max = j.first;
                }
            }
            h_index.push_back(max);
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