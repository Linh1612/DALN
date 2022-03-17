#pragma once
#include<iostream>
#include<string>
#include<vector>


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
