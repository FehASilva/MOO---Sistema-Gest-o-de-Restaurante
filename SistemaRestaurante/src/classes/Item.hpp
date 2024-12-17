#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>

class Item {
public:
    std::string nome;
    std::string receita;
    std::vector<std::string> informacaoNutricional;

    Item(const std::string& nome, const std::string& receita, const std::vector<std::string>& info);

    bool estaDisponivel() const;
};

#endif // ITEM_HPP
