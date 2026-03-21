#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_stack(const char *name, t_stack *stack)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d(index:%d) -> ", stack->value, stack->index);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int bench_mode = 0;
    const char *strategy_flag = "--adaptive";

    printf("DEBUG: argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = '%s'\n", i, argv[i]);

    if (argc < 2)
    {
        printf("DEBUG: No arguments, exiting\n");
        return 0;
    }

    // Detectar flags
    int num_count = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--simple") == 0)
            strategy_flag = "--simple";
        else if (strcmp(argv[i], "--medium") == 0)
            strategy_flag = "--medium";
        else if (strcmp(argv[i], "--complex") == 0)
            strategy_flag = "--complex";
        else if (strcmp(argv[i], "--adaptive") == 0)
            strategy_flag = "--adaptive";
        else if (strcmp(argv[i], "--bench") == 0)
            bench_mode = 1;
        else
            num_count++;
    }

    printf("DEBUG: Strategy: %s\n", strategy_flag);
    printf("DEBUG: Bench mode: %d\n", bench_mode);
    printf("DEBUG: Number of inputs: %d\n", num_count);

    // Crear array de números
   char **numbers = malloc(sizeof(char *) * (num_count + 1)); // +1 para NULL
if (!numbers)
    ft_error();

int idx = 0;
for (int i = 1; i < argc; i++)
{
    if (ft_is_number(argv[i]))
    {
        numbers[idx++] = argv[i];
        printf("DEBUG: numbers[%d] = '%s'\n", idx-1, argv[i]);
    }
}
numbers[idx] = NULL; 

    // Validar inputs
    printf("DEBUG: Validating inputs...\n");
    ft_check_input(num_count, numbers);
    printf("DEBUG: Input validation passed\n");

    // Inicializar stack
    stack_a = ft_init_stack(num_count, numbers);
    printf("DEBUG: Stack A initialized\n");
    print_stack("Stack A", stack_a);

    ft_index_stack(stack_a);
    printf("DEBUG: Stack A indexed\n");
    print_stack("Stack A", stack_a);

    // Revisar si ya está ordenado
    if (ft_is_sorted(stack_a))
    {
        printf("DEBUG: Stack already sorted\n");
        ft_free_stack(&stack_a);
        free(numbers);
        return 0;
    }

    double disorder = ft_disorder(stack_a);

    t_bench bench = {0};
    // Ejecutar estrategia
    printf("DEBUG: Executing strategy '%s'\n", strategy_flag);
    if (strcmp(strategy_flag, "--simple") == 0)
    ft_bubble_sort(&stack_a, &bench);
    else if (strcmp(strategy_flag, "--medium") == 0)
    ft_chunk_sort(&stack_a, &stack_b, &bench);
    else if (strcmp(strategy_flag, "--complex") == 0)
    ft_radix_sort(&stack_a, &stack_b, &bench);
    else
    ft_adaptive_sort(&stack_a, &stack_b, &bench);

    printf("DEBUG: Strategy execution finished\n");
    print_stack("Stack A final", stack_a);
    print_stack("Stack B final", stack_b);

    // 🔥 AQUI VA EL BENCHMARK
    if (bench_mode)
    ft_print_benchmark(stack_a, &bench, disorder, strategy_flag);

    // Liberar memoria
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    free(numbers);

    printf("DEBUG: Memory freed, program finished\n");

    return 0;
}