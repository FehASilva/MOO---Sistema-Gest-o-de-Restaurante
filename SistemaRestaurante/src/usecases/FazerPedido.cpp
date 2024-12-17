#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "FazerPedido.hpp"
#include "VerCardapio.hpp"
#include "../classes/Cliente.hpp"
#include "../classes/Pedido.hpp"

void FazerPedido() {
    std::string nome, senha;
    
    // Identificação do cliente
    std::cout << "Digite seu nome: ";
    std::cin >> nome;
    std::cout << "Digite sua senha: ";
    std::cin >> senha;
    
    Cliente cliente(nome, senha, "", "");
    
    // Verificar se o cliente existe
    if (!cliente.consultarUsuario(nome)) {
        std::cout << "Cliente não encontrado.\n";
        return;
    }
    
    // Validar senha
    if (!cliente.validarSenha(senha)) {
        std::cout << "Senha incorreta.\n";
        return;
    }
    
    // Carregar itens do arquivo CSV
    Cardapio cardapio;
    const std::string cardapioPath = "../data/itens.csv";
    cardapio.carregarCardapio(cardapioPath);

    // Exibir os itens do cardápio
    std::cout << "========== CARDÁPIO ==========\n";
    cardapio.listarItens();
    std::cout << "==============================\n";

    // Solicitar itens e quantidades
    Pedido pedido(nome);
    int numItens;
    std::cout << "Quantos itens deseja pedir? ";
    std::cin >> numItens;

    for (int i = 0; i < numItens; ++i) {
        int itemEscolhido, quantidade;
        std::cout << "Digite o número do item e a quantidade desejada: ";
        std::cin >> itemEscolhido >> quantidade;
        pedido.adicionaItem(cardapio[itemEscolhido - 1], quantidade);  // Adiciona o item ao pedido
    }

    // Registrar o pedido
    pedido.registraPedido();
    std::cout << "Pedido realizado com sucesso!\n";
}

