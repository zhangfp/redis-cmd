all:
	gcc -o lpush lpush.c redis_cmd.c -I./include -lhiredis
	gcc -o lrange lrange.c redis_cmd.c -I./include -lhiredis