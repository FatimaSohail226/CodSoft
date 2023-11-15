#include<iostream>
#include<random>
using namespace std;

// Function to generate a random number between 1 and 20
int Gen()
{
    random_device rd; // Initialize a random seed generator
    mt19937 gen(rd()); // Initialize a random number generator with the seed from random_device
    int min=1; // Minimum value for the random number
    int max=20; // Maximum value for the random number
    uniform_int_distribution<>dist(min,max); // Create a distribution for integers between min and max
    return dist(gen); // Generate and return a random number within the specified range
}

int main()
{
    int num; // Variable to store user's guessed number
    cout<<"Enter number to guess between 1 and 20!\n ";
    cin>>num; // Prompt the user to enter their guess and store it in 'num'
    
    int gen=Gen(); // Generate a random number and store it in 'gen'
    
    do {
        if(num < gen)
        {
            cout<<"Guess is too low!\n"; // Inform the user that their guess is too low
        }
        else if(num > gen)
        {
            cout<<"Guess is too high!\n"; // Inform the user that their guess is too high
        }
    } while(num != gen); // Continue the loop until the user's guess matches the generated number
    
    return 0; // Return 0 to indicate successful execution of the program
}
