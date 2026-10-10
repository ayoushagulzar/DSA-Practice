## Question 01 - Cinepax Seat Booking

Cinepax wants to store the booking status of seats in a single hall using a dynamically sized array of integers (0 = free, 1 = booked), because different halls have different seat counts decided only when the hall is registered at runtime. Management also wants the hall's capacity to be increased later if extra seats are added (e.g. a hall extension), without losing existing bookings.
Design a class SeatHall that safely manages this using dynamic memory. Your class must provide:
1.	A constructor that accepts the initial number of seats and allocates the array on the heap, initializing every seat to free (0).
2.	A method bookSeat(int seatNumber) that marks a seat as booked, but must reject the request safely (without crashing) if seatNumber is out of range.
3.	A method expandHall(int extraSeats) that grows the array to hold extraSeats more seats, WITHOUT losing the booking status of existing seats.
4.	A destructor that releases all heap memory correctly.
5.	A copy constructor and copy assignment operator so that copying a SeatHall object produces a fully independent hall (changing bookings in the copy must not affect the original).

## Question 02 - Campus Parking Manager 

FAST wants a system to manage parking slots in a new parking lot. The NUMBER OF SLOTS is not fixed in the source code — it is entered by the admin when the lot is registered (it could be 50 slots at one campus block and 120 at another), so the slot list must be built at runtime using dynamic memory. Each slot is simply 'free' or 'occupied'.

Implement a class ParkingManager using a dynamically allocated array (bool*) that satisfies the following:

1.	A constructor that accepts the total number of slots and allocates the array on the heap, marking every slot as free initially.
2.	bookSlot(int slotNumber) and releaseSlot(int slotNumber) — both must safely reject an out-of-range slotNumber instead of crashing.
3.	findFirstFreeSlot() — returns the index of the first free slot, or -1 if the lot is full.
4.	A destructor that correctly releases the heap array.
5.	The admin office occasionally needs a full backup snapshot of a lot's current state: ParkingManager backup = liveLot; and later backup = anotherLot;. Implement the copy constructor and copy assignment operator (with a self-assignment guard) so that the backup is a fully independent copy — later bookings on the live lot must NOT affect the backup, and vice versa.
