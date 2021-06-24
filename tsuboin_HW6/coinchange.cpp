// Narissa Tsuboi
// coinchange.cpp R1
// purpose: calculates and displays the total weight in pounds of all the coins
//          used by all the possible combinations of 1, 5, 10, 25, and 50 cents
//          to add up to total amount, by default amount is 1 dollar. Does not
//          consider dollar coins.
// approach: use recursion in the base case and sub-problem to capture every
//           possible coin combination, and calculate the weight with a
//           helper function. use a reference to the weight accumulator to
//           allow each recursive function call to add to it.
//           the case base of the problem occurs when the recursive function
//           has cycled through the sub-problem with each coin denomination in
//           the global constant vector COINS. at this point the number of
//           counts for the current combination are pass to the helper
//           function to be converted into weight in grams. the sub-problem is
//           to take as many coins of the current index of denomination out
//           of the amount before moving onto the next denomination. a
//           separate sub-problem addresses when the last denomination
//           available to take out is just the penny.


#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// global constants
const int AMOUNT = 100; // amount to calculate as global const per specs
const vector<int> COINS = {50, 25, 10, 5, 1}; // coins considered
const int COINS_LEN = COINS.size();

// weight constants
const double GRAMS_LBS = 1/453.592;
const double HALFDOLLAR_WT = 11.340;
const double QUARTER_WT = 5.670;
const double DIME_WT = 2.268;
const double NICKEL_WT = 5.000;
const double PENNY_WT = 2.5000;

// prototypes

void calcCoinWeight(int index, int numCounts, double& wt);
// sums the total coin weight in grams
// pre: index <= COINS.size()
// post: wt reference variable holds weight of additional coin combo

void getCoinWeight(const vector<int> &coins, vector<int> counts,
                   int index, const int &amount, double& wt);
// calculates the weight in grams of the total number of combos to
// make the amount entered
// pre: index <= COINS.size()
// post: wt reference variable holds weight of additional coin combo


// methods

void calcCoinWeight(int i, int numCounts, double &wt) {
// calculates the weight in grams of the total number of combos to
// make the amount entered
// in: index of coin array, numCounts the quantity of type i of coin
//     counted, wt reference to accumulator for total weight
        if (i == 0)
            wt += (HALFDOLLAR_WT * numCounts);
        else if (i == 1)
            wt += (QUARTER_WT * numCounts);
        else if (i == 2)
            wt += (DIME_WT * numCounts);
        else if (i == 3)
            wt += (NICKEL_WT * numCounts);
        else if (i == 4)
            wt += (PENNY_WT * numCounts);
        else
            cout << "invalid index" <<endl;
}

void getCoinWeight(const vector<int> &coins, vector<int> counts, int
        index, const int &amount, double& wt)
{
// sums the total coin weight in grams
// in: coins - holds coin values sorted in descending order
//     counts - holds the number of coins counted at the index
//     startIndex - the coin denomination currently being processed
//     totalAmount - keep track of remaining amount left  to process
//     wt - reference to accumulator for total weight

    // base case - all coin denominations have been processed
    // for each denomination, input number of times it was used
    // to the helper function
    if (index >= COINS_LEN) {
        for (int i =0; i < COINS_LEN; i++)
            calcCoinWeight(i, counts[i], wt);
        return;
    }
    // sub-problem: if only the smallest denomination coin can
    // be removed evenly, increase its count
    if (index == COINS_LEN - 1) {
        if (amount % coins[index] == 0) {// valid combo
            // set the counts of coins at start index
            counts[index] = amount / coins[index];
            // proceed to recursive call
            // notice index+1 and amount = 0
            getCoinWeight(coins, counts, index + 1, 0,
                          wt);
        }
    }
    // sub-problem cont: divide out as many of the current largest
    // denominations as possible, then advance loop
    else {
        for (int i = 0; i <= amount / coins[index]; i++) {
            counts[index] = i;
            getCoinWeight(coins, counts, index + 1,
                          amount - coins[index] * i, wt);
        }
    }
}

// prints total weight in pounds of all the coins used by all the possible
// combinations of 1, 5, 10, 25, 50 cent coins to make $AMOUNT
int main() {
    double wt = 0;
    vector<int> counts(COINS_LEN);

    // display program overview
    cout << "\n*** Coin Change Weight Program ***\n";
    cout << "\nThis program displays the weight in pounds\nof all the "
            "combinations of change that make\nup the default "
            "amount assigned to the amount\nglobal variable.\n" << endl;

    // display program parameters
    cout << "Amount: " << showpoint << setprecision(3) << "$"
         <<  (1.00 * AMOUNT) / 100 << endl;
    cout << "Coins considered: ";
    for (int i = COINS.size() - 1; i >=0; i--)
        cout << COINS[i] << "c ";

    // calculate and display weight
    getCoinWeight(COINS, counts, 0, AMOUNT, wt);
    cout << endl << "Total weight: " <<  wt * GRAMS_LBS << " lbs" << endl;

    return 0;
}


