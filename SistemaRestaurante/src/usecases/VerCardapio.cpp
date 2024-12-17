#include "VerCardapio.hpp"
#include "../classes/Cardapio.hpp"
#include <iostream>

void VerCardapio() {
    Cardapio cardapio;

    // Carregar itens do arquivo CSV
    const std::string cardapioPath = "../data/itens.csv"; // Caminho do arquivo CSV
    cardapio.carregarCardapio(cardapioPath);

    // Exibir os itens do cardápio
    std::cout << "========== CARDÁPIO ==========\n";
    cardapio.listarItens();
    std::cout << "==============================\n";
}
