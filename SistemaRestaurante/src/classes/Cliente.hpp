// Arquivo: src/classes/Cliente.hpp
#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>
#include "Database.hpp"

class Cliente {
private:
    std::string nome;
    std::string senha;
    std::string contato;
    std::string endereco;

public:
    Cliente(const std::string& nome, const std::string& senha, const std::string& contato, const std::string& endereco)
        : nome(nome), senha(senha), contato(contato), endereco(endereco) {}

    // Métodos
    bool consultarUsuario(const std::string& nome);
    bool validarSenha(const std::string& senha);
    bool solicitarReserva(const std::string& nome);
    std::vector<std::string> solicitarConsultaReserva(const std::string& nome);
};

#endif // CLIENTE_HPP
