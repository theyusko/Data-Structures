/*
 * Ecem ilgun
 * 21502157
 */


#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight(){
    flightNo = 0;
    rowNo = 0;
    seatNo = 0;
    plane = NULL;
}


Flight::Flight( const int flightNo, const int rowNo, const int seatNo) {
    this->flightNo = flightNo;
    this->rowNo = rowNo;
    this->seatNo = seatNo;
    plane = new int *[rowNo];
    for (int i = 0; i < rowNo; i++) {
        plane[i] = new int[seatNo];
        for (int j = 0; j < seatNo; j++) {
            plane[i][j] = -1;
        }
    }
}


Flight::~Flight(){
    for (int i = 0; i < rowNo; i++)
        delete [] plane[i]; //deletes columns = seats
    delete [] plane;
}


//CHECK! FOR MT2
Flight& Flight::operator=(const Flight& other ){
    if (&other != this) {
        if (plane != NULL) {
            //delete previous data
            for (int i = 0; i < rowNo; i++)
                delete [] plane[i]; //deletes columns = seats
            delete [] plane;
        }
        //equal it to the new data
        flightNo = other.flightNo;
        rowNo = other.rowNo;
        seatNo = other.seatNo;
        plane = new int*[rowNo];
        for (int i = 0; i < rowNo; i++) {
            plane[i] = new int[seatNo];
            for (int j = 0; j < seatNo; j++)
                plane[i][j] = other.plane[i][j];
        }
    }
    return *this;
}


void Flight::show() {
    cout << "Flight " << flightNo << " has " << getAvailableSeats() << " available seats" << endl;

    for (int i = 0; i < seatNo; i++)
        cout << (char) ('A' + i) << " "; // prints out the seat names
    cout << endl;

    for (int i = 0; i < rowNo; i++) {
            cout << i + 1 << " "; // prints out the row number
        for (int j = 0; j < seatNo; j++) {
            if ( plane[i][j] == -1)
                cout << "o ";
            else
                cout << "x ";
        }
        cout << endl;
    }
}


void Flight::reserve(const int numPassengers, const int *seatRow, const char *seatCol, int &code) {
    cout << endl;

    //Checks if any of the seats are already taken
    int row, column;
    bool exists = false;
    for (int i = 0; i < numPassengers; i++) {
        row = seatRow[i] - 1;
        column = seatCol[i] - 'A'; //Convert the seatNo's into corresponding columns
        if (plane[row][column] != -1) {
        cout << seatRow[i] << seatCol[i] << " ";
        exists = true;
        }
    }
    if (exists) {
        cout << " not available" << endl;
        code = -1;
        return;
    }

    //reserves the seats
    for (int i = 0; i < numPassengers; i++) {
        row = seatRow[i] - 1;
        column = seatCol[i] - 'A';
        plane[row][column] = code;
    }
}


void Flight::cancelReserve( const int code , bool& exists) {
    if (reservationExists(code)) {
        exists = true;

        cout << "Reservation for the seats ";
        for (int i = 0; i < rowNo; i++) {
            for (int j = 0; j < seatNo; j++) {
                if (plane[i][j] == code) { //make the reservation code -1 again, back to initial state
                    plane[i][j] = -1;
                    cout << i+ 1 << (char)('A' + j) << " ";
                }
            }
        }
        cout << "is cancelled in Flight " << flightNo << endl;
    }
}


bool Flight::reservationExists( const int code) {
    for (int i = 0; i < rowNo; i++) {
        for (int j = 0; j < seatNo; j++) {
            if (plane[i][j] == code)
                return true;
        }
    }
    return false;
}


void Flight::showReserve( const int code ) {
    if ( reservationExists(code) ) {
        cout << "Reservations under Code " << code << " in Flight "<< flightNo << ": " ;

        //print the seating of reservation
        for (int i = 0; i < rowNo; i++) {
            for (int j = 0; j < seatNo; j++) {
                if (plane[i][j] == code)
                    cout << i + 1 << (char) (j + 'A') << " ";
            }
        }
        cout << endl;
    }
}


int Flight::getAvailableSeats() {
    int availableCount = 0;
    for (int i = 0; i < rowNo; i++) {
        for (int j = 0; j < seatNo; j++) {
            if (plane[i][j] == -1)
                availableCount++;
        }
    }
    return availableCount;
}
