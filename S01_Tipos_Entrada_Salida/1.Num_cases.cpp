#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    int TC, a, b;
    scanf("%d", &TC); // número de casos de prueba
    while(TC--){ // atajo que repite hasta 0
        scanf("%d %d", &a, &b); // respuesta procesada
        printf("%d\n", a+b); // sobre la marcha
    }
    return 0;
}