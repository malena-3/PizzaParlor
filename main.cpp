/* Project 5: Pizza Order
Program Details: Pizza ordering system
Course: Computer Science 002 Pasadena City College
Professor: Professor Mayada Alani
Creator: Malena Lodi */

#include <string>
#include "function.h"
using namespace std;

int main() // Main function.
{
    string customerName = "blank", toppings = "blank", crustType = "blank";
    int pizzaSize = 0, numToppings = 0;
    double pizzaCost = 0.00;

    pizzaMenu(customerName); //Task #1
    pizzaSizeFunc(pizzaSize, pizzaCost); //Task #2
    crustTypeFunc(crustType); //Task #3
    getToppings(numToppings, toppings); //Task #4
    outputs(pizzaSize, crustType, toppings, customerName, pizzaCost, numToppings); //Task #5

    return 0;
}
