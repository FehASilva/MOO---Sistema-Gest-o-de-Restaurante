#include "FormularioDeAvaliacao.hpp"
#include <iostream>

bool FormularioDeAvaliacao::criarFormulario(const std::string& nome, const std::string& descricao, float nota, const std::string& comentario) {
    if (nota < 0.0 || nota > 5.0) {
        std::cout << "Erro: a nota deve estar entre 0 e 5.\n";
        return false;
    }

    this->nome = nome;
    this->descricao = descricao;
    this->nota = nota;
    this->comentario = comentario;
    std::cout << "Formulário criado com sucesso.\n";

    return true;
}

bool FormularioDeAvaliacao::gerarAvaliacao(int id) {
    std::cout << "Gerando avaliação com base no formulário #" << id << ".\n";
    return true;
}
