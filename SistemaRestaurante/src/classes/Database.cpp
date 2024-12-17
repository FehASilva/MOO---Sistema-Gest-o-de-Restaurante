// Arquivo: src/classes/Database.cpp
#include "Database.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<std::string>> Database::loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;
        bool insideQuotes = false;

        while (std::getline(lineStream, cell, ',')) {
            if (insideQuotes) {
                // Se estivermos dentro de aspas, concatenamos a célula com vírgulas internas
                row.back() += "," + cell;
            } else {
                if (cell.front() == '"' && cell.back() != '"') {
                    // Se encontramos uma célula que começa com aspas, mas não termina, significa que está dentro de aspas
                    insideQuotes = true;
                    row.push_back(cell);  // Adiciona o primeiro pedaço da célula
                } else if (cell.front() == '"' && cell.back() == '"') {
                    // Se a célula começa e termina com aspas, basta remover as aspas
                    row.push_back(cell.substr(1, cell.size() - 2));
                } else {
                    // Caso normal: sem aspas, podemos adicionar diretamente
                    row.push_back(cell);
                }
            }

            if (insideQuotes && cell.back() == '"') {
                insideQuotes = false;  // Se encontramos a aspa de fechamento, terminamos o campo entre aspas
            }
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

void Database::saveCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename, std::ios::app);  // Abre o arquivo no modo "append"
    
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";  // Se não for o último elemento, adiciona uma vírgula
            }
        }
        file << "\n";  // Adiciona uma nova linha após cada registro
    }
}
