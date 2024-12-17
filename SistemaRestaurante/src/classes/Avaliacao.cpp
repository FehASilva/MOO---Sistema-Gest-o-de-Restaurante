#include "Avaliacao.hpp"
#include "Database.hpp"
#include <iomanip>
#include <sstream>

bool Avaliacao::criarAvaliacao(const FormularioDeAvaliacao& formulario) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << formulario.getNota();
    std::string notaFormatada = oss.str();

    // Criar os dados da avaliação
    std::vector<std::string> novaAvaliacao = {
        formulario.getNome(),
        formulario.getDescricao(),
        notaFormatada,
        formulario.getComentario()
    };

    // Salvar no arquivo CSV
    Database::saveCSV("../data/avaliacoes.csv", {novaAvaliacao});
    return true;
}
