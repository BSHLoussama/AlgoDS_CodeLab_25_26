#include<stdio.h>
int q, r, idx, i;
int data[] = {45, 23, 67, 12, 89, 34};
void euclidean_div(int a, int b, int *q, int *r);  // Fixed parameter order
int array_min(int arr[], int n, int *idx);
int array_max(int arr[], int n, int *idx);

int main()
{
    euclidean_div(17, 5, &q, &r);
    printf("%d / %d = %d remainder %d\n", 17, 5, q, r);
    euclidean_div(20, 4, &q, &r);
    printf("%d / %d = %d remainder %d\n", 20, 4, q, r);
    printf("Min = %d at index %d\n", array_min(data, 6, &idx), idx);
    printf("Max = %d at index %d\n", array_max(data, 6, &idx), idx);
}

void euclidean_div(int a, int b, int *q, int *r)
{
    *q = a / b;
    *r = a % b;
}

int array_min(int arr[], int n, int *idx)
{
    int min = arr[0];
    *idx = 0;  // Bug fixed: was *idx=5, should be 0
    for(i = 1; i < n; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
            *idx = i;
        }
    }
    return min;
}

int array_max(int arr[], int n, int *idx)
{
    int max = arr[0];
    *idx = 0;
    for(i = 1; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            *idx = i;
        }
        // Bug fixed: removed printf("%d", i); 
    }
    return max;
}