#include <iostream>
#include "usecases/VerCardapio.hpp"
#include "usecases/FazerPedido.hpp"
#include "usecases/FazerReserva.hpp"
#include "usecases/ConsultaReserva.hpp"
#include "usecases/FazerAvaliacao.hpp"


int main() {
    int escolha;
    do {
        std::cout << "==============================\n";
        std::cout << "Sistema do Restaurante\n";
        std::cout << "1. Ver cardápio\n";
        std::cout << "2. Fazer Pedido\n";
        std::cout << "3. Fazer Reserva\n";
        std::cout << "4. Verificar Reservas\n";
        std::cout << "5. Fazer Avaliação\n";
        std::cout << "0. Sair\n";
        
        std::cout << "==============================\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                VerCardapio();
                break;
            case 2:
                FazerPedido();
                break;
            case 3:
                fazerReserva();
                break;
            case 4:
                realizarConsultaReserva();
                break;
            case 5:
                fazerAvaliacao();
                break;
            case 0:
                std::cout << "Saindo do sistema. Até logo!\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (escolha != 0);

    return 0;
}
