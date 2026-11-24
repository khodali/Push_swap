#include "push_swap.h"

t_operations    *get_adaptive_stats(t_bench *bench, float disorder_value, const char **strategy)
{
    if (disorder_value < 0.2f)
    {
        *strategy = "Adaptive / O(n²)";
        return (&bench->simple_stats);
    }
    if (disorder_value < 0.5f)
    {
        *strategy = "Adaptive / O(n√n)";
        return (&bench->medium_stats);
    }
    *strategy = "Adaptive / O(n log n)";
    return (&bench->complex_stats);
}