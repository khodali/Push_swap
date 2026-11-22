#include "push_swap.h"

void    print_simple_bench(t_operations *stats)
{
    printf("SIMPLE: %d operations\n", stats->total_op);
}

void    print_medium_bench(t_operations *stats)
{
    printf("MEDIUM: %d operations\n", stats->total_op);
}

void    print_complex_bench(t_operations *stats)
{
    printf("COMPLEX: %d operations\n", stats->total_op);
}

void    print_bench(t_bench *bench)
{
    print_simple_bench(&bench->simple_stats);
    print_medium_bench(&bench->medium_stats);
    print_complex_bench(&bench->complex_stats);
}