#include "astronauta.h"
#include <iostream>


Astronauta::Astronauta(std::string cpf, std::string nome, int idade)
    : cpf(cpf), nome(nome), idade(idade), disponivel(true) {}


Voo::Voo(int codigo) : codigo(codigo), estado("Planejado") {}

void Voo::adicionarPassageiro(Astronauta* astronauta) {
    passageiros.push_back(astronauta);
}

void Voo::removerPassageiro(std::string& cpf) {
    for (size_t i = 0; i < passageiros.size(); ++i) {
        if (passageiros[i]->cpf == cpf) {
            passageiros.erase(passageiros.begin() + i);
            break;
        }
    }
}


void cadastrarAstronauta(std::vector<Astronauta>& astronautas) {
    std::string cpf, nome;
    int idade;

    std::cout << "Digite o CPF do astronauta: ";
    std::cin >> cpf;

    std::cout << "Digite o nome do astronauta: ";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout << "Digite a idade do astronauta: ";
    std::cin >> idade;

    astronautas.emplace_back(cpf, nome, idade);
    std::cout << "Astronauta cadastrado com sucesso!";
}

void cadastrarVoo(std::vector<Voo>& voos) {
    int codigo;

    std::cout << "Digite o código do voo: ";
    std::cin >> codigo;

    voos.emplace_back(codigo);
    std::cout << "Voo cadastrado com sucesso!";
}

