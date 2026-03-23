*Este proyecto ha sido creado como parte del currículo de 42 por jacarpio, sbouzian.*

# Push_swap

## Descripción

Push_swap es un proyecto cuyo objetivo consiste en ordenar una lista de enteros utilizando exclusivamente dos stacks (`a` y `b`) y un conjunto limitado de operaciones.

El programa recibe como entrada una secuencia de números enteros en el stack `a`, mientras que el stack `b` comienza vacío. A partir de esa configuración inicial, debe generar una secuencia de operaciones que deje los números ordenados en orden ascendente utilizando el menor número posible de movimientos.

Este proyecto trabaja conceptos fundamentales de:

* Diseño de algoritmos
* Análisis de complejidad
* Optimización bajo restricciones
* Estructuras de datos dinámicas.
* Parsing y validación de entrada
* Gestión de memoria en C

---

## Reglas del proyecto

Se dispone de dos stacks:

* `a`: contiene inicialmente todos los números
* `b`: comienza vacío

### Operaciones permitidas

#### Swap

* `sa`: intercambia los dos primeros elementos de `a`
* `sb`: intercambia los dos primeros elementos de `b`
* `ss`: ejecuta `sa` y `sb`

#### Push

* `pa`: mueve el primer elemento de `b` a `a`
* `pb`: mueve el primer elemento de `a` a `b`

#### Rotate

* `ra`: desplaza hacia arriba los elementos de `a`
* `rb`: desplaza hacia arriba los elementos de `b`
* `rr`: ejecuta `ra` y `rb`

#### Reverse rotate

* `rra`: desplaza hacia abajo los elementos de `a`
* `rrb`: desplaza hacia abajo los elementos de `b`
* `rrr`: ejecuta `rra` y `rrb`

---

## Instrucciones

### Compilación

```bash id="1sivdi"
make
```

### Ejecución

```bash id="dy9j9n"
./push_swap 4 2 7 1 3
```

### Selección de estrategia

```bash id="kzq23d"
./push_swap --simple 4 2 7 1 3
./push_swap --medium 4 2 7 1 3
./push_swap --complex 4 2 7 1 3
./push_swap --adaptive 4 2 7 1 3
```

### Flags disponibles (opcional)

* `--simple` → fuerza algoritmo O(n²)
* `--medium` → fuerza algoritmo O(n√n)
* `--complex` → fuerza algoritmo O(n log n)
* `--adaptive` → selección automática (por defecto)
* `--bench` → si se activa, el programa muestra por `stderr`:

    * Índice de desorden
    * Estrategia utilizada
    * Complejidad teórica
    * Número total de operaciones
    * Conteo por tipo de instrucción

---

## Índice de desorden

Antes de ordenar, el programa calcula un índice de desorden entre `0` y `1`.

Este valor representa cuántos pares están fuera de orden respecto al total posible.

### Fórmula conceptual

Si existen muchos pares `(a[i] > a[j])` con `i < j`, el índice aumenta.

* `0` → stack ya ordenado
* `1` → máximo desorden posible

### Objetivo

Este índice permite decidir automáticamente qué estrategia usar en modo adaptativo.

---

# Estrategias implementadas

## 1. Algoritmo simple — O(n²)

Se utiliza una variante de **bubble sort adaptado a stacks**.

### Método real implementado

* Se compara el primer nodo con el siguiente.
* Si el índice del primer nodo es mayor, se ejecuta `sa`.
* Después se hace `ra` para avanzar por el stack.
* Al terminar cada pasada, se restaura la posición original con `rra`.
* Si en una pasada no hay swaps, el algoritmo termina antes.

### Función utilizada

`ft_bubble_sort()`

### Justificación

Este método es simple y eficiente para tamaños pequeños o entradas con poco desorden.

### Complejidad

* Tiempo: O(n²)
* Espacio: O(1)

---

## 2. Algoritmo intermedio — O(n√n)

Se utiliza una estrategia de **chunk sorting basada en índices normalizados**.

### Método real implementado

* Se calcula el tamaño del chunk como `sqrt(n)`.
* Se empujan a `b` los elementos cuyo índice está dentro del rango actual.
* Si el índice es menor o igual al valor actual `i`, después de `pb` se ejecuta `rb`.
* Si el índice entra en el chunk actual, solo se hace `pb`.
* Si no pertenece al chunk, se rota `a` con `ra`.
* Una vez vacío `a`, se reconstruye el stack:

  * se localiza el índice máximo en `b`
  * se rota `b` con `rb` o `rrb`
  * se devuelve a `a` con `pa`

### Funciones utilizadas

`ft_chunk_sort()`
`ft_push_back()`
`ft_find_max_pos()`

### Justificación

