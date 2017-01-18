/*
 * Ecem ilgun
 * 21502157
 */
#include "ReservationSystem.h"
#include <iostream>
#include <string>
#include <cstddef>
#include "Flight.h"

using namespace std;

    ReservationSystem::ReservationSystem() {
        noOfFlights = 0;
        counter = 1;
        system = new Flight[10];
        // initialize with 10 - 20 sizes then create new one..
    }

    ReservationSystem::~ReservationSystem() {
            delete []system;
    }

    void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo ) {
        //Checks whether the flight with same number exists
        bool exists = false;
        for (int i = 0; i < noOfFlights; i++) {
            if (system[i].flightNo == flightNo )
                exists = true;
        }
        if ( exists) {
            cout << "Flight "<< flightNo <<" already exists" << endl;
            return;
        }
        //adds the flight into system
        Flight *tempSystem = system;
        system = new Flight[noOfFlights + 1];
        for (int i = 0; i < noOfFlights; i++)
            system[i] = tempSystem[i];

        system[noOfFlights] = Flight(flightNo, rowNo, seatNo);

        //deallocates temporary array
        delete []tempSystem;

        noOfFlights++;

        cout << "Flight " << flightNo << " has been added" << endl;
    }

    void ReservationSystem::cancelFlight( const int flightNo ) {
        cout << endl;

        //Checks whether the flight with same number exists
        //and if exists Finds the index of the flight
        bool exists;
        int i;
        for (i = 0; i < noOfFlights; i++) {
            if (system[i].flightNo == flightNo ) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            cout << "Flight "<< flightNo <<" does not exist" << endl;
            return;
        }

        //deletes the flight from system
        Flight *tempSystem = system;
        system = new Flight[noOfFlights - 1];
        for (int k = 0; k < i ; k++)
            system[k] = tempSystem[k];
        for (int k = i + 1; k < noOfFlights; k++)
            system[k - 1] = tempSystem[k];

        //deallocates temporary array
        delete []tempSystem;

        noOfFlights--;

        cout << "Flight " << flightNo << " and all of its reservations are canceled" << endl;
    }

    void ReservationSystem::showAllFlights() {
        cout << endl;
        if (noOfFlights == 0)
            cout << "No flights exist \n\n" ;
        else {
            cout << "Flights currently operated: "<< endl;
            for (int i = 0; i < noOfFlights; i++) {
                cout << "Flight " << system[i].flightNo << "(" << system[i].getAvailableSeats() << " available seats)" << endl;
            }
        }
    }

    void ReservationSystem::showFlight( const int flightNo ) {
        cout << endl;

        bool exists;
        int i; // index of flight if exists
        for (i = 0; i < noOfFlights; i++) {
            if (system[i].flightNo == flightNo ) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            cout << "Warning: flight "<< flightNo <<" doesn't exist" << endl;
            return;
        }

        system[i].show();

    }

    int ReservationSystem::makeReservation( const int flightNo, const int numPassengers,
                                            const int *seatRow, const char *seatCol ) {
        cout << endl;

        bool exists = false;
        int i, code;
        for (i = 0; i < noOfFlights; i++) {
            if (system[i].flightNo == flightNo ) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            cout << "Warning: the flight " << flightNo << "that you are trying to make reservation does not exist" << endl;
            return (-1)*1;
        }

        code = counter;
        system[i].reserve(numPassengers, seatRow, seatCol, code);
        if (code != -1) counter++;
        return code;
    }

    void ReservationSystem::cancelReservation( const int resCode) {
        bool exists = false;

        for (int i = 0; i < noOfFlights; i++) {
            system[i].cancelReserve(resCode, exists);
        }

        if(!exists)
            cout << "No reservations are found under code " << resCode<< endl;
    }

    void ReservationSystem::showReservation( const int resCode ) {
        cout << endl;
        bool flag = false;
        for (int i = 0; i < noOfFlights; i++) {
            if ( system[i].reservationExists( resCode)) {
                system[i].showReserve( resCode);
                flag = true;
            }
        }

        if (!flag)
            cout << "No reservations under code " << resCode << endl;
    }
