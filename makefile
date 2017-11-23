build:
	rpcgen -C game.x
	gcc -o server p_server.c game_svc.c game_xdr.c -lm -lnsl -Wall
	gcc -o client p_client.c game_clnt.c game_xdr.c -lnsl -Wall

clean:
	rm -f client server game.h game_svc.c game_clnt.c
