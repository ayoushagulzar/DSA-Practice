# Arrays and Dynamic Memory — Practice Questions

## Part A — Dynamic Memory Allocation (DMA)

### Question 01 — Cinepax Seat Booking

Cinepax wants to store the booking status of seats in a single hall using a dynamically sized array of integers (`0` = free, `1` = booked). Different halls have different seat counts decided only when the hall is registered at runtime. Management also wants to increase the hall's capacity later without losing existing bookings.

Design a class `SeatHall` that safely manages this using dynamic memory.

**Requirements:**

1. Write a constructor that accepts the initial number of seats, allocates the array on the heap, and initializes every seat to free (`0`).
2. Implement `bookSeat(int seatNumber)` to mark a seat as booked. Reject out-of-range indices safely.
3. Implement `expandHall(int extraSeats)` to increase capacity without losing existing booking statuses. New seats must be initialized as free.
4. Write a destructor that releases the allocated memory.
5. Implement a copy constructor and copy assignment operator to ensure independent copies. Changing bookings in a copy must not affect the original object.

### Question 02 — Campus Parking Manager

FAST wants a system to manage parking slots in a new parking lot. The number of slots is entered by the admin at runtime. Each slot is represented by a Boolean value indicating whether it is free or occupied.

Implement a class `ParkingManager` using a dynamically allocated array (`bool*`).

**Requirements:**

1. Write a constructor that accepts the total number of slots, allocates the array, and marks every slot as free.
2. Implement `bookSlot(int slotNumber)` and `releaseSlot(int slotNumber)`. Both methods must reject out-of-range indices safely.
3. Implement `findFirstFreeSlot()` to return the index of the first free slot, or `-1` if the lot is full.
4. Write a destructor that releases the allocated memory.
5. Implement a deep-copy constructor and copy assignment operator, including a self-assignment guard.

---

## Part B — Array Manipulation

### Question 03 — University Exam Result Analyzer

A university stores students' marks in an integer array. The administration wants to analyze and rearrange the results without using built-in sorting functions.

Write a C++ program that accepts the number of students and their marks, then performs the following operations:

1. Find and display the highest and lowest marks.
2. Calculate the sum and average of all marks.
3. Count how many students obtained a particular mark entered by the user.
4. Find the second-largest **distinct** mark. If it does not exist, display an appropriate message.
5. Check whether the original sequence of marks is a palindrome **before modifying the array**.
6. Reverse the array in place and display the reversed array.

**Conditions:**

- Use an ordinary fixed-size array; dynamic memory is not required.
- Do not use built-in sorting or reversing functions.
- Handle duplicate marks correctly when finding the second-largest distinct mark.
- Validate the array size and marks where appropriate.
- Test cases with duplicate values, identical values, and small array sizes.

### Question 04 — Library Book-ID Manager

A library stores book IDs in an array in the order they were added. The librarian needs to insert and remove IDs while preserving the order of the remaining elements.

Write a menu-driven C++ program using a fixed-size array.

**Requirements:**

1. Maintain an array, its maximum capacity, and a variable tracking the number of occupied positions.
2. Display all currently stored book IDs.
3. Insert a new book ID at a specified index by shifting elements to the right.
4. Delete a book ID at a specified index by shifting elements to the left.
5. Reject insertion if the array is full.
6. Reject invalid indices and handle an empty list.
7. Rotate the array one position to the left or right.

**Examples:**

- Right rotation: `[12, 25, 31, 46]` becomes `[46, 12, 25, 31]`.
- Left rotation: `[12, 25, 31, 46]` becomes `[25, 31, 46, 12]`.
- Insert `20` at index `1` in `[10, 30, 40]` to obtain `[10, 20, 30, 40]`.
- Delete the element at index `1` from `[10, 20, 30, 40]` to obtain `[10, 30, 40]`.

**Conditions:**

- Use zero-based indexing.
- Do not use STL containers or built-in array-manipulation functions.
- Preserve the order of elements during insertion and deletion.
- Test insertion at the beginning, middle, and end, as well as deletion from an array with one element.
