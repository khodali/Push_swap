#include "push_swap.h"

long	count_inversions(int *arr, int *tmp, long left, long right)
{
	long	mid;
	long	count;
	t_merge	merge;

	if (left >= right)
		return (0);
	mid = left + (right - left) / 2;
	count = count_inversions(arr, tmp, left, mid);
	count += count_inversions(arr, tmp, mid + 1, right);
	merge = (t_merge){left, mid, right, left};
	count += merge_count(arr, tmp, merge);
	return (count);
}
