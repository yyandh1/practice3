#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <functional>

using namespace std;

void task1()
{
   int planned_profit = 450;

    map<int, pair<int, int>> data = {{1, {500, 50}}, {2, {400, 60}}, {3, {700, 250}}, {4, {300, 100}}, {5, {450, 50}}};

    vector<pair<int, int>> results;

    for (const auto& days : data) {
        int day = days.first;
        int income = days.second.first;
        int expenses = days.second.second;
        int profit = income - expenses;

        if (profit < planned_profit) {
            results.push_back({day, planned_profit - profit});
        }
    }

    sort(results.begin(), results.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for (pair<int, int> result : results) {
        cout << "День: " << result.first << ", Прибыль меньше плановой на: " << result.second << endl;
    }
}
struct Student {
    int number;
    double stip;
    double sr_ball;

    // Конструктор для создания объектов Student
    Student(int num, double i, double g) : number(num), stip(i), sr_ball(g) {}
};

// Функция для сравнения студентов на основе их дохода и успеваемости
bool compareStudents(const Student& a, const Student& b) {
    // Сначала сравниваем по доходу (меньший доход имеет приоритет)
    if (a.stip != b.stip) {
        return a.stip < b.stip;
    }
    // Если доходы равны, сравниваем по успеваемости (больший балл имеет приоритет)
    return a.sr_ball > b.sr_ball;
}

void task2() 
{
        int n, z; // Количество заявлений и студентов, которым можно одобрить мат. помощь

    cout << "Введите количество заявлений: ";
    cin >> n;
    cout << "Введите количество студентов, которым можно одобрить мат. помощь: ";
    cin >> z;

    srand(time(0));

    // Создание вектора для хранения заявлений
    vector<Student> students;

    // Генерация случайных данных об оценках и доходах студентов и вывод списка студентов
    cout << "\nДанные о всех студентах, их доходы и успеваемость:\n";
    for (int i = 1; i <= n; ++i) {
        double Sr_Ball2 = rand() % 20 + 30;
        double Sr_Ball = Sr_Ball2 / 10.0;
        int Stip = rand() % 15000 + 5100;
        students.push_back(Student(i, Stip, Sr_Ball));
        cout << "Студент " << i << ": Доход - " << Stip << ", Успеваемость - " << Sr_Ball << endl;
    }

    // Сортировка студентов по приоритету
    sort(students.begin(), students.end(), compareStudents);

    // Сортировка студентов, которым одобрили мат. помощь, по возрастанию номеров
    sort(students.begin(), students.begin() + min(n, z), [](const Student& a, const Student& b) {
        return a.number < b.number;
        });

    // Вывод списка студентов, которым одобрят мат. помощь (упорядоченных по возрастанию номеров)
    cout << "\nСтуденты, которым одобрят мат. помощь (в порядке возрастания номеров):\n";
    for (int i = 0; i < min(n, z); ++i) {
        cout << "Студент " << students[i].number << endl;
    }
} 

bool isAnagram(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;
    string a = s1, b = s2;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
void task3()// функция, которая находит все анаграммы заданного слова в списке слов
{
    unordered_set<string> uniqueWords;
    string excludedStrings[] = {"лимон", "монил", "олимп", "плимо", "серия", "ярсие", "ресиц", "ерисц", "аноко", "кооан"};

    for (const auto& word : excludedStrings) {
        uniqueWords.insert(word);
    }

    for (size_t i = 0; i < size(excludedStrings); i++) {
        for (size_t j = i + 1; j < size(excludedStrings); j++) {
            if (isAnagram(excludedStrings[i], excludedStrings[j])) {
                uniqueWords.erase(excludedStrings[j]);
            }
        }
    }

    cout << "Количество уникальных слов: " << uniqueWords.size() << endl;
}

void task4()
{
vector<int> class9a_scores = {75, 80, 95, 88, 76, 85, 92, 89, 90, 78};
    vector<int> class9b_scores = {82, 91, 78, 84, 88, 95, 92, 79, 86, 85, 89, 90, 91, 87, 84};

    int total_class9a = accumulate(class9a_scores.begin(), class9a_scores.end(), 0);
    int total_class9b = accumulate(class9b_scores.begin(), class9b_scores.end(), 0);

    if (total_class9a > total_class9b) {
        cout << "9 А класс победил с " << total_class9a << " баллами";
    } else if (total_class9b > total_class9a) {
        cout << "9 Б класс победил с " << total_class9b << " баллами";
    } else {
        cout << "У классов одно и то же количество баллов, победила дружба";
    }


}

bool throwDiceForSums(int sum1, int sum2, int sum3) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);

    for (int i = 0; i < 3; ++i) {
        int dice1 = dis(gen);
        int dice2 = dis(gen);
        int currentSum = dice1 + dice2;

        if (currentSum != sum1 && currentSum != sum2 && currentSum != sum3) {
            return false;
        }
    }

    return true;
}

