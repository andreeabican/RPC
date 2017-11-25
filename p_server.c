#include <rpc/rpc.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <math.h>

long get_next_prime(long n);
long is_prime(long n);
void calculate_square_roots(long n, long *res1, long *res2);

game_result *find_numbers_1_svc(game_request *request, struct svc_req *cl)
{
	static game_result result;
	
	long n = request->n;
	if (is_prime(n) && n % 4 ==1) {
		result.match = 1;
		calculate_square_roots(n, &result.a, &result.b);
	} else {
		result.match = 0;
		result.m = get_next_prime(n);
		calculate_square_roots(result.m, &result.a, &result.b);
	}
	return (&result);
}

void calculate_square_roots(long n, long *res1, long *res2) {
	long a;
	for (a = 1; a * a <= n; a++) {
		double aux_b = sqrt(n - a*a);
		if (aux_b == (long)aux_b) {
			*res1 = a;
			*res2 = (long)aux_b;
			break;
		}
	}	
}

long get_next_prime(long n) {
    long m, p;
    int is_m_prime = 0, is_p_prime = 0;
    
    if (n % 4 == 0) {
        m = n - 3;
    } else {
        m = n / 4 * 4 + 1;
    }
    
    p = m + 4;
	while (!is_prime(m) && !is_prime(p)) {
		m -= 4;
        p += 4;
	}
  
    if (is_prime(m)) {
        is_m_prime = 1;
    }
    if (is_prime(p)) {
        is_p_prime = 1;
    }
    
    if (is_p_prime == 1 && is_m_prime == 1) {
        return n - m > p - n ? p : m;
    } else if (is_m_prime == 1) {
        return m;
    }
    return p;
}

long is_prime(long n)
{
	long i;
	for (i = 2; i*i <= n; i++){
        if ((n % i) == 0) {
			return 0;
        }
	}
	return 1;
}
