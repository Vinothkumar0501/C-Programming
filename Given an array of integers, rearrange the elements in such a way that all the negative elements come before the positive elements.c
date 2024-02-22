#include <stdio.h>
//Calculate array size
#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])
//swap function not handle null pointer scenario
//not much safe to use
void swap(int *s1, int *s2)
{
    int temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
// Moves all -ve element to begining of array
void segregateElements(int arr[], int n)
{
    int i =0,j = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)//non-zero
        {
            if (i != j)
            {
                swap(&arr[i],&arr[j]);
            }
            j++;
        }
    }
}
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    //get array size
    int arr_size = ARRAY_SIZE(arr);
    int i = 0;
    segregateElements(arr, arr_size);
    for (i = 0; i < arr_size; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
