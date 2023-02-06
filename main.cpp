#include <iostream>
#include <vector>
#include <unordered_map>


class DataManager { //������� ����� DataManager
public:
    int mostSearchedKey() { // � ��������� ���� ������ ������� ����� ��� ������ �������� ����� �������������� ��������
        std::unordered_map<int, int> keyAmount; // ������� unordered_map ���� ����-��������
        for (size_t i = 0; i < _keys.size(); i++) { // �������� �� ������ ������� _keys �� ������ i = 0 � �� ����� i < _keys.size() � ����� 1 i++
            const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 }); //��������� i-� ������� �������� ���� ���
            if (!isInserted) { // ���� isInserted �� ����� 1
                auto value = it->second; // ��������� � 2-�� �������� ����
                value++; // ����������� �������� �� 1
                keyAmount[_keys[i]] = value; // ������������� ��������� value ;                
            }
        }
        std::pair<int, int> key_biggestValue = { 0,0 }; // ������� ����, � ������� ������ ������� ��� ����� ��� ����� ����� ����������� �������
        for (std::unordered_map <int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) { // ��������� �� unordered_map<int, int> keyAmount �� ������ keyAmount.begin() �� ����� keyAmount.end() � ����� 1
            if (key_biggestValue.second < it->second) { //���� ������ ������� pair ������ ������� �������� unordered_map it 
                key_biggestValue = std::make_pair(it->first, it->second); // ��������� ����  key_biggestValue �� ���������� it->first, it->second
            }
        }
        return key_biggestValue.first; // ������� ����� ����� ����������� ������� (������ first �������� ����)
    }
private: //� ��������� ���� ������� ������ ������, � ������� � ����� ������� �������� ����� �����������
    std::vector<int> _keys = { 1, 1, 2, 2, 2, 4, 6, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2 };
};




int main() {
    
    DataManager dm;
    std::cout << dm.mostSearchedKey() << std::endl;    
}