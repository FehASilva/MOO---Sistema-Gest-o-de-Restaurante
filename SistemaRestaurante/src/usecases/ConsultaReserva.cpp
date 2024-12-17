#include "ConsultaReserva.hpp"
#include "../classes/Cliente.hpp"
#include "../classes/Reserva.hpp"
#include <iostream>
#include <string>

void realizarConsultaReserva() {
    std::string nome, senha;
    
    // Identificação do cliente
    std::cout << "Digite seu nome: ";
    std::cin >> nome;
    
    // Criar uma instância da classe Cliente
    Cliente cliente(nome, senha, "", "");
    
    // Verificar se o cliente existe
    if (!cliente.consultarUsuario(nome)) {
        std::cout << "Cliente não encontrado.\n";
        return;
    }
    
    // Validar senha
    std::cout << "Digite sua senha: ";
    std::cin >> senha;
    
    if (!cliente.validarSenha(senha)) {
        std::cout << "Senha incorreta.\n";
        return;
    }

    // Consultar as reservas do cliente
    std::vector<std::string> reservas = cliente.solicitarConsultaReserva(nome);
    
    if (reservas.empty()) {
        std::cout << "Nenhuma reserva encontrada para o cliente " << nome << ".\n";
    } else {
        std::cout << "Reservas de " << nome << ":\n";
        for (const auto& reserva : reservas) {
            std::cout << reserva << std::endl;
        }
    }
}
