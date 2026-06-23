/*-------------------------------------------------	  */
/*													  */
/* Name: Momina Amjad-143 and Aroona Noor-027  		  */
/* Date: 15-Dec-2024								  */
/* Program: airline.cpp							      */
/* Description:	This program enables users to		  */
/* book flights.                                	  */
/*-------------------------------------------------	  */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// declaration  of variables;
double platinumDc = 0.0;
const double tax = 0.15;
const int maxRows = 9;
const int maxCols = 9;
const int maxSeats = maxRows * maxCols;
double fare = 0.0;
double baseFare = 30000.00;
double infantRate = 0.50;
double childRate = 0.75;
double adultRate = 1;
char ageType;
double regionFare = 0.0;
char seatType;
double seatFare = 0.0;
int numSeats;
char mealPref;
bool isReturn = false;
bool isDomestic = false;
string seat, meal, fromCity, toCity, name, email, depDate, retDate;
//functions
void displaydomestic() {
    cout << "\n===================================" << endl;
    cout << "     Available Airports in Pakistan" << endl;
    cout << "===================================" << endl;
    cout << "KHI - Karachi       CJL - Chitral       GWD - Gwadar" << endl;
    cout << "BHV - Bahawalpur    LYP - Faisalabad    ISB - Islamabad" << endl;
    cout << "GIL - Gilgit        SKT - Sialkot      MUX - Multan" << endl;
    cout << "LHR - Lahore        PEW - Peshawar     SKZ - Sukkur" << endl;
    cout << "===================================\n" << endl;

}
void displayinternational() {

    cout << "\n===================================" << endl;
    cout << "       Available International Destinations" << endl;
    cout << "===================================" << endl;
    cout << "1. United Kingdom     7. Thailand\n";
    cout << "2. Korea              8. Singapore\n";
    cout << "3. China              9. USA\n";
    cout << "4. Japan              10. Turkey\n";
    cout << "5. Saudi Arabia       11. Germany\n";
    cout << "6. Malaysia\n";
    cout << "===================================\n" << endl;
    int countryChoice;
    do {
        cout << "Choose a country (1-11): ";
        cin >> countryChoice;
    } while (countryChoice < 1 || countryChoice > 11);

    if (countryChoice == 1) {
        cout << "Available cities in United Kingdom: LHR - London Heathrow, MAN - Manchester\n";
        baseFare *= 1.50;
    }
    else if (countryChoice == 2) {
        cout << "Available cities in Korea: ICN - Incheon, PUS - Busan\n";
        baseFare *= 1.30;
    }
    else if (countryChoice == 3) {
        cout << "Available cities in China: PEK - Beijing, PVG - Shanghai\n";
        baseFare *= 1.05;
    }
    else if (countryChoice == 4) {
        cout << "Available city in Japan: HND - Tokyo\n";
        baseFare *= 1.25;
    }
    else if (countryChoice == 5) {
        cout << "Available cities in Saudi Arabia: JED - Jeddah, RUH - Riyadh, MKK - Makkah\n";
        baseFare *= 1.15;
    }
    else if (countryChoice == 6) {
        cout << "Available cities in Malaysia: KUL - Kuala Lumpur, PEN - Penang\n";
        baseFare *= 1.25;
    }
    else if (countryChoice == 7) {
        cout << "Available cities in Thailand: BKK - Bangkok, HKT - Phuket\n";
        baseFare *= 1.25;
    }
    else if (countryChoice == 8) {
        cout << "Available city in Singapore: SIN - Singapore Changi\n";
        baseFare *= 1.25;
    }
    else if (countryChoice == 9) {
        cout << "Available states in USA: JFK - New York, LAX - Los Angeles, ORD - Chicago\n";
        baseFare *= 1.5;
    }
    else if (countryChoice == 10) {
        cout << "Available cities in Turkey: IST - Istanbul, AYT - Antalya\n";
        baseFare *= 1.10;
    }
    else if (countryChoice == 11) {
        cout << "Available cities in Germany: FRA - Frankfurt, MUC - Munich\n";
        baseFare *= 1.25;
    }
}
string departureOrArrivalDate() {
    cout << "\nEnter DEPARTURE date (DD/MM/YYYY): ";
    cin >> depDate;
    if (isReturn) {
        cout << "Enter RETURN date (DDMM/YYYY): ";
        cin >> retDate;
    }
    else {
        retDate = depDate;
    }
    return depDate;
}
void seatTypeAge(int num) {
    cout << " Type of seats: Adult, child (age<=12) , infant(age<=2) (A/C/I) " << endl;
    for (int i = 0; i < num; i++) {
        cout << "\nEnter seat type for seat " << (i + 1) << " :";
        cin >> ageType;
        if (ageType == 'A' || ageType == 'a') baseFare *= adultRate;
        else if (ageType == 'C' || ageType == 'c') baseFare *= childRate;
        else if (ageType == 'I' || ageType == 'i') baseFare *= infantRate;

    }

}
string seatTypeClass() {

    do {
        cout << "\nEnter seat type (choose one):" << endl;
        cout << "E - Economy (Rs 15,000 extra)" << endl;
        cout << "B - Business (Rs 30,000 extra)" << endl;
        cout << "F - First Class (Rs 50,000 extra)" << endl;
        cout << "Your choice: ";
        cin >> seatType;


        if (seatType == 'E' || seatType == 'e') {
            seatFare = 15000;
            seat = "Economy";
        }
        if (seatType == 'B' || seatType == 'b') {
            seatFare = 30000;
            seat = "Business";
        }
        if (seatType == 'F' || seatType == 'f') {
            seatFare = 50000;
            seat = "First Class";
        }

    } while (!(seatType == 'E' || seatType == 'e' || seatType == 'B' || seatType == 'b' || seatType == 'F' || seatType == 'f'));
    return seat;
}
double calculateFare() {
    fare = baseFare + regionFare+ seatFare;
    fare *= numSeats;
    fare *= (1 - platinumDc);
    fare *= (1 + tax);

    return fare;
}
double platinumCardDc() {
    char choice2;
    do {
        cout << "\nDoes the passenger have a platinum card? (Y/N): ";
        cin >> choice2;

        if (choice2 == 'Y' || choice2 == 'y') {
            return 0.10; // 10% discount
        }
        else if (choice2 == 'N' || choice2 == 'n') {
            return 0.0; // No discount
        }
        else {
            cout << "Invalid input. Please enter Y or N." << endl;
        }
    } while (true);

}
void displaySeatingPlan() {
    int seats[maxSeats]; // Use int for internal representation

    // Initialize all seats to 0 (Available)
    for (int i = 0; i < maxSeats; ++i) {
        seats[i] = 0; // 0 represents available
    }

    // Open file for writing the seating plan
    ofstream outFile("seating_plan.txt", ios::app); // Open in append mode
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing the seating plan." << endl;
        return;
    }

    // Display header
    cout << "===================================" << endl;
    cout << "   Seating Plan (O: Available, X: Booked)" << endl;
    cout << "===================================" << endl;

    // Display initial seating layout
    for (int i = 0; i < maxSeats; i += maxCols) {
        cout << "Row " << setw(2) << (i / maxCols + 1) << ": ";
        for (int j = 0; j < maxCols; ++j) {
            if (seats[i + j] == 0) {
                cout << 'O' << " ";
            }
            else {
                cout << 'X' << " ";
            }
        }
        cout << endl;
    }

    // Booking logic
    int numBookings = 0; // Track the number of booked seats
    int row, col;

    // Booking loop
    while (numBookings < numSeats) {
        cout << "\nEnter row and column to book (e.g., 1 2 for Row 1, Column 2), or -1 to stop: ";
        cin >> row;

        // Stop booking if the user enters -1
        if (row == -1) {
            break;
        }
        cin >> col;

        // Validate the input
        if (row >= 1 && row <= maxRows && col >= 1 && col <= maxCols) {
            int seatIndex = (row - 1) * maxCols + (col - 1); // Convert row and column to a linear index
            if (seats[seatIndex] == 0) { // Check if the seat is available
                seats[seatIndex] = 1; // Mark the seat as booked
                numBookings++;
                cout << "Seat successfully booked!" << endl;
            }
            else {
                cout << "Seat already booked. Please choose another seat." << endl;
            }
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }

        // If all seats are booked, exit the loop
        if (numBookings >= maxSeats) {
            cout << "All seats are booked!" << endl;
            break;
        }
    }

    // Display updated seating plan
    cout << "\nUpdated Seating Plan:" << endl;
    outFile << "\nUpdated Seating Plan:" << endl;

    for (int i = 0; i < maxSeats; i += maxCols) {
        cout << "Row " << setw(2) << (i / maxCols + 1) << ": ";
        outFile << "Row " << setw(2) << (i / maxCols + 1) << ": ";
        for (int j = 0; j < maxCols; ++j) {
            if (seats[i + j] == 0) {
                cout << 'O' << " ";
                outFile << 'O' << " ";
            }
            else {
                cout << 'X' << " ";
                outFile << 'X' << " ";
            }
        }
        cout << endl;
        outFile << endl;
    }

    // Close the file
    outFile.close();
    cout << "\nSeating plan has been saved to 'seating_plan.txt' successfully!" << endl;
}
string mealPlan() {
    do {
        cout << "\nWould you like a default or vegan meal? (D/V): ";
        cin >> mealPref;

        if (mealPref == 'D' || mealPref == 'd') {
            meal = "Default";
            break;
        }
        if (mealPref == 'V' || mealPref == 'v') {
            meal = "Vegan";
        }
        else {
            cout << "Invalid input. Please enter D for default or V for vegan." << endl;
        }
    } while (!(mealPref == 'D' || mealPref == 'd' || mealPref == 'V' || mealPref == 'v'));
    return meal;
}
void displaySummary() {
    cout << "\n===================================" << endl;
    cout << "            Booking Summary" << endl;
    cout << "===================================" << endl;
    if (isReturn) {
        cout << setw(20) << left "Flight Type: Return" << endl;
    }
    else {
        cout << setw(20) << left "Flight Type: One-way" << endl;
    }
    cout << setw(20) << left << "From:" << fromCity << endl;
    cout << setw(20) << left << "To:" << toCity << endl;
    cout << setw(20) << left << "Departure Date:" << depDate << endl;
    if (isReturn) {
        cout << setw(20) << left << "Return Date:" << retDate << endl;
    }
    cout << setw(20) << left << "Number of Seats:" << numSeats << endl;
    cout << setw(20) << left << "Seat Type:" << seat << endl;
    cout << setw(20) << left << "Meal Preference:" << meal << endl;
    cout << setw(20) << left << "Total Fare (Rs):" << fixed << setprecision(2) << fare << endl;
    cout << "===================================\n" << endl;
}
void writeSummaryToFile() {
    ofstream outFile("booking.txt", ios::app);    if (outFile.is_open()) {

        outFile << "Booking Details:" << endl;
        outFile << "Email: " << email << endl;
        if (isReturn) {
            outFile << "Flight Type: Return" << endl;
        }
        else {
            outFile << "Flight Type: One-way" << endl;
        }
        outFile << "Destination: " << fromCity << " ----to----- " << toCity << endl;
        outFile << "Departure Date: " << depDate << endl;
        outFile << "Number of Seats: " << numSeats << endl;
        outFile << "Seat Type: " << seat << endl;
        outFile << "Meal Preference: " << meal << endl;
        outFile << "Total Fare: Rs " << fixed << setprecision(2) << fare << endl;
        outFile.close();
        cout << "Data written to booking.txt successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}
int main()
{
    cout << "\n=======================================" << endl;
    cout << "    Welcome to the Flight Booking System!" << endl;
    cout << "=======================================\n" << endl;


    // Ask about flight type
    char choice;
    do {
        cout << "\nIs this a one-way or return flight? (O/R): ";
        cin >> choice;
        isReturn = (choice == 'R' || choice == 'r');
    } while (!(choice == 'R' || choice == 'r' || choice == 'O' || choice == 'o'));

    // Ask about flight type
    do {
        cout << "\nIs this a domestic or international flight? (D/I): ";
        cin >> choice;
        isDomestic = (choice == 'D' || choice == 'd');
    } while (!(choice == 'D' || choice == 'd' || choice == 'I' || choice == 'i'));

    if (isDomestic) {
        displaydomestic();
        regionFare = 30000;
    }
    else {
        displaydomestic();
        displayinternational();
        regionFare = 50000;
    }

    // Input departure and arrival cities

    cout << "\nEnter DEPARTURE city code: ";
    cin >> fromCity;
    cout << "Enter ARRIVAL city code: ";
    cin >> toCity;


    // Input dates
    departureOrArrivalDate();


    // Input number of seats
    cout << "\nEnter number of seats: ";
    cin >> numSeats;
    // input type of seat
    seatTypeAge(numSeats);
    seatTypeClass();
    displaySeatingPlan();
    // Input meal preference
    mealPlan();
    calculateFare();
    cout << "Enter your email: ";
    cin >> email;

    // Output summary
    displaySummary();

    // Write data to file
    writeSummaryToFile();

    // Confirmation
    char confirm;
    cout << "\nDo you want to proceed with payment? (Y/N) ";
    cin >> confirm;
    if (confirm == 'Y' || confirm == 'y') {
        cout << "\n===================================" << endl;
        cout << "    Thank you for booking with us!" << endl;
        cout << "===================================" << endl;
        cout << "You will receive an email shortly with a link to complete your payment." << endl;
        cout << "After payment, your ticket(s) will be emailed to you." << endl;
    }
    else if (confirm == 'N' || confirm == 'n') {
        cout << "exiting program ";
        return 0;
    }


    return 0;
}