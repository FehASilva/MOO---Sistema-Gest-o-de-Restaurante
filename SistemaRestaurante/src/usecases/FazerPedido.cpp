#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
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
        if (!(std::cin >> itemEscolhido >> quantidade)) {
            std::cout << "Entrada inválida! Tente novamente.\n";
            std::cin.clear();  // Limpa erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            --i;
            continue;
        }

        const std::vector<Item>& itensCardapio = cardapio.getItens();

        // Validar índice do item escolhido
        if (itemEscolhido <= 0 || itemEscolhido > itensCardapio.size()) {
            std::cout << "Item inválido! Tente novamente.\n";
            --i;
            continue;
        }

        // Selecionar o item
        const Item& itemSelecionado = itensCardapio[itemEscolhido - 1];

        // Verificar disponibilidade do item
        if (!itemSelecionado.estaDisponivel()) {
            char escolha;
            std::cout << "Desculpe, o item '" << itemSelecionado.nome << "' não está disponível.\n";
            std::cout << "Gostaria de tentar outro item (S) ou sair do pedido (N)? ";
            std::cin >> escolha;

            // Converter para maiúsculo para consistência
            escolha = std::toupper(escolha);

            if (escolha == 'N') {
                std::cout << "Pedido cancelado.\n";
                return;
            }

            // Caso contrário, repetir a iteração
            --i;
            continue;
        }

        // Validar quantidade
        if (quantidade <= 0) {
            std::cout << "A quantidade deve ser maior que zero.\n";
            --i;
            continue;
        }

         // Adicionar item ao pedido
        bool adicionaItem(const Item& item, int quantidade);
    }

    // Registrar o pedido
    pedido.registraPedido();
    std::cout << "Pedido realizado com sucesso!\n";
}
       
    
