# Sorting Techniques — Scenario-Based Practice Questions

## Question 01 — Hospital Emergency Queue Records

A hospital maintains an array containing patient priority scores recorded in the order they were received. Before preparing a report, the system must arrange the scores in ascending order.

The sorting process repeatedly examines pairs of neighboring elements. Whenever the earlier element is greater than the next element, their positions are exchanged. After each complete pass, the largest remaining value reaches its correct position at the end of the unsorted portion.

The hospital also wants to observe how the array changes throughout the process.

**Requirements:**

1. Take the number of patients and their priority scores as input.
2. Display the original array.
3. Arrange the scores in ascending order using the described process.
4. Display the array after every complete pass.
5. Display the total number of passes and exchanges performed.
6. Display the final sorted array.

**Conditions:**

- Identify the sorting algorithm from the scenario before implementing it.
- Do not use `sort()`, STL containers, or another sorting algorithm.
- Use the original array for sorting.
- Handle duplicate values correctly.
- Test the program with already sorted, reverse-sorted, and randomly arranged inputs.

---

## Question 02 — Smart Railway Ticket Record System

A railway reservation office stores ticket numbers in an array. Most days, the ticket numbers are already arranged or require only a few corrections. The existing system, however, continues processing the array even when all ticket numbers are already in the correct order.

Develop an improved sorting solution that arranges ticket numbers in ascending order while avoiding unnecessary work.

During each pass, the system must examine neighboring elements and exchange them whenever they are out of order. It must also maintain a variable indicating whether any exchange occurred during the current pass. If a complete pass finishes without an exchange, the system must terminate immediately.

**Requirements:**

1. Accept the number of tickets and their ticket numbers.
2. Display the original array.
3. Sort the ticket numbers using the described process.
4. Display the array after each pass.
5. Display the number of passes and exchanges performed.
6. Display a message explaining whether the process terminated early.
7. Display the final sorted array.

**Conditions:**

- Identify the required algorithm and its optimization.
- Do not use `sort()`, STL containers, or another sorting algorithm.
- Do not terminate simply because the array appears nearly sorted; the termination condition must be verified.
- Test an already sorted array, a reverse-sorted array, an array containing duplicates, and an array with a single element.
- Ensure that the pass counter reflects the actual number of passes executed.

---

## Question 03 — University Admission Merit Processor

A university receives applicants' admission scores in an array. The administration wants to arrange the scores in ascending order. Instead of repeatedly comparing neighboring elements, the program must build an ordered portion of the array from left to right.

The first score is initially considered ordered. For every subsequent score, the program must preserve its value in a temporary variable, compare it with the previously processed scores, shift every larger score one position to the right, and insert the stored score into the resulting empty position.

**Requirements:**

1. Accept the number of applicants and their scores.
2. Display the original array.
3. Display the initially ordered portion.
4. For each subsequent element, display the value selected for insertion.
5. Show the shifts performed and the array after every iteration.
6. Display the final sorted array.

**Conditions:**

- Identify the sorting algorithm from the described behavior.
- Do not use `sort()`, STL containers, another array, or repeated swapping as the main insertion mechanism.
- Use a temporary variable and shifting.
- Preserve duplicate scores.
- Test the cases where the selected value belongs at the beginning, in the middle, and at the end of the ordered portion.
- Explain why the temporary variable must preserve the selected value before shifting begins.

---

## Question 04 — Electronic Store Price Auditor

An electronics store maintains product prices in an array. The manager wants to arrange them in ascending order while minimizing the number of exchanges between array positions.

The system must divide the array conceptually into an ordered portion and an unordered portion. During each pass, it must search the entire unordered portion for its smallest value. Once the smallest value is found, the system must place it at the beginning of that portion by exchanging it with the element currently occupying that position.

Once a position has been finalized, it must not be included in subsequent searches.

**Requirements:**

1. Accept the number of products and their prices.
2. Display the original array.
3. Identify the current unordered portion during every pass.
4. Display the minimum value found and its index.
5. Display the array after placing that value in its correct position.
6. Count and display the number of comparisons and exchanges.
7. Display the final sorted array.

**Conditions:**

