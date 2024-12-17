#include "Item.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Item::Item(const std::string& nome, const std::string& receita, const std::vector<std::string>& info)
    : nome(nome), receita(receita), informacaoNutricional(info) {}

bool Item::estaDisponivel() const{
    std::ifstream file("../data/itens.csv");
    std::string linha;

    // Ignora a primeira linha (cabeçalho do CSV)
    std::getline(file, linha);

    // Lê o arquivo linha por linha
    while (std::getline(file, linha)) {
        std::stringstream ss(linha);
        std::string nomeItem, receita, info1, info2, info3, disponivelStr;
        bool disponivel;

        // Lê os dados da linha
        std::getline(ss, nomeItem, ',');  // Nome
        std::getline(ss, receita, ',');   // Receita
        std::getline(ss, info1, ',');     // Informacao1
        std::getline(ss, info2, ',');     // Informacao2
        std::getline(ss, info3, ',');     // Informacao3
        std::getline(ss, disponivelStr);  // Disponibilidade

        // Converte o valor de disponibilidade para booleano
        disponivel = (disponivelStr == "true");

        // Verifica se o nome do item corresponde ao que foi solicitado
        if (nomeItem == this->nome) {
            return disponivel;  // Retorna a disponibilidade do item
        }
    }

    // Se o item não for encontrado no arquivo, retorna false
    return false;
}