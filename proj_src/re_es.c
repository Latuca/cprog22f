#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct real_estate{
    char address[20];
    char apt_name[20];
    int price;
}Re_Es;
int main()
{
    Re_Es A;
    int a[8]={1,2,3,4,5,6,7,8};
    QuickSort(a,0,7);
    return 0;
}

void QuickSort(int a[], int left, int right) //Quick Sorting 내림차순 알고리즘 for 가격
{
    int i = left;
    int j = right;
    int temp = a[i];

    if( left < right)
    {
        while(i < j)
        {
            while(a[j] <= temp && i < j)
            {
                j--;
                }
            a[i] = a[j];

            while(a[i] >= temp && i < j)
            {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = temp;

        QuickSort(a, left, i - 1);
        QuickSort(a, j + 1, right);
    }
}



 