Reduce el número de movimientos respecto al algoritmo simple y mejora el rendimiento en tamaños medios.

### Complejidad

* Tiempo: O(n√n)
* Espacio: O(n)

---

## 3. Algoritmo complejo — O(n log n)

Se utiliza **radix sort binario sobre índices normalizados**.

### Método real implementado

Antes de comenzar, cada número del stack se sustituye por su índice dentro del conjunto ordenado.

Esto permite trabajar con valores consecutivos desde `0` hasta `n - 1`, simplificando el tratamiento binario.

### Funcionamiento

Primero se calcula cuántos bits son necesarios para representar el índice máximo.

Ejemplo:

```text id="0h4u2j"
8 elementos → índice máximo = 7 → binario = 111 → 3 bits
```

Después se procesa cada bit desde el menos significativo hasta el más alto.

Para cada bit:

* Se recorre todo el stack `a`.
* Se analiza el bit actual del índice del elemento superior.
* Si el bit es `1`:

  * el elemento permanece en `a` mediante `ra`
* Si el bit es `0`:

  * el elemento se envía a `b` mediante `pb`

De este modo:

* los elementos con bit `1` se mantienen rotando en `a`
* los elementos con bit `0` se separan temporalmente en `b`

Al terminar cada pasada completa:

* todos los elementos de `b` regresan a `a` usando `pa`

### Resultado

Cada pasada ordena progresivamente según un bit adicional.

Tras procesar todos los bits necesarios, el stack queda completamente ordenado.

### Funciones utilizadas

`ft_radix_sort()`
`ft_get_max_bits()`

### Justificación

Este algoritmo garantiza un comportamiento estable y muy eficiente en entradas grandes, manteniendo un número de operaciones competitivo en push_swap.

### Complejidad

* Tiempo: O(n log n)
* Espacio: O(n)

---

## 4. Algoritmo adaptativo

La estrategia adaptativa selecciona automáticamente el algoritmo según el tamaño del stack y el nivel de desorden inicial.

### Método real implementado

Primero se comprueba el tamaño del stack:

* Si el tamaño es menor o igual a `7`, se utiliza `ft_smallsort()`.
* Si el tamaño es mayor, se calcula `ft_disorder()` y se selecciona:

  * `disorder < 0.2` → bubble sort
  * `disorder < 0.5` → chunk sort
  * `disorder >= 0.5` → radix sort

### Gestión de tamaños pequeños

Para entradas pequeñas se aplica una estrategia específica de mínimo coste:

* `2 elementos` → un único `sa` si están invertidos.
* `3 elementos` → combinación óptima de `sa`, `ra` y `rra`.
* `4 a 7 elementos`:

  * se localiza el mínimo
  * se rota hasta llevarlo arriba
  * se empuja a `b` con `pb`
  * se repite hasta dejar `3 elementos`
  * se ordenan esos `3`
  * se reconstruye con `pa`

### Funciones utilizadas

`ft_adaptive_sort()`
`ft_smallsort()`
`ft_sort_two()`
`ft_sort_three()`
`get_min_pos()`

### Justificación

Esta fase evita aplicar algoritmos generales en tamaños pequeños, donde una estrategia dedicada produce menos movimientos.

### Complejidad

* Tamaños pequeños → coste optimizado en muy pocos movimientos
* Bajo desorden → O(n²)
* Desorden medio → O(n√n)
* Alto desorden → O(n log n)

---

## Rendimiento esperado

### 100 números

* < 2000 operaciones - requisito mínimo
* < 1500 operaciones - buen rendimiento
* < 700 operaciones - rendimiento excelente

### 500 números

* < 12000 operaciones - requisito mínimo
* < 8000 operaciones - buen rendimiento
* < 5500 operaciones - rendimiento excelente

---

## Recursos

### Referencias técnicas

* Subject oficial de push_swap.
* Manual pages de C.
* Documentación de stacks y linked lists.
* Teoría de bubble sort, chunk sort y radix sort.
* Análisis de complejidad algorítmica.

### Referencias de librerías autorizadas

* libft.
* ft_printf.

### Uso de IA

La IA se ha utilizado como herramienta de apoyo durante el desarrollo del proyecto en tareas como:

* Refactorización de funciones para mejorar claridad y legibilidad.
* Revisión de estructura y organización del código.
* Apoyo conceptual para entender algoritmos y su adaptación al proyecto.
* Explicaciones técnicas sobre comportamiento de stacks, índices y complejidad.
* Ayuda para interpretar errores, validar enfoques y comparar soluciones.
* Guía puntual en documentación y redacción del README.

---

## Objetivo final

Obtener la menor secuencia posible de operaciones respetando completamente el modelo de push_swap.