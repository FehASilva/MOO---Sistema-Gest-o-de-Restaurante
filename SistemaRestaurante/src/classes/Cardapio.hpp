#ifndef CARDAPIO_HPP
#define CARDAPIO_HPP

#include "Item.hpp"
#include <vector>
#include <string>

// Classe que gerencia o cardápio do sistema
class Cardapio {
private:
    std::vector<Item> itens;      // Lista de itens disponíveis no cardápio
    std::vector<double> precos;   // Lista de preços correspondentes aos itens

public:
    // Carrega os itens e preços do cardápio
    void carregarCardapio(const std::string& filename);

    // Lista os itens e seus preços no console
    void listarItens() const;
    std::string operator[](int index) const;  // Retorna o nome do item

    const std::vector<Item>& getItens() const {
        return itens;
    }
};

#endif // CARDAPIO_HPP
