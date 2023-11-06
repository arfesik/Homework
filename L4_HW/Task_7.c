#include <stdio.h>
#include <math.h>
int main() {
    int number = 110101;
    int result = 0;
    int k = 0;
    while (number != 0) {
        result += (number % 10) * pow((double)2, (double)k);
        k++;
        number /= 10;
    }
    printf("%d", result);
    return 0;
}
