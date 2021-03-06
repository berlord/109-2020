// Определить ранг вещественной N × M матрицы.
#include<stdio.h>
#include<math.h>

#include"1.h"
#define CHECK_NOT_NULL 1
#define CHECK_NULL 0
#define EPS 0.0001

	void str_diff(int i, int j, int m , int n,  double *matrix){
		//подаем i,j элемент с которого строки надо вычитать с подх коэф
		int i0 = 0;
		int j0 = 0;
		double k = 1;
		// если строка не последняя
			for(i0 = n - 1 ; i0 > i; i0--) { // меняем строку и идем с конца вверх
				k = matrix[i0 * m + j] / matrix[i * m + j]; // коэф для убийства нужного элемента строки
	//			printf("k (%lf) = %lf / %lf\n",k , matrix[i0 * m + j], matrix[i * m + j]);
				for(j0 = 0; j0 < m; j0++){ //меняем столбец
					matrix[i0 * m + j0] -= k * matrix[i * m + j0]; //вычитаем
				}
			}
	}
	
	void print_matrix(int n, int m, double *matrix){
    printf("\nтеперь матрица\n");
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%lf\t", matrix[i * m + j]);
        }
    printf("\n");
    }
}
	void str_change(int i, int j, int place, int m, double *matrix) {
	//i j это крайний элемент лесенки который надо поставить на место place,place  
		// t = a a = b b = t
		int j0;
		double tmp;
		for(j0 = j; j0 < m; j0++) { 
			tmp = matrix[i * m + j0];
			matrix[i * m + j0] = matrix[place * m + j0];
			matrix[place * m + j0] = tmp;
		}
	}

	void gauss_down(int n, int m, double *matrix) { // ступенчатый вид
		int i = 0;
		int without_repeat = 0;
		int c = 0; // счетчик угловых клеток
	    int j;	
		//находим первый ненулевой столбец i - номер строчки j - номер столбца
		for(j = 0; j < m; j++){ // фиксируем столбец 
			for(i = without_repeat; i < n; i++){ // смотрим на разные строчки
				if ( fabs(matrix[i * m + j]) > EPS ) { 
				//нашли первый ненулевой элемент в столбце
		// теперь вычитаем остальные строки из той которую нашли с нужным коэф
//					printf("\ni =%d j = %d\n", i, j);
					str_change(i, j, c, m, matrix); // ставим строку на нужное место
					str_diff(c, c, m, n, matrix); //вычитаем остальные строки с подходящим коэффициентом
					print_matrix(n, m, matrix);
					without_repeat = c + 1; // до c строки ступеньки сделаны
					break;
				}
			}
			c++;
		}

		print_matrix(n, m, matrix);	
	}
	
	int check_null(int i, int n, int m, double *matrix){
		int i0 = i;
		int check = 0;
		for(int j = 0; j < m; j++){
//			printf("\nmatrix[%d*%d+%d] = %lf\n", i0, m, j, matrix[i0 * m + j]);
			if(fabs(matrix[i0 * m + j]) > EPS) {
				check = 1;
//			printf("find not null i %d j %d",i0,j);
				break;
			}
		}
		if(check > 0) return CHECK_NOT_NULL;
		else return CHECK_NULL;		
	}

	int rk(int n, int m, double *matrix) {
		int res = 0;
		gauss_down(n, m, matrix) ; // ступенчатый вид
			for(int i = 0; i < n ; i++){ // проходимся по строкам
				res += check_null(i, n, m,matrix);
//				printf("\nres += %d\n",check_null(i,n,m,matrix));
			}
//		int i = 0;
//		int counter = 0; 		
//		while( check_null(i, n, m, matrix) == 1) {
//			counter++;
//			i++;
//		}			
		return res;
	}



/*	void algorithm(int n, int m, double *matrix) { // ступенчатый вид
	
		int i = 0;
		int without_repeat = 0;
	    int j;	
		//находим первый ненулевой столбец i - номер строчки j - номер столбца
		for(j = 0; j < m; j++){ // фиксируем столбец
			for(i = without_repeat; i < n; i++){ // смотрим на разные строчки
			// мы идем по каждому из столбцов вниз и смотрим на элементы
				if ( fabs(matrix[i * m + j]) > EPS) { 
			//нашли первый ненулевой элемент в столбце (i-ая строка) 
			// теперь вычитаем остальные строки из той которую нашли с нужным коэф
					printf("\ni =%d j = %d\n", i, j);
					str_diff(i, j, m, n, matrix);
					print_matrix(n, m, matrix);
		//когда мы обнулили остальные строчки в котогрых элемент в j столбце
		//не нулевой, то мы должны перейти на следующую строку
		//чтобы у нас получился при выравнивании вид лесенки
		//так как я нахожу ранг выравнивать мне не нужно, достаточно
		//только понять сколько нулевых строк
					without_repeat = i + 1; 			
					break;
				}
			}
		}
	}
*/	





