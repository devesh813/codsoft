#include <iostream>

using namespace std;

// initialize constants
const int NUM_ROWS = 7;
const int NUM_COLS = 7;
const double TICKET_PRICE = 10.0;

// Function to display the seating arrangement
void displaySeats(char seats[NUM_ROWS][NUM_COLS]) {
    cout << "   1  2  3  4  5  6  7" << endl; 
    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << seats[i][j] << "  "; 
        }
        cout << endl;
        cout<<endl;
    }
}

// Function to book a seat
bool bookSeat(char seats[NUM_ROWS][NUM_COLS], int row, int col) {
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col] == 'O') {
        seats[row][col] = 'X';   // 'X' represents that seat is booked
        return true;
    }
    return false;
}

// Function to calculate the total cost
double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    char seats[NUM_ROWS][NUM_COLS];
    int totalTickets = 0;
    double totalCost = 0.0;

    // Initializing all seats to 'O' (available seats)
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            seats[i][j] = 'O';
        }
    }

    while (true) {
        cout << "Movie Ticket Booking System" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Calculate Total Cost" << endl;
        cout << "4. Quit" << endl;
        
        int choice;
        cout <<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch (choice) {
            case 1:
                cout<<"Displaying available seats with 'O' and booked seats with 'X' :"<<endl;
                displaySeats(seats);
                break;
            case 2:
                cout << "Enter row (A-G) and seat number (1-7): ";
                char row;
                int col;
                cin >> row >> col;
                row = toupper(row) - 'A';
                col--;
                if (bookSeat(seats, row, col)) {
                    totalTickets++;
                    cout << "> Seat booked successfully!" << endl<<endl;;
                } else {
                    cout << "> Invalid seat selection. Please try again." << endl<<endl;
                }
                break;
            case 3:
                totalCost = calculateTotalCost(totalTickets);
                cout<<"> Cost of 1 ticket is $10"<<endl;
                cout << "> Total Cost of your "<<totalTickets <<" tickets is $"<< totalCost << endl<<endl;
                break;
            case 4:
                cout << "Enjoy your Movie! Goodbye" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
