
#ifndef CLEANER_H
#define CLEANER_H

#include <sstream>

using namespace std;


class DataCleaner {
public:
    static void clean_string(string& str) {
        stringstream ss(str);
        string word, result;
        while (ss >> word) {
            result += word + " ";
        }
        if (!result.empty()) {
            result.erase(result.find_last_not_of(" \n\r") + 1);
        }
        str = result;
    }
};

#endif
