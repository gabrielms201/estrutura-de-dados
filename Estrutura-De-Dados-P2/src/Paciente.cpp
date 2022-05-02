#include "Paciente.h"

Paciente::Paciente(unsigned short sexo, unsigned short tipoPaciente, unsigned short intubado, unsigned short pneumonia,
                   unsigned short idade, unsigned short gravidez, unsigned short diabetes, unsigned short copd,
                   unsigned short asma, unsigned short imunossupressao, unsigned short hipertensao,
                   unsigned short outrasDoencas, unsigned short cardiovascular, unsigned short obesidade,
                   unsigned short irc, unsigned short fumante, unsigned short outroCaso, unsigned short testeCovid,
                   unsigned short icu, unsigned short obito)
                   : _sexo(sexo), _tipoPaciente(tipoPaciente),
                     _intubado(intubado), _pneumonia(pneumonia),
                     _idade(idade), _gravidez(gravidez), _diabetes(diabetes),
                     _copd(copd), _asma(asma),
                     _imunossupressao(imunossupressao),
                     _hipertensao(hipertensao), _outrasDoencas(outrasDoencas),
                     _cardiovascular(cardiovascular), _obesidade(obesidade),
                     _irc(irc), _fumante(fumante), _outroCaso(outroCaso),
                     _testeCovid(testeCovid), _icu(icu), _obito(obito)
{}

bool Paciente::operator==(const Paciente &p) const
{
    return _sexo == p._sexo &&
           _tipoPaciente == p._tipoPaciente &&
           _intubado == p._intubado &&
           _pneumonia == p._pneumonia &&
           _idade == p._idade &&
           _gravidez == p._gravidez &&
           _diabetes == p._diabetes &&
           _copd == p._copd &&
           _asma == p._asma &&
           _imunossupressao == p._imunossupressao &&
           _hipertensao == p._hipertensao &&
           _outrasDoencas == p._outrasDoencas &&
           _cardiovascular == p._cardiovascular &&
           _obesidade == p._obesidade &&
           _irc == p._irc &&
           _fumante == p._fumante &&
           _outroCaso == p._outroCaso &&
           _testeCovid == p._testeCovid &&
           _icu == p._icu &&
           _obito == p._obito;
}

bool Paciente::operator!=(const Paciente &p) const
{
    return !(p == *this);
}

Paciente::Paciente()
{}

std::ostream &operator<<(std::ostream &os, const Paciente &paciente)
{
    os << "Sexo: " << paciente._sexo << " TipoPaciente: " << paciente._tipoPaciente << " Intubado: "
       << paciente._intubado << " Pneumonia: " << paciente._pneumonia << " Idade: " << paciente._idade
       << " Gravidez: " << paciente._gravidez << " Diabetes: " << paciente._diabetes << " Copd: " << paciente._copd
       << " Asma: " << paciente._asma << " Imunossupressao: " << paciente._imunossupressao << " Hipertensao: "
       << paciente._hipertensao << " OutrasDoencas: " << paciente._outrasDoencas << " Cardiovascular: "
       << paciente._cardiovascular << " Obesidade: " << paciente._obesidade << " Irc: " << paciente._irc
       << " Fumante: " << paciente._fumante << " OutroCaso: " << paciente._outroCaso << " TesteCovid: "
       << paciente._testeCovid << " Icu: " << paciente._icu << " Obito: " << paciente._obito;
    return os;
}



