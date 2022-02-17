// H_Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
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
    int current_indexer{};
    for (auto i = citations_per_paper.begin(); i != citations_per_paper.end(); ++i)
    {
        papers++;
        //if it is the first element
        if (i == citations_per_paper.begin()) {
            h_index.push_back(1);
            current_indexer = *i;
        }
        else
        {
            //create copy of sub vector up to i
            vector<int> newVec{ citations_per_paper.begin(), citations_per_paper.begin() + papers };

            //check how many papers at least have *i citations
            int i_citations = fits_in(newVec, *i);
            //int ci_citations = fits_in(newVec, current_indexer);
            int last = h_index.back();
            //find the H_index
            if (*i > last) {
                if (*i >= current_indexer) {
                    if (i_citations >= last) {
                        if (*i <= papers) {
                            h_index.push_back(i_citations);
                            current_indexer = *i;
                        }
                        else {
                            h_index.push_back(last);
                        }                        
                    }
                    else if (i_citations < last)
                    {
                        int ci_citations = last + 1;
                        h_index.push_back(ci_citations);
                    }
                }
                else if (*i < current_indexer) {
                    if (i_citations > last && *i >= i_citations) {
                        if (*i <= papers) {
                            h_index.push_back(i_citations);
                            current_indexer = *i;
                        }
                        else {
                            h_index.push_back(last);
                        }
                    }
                    else
                    {
                        h_index.push_back(last);
                    }
                }
            }
            else {
                h_index.push_back(last);
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