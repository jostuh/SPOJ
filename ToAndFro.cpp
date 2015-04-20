/* 
 * File:   ToAndFro.cpp
 * Author: jjost
 *
 * Created on April 12, 2015, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<std::string> message;

std:: string reverse_string(const std::string &input) {
    string result;
    
    for (int i = 0; i < input.length(); i++) {
        result+= input[input.length() - i - 1];
    }
    return result;        
}

/*
 * 
 */
int main(int argc, char** argv) {
    int num_columns;
    string input;
    cin >> num_columns;
    
    while (num_columns) {
        cin >> input;
        int num_rows = input.length() / num_columns;
        
        message m1;
        for (int i = 0; i < num_rows; i++) {
            if (input.length() >= num_columns) {
                string substring = input.substr(0,num_columns);
                if (i % 2 != 0) {
                    substring = reverse_string(substring);
                }
                m1.push_back(substring);
                input.erase(0,num_columns);
            } else {
                int len = input.length();
                for (int x = 0; x < num_columns - len; x++) {
                    string x_str("x");
                    input.append(x_str);
                }
                m1.push_back(input);
            }   
        }
        
        // Display string in the encrypted manner
        for (int i = 0; i < num_columns; i++) {
            for ( auto x : m1) {
                cout << x[i];
            }
        }
        cout << endl;
        
        cin >> num_columns;
    }

    return 0;
}

