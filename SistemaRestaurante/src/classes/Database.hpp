// Arquivo: src/classes/Database.hpp
#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <string>

// Classe para manipulação de arquivos CSV
class Database {
public:
    // Carrega os dados de um arquivo CSV para um vetor de vetores de strings
    static std::vector<std::vector<std::string>> loadCSV(const std::string& filename);
    
    // Salva os dados de um vetor de vetores de strings em um arquivo CSV
    static void saveCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data);
};

#endif // DATABASE_HPP
