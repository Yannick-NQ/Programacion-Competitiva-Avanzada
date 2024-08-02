#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    int a, b;
    // Scanf devuelve el número de elementos leídos
    while( scanf("%d %d", &a, &b) == 2){
        // o puedes verificar el EOF, ej.
        // while (scanf(“%d %d”, &a, &b) ¡= EOF)
        printf("%d\n", a + b);
    }
    return 0;
}