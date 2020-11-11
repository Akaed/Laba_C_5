#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

/*Написать функцию, которая читает массив из файла, сортирует его указанным методом, записывает отсортированный массив в новый файл.1. Сортировка пузырьком. 2. Сортировка слиянием.*/
#define N 10
void merge(int *a, int n);
void func(int *a, int size);

///////////////////////////
int main() {

    int arr1[N];

    srand(time(NULL));
    int len = sizeof(arr1)/ sizeof(int); // длина массива
    int i;

        // заполняем массив
    for(i=0; i< len; i++) arr1[i]=1+rand()%9;

    printf("\n print array1\n");

    for(int i=0; i< len; i++) printf("arr1[%i]= %i\t",i,arr1[i] );

    FILE *file =fopen("C:\ish\laba_c\file1.txt", "w+");



    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }


    for(int i=0; i< len; i++) {
    fprintf(file, "%i", arr1[i]);

    }

    close(file);
    func(arr1, len);
    merge(arr1,len);
    // открываем файл для чтения и записи


    return 0;
}
////////
void func(int *a, int size) {
    FILE *file1 = open("C:\ish\laba_c\file1.txt", "w+");
    if(file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    rewind (file1);
    printf("\n write array2\n");

    for(int i=0; i<size; i++) {
        fscanf(file1, "%i", &a[i]);

    }
    //////////
    int i, j;
    int tmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (a[j] > a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }

    FILE *file2 = open("C:\ish\laba_c\file1.txt", "w+");
    // выводим массив в файл
    for(int i=0; i< size; i++) {
        fprintf(file1, "%i", a[i]);
    }

    close(file1);
    close(file2);



}

void merge(int *a, int n)
{
      FILE *file1 = open("C:\ish\laba_c\file1.txt", "w+");
    if(file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    rewind (file1);
    printf("\n write array2\n");

    for(int i=0; i<size; i++) {
        fscanf(file1, "%i", &a[i]);

    }
  int mid = n / 2; // находим середину сортируемой последовательности
  if (n % 2 == 1)
    mid++;
  int h = 1; // øàã
  // выделяем память под формируемую последовательность
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;   // индекс первого пути
    int j = mid; // индекс второго пути
    int k = 0;   // индекс элемента в результирующей последовательности
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      { // пока не дошли до конца пути
      // заполняем следующий элемент формируемой последовательности
         // меньшим из двух просматриваемых
        if (a[i] < a[j])
        {
          c[k] = a[i];
          i++; k++;
        }
        else {
          c[k] = a[j];
          j++; k++;
        }
      }
      while (i < step)
      { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n))
      { // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
        c[k] = a[j];
        j++; k++;
      }
      step = step + h; // переходим к следующему этапу
    }
    h = h * 2;
    // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
      FILE *file2 = open("C:\ish\laba_c\file1.txt", "w+");
  // выводим массив в файл
    for(int i=0; i< size; i++) {
        fprintf(file1, "%i", a[i]);
    }

    close(file1);
    close(file2);
    ////c5laba
}
