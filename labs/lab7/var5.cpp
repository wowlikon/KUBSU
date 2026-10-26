#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Call {
    string date;
    int city_code;
    string city_name;
    double duration;
    double tariff;
    string src_phone;
    string dst_phone;
};

int main() {
    setlocale(0, "Russian");

    int n;
    vector<Call> calls;

    cout << "Введите количество записей: ";
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        Call c;
        cout << "\nРазговор №" << (i + 1) << ":" << endl;
        cout << "Дата: "; cin >> c.date;
        cout << "Код города: "; cin >> c.city_code;
        cout << "Тариф (за минуту): "; cin >> c.tariff;
        cout << "Название города: "; cin >> c.city_name;
        cout << "Время разговора (минут): "; cin >> c.duration;
        cout << "Номер телефона в городе: "; cin >> c.src_phone;
        cout << "Номер телефона абонента: "; cin >> c.dst_phone;
        calls.push_back(c);
    }

    string target_city;
    cout << "\nПоиск названия города: "; cin >> target_city;

    double total_duration = 0.0;
    double total_cost = 0.0;

    for (const auto& call : calls) {
        if (call.city_name == target_city) {
            total_duration += call.duration;
            total_cost += call.duration * call.tariff;
        }
    }

    cout << "\nСтатистика для города: " << target_city << endl;
    cout << "Общее время разговоров: " << total_duration << " мин." << endl;
    cout << "Общая сумма к оплате: " << total_cost << endl;

    return 0;
}
