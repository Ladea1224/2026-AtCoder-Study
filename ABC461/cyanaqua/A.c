#include <stdio.h>

int main(void)
{
    int attack, defense;
    scanf("%d %d", &attack, &defense);
    printf("%s", defense >= attack? "Yes" : "No");
    return 0;
}