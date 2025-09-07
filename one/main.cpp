#include "header.h"
#include <iostream>

int main() 
{
    setlocale(LC_ALL, "Russian");
    try 
    {
        string filename = "laba26.txt";
        Graph graph(filename);  // Создание графа
        cout << "Граф успешно загружен. Количество вершин: " << graph.getVertexCount() << endl;
        graph.printDegrees();   // Вывод результатов
    }
    catch (const exception& e) 
    {
        cerr << "Ошибка: " << e.what() << endl;
        cerr << "Проверьте файл на корректность." << endl;
        return 1;
    }
    return 0;
}
