#include <iostream>
#include <windows.h>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int &n, int capacity)
{
    int index, bookId;

    cout << "Enter index where you want to insert new book-id: ";
    cin >> index;

    cout << "Enter bookId to insert: ";
    cin >> bookId;

    if (n >= capacity)
    {
        cout << "Array is full." << endl;
        return;
    }

    if (index < 0 || index > n)
    {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = bookId;
    n++;

    cout << "Book-Id inserted successfully." << endl;

    cout << "Updated array: ";
    display(arr, n);
}

void deleteId(int arr[], int &n)
{
    int index;

    cout << "Enter index of book-id you want to delete: ";
    cin >> index;

    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }

    if (index < 0 || index >= n)
    {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Book-Id deleted successfully." << endl;

    cout << "Updated array: ";
    display(arr, n);
}

void rotateRight(int arr[], int n)
{
    if (n <= 1)
    {
        cout << "Array must have more than one element to rotate." << endl;
        return;
    }
    int last = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
    cout << "Array after rotating right: ";
    display(arr, n);
}

void rotateLeft(int arr[], int n)
{
    if (n <= 1)
    {
        cout << "Array must have more than one element to rotate." << endl;
        return;
    }

    int first = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;
    cout << "Array after rotating left: ";
    display(arr, n);
}

int main()
{
    int capacity = 100;
    int arr[100];
    int n;

    cout << "Enter the number of book IDs initially: ";
    cin >> n;

    if (n < 0 || n > capacity)
    {
        cout << "Invalid number of book IDs." << endl;
        return 0;
    }

    cout << "Enter the book IDs:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int choice;

    do
    {
        cout << "\n===== Library Book-ID Manager =====" << endl;
        cout << "1. Display all book IDs" << endl;
        cout << "2. Insert a book ID" << endl;
        cout << "3. Delete a book ID" << endl;
        cout << "4. Rotate array left" << endl;
        cout << "5. Rotate array right" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Currently stored book ids: ";
            display(arr, n);
            break;

        case 2:
            insert(arr, n, capacity);
            break;

        case 3:
            deleteId(arr, n);
            break;

        case 4:
            rotateLeft(arr, n);
            break;

        case 5:
            rotateRight(arr, n);
            break;

        case 0:
            cout << "Exiting..." << endl;
            Sleep(500);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}