#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    int a, b, c = 1;
    while (scanf("%d %d", &a, &b) != EOF) { 
        if (c > 1) printf("\n");
        printf("Case %d: %d\n", c++, a + b);
    }
    return 0;
}