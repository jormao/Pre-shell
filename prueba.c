#include <stdio.h>
#include <string.h>

int main(int argc,char **argv,char** envp)
{
	char** env;
	for(env=envp;*env!=0;env++)
	{
		if ((strncmp("PATH", *env, 4) == 0))
		    printf("%s\n", *env);
	}
	return 0;
}
