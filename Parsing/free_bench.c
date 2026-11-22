#include "push_swap.h"

void    free_bench(t_bench *bench)
{
    if (!bench)
        return ;
    free_stack(&bench->simple_a);
    free_stack(&bench->simple_b);
    free_stack(&bench->medium_a);
    free_stack(&bench->medium_b);
    free_stack(&bench->complex_a);
    free_stack(&bench->complex_b);
}
