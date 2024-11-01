# 1843C_SumInBinaryTree
Este repositorio contiene la solución al problema "2843C – Sum In Binary Tree" de Codeforces. El problema consiste en modelar un árbol binario cuyos nodos se forman de manera ascendente. La idea es calcular la suma acumulada hasta un nodo específico. Por ejemplo, si se quiere calcular la suma acumulada en el nodo 6, el resultado sería 1 + 3 + 6 = 10.

La solución se desarrolla en tres aspectos importantes. El primer aspecto es modelar un árbol de tipo min heap, con la diferencia de que dicho árbol no requiere el método de heapify, ya que los números se introducen de manera ordenada. El segundo aspecto consiste en introducir cada nuevo elemento en el primer espacio vacío del árbol, de izquierda a derecha. Para esto, se utiliza la lógica de búsqueda en amplitud (BFS), de manera que cada valor se inserte por niveles, verificando si cada nivel está completo o no. Finalmente, se realiza la suma acumulada de manera recursiva, recorriendo la respectiva rama del árbol.

Video YouTube: https://youtu.be/L46HIY1YT9Q
