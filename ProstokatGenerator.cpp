#include "ProstokatGenerator.h"
#include <cmath> // For fmod

ProstokatGenerator::ProstokatGenerator(SygnalGenerator *dekorowanySygnal, double amplituda, double czestotliwosc, double wypelnienie)
    : SygnalDekorator(dekorowanySygnal), m_amplituda(amplituda), m_czestotliwosc(czestotliwosc), m_wypelnienie(wypelnienie), m_czas(0.0)
{
    if (m_czestotliwosc > 0)
    {
        m_okres = 1.0 / m_czestotliwosc;
    }
    else
    {
        m_okres = 0.0;
    }
}

double ProstokatGenerator::generuj(double t)
{
    double okres = 1.0 / m_czestotliwosc;
    double czas_w_okresie = fmod(t, okres);
    double wartosc = (czas_w_okresie < m_wypelnienie * okres) ? m_amplituda : -m_amplituda;
    return SygnalDekorator::generuj(t) + wartosc;
}
