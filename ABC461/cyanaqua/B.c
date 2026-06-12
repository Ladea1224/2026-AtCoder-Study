#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numberOfWoodcutters;
    scanf("%d", &numberOfWoodcutters);

    int* claims = malloc((numberOfWoodcutters + 1) * sizeof(int));
    int* axeOwners = malloc((numberOfWoodcutters + 1) * sizeof(int));

    for (int i = 1; i <= numberOfWoodcutters; i++) scanf("%d", &claims[i]);
    for (int i = 1; i <= numberOfWoodcutters; i++) scanf("%d", &axeOwners[i]);

    int allHonest = 1;
    for (int i = 1; i <= numberOfWoodcutters; i++)
    {
        if (axeOwners[claims[i]] != i)
        {
             allHonest = 0;
             break;
        }
    }

    printf("%s", allHonest? "Yes" : "No");

    free(claims);
    free(axeOwners);
    return 0;
}