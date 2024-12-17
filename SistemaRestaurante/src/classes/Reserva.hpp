#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>

class Reserva {
private:
    int idReserva;
    std::string nomeCliente;
    int quantidadePessoas;
    std::string dataHora;
    bool status;

public:
    Reserva(int id, const std::string& cliente, int qtdPessoas, const std::string& data, bool status)
        : idReserva(id), nomeCliente(cliente), quantidadePessoas(qtdPessoas), dataHora(data), status(status) {}

    static bool criarReserva(int qtdPessoas, const std::string& cliente, const std::string& dataHora);
    static bool mesaDisponivel(int qtdPessoas);
};

#endif // RESERVA_HPP
