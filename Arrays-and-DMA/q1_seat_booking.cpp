#include <iostream>
using namespace std;

class seatHall
{
private:
    int no_of_seats;
    int *seats;

public:
    // constructor
    seatHall(int n)
    {
        no_of_seats = n;
        seats = new int[no_of_seats];

        for (int i = 0; i < no_of_seats; i++)
        {
            seats[i] = 0;
        }
    }

    // book seat method
    void bookSeat(int seat_no)
    {
        if (seat_no < 0 || seat_no >= no_of_seats)
        {
            cout << "Seat number out of range!" << endl;
        }
        else
        {
            seats[seat_no] = 1;
        }
    }

    // expand hall method
    void expandHall(int extraSeats)
    {
        int total_seats = extraSeats + no_of_seats;
        int *expandSeats = new int[total_seats];

        // copying exiting bookings
        for (int i = 0; i < no_of_seats; i++)
        {
            expandSeats[i] = seats[i];
        }

        // Initialize new seats as free
        for (int i = no_of_seats; i < total_seats; i++)
        {
            expandSeats[i] = 0;
        }

        delete[] seats; // deleting old array

        seats = expandSeats; // now seats point to new array

        no_of_seats = total_seats;
    }

    // copy constructor
    seatHall(const seatHall &other)
    {
        no_of_seats = other.no_of_seats;
        seats = new int[no_of_seats];

        for (int i = 0; i < no_of_seats; i++)
        {
            seats[i] = other.seats[i];
        }
    }

    // copy assignment
    seatHall &operator=(const seatHall &other)
    {
        if (this != &other)
        {
            delete[] seats;

            no_of_seats = other.no_of_seats;
            seats = new int[no_of_seats];

            for (int i = 0; i < no_of_seats; i++)
            {
                seats[i] = other.seats[i];
            }
        }

        return *this;
    }

    void printSeats()
    {
        for (int i = 0; i < no_of_seats; i++)
        {
            cout << seats[i] << " ";
        }
        cout << endl;
    }

    // destructor
    ~seatHall()
    {
        delete[] seats;
    }
};

int main()
{
    seatHall s1(10);

    s1.bookSeat(6);
    s1.expandHall(15);

    cout << "s1: ";
    s1.printSeats();

    // Copy constructor
    seatHall s2 = s1;

    s2.bookSeat(5);

    cout << "s1 after changing s2: ";
    s1.printSeats();

    cout << "s2: ";
    s2.printSeats();

    // Copy assignment
    seatHall s3(5);
    s3 = s1;

    s3.bookSeat(10);

    cout << "s1 after changing s3: ";
    s1.printSeats();

    cout << "s3: ";
    s3.printSeats();

    return 0;
}