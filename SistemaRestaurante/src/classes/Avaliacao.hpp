#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include "FormularioDeAvaliacao.hpp"
#include <string>

class Avaliacao {
private:
    std::string cliente;
    std::string dataHora;
    float nota;
    std::string comentario;

public:
    Avaliacao(const std::string& cliente, const std::string& dataHora, float nota, const std::string& comentario)
        : cliente(cliente), dataHora(dataHora), nota(nota), comentario(comentario) {}

    bool criarAvaliacao(const FormularioDeAvaliacao& formulario);
};

#endif // AVALIACAO_HPP
