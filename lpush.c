#include "redis_cmd.h"

/*lpush key string*/
RESULT lpush(char *key, char *string)
{
	char cmd[CMD_MAX_LENGHT] = {0};
	redisReply *reply;
	
    snprintf(cmd,CMD_MAX_LENGHT,"lpush %s %s",key, string);
	
	if ((reply = execRedisCmd(cmd)) == NULL)
	{
		return FAILURE;
	}
	
	if(!(reply->type == REDIS_REPLY_INTEGER && reply->integer > 0))
    {
        printf("%d execute command:%s failure\n",__LINE__, cmd);
        freeReplyObject(reply);
        return FAILURE;
    }
	
	freeReplyObject(reply);
    return SUCCESS;
}

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