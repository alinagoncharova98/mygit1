#include <iostream>
#include <cmath>
using namespace std;
 
// Целевая функция
double f(double x) {
	return (x-1)*(x-1);
}
 
int main() {
	double a;	// Левый конец сегмента локализации
	double b;	// Правый конец сегмента локализации
	double epsilon;	// Требуемая точность
 
	cin >> a >> b >> epsilon;
 
	int k = 0;	// Счетчик итераций
	int l = 1;	// Счетчик вычислений функции
 
	// Вычисляем среднюю точку сегмента
	double x_avg  = (a + b) / 2;
		double f_x_avg = f(x_avg);
 
	// Пока длина сегмента локализации меньше требуемой точности
	while (b - a > epsilon) {
		cout << a << " " << b << endl << k << endl;
 
		// Вычисляем среднюю точку сегмента
		//double x_avg  = (a + b) / 2;
 
		// Вычисляем потенциально новые концы сегмента
		double y_k = a + (b - a) / 4;
		double z_k = b - (b - a) / 4;
 
 
		// Вычисляем значение функции в этих точках
		double f_y_k  = f(y_k);
		double f_z_k = f(z_k);
		//double f_x_avg = f(x_avg);
		l += 2;	// Инкрементируем счетчик вычислений функции
 
		// Определяем концы нового сегмента локализации
		if (f_y_k < f_x_avg){
			b = x_avg;
			x_avg = y_k;
		}
		else if (f_y_k >= f_x_avg) {
			if(f_z_k < f_x_avg){
				a = x_avg;
				x_avg = z_k;
			}
			else {
				a = y_k;
				b = z_k;
			}
		}
 
		k++;	// Инкрементируем счетчик итераций
	}
	 double X_min = x_avg;// Вычисляем точку минимума
 
	// Выводим результаты
	cout << "Точка минимума:  \t" <<  X_min  << endl
	     << "Значение функции:\t" << f(X_min) << endl
	     << "Количество итераций:          \t" << k << endl
	     << "Количество вычислений функции:\t" << l << endl;
 
	return 0;
}
 

