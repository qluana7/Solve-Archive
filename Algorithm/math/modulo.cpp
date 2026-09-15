/*
 * Algorithm Name : Modulo Algorithms.
 *
 * Description
 * 
 * Modular Arimethics
 *    - 모듈러 연산 구현 
 * 
 * Modular Expontiation
 *    - 모듈러 거듭제곱 구현
 *    - 분할 정복을 이용한 거듭제곱 구현
 * 
 * Modular Multiplicative Inverse with Fermat's Little Theorem
 *    - 페르마의 소정리를 이용한 모듈러 역원 구하기
 * 
 *    - a^(m-1) ≡ 1 (mod m) (m is prime number)
 *      -> a^(m-2) ≡ a^-1 (mod m)
 * 
 *       a^-1 ≡ a^(m-2) (mod m)
 * 
 * Modular Multiplicative Inverse with Extended Euclidean Algorithm
 *    - 확장 유클리드 호제법을 이용한 모듈러 역원 구하기
 *    
 *    - // Under Construction
 * 
 * Note
 *    - Meaning of the x suffix on the function name:
 *      When calculating u64 * u64 % u64, it can overflow.
 *      The x suffix function prevents overflow using a hack.
 *      This is faster than using uint128_t,
 *      but cannot be used if 80-bit floating point is not supported.
 *      * A notable exception is MSVC, which implements long double
 *        in the same format as double. (https://en.cppreference.com/w/cpp/language/types)
 * 
 *    - Meaning of the c suffix on the function name:
 *      The c suffix means 'common'. It means, works even if the number is not prime.
 *      This uses the extended Euclidean algorithm to find the modular inverse.
 * 
 * Reference
 *    - mulmod : https://github.com/kth-competitive-programming/kactl/blob/main/doc/modmul-proof.md
 *    - https://en.wikipedia.org/wiki/Fermat%27s_little_theorem
 */

#include <tuple>

#define i64 long long
#define u64 unsigned long long

using namespace std;

extern tuple<u64, u64, u64> egcd(u64, u64);

// Forward declarations
u64 invmodc(u64, u64);


/* arithmetics */

u64 addmod(u64 a, u64 b, u64 m)
{ if ((a += b) >= m) a -= m; return a; }

u64 mulmod(u64 a, u64 b, u64 m)
{ return a * b % m; }

u64 divmod(u64 a, u64 b, u64 m)
{ return a * invmod(b, m); }

u64 divmodx(u64 a, u64 b, u64 m)
{ return a * invmodx(b, m); }

u64 divmodc(u64 a, u64 b, u64 m)
{ return a * invmodc(b, m); }

u64 mulmodx(u64 a, u64 b, u64 m) {
    i64 r = a * b - m * (u64)(1.L / m * a * b);
    return r + m * (r < 0) - m * (r >= (i64)m);
}


/* exponentiation */

// Modular hack : u64 * u64 % u64 without overflow.
u64 powmodx(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = mulmodx(r, a, m);
        a = mulmodx(a, a, m);
        b >>= 1;
    }

    return r;
}

u64 powmod(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return r;
}


/* inversion */

u64 invmodx(u64 a, u64 m) {
    return powmodx(a, m - 2, m);
}

u64 invmod(u64 a, u64 m) {
    return powmod(a, m - 2, m);
}

i64 inv(i64 a, i64 m) {
    auto [r, x, _] = egcd(a, m);

    if (r != 1) return -1;

    return addmod(x, m, m);
}
