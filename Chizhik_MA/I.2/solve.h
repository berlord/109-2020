typedef double (*dFUNC)(double x);
typedef enum {
	OK_ROOT,
	NO_ROOTS,
	SAME_SIGN_AT_THE_ENDPOINTS
} RootStatus;

/* 
 * Монотонная вещественнозначная непрерывная функция, для которой ищутся определенные интегралы
 */

double f(double t);

/* 
 * Заменив f на f_imp, можно вместо рассмотрения всей числовой прямой
 * ограничиться рассмотрением отрезка [-PI/2, PI/2] (преобразования описаны в integral.pdf)
 *
 */

double f_imp(double z);

/* 
 * Нахождение корня уравнения f_imp(x) = constant на заданном отрезке методом секущих
 *
 * Параметры:
 * constant: константа, которой должна равняться функция f_imp
 * a: левый конец отрезка
 * b: правый конец отрезка
 * precision: точность вычислений
 * s: указатель на переменную, в которую записывается информация об успешности выполнения функции
 *
 * Функция находит корень уравнения f_imp(x) = constant на заданном отрезке [a, b]
 * c точностью до precision. 
 *
 * Метод:
 * Корень на отрезке находится методом секущих. f_imp - непрерывная, положительная на [-PI/2, PI/2] функция, 
 * принимающая на концах заданного отрезка значения с разных сторон от constant (или равняющаяся constant 
 * хотя бы на одном из концов отрезка). Если на концах отрезка принимаются отличные от constant значения
 * с одной и той же стороны от него, поиск корня производиться не будет 
 * (метод оправдан тем, что первообразная f_imp в силу положительности функции монотонна).
 *
 * Возвращаемое значение:
 * В случае успешного нахождения корня возвращается x, 
 * для которого f_imp(x) = constant (с точностью до precision). В том случае, 
 * если корень не может быть найден, возвращается произвольное значение за границами отрезка, 
 * а в s записывается соответствующая информация.
 *
 */

double solve_equation(double constant, double a, double b, double precision, RootStatus *s);