void adicionarAstronautaEmVoo(std::vector<Astronauta>& astronautas, std::vector<Voo>& voos) {
    std::string cpf;
    int codigoVoo;
    bool cpfEncontrado = false;
    bool vooEncontrado = false;

    do {
        std::cout << "Digite o CPF do astronauta: ";
        std::cin >> cpf;

        if (cpf == "0") {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& a : astronautas) {
            if (a.cpf == cpf) {
                cpfEncontrado = true;
                break;
            }
        }

        if (!cpfEncontrado) {
            std::cout << "CPF não encontrado.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!cpfEncontrado);

    Astronauta* astronauta = nullptr;
    for (auto& a : astronautas) {
        if (a.cpf == cpf) {
            astronauta = &a;
            break;
        }
    }

    do {
        std::cout << "Digite o código do voo: ";
        std::cin >> codigoVoo;

        if (codigoVoo == 0) {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& v : voos) {
            if (v.codigo == codigoVoo) {
                vooEncontrado = true;
                break;
            }
        }

        if (!vooEncontrado) {
            std::cout << "Código do voo não encontrado ou voo não está em planejamento.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!vooEncontrado);

    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v.codigo == codigoVoo) {
            voo = &v;
            break;
        }
    }

    if (astronauta && voo && voo->estado == "Planejado") {
        voo->adicionarPassageiro(astronauta);
        std::cout << "Astronauta " << astronauta->nome << " foi adicionado ao voo " << voo->codigo << ".\n";
    } else {
        std::cout << "Não foi possível adicionar o astronauta ao voo. Verifique as condições do voo.\n";
    }
}

void removerAstronautaDeVoo(std::vector<Voo>& voos) {
    std::string cpf;
    int codigoVoo;
    bool vooEncontrado = false;

    do {
        std::cout << "Digite o código do voo: ";
        std::cin >> codigoVoo;

        if (codigoVoo == 0) {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& v : voos) {
            if (v.codigo == codigoVoo) {
                vooEncontrado = true;
                break;
            }
        }

        if (!vooEncontrado) {
            std::cout << "Código do voo não encontrado ou voo não está em planejamento.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!vooEncontrado);

    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v.codigo == codigoVoo) {
            voo = &v;
            break;
        }
    }

    bool cpfEncontrado = false;
    do {
        std::cout << "Digite o CPF do astronauta a ser removido: ";
        std::cin >> cpf;

        if (cpf == "0") {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& a : voo->passageiros) {
            if (a->cpf == cpf) {
                cpfEncontrado = true;
                break;
            }
        }

        if (!cpfEncontrado) {
            std::cout << "CPF não encontrado no voo. Por favor, tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!cpfEncontrado);

    if (voo && voo->estado == "Planejado") {
        voo->removerPassageiro(cpf);
        std::cout << "Astronauta com CPF " << cpf << " foi removido do voo " << voo->codigo << ".\n";
    } else {
        std::cout << "Não foi possível remover o astronauta do voo. Verifique as condições do voo.\n";
    }
}

void lancarVoo(std::vector<Voo>& voos) {
    int codigoVoo;
    bool vooEncontrado = false;

    do {
        std::cout << "Digite o código do voo a ser lançado: ";
        std::cin >> codigoVoo;

        if (codigoVoo == 0) {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& v : voos) {
            if (v.codigo == codigoVoo) {
                vooEncontrado = true;
                break;
            }
        }

        if (!vooEncontrado) {
            std::cout << "Código do voo não encontrado ou voo já foi lançado.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!vooEncontrado);

    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v.codigo == codigoVoo) {
            voo = &v;
            break;
        }
    }

    if (voo && voo->estado == "Planejado" && !voo->passageiros.empty()) {
        voo->estado = "Em Curso";
        for (auto& a : voo->passageiros) {
            a->disponivel = false;
        }
        std::cout << "Voo " << voo->codigo << " foi lançado.\n";
    } else {
        std::cout << "Não foi possível lançar o voo. Verifique se o voo está em planejamento e se há pelo menos um astronauta.\n";
    }
}


void explodirVoo(std::vector<Voo>& voos, std::vector<Astronauta*>& astronautasMortos) {
    int codigoVoo;
    bool vooEncontrado = false;

    do {
        std::cout << "Digite o código do voo a ser explodido: ";
        std::cin >> codigoVoo;

        if (codigoVoo == 0) {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return; 
        }

        for (auto& v : voos) {
            if (v.codigo == codigoVoo) {
                vooEncontrado = true;
                break;
            }
        }

        if (!vooEncontrado) {
            std::cout << "Código do voo não encontrado ou voo não está em curso.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!vooEncontrado);

    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v.codigo == codigoVoo) {
            voo = &v;
            break;
        }
    }

    if (voo && voo->estado == "Em Curso") {
        voo->estado = "Finalizado com Falha";
        for (auto& a : voo->passageiros) {
            a->disponivel = false;
            astronautasMortos.push_back(a);
        }
        std::cout << "Voo " << voo->codigo << " explodiu. Todos os astronautas a bordo morreram.\n";
    } else {
        std::cout << "Não foi possível explodir o voo. Verifique se o voo está em curso.\n";
    }
}
void finalizarVoo(std::vector<Voo>& voos) {
    int codigoVoo;
    bool vooEncontrado = false;

    do {
        std::cout << "Digite o código do voo a ser finalizado: ";
        std::cin >> codigoVoo;

        if (codigoVoo == 0) {
            std::cout << "Operação cancelada. Voltando ao menu.\n";
            return;
        }

        for (auto& v : voos) {
            if (v.codigo == codigoVoo) {
                vooEncontrado = true;
                break;
            }
        }

        if (!vooEncontrado) {
            std::cout << "Código do voo não encontrado ou voo não está em curso.Tente novamente ou digite '0' para cancelar.\n";
        }
    } while (!vooEncontrado);

    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v.codigo == codigoVoo) {
            voo = &v;
            break;
        }
    }

    if (voo && voo->estado == "Em Curso") {
        voo->estado = "Finalizado com Sucesso";
        for (auto& a : voo->passageiros) {
            a->disponivel = true;
        }
        std::cout << "Voo " << voo->codigo << " foi finalizado com sucesso.\n";
    } else {
        std::cout << "Não foi possível finalizar o voo. Verifique se o voo está em curso.\n";
    }
}

void listarVoos(std::vector<Voo>& voos) {
        if (voos.empty()) {
        std::cout << "Nenhum voo foi encontrado.\n";
        return;
    }
    for (auto& voo : voos) {
        std::cout << "Voo " << voo.codigo << ": " << voo.estado << " - Astronautas: ";
        for (auto& astronauta : voo.passageiros) {
            std::cout << astronauta->nome << " ";
        }
        std::cout << std::endl;
    }
}

void listarAstronautasMortos(std::vector<Astronauta*>& astronautasMortos) {
        if (astronautasMortos.empty()) {
        std::cout << "Nenhum astronauta morto foi encontrado.\n";
        return;
    }
    std::cout << "Astronautas mortos:\n";
    for (auto& astronauta : astronautasMortos) {
        std::cout << "CPF: " << astronauta->cpf << ", Nome: " << astronauta->nome << std::endl;
    }
}
