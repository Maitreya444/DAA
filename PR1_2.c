//Write a non recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexities

#include <stdio.h>

int FIBOr(int iNo)
{
    if (iNo <= 1)
        return iNo;

    return FIBOr(iNo - 1) + FIBOr(iNo - 2);
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter a number: ");
    scanf("%d", &iValue);

    iRet = FIBOr(iValue);
    printf("Fibonacci number is %d\n", iRet);
    
    return 0;
}
