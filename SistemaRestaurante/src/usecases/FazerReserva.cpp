#include "../classes/Cliente.hpp"
#include "../classes/Reserva.hpp"
#include <iostream>

void fazerReserva() {
    std::string nome, senha, dataHora;
    int qtdPessoas;

    // Login do cliente
    Cliente cliente("", "", "", "");
    std::cout << "Digite seu nome: ";
    std::cin >> nome;

    if (!cliente.consultarUsuario(nome)) {
        std::cout << "Usuário não encontrado.\n";
        return;
    }

    std::cout << "Digite sua senha: ";
    std::cin >> senha;

    if (!cliente.validarSenha(senha)) {
        std::cout << "Senha incorreta.\n";
        return;
    }

    // Solicitar detalhes da reserva
    std::cout << "Número de pessoas: ";
    std::cin >> qtdPessoas;

    std::cout << "Data e hora (YYYY-MM-DD HH:MM): ";
    std::cin.ignore(); // Limpa o buffer de entrada
    std::getline(std::cin, dataHora);

    // Criar a reserva
    if (!Reserva::criarReserva(qtdPessoas, nome, dataHora)) {
        std::cout << "Erro ao criar a reserva.\n";
    }
}
