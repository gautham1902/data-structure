#include<stdio.h>


int max(int a, int b);
int findMax(int i, int j, int *arr);
int maxArrElement(int len,int arr[]);
int testArr[] = {3,6,4,7,120,8,23,90,78,24,56,203,244,67,90};

int main()
{
    int leng = sizeof(testArr)/sizeof(testArr[0]);
    int maxVal = maxArrElement(leng,testArr);
    printf("Max value of array is %d\n",maxVal);
    return 1;
}

int maxArrElement(int len,int arr[])
{
    if(len == 0)
    {
        return 0;
    }

    return findMax(0,len,arr);
}

int findMax(int i, int j, int *arr)
{
    if (i ==j)
    {
        return arr[i];
    }

    int mid = (i+j)/2;
    return max(findMax(i,mid,arr),findMax(mid+1,j,arr));
}

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }else
    {
        return b;
    }
}