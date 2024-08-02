#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    int a, b;
    // Parar cuando ambas entradas sean 0
    while( scanf("%d %d", &a, &b), (a || b)){
        printf("%d\n", a + b);
    }
    return 0;
}