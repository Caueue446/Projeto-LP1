#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <vector>
#include <string>

class Astronauta {
public:
    std::string cpf;
    std::string nome;
    int idade;
    bool disponivel;

    Astronauta(std::string cpf, std::string nome, int idade);
};

class Voo {
public:
    int codigo;
    std::string estado;
    std::vector<Astronauta*> passageiros;

    Voo(int codigo);

    void adicionarPassageiro(Astronauta* astronauta);
    void removerPassageiro(std::string& cpf);
};

void cadastrarAstronauta(std::vector<Astronauta>& astronautas);
void cadastrarVoo(std::vector<Voo>& voos);
void adicionarAstronautaEmVoo(std::vector<Astronauta>& astronautas, std::vector<Voo>& voos);
void removerAstronautaDeVoo(std::vector<Voo>& voos);
void lancarVoo(std::vector<Voo>& voos);
void explodirVoo(std::vector<Voo>& voos, std::vector<Astronauta*>& astronautasMortos);
void finalizarVoo(std::vector<Voo>& voos);
void listarVoos(std::vector<Voo>& voos);
void listarAstronautasMortos(std::vector<Astronauta*>& astronautasMortos);

#endif