void task5(){
   int numTrials = 10000; // Количество попыток
    int successes = 0;

    for (int i = 0; i < numTrials; ++i) {
        if (throwDiceForSums(8, 9, 10)) {
            ++successes;
        }
    }

    double probability = static_cast<double>(successes) / numTrials;
    cout << "Вероятность выпадения 8, 9 или 10 при трех бросках двух кубиков: " << probability << endl;
}

void task6(){
    double white_f_peshka=1.0/32;//шанс, что белые походят пешкой на f, неважно на одну или две клетки
    double black_e_peshka=1.0/32;//шанс, что черные походят пешкой на e, неважно на одну или две клетки
    double white_g_peshka=1.0/32*1.0/2;//шанс, что белые походят пешкой на g, обязательно на две клетки
    double probability = white_f_peshka*black_e_peshka*white_g_peshka;// дальше черным лишь остается двинуть ферзя на h4 и поставить мат, мы подсчитаываем вероятность, лишь первы трех ходов
    cout << "Вероятность поставить мат в два хода: " << probability << endl;
}

void task7(){
    vector<string> words = {"Flutter", "Quartz", "Zephyr", "Glisten", "Mirth", "Bramble", "Whimsy", "Luminous", "Cascade", "Ephemeral"};

    auto longestWord = max_element(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });
    cout << "Самое длинное слово: " << *longestWord;

}
void task8(){
    // Инициализируем вектор с некоторыми значениями
    vector<int> numbers = {5, 2, -3, 8, 1, 9, -10, 4, 7, 6};

    // Ищем максимальный и минимальный элементы
    auto minmax = minmax_element(numbers.begin(), numbers.end());
    int minElement = *minmax.first;
    int maxElement = *minmax.second;

    // Вычисляем сумму квадратов минимального и максимального элементов
    int sumOfSquares = pow(minElement, 2) + pow(maxElement, 2);

    // Выводим результаты
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl;
    cout << "Сумма квадратов минимального и максимального элементов: " << sumOfSquares << endl;
}
void task9(vector<vector<int>>& sudoku) {
    // Инициализация вектора с пустым Судоку
    sudoku = vector<vector<int>>(9, vector<int>(9, 0));

    // Заполняем первую строку случайными числами от 1 до 9
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_device rd;
    mt19937 gen(rd());
    shuffle(numbers.begin(), numbers.end(), gen);
    copy(numbers.begin(), numbers.end(), sudoku[0].begin());

    // Заполняем остальные строки, используя алгоритмы
    for (int row = 1; row < 9; ++row) {
        // Копируем элементы предыдущей строки
        copy(sudoku[row - 1].begin(), sudoku[row - 1].end(), sudoku[row].begin());

        // Смещаем элементы вправо на 1 позицию
        rotate(sudoku[row].begin(), sudoku[row].begin() + 1, sudoku[row].end());
    }

    // Перемешиваем элементы в каждом столбце
    for (int col = 0; col < 9; ++col) {
        vector<int> columnElements(9);
        transform(sudoku.begin(), sudoku.end(), columnElements.begin(), [col](const vector<int>& row) {
            return row[col];
        });
        shuffle(columnElements.begin(), columnElements.end(), gen);
        for (int row = 0; row < 9; ++row) {
            sudoku[row][col] = columnElements[row];
        }
    }

    // Перемешиваем элементы в каждом квадрате 3x3
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            vector<int> squareElements(9);
            transform(sudoku.begin() + row, sudoku.begin() + row + 3, squareElements.begin(), [col](const vector<int>& row) {
                return row[col] * 100 + row[col + 1] * 10 + row[col + 2];
            });
            shuffle(squareElements.begin(), squareElements.end(), gen);
            for (int i = 0; i < 9; ++i) {
                int value = squareElements[i];
                sudoku[row + i / 3][col + i % 3] = value % 10;
            }
        }
    }
}

