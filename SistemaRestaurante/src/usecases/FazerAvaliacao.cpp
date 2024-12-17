#include "../classes/FormularioDeAvaliacao.hpp"
#include "../classes/Avaliacao.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

void fazerAvaliacao() {
    std::string nome, descricao, comentario;
    float nota;

    // Obter os dados do cliente
    std::cout << "Informe seu nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Descreva o serviço avaliado: ";
    std::getline(std::cin, descricao);

    std::cout << "Informe sua nota (0-5): ";
    std::cin >> nota;

    std::cout << "Faça um comentário: ";
    std::cin.ignore();
    std::getline(std::cin, comentario);

    // Criar o formulário de avaliação
    FormularioDeAvaliacao formulario(0, nome, descricao, nota, comentario);

    if (!formulario.criarFormulario(nome, descricao, nota, comentario)) {
        std::cout << "Erro ao criar o formulário de avaliação.\n";
        return;
    }

    // Obter a data/hora atual
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M");
    std::string dataHora = oss.str();

    // Criar e salvar a avaliação
    Avaliacao avaliacao(nome, dataHora, nota, comentario);
    if (avaliacao.criarAvaliacao(formulario)) {
        std::cout << "Avaliação registrada com sucesso!\n";
    } else {
        std::cout << "Erro ao registrar a avaliação.\n";
    }
}
