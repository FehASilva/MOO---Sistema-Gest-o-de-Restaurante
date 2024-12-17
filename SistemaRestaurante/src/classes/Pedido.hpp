#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <vector>
#include <string>
#include "Database.hpp"

class Pedido {
private:
    std::string cliente;
    std::vector<std::string> itens;
    std::vector<int> quantidade;

public:
    Pedido(const std::string& cliente) : cliente(cliente) {}

    bool criaPedido();
    bool adicionaItem(const std::string& nome, int quantidade);
    void registraPedido();
};

#endif
