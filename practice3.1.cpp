#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_set>

using namespace std;

void task1()//Двоичному коду делают стрижку
{
    // Создаем вектор, начинающийся с 1
    vector<int> binary_code;
    binary_code.push_back(1);
    
    // Заполняем вектор случайным количеством 1 и 0
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    
    while (binary_code.size() < 5) {
        binary_code.push_back(dis(gen));
    }
    
    // Выводим вектор
    cout << "Двоичный код: ";
    for (int bit : binary_code) {
        cout << bit;
    }
    cout << endl;
    cout << "- Можно ли к вам прикасаться? ";
    if (binary_code[0] == 1) {//первая цифра вектора
        cout <<endl<< "- Да"<<endl<<"- Делаем как обычно? ";
        if (binary_code[1] == 1) {//вторая цифра вектора
            cout <<endl<< "- Да"<<endl<<"- Обожаю постоянность!"<<endl<<"- Мне итак идет)" ;
        }
        else {
            cout <<endl<< "- Нет"<<endl<<"- Интересно, тогда может карэ? ";
            if (binary_code[2] == 1) {//третья цифра вектора
            cout << endl<<"- Да"<<endl<<"- Круто, давай попробуем" <<endl<<"- Уверен, мне пойдет" ;
            }
            else {
                cout <<endl<< "- Нет"<<endl<<"- Хм, скоро лето, го налысо?" << endl;
                if (binary_code[3] == 1) {//четвертая цифра вектора
                cout <<endl<< "-Да"<<endl<<"- Ты будешь вылетый Вин Дизель!"<<endl<<"- Наконец-то!" ;
                }
                else {
                    cout <<endl<< "- Нет"<<endl<<"- Слушай ты вообще, уверен, что хочешь стричься? А то тебе не угодишь! " << endl;
                    if (binary_code[4] == 1) {//пятая цифра вектора
                    cout <<endl<< "- Да"<<endl<<"- Тогда определись, что тебе нужно и приходи в следующий раз!"<<endl<<"- Ладненько, извини, пока...";
                    }
                    else {
                    cout <<endl<< "- Нет"<<endl<<"- Ты только зря тратишь мое время! Выметайся! " << endl;
                    }       
            }
            }
        }
    } else {
        cout <<endl<< "- Нет"<<endl<<"- Тогда иди домой шутник!"<<endl<<"- Вот и пойду!" << endl;
    }
}
void task2() // вывод палиндромов из массива
{
    vector<string> Polindrom = { "madam", "racecar", "level", "deified", "rotor", "civic", "kayak", "radar", "refer", "pop" };
    vector<string> findPolindrom;
    copy_if(Polindrom.begin(), Polindrom.end(), back_inserter(findPolindrom),[](const string& word)
    {
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return word == reversedWord;
    });
    if (findPolindrom.empty()){
        cout << "Не найдены палиндромы" << endl;
        }
        else{
        cout << "Найдены следующие палиндромы:" << endl;
            for (const auto& word : findPolindrom) {
            cout << word << " ";
            }
        cout << endl;
        }
    }

    int two_versions(int a, int b)
    {
    return b == 0 ? a : two_versions(b, a % b);
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
    string input = "ThIS iS aN ExAmPlE Of A sEnTEnCE wItH rAnDoM cApItAlIzAtIoN aNd lOwErCaSe LeTtErS.";
    cout << input << endl;
 int quantityCapitalLetters = count_if(input.begin(), input.end(),[](char k) {return (k >= 'A' && k <= 'Z'); });//количество заглавных
 cout <<"Кол-во заглавных букв = " << quantityCapitalLetters << endl;
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
void task9(){
    // Количество клавиш на клавиатуре (примерное значение)
    const int totalKeys = 104; // Примерное количество клавиш на стандартной клавиатуре без функциональных клавиш

    // Количество клавиш, которые могут залипать (W, A, S, D)
    const int stuckKeys = 4;

    // Вероятность залипания каждой клавиши
    double probabilityOfStuckKey = 1.0 / stuckKeys;

    // Выводим результат
    cout << "Вероятность, что из всех клавиш на клавиатуре, залипнет W, A, S или D: " << probabilityOfStuckKey << endl;
}
void task10(){
       // Предположим, что цена биткоина в долларах в 2010 была около $10
    const double bitcoinPrice2010 = 0.5;
    // Предположим, что цена биткоина в долларах в 2024 будет такой же, как в 2010
    const double bitcoinPrice2024 = 66740.0;

    // Количество долларов, которые мы можем потратить
    const double dollarsAvailable = 10000.0;

    // Количество биткоинов, которые мы можем купить в 2010
    double bitcoinsBought2010 = dollarsAvailable / bitcoinPrice2010;
    // Количество биткоинов, которые мы можем купить в 2024
    double bitcoinsBought2024 = dollarsAvailable / bitcoinPrice2024;

    // Выводим результаты
    cout << "Количество биткоинов, которые можно было купить на 10000 долларов в 2010: " << bitcoinsBought2010 << endl;
    cout << "Количество биткоинов, которые можно было купить на 10000 долларов в 2024: " << bitcoinsBought2024 << endl;

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
     task9();

     cout << "\n\nЗадание 10\n" << endl;
     task10();
}
