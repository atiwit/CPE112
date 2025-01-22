#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) { //เช็คว่าเป็นจำนวนเฉพาะมั้ย

    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) //ถ้าหาร i แล้วลงตัวให้ return false
            return false;
    }
    return true;
}

void findPrimes(int a, int b) { //หาจำนวนเฉพาะทั้งหมด

    bool found = false;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("none");
    }
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    findPrimes(a, b);
  
    return 0;
}