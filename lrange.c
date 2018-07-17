#include "redis_cmd.h"
#include <stdlib.h>

int main(int argc,char *argv[])
{
	if (argc != 4)
	{
		printf("parameter count < 3.usage: lpush key string");
		return -1;
	}
	
	lrange(argv[1], atoi(argv[2]), atoi(argv[3]));
	
    return 0;
}