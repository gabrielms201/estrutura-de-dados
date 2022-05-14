#ifndef PACIENTE_H
#define PACIENTE_H

#include <ostream>

using namespace std;
class Paciente
{
public:
    friend ostream &operator<<(ostream &os, const Paciente &paciente);

    // Construtores
    Paciente(unsigned short sexo, unsigned short tipoPaciente, unsigned short intubado, unsigned short pneumonia,
             unsigned short idade, unsigned short gravidez, unsigned short diabetes, unsigned short copd,
             unsigned short asma, unsigned short imunossupressao, unsigned short hipertensao,
             unsigned short outrasDoencas, unsigned short cardiovascular, unsigned short obesidade, unsigned short irc,
             unsigned short fumante, unsigned short outroCaso, unsigned short testeCovid, unsigned short icu,
             unsigned short obito);

    Paciente();

    // Getters
    unsigned short getSexo() const { return _sexo; }

    unsigned short getTipoPaciente() const { return _tipoPaciente; }

    unsigned short getIntubado() const { return _intubado; }

    unsigned short getPneumonia() const { return _pneumonia; }

    unsigned short getIdade() const { return _idade; }

    unsigned short getGravidez() const { return _gravidez; }

    unsigned short getDiabetes() const { return _diabetes; }

    unsigned short getCopd() const { return _copd; }

    unsigned short getAsma() const { return _asma; }

    unsigned short getImunossupressao() const { return _imunossupressao; }

    unsigned short getHipertensao() const { return _hipertensao; }

    unsigned short getOutrasDoencas() const { return _outrasDoencas; }

    unsigned short getCardiovascular() const { return _cardiovascular;}

    unsigned short getObesidade() const { return _obesidade; }

    unsigned short getIrc() const { return _irc; }

    unsigned short getFumante() const { return _fumante; }

    unsigned short getOutroCaso() const { return _outroCaso; }

    unsigned short getTesteCovid() const { return _testeCovid; }

    unsigned short getIcu() const { return _icu; }

    unsigned short getObito() const { return _obito; }

    // Setters
    void setSexo(unsigned short sexo) { _sexo = sexo; }

    void setTipoPaciente(unsigned short tipoPaciente) { _tipoPaciente = tipoPaciente; }

    void setIntubado(unsigned short intubado) { _intubado = intubado; }

    void setPneumonia(unsigned short pneumonia) { _pneumonia = pneumonia; }

    void setIdade(unsigned short idade) { _idade = idade; }

    void setGravidez(unsigned short gravidez) { _gravidez = gravidez; }

    void setDiabetes(unsigned short diabetes) { _diabetes = diabetes; }

    void setCopd(unsigned short copd) { _copd = copd; }

    void setAsma(unsigned short asma) { _asma = asma; }

    void setImunossupressao(unsigned short imunossupressao) { _imunossupressao = imunossupressao; }

    void setHipertensao(unsigned short hipertensao) { _hipertensao = hipertensao; }

    void setOutrasDoencas(unsigned short outrasDoencas) { _outrasDoencas = outrasDoencas; }

    void setCardiovascular(unsigned short cardiovascular) { _cardiovascular = cardiovascular; }

    void setObesidade(unsigned short obesidade) { _obesidade = obesidade; }

    void setIrc(unsigned short irc) { _irc = irc; }

    void setFumante(unsigned short fumante) { _fumante = fumante; }

    void setOutroCaso(unsigned short outroCaso) { _outroCaso = outroCaso; }

    void setTesteCovid(unsigned short testeCovid) { _testeCovid = testeCovid; }

    void setIcu(unsigned short icu) { _icu = icu; }

    void setObito(unsigned short obito) { _obito = obito; }

    // Comparators
    bool operator==(const Paciente& p) const;

    bool operator!=(const Paciente& p) const;

private:
    unsigned short _sexo;
    unsigned short _tipoPaciente;
    unsigned short _intubado;
    unsigned short _pneumonia;
    unsigned short _idade;
    unsigned short _gravidez;
    unsigned short _diabetes;
    unsigned short _copd;
    unsigned short _asma;
    unsigned short _imunossupressao;
    unsigned short _hipertensao;
    unsigned short _outrasDoencas;
    unsigned short _cardiovascular;
    unsigned short _obesidade;
    unsigned short _irc;
    unsigned short _fumante;
    unsigned short _outroCaso;
    unsigned short _testeCovid;
    unsigned short _icu;
    unsigned short _obito;

};

#endif