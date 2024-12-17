#include "Pedido.hpp"
#include "Database.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool Pedido::criaPedido() {
    // Aqui pode haver validações se o pedido está completo ou se está correto
    return true;
}

bool Pedido::adicionaItem(const std::string& nome, int quantidade) {
    itens.push_back(nome);
    this->quantidade.push_back(quantidade);
    return true;
}

void Pedido::registraPedido() {
    // Preparar os dados do pedido
    std::vector<std::vector<std::string>> pedidoData;
    std::vector<std::string> pedidoRow;
    pedidoRow.push_back(cliente);  // Nome do cliente

    // Adiciona os itens e quantidades
    for (size_t i = 0; i < itens.size(); ++i) {
        pedidoRow.push_back(itens[i] + " (" + std::to_string(quantidade[i]) + ")");
    }

    // Adiciona a linha com o pedido no vetor
    pedidoData.push_back(pedidoRow);

    // Chama a função para salvar no CSV
    Database::saveCSV("../data/pedidos.csv", pedidoData);

    std::cout << "Pedido realizado e registrado com sucesso!\n";
}