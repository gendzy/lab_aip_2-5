#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления площади основания
double calculateBaseArea(double a, double b, double angle) {
    double sinAngle = sin(angle / 2);
    return a * b * sinAngle;
}

// Функция для вычисления площади боковой поверхности
double calculateLateralSurfaceArea(double a, double b, double angle, double H) {
    double cosAngle = cos(angle);
    return (a + b + sqrt(a * a + b * b - 2 * a * b * cosAngle)) * H;
}

// Функция для вычисления полной поверхности
double calculateTotalSurfaceArea(double a, double b, double angle, double H) {
    double baseArea = calculateBaseArea(a, b, angle);
    double lateralSurfaceArea = calculateLateralSurfaceArea(a, b, angle, H);
    return 2 * baseArea + lateralSurfaceArea;
}

// Функция для вычисления объема
double calculateVolume(double a, double b, double angle, double H) {
    double baseArea = calculateBaseArea(a, b, angle);
    return baseArea * H;
}

// Функция для вычисления веса
double calculateWeight(double volume, double density) {
    return volume * density;
}

int main() {
    double a, b, angle, H;
    double density;

    setlocale(LC_ALL, "Russian");

    // Ввод параметров фигуры
    wcout << L"Введите сторону a: ";
    wcin >> a;
    wcout << L"Введите сторону b: ";
    wcin >> b;
    wcout << L"Введите угол между сторонами: ";
    wcin >> angle;
    wcout << L"Введите высоту H: ";
    wcin >> H;
    wcout << L"Введите плотность материала: ";
    wcin >> density;

    // Вычисление значений
    double baseArea = calculateBaseArea(a, b, angle);
    double lateralSurfaceArea = calculateLateralSurfaceArea(a, b, angle, H);
    double totalSurfaceArea = calculateTotalSurfaceArea(a, b, angle, H);
    double volume = calculateVolume(a, b, angle, H);
    double weight = calculateWeight(volume, density);

    // Вывод результатов
    wcout << L"Площадь основания: " << baseArea << endl;
    wcout << L"Боковая поверхность: " << lateralSurfaceArea << endl;
    wcout << L"Полная поверхность: " << totalSurfaceArea << endl;
    wcout << L"Объем: " << volume << endl;
    wcout << L"Вес: " << weight << endl;

    return 0;
}
