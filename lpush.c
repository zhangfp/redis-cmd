#include "redis_cmd.h"

int main(int argc,char *argv[])
{
	if (argc !=3)
	{
		printf("parameter count < 3.usage: lpush key string");
		return -1;
	}
	
	lpush(argv[1], argv[2]);
	
    return 0;
}