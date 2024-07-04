#include <iostream>
#include <vector>
#include "astronauta.h"

int main() {
    std::vector<Astronauta> astronautas;
    std::vector<Voo> voos;
    std::vector<Astronauta*> astronautasMortos;

    int opcao;
    char continuar;
    bool finalizado = false;

    do {
        std::cout << "\nSistema de Gestão de atronautas e Voos espaciais\n";
        std::cout << "1. Cadastrar Astronauta\n";
        std::cout << "2. Cadastrar Voo\n";
        std::cout << "3. Adicionar Astronauta em Voo\n";
        std::cout << "4. Remover Astronauta de Voo\n";
        std::cout << "5. Lançar Voo\n";
        std::cout << "6. Explodir Voo\n";
        std::cout << "7. Finalizar Voo\n";
        std::cout << "8. Listar Voos\n";
        std::cout << "9. Listar Astronautas Mortos\n";
        std::cout << "0. Sair\n";
        std::cout << "\nSe desistir da operação em qualquer momento digite 0 para retornar ao menu (não funciona se tiver cadastrando Astronauta ou Voo)\n";
        std::cout << "\nEscolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAstronauta(astronautas);
                break;
            case 2:
                cadastrarVoo(voos);
                break;
            case 3:
                adicionarAstronautaEmVoo(astronautas, voos);
                break;
            case 4:
                removerAstronautaDeVoo(voos);
                break;
            case 5:
                lancarVoo(voos);
                break;
            case 6:
                explodirVoo(voos, astronautasMortos);
                break;
            case 7:
                finalizarVoo(voos);
                break;
            case 8:
                listarVoos(voos);
                break;
            case 9:
                listarAstronautasMortos(astronautasMortos);
                break;
            case 0:
                finalizado = true;
                continuar = 'n';
                break;
            default:
                std::cout << "Opção inválida! Digite outra opção de 1 a 9, ou 0 para finalizar o programa.\n";
        }

        if(finalizado == false){

        std::cout << "\nContinuar no programa? (s/n) ";
        std::cin >> continuar;
        }
    } while (continuar == 's' || continuar == 'S');
    if (continuar == 'n' || continuar == 'N' ){
        std::cout << "Finalizando Programa...\n";
    }


    return 0;
}