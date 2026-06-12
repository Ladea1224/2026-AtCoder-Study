#include <stdio.h>
#include <stdlib.h>

typedef struct Gem
{
    int value;
    int color;
} Gem;

int compare_gems(const void* a, const void* b) //taken from cppreference
{
    Gem arg1 = *(const Gem*)a;
    Gem arg2 = *(const Gem*)b;

    if (arg1.value < arg2.value) return 1;
    if (arg1.value > arg2.value) return -1;
    return 0;
}

typedef unsigned long long int lint;

int main(void)
{
    int numberOfGems, numberOfGemsToChoose, numberOfDistinctColors;
    scanf("%d %d %d", &numberOfGems, &numberOfGemsToChoose, &numberOfDistinctColors);

    Gem* gems = malloc(numberOfGems * sizeof(Gem));
    int largestColorValue = 0;
    for (int i = 0; i < numberOfGems; i++)
    {
        Gem newGem = {0, 0};
        gems[i] = newGem;
        scanf("%d %d", &(gems[i].color), &(gems[i].value));
        if (gems[i].color > largestColorValue) largestColorValue = gems[i].color;
    }

    qsort(gems, numberOfGems, sizeof(Gem), compare_gems);

    int variety = 0;
    int numberOfGemsChosen = 0;
    int* pickedGemsByColor = calloc(largestColorValue + 1, sizeof(int));
    lint totalValue = 0;

    for (int i = 0; i < numberOfGems; i++)
    {
        //printf("current gem: %d %d\n", gems[i].color, gems[i].value);
        int increasesVariety = pickedGemsByColor[gems[i].color] == 0;
        if (numberOfGemsToChoose - (numberOfGemsChosen + 1) >= numberOfDistinctColors - (variety + increasesVariety))
        {
            pickedGemsByColor[gems[i].color]++;
            variety += increasesVariety;
            numberOfGemsChosen++;
            totalValue += gems[i].value;
            //printf("picked!\n");
        }
        if (numberOfGemsChosen == numberOfGemsToChoose) break;
    }

    printf("%lld", totalValue);

    free(gems);
    free(pickedGemsByColor);
    return 0;
}