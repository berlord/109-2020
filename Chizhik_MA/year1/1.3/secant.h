typedef double (*dFUNC)(double x);
typedef enum {
        OK_ROOT,
        NO_ROOTS,
        SAME_SIGN_AT_THE_ENDPOINTS
} RootStatus;

/* 
 * Нахождение корня уравнения fn(x) = 0 на заданном отрезке методом секущих
 *
 * Параметры:
 * fn: вещественнозначная функция от одной переменной, для которой ищется корень 
 * a: левый конец отрезка
 * b: правый конец отрезка
 * precision: точность вычислений
 * s: указатель на переменную, в которую записывается информация об успешности выполнения функции
 *
 * Функция находит корень уравнения fn(x) = 0 на заданном отрезке [a, b] 
 * c точностью до precision. 
 *
 * Метод:
 * Корень на отрезке находится методом секущих. Предполагается, что fn - непрерывная функция, 
 * принимающая на концах заданного отрезка значения разных знаков (или равняющаяся нулю 
 * хотя бы на одном из концов отрезка). Если на концах отрезка принимаются отличные от нуля значения
 * одного и того же знака, поиск корня производиться не будет.
 *
 * Возвращаемое значение:
 * В случае успешного нахождения корня возвращается x, для которого fn(x) = 0 (с точностью до precision).
 * В том случае, если корень не может быть найден, возвращается произвольное значение за границами отрезка, 
 * а в s записывается соответствующая информация.
 *
 */

double find_root(dFUNC fn, double a, double b, double precision, RootStatus *s);