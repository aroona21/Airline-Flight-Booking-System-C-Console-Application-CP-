# ✈️ Airline Flight Booking System
### Computer Programming (CP) | C++ Console Application

A fully functional console-based flight booking system written in **C++** as a semester project. The program simulates a real airline reservation workflow — from selecting domestic or international routes and choosing seat class, to applying discounts, generating booking summaries, and saving data to files.


## 📌 Features

| Feature | Description |
|---|---|
| 🌍 Domestic Flights | 12 Pakistani airports with IATA codes (ISB, LHR, KHI, PEW, etc.) |
| 🌐 International Flights | 11 countries, 20+ destination airports with region-based fare multipliers |
| 🔁 One-Way & Return | Supports both one-way and return flight bookings |
| 👨‍👩‍👧 Passenger Age Tiers | Adult (100%), Child ≤12 (75%), Infant ≤2 (50%) fare rates |
| 💺 Seat Class Selection | Economy (+PKR 15,000), Business (+PKR 30,000), First Class (+PKR 50,000) |
| 🪑 Seat Map | Interactive 9×9 grid seating plan — book by row & column, visualized with O/X |
| 🥗 Meal Preference | Default or Vegan meal selection |
| 💳 Platinum Card Discount | 10% discount for platinum cardholders |
| 🧾 Fare Calculation | Base fare + region fare + seat fare × passengers − discount + 15% tax |
| 📄 File Output | Booking summary saved to `booking.txt`, seating plan saved to `seating_plan.txt` |
| 📧 Email Confirmation | Captures email and simulates payment confirmation flow |



## 🛠️ Technical Highlights

- Written in **C++** using standard libraries: `<iostream>`, `<fstream>`, `<string>`, `<iomanip>`
- **Modular design** — 10+ functions (`displaydomestic`, `seatTypeClass`, `calculateFare`, `displaySeatingPlan`, `writeSummaryToFile`, etc.)
- **File I/O** — `ofstream` with `ios::app` mode to persist booking records and seating plans across sessions
- **Input validation** — `do-while` loops throughout to reject invalid menu choices
- **Fare engine** — multi-factor calculation: base fare × age rate + region surcharge + class surcharge × seat count × (1 - discount) × (1 + tax)
- **2D seating grid** — 81-seat array mapped from row/column input, displayed as ASCII grid



## 📁 Project Structure

```
├── airlineFinal.cpp          # Full C++ source code
├── booking.txt               # Booking records (appended on each run)
├── seating_plan.txt          # Saved seating plans (appended on each run)
├── CP Project report.pdf     # Project documentation and report
└── Project Presentation.pptx # Slide deck
```



## ⚙️ How to Run

### Prerequisites
- Any C++ compiler: **GCC (g++)**, **MSVC**, or **MinGW**
- Or an IDE: **Code::Blocks**, **Dev-C++**, **Visual Studio**, or **VS Code with C++ extension**

### Steps

1. Clone this repository
2. Compile:
   ```bash
   g++ airlineFinal.cpp -o airline
   ```

3. Run:
   ```bash
   ./airline
   ```


## 🖥️ Sample Console Flow

```
=======================================
    Welcome to the Flight Booking System!
=======================================

Is this a one-way or return flight? (O/R): O
Is this a domestic or international flight? (D/I): D

===================================
     Available Airports in Pakistan
===================================
KHI - Karachi       CJL - Chitral       GWD - Gwadar
BHV - Bahawalpur    LYP - Faisalabad    ISB - Islamabad
...

Enter DEPARTURE city code: ISB
Enter ARRIVAL city code: LHR
Enter DEPARTURE date (DD/MM/YYYY): 25/12/2024
Enter number of seats: 2

Enter seat type (choose one):
E - Economy (Rs 15,000 extra)
B - Business (Rs 30,000 extra)
F - First Class (Rs 50,000 extra)
Your choice: B

===================================
            Booking Summary
===================================
From:               ISB
To:                 LHR
Departure Date:     25/12/2024
Number of Seats:    2
Seat Type:          Business
Meal Preference:    Default
Total Fare (Rs):    178,500.00
===================================
```


## 💰 Fare Calculation Logic

```
Total Fare = (Base Fare × Age Rate + Region Surcharge + Seat Class Surcharge)
             × Number of Seats
             × (1 − Platinum Discount)
             × (1 + 15% Tax)
```

| Component | Value |
|---|---|
| Base Fare | PKR 30,000 |
| Domestic Region | +PKR 30,000 |
| International Region | +PKR 50,000 |
| Economy Class | +PKR 15,000 |
| Business Class | +PKR 30,000 |
| First Class | +PKR 50,000 |
| Adult Rate | 100% |
| Child Rate | 75% |
| Infant Rate | 50% |
| Platinum Discount | −10% |
| Tax | +15% |

