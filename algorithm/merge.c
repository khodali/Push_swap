#include "push_swap.h"

void	copy_back(int *arr, int *tmp, t_merge m)
{
	long i;

	i = m.left;
	while (i <= m.right)
	{
		arr[i] = tmp[i];
		i++;
	}
}

long	merge_count(int *arr, int *tmp, t_merge m)
{
	long i;
	long j;
	long k;
	long count;

	i = m.left;
	j = m.mid + 1;
	k = m.left;
	count = 0;
	while (i <= m.mid && j <= m.right)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
		{
			tmp[k++] = arr[j++];
			count += m.mid - i + 1;
		}
	}
	while (i <= m.mid)
		tmp[k++] = arr[i++];
	while (j <= m.right)
		tmp[k++] = arr[j++];
	copy_back(arr, tmp, m);
	return (count);
}
