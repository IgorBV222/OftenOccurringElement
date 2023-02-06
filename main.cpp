#include <iostream>
#include <vector>
#include <unordered_map>


class DataManager { //создаем класс DataManager
public:
    int mostSearchedKey() { // в публичном поле класса создаеи метод для поиска наиболее часто встречающегося элемента
        std::unordered_map<int, int> keyAmount; // создаем unordered_map пары ключ-значение
        for (size_t i = 0; i < _keys.size(); i++) { // проходим по нашему вектору _keys от начала i = 0 и до конца i < _keys.size() с шагом 1 i++
            const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 }); //проверяем i-й элемент вставлен один раз
            if (!isInserted) { // если isInserted не равно 1
                auto value = it->second; // обращение к 2-му элементу пары
                value++; // увеличиваем значение на 1
                keyAmount[_keys[i]] = value; // принудительно вставляет value ;                
            }
        }
        std::pair<int, int> key_biggestValue = { 0,0 }; // создаем пару, в которой первый элемент это будет наш самый часто встречаемый элемент
        for (std::unordered_map <int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) { // пробигаем по unordered_map<int, int> keyAmount от начала keyAmount.begin() до конца keyAmount.end() с шагом 1
            if (key_biggestValue.second < it->second) { //если первый элемент pair меньше второго элемента unordered_map it 
                key_biggestValue = std::make_pair(it->first, it->second); // создается пара  key_biggestValue со значениями it->first, it->second
            }
        }
        return key_biggestValue.first; // выводим самый часто встречаемый элемент (первое first значение пары)
    }
private: //в приватном поле создали вектор ключей, в котором и будем исткать наиболее часто встречаемый
    std::vector<int> _keys = { 1, 1, 2, 2, 2, 4, 6, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2 };
};




int main() {
    
    DataManager dm;
    std::cout << dm.mostSearchedKey() << std::endl;    
}