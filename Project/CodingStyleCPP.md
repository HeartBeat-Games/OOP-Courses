# Convention de style C++

## 1. Indentation et mise en forme

- Utiliser **4 espaces** par niveau d'indentation.
- Placer les accolades ouvrantes et fermantes sur des lignes séparées.
- Ajouter un espace autour des opérateurs (`=`, `+`, `-`, `==`, `<`, etc.).
- Ajouter un espace après les virgules.
- Ne pas ajouter d'espace avant un point-virgule.
- Limiter les lignes à **90 caractères**.
- Limiter les fonction à **25 lignes**.
- Aligner les accolades ouvrantes et fermantes.

```cpp
if (age >= 18)
{
    afficherMessage("Majeur", age);
}
```

## 2. Nommage

| Élément | Convention | Exemple |
|---|---|---|
| Variables | `camelCase` | `nombreEtudiants` |
| Fonctions | `camelCase` | `calculerMoyenne()` |
| Classes | `PascalCase` | `GestionnaireEtudiants` |
| Structures | `PascalCase` | `Point` |
| Constantes | `UPPER_SNAKE_CASE` | `NOMBRE_MAX` |
| Paramètres | `camelCase` | `prixTotal` |

- Utiliser des noms explicites.
- Éviter les abréviations non conventionnelles.
- Utiliser des noms en français ou en anglais, sans mélanger les deux.
- Écrire les noms sans accents.

## 3. Variables et constantes

- Déclarer une variable par ligne.
- Initialiser les variables lors de leur déclaration.
- Déclarer les variables au plus près de leur utilisation.
- Utiliser `const` pour les variables non modifiables.
- Utiliser `constexpr` pour les constantes évaluables à la compilation.

```cpp
int age = 20;
double moyenne = 15.5;
const int NOMBRE_MAX = 30;
```

## 4. Conditions et boucles

- Toujours utiliser des accolades, même pour une seule instruction.
- Placer `else` sur la même ligne que l'accolade fermante du bloc précédent.
- Ajouter un espace après `if`, `for`, `while` et `switch`.
- Utiliser `++i` plutôt que `i++` lorsque la valeur précédente n'est pas nécessaire.

```cpp
if (condition)
{
    instruction();
}
else
{
    autreInstruction();
}

for (int i = 0; i < 10; ++i)
{
    afficher(i);
}
```

## 5. Fonctions

- Utiliser le `camelCase`.
- Séparer les fonctions par une ligne vide.
- Placer l'accolade ouvrante sur une nouvelle ligne.
- Placer le type de retour, le nom et les paramètres sur la même ligne.
```cpp
double calculerMoyenne(double somme, int nombre)
{
    return somme / nombre;
}
```

## 6. Classes et structures

- Utiliser le `PascalCase` pour les noms.
- Placer les accolades sur des lignes séparées.
- Indenter les membres de 4 espaces.
- Respecter l'ordre suivant : `public`, `protected`, `private`.
- Aligner les groupes de variables et de fonctions membres.

```cpp
class Etudiant
{
public:
    void afficherNom();

private:
    std::string nom;
    int         age;
};
```

## 7. Commentaires

- Utiliser `//` pour les commentaires courts.
- Utiliser `/* ... */` pour les commentaires sur plusieurs lignes.
- Placer les commentaires sur une ligne séparée au-dessus du code concerné.
- Rédiger les commentaires dans la même langue que le reste du projet.

```cpp
// Calcule la moyenne des notes.
double calculerMoyenne();
```

## 8. Organisation des fichiers

- Utiliser `.h` ou `.hpp` pour les fichiers d'en-tête.
- Utiliser `.cpp` pour les fichiers source.
- Placer les directives `#include` au début du fichier.
- Regrouper les inclusions dans l'ordre suivant :
  1. En-têtes correspondants au fichier source.
  2. Bibliothèque standard.
  3. Bibliothèques externes.
  4. En-têtes du projet.

```cpp
#include "Etudiant.h"

#include <iostream>
#include <string>

#include "Gestionnaire.h"
```

## 9. Espaces de noms

- Préfixer les éléments de la bibliothèque standard par `std::`.
- Ne pas utiliser `using namespace std;`.
- Utiliser `namespace fs = std::filesystem;` pour réduire les namespaces trop long.

```cpp
std::string nom = "Alice";
std::cout << nom << '\n';
```

## 10. Espaces et lignes vides

- Ajouter une ligne vide entre les fonctions.
- Ajouter une ligne vide entre les grandes sections d'une fonction.
- Ne pas multiplier les lignes vides consécutives.
- Ne pas ajouter d'espaces en fin de ligne.
- Ne pas placer plusieurs instructions sur une même ligne.

**Convention générale :** appliquer les mêmes règles de formatage à tous les fichiers du projet.