OS := $(shell uname)

ifeq ($(OS), Darwin)
	FLAGS = -lm 
else
	FLAGS = -lnsl -lm
endif

build:
	rpcgen -C game.x
	gcc -o server p_server.c game_svc.c game_xdr.c  $(FLAGS)
	gcc -o client p_client.c game_clnt.c game_xdr.c  $(FLAGS)

clean:
	rm -f client server game.h game_svc.c game_clnt.c
