/* Electric Bill-V1.@ - Determines the game winner
C++ Programming version of the game
Name: Christian Millar
Date: 27 June 2022
CIS054
Inputs: kwH
Output: total cost of energy tiers
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    //constants
    const double tier1br = 0.230;
    const double tier2br = 0.290;
    const double tier3br = 0.450;
    const double tier1ar = 350.00;
    const double tier2ar = 1450.00;
    const double ctax = 0.200;
    
    //variables
    double kwH;
    double tier1price;
    double tier2price;
    double tier3price;
    double totalCost;

        
    //Inputs
    cout << "Enter the kilowatt hours: ";
    cin >> kwH;
    if (cin.fail() || kwH < 0)
    {
        cout << "The first number entered was either non-numeric or less than zero" << endl;
        return 1;
    }
    cout << "The first number " << kwH << " was greater than zero" << endl;
    
    //Process
    if (kwH <= tier1ar)
    {
        tier1price = kwH * tier1br;
        tier2price = 0.00;
        tier3price =0.00;
    }
    else if (tier1ar< kwH <= tier2ar)
    {
        tier1price = tier1br * tier1ar;
        tier2price = (kwH - tier1ar)*tier2br;
        tier3price = 0.00;
    }
    else if (kwH > tier2ar)
    {
        tier1price = tier1br * tier1ar;
        tier2price = tier2br * (tier2ar-tier1ar);
        tier3price = (kwH - tier2ar) * tier3br;
    }
    else
        cout << "The input is invalid" << endl;
    
    //Compute
        
        totalCost = tier1price + tier2price + tier3price + ctax;
        
    //Output
        cout << endl;
        cout << setiosflags(ios::fixed | ios::showpoint); // C++ setup for the display past deciaml
        cout << setprecision(2); // 2 digits past the decimal point
        cout << "The total cost of Tier1 is: $ "<< tier1price <<endl;
        cout << "The total cost of Tier2 is: $ "<< tier2price <<endl;
        cout << "The total cost of Tier2 is: $ "<< tier3price <<endl;
        cout << "The total cost of energy is: $ "<< totalCost << endl;
        return 0;

}
        
        
    
    
    

    
    
