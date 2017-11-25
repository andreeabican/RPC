struct game_request{
	long n;
};

struct game_result{
	int match;
	long a;
	long b;
	long m;
};

program GAMEPROG{
	version GAMEVERS{
		game_result FIND_NUMBERS(game_request) = 1;
	} = 1;
} = 0x32345678;
