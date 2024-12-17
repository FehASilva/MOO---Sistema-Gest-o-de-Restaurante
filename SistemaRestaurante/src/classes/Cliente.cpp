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
    // Carregar todas as reservas do arquivo reservas.csv
    auto reservas = Database::loadCSV("../data/reservas.csv");

    std::vector<std::string> reservasDoCliente;
    
    // Buscar as reservas feitas pelo cliente
    for (const auto& reserva : reservas) {
        if (reserva.size() >= 5 && reserva[1] == nome && reserva[4] == "true") {
            std::string reservaInfo = "Reserva ID: " + reserva[0] + " | " 
                                    + "Data/Hora: " + reserva[3] + " | " 
                                    + "Pessoas: " + reserva[2];
            reservasDoCliente.push_back(reservaInfo);
        }
    }

    return reservasDoCliente;  // Retorna as reservas encontradas
}
