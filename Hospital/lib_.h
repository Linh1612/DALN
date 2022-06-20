#pragma once
#include<bits/stdc++.h>

using namespace std;

vector<string> tokenize(string const &str, char const delim) {
    vector<string> out;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
    return out;
}

vector<vector<string>> readData(string link_file){
    ifstream filename_in(link_file);
    vector<vector<string>> result ;
    string tmp ;
    while (getline(filename_in, tmp)) {
        vector<string> token = tokenize(tmp, ',');
        result.push_back((token));
    }
    filename_in.close();
    return result;
}
