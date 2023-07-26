#include "main.h"

int main(void)
{
	int _setenv(const char *name, const char *value, int overwrite);
	return (0);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
		return (-1);
	if (overwrite == 0)
	{
		if (getenv(name) != NULL)
		{
			return (0);
		}
	}


}
