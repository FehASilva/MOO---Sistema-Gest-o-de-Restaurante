#include "Item.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Item::Item(const std::string& nome, const std::string& receita, const std::vector<std::string>& info)
    : nome(nome), receita(receita), informacaoNutricional(info), disponivel(disponivel) {}

#include <regex>

bool Item::estaDisponivel() const {
    std::ifstream file("../data/itens.csv");
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo ../data/itens.csv");
    }

    std::string linha;

    // Ignora a primeira linha (cabeçalho do CSV)
    std::getline(file, linha);

    // Lê o arquivo linha por linha
    while (std::getline(file, linha)) {
        std::regex regexCsv("\"([^\"]*)\",?|([^,]+),?|,"); // Expressão regular para capturar valores CSV
        std::sregex_iterator it(linha.begin(), linha.end(), regexCsv);
        std::sregex_iterator end;

        std::vector<std::string> campos;
        while (it != end) {
            if ((*it)[1].matched) {
                campos.push_back((*it)[1].str()); // Valor entre aspas
            } else if ((*it)[2].matched) {
                campos.push_back((*it)[2].str()); // Valor sem aspas
            } else {
                campos.push_back(""); // Valor vazio
            }
            ++it;
        }

        if (campos.size() < 6) {
            continue; // Ignora linhas incompletas
        }

        std::string nomeItem = campos[0];
        std::string preco = campos[1];
        std::string receita = campos[2];
        std::string info1 = campos[3];
        std::string info2 = campos[4];
        std::string info3 = campos[5];
        std::string disponivelStr = campos[6];

        // Remove espaços em branco ao redor de disponivelStr
        disponivelStr.erase(disponivelStr.find_last_not_of(" \t\n\r") + 1);

        // Converte o valor de disponibilidade para booleano
        bool disponivel = (disponivelStr == "true");

        // Verifica se o nome do item corresponde ao que foi solicitado
        if (nomeItem == this->nome) {
            return disponivel;  // Retorna a disponibilidade do item
        }
    }

    // Se o item não for encontrado no arquivo, retorna false
    return false;
}
