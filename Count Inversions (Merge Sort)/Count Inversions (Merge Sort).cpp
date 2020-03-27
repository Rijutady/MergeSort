// C++ program to Count Inversions in an array using Divide and Conquer (Merge Sort)

//Huiqing Wu (wj8664)
#include <iostream> 
using namespace std;

int mergeSort(int arr[], int temp[], int left, int right);
int merge_count(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
number of inversions in the array */

int count_inversion(int arr[], int array_size)
{
    int* temp = NULL;   // Pointer to int, initialize to nothing.
    temp = new int[array_size];  // Allocate n ints and save ptr in array.
    return mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call mergeSort and merge_count()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge_count(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge_count(int arr[], int temp[], int left,
    int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            //In merge process, let i is used for indexing left sub-array and j for right sub-array. 
            //At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
            //because left and right subarrays are sorted
            //so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
(if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Driver code 
int main()
{
    int arr[] = {1,5,4,8,10,2,6,9,12,11,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = count_inversion(arr, n);
    cout << "Number of inversions are " << ans;
    return 0;
}

