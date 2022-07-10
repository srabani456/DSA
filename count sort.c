#include <stdio.h>
#include <string.h>

int k=255; 
void countSort(char arr[])
{
	int n=strlen(arr);
    char output[n];
    int i;
    int count[k + 1];
    for(i=0;i<=k;i++)
    count[i]=0;
 
    for (i = 0; i<n; i++)
        ++count[arr[i]];
 
    for (i = 1; i <= k; i++)
        count[i] += count[i - 1];
 
    for (i = 0; i<n; i++) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
 
    for (i = 0; i<n; i++)
        arr[i] = output[i];
}
 
int main()
{
    char arr[] = "abbacddc";
 
    countSort(arr);
 
    printf("Sorted character array is %s", arr);
    return 0;
}
