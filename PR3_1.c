#include <stdio.h>
#include <stdlib.h>

struct Item 
{
    int weight;
    int profit;
    float pi_wi;
};

float calculatePiWi(int weight, int profit) 
{
    return (float)profit / (float)weight;
}

void DisplayPiWi(int items, struct Item *itemsArray) 
{
    printf("Calculating Pi/Wi for each item:\n");
    for (int i = 0; i < items; i++) 
    {
        itemsArray[i].pi_wi = calculatePiWi(itemsArray[i].weight, itemsArray[i].profit);
        printf("Item %d - Weight: %d, Profit: %d, Pi/Wi: %.2f\n", i + 1, itemsArray[i].weight, itemsArray[i].profit, itemsArray[i].pi_wi);
    }
}

void swap(struct Item *a, struct Item *b) 
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Item *itemsArray, int low, int high) 
{
    float pivot = itemsArray[high].pi_wi;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (itemsArray[j].pi_wi >= pivot) {
            i++;
            swap(&itemsArray[i], &itemsArray[j]);
        }
    }
    swap(&itemsArray[i + 1], &itemsArray[high]);
    return (i + 1);
}

void quicksort(struct Item *itemsArray, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(itemsArray, low, high);
        quicksort(itemsArray, low, pi - 1);
        quicksort(itemsArray, pi + 1, high);
    }
}

void Descending(struct Item *itemsArray, int items) 
{
    quicksort(itemsArray, 0, items - 1);
}

int main() 
{
    int items = 0;
    struct Item *itemsArray = NULL;
    int iCnt = 0;

    printf("Enter the number of elements:\n");
    scanf("%d", &items);

    itemsArray = (struct Item *)malloc(items * sizeof(struct Item));

    printf("Enter the elements (weight and profit) for each item:\n");
    for (iCnt = 0; iCnt < items; iCnt++) 
    {
        printf("Enter weight for item %d: ", iCnt + 1);
        scanf("%d", &itemsArray[iCnt].weight);
        printf("Enter profit for item %d: ", iCnt + 1);
        scanf("%d", &itemsArray[iCnt].profit);
    }

    DisplayPiWi(items, itemsArray);

    Descending(itemsArray, items);

    printf("Items sorted by Pi/Wi in descending order:\n");
    for (iCnt = 0; iCnt < items; iCnt++) 
    {
        printf("Item %d - Weight: %d, Profit: %d, Pi/Wi: %.2f\n", iCnt + 1, itemsArray[iCnt].weight, itemsArray[iCnt].profit, itemsArray[iCnt].pi_wi);
    }

    free(itemsArray);
    return 0;
}
