// C program for the above approach
#include <stdio.h>
#include <string.h>

// Function for bit stuffing
void bitStuffing(int N, int arr[])
{
    // Stores the stuffed array
    int brr[30];

    // Variables to traverse arrays
    int i, j, k;
    i = 0;
    j = 0;

    // Loop to traverse in the range [0, N)
    while (i < N) {

        // If the current bit is a set bit
        if (arr[i] == 1) {
          
            // Stores the count of consecutive ones
            int count = 1;

            // Insert into array brr[]
            brr[j] = arr[i];

            // Loop to check for
            // next 5 bits
            for (k = i + 1;
                 arr[k] == 1 && k < N && count < 5; k++) {
                j++;
                brr[j] = arr[k];
                count++;

                // If 5 consecutive set bits
                // are found insert a 0 bit
                if (count == 5) {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }

        // Otherwise insert arr[i] into
        // the array brr[]
        else {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }

    // Print Answer
    for (i = 0; i < j; i++)
        printf("%d", brr[i]);
}

// Driver Code
int main()
{
    int N = 11;
    int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    bitStuffing(N, arr);

    return 0;
}