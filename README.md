# libft

Ceci est le premier projet que j'ai effectué à l'école 42, il consiste à réécrire quelques fonctions de la libc ainsi l'ajout de fonction personnalisé demandé par le sujet.

## Installation

### Prérequis

- Un compilateur C compatible (par exemple, `gcc`).
- `make` pour la compilation

### Installation à partir des sources

- Clonez le dépôt :

  ```bash
  git clone git@github.com:raphifou15/libft.git
  cd libft
  make
  ```

  Cela générera un fichier libft.a dans le répertoire.

### Utilisation

- Incluez le fichier d'en-tête libft.h dans vos fichiers source C:

  ```
  gcc "file.c" -L" path to libft" libft.a
  ```

  Exemple

  ```
  #include "libft.h"

  int main() {
  // Utilisez les fonctions de libft ici
  return 0;
  }
  ```

- utiliser les fonction de la partie bonus en faisant

  ```
  make bonus
  ```
