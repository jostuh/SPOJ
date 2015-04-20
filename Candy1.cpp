/* 
 * File:   main.cpp
 * Author: jjost
 *
 * Created on April 12, 2015, 3:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int num_bags;
    cin >> num_bags;
    
    while(num_bags != -1) {
        vector<int> bags;
        int total = 0;
        for (int x = 0; x < num_bags; x++) {
            int current;
            cin >> current;
            bags.push_back(current);
            total += current;
        }
        
        if (total % num_bags != 0) {
            cout << "-1" << endl;
        } else {
            int avg = total / num_bags;
            int to_move = 0;
            for (auto current_bag : bags) {
                if (current_bag > avg) {
                    to_move += current_bag - avg;
                }
            }
            cout << to_move << endl;
        }       
        
        cin >> num_bags;
    }
    
    return 0;
}