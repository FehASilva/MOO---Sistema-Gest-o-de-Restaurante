#ifndef MESA_HPP
#define MESA_HPP

class Mesa {
private:
    bool status; // Disponível ou não
    int numeroDeCadeiras;

public:
    Mesa(bool status, int cadeiras) : status(status), numeroDeCadeiras(cadeiras) {}

    bool statusDaMesa();
    int tamanhoDaMesa() const { return numeroDeCadeiras; }
};

#endif // MESA_HPP
