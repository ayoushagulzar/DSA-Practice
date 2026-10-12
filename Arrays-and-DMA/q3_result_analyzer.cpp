#include <iostream>
using namespace std;

void findHighest(int arr[], int n)
{
    int highest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > highest)
        {
            highest = arr[i];
        }
    }
    cout << "Highest marks: " << highest << endl;
}

void findLowest(int arr[], int n)
{
    int lowest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }
    cout << "Lowest marks: " << lowest << endl;
}

void sumAvg(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    double avg = (double)sum / n;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;
}

void findMarks(int arr[], int n)
{
    int marks;
    int count = 0;

    cout << "Enter the marks you want to search for: ";
    cin >> marks;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == marks)
        {
            count++;
        }
    }

    cout << count << " student(s) scored " << marks << " marks." << endl;
}

void findSecondLargest(int arr[], int n)
{
    if (n < 2)
    {
        cout << "Second-largest distinct mark does not exist." << endl;
        return;
    }
    int largest = arr[0];
    int secondLargest = arr[0];
    bool found = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
            found = true;
        }
        else if (arr[i] < largest)
        {
            if (!found || arr[i] > secondLargest)
            {
                secondLargest = arr[i];
                found = true;
            }
        }
    }

    if (found)
        cout << "Second-largest distinct mark: " << secondLargest << endl;
    else
        cout << "Second-largest distinct mark does not exist." << endl;
}

void palindromeCheck(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    bool flag = true;
    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            flag = false;
            break;
        }

        left++;
        right--;
    }

    if (flag)
        cout << "Sequence is palindrome." << endl;
    else
        cout << "Sequence is not palindrome." << endl;
}

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int marks[100];

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of students. Enter a value between 1 and 100." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks. Enter marks between 0 and 100." << endl;
            return 0;
        }
    }

    cout << "\n--- University Exam Result Analyzer ---" << endl;

    findHighest(marks, n);
    findLowest(marks, n);
    findSecondLargest(marks, n);
    sumAvg(marks, n);
    cout << endl;

    findMarks(marks, n);
    cout << endl;

    palindromeCheck(marks, n);
    reverseArray(marks, n);

    return 0;
}
