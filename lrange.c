#include "redis_cmd.h"
#include <stdlib.h>

/*lrange key start end*/
RESULT lrange(char *key, int start, int end)
{
	int i = 0;
	char cmd[CMD_MAX_LENGHT] = {0};
	redisReply *reply;
	
    snprintf(cmd,CMD_MAX_LENGHT,"lrange %s %d %d", key, start, end);
    
	if ((reply = execRedisCmd(cmd)) == NULL)
	{
		return FAILURE;
	}
	
	if(!(reply->type == REDIS_REPLY_ARRAY && reply->elements > 0))
    {
        printf("%d execute command:%s failure\n", __LINE__, cmd);
        freeReplyObject(reply);
        return FAILURE;
    }
	
    for(i = 0;i < reply->elements;i++)
    {
        printf("%s\n",reply->element[i]->str);
    }
	
	freeReplyObject(reply);
    return SUCCESS;
}

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