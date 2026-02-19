#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

// Constants and precomputed data
const int SMALL_N_MAX = 39; // Max n for full number output
const int MOD = 10000;      // Modulus for last 4 digits
const int PERIOD = 15000;   // Pisano period for mod 10000

unsigned long long fib_small[SMALL_N_MAX + 1];
int fib_mod[PERIOD];
long double LOG10_PHI;
long double LOG10_SQRT5;

void init() {
    // Precompute small Fibonacci numbers
    fib_small[0] = 0;
    fib_small[1] = 1;
    for (int i = 2; i <= SMALL_N_MAX; ++i) {
        fib_small[i] = fib_small[i-1] + fib_small[i-2];
    }

    // Precompute Pisano period for mod 10000
    fib_mod[0] = 0;
    fib_mod[1] = 1;
    for (int i = 2; i < PERIOD; ++i) {
        fib_mod[i] = (fib_mod[i-1] + fib_mod[i-2]) % MOD;
    }

    // Precompute logarithmic constants for first 4 digits
    long double phi = (1.0L + sqrtl(5.0L)) / 2.0L;
    LOG10_PHI = log10l(phi);
    LOG10_SQRT5 = log10l(sqrtl(5.0L));
}

// Get last 4 digits using Pisano period
int get_last_4_digits(ll n) {
    if (n == 0) return 0;
    return fib_mod[n % PERIOD];
}

// Get first 4 digits using logarithms (works for n >= 40)
int get_first_4_digits(ll n) {
    long double x = n * LOG10_PHI - LOG10_SQRT5;
    long double frac = x - floorl(x);
    long double power = frac + 3.0L; // Get 10^(frac + 3)
    return (int)powl(10.0L, power);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    ll n;
    while (cin >> n) {
        if (n <= SMALL_N_MAX) {
            // For n <= 39, print the full number
            cout << fib_small[n] << "\n";
        } else {
            // For n >= 40, print first and last 4 digits
            int first_4 = get_first_4_digits(n);
            int last_4 = get_last_4_digits(n);

            cout << first_4 << "...";
            cout << setw(4) << setfill('0') << last_4 << "\n";
        }
    }
    return 0;
}
