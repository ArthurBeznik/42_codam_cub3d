#include <utils.h>

char	**copy_map(char **map, int rows)
{
	int		i;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (rows + 1));
	// copy = NULL; // ? testing
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		// copy[i] = NULL; // ? testing
		if (!copy[i])
		{
			free_2d(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
