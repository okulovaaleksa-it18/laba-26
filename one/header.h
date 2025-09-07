#pragma once
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Graph 
{
private:
    int vertexCount; // Количество вершин
    vector<vector<int>> adjMatrix; // Матрица смежности

public:
    Graph(const string& filename);// Конструктор
    vector<int> calculateDegrees() const;// Вычисление степеней вершин
    void printDegrees() const;// Вывод степеней
    int getVertexCount() const;//Получение кол-ва вершин
};
