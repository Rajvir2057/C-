// Selection Sort Program
#include <iostream>
using namespace std;

//declared the functions
void fill_array(int a[], int size, int& number_used);
void sort(int a[], int number_used);
void swap_values(int& v1, int& v2);
int index_of_smallest(const int a[], int start_index, int number_used);

// main to run 
int main()
{
    int sample_array[10], number_used;

    cout << "Selection Sort:\nEnter up to 10 nonnegative whole numbers (end with a negative number):\n";
    fill_array(sample_array, 10, number_used);

    sort(sample_array, number_used);

    cout << "In sorted order the numbers are:\n";
    for (int i = 0; i < number_used; i++)
        cout << sample_array[i] << " ";
    cout << endl;

    return 0;
}
//defining the functions 
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

void sort(int a[], int number_used)
{
    int index_of_next_smallest;

    for (int index = 0; index < number_used - 1; index++)
    {
        index_of_next_smallest = index_of_smallest(a, index, number_used);
        swap_values(a[index], a[index_of_next_smallest]);
    }
}

void swap_values(int& v1, int& v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_of_smallest(const int a[], int start_index, int number_used)
{
    int min = a[start_index],
        index_of_min = start_index;

    for (int index = start_index + 1; index < number_used; index++)
    {
        if (a[index] < min)
        {
            min = a[index];
            index_of_min = index;
        }
    }

    return index_of_min;
}
