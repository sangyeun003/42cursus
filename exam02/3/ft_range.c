#include	<stdio.h>
#include	<stdlib.h>

int	*ft_range(int start, int end)
{
	int	*result;
	int	len;
	int	i;

	len = end - start + 1;
	result = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		result[i++] = start++;
	}
	return (result);
}

int	main(void)
{
	for (int i = 0; i < 4; i++)
		printf("%d ", ft_range(3, 5)[i]);
}