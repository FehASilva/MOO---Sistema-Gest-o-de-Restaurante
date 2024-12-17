#ifndef FORMULARIO_DE_AVALIACAO_HPP
#define FORMULARIO_DE_AVALIACAO_HPP

#include <string>

class FormularioDeAvaliacao {
private:
    int id;
    std::string nome;
    std::string descricao;
    float nota;
    std::string comentario;

public:
    FormularioDeAvaliacao(int id, const std::string& nome, const std::string& descricao, float nota, const std::string& comentario)
        : id(id), nome(nome), descricao(descricao), nota(nota), comentario(comentario) {}

    // Métodos
    bool criarFormulario(const std::string& nome, const std::string& descricao, float nota, const std::string& comentario);
    bool gerarAvaliacao(int id);
    
    // Getters 
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getDescricao() const { return descricao; }
    float getNota() const { return nota; }
    std::string getComentario() const { return comentario; }
};

#endif // FORMULARIO_DE_AVALIACAO_HPP
