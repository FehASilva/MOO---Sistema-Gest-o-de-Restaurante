#include "Cardapio.hpp"
#include "Database.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Cardapio::carregarCardapio(const std::string& filename) {
    // Carrega os dados do CSV usando o Database
    std::vector<std::vector<std::string>> dados = Database::loadCSV(filename);

    // A primeira linha contém os cabeçalhos, então ignoramos ela
    for (size_t i = 1; i < dados.size(); ++i) {
        const auto& linha = dados[i];

        // Lê os dados da linha (nome, preço, receita, informações nutricionais e disponibilidade)
        std::string nomeItem = linha[0];
        double preco = std::stod(linha[1]);
        std::string receita = linha[2];
        std::vector<std::string> infoNutricional = {linha[3], linha[4], linha[5]};
        bool disponivel = (linha[6] == "true");

        // Adiciona o item ao cardápio
        itens.emplace_back(nomeItem, receita, infoNutricional);
        precos.push_back(preco);
    }
}

void Cardapio::listarItens() const {
    for (size_t i = 0; i < itens.size(); ++i) {
        const auto& item = itens[i];
        double preco = precos[i];  // Obtém o preço correspondente ao item

        std::cout << "Item: " << i + 1 << "\n";
        std::cout << "Nome: " << item.nome << "\n";
        std::cout << "Preço: R$ " << preco << "\n";
        std::cout << "Receita: " << item.receita << "\n";
        std::cout << "Informações Nutricionais:\n";
        for (const auto& info : item.informacaoNutricional) {
            std::cout << "- " << info << "\n";
        }
        std::cout << "\n";
    }
}

std::string Cardapio::operator[](int index) const {
    if (index >= 0 && index < itens.size()) {
        return itens[index].nome;  // Retorna o nome do item
    }
    return "";  // Retorna uma string vazia se o índice for inválido
}