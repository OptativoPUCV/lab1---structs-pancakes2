#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}


int findMax(int arr[], int size) {
  int elemMayor = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > elemMayor) {
      elemMayor = arr[i];
    }
  }
  return elemMayor;
}

// Itera el arreglo hasta encontrar el elemento mayor

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int *arregloInverso = (int *)malloc(size * sizeof(int));
  int indice = size - 1;
  for (int i = 0; i < size; i++) {
    // Itera el arreglo desde el indice final del arreglo input
    arregloInverso[i] = arr[indice];
    indice--;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = arregloInverso[i];
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int *arregloPares = (int *)malloc(size * sizeof(int));
  int indice = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      arregloPares[indice] = arr[i];
      indice++;
    }
  }
  *newSize = indice;
  return arregloPares;
}


/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
  for (int i = 0; i < size1+size2; i++) {
    if (i < size1) {
      result[i] = arr1[i];
    } else {
      result[i] = arr2[i-size1];
    }
  }
  qsort(result, size1+size2, sizeof(int), compare);

}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascendente = 1;
  int decreciente = 1;

  for (int i = 0; i < size-1; i++) {
    // Checkeamos si el arreglo está ordenado de forma ascendente
    if (arr[i] < arr[i+1]) {
      ascendente++;
    // Checkeamos si es decreciente..
    } else if (arr[i] > arr[i+1]) {
      decreciente++;
    } else if (arr[i] == arr[i+1]) {
      decreciente++;
      ascendente++;
    }
  }
  // Lógica para determinar si es ascendente, descendiente o no ordenado
  // Si cada número cumple con la condición de ser igual al tamaño, entonces cada número está ordenado
  // Si no cumple con ninguna entonces este no estaría ordenado
  printf("ascendente: %d, decreciente: %d\n", ascendente, decreciente);
  if (ascendente == size) {
    return 1;
  } else if (decreciente == size) {
    return -1;
  } else {
    return 0;
  }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
  // Inicializo el libro con la estructura 'libro' y con sus atributos equivaliendo a los parametros de la función
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
  // Imprimo el libro accediendo a los atributos de 'libro'
  printf("%s\n", libro->titulo);
  printf("%s\n", libro->autor.nombre);
  printf("%d\n", libro->autor.anioNacimiento);
  printf("%d\n", libro->anioPublicacion);
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
    return NULL;
}
