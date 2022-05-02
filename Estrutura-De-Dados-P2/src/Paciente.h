#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente
{
public:
    // Getters
    unsigned short getSexo() const { return _Sexo; }

    unsigned short getTipoPaciente() const { return _TipoPaciente; }

    unsigned short getIntubado() const { return _Intubado; }

    unsigned short getPneumonia() const { return _Pneumonia; }

    unsigned short getIdade() const { return _Idade; }

    unsigned short getGravidez() const { return _Gravidez; }

    unsigned short getDiabetes() const { return _Diabetes; }

    unsigned short getCopd() const { return _Copd; }

    unsigned short getAsma() const { return _Asma; }

    unsigned short getImunossupressao() const { return _Imunossupressao; }

    unsigned short getHipertensao() const { return _Hipertensao; }

    unsigned short getOutrasDoencas() const { return _OutrasDoencas; }

    unsigned short getCardiovascular() const { return _Cardiovascular;}

    unsigned short getObesidade() const { return _Obesidade; }

    unsigned short getIrc() const { return _Irc; }

    unsigned short getFumante() const { return _Fumante; }

    unsigned short getOutroCaso() const { return _OutroCaso; }

    unsigned short getTesteCovid() const { return _TesteCovid; }

    unsigned short getIcu() const { return _Icu; }

    unsigned short getObito() const { return _Obito; }

    // Setters
    void setSexo(unsigned short sexo) { _Sexo = sexo; }

    void setTipoPaciente(unsigned short tipoPaciente) { _TipoPaciente = tipoPaciente; }

    void setIntubado(unsigned short intubado) { _Intubado = intubado; }

    void setPneumonia(unsigned short pneumonia) { _Pneumonia = pneumonia; }

    void setIdade(unsigned short idade) { _Idade = idade; }

    void setGravidez(unsigned short gravidez) { _Gravidez = gravidez; }

    void setDiabetes(unsigned short diabetes) { _Diabetes = diabetes; }

    void setCopd(unsigned short copd) { _Copd = copd; }

    void setAsma(unsigned short asma) { _Asma = asma; }

    void setImunossupressao(unsigned short imunossupressao) { _Imunossupressao = imunossupressao; }

    void setHipertensao(unsigned short hipertensao) { _Hipertensao = hipertensao; }

    void setOutrasDoencas(unsigned short outrasDoencas) { _OutrasDoencas = outrasDoencas; }

    void setCardiovascular(unsigned short cardiovascular) { _Cardiovascular = cardiovascular; }

    void setObesidade(unsigned short obesidade) { _Obesidade = obesidade; }

    void setIrc(unsigned short irc) { _Irc = irc; }

    void setFumante(unsigned short fumante) { _Fumante = fumante; }

    void setOutroCaso(unsigned short outroCaso) { _OutroCaso = outroCaso; }

    void setTesteCovid(unsigned short testeCovid) { _TesteCovid = testeCovid; }

    void setIcu(unsigned short icu) { _Icu = icu; }

    void setObito(unsigned short obito) { _Obito = obito; }


private:
    unsigned short _Sexo;
    unsigned short _TipoPaciente;
    unsigned short _Intubado;
    unsigned short _Pneumonia;
    unsigned short _Idade;
    unsigned short _Gravidez;
    unsigned short _Diabetes;
    unsigned short _Copd;
    unsigned short _Asma;
    unsigned short _Imunossupressao;
    unsigned short _Hipertensao;
    unsigned short _OutrasDoencas;
    unsigned short _Cardiovascular;
    unsigned short _Obesidade;
    unsigned short _Irc;
    unsigned short _Fumante;
    unsigned short _OutroCaso;
    unsigned short _TesteCovid;
    unsigned short _Icu;
    unsigned short _Obito;

};

#endif