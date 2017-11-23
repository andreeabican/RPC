struct game_request{
	int n;
};
struct game_result{
	int match;
	long a;
	long b;
	long m;
	long s;
	long r;
};

program GAMEPROG{
	version GAMEVERS{
		game_result FIND_NUMBERS(game_request) = 1;
	} = 1;
} = 0x32345678;
