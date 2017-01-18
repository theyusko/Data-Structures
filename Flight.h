/*
 * Ecem ilgun
 * 21502157
 */


#ifndef FLIGHT_H
#define FLIGHT_H


class Flight
{
    public:
        Flight();
        Flight( const int flightNo, const int rowNo, const int seatNo);
        ~Flight();
        //CHECK LATER
        Flight& operator=( const Flight& );
        void show();
        void reserve( const int numPassengers, const int *seatRow, const char *seatCol, int &code);
        void cancelReserve( const int code, bool& exists);
        bool reservationExists( const int code);
        void showReserve( const int code );
        int getAvailableSeats();
        int flightNo;

    private:
        int rowNo, seatNo;
        int **plane;
};

#endif // FLIGHT_H