// Структура для хранения информации о продажах
struct SalesData {
    string product;
    int quantity;
    double price;
};

// Функция для вычисления общей выручки компании
double calculateTotalRevenue(const vector<SalesData>& salesData) {
    return accumulate(salesData.begin(), salesData.end(), 0.0, [](double total, const SalesData& sale) {
        return total + sale.quantity * sale.price;
    });
}

// Функция для определения самого прибыльного продукта
pair<string, double> findMostProfitableProduct(const vector<SalesData>& salesData) {
    unordered_map<string, double> productProfits;
    for (const auto& sale : salesData) {
        productProfits[sale.product] += sale.quantity * sale.price;
    }

    auto mostProfitableProduct = max_element(productProfits.begin(), productProfits.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    return *mostProfitableProduct;
}

// Функция для определения топ-3 самых продаваемых продуктов
vector<pair<string, int>> findTopThreeProducts(const vector<SalesData>& salesData) {
    unordered_map<string, int> productSales;
    for (const auto& sale : salesData) {
        productSales[sale.product] += sale.quantity;
    }

    vector<pair<string, int>> topProducts(productSales.begin(), productSales.end());
    sort(topProducts.begin(), topProducts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    return {topProducts.begin(), topProducts.begin() + 3};
}

void task10() {
    vector<SalesData> salesData = {
        {"Сгущенка", 100, 10.0},
        {"Кабачки", 50, 20.0},
        {"Пряники", 75, 15.0},
        {"Мороженое", 80, 10.0},
        {"Хлеб", 60, 20.0},
        {"Жвачка", 30, 25.0}
    };

    // Вычисление общей выручки
    double totalRevenue = calculateTotalRevenue(salesData);
    cout << "Общая выручка: " << totalRevenue << endl;

    // Определение самого прибыльного продукта
    auto mostProfitableProduct = findMostProfitableProduct(salesData);
    cout << "Самый прибыльный продукт: " << mostProfitableProduct.first << ", прибыль: " << mostProfitableProduct.second << endl;

    // Определение топ-3 самых продаваемых продуктов
    auto topProducts = findTopThreeProducts(salesData);
    cout << "Топ-3 самых продаваемых продукта:" << endl;
    for (const auto& product : topProducts) {
        cout << product.first << ": " << product.second << " шт." << endl;
    }

}

int main() {
    system("chcp 65001");

     cout << "Задание 1\n" << endl;
     task1();

     cout <<"\n\nЗадание 2\n" << endl;
     task2();

     cout << "\n\nЗадание 3\n" << endl;
     task3();

     cout << "\n\nЗадание 4\n" << endl;
     task4();

     cout << "\n\nЗадание 5\n" << endl;
     task5();

     cout << "\n\nЗадание 6\n" << endl;
     task6();

     cout << "\n\nЗадание 7\n" << endl;
     task7();

     cout << "\n\nЗадание 8\n" << endl;
     task8();

     cout << "\n\nЗадание 9\n" << endl;
     vector<vector<int>> sudoku;
    task9(sudoku);
    // Вывод сгенерированного Судоку
    for (const auto& row : sudoku) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

     cout << "\n\nЗадание 10\n" << endl;
     task10();
}
