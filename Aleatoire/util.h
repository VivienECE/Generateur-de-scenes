///Fichier donn� par Mr.Fercoq dans les TP
///+Ajout graine mt...
///DETOURNAY-HILT-PICHON

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <string>
#include <random>

namespace util
{

/// L'appel de cette fonction redirige les
/// donn�es du fichier dont le nom est pass�
/// en param�tre vers std::cin
/// On "simule" les frappes clavier ce qui
/// permet de tester sans avoir � retaper
/// � chaque fois les m�me donn�es
/// temporisation : nombre de milliseconde entre chaque frappe clavier
/// couleur : colorisation (WINDOWS seulement https://ss64.com/nt/color.html
///                         pr�fixer par 0x, exemple 0x1a vert sur Fond bleu)
void startAutoCin(std::string fileName, size_t temporisation=0, short couleur=0);

/// Cette fonction doit �tre appel�e pour
/// terminer la saisie automatique et retrouver
/// un comportement normal (saisir au clavier)
void stopAutoCin();

/// Vide tampon clavier
void videCin();

/// Cette fonction retourne un entier al�atoire dans [min...max]
double alea(int min, int max);
int alea(int min, int max, std::mt19937& randGen);
double alea(double min, double max, std::mt19937& randGen);
size_t alea(size_t min, size_t max, std::mt19937& randGen);
unsigned int alea(unsigned int min, unsigned int max, std::mt19937& randGen);

/// Le code qui suit est sp�cifique aux plateformes Windows
/// et ne concerne ni macOS ni les Linux
#ifdef _WIN32
void accentsPourWindows();
#endif // _WIN32

}


#endif // UTIL_H_INCLUDED
