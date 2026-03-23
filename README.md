*Este proyecto ha sido creado como parte del currículo de 42 por sbouzian, jacarpio.*

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

### Flags disponibles

* `--simple` → fuerza algoritmo O(n²)
* `--medium` → fuerza algoritmo O(n√n)
* `--complex` → fuerza algoritmo O(n log n)
* `--adaptive` → selección automática (por defecto)

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

## Estrategias implementadas

## 1. Algoritmo simple — O(n²)

Se utiliza una estrategia de extracción progresiva del mínimo.

### Método

* Localizar el menor valor
* Rotarlo hasta el top
* Hacer `pb`
* Repetir hasta vaciar parcialmente `a`
* Devolver con `pa`

### Justificación

Es simple, estable y eficiente para tamaños pequeños.

### Complejidad

* Tiempo: O(n²)
* Espacio: O(1)

---

## 2. Algoritmo intermedio — O(n√n)

Se utiliza división en bloques (chunks).

### Método

* Indexar valores
* Dividir en √n bloques
* Empujar a `b` por rangos
* Reconstruir desde máximos

### Justificación

Reduce rotaciones y mantiene coste medio muy competitivo.

### Complejidad

* Tiempo: O(n√n)
* Espacio: O(n)

---

## 3. Algoritmo complejo — O(n log n)

Se utiliza radix sort sobre índices normalizados.

### Método

* Convertir cada número en índice
* Recorrer bits desde menos significativo
* Distribuir entre `a` y `b`

### Justificación

Garantiza rendimiento estable para entradas grandes.

### Complejidad

* tiempo: O(n log n)
* espacio: O(n)

---

## 4. Algoritmo adaptativo

La estrategia adaptativa selecciona automáticamente según el índice de desorden.

### Umbrales definidos

* Desorden < 0.20 → algoritmo lineal optimizado
* 0.20 ≤ desorden < 0.50 → chunks
* Desorden ≥ 0.50 → radix

### Justificación de umbrales

Estos límites separan claramente:

* Secuencias casi ordenadas
* Secuencias parcialmente mezcladas
* Secuencias aleatorias o muy invertidas

Se eligieron tras comparar número medio de operaciones.

### Complejidad

* Bajo desorden → O(n)
* Desorden medio → O(n√n)
* Alto desorden → O(n log n)

---

## Rendimiento esperado

### 100 números

* < 2000 operaciones mínimo
* < 1500 buen rendimiento
* < 700 excelente

### 500 números

* < 12000 operaciones mínimo
* < 8000 buen rendimiento
* < 5500 excelente

---

## Benchmark (opcional)

Si se activa `--bench`, el programa muestra por `stderr`:

* Índice de desorden
* Estrategia utilizada
* Complejidad teórica
* Número total de operaciones
* Conteo por tipo de instrucción

---

## Recursos

### Referencias técnicas

* Subject oficial de push_swap
* Manual pages de C
* Documentación de stacks y linked lists
* Teoría de radix sort
* Análisis de complejidad algorítmica

### Uso de IA

La IA se ha utilizado exclusivamente para:

* Estructuración del README
* Mejora de redacción técnica
* Revisión conceptual de explicaciones

---

## Objetivo final

Obtener la menor secuencia posible de operaciones respetando completamente el modelo de Push_swap.
