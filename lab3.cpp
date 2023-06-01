#include <iostream>
using namespace std;

enum class Month {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

class Date {
private:
    int year;
    mutable Month month; // Используем модификатор mutable для изменения поля month в const-методах
    int day;

public:
    Date(int year, Month month, int day)
        : year(year), month(month), day(day) {}

    void display() const {
        cout << day << "/" << static_cast<int>(month) << "/" << year << endl; // Выводим дату на экран
    }

    Date operator+(int days) const {
        int totalDays = day + days;
        int daysInMonth = getDaysInMonth(year, month); // Получаем количество дней в текущем месяце

        int newYear = year;
        Month newMonth = month;

        while (totalDays > daysInMonth) { // Пока общее количество дней превышает количество дней в текущем месяце
            totalDays -= daysInMonth; // Уменьшаем общее количество дней на количество дней в текущем месяце
            int nextMonth = static_cast<int>(newMonth) + 1;

            if (nextMonth > 12) { // Если следующий месяц больше декабря, то увеличиваем год
                nextMonth = 1;
                ++newYear;
            }

            newMonth = static_cast<Month>(nextMonth); // Устанавливаем новый месяц
            daysInMonth = getDaysInMonth(newYear, newMonth); // Получаем количество дней в новом месяце
        }

        return Date(newYear, newMonth, totalDays); // Возвращаем новую дату
    }

    Date& operator++() {
        *this = *this + 1; // Инкрементируем дату на 1 день
        return *this; // Возвращаем измененную дату
    }

    Date operator++(int) {
        Date temp = *this; // Создаем копию текущей даты
        ++(*this); // Инкрементируем дату на 1 день
        return temp; // Возвращаем копию старой даты
    }

    Date& operator--() {
        *this = *this + 1; // Декрементируем дату на 1 день
        return *this; // Возвращаем измененную дату
    }

    Date operator--(int) {
        Date temp = *this; // Создаем копию текущей даты
        --(*this); // Декрементируем дату на 1 день
        return temp; // Возвращаем копию старой даты
    }

private:
    int getDaysInMonth(int year, Month month) const {
        switch (month) {
        case Month::January:
        case Month::March:
        case Month::May:
        case Month::July:
        case Month::August:
        case Month::October:
        case Month::December:
            return 31; // Возвращаем 31 день для месяцев с 31 днем

        case Month::April:
        case Month::June:
        case Month::September:
        case Month::November:
            return 30; // Возвращаем 30 дней для месяцев с 30 днями

        case Month::February:
            if (isLeapYear(year)) { // Если год високосный
                return 29; // Возвращаем 29 дней для февраля
            }
            else {
                return 28; // Возвращаем 28 дней для февраля
            }
        }

        return 0;
    }

    bool isLeapYear(int year) const {
        if (year % 4 != 0) { // Если год не делится на 4 без остатка
            return false; // Год не високосный
        }
        else if (year % 100 != 0) { // Если год не делится на 100 без остатка
            return true; // Год високосный
        }
        else if (year % 400 != 0) { // Если год не делится на 400 без остатка
            return false; // Год не високосный
        }

        return true; // Год високосный
    }
};

int main() {
    Date currentDate(2023, Month::May, 27); // Создаем объект currentDate с текущей датой

    currentDate.display(); // Выводим текущую дату на экран

    Date futureDate = currentDate + 10; // Увеличиваем текущую дату на 10 дней
    futureDate.display(); // Выводим будущую дату на экран

    ++currentDate; // Инкрементируем текущую дату на 1 день
    currentDate.display(); // Выводим обновленную текущую дату на экран

    --currentDate; // Декрементируем текущую дату на 1 день
    currentDate.display(); // Выводим обновленную текущую дату на экран

    return 0;
}