- Identify the appropriate sorting algorithm.
- Do not use `sort()`, STL containers, or another sorting algorithm.
- Do not create a second array.
- Avoid exchanging an element with itself.
- Handle duplicate prices and arrays containing identical values.
- Explain why the number of exchanges can remain low even when the array is initially in reverse order.

---

## Question 05 — Parcel Weight Optimizer

A logistics company records parcel weights in an array:

`120, 35, 90, 15, 75, 10, 60, 25`

The company wants to arrange the weights in ascending order. However, the system should initially compare elements separated by a relatively large distance instead of restricting every comparison to neighboring positions.

The distance, called the gap, must initially be equal to the array size. After each pass, reduce the gap by dividing it by a shrink factor of `1.3`, using integer conversion. If the resulting gap becomes smaller than `1`, set it to `1`.

For the current gap, compare every pair of elements whose indices differ by that gap. Exchange them whenever they are out of order. Continue processing until the gap is `1` and a complete pass finishes without any exchanges.

**Requirements:**

1. Take the number of parcels and their weights as input.
2. Display the original array.
3. Display the gap used during every pass.
4. Display the indices and values compared during each pass.
5. Display the array after each pass.
6. Display the final sorted array.

**Conditions:**

- Identify the sorting algorithm represented by the scenario.
- Do not use `sort()`, STL containers, another array, or any other sorting algorithm.
- Use the specified gap-reduction rule.
- Ensure that the final gap does not become smaller than `1`.
- Do not terminate merely because the gap reaches `1`; the final pass must also be free of exchanges.
- Test with duplicate values and an already sorted array.

---

## Question 06 — Industrial Sensor Data Organizer

An industrial monitoring system stores thousands of sensor readings in an array. The readings are not arranged in ascending order, and the system needs to bring elements closer to their correct positions before completing the final arrangement.

The algorithm must begin by selecting a gap equal to half the array size. For each gap, process elements from left to right. Store the current element temporarily, then compare it with earlier elements separated by the same gap. Shift larger elements forward by the gap until the correct position is found, and insert the stored value.

After processing all eligible elements for the current gap, reduce the gap to half its previous value using integer division. Continue until the gap becomes zero.

**Requirements:**

1. Accept the number of sensor readings and their values.
2. Display the original array.
3. Display the gap at the beginning of each pass.
4. For every selected element, display its original index, the shifts performed, and its final position.
5. Display the array after completing each gap pass.
6. Display the final sorted array.

**Conditions:**

- Identify the sorting algorithm represented by the process.
- Do not use `sort()`, STL containers, or another sorting algorithm.
- Use a temporary variable and gap-based shifting rather than repeated swapping.
- Do not create another array.
- Handle arrays of odd and even lengths.
- Ensure that a gap of `1` is processed before termination.
- Explain why the final pass alone may not be sufficient to understand the algorithm's earlier behavior.

---

## Question 07 — Integrated Sorting Logic Challenge

A software company stores the processing times of its tasks in an array. The company is evaluating different ways to arrange these values in ascending order.

Implement a menu-driven C++ program that allows the user to choose between the following six behaviors:

1. Repeatedly compare neighboring elements and exchange out-of-order pairs.
2. Perform neighboring comparisons but stop when a complete pass makes no exchanges.
3. Build an ordered portion by inserting each selected value after shifting larger elements.
4. Search the unordered portion for its minimum value and place it at the beginning of that portion.
5. Compare elements separated by a shrinking gap, using a shrink factor of `1.3`.
6. Use gap-based insertion, beginning with half the array size and repeatedly halving the gap.

**Requirements:**

1. Accept an array of task processing times.
2. Display the six descriptions without revealing the algorithm names.
3. Let the user select a behavior.
4. Implement each behavior in a separate function.
5. Preserve the original input so the same data can be used for every selection.
6. Display the intermediate arrays, relevant counters, and final sorted result.
7. Allow the user to select multiple behaviors without re-entering the original values.

**Conditions:**

- Identify the appropriate algorithm for each behavior before implementation.
- Do not use `sort()`, STL containers, or library-based sorting.
- Keep each implementation independent.
- Use consistent definitions for counting comparisons and exchanges.
- Test empty or invalid input according to your chosen array representation, along with single-element, duplicate-containing, sorted, and reverse-sorted arrays.
