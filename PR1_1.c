//Write a non recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexities

#include<stdio.h>

int FIBOnr(int iNo)
{
    //F(n)=F(n−1)+F(n−2)
    int iCnt = 0;
    int arr[iNo + 2];
    arr[0] = 0;
    arr[1] = 1;

    for(iCnt = 2; iCnt <= iNo; iCnt++)
    {
        arr[iCnt] = arr[iCnt -1] + arr[iCnt -2];
        printf("%d\n", arr[iCnt]);
    }
    return arr[iNo];
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter a number \n");
    scanf("%d",&iValue);

    iRet = FIBOnr(iValue);

    printf("No is %d\n", iRet);

    return 0;
}