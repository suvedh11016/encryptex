#include <bits/stdc++.h>

using namespace std;

void arthematicOperations(double a, double b) // Function to handle the arthematic operations.
{
    int key; // Variable used for the selection of arthematic operation purpose.
    double answer = 0; // Variable for the final result.
    cin >> key; // Taking input of the key.
    if (key == 1)
    {
        answer = a + b; // If we choose key as 1 then addtion operation is done and stored in answer variable.
        cout << "Additon of " << a << " and " << b << " is " << answer << endl; // Prompt the result based on key value.
    }
    else if (key == 2)
    {
        answer = a-b; 
        cout << "Subtraction of " << a << " and " << b << " is " << answer << endl; // Prompt the result based on key value.
    }
    else if (key == 3)
    {
        answer = a*b;
        cout << "Multiplication of " << a << " and " << b << " is " << answer << endl; // Prompt the result based on key value.
    }
    else if (key == 4)
    {
        answer = a/b;
        cout << "Division of " << a << " and " << b << " is " << answer << endl; // Prompt the result based on key value.
    }
    else
    {
        cout << "You have pressed wrong button check the instruction again" << endl; // Prompt the result based on key value.
    }
}

int main()
{
    double a,b; // Variables for the two numbers.
    cout << "Enter the numbers whose arthematic operations you want to find: "; // Prompt for taking input numbers.
    cin >> a >> b;
    // Instrutions to be followed.
    cout << "**************INSTRUCTIONS***************" << endl;
    cout << "** Press 1 to implement Addition       **" << endl;
    cout << "** Press 2 to implement Subtraction    **" << endl;
    cout << "** Press 3 to implement Multiplication **" << endl;
    cout << "** Press 4 to implement Division       **" << endl;
    cout << "*****************************************" << endl;
    cout << "Press the key which you want to perform: "; // Prompt for key.
    arthematicOperations(a,b);

    return 0;
}