/*
 * HW2P4
 * The CoinChange program prints the total weight in poiuds of all the coins
 * used by all the possible combinations of 1, 5, 10, 25, and 50 cents coins
 * to add up to a total value, by default set to 1 dollar. Does not consider
 * 1 dollar coins.
 *
 * @author Narissa Tsuboi
 * @version 1.0
 *
 * Approach:
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 100;
const vector<double> WTS = {2.500, 5.000, 2.268, 5.670, 11.340};
const vector<double> COINS  = {1, 5, 10, 25, 50};

// Prints total weight in pounds of all the coins used by all the possible combinations
// of 1, 5, 10, 25, 50 cent coins to make $1
int main() {



    int row, col;
    vector<vector<int>> combo_tbl(COINS.size(), vector<int>(N, 0));
    //assign 0s to the top row and 1s to the first col
    for (row = 0; row <= COINS.size(); row++)
        combo_tbl[0][row] = 0;
    for (row = 0; row < COINS.size(); row++)
        combo_tbl[row][0] = 1;

    //table to console to check
    for (row = 0; row <= COINS.size(); row++)
    {
        for (int col = 0; col <= N; col++)
            cout <<combo_tbl[row][col] << " ";
        cout << endl;
    }

    //fill
    //include or exclude coin
    for (col = 1; col <= N; col++)
    {
        for (row = 1; row <= COINS.size(); row++)
        {
            //case 1: look to the left of the current combo square
            //if that value is greater than the
            if (col >= combo_tbl[row - 1])
                combo_tbl[row][col] = combo_tbl[row][col - COINS[row - 1] +
                                                     combo_tbl[row - 1][col]];
        }
    }

}


