#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    int a, b, c = 1;
    while (scanf("%d %d", &a, &b) != EOF) { 
        // fíjate en las dos ‘/n’
        printf("Caso %d: %d\n\n", c++, a + b);
    }
    return 0;
}