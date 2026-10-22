#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dish {
private:
    string name;
    double price;
    int calories;

    static int totalCount;

public:

    Dish(const string& n, double p, int c)
        : name(n), price(p), calories(c) {
        totalCount++;
        cout << "[Dish] Создано блюдо: " << name << " (" << price << " руб., " << calories << " ккал)\n";
    }

    ~Dish() {
        totalCount--;
        cout << "[Dish] Уничтожено блюдо: " << name << "\n";
    }

    static int getTotalCount() {
        return totalCount;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getCalories() const { return calories; }

    void print() const {
        cout << "  - " << name << " | Цена: " << price << " руб. | Калорийность: " << calories << " ккал\n";
    }
};

int Dish::totalCount = 0;

class Menu {
private:
    string title;
    vector<const Dish*> dishes;

public:
    Menu(const string& t) : title(t) {
        cout << "\n[Menu] Создано меню: \"" << title << "\"\n";
    }

    ~Menu() {
        cout << "[Menu] Меню \"" << title << "\" уничтожено \n\n";
    }

    void addDish(const Dish* dish) {
        if (dish != nullptr) {
            dishes.push_back(dish);
            cout << "[Menu] В меню \"" << title << "\" добавлено блюдо: " << dish->getName() << "\n";
        }
    }

    void print() const {
        cout << endl << title << endl;
        if (dishes.empty()) {
            cout << "Меню пусто.\n";
        }
        else {
            for (const Dish* dish : dishes) {
                dish->print();
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Начальное количество блюд: " << Dish::getTotalCount() << "\n\n";

    Dish* d1 = new Dish("Блюдо 1", 450.0, 800);
    Dish* d2 = new Dish("Блюдо 2", 350.0, 350);
    Dish* d3 = new Dish("Блюдо 3", 280.0, 400);

    cout << "\nТекущее количество блюд в памяти: " << Dish::getTotalCount() << "\n";

    {
        Menu lunchMenu("Обеденное меню");
        lunchMenu.addDish(d1);
        lunchMenu.addDish(d2);
        lunchMenu.print();

    }

    cout << "--- Проверка после уничтожения Menu ---\n";
    cout << "Количество блюд: " << Dish::getTotalCount() << "\n";
    cout << "Обращаемся к блюду напрямую: \n";
    d1->print();

    cout << "\n--- Освобождаем память объектов Dish ---\n";
    delete d1;
    delete d2;
    delete d3;

    cout << "\nИтоговое количество блюд в памяти: " << Dish::getTotalCount() << "\n";

    return 0;
}
