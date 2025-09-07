#include "header.h"
#include <fstream>
#include <iostream>
#include <sstream>

//Количество вершин
int Graph::getVertexCount() const 
{
    return vertexCount;
}

// Конструктор: загружает граф из файла
Graph::Graph(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }

    // Чтение количества вершин
    string line;
    if (!getline(file, line))
    {
        throw runtime_error("Файл пуст");
    }

    istringstream iss(line);
    if (!(iss >> vertexCount) || vertexCount <= 0)
    {
        throw runtime_error("Некорректное количество вершин");
    }

    // Инициализация матрицы
    adjMatrix.resize(vertexCount, vector<int>(vertexCount, 0));

    // Чтение матрицы смежности
    for (int i = 0; i < vertexCount; ++i)
    {
        if (!getline(file, line))
        {
            throw runtime_error("Неожиданный конец файла");
        }

        istringstream row_iss(line);
        for (int j = 0; j < vertexCount; ++j)
        {
            int value;
            if (!(row_iss >> value))
            {
                throw runtime_error("Ошибка чтения элемента матрицы");
            }
            if (value != 0 && value != 1)
            {
                throw runtime_error("Некорректное значение в матрице (допустимо 0 или 1)");
            }
            adjMatrix[i][j] = value;
        }

        // Проверка на лишние элементы в строке
        int extra;
        if (row_iss >> extra)
        {
            throw runtime_error("Лишние элементы в строке матрицы");
        }
    }

    file.close();
}

// Вычисление степеней вершин
vector<int> Graph::calculateDegrees() const 
{
    vector<int> degrees(vertexCount, 0);
    for (int i = 0; i < vertexCount; ++i) 
    {
        for (int j = 0; j < vertexCount; ++j) 
        {
            if (adjMatrix[i][j] != 0) {
                degrees[i]++;
                if (i == j) degrees[i]++;  // Учет петли
            }
        }
    }
    return degrees;
}

// Вывод степеней вершин
void Graph::printDegrees() const 
{
    vector<int> degrees = calculateDegrees();
    cout << "Степени вершин графа:" << endl;
    for (int i = 0; i < vertexCount; ++i) 
    {
        cout << "Вершина " << i << ": " << degrees[i] << endl;
    }
}
