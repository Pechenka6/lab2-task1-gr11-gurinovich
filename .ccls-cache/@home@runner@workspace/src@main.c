#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  
#include <math.h>

bool is_power_of_five(int number) {
		if (number <= 0) {
				return false; 
		}

		while (number % 5 == 0) {
				number /= 5;
		}

		return number == 1;
}


int* generate_random_array(int size, int max_value) {
		int* array = malloc(size * sizeof(int));
		if (array == NULL) {
				fprintf(stderr, "Ошибка выделения памяти\n");
				exit(1);
		}

		srand(time(NULL)); 

		for (int i = 0; i < size; i++) {
				array[i] = 1 + rand() % max_value;
		}

		return array;
}

void print_powers_of_five(int* array, int size) {
		printf("Числа, являющиеся степенями пятерки:\n");
		bool found = false;

		for (int i = 0; i < size; i++) {
				if (is_power_of_five(array[i])) {
						printf("%d (5^%d)\n", array[i], 
									(int)(log(array[i]) / log(5) + 0.5));
						found = true;
				}
		}

		if (!found) {
				printf("В массиве нет степеней пятерки.\n");
		}
}

int main(int argc, char* argv[]) {
		if (argc != 3) {
				printf("Использование: %s <размер массива> <максимальное значение>\n", argv[0]);
				return 1;
		}

		int size = atoi(argv[1]);
		int max_value = atoi(argv[2]);

		if (size <= 0 || max_value <= 0) {
				printf("Ошибка: аргументы должны быть положительными числами\n");
				return 1;
		}

		int* numbers = generate_random_array(size, max_value);

		printf("Сгенерированный массив:\n");
		for (int i = 0; i < size; i++) {
				printf("%d ", numbers[i]);
		}
		printf("\n\n");

		print_powers_of_five(numbers, size);

		free(numbers);

		return 0;
}