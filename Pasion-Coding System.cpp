#include <iostream>
#include <string>

using namespace std;

const double COST_PER_ORDER = 90.00;

void displayLocations();
void processPayment();
void displayHistory(const string& bookingHistory, double totalCost);
string bookOrder();

int main() {
    cout << "Precious' Drop off & Pick-up service <3 " << "\n" << endl;

    string bookingHistory;
    string continueBooking; // Change the type to string
    double totalCost = 0.0;

    do {
        string orderDetails = bookOrder();

        // Display order details
        cout << "\nOrder Details:\n" << orderDetails << "\n";

        processPayment();

        // Add order to booking history
        bookingHistory += orderDetails + "\n";

        // Increment total cost for each order
        totalCost += COST_PER_ORDER;

        cout << "\nDo you have another transaction? (yes or no): ";
        cin >> continueBooking;
        cin.ignore();

     } while (continueBooking == "yes");

    // Display booking history and total cost
    displayHistory(bookingHistory, totalCost);

    cout << " 														 " << endl;
    cout << "Thank you for your booking! Have a nice day ahead." << endl;

    return 0;
}

void displayLocations() {
    cout << " 																		"<< endl;
    cout << "Available locations:\n"
         << "- SM Mall of Asia, Pasay City store\n"
         << "- Del Monte Ave, Quezon City store\n"
         << "- Morayta, Manila Store\n"
         << "- BGC, Makati City store\n";
}

void processPayment() {
    cout << "\nPayment Options:\n"
         << "1. GCash\n"
         << "2. Debit or Credit Card\n"
         << "3. Cash\n";

    int choice;
    cout << "Choose a payment method (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "	You have selected GCash. Please proceed with the payment using the GCash app.\n";
            cout << "	Kindly send the payment to this number: 0917 105 1324 H.A.\n";
            cout << "	Please provide the GCash receipt upon drop-off.\n";
            break;
        case 2:
            {
                cout << "You have selected Debit or Credit Card. Please enter your card details.\n";
                
                string cardNumber, cardHolderName, expirationDate, securityCode;
                
                cout << "	Enter the 12-Digit Card Number: ";
                cin >> cardNumber;
                
                cout << "	Enter Card Holder Name: ";
                cin.ignore();
                getline(cin, cardHolderName);
                
                cout << "	Enter Expiration Date (MM/YYYY): ";
                cin >> expirationDate;
                
                cout << "	Enter Security Code: ";
                cin >> securityCode;
                
                cout << "	Processing payment with credit card ending in " << cardNumber.substr(cardNumber.length() - 4) << "...\n";
                cout << "	Payment successful!\n";
            }
            break;
        case 3:
            cout << "	You have selected Cash. Please make the payment in cash upon delivery.\n";
            break;
        default:
            cout << "	Invalid choice. Please choose a valid payment method.\n";
            break;
    }
}

string bookOrder() {
    string senderFullName, senderAddress, senderContactNumber, receiverFullName, receiverAddress, receiverContactNumber, pickupLocation, dropOffLocation;

    cout << "Enter sender details:\n";
    cout << "Full name: ";
    getline(cin, senderFullName);
    cout << "Address: ";
    getline(cin, senderAddress);
    cout << "Contact number: ";
    getline(cin, senderContactNumber);

    cout << "\nEnter receiver details:\n";
    cout << "Full name: ";
    getline(cin, receiverFullName);
    cout << "Address: ";
    getline(cin, receiverAddress);
    cout << "Contact number: ";
    getline(cin, receiverContactNumber);

    displayLocations();

    cout << "\nEnter pickup location: ";
    getline(cin, pickupLocation);
    cout << "Enter drop-off location: ";
    getline(cin, dropOffLocation);

    return
        "- Sender Full Name: " + senderFullName + "\n"
        "- Sender Address: " + senderAddress + "\n"
        "- Sender Contact Number: " + senderContactNumber + "\n"
        "- Receiver Full Name: " + receiverFullName + "\n"
        "- Receiver Address: " + receiverAddress + "\n"
        "- Receiver Contact Number: " + receiverContactNumber + "\n"
        "- Pickup Location: " + pickupLocation + "\n"
        "- Drop-off Location: " + dropOffLocation;
}

void displayHistory(const string& bookingHistory, double totalCost) {
    cout << "\nBooking History:\n" << bookingHistory << "\n";
    cout << "Total Cost: " << totalCost << ".00 Philippine Pesos " << "\n";
}
