#include<stdio.h>

void merge(int arr[],int l, int m, int r);
void mergeSort(int arr[],int left, int right);

int main()
{
    int testArr[] = {12,56,34,78,99,2343,45,223,22,444,88,556,334};
    int length = sizeof(testArr)/sizeof(testArr[0]);

    mergeSort(testArr,0,length);

    for(int i=0;i<length;i++)
    {
        printf("%d ",testArr[i]);
    }
    printf("\n");
    return 1;
}

void mergeSort(int arr[],int left, int right)
{
    if(left < right)
    {
        int mid = left +(right-left)/2;
        mergeSort(arr, left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[],int l, int m, int r)
{
    int i=0,j=0,k=0;
    int s1 = m - l + 1;
    int s2 = r - m;
    int leftArr[s1];
    int rightArr[s2];

    for(i=0;i<s1;i++)
    {
        leftArr[i] = arr[l+i];
    }

    for(j=0;j<s2;j++)
    {
        rightArr[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<s1 && j<s2)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i<s1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j<s2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
