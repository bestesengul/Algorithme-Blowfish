# Algorithme Chiffrement de Blowfish


## Tableau de Contenu

- [Tableau de Contenu](#_Toc92625930)

- [Introduction](#_Toc92625931)

  - [But de Projet](#_Toc92625932)

  - [Cryptage des Données](#_Toc92625933)

  - [Technologies Utilisées](#_Toc92625934)

- [Algorithme Blowfish](#_Toc92625935)

  - [Notion de Algorithme de Chiffrement Blowfish](#_Toc92625936)

  - [Applications du Monde Réel de Blowfish](#_Toc92625937)

    - [Gestion des mots de passe](#_Toc92625938)

    - [Cryptage de fichiers/disques](#_Toc92625939)

    - [Outils de sauvegarde](#_Toc92625940)

    - [Cryptage des courriels](#_Toc92625941)

    - [Secure Shell (SSH)](#_Toc92625942)

    - [Architecture du Project](#_Toc92625943)

- [Processus du Projet](#_Toc92625944)

  - [Structure de Code](#_Toc92625945)

  - [Processus de débogage](#_Toc92625946)

  - [Première Partie : La Nettoyage des Données](#_Toc92625947)

    - [Système de Fichier &amp; Coup d&#39;œil à Jeu de Données](#_Toc92625948)

    - [Compilation du programme &amp; Interface Utilisateur](#_Toc92625949)

  - [Deuxième Partie : Le Chiffrement &amp; Application de Chiffrement de Message](#_Toc92625950)

    - [Structure Employée](#_Toc92625951)

    - [Fonctions (BLOWFISH.H)](#_Toc92625952)

- [Résultats](#_Toc92625953)

  - [Cryptanalyse du Blowfish](#_Toc92625954)

  - [Efficacité du Blowfish](#_Toc92625955)

  - [Conclusion &amp; Travaux Futur](#_Toc92625956)

  - [Améliorations de Algorithme de Chiffrement](#_Toc92625957)

- [Ressources](#_Toc92625958)

## _Introduction_

#### But de Projet

- Définir le cryptage des données,
- Analyser l&#39;algorithme de chiffrement Blowfish techniquement et historiquement
- Observer ses applications du monde réel,
- Etudier sa cryptanalyse,
- Examiner son efficacité en le comparant avec les autres algorithmes de chiffrement,
- Mettre en œuvre l&#39;une de ses applications du monde réel – chiffrement de message
- Discuter ses améliorations et ses travaux futur

#### Cryptage des Données

Le chiffrement désigne la conversion des données depuis un format lisible dans un format codé. Cela nous aide à ainsi traiter et stocker des données en toute sécurité en préservant leur confidentialité et intégrité et échanger sans risque des clés et du texte crypté dans des messages. Puisque le chiffrement est le moyen le plus simple et le plus efficace de s&#39;assurer que les informations du système informatique ne peuvent être ni volées ni lues par quelqu&#39;un qui souhaite les utiliser à des fins malveillantes, cela port une importance cruciale de la sécurité des données. Le cryptage des données nous assure la confidentialité, l&#39;intégrité et l&#39;authenticité du contenue (texte, message, etc.).

Les deux types principaux des algorithmes de chiffrement sont le cryptage symétrique et asymétrique. Le chiffrement symétrique est un système de chiffrement qui utilise la même clé secrète pour le chiffrement et le déchiffrement. C&#39;est un chiffrement qui est particulièrement utile pour chiffrer de grandes quantités de données. En effet, il est très rapide et consomme peu de ressources.

![Resim1](https://user-images.githubusercontent.com/83185578/148678231-0e53a23b-4ab4-4716-b191-15cc2a513464.png)

Les deux types de briques de base de chiffrement symétrique : le chiffrement de flux (chiffrement par flot) et le chiffrement par bloc. Le chiffrement de flux est basé sur le principe du One-Time Pad, c&#39;est-à-dire l&#39;opération bit à bit XOR. Le chiffrement de bloc est la catégorie la plus utilisée aujourd&#39;hui. Ce chiffrement consiste à découper un message en blocs de taille fixe, généralement de 128 bits. Chaque bloc est chiffré avec la clé secrète et une fonction de chiffrement de bloc interne, ce qui donne un bloc chiffré de la même taille. On regroupe ensuite tous les blocs pour former le texte chiffré.

#### Technologies Utilisées

Puisque je lance mon projet sur GitHub, j&#39;utilise la technologie Git dans la gestion de projet et la révision de code. J&#39;ai profité de l&#39;éditeur de texte Sublime Text et Code::Bloks IDE pour écrire du code. De plus, j&#39;ai utilisé Valgrind, Code::Bloks et GDB (GNU débogueur) pour les vérifications de bogues et d&#39;optimisation de code.

## _Algorithme Blowfish_

#### Notion de Algorithme de Chiffrement Blowfish

En 1983, Bruice Schneier a développé un algorithme comme alternative à vieillissement DES et IDEA à savoir Blowfish. C&#39;est une clé symétrique chiffrement par bloc. Blowfish a une taille de bloc de 64 bits et une clé variable longueur de 32 bits à 448 bits. C&#39;est un Feistel de 16 coups chiffrement et utilise de grandes boîtes S dépendant de la clé. Le poisson-globe est connu pour être sensible aux attaques sur les touches réfléchissantes faibles. Blowfish est dans le domaine public, c&#39;est-à-dire qu&#39;il est sans licence et s&#39;ouvre pour tout le monde. Blowfish divise l&#39;entrée 64 bits en deux moitiés chacune de 32 bits, puis selon la structure de Feistel, le texte chiffré sera être produit à partir de texte brut.

![Resim2](https://user-images.githubusercontent.com/83185578/148678269-1a3aa9fc-96c6-4ff7-b340-3f9817c9c020.png)

#### Applications du Monde Réel de Blowfish

### Gestion des mots de passe

Les logiciels et systèmes de gestion des mots de passe protègent et créent des mots de passe. Blowfish a été utilisé dans une variété d&#39;outils de gestion de mots de passe pour créer des mots de passe et crypter les mots de passe enregistrés. Voici des exemples d&#39;outils de gestion de mots de passe utilisant Blowfish : Gestionnaire d&#39;accès, Java PasswordSafe, Web confidentiel

**Cryptage de fichiers/disques**

Les logiciels qui cryptent les fichiers ou les disques sont extrêmement courants aujourd&#39;hui, car de nombreuses organisations ont des données sensibles dont elles ont besoin pour assurer la sécurité. Ce logiciel doit être simple à utiliser par les entreprises et rapide pour terminer le processus de cryptage. Ainsi, Blowfish est utilisé dans ces systèmes de cryptage souvent dans des produits tels que GnuPG, Bcrypt, CryptoForge

### Outils de sauvegarde

Les logiciels qui sauvegardent l&#39;infrastructure vitale d&#39;une organisation doivent avoir la capacité de chiffrer les informations contenues dans ces sauvegardes. C&#39;est dans le cas où la sauvegarde contient des informations sensibles. Les systèmes de sauvegarde qui utilisent Blowfish sont Symantec NetBackup et Sauvegarde pour les groupes de travail.

**Cryptage des courriels**

Le cryptage des courriels est extrêmement important sur n&#39;importe quel appareil. Différents logiciels IOS, Linux et Windows utilisent tous Blowfish pour le cryptage des courriels. Pour illustrer, on peut donner quelques exemples : A-Lock, SecuMail.

**Secure Shell (SSH)**

Secure Shell est utilisé pour accéder à distance aux réseaux informatiques tout en authentifiant l&#39;utilisateur grâce à l&#39;utilisation de méthodes de cryptage comme Blowfish. Exemples : OpenSSH, PuTTY

## _Architecture du Project_

#### Processus du Projet

### Structure de Code

De premier lieu, j'ai lu les articles de Bruce Schneier et observé les implémentations différentes de l'algorithme de Blowfish [sur son site d&#39;Internet](https://www.schneier.com/academic/blowfish/). Je me suis inspirée à l'implémentation de Paul Kocher (qui est publié en 1997) quand j&#39;ai des problèmes liés au chiffrement. Dans le fichier de source blowfish.c, il y a la fonction d'initialisation, la fonction de hachage, la fonction déchiffrement et la fonction de déchiffrement. Le fichier d'en-tête blowfish.h contient les définitions des fonctions et de la structure. La fonction de main() se trouve dans le ficher de teste main.c qui contient une application de teste et une application du monde réel qui chiffre et déchiffre un jeu de donnée nettoyé des messages en les écrivant sur les fichier \*.txt différents pour montrer le chiffrement et le déchiffrement.

### Processus de débogage

Au cours du processus de programmation, des erreurs de mémoire ont été rencontrées assez souvent. Ceci est difficile à remarquer car le processus de compilation est effectué avec la commande `./main` sur le terminal. La présence d&#39;erreurs est détectée par l'outil de programmation appelé Valgrind, qui est utilisé pour détecter les erreurs de mémoire et les fuites. Dans le processus de débogage, les résultats créés par Valgrind ont été examinés en détail et des recherches approfondies ont été menées sur Internet. En faisant cela, la racine des erreurs a été atteinte.

#### _Première Partie : La Nettoyage des Données_

### Système de Fichier & Coup d'oeuil à Jeu de Données

Tous les fichiers de code, le jeu de donnée de messages et tous les fichiers de \*.txt qui seront créés se trouvent dans le dossier src.

Dans le jeu de données, il y a une mille messages nettoyés et ces messages sont stockés dans un fichier appelé messages.txt. Le ligne le plus longue vaut 386 charactères, c'est pourquoi on a utilisé une liste appelée tmp de taille 500 bits (charactères).

J'ai nettoyé les données pour supprimer les caractères non-ASCIIs et alphanumériques.

### Compilation du programme & Interface Utilisateur

L'utilisateur doit d&#39;abord compiler le programme sur un système d&#39;exploitation basé sur Linux en en tapant la commande suivante dans le terminal : gcc blowfish.c blowfish.h main.c -o main. Ensuite, l&#39;utilisateur doit appeler le fichier exécutable pour exécuter le programme : ./main.

L&#39;exécution du programme donne le fichier messages-cryptes.txt et le fichier messages-decryptes.txt dans le dossier src.

#### _Deuxième Partie : Le Chiffrement &amp; Application de Chiffrement de Message_

### Structure Employée

```
typedef struct{

uint32\_tP[16 + 2];

uint32\_tS[4][256];

} BLOWFISH\_CTX;
```

### Fonctions (BLOWFISH.H)
```
unsigned long F(BLOWFISH\_CTX \*ctx, uint32\_t x)
```
```
Cette fonction faire une combinaison des pièces quartet de la partie gauche du message (ou bien la partie gauche du texte dans la boucle actuelle) et boîtes S.
```
```
void Blowfish_Init(BLOWFISH_CTX *ctx, uint16_t *key, int KeyLen)
```
```
Cette fonction initialise le chiffrement en faisant les ajustements nécessaires.
```
```
void Blowfish_Encrypt(BLOWFISH_CTX *ctx, uint32_t *xl, uint32_t *xr)
```
```
void Blowfis\_Decrypt (BLOWFIS\_CTX *ctx, uint32_t *xl, uint32_t *xr)
```
## _Résultats_

#### Cryptanalyse du Blowfish

En 1996, Serge Vaudenay a montré que les permutations dans Blowfish s&#39;écartaient sensiblement des permutations complètement aléatoires sur 14 tours. L&#39;attaque qu&#39;il a forgée nécessite 28r + 1 textes clairs connus, avec r le nombre de tours. Il a de plus mis en évidence des clés dites faibles, qui génèrent des boîtes S comportant des collisions. Ces clés sont détectables et cassables avec la même attaque en seulement 24r + 1 textes clairs connus. L&#39;attaque ne peut être étendue au Blowfish complet avec ses 16 tours. Vincent Rijmen a publié une attaque sur quatre tours en 1997, elle est basée sur une cryptanalyse différentielle de second degré. La recherche exhaustive reste la seule solution pour vaincre un Blowfish complet à ce jour.
# 1

#### Efficacité du Blowfish

L&#39;algorithme Blowfish a beaucoup d&#39;avantages. Blowfish est plus rapide que d&#39;autres algorithmes de cryptage, tels que le Data Encryption Standard (DES). Il a également moins d&#39;opérations à effectuer par rapport aux autres algorithmes de chiffrement. Le calendrier clé de Blowfish prend beaucoup de temps, mais cela peut être avantageux, car les attaques par force brute sont plus difficiles De plus, Blowfish n&#39;est pas breveté et est libre d&#39;utilisation. Cela signifie que n&#39;importe qui peut prendre et utiliser Blowfish pour ce qu&#39;il veut.

Blowfish donne plusieurs avantages pourtant le calendrier des clés de Blowfish prend beaucoup de temps, équivalent à crypter 4 KBs de données, ce qui peut être un inconvénient ou un avantage. Il faut beaucoup de temps pour faire. Le deuxième inconvénient, la petite taille de bloc de Blowfish signifie que des Attaques des Anniversaire peuvent se produire et compromettre l&#39;algorithme de cryptage. De plus, il est suivi de Twofish, qui a été créé pour remplacer Blowfish, car Twofish est meilleur à bien des égards.

#### Conclusion &amp; Travaux Futur

Un programme dédié à fonctionner de la manière la plus efficace dans tous les processus du projet et capable de crypter le jeu de données de message d&#39;échantillon a été créé à l&#39;aide de l&#39;implémentation l&#39;algorithme Blowfish en C. Dans la section [Nettoyage des Données](#_Premi%C3%A8re_Partie_:), qui est l&#39;une des deux parties principales du programme, j&#39;ai ;

- Supprimé les caractères inutiles et qui peut entrainer une erreur de compilation.
- Les stocké dans un fichier de texte.

Dans la section [Chiffrement](#_Deuxi%C3%A8me_Partie_:), j&#39;ai ;

- Implémenté l&#39;algorithme de cryptage Blowfish.
- Créé une application de chiffrement de message.
- Utilisé un jeu de donnée pour tester mon application.

### Améliorations de Algorithme de Chiffrement

On peut utiliser un autre algorithme de cryptage comme Twofish, DES, 3DES, AES, RSA, etc. pour améliorer la rapidité de chiffrement ou la sécurité du message. On va comparer les algorithmes de chiffrement pour le choix de l’algorithme en termes de la durée de chiffrement, la durée de déchiffrement et l’usage de mémoire.

![Clipboard01](https://user-images.githubusercontent.com/83185578/148693192-a5d59476-be53-4ff6-8eb7-5fb427dade66.jpg)

D’après le dessin 4, l'algorithme Blowfish enregistre la durée de cryptage le plus rapide et l'algorithme RSA enregistre la durée de cryptage le plus lent. Quant à la durée de décryptage pour tous les algorithmes est plus rapide que le temps de cryptage. De plus, l'algorithme Blowfish enregistre la durée de déchiffrement le plus rapide et l'algorithme RSA enregistre la durée de déchiffrement le plus lent.

![Resim2](https://user-images.githubusercontent.com/83185578/148693209-b579c11d-84f6-4e32-89a2-5112ae66ae28.png)

Selon le dessin, la mémoire utilisée pour les opérations unitaires pour toutes les techniques cryptographiques que nous avons étudiées. Blowfish a consommé moins de stockage de mémoire que les autres types, tandis que RSA utilise la mémoire la plus élevée.

![Resim3](https://user-images.githubusercontent.com/83185578/148693224-fbec173d-ebf0-457c-841e-aa4730e3869a.png)

Quant au dessin 6, les comparaisons de temps entre Twofish et Blowfish nous montrent que Twofish prend moins de temps pour crypter le document que Blowfish.

## _Ressources_

1. [https://www.kaspersky.fr/resource-center/definitions/encryption](https://www.kaspersky.fr/resource-center/definitions/encryption)
2. [https://www.itpro.fr/qu-est-ce-que-cryptage-donnees/](https://www.itpro.fr/qu-est-ce-que-cryptage-donnees/)
3. [https://www.cnil.fr/en/node/23022](https://www.cnil.fr/en/node/23022)
4. [https://web.maths.unsw.edu.au/~lafaye/CCM/crypto/crypto.htm](https://web.maths.unsw.edu.au/~lafaye/CCM/crypto/crypto.htm)
5. [https://berty.tech/blog/cryptography-daily-usage](https://berty.tech/blog/cryptography-daily-usage)
6. [https://www.schneier.com/academic/blowfish/](https://www.schneier.com/academic/blowfish/)
7. By Gid.vn - Own work, CC BY-SA 4.0, [https://commons.wikimedia.org/w/index.php?curid=46009111](https://commons.wikimedia.org/w/index.php?curid=46009111)
8. [https://www.encryptionconsulting.com/education-center/what-is-blowfish/](https://www.encryptionconsulting.com/education-center/what-is-blowfish/)
9. [https://fr.wikipedia.org/wiki/Blowfish](https://fr.wikipedia.org/wiki/Blowfish)
10. Rane, D. D. (2016). Superiority of Twofish over Blowfish_. International Journal of Scientific Research and Management_. [https://doi.org/10.18535/ijsrm/v4i11.01](https://doi.org/10.18535/ijsrm/v4i11.01)
11. **Jeu de Données :** [http://www.dt.fee.unicamp.br/~tiago/smsspamcollection/](http://www.dt.fee.unicamp.br/~tiago/smsspamcollection/)
12. **Nettoyage des Données :**
  1. [https://pteo.paranoiaworks.mobi/diacriticsremover/](https://pteo.paranoiaworks.mobi/diacriticsremover/)
  2. [http://www.text-filter.com/Remove-Delete-Non-Alphanumeric-Characters-From-Text-Excel-Online.htm](http://www.text-filter.com/Remove-Delete-Non-Alphanumeric-Characters-From-Text-Excel-Online.htm)
13. [https://symbiosisonlinepublishing.com/computer-science-technology/computerscience-information-technology32.php](https://symbiosisonlinepublishing.com/computer-science-technology/computerscience-information-technology32.php)

[1](#sdfootnote1anc)[https://fr.wikipedia.org/wiki/Blowfish](https://fr.wikipedia.org/wiki/Blowfish)
