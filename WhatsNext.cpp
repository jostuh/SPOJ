/* 
 * File:   main.cpp
 * Author: jjost
 *
 * Created on April 12, 2015, 11:47 AM
 */

#include <cstdlib>
#include<iostream>

using namespace std;

int main(int argc, char** argv) {
    int num1, num2, num3;
        
    cin >> num1; cin >> num2; cin >> num3;
    while(num1 != 0 || num2 != 0 || num3 != 0)
    {
        bool arithmetic_progression = true;
        auto first_difference = num2 - num1;
        auto second_difference = num3 - num2;
        if (first_difference != second_difference) {
            arithmetic_progression = false;            
        }
        if (arithmetic_progression) {
            cout << "AP " << num3 + second_difference << endl;
        }
        else {
            int factor = num3 / num2;
            cout << "GP " << num3 * factor << endl;
        }
            
        cin >> num1; cin >> num2; cin >> num3;
    }

    return 0;
}

