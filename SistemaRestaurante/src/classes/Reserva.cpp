#include "Reserva.hpp"
#include "Database.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

bool Reserva::mesaDisponivel(int qtdPessoas) {
    auto mesas = Database::loadCSV("../data/mesas.csv");

    for (const auto& mesa : mesas) {
        if (mesa.size() >= 3 && mesa[1] == "true" && std::stoi(mesa[2]) >= qtdPessoas) {
            return true; // Há pelo menos uma mesa disponível
        }
    }
    return false; // Nenhuma mesa disponível
}

bool Reserva::criarReserva(int qtdPessoas, const std::string& cliente, const std::string& dataHora) {
    // Carregar reservas existentes
    auto reservas = Database::loadCSV("../data/reservas.csv");

    // Converter a dataHora da nova reserva para um formato comparável
    std::tm novaData = {};
    std::istringstream ssNovaData(dataHora);
    ssNovaData >> std::get_time(&novaData, "%Y-%m-%d %H:%M");
    time_t novaTimestamp = std::mktime(&novaData);

    if (novaTimestamp == -1) {
        std::cout << "Erro: formato de data/hora inválido." << std::endl;
        return false;
    }

    // Verificar conflitos com reservas existentes
    for (const auto& reserva : reservas) {
        if (reserva.size() >= 4) {
            std::tm dataExistente = {};
            std::istringstream ssDataExistente(reserva[3]);
            ssDataExistente >> std::get_time(&dataExistente, "%Y-%m-%d %H:%M");
            time_t existenteTimestamp = std::mktime(&dataExistente);

            if (std::difftime(novaTimestamp, existenteTimestamp) < 3600 && std::difftime(novaTimestamp, existenteTimestamp) > -3600) {
                std::cout << "Erro: conflito com outra reserva." << std::endl;
                return false;
            }
        }
    }

    // Verificar disponibilidade de mesas
    if (!mesaDisponivel(qtdPessoas)) {
        std::cout << "Nenhuma mesa disponível para o número de pessoas solicitado." << std::endl;
        return false;
    }

    // Gerar ID da reserva
    int idReserva = reservas.size() + 1;

    // Adicionar nova reserva
    std::vector<std::string> novaReserva = {
        std::to_string(idReserva),
        cliente,
        std::to_string(qtdPessoas),
        dataHora,
        "true"
    };
    reservas.push_back(novaReserva);
    Database::saveCSV("../data/reservas.csv", {novaReserva}); // Salva apenas a nova reserva no fim do arquivo

    std::cout << "Reserva criada com sucesso!" << std::endl;
    return true;
}
