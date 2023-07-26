int __exit(char **tokens)
{
	if 
	exit(0);
}


int inbuilts(char **tokens)
{
	size_t i;

	inbuilt_t func[5] = {
		{"exit", __exit},
	}

	for (i = 0; fun[i]; i++)
	{
		if (strcmp(fun[i].name, token[0]) == 0)
		{
			return (fun[i].func());
		}
	}
	return (NOT_INBUILT);
}
