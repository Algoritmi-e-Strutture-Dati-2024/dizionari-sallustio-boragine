#include <string>
#include "Dizionario.cpp"

int main() { 
    Dizionario<int> dizionario;//SVOLTO DA SALLUSTIO BACHIS BORAGINE

    dizionario.inserisci("mela", frutta);
    dizionario.inserisci("limone", frutta);
    dizionario.inserisci("mortadella", salato);
    dizionario.inserisci("baguette", salato);  
    dizionario.inserisci("tiramisu", dolce);     
    dizionario.stampa();

    std::cout << "Recupera 'limone': " << dizionario.recupera("limone") << std::endl;   
    dizionario.cancella("baguette");
    dizionario.stampa();

    
    std::cout << "Appartiene 'tiramisu': " << dizionario.appartiene("tiramisu") << std::endl;

    return 0;
}

