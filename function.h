//
// Created by Malena Lodi - April 2023.
//
#ifndef PIZZAPARLOR_FUNCTION_H
#define PIZZAPARLOR_FUNCTION_H

#include<iostream>
#include<string>
using namespace std;

// Task#1
void pizzaMenu(string customerName) // Definition of pizzaMenu function
{
    cout << endl;
    cout << "Hello! Welcome to Malena's Pizzeria\n";
    cout << "Enter your first name: ";
    cin >> customerName;
    cout << endl;

    /*Boolean expression that determines if the user is
    eligible for a $2.00 discount.*/
    bool discountEligible = discount(customerName);
    if (discountEligible) {
        cout << "You are eligible for a discount!\n";
    }
    cout << endl;

    // User interface that gathers User's name.
    cout << "Take a look at our menu " << customerName << "!";

    cout << endl << "Menu: \n";
    cout << "Pizza Size (inches) and Price:\n";
    cout << "10 for $10.99\n"
         << "12 for $12.99\n"
         << "14 for $14.99\n"
         << "16 for $16.99\n";
    // Pizza cost and size menu.
}

// Task#2
double pizzaSizeFunc(int &pizzaSize, double &pizzaCost) {
    // Ask the user for their choice of pizza size
    cout << "\nWhat size pizza would you like?" << endl;
    cout << "10, 12, 14, or 16 (enter the number only): ";
    // Store the choice
    cin >> pizzaSize;

    // Add the corresponding cost to the total cost depending on the user choice
    if (pizzaSize == 10) {
        pizzaCost = pizzaCost + 10.99;
    } else if (pizzaSize == 12) {
        pizzaCost = pizzaCost + 12.99;
    } else if (pizzaSize == 14) {
        pizzaCost = pizzaCost + 14.99;
    } else if (pizzaSize == 16) {
        pizzaCost = pizzaCost + 16.99;
        // Price choice if the user submits an invalid input
    } else {
        cout << "Invalid input. A 12-inch pizza will be made." << endl;
        pizzaSize = 12;
        pizzaCost = 12.99;
    }

    return pizzaCost;
}

// Task #3
void crustTypeFunc(string crustType) {
    char crustOrder;
    cout << "What type of crust do you want?\n";
    cout << "   (H) Hand-tossed, (T) Thin-crust, or (D) Deep- dish\n"
         << "   (enter H, T, or D): ";
    cin >> crustOrder;
    // Gathers crust type the User wants. **(Default is hand-tossed)**

    switch (crustOrder) {
        case 'H':
        case 'h':
            crustType = "Hand-tossed\n";
            break;
        case 'T':
        case 't':
            crustType = "Thin-crust\n";
            break;
        case 'D':
        case 'd':
            crustType = "Deep-dish\n";
            break;
        default:
            cout << "Invalid input. A hand-tossed crust will be made.\n";
            crustType = "Hand-tossed\n";
    }
}

// Task#4
void getToppings(int &numToppings, string &toppings) {
    // Prompt user for toppings
    cout << "Additional toppings are $1.25 each, choose from:" << endl;
    cout << "Pepperoni, Sausage, Onion, Mushroom" << endl;

    // Prompt pepperoni
    char choice;
    cout << "Do you want Pepperoni? (Y/N): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        numToppings++;
        toppings += " Pepperoni";
    }

    // Prompt sausage
    cout << "Do you want Sausage? (Y/N): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        numToppings++;
        toppings += " Sausage";
    }

    // Prompt onion
    cout << "Do you want Onion? (Y/N): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        numToppings++;
        toppings += " Onion";
    }

    // Prompt mushroom
    cout << "Do you want Mushroom? (Y/N): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        numToppings++;
        toppings += " Mushroom";
    }
}

// Task #5
void outputs(int pizzaSize, const string &crustType, const string &toppings, string customerName,
             double pizzaCost, int numToppings)
{
    // Complete output of the User's pizza order
    cout << endl;
    cout << "Your order is as follows:\n";
    if (pizzaSize == 10) {
        cout << "10-inch pizza\n";
    } else if (pizzaSize == 12) {
        cout << "12-inch pizza\n";
    } else if (pizzaSize == 14) {
        cout << "14-inch pizza\n";
    } else if (pizzaSize == 16) {
        cout << "16-inch pizza\n";
    }
    cout << crustType;
    cout << toppings << endl;

    // Calculation of costs
    double taxRate = 0.0795, toppingCost = 1.25, orderCost, tax, totalDue;

    /*Boolean expression that deducts the discount of $2.00
    if the customerName is eligible*/
    bool discountEligible = discount(customerName);
    if (discountEligible)
    {
        pizzaCost = pizzaCost - 2.00;
    }

    toppingCost = toppingCost * numToppings;
    orderCost = pizzaCost + toppingCost;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Output of the calculated costs
    cout << "The cost of your order is: $" << orderCost << endl;

    tax = taxRate * orderCost;
    cout << "The tax is: $" << tax << endl;

    totalDue = orderCost + tax;
    cout << "The total due is: $" << totalDue << endl;

    cout << "Your order will be ready for pickup in 30 minutes.\n";
}

// Task #6
bool discount(string& customerName) {
    // Variable for discount eligibility
    bool discount;
    // Compare the user inputted name to the name of the owners
    if ((customerName == "jack" || customerName == "Jack") ||
        (customerName == "malena" || customerName == "Malena")) {
        discount = true;
        return discount;
    } else {
        discount = false;
        return discount;
    }
}


#endif //PIZZAPARLOR_FUNCTION_H
