char*	get_lines(int fd)
{
	struct	gnlstruct gnl;
	char	buf[1];
	char	*temp;
	int		i;
	int		readv;

	gnl.index = 0;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		readv = read (fd, buf, 1);
		if (readv == 0 && gnl.index == 0)
			return 0;
		if ( readv == -1 || readv == 0)
			return (NULL);
		free (gnl.line);
		gnl.line = malloc (sizeof(char)* (gnl.index + 2));
		if (!gnl.line)
			return(NULL);
		if (gnl.index > 0)
		{
			ft_strlcpy(gnl.line, temp, gnl.index+1);
			free(temp);
		}
		gnl.line[gnl.index] = buf[0];
		if (buf[0] == '\n')
		{
			gnl.line[gnl.index +1] = '\0';
			break;
		}
		gnl.index++;
		temp = ft_strdup(gnl.line);
	}
	return (gnl.line);
}
