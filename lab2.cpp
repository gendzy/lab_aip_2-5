#include <iostream>
#include <string>

using namespace std;

enum Month {
    January = 1, February, March, April, May, June, July,
    August, September, October, November, December
};

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date(const string& dateString) {
        string delimiter = ".";
        size_t pos = 0;
        string token;
        int dateArr[3];
        int i = 0;

        string tempString = dateString;
        while ((pos = tempString.find(delimiter)) != string::npos) {
            token = tempString.substr(0, pos);
            dateArr[i++] = stoi(token);  // Конвертируем подстроку в целое число
            tempString.erase(0, pos + delimiter.length());  // Удаляем обработанную подстроку
        }

        dateArr[i] = stoi(tempString);  // Получаем последнюю часть даты

        year = dateArr[0];  // Присваиваем значения полям класса
        month = dateArr[1];
        day = dateArr[2];
    }

    Date(int dateInt) {
        year = dateInt / 10000;
        month = (dateInt / 100) % 100;
        day = dateInt % 100;
    }

    void setDay(int d) {
        day = d;  // Устанавливаем новое значение дня
    }

    void setMonth(int m) {
        month = m;  // Устанавливаем новое значение месяца
    }

    void setYear(int y) {
        year = y;  // Устанавливаем новое значение года
    }

    int getDay() const {
        return day;  // Возвращаем значение дня
    }

    int getMonth() const {
        return month;  // Возвращаем значение месяца
    }

    int getYear() const {
        return year;  // Возвращаем значение года
    }

    void addDays(int numDays) {    // Реализация метода добавления дней к дате 
    }

    int getDaysDifference(const Date& otherDate) const {  // Реализация метода подсчета количества дней между двумя датами
    
    }
};

int main() {
    Date date1(3, 9, 2020);
    cout << "Day: " << date1.getDay() << endl;
    cout << "Month: " << date1.getMonth() << endl;
    cout << "Year: " << date1.getYear() << endl;

    Date date2("2020.04.07");
    cout << "Day: " << date2.getDay() << endl;
    cout << "Month: " << date2.getMonth() << endl;
    cout << "Year: " << date2.getYear() << endl;

    Date date3(20200407);
    cout << "Day: " << date3.getDay() << endl;
    cout << "Month: " << date3.getMonth() << endl;
    cout << "Year: " << date3.getYear() << endl;

    return 0;
}
