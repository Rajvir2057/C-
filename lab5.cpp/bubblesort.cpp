// Bubble Sort Program
#include <iostream>
using namespace std;

// declared the functions
void fill_array(int a[], int size, int& number_used);
void bubblesort(int arr[], int length);

//main is used to run the code
int main()
{
    int arr[10], number_used;

    cout << "Bubble Sort:\nEnter up to 10 nonnegative whole numbers (end with a negative number):\n";
    fill_array(arr, 10, number_used);

    bubblesort(arr, number_used);

    cout << "In sorted order the numbers are:\n";
    for (int i = 0; i < number_used; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

//defined the declared
void fill_array(int a[], int size, int& number_used)
{
    int next, index = 0;
    cin >> next;

    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }
    number_used = index;
}

void bubblesort(int arr[], int length)
{
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
