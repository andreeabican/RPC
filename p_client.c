#include <rpc/rpc.h>
#include "game.h" 

int main(int argc, char *argv[])
{
	CLIENT *cl;

	game_result *result;
	game_request request; 

	if (argc != 3){
		printf("usage: %s host input_file\n", argv[0]);
		exit(1);
	}
	cl = clnt_create(
		argv[1], 
		GAMEPROG,
		GAMEVERS, 
		"tcp");

	if (cl == NULL){
		clnt_pcreateerror(argv[1]);
		exit(2);
	}
	
	long n;
	FILE *input_fp = fopen(argv[2], "r");
	FILE *output_fp = fopen("output", "a+");

	while (fscanf(input_fp, "%ld", &n) != EOF) {
		request.n = n;
		result = find_numbers_1(&request, cl);
		if (result->match == 1)
			fprintf(output_fp, "YES %ld %ld \n", result->a, result->b);
		else
			fprintf(output_fp, "NO %ld %ld %ld\n", result->m, result->r, result->s);
	}

	fclose(input_fp);
	fclose(output_fp);

	xdr_free(xdr_game_result, result);
	clnt_destroy(cl);

	return 0;
}
