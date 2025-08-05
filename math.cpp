// count of prime number ina range 1 to N
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
        for (int j = i * 2; j < n; j = j + i) {
            isPrime[j] = false;
        }
    }
    return count;
}

void printDigits(int n) {
    int count = 0;
    while (n != 0) {
        int digit = n % 10;
        cout << digit << endl;
        count++;
        n /= 10;
    }
    cout << "total count = " << count << endl;
}

bool isArmstrong(int n) {
    if (n == 1) {
        return true;
    }
    if (n <= 0) {
        return false;
    }

    int result;
    int tempN = n;
    while (tempN != 0) {
        int digit = tempN % 10;
        int digitcube = digit * digit * digit;
        result += digitcube;
        cout << "at digit = " << digit << " Result = " << result << " Digit coube = " << digitcube << endl;
        tempN /= 10;
    }
    cout << "final result: " << result << endl;

    return result == n;
}

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) return b;
    return a;
}

int lcm(int a, int b) {
    int ngcd = gcd(a, b);
    return (a * b) / ngcd;
}

int reverseNum(int n) {
    if (n <= 0) {
        return n;
    }
    int revNum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
            return 0;
        }
        revNum = (revNum * 10) + digit;
        n /= 10;
    }
    return revNum;
}

int main() {
    int n = 3456;
    // printDigits(n);
    // cout << (int)(log10(n) + 1) << endl;
    cout << isArmstrong(153) << endl;
    cout << gcd(20, 28) << endl;
    cout << reverseNum(4537) << endl;
    return 0;
}