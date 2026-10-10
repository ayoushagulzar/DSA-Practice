#include <iostream>
using namespace std;

class parkingManager
{
    bool *slots;
    int totalslots;

public:
    // constructor
    parkingManager(int n)
    {
        totalslots = n;
        slots = new bool[totalslots];
        for (int i = 0; i < totalslots; i++)
        {
            slots[i] = false; // false means free
        }
    }

    // book slot function
    void bookSlot(int slotNumber)
    {
        if (slotNumber < 0 || slotNumber >= totalslots)
        {
            cout << "Invalid slot number!" << endl;
            return;
        }

        if (slots[slotNumber] == true)
        {
            cout << "Slot is already occupied." << endl;
            return;
        }

        slots[slotNumber] = true; // if not booked , then book the slot
        cout << "Slot booked successfully!" << endl;
    }

    // release slot function
    void releaseSlot(int slotNumber)
    {
        if (slotNumber < 0 || slotNumber >= totalslots)
        {
            cout << "Invalid slot number!" << endl;
            return;
        }

        if (slots[slotNumber] == false)
        {
            cout << "Slot is already free." << endl;
            return;
        }

        slots[slotNumber] = false;
        cout << "Slot released successfully!" << endl;
    }

    // find first free slot function
    int findFirstFreeSlot()
    {
        for (int i = 0; i < totalslots; i++)
        {
            if (slots[i] == false)
            {
                return i;
            }
        }
        return -1;
    }

    // destructor
    ~parkingManager()
    {
        delete[] slots;
    }

    // copy contructor
    parkingManager(const parkingManager &other)
    {
        totalslots = other.totalslots;
        slots = new bool[totalslots];

        for (int i = 0; i < totalslots; i++)
        {
            slots[i] = other.slots[i];
        }
    }

    // copy assignment operator
    parkingManager &operator=(const parkingManager &other)
    {
        if (this != &other)
        {
            bool *newSlots = new bool[other.totalslots];

            for (int i = 0; i < other.totalslots; i++)
            {
                newSlots[i] = other.slots[i];
            }

            delete[] slots;

            slots = newSlots;
            totalslots = other.totalslots;
        }

        return *this;
    }

    // to display all slots
    void display()
    {
        for (int i = 0; i < totalslots; i++)
        {
            cout << slots[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of slots: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of slots must be positive." << endl;
        return 0;
    }

    parkingManager liveLot(n);

    // Booking slots
    liveLot.bookSlot(1);
    liveLot.bookSlot(3);
    liveLot.bookSlot(1); // Already occupied
    liveLot.bookSlot(n); // Out of range

    cout << "\nLive lot: ";
    liveLot.display();

    // Find first free slot
    cout << "First free slot: " << liveLot.findFirstFreeSlot() << endl;

    // Copy constructor
    parkingManager backup = liveLot;

    liveLot.bookSlot(2);

    cout << "\nLive lot after booking slot 2: ";
    liveLot.display();

    cout << "Backup after changing live lot: ";
    backup.display();

    // Release a slot
    liveLot.releaseSlot(1);

    cout << "\nLive lot after releasing slot 1: ";
    liveLot.display();

    liveLot.releaseSlot(1); // Already free
    liveLot.releaseSlot(n); // Out of range

    // Copy assignment operator
    parkingManager anotherLot(3);

    anotherLot.bookSlot(0);
    anotherLot.bookSlot(2);

    backup = anotherLot;

    cout << "\nAnother lot: ";
    anotherLot.display();

    //remain unchanged
    cout << "Backup after assignment: ";
    backup.display();

    anotherLot.releaseSlot(0);

    cout << "\nAnother lot after releasing slot 0: ";
    anotherLot.display();

    //remain unchanged
    cout << "Backup after releasing slot 0: ";
    backup.display();

    // Self-assignment
    backup = backup;

    cout << "\nBackup after self-assignment: ";
    backup.display();

    return 0;
}
