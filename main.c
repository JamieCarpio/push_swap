/*#include "push_swap.h"

typedef enum e_strategy
{
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX,
	S_ADAPTIVE
}	t_strategy;

int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_strategy strategy = S_ADAPTIVE;
	//int		bench_mode = 0;
	int		arg_start = 1;

	if (argc < 2)
		return (0);

	// --- Parse flags ---
	while (arg_start < argc && argv[arg_start][0] == '-')
	{
		if (ft_strcmp(argv[arg_start], "--simple") == 0)
			strategy = S_SIMPLE;
		else if (ft_strcmp(argv[arg_start], "--medium") == 0)
			strategy = S_MEDIUM;
		else if (ft_strcmp(argv[arg_start], "--complex") == 0)
			strategy = S_COMPLEX;
		else if (ft_strcmp(argv[arg_start], "--adaptive") == 0)
			strategy = S_ADAPTIVE;
		//else if (ft_strcmp(argv[arg_start], "--bench") == 0)
		//	bench_mode = 1;
		else
		{
			write(2, "Error\n", 6);
			return (1);
		}
		arg_start++;
	}

	// --- Verificar que haya números ---
	if (arg_start >= argc)
		return (0);

	// --- Verificar inputs ---
	ft_check_input(argc - arg_start, argv + arg_start);

	// --- Inicializar stack ---
	a = ft_init_stack(argc - arg_start, argv + arg_start);
	ft_index_stack(a);

	if (ft_is_sorted(a))
	{
		ft_free_stack(&a);
		return (0);
	}

	// --- Ejecutar estrategia ---
	if (strategy == S_SIMPLE)
		ft_bubble_sort(&a);
	else if (strategy == S_MEDIUM)
		ft_chunk_sort(&a, &b);
	else if (strategy == S_COMPLEX)
		ft_radix_sort(&a, &b);
	else // S_ADAPTIVE
		ft_adaptive_sort(&a, &b);

	// --- Modo bench ---
	if (bench_mode)
		ft_print_benchmark(&a, strategy);

	ft_free_stack(&a);
	return (0);
}
*/

#include "push_swap.h"
#include <stdio.h>

/* =================== DEBUG / BENCH HELPERS =================== */

static void print_stack(t_stack *stack, const char *title)
{
    printf("=== %s ===\n", title);
    while (stack)
    {
        printf("value: %d | index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("\n");
}

static void print_strategy(const char *strategy_name, const char *complexity, double disorder, int size)
{
    fprintf(stderr, "Disorder: %.3f\n", disorder);
    fprintf(stderr, "Size: %d\n", size);
    fprintf(stderr, "Strategy: %s (%s)\n", strategy_name, complexity);
    fprintf(stderr, "\n");
}

/* =================== MAIN DEBUG =================== */

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    double disorder;
    int size;
    char *strategy_flag = NULL;
    int arg_start = 1;

    if (argc < 2)
        return 0;

    /* --- DETECT FLAG --- */
    if (argv[1][0] == '-' && argv[1][1] == '-')
    {
        strategy_flag = argv[1];
        arg_start = 2;
    }

    /* --- CHECK INPUT --- */
    ft_check_input(argc - arg_start, argv + arg_start);

    /* --- INIT STACK --- */
    a = ft_init_stack(argc - arg_start, argv + arg_start);
    b = NULL;

    /* --- INDEX STACK --- */
    ft_index_stack(a);

    print_stack(a, "INITIAL STACK");

    if (ft_is_sorted(a))
    {
        fprintf(stderr, "Already sorted\n");
        ft_free_stack(&a);
        return 0;
    }

    /* --- COMPUTE DISORDER --- */
    disorder = ft_disorder(a);
    size = ft_stack_size(a);

    /* --- SELECT STRATEGY --- */
    const char *strategy_name = NULL;
    const char *complexity = NULL;

    if (strategy_flag)
    {
        if (ft_strcmp(strategy_flag, "--simple") == 0)
        {
            strategy_name = "SIMPLE";
            complexity = "O(n^2)";
            ft_bubble_sort(&a);
        }
        else if (ft_strcmp(strategy_flag, "--medium") == 0)
        {
            strategy_name = "CHUNK";
            complexity = "O(n√n)";
            ft_chunk_sort(&a, &b);
        }
        else if (ft_strcmp(strategy_flag, "--complex") == 0)
        {
            strategy_name = "RADIX";
            complexity = "O(n log n)";
            ft_radix_sort(&a, &b);
        }
        else if (ft_strcmp(strategy_flag, "--adaptive") == 0)
        {
            strategy_name = "ADAPTIVE";
            complexity = "variable";
            ft_adaptive_sort(&a, &b);
        }
        else
        {
            ft_error(); // flag inválida
        }
    }
    else
    {
        // default adaptive
        strategy_name = "ADAPTIVE";
        complexity = "variable";
        ft_adaptive_sort(&a, &b);
    }

    print_strategy(strategy_name, complexity, disorder, size);

    print_stack(a, "FINAL STACK");

    if (ft_is_sorted(a))
        fprintf(stderr, "✅ SORTED OK\n");
    else
        fprintf(stderr, "❌ NOT SORTED\n");

    ft_free_stack(&a);
    return 0;
}