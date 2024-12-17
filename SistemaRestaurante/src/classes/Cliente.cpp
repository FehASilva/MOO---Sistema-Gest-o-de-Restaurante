// Arquivo: src/classes/Cliente.cpp
#include "Cliente.hpp"
#include "Database.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool Cliente::consultarUsuario(const std::string& nome) {
    // Carregar todos os dados do arquivo clientes.csv
    auto data = Database::loadCSV("../data/clientes.csv");

    // Procurar pelo nome do cliente
    for (const auto& row : data) {
        if (row.size() >= 2 && row[0] == nome) {
            this->nome = row[0];  // Definindo o nome do cliente
            this->senha = row[1];  // Definindo a senha
            this->contato = row[2];  // Definindo o contato
            this->endereco = row[3];  // Definindo o endereço
            return true;
        }
    }
    return false;  // Se o nome não for encontrado
}

bool Cliente::validarSenha(const std::string& senha) {
    return this->senha == senha;  // Verifica se a senha está correta
}

bool Cliente::solicitarReserva(const std::string& nome) {
    // Lógica de reserva 
    return true;
}

std::vector<std::string> Cliente::solicitarConsultaReserva(const std::string& nome) {
    // Lógica para consultar reservas
    std::vector<std::string> reservas;
    // Retorna um vetor de reservas fictícias para exemplo
    reservas.push_back("Reserva 1");
    reservas.push_back("Reserva 2");
    return reservas;
}
