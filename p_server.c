#include <rpc/rpc.h>
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
		calculate_square_roots(result.m, &result.s, &result.r);
	}
	return (&result);
}

void calculate_square_roots(long n, long *res1, long *res2) {
	long a;
	for (a = 0; a * a <= n; a++) {
		double aux_b = sqrt(n - a*a);
		if (aux_b == (long)aux_b) {
			*res1 = a;
			*res2 = (long)aux_b;
			break;
		}
	}	
}

long get_next_prime(long n) {
	long m = n / 4 * 4 + 1;
	while (!is_prime(m)) {
		m -= 4;
	}
	return m;
}

long is_prime(long n)
{
	long i;
	for (i = 2; i*i <= n; i++){
		if ((n % i) == 0) 
			return 0;
	}
	return 1;
}
