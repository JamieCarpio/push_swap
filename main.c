/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:20 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:54:59 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char    **numbers;
    int     bench_mode;
    int     num_count;
    int     i;
    int     idx;
    const char *strategy_flag;
    double  disorder;
    t_bench bench;

    if (argc < 2)
        return (0);

    stack_a = NULL;
    stack_b = NULL;
    bench_mode = 0;
    strategy_flag = "--adaptive";

    // Contar números y detectar flags
    num_count = 0;
    i = 1;
    while (i < argc)
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
        i++;
    }

    // Reservar array de números
    numbers = malloc(sizeof(char *) * (num_count + 1));
    if (!numbers)
        return (1);

    // Guardar solo números
    i = 1;
    idx = 0;
    while (i < argc)
    {
        if (ft_is_number(argv[i]))
            numbers[idx++] = argv[i];
        i++;
    }
    numbers[idx] = NULL;

    // Validación
    ft_check_input(num_count, numbers);

    // Inicializar stack
    stack_a = ft_init_stack(num_count, numbers);

    // Indexado
    ft_index_stack(stack_a);

    // Si ya está ordenado → salir
    if (ft_is_sorted(stack_a))
    {
        ft_free_stack(&stack_a);
        free(numbers);
        return (0);
    }

    // Calcular disorder ANTES de ordenar
    disorder = ft_disorder(stack_a);

    // Inicializar benchmark
    bench = (t_bench){0};

    // Ejecutar estrategia
    if (strcmp(strategy_flag, "--simple") == 0)
        ft_bubble_sort(&stack_a, &bench);
    else if (strcmp(strategy_flag, "--medium") == 0)
        ft_chunk_sort(&stack_a, &stack_b, &bench);
    else if (strcmp(strategy_flag, "--complex") == 0)
        ft_radix_sort(&stack_a, &stack_b, &bench);
    else
        ft_adaptive_sort(&stack_a, &stack_b, &bench);

    // Mostrar benchmark si aplica
    if (bench_mode)
        ft_print_benchmark(stack_a, &bench, disorder, strategy_flag);

    // Liberar memoria
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    free(numbers);

    return (0);
}