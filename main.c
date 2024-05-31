
/**--------------------------------------------------------**/
/**       C o n v e r s i o n   Z vers C (Standard)        **/
/**             Réalisée par Pr D.E ZEGOUR                 **/
/**             E S I - Alger                              **/
/**             Copywrite 2014                             **/
/**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Time.h>
#include <windows.h>
#include <conio.h>

typedef int bool;
typedef char *string255;

#define True 1
#define False 0

/** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

/** Structures statiques **/

typedef struct Tib Type_Tib;
typedef Type_Tib *Typestr_Tib;
typedef int Type1_Tib;
typedef bool Type2_Tib;
struct Tib
{
  Type1_Tib Champ1;
  Type2_Tib Champ2;
};

Type1_Tib Struct1_Tib(Typestr_Tib S)
{
  return S->Champ1;
}

Type2_Tib Struct2_Tib(Typestr_Tib S)
{
  return S->Champ2;
}

void Aff_struct1_Tib(Typestr_Tib S, Type1_Tib Val)
{
  S->Champ1 = Val;
}

void Aff_struct2_Tib(Typestr_Tib S, Type2_Tib Val)
{
  S->Champ2 = Val;
}

/** Arbres de recherche binaire **/

typedef Typestr_Tib Typeelem_ATib;
typedef struct Noeud_ATib *Pointeur_ATib;

struct Noeud_ATib
{
  Typeelem_ATib Val;
  Pointeur_ATib Fg;
  Pointeur_ATib Fd;
  Pointeur_ATib Pere;
};

Typeelem_ATib Info_ATib(Pointeur_ATib P)
{
  return P->Val;
}

Pointeur_ATib Fg_ATib(Pointeur_ATib P)
{
  return P->Fg;
}

Pointeur_ATib Fd_ATib(Pointeur_ATib P)
{
  return P->Fd;
}

Pointeur_ATib Pere_ATib(Pointeur_ATib P)
{
  return P->Pere;
}

void Aff_info_ATib(Pointeur_ATib P, Typeelem_ATib Val)
{
  Typeelem_ATib _Temp;
  _Temp = malloc(sizeof(Type_Tib));
  /* Affectation globale de structure */
  _Temp->Champ1 = Val->Champ1;
  _Temp->Champ2 = Val->Champ2;
  Val = _Temp;
  P->Val = Val;
}

void Aff_fg_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
  P->Fg = Q;
}

void Aff_fd_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
  P->Fd = Q;
}

void Aff_pere_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
  P->Pere = Q;
}

void Creernoeud_ATib(Pointeur_ATib *P)
{
  *P = (struct Noeud_ATib *)malloc(sizeof(struct Noeud_ATib));
  (*P)->Val = malloc(sizeof(Type_Tib));
  (*P)->Fg = NULL;
  (*P)->Fd = NULL;
  (*P)->Pere = NULL;
}

void Liberernoeud_ATib(Pointeur_ATib P)
{
  free(P);
}

/** Implémentation **\: LISTE DE ENTIERS**/

/** Listes lin?aires cha?n?es **/

typedef int Typeelem_Li;
typedef struct Maillon_Li *Pointeur_Li;

struct Maillon_Li
{
  Typeelem_Li Val;
  Pointeur_Li Suiv;
};

Pointeur_Li Allouer_Li(Pointeur_Li *P)
{
  *P = (struct Maillon_Li *)malloc(sizeof(struct Maillon_Li));
  (*P)->Suiv = NULL;
}

void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val)
{
  P->Val = Val;
}

void Aff_adr_Li(Pointeur_Li P, Pointeur_Li Q)
{
  P->Suiv = Q;
}

Pointeur_Li Suivant_Li(Pointeur_Li P)
{
  return (P->Suiv);
}

Typeelem_Li Valeur_Li(Pointeur_Li P)
{
  return (P->Val);
}

void Liberer_Li(Pointeur_Li P)
{
  free(P);
}

/** Pour les variables temporaires **/
typedef Typestr_Tib Typeelem_V1Tib;
typedef Typeelem_V1Tib Typetab_V1Tib[1];

/** Pour les variables temporaires **/
typedef int Typeelem_V1i;
typedef Typeelem_V1i Typetab_V1i[1];

/** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
/** Piles **/

typedef Pointeur_ATib Typeelem_PATib;
typedef struct Maillon_PATib *Pointeur_PATib;
typedef Pointeur_PATib Typepile_PATib;

struct Maillon_PATib
{
  Typeelem_PATib Val;
  Pointeur_PATib Suiv;
};

void Creerpile_PATib(Pointeur_PATib *P)
{
  *P = NULL;
}

bool Pilevide_PATib(Pointeur_PATib P)
{
  return (P == NULL);
}

void Empiler_PATib(Pointeur_PATib *P, Typeelem_PATib Val)
{
  Pointeur_PATib Q;

  Q = (struct Maillon_PATib *)malloc(sizeof(struct Maillon_PATib));
  Q->Val = Val;
  Q->Suiv = *P;
  *P = Q;
}

void Depiler_PATib(Pointeur_PATib *P, Typeelem_PATib *Val)
{
  Pointeur_PATib Sauv;

  if (!Pilevide_PATib(*P))
  {
    *Val = (*P)->Val;
    Sauv = *P;
    *P = (*P)->Suiv;
    free(Sauv);
  }
  else
    printf("%s \n", "Pile vide");
}

/** Implémentation **\: PILE DE ENTIERS**/
/** Piles **/

typedef int Typeelem_Pi;
typedef struct Maillon_Pi *Pointeur_Pi;
typedef Pointeur_Pi Typepile_Pi;

struct Maillon_Pi
{
  Typeelem_Pi Val;
  Pointeur_Pi Suiv;
};

void Creerpile_Pi(Pointeur_Pi *P)
{
  *P = NULL;
}

bool Pilevide_Pi(Pointeur_Pi P)
{
  return (P == NULL);
}

void Empiler_Pi(Pointeur_Pi *P, Typeelem_Pi Val)
{
  Pointeur_Pi Q;

  Q = (struct Maillon_Pi *)malloc(sizeof(struct Maillon_Pi));
  Q->Val = Val;
  Q->Suiv = *P;
  *P = Q;
}

void Depiler_Pi(Pointeur_Pi *P, Typeelem_Pi *Val)
{
  Pointeur_Pi Sauv;

  if (!Pilevide_Pi(*P))
  {
    *Val = (*P)->Val;
    Sauv = *P;
    *P = (*P)->Suiv;
    free(Sauv);
  }
  else
    printf("%s \n", "Pile vide");
}

/** Variables du programme principal **/
Pointeur_ATib Root = NULL;
Pointeur_ATib Temp = NULL;
Pointeur_ATib Racine = NULL;
Pointeur_ATib Racine_copy = NULL;
Typestr_Tib K;
Typestr_Tib L;
Pointeur_ATib Iter = NULL;
Pointeur_Li Li = NULL;
Pointeur_Li L1 = NULL;
Pointeur_Li L2 = NULL;
int I;
Type_Tib S_K;
Typetab_V1Tib T_Root;
Type_Tib S_L;
int _Px1;

/** Fonctions standards **/

int Aleanombre(int N)
{
  return (rand() % N);
}

/** Initialisation d'une structure **/
void Init_struct_Tib(Typestr_Tib S, Type_Tib S_)
{
  S->Champ1 = S_.Champ1;
  S->Champ2 = S_.Champ2;
}

/** Cr?ation d'un arbre de recherche binaire **/

void Creer_arb_ATib(Pointeur_ATib *Arbre, Typetab_V1Tib Tab, int N)
{
  int I;
  Pointeur_ATib P, Q;

  /* Creation De La Racine */
  Creernoeud_ATib(&P);
  *Arbre = P;
  Aff_info_ATib(P, Tab[0]);
  for (I = 2; I <= N; ++I)
  {
    P = *Arbre;
    Q = *Arbre;
    while ((Tab[I - 1]->Champ1 != Struct1_Tib(Info_ATib(P))) && (Q != NULL))
    {
      P = Q;
      if (Tab[I - 1]->Champ1 < Struct1_Tib(Info_ATib(P)))
        Q = Fg_ATib(P);
      else
        Q = Fd_ATib(P);
    }
    if (Tab[I - 1]->Champ1 == Struct1_Tib(Info_ATib(P)))
      printf("%s \n", "Un double existe");
    else
    {
      Creernoeud_ATib(&Q);
      Aff_info_ATib(Q, Tab[I - 1]);
      if (Tab[I - 1]->Champ1 < Struct1_Tib(Info_ATib(P)))
        Aff_fg_ATib(P, Q);
      else
        Aff_fd_ATib(P, Q);
      Aff_pere_ATib(Q, P);
    }
  }
}

/** Cr?ation d'une liste **/
void Creer_liste_Li(Pointeur_Li *L, Typetab_V1i Tab, int N)
{
  int I;
  Pointeur_Li P, Q;

  *L = NULL;
  for (I = 1; I <= N; ++I)
  {
    Allouer_Li(&Q);
    Aff_val_Li(Q, Tab[I - 1]);
    Aff_adr_Li(Q, NULL);
    if (*L == NULL)
      *L = Q;
    else
      Aff_adr_Li(P, Q);
    P = Q;
  }
}

int getTerminalSize()
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int cols;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  return cols;
}



/*-----------------------------------------LES ENTETES DES FONCTIONS ET PROCEDURES---------------------------------------------------------*/

/*--------La creation et la verification d'un arbre aleatoire--------------*/
void Randomarbre(Pointeur_ATib *R, int *N);//Cette procedure Creer un arbre aleatoire dont la racine est R , avec N noeuds
void Randomarbre_verif(Pointeur_ATib *Rac);//Cette procedure verifie si un arbre est un BST (arbre binaire) 
/*-----------------------------------------------------------------------*/


/*Fonctions intermediares*/
void Reinitialiserarbre(Pointeur_ATib *Rac);//cette fonction remet les champs visited d'un arbre a faux pour pouvoir le re parcourir
Pointeur_ATib Copytree(Pointeur_ATib *Rac, Pointeur_ATib *Parent);//cette fonction copie un arbre pour ensuite pouvoir verifier le 4eme et 2eme paarcour
void Inorder_verif(Pointeur_ATib *Rac, Pointeur_Li *L);//Cette fonction parcours l'arbre en inordre et assigne chaque valeur a une liste linéaire chainées pour pouvoir verifier si c'est un BST 
void Insert_list(Pointeur_Li *L1, int *Val);//cette procedure insere une valeur val dans une liste L1
bool Comparelist(Pointeur_Li *L1, Pointeur_Li *L2);//Cette fonction compare chaque valeur de la liste L1 avec la Liste L2 et renvoie faux si il y a des differences
void Branchtravesral(Pointeur_ATib *Rac, Pointeur_Pi *Stack, Pointeur_Li *L1);//Cette fonction traverse l'arbre Branche par Branche de Gauche a droite et affecte les valeur a une liste L1 si la valeur n'existe pas deja dans celle ci 
void Inv_branchtraversal(Pointeur_ATib *Rac, Pointeur_Pi *Stack, Pointeur_Li *L1);//Cette fonction traverse l'arbre Branche par Branche de Droite a gauche et affecte les valeur a une liste L1 si la valeur n'existe pas deja dans celle ci
Pointeur_ATib Last_leaf(Pointeur_ATib *Rac);//cette fonction recupere la feuille la plus a droite
void Firstleaf(Pointeur_ATib *Root, Pointeur_ATib *Iter, bool *Isleaf);//cette fonction recupere la feuille la plus a gauche
Pointeur_ATib Next_leaf(Pointeur_ATib *Rac, Pointeur_ATib *Feui);//cette fonction recupere la prochaine feuille a partir de feui vers la droite 
Pointeur_ATib Inv_last_leaf(Pointeur_ATib *Rac);////cette fonction recupere la feuille la plus a droite
Pointeur_ATib Inv_next_leaf(Pointeur_ATib *Rac, Pointeur_ATib *Feui);//cette fonction recupere la prochaine feuille a partir de feui vers la gauche
/*-------------------------*/




/*-------------------------------Parcours 1 et 3 ( BB-LR/BB-RL )*/
void Bblr(Pointeur_ATib *Root, Pointeur_Li *L1);//Cette fonction effectue le parcours N:1
void Bbrl(Pointeur_ATib *Root, Pointeur_Li *L1);//Cette fonction effectue le parcours N:3
void Bbrl_verif(Pointeur_ATib *Rac, Pointeur_Li *L1);//Cette fonction verifie le parcours N:1
void Bblr_verif(Pointeur_ATib *Rac, Pointeur_Li *L1);//Cette fonction verifie le parcours N:3
/*---------------------------------------------------------------*/



/*----------------------Parcours 2 et 4 (LL-LR/LL-RL)---------*/
void Lllr(Pointeur_ATib *Rac);//Cette fonction effectue le parcours N:2
void Llrl(Pointeur_ATib *Rac);//Cette fonction effectue le parcours N:4
void Lllr_verif(Pointeur_ATib *Rac);//Cette fonction verifie le parcours N:2
void Llrl_verif(Pointeur_ATib *Rac);//Cette fonction verifie le parcours N:4
/*---------------------------------------------------------------*/

/*---------------------------------Les Fonctions d'Affichage-------------------------------------------------*/
void SetColor(int color);//
void fillMatrix(Pointeur_ATib root, char matrix[][148], int row, int col, int space);//cette fonction remplie une matrice avec l'arbre qu'on affichera
int getHeight(Pointeur_ATib root);//cette fonction recupere la hauteur d'un arbre
int countNodes(Pointeur_ATib root);//cette fonction recupere le nombre de noeud d'un arbre
void printMatrix(char matrix[][148], int height, char wanted[10]);//cette fonction affiche la matrice en question
void printTree(Pointeur_ATib root, int highlightVal);//Cette fonction affiche notre arbre avec la valeur en cours de parcours en surbrillance
void printTreeVertical(Pointeur_ATib Root, int height, int wanted);//cette fonction affiche l'arbre verticalement quand le nombre de noeuds est trop important
void printOption(char *text,bool isSelected,int width);//cette fonction affiche les options du menu avec en rouge celle selectioné 
/*------------------------------------------------------------------------------------------------------------*/




/*--------------------------------------------------------LE CORP DES FONCTIONS----------------------------------------------------*/

/*dans cette procedure nous allons generer des nombres aleatoire entre 1 et 500 et les inserer dans un arbre 
suivant cette logique d'insertion dans un BST (si inferieur a gauche , sinon a droite)*/



/*---------------------------------------------LA creation d'un arbre aleatoire------------------------------------------------------*/
void Randomarbre(Pointeur_ATib *R, int *N)
{
   /** Variables locales **/
  int Cmp;            // Compteur de nœuds insérés
  int Random;         // Nombre aléatoire généré
  Pointeur_ATib Iter = NULL;  // Pointeur d'itération pour traverser l'arbre
  Pointeur_ATib Temps = NULL; // Pointeur temporaire pour le nouveau nœud
  bool Trouv;         // Indicateur pour savoir si le bon emplacement a été trouvé
  Typestr_Tib S;      // Structure pour le nouveau nœud
  Typestr_Tib J;      // Structure initiale pour le premier nœud
  Type_Tib S_J;       // Valeur pour le premier nœud
  Type_Tib S_S;       // Valeur pour les nœuds suivants

  /** Corps du module **/
  S = malloc(sizeof(Type_Tib));
  J = malloc(sizeof(Type_Tib));
  printf(" %s", "NOUS ALLONS PROCEDER A LA CREATION DE L'ARBRE. SES NOEUDS SONT : \n");
  printf("Appuyez pour continuer...\n");
  getchar();
  
  // Création du premier nœud avec une valeur aléatoire
  Random = Aleanombre(100);
  S_J.Champ1 = Random;
  S_J.Champ2 = False;
  Init_struct_Tib(J, S_J);
  Creernoeud_ATib(&*R);
  Aff_info_ATib(*R, J);

  Cmp = 1;
  while (Cmp < *N)
  {
    Iter = *R;
    Trouv = False;
    Random = Aleanombre(100);
    while (Trouv == False)
    {
      // Vérifie si la valeur aléatoire existe déjà
      if (Random == Struct1_Tib(Info_ATib(Iter)))
      {
        Trouv = True;
        Cmp = Cmp - 1;
      }
      // Si la valeur est inférieure, insère à gauche
      else if (Random < Struct1_Tib(Info_ATib(Iter)))
      {
        if (Fg_ATib(Iter) == NULL)
        {
          S_S.Champ1 = Random;
          S_S.Champ2 = False;
          Init_struct_Tib(S, S_S);
          Creernoeud_ATib(&Temps);
          Aff_info_ATib(Temps, S);
          Aff_fg_ATib(Iter, Temps);
          Aff_pere_ATib(Temps, Iter);
          Trouv = True;
        }
        else
        {
          Iter = Fg_ATib(Iter);
        }
      }

      // Si la valeur est supérieure, insère à droite

      else if (Random > Struct1_Tib(Info_ATib(Iter)))
      {
        if (Fd_ATib(Iter) == NULL)
        {
          S_S.Champ1 = Random;
          S_S.Champ2 = False;
          Init_struct_Tib(S, S_S);
          Creernoeud_ATib(&Temps);
          Aff_info_ATib(Temps, S);
          Aff_fd_ATib(Iter, Temps);
          Aff_pere_ATib(Temps, Iter);
          Trouv = True;
        }
        else
        {
          Iter = Fd_ATib(Iter);
        }
      }
    }
    Cmp = Cmp + 1;
  }
  printf("L'arbre aléatoire créé est : \n");
  printTree(*R, 10000);
}


//verifie si un arbre est un bst en le parcourant en inordre et inserant chaque valeur dans une liste puis en verifiant si cette liste est ordonnée
void Randomarbre_verif(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_Li L = NULL;
  Pointeur_Li Iter = NULL;
  bool Correcte;
  Typetab_V1i T_L;

  /** Corps du module **/
  Correcte = True;
  T_L[0] = 0;
  Creer_liste_Li(&L, T_L, 1);
  Iter = L;
  Inorder_verif(&*Rac, &L);
  while (((Suivant_Li(Iter) != NULL) && (Correcte == True)))
  {
    if ((Valeur_Li(Iter) > Valeur_Li(Suivant_Li(Iter))))
    {
      Correcte = False;
    };
    Iter = Suivant_Li(Iter);
  };
  if (Correcte == True)
  {
    printf(" %s", "ARBRE CORRECTEMENT CONSTRUIT !!!!! \n");
    printf("appuyez pour continuer...");
    getchar();
     system("cls");
  }
  else
  {
    printf(" %s", "ARBRE MAL CONSTRUIT \n");
    printf("appuyez pour continuer...");
    getchar();
    system("cls");
  };
}

/*-------------------------------------------------Fonctions intermediaires------------------------------------------*/
//parcours l'arbre et remet les champs visited a faux
void Reinitialiserarbre(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib _Px1 = NULL;
  Pointeur_ATib _Px2 = NULL;

  /** Corps du module **/
  if ((*Rac != NULL))
  {
    _Px1 = Fg_ATib(*Rac);
    Reinitialiserarbre(&_Px1);
    Aff_struct2_Tib(Info_ATib(*Rac), False);
    _Px2 = Fd_ATib(*Rac);
    Reinitialiserarbre(&_Px2);
  };
}

/*copie un arbre pour pouvoir effectuer la verification des parcours 4 et 2*/
/*on parcours les noeuds et les recreer recursivement*/
Pointeur_ATib Copytree(Pointeur_ATib *Rac, Pointeur_ATib *Parent)
{
  /** Variables locales **/
  Pointeur_ATib Copytree2 = NULL;
  Pointeur_ATib Temp = NULL;
  Pointeur_ATib _Px1 = NULL;
  Pointeur_ATib _Px2 = NULL;

  /** Corps du module **/
  if (*Rac == NULL)
  {
    Copytree2 = NULL;
  }
  else
  {
    Creernoeud_ATib(&Temp);
    Aff_info_ATib(Temp, Info_ATib(*Rac));
    _Px1 = Fd_ATib(*Rac);
    Aff_fd_ATib(Temp, Copytree(&_Px1, &Temp));
    _Px2 = Fg_ATib(*Rac);
    Aff_fg_ATib(Temp, Copytree(&_Px2, &Temp));
    Aff_pere_ATib(Temp, *Parent);
    Copytree2 = Temp;
  };

  return Copytree2;
}



 /*
 * Fonction qui parcours l'arbre en inordre et met chaque valeur dans une liste
 * Rac Pointeur vers la racine de l'arbre à vérifier.
 * L Pointeur vers la liste où les valeurs des nœuds seront insérées en ordre.
 */
void Inorder_verif(Pointeur_ATib *Rac, Pointeur_Li *L)
{
  /** Variables locales **/
  Pointeur_Li Iter = NULL;  // Pointeur d'itération pour la liste
  bool Correcte;            // Indicateur de correction
  Pointeur_ATib _Px1 = NULL;// Pointeur temporaire pour le sous-arbre gauche
  int _Px2;                 // Valeur du nœud actuel
  Pointeur_ATib _Px3 = NULL;// Pointeur temporaire pour le sous-arbre droit

  /** Corps du module **/
  Iter = *L; // Initialise l'itérateur de la liste
  if (*Rac != NULL) // Si le nœud actuel n'est pas NULL
  {
    // Traite récursivement le sous-arbre gauche
    _Px1 = Fg_ATib(*Rac);
    Inorder_verif(&_Px1, &*L);
    // Insère la valeur du nœud actuel dans la liste
    _Px2 = Struct1_Tib(Info_ATib(*Rac));
    Insert_list(&*L, &_Px2);
    // Traite récursivement le sous-arbre droit
    _Px3 = Fd_ATib(*Rac);
    Inorder_verif(&_Px3, &*L);
  };
}

/*------------------------------------------------------LE 1er et 3eme parcours--------------------------------------------*/

/*Voici comment nous allons effectuer le parcours : 
-on descend vers la premiere feuille et a chaque noeud si celui si a un fils droit et gauche on empile le fils droit
-une fois arrivé a une feuille on remonte et on met les champs des noeuds parcourue a visited jusqu'a la racine ou trouver un noeud deja visited
-on depile et recommence l'operation jusqu'a ce que la pile sois vide et le parent du noeud courant est visited (nous avons parcourue tout les noeuds) 
*/
void Bblr(Pointeur_ATib *Root, Pointeur_Li *L1)
{
  /** Variables locales **/
  Pointeur_ATib Iter = NULL;
  Pointeur_PATib Stack = NULL;
  bool Allvisited;
  bool Isaleaf;
  bool Adeuxenfants;
  bool Aquefilsgauche;
  bool Aquefilsdroit;
  bool Apasdepere;
  int _Px1;

  /** Corps du module **/
  printf(" %s", "NOUS ALLONS PROCEDER AU PARCOURS BBLR : \n");
  printf("appuyez pour continuer....\n");
  getchar();
  Iter = *Root;
  Creerpile_PATib(&Stack);
  Allvisited = False;
  while (Allvisited == False) // all visited est un boolleen qui devient vrai quand tout les noeuds sont visitées 
  {
    while ((Allvisited == False))
    {
      Isaleaf = False;
      Adeuxenfants = False;
      Aquefilsgauche = False;
      Aquefilsdroit = False;
      while ((Isaleaf == False))
      {
        Adeuxenfants = False;
        Aquefilsgauche = False;
        Aquefilsdroit = False;
        Apasdepere = False;

        //on descend vers une feuille en empilant le fils droit si il a un fils droit et gauche
        // on aura 4 booleen pour savoir dans quel cas de figure nous sommes 
        if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
        {
          Isaleaf = True;
        };
        if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
        {
          if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
          {
            Isaleaf = True;
          }
          else
          {
            Aquefilsgauche = True;
          };
        };
        if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
        {
          if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
          {
            Isaleaf = True;
          }
          else
          {
            Aquefilsdroit = True;
          };
        };
        if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) != NULL))
        {
          if ((Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True))
          {
            Isaleaf = True;
          };
          if ((Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False))
          {
            Aquefilsgauche = True;
          };
          if ((Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True))
          {
            Aquefilsdroit = True;
          };
          if ((Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False))
          {
            Adeuxenfants = True;
          };
        };
        if ((Adeuxenfants == True)) // on empile 
        {
          Empiler_PATib(&Stack, Fd_ATib(Iter));
          Iter = Fg_ATib(Iter);
        };
        if ((Aquefilsgauche == True))
        {
          Iter = Fg_ATib(Iter);
        };
        if ((Aquefilsdroit == True))
        {
          Iter = Fd_ATib(Iter);
        };
      };
      while ((Apasdepere == False))
      {
        if (((Pere_ATib(Iter)) == NULL))
        {
          Apasdepere = True;
        }
        else
        {
          if (Struct2_Tib(Info_ATib(Pere_ATib(Iter))) == True)
          {
            Apasdepere = True;
          };
        };
        _Px1 = Struct1_Tib(Info_ATib(Iter));
        Insert_list(&*L1, &_Px1);
        Aff_struct2_Tib(Info_ATib(Iter), True);
        system("cls");
        printTree(*Root, Struct1_Tib(Info_ATib(Iter)));

        Iter = Pere_ATib(Iter);
      };
      if (Pilevide_PATib(Stack) == False)
      {
        Depiler_PATib(&Stack, &Iter);
        Apasdepere = False;
      }
      else
      {
        Allvisited = True;
      };
    };
  };
  Reinitialiserarbre(&*Root);//on reinitialise l'arbre pour pouvoir reparcourir
}



//cette fonction est similaire a la precedente sauf que on descendra a droite et en empilera le fils gauche 
void Bbrl(Pointeur_ATib *Root, Pointeur_Li *L1)
{
  /** Variables locales **/
  Pointeur_ATib Iter = NULL;
  Pointeur_PATib Stack = NULL;
  bool Allvisited;
  bool Isaleaf;
  bool Adeuxenfants;
  bool Aquefilsgauche;
  bool Aquefilsdroit;
  bool Apasdepere;
  int _Px1;

  /** Corps du module **/
  printf(" %s", "NOUS ALLONS PROCEDER AU PARCOURS BBRL : \n");
  printf("appuyez pour continuer....\n");
  getchar();
  Iter = *Root;
  Creerpile_PATib(&Stack);
  Allvisited = False;
  while (Allvisited == False)
  {
    while ((Allvisited == False))
    {
      Isaleaf = False;
      Adeuxenfants = False;
      Aquefilsgauche = False;
      Aquefilsdroit = False;
      while ((Isaleaf == False))
      {
        Adeuxenfants = False;
        Aquefilsgauche = False;
        Aquefilsdroit = False;
        Apasdepere = False;
        if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
        {
          Isaleaf = True;
        };
        if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
        {
          if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
          {
            Isaleaf = True;
          }
          else
          {
            Aquefilsgauche = True;
          };
        };
        if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
        {
          if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
          {
            Isaleaf = True;
          }
          else
          {
            Aquefilsdroit = True;
          };
        };
        if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) != NULL))
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
          {
            Isaleaf = True;
          };
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Aquefilsgauche = True;
          };
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
          {
            Aquefilsdroit = True;
          };
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Adeuxenfants = True;
          };
        };
        if ((Adeuxenfants == True))
        {
          Empiler_PATib(&Stack, Fg_ATib(Iter));
          Iter = Fd_ATib(Iter);
        };
        if ((Aquefilsgauche == True))
        {
          Iter = Fd_ATib(Iter);
        };
        if ((Aquefilsdroit == True))
        {
          Iter = Fg_ATib(Iter);
        };
      };
      while ((Apasdepere == False))
      {
        if (((Pere_ATib(Iter)) == NULL))
        {
          Apasdepere = True;
        }
        else
        {
          if (Struct2_Tib(Info_ATib(Pere_ATib(Iter))) == True)
          {
            Apasdepere = True;
          };
        };
        _Px1 = Struct1_Tib(Info_ATib(Iter));
        Insert_list(&*L1, &_Px1);
        Aff_struct2_Tib(Info_ATib(Iter), True);
        system("cls");
        printTree(*Root, Struct1_Tib(Info_ATib(Iter)));
        Iter = Pere_ATib(Iter);
      };
      if (Pilevide_PATib(Stack) == False)
      {
        Depiler_PATib(&Stack, &Iter);
        Apasdepere = False;
      }
      else
      {
        Allvisited = True;
      };
    };
  };
  Reinitialiserarbre(&*Root);
}


/*cette fonction va parcourir l'arbre branche par branche et mettre les elements dans une liste
 si l'element n'existe pas deja puis comparer la liste avec la liste crée lors du vrai parcours*/ 

void Bbrl_verif(Pointeur_ATib *Rac, Pointeur_Li *L1)
{
  /** Variables locales **/
  Pointeur_ATib Iter = NULL;
  Pointeur_Li L2 = NULL;
  bool Isleaf;
  Pointeur_Pi Stack = NULL;

  /** Corps du module **/
  Creerpile_Pi(&Stack);
  Branchtravesral(&*Rac, &Stack, &L2); // remplie la liste 
  if ((Comparelist(&*L1, &L2) == True)) // compare les listes
  {
    printf(" %s", "LE PARCOURS EST CORRECTE \n");
    printf("appuyez pour continuer..");
    getchar();
  }
  else
  {
    printf(" %s", "LE PARCOURS EST FAUX \n");
    printf("appuyez pour continuer..");
    getchar();
  };
}

/*cette fonction va parcourir l'arbre branche par branche et mettre les elements dans une liste
 si l'element n'existe pas deja puis comparer la liste avec la liste crée lors du vrai parcours*/ 

void Bblr_verif(Pointeur_ATib *Rac, Pointeur_Li *L1)
{
  /** Variables locales **/
  Pointeur_ATib Iter = NULL;
  Pointeur_Li L2 = NULL;
  bool Isleaf;
  Pointeur_Pi Stack = NULL;

  /** Corps du module **/
  Creerpile_Pi(&Stack);
  Branchtravesral(&*Rac, &Stack, &L2);
  if ((Comparelist(&*L1, &L2) == True))
  {
    printf(" %s", "LE PARCOURS EST CORRECTE !!\n");
    printf("appuyez pour continuer..");
    getchar();
  }
  else
  {
    printf(" %s", "LE PARCOURS EST FAUX !!\n");
    printf("appuyez pour continuer..");
    getchar();
  };
}

/*--------------------------------------------------LE PARCOURS 2 et 4 ------------------------------------------------- */
/* Pour effectuer ce parcours on trouvera d'abord la premiere feuille et on met son champ visited puis on trouve la prochaine feuille avec 
next_leaf et on la met visited jusqu'a trouver la derniere feuille dans ce cas on remonte a la racine*/

void Lllr(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Temp = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;
  bool Allvisited;

  /** Corps du module **/
  printf("NOUS ALLONS PROCEDER AU PARCOURS LLLR :  \n");
  printf("appuyez pour continuer....\n");
  getchar();
  Allvisited = False;
  while ((Allvisited == False))
  {
    Firstleaf(&*Rac, &Iter, &Isleaf);
    if ((Iter == *Rac) && (Isleaf == True))
    {
      Allvisited = True;
    };
    while ((Iter != Last_leaf(&*Rac)))
    {
      Aff_struct2_Tib(Info_ATib(Iter), True);
      system("cls");

      printTree(*Rac, Struct1_Tib(Info_ATib(Iter)));
      Iter = Next_leaf(&*Rac, &Iter);
    };
    Aff_struct2_Tib(Info_ATib(Iter), True);
    system("cls");

    printTree(*Rac, Struct1_Tib(Info_ATib(Iter)));
    Iter = *Rac;
  };
  Reinitialiserarbre(&*Rac);
}



/* Pour effectuer ce parcours on trouvera d'abord la premiere feuille et on met son champ visited puis on trouve la prochaine feuille avec 
next_leaf et on la met visited jusqu'a trouver la derniere feuille dans ce cas on remonte a la racine sauf que cette fois ci de droite a gauche*/
void Llrl(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Temp = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;
  bool Allvisited;

  /** Corps du module **/
  printf(" %s", "NOUS ALLONS PROCEDER AU PARCOURS LLRL : \n");
  printf("appuyez pour continuer....\n");
  getchar();
  Allvisited = False;
  while ((Allvisited == False))
  {
    Iter = Last_leaf(&*Rac);
    if ((Iter == *Rac))
    {
      Allvisited = True;
    };
    while ((Iter != Inv_last_leaf(&*Rac)))
    {
      Aff_struct2_Tib(Info_ATib(Iter), True);
      system("cls");
      printTree(*Rac, Struct1_Tib(Info_ATib(Iter)));
      Iter = Inv_next_leaf(&*Rac, &Iter);
    };
    Aff_struct2_Tib(Info_ATib(Iter), True);
    system("cls");
    printTree(*Rac, Struct1_Tib(Info_ATib(Iter)));
    Iter = *Rac;
  };
  Reinitialiserarbre(&*Rac);
}


/*on verifie le parcours en supprimant les feuilles et a a fin il ne devrait en rester aucune*/
void Lllr_verif(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Temp = NULL;
  Pointeur_ATib Per = NULL;
  Pointeur_ATib Racine_copy = NULL;
  Pointeur_ATib Parent = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;
  bool Allvisited;

  /** Corps du module **/
  Racine_copy = Copytree(&*Rac, &Parent);
  Allvisited = False;
  while ((Allvisited == False))
  {
    Firstleaf(&Racine_copy, &Iter, &Isleaf);
    if ((Iter == Racine_copy) && (Isleaf == True))
    {
      Allvisited = True;
    };
    while ((Iter != Last_leaf(&Racine_copy)))
    {
      if (Pere_ATib(Iter) != NULL)
      {
        Per = Pere_ATib(Iter);
        Temp = Iter;
        Iter = Next_leaf(&Racine_copy, &Iter);
        if (Temp == Fg_ATib(Per))
        {
          Aff_fg_ATib(Per, NULL);
        }
        else
        {
          Aff_fd_ATib(Per, NULL);
        };
        Liberernoeud_ATib(Temp);
      }
      else
      {
        Racine_copy = NULL;
      };
    };
    if (Pere_ATib(Iter) != NULL)
    {
      Per = Pere_ATib(Iter);
      Temp = Iter;
      if (Temp == Fg_ATib(Per))
      {
        Aff_fg_ATib(Per, NULL);
      }
      else
      {
        Aff_fd_ATib(Per, NULL);
      };
      Liberernoeud_ATib(Temp);
    }
    else
    {
      Racine_copy = NULL;
    };
    Iter = Racine_copy;
  };
  if (Racine_copy == NULL)
  {
    printf(" %s", "LE PARCOURS EST CORRECTE !!!! \n");
    printf("appuyez pour continuer..");
    getchar();
  }
  else
  {
    printf(" %s", "LE PARCOURS EST FAUX !!!!! \n");
    printf("appuyez pour continuer..");
    getchar();
  };
}


//de meme pour cette fonction mais cette fois ci de droite a gauche 
void Llrl_verif(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Temp = NULL;
  Pointeur_ATib Per = NULL;
  Pointeur_ATib Racine_copy = NULL;
  Pointeur_ATib Parent = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;
  bool Allvisited;

  /** Corps du module **/
  Racine_copy = Copytree(&*Rac, &Parent);
  Allvisited = False;
  while ((Allvisited == False))
  {
    Iter = Last_leaf(&Racine_copy);
    if ((Iter == Racine_copy))
    {
      Allvisited = True;
    };
    while ((Iter != Inv_last_leaf(&Racine_copy)))
    {
      if (Pere_ATib(Iter) != NULL)
      {
        Per = Pere_ATib(Iter);
        Temp = Iter;
        Iter = Inv_next_leaf(&Racine_copy, &Iter);
        if (Temp == Fg_ATib(Per))
        {
          Aff_fg_ATib(Per, NULL);
        }
        else
        {
          Aff_fd_ATib(Per, NULL);
        };
        Liberernoeud_ATib(Temp);
      }
      else
      {
        Racine_copy = NULL;
      };
    };
    if (Pere_ATib(Iter) != NULL)
    {
      Per = Pere_ATib(Iter);
      Temp = Iter;
      if (Temp == Fg_ATib(Per))
      {
        Aff_fg_ATib(Per, NULL);
      }
      else
      {
        Aff_fd_ATib(Per, NULL);
      };
      Liberernoeud_ATib(Temp);
    }
    else
    {
      Racine_copy = NULL;
    };
    Iter = Racine_copy;
  };
  if (Racine_copy == NULL)
  {
    printf(" %s", "LE PARCOURS EST CORRECTE !! \n");
    printf("appuyez pour continuer..");
    getchar();
  }
  else
  {
    printf(" %s", "LE PARCOUR EST FAUX !!!! \n");
    printf("appuyez pour continuer..");
    getchar();
  };
}



/*-------------------------------------------------LES FONCTIONS INTERMEDIARES-----------------------------------------------------*/


// cette fonction insere une valeur dans une liste 
void Insert_list(Pointeur_Li *L1, int *Val)
{
  /** Variables locales **/
  Pointeur_Li Iter = NULL;
  Pointeur_Li Temp = NULL;
  bool Doublon;

  /** Corps du module **/
  Iter = *L1;
  Doublon = False;
  if (Iter == NULL)
  {
    Allouer_Li(&Iter);
    Aff_val_Li(Iter, *Val);
  }
  else
  {
    while (((Suivant_Li(Iter) != NULL) && (Doublon == False)))
    {
      if ((Valeur_Li(Iter) != *Val))
      {
        Iter = Suivant_Li(Iter);
      }
      else
      {
        Doublon = True;
      };
    };
    if (Doublon == False)
    {
      Allouer_Li(&Temp);
      Aff_adr_Li(Iter, Temp);
      Aff_val_Li(Temp, *Val);
    };
  };
}

// cette fonction compare 2 liste 
bool Comparelist(Pointeur_Li *L1, Pointeur_Li *L2)
{
  /** Variables locales **/
  bool Comparelist2;
  Pointeur_Li Iter1 = NULL;
  Pointeur_Li Iter2 = NULL;
  bool Egale;

  /** Corps du module **/
  Egale = True;
  Iter1 = *L1;
  Iter2 = *L2;
  while (((Iter1 != NULL) && (Iter2 != NULL) && (Egale == True)))
  {
    if (Valeur_Li(Iter1) != Valeur_Li(Iter2))
    {
      Egale = False;
    };
    Iter1 = Suivant_Li(Iter1);
    Iter2 = Suivant_Li(Iter2);
  };
  if (((Iter1 == NULL) && (Iter2 != NULL)) || ((Iter1 != NULL) && (Iter2 == NULL)))
  {
    Egale = False;
  };
  Comparelist2 = Egale;
  return Comparelist2;
}

/*cette fonction traverse branche par branche de gauche a droite et met les valeur dans une liste */
void Branchtravesral(Pointeur_ATib *Rac, Pointeur_Pi *Stack, Pointeur_Li *L1)
{
  /** Variables locales **/
  int Temp;
  Pointeur_ATib _Px1 = NULL;
  Pointeur_ATib _Px2 = NULL;

  /** Corps du module **/
  if ((*Rac != NULL))
  {
    Empiler_Pi(&*Stack, Struct1_Tib(Info_ATib(*Rac)));
    if (((Fd_ATib(*Rac) == NULL) && (Fg_ATib(*Rac) == NULL)))
    {
      while ((Pilevide_Pi(*Stack) != True))
      {
        Depiler_Pi(&*Stack, &Temp);
        Insert_list(&*L1, &Temp);
      };
    };
    _Px1 = Fg_ATib(*Rac);
    Branchtravesral(&_Px1, &*Stack, &*L1);
    _Px2 = Fd_ATib(*Rac);
    Branchtravesral(&_Px2, &*Stack, &*L1);
  };
}


/*cette fonction traverse branche par branche de droite a gauche et met les valeur dans une liste */
void Inv_branchtraversal(Pointeur_ATib *Rac, Pointeur_Pi *Stack, Pointeur_Li *L1)
{
  /** Variables locales **/
  int Temp;
  Pointeur_ATib _Px1 = NULL;
  Pointeur_ATib _Px2 = NULL;

  /** Corps du module **/
  if ((*Rac != NULL))
  {
    Empiler_Pi(&*Stack, Struct1_Tib(Info_ATib(*Rac)));
    if (((Fd_ATib(*Rac) == NULL) && (Fg_ATib(*Rac) == NULL)))
    {
      while ((Pilevide_Pi(*Stack) != True))
      {
        Depiler_Pi(&*Stack, &Temp);
        Insert_list(&*L1, &Temp);
      };
    };
    _Px1 = Fd_ATib(*Rac);
    Inv_branchtraversal(&_Px1, &*Stack, &*L1);
    _Px2 = Fg_ATib(*Rac);
    Inv_branchtraversal(&_Px2, &*Stack, &*L1);
  };
}





//cette fonction recupere la feuille la plus a droite d'un arbre 
Pointeur_ATib Last_leaf(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Last_leaf2 = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;

  /** Corps du module **/
  Iter = *Rac;
  Isleaf = False;
  while ((Isleaf == False))
  {
    if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
    {
      Isleaf = True;
    };
    if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fd_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fg_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
      {
        Isleaf = True;
      };
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
      {
        Iter = Fd_ATib(Iter);
      }
      else
      {
        if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
        {
          Iter = Fg_ATib(Iter);
        }
        else
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Iter = Fd_ATib(Iter);
          };
        };
      };
    };
  };
  Last_leaf2 = Iter;
  return Last_leaf2;
}


//cette fonction recupere la fonction la plus a gauche d'un arbre 
void Firstleaf(Pointeur_ATib *Root, Pointeur_ATib *Iter, bool *Isleaf)
{

  /** Corps du module **/
  *Iter = *Root;
  *Isleaf = False;
  while ((*Isleaf == False))
  {
    if ((Fg_ATib(*Iter) == NULL) && (Fd_ATib(*Iter) == NULL))
    {
      *Isleaf = True;
    };
    if ((Fd_ATib(*Iter) != NULL) && (Fg_ATib(*Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fd_ATib(*Iter))) == True)
      {
        *Isleaf = True;
      }
      else
      {
        *Iter = Fd_ATib(*Iter);
      };
    };
    if ((Fg_ATib(*Iter) != NULL) && (Fd_ATib(*Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fg_ATib(*Iter))) == True)
      {
        *Isleaf = True;
      }
      else
      {
        *Iter = Fg_ATib(*Iter);
      };
    };
    if ((Fg_ATib(*Iter) != NULL) && (Fd_ATib(*Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(*Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(*Iter))) == True))
      {
        *Isleaf = True;
      };
      if ((Struct2_Tib(Info_ATib(Fg_ATib(*Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(*Iter))) == False))
      {
        *Iter = Fd_ATib(*Iter);
      }
      else
      {
        if ((Struct2_Tib(Info_ATib(Fg_ATib(*Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(*Iter))) == True))
        {
          *Iter = Fg_ATib(*Iter);
        }
        else
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(*Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(*Iter))) == False))
          {
            *Iter = Fg_ATib(*Iter);
          };
        };
      };
    };
  };
}

/*cette fonction recupere la prochaine feuille a partir de fei et cela en remontant jusqua ce 
qu'un noeud ai un fils droit par lequel on ne remonte pas*/ 
Pointeur_ATib Next_leaf(Pointeur_ATib *Rac, Pointeur_ATib *Feui)
{
  /** Variables locales **/
  Pointeur_ATib Next_leaf2 = NULL;
  Pointeur_ATib Iter = NULL;
  Pointeur_ATib Dernier = NULL;// cette variable contient le dernier noeud par lequel on est monté 
  bool Isleaf;
  bool Afilsdroit;
  string255 A;

  /** Corps du module **/
  A = malloc(255 * sizeof(char));
  Iter = *Feui;
  Isleaf = False;
  Afilsdroit = False;
  Dernier = Iter;
  Iter = Pere_ATib(Iter);
  while ((Afilsdroit == False))
  {
    if ((Fd_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
      {
        if ((Fd_ATib(Iter) != Dernier))
        {
          Afilsdroit = True;
        }
        else
        {
          Dernier = Iter;
          Iter = Pere_ATib(Iter);
        };
      }
      else
      {
        Dernier = Iter;
        Iter = Pere_ATib(Iter);
      };
    };
    if ((Fd_ATib(Iter) == NULL))
    {
      Dernier = Iter;
      Iter = Pere_ATib(Iter);
    };
  };
  Iter = Fd_ATib(Iter);
  while ((Isleaf == False))
  {
    if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
    {
      Isleaf = True;
    };
    if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fd_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fg_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
      {
        Isleaf = True;
      };
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
      {
        Iter = Fd_ATib(Iter);
      }
      else
      {
        if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
        {
          Iter = Fg_ATib(Iter);
        }
        else
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Iter = Fg_ATib(Iter);
          };
        };
      };
    };
  };
  Next_leaf2 = Iter;

  return Next_leaf2;
}


//cette fonction recupere le noeud le plus a gauche 
Pointeur_ATib Inv_last_leaf(Pointeur_ATib *Rac)
{
  /** Variables locales **/
  Pointeur_ATib Inv_last_leaf2 = NULL;
  Pointeur_ATib Iter = NULL;
  bool Isleaf;

  /** Corps du module **/
  Iter = *Rac;
  Isleaf = False;
  while ((Isleaf == False))
  {
    if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
    {
      Isleaf = True;
    };
    if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fd_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fg_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
      {
        Isleaf = True;
      };
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
      {
        Iter = Fd_ATib(Iter);
      }
      else
      {
        if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
        {
          Iter = Fg_ATib(Iter);
        }
        else
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Iter = Fg_ATib(Iter);
          };
        };
      };
    };
  };
  Inv_last_leaf2 = Iter;

  return Inv_last_leaf2;
}


//cette fonction recupere la prochaine feuille mais a gauche 
Pointeur_ATib Inv_next_leaf(Pointeur_ATib *Rac, Pointeur_ATib *Feui)
{
  /** Variables locales **/
  Pointeur_ATib Inv_next_leaf2 = NULL;
  Pointeur_ATib Iter = NULL;
  Pointeur_ATib Dernier = NULL;
  bool Isleaf;
  bool Afilsdroit;
  string255 A;

  /** Corps du module **/
  A = malloc(255 * sizeof(char));
  Iter = *Feui;
  Isleaf = False;
  Afilsdroit = False;
  Dernier = Iter;
  Iter = Pere_ATib(Iter);
  while ((Afilsdroit == False))
  {
    if ((Fg_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False))
      {
        if ((Fg_ATib(Iter) != Dernier))
        {
          Afilsdroit = True;
        }
        else
        {
          Dernier = Iter;
          Iter = Pere_ATib(Iter);
        };
      }
      else
      {
        Dernier = Iter;
        Iter = Pere_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) == NULL))
    {
      Dernier = Iter;
      Iter = Pere_ATib(Iter);
    };
  };
  Iter = Fg_ATib(Iter);
  while ((Isleaf == False))
  {
    if ((Fg_ATib(Iter) == NULL) && (Fd_ATib(Iter) == NULL))
    {
      Isleaf = True;
    };
    if ((Fd_ATib(Iter) != NULL) && (Fg_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fd_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) == NULL))
    {
      if (Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True)
      {
        Isleaf = True;
      }
      else
      {
        Iter = Fg_ATib(Iter);
      };
    };
    if ((Fg_ATib(Iter) != NULL) && (Fd_ATib(Iter) != NULL))
    {
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
      {
        Isleaf = True;
      };
      if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
      {
        Iter = Fd_ATib(Iter);
      }
      else
      {
        if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == True))
        {
          Iter = Fg_ATib(Iter);
        }
        else
        {
          if ((Struct2_Tib(Info_ATib(Fg_ATib(Iter))) == False) && (Struct2_Tib(Info_ATib(Fd_ATib(Iter))) == False))
          {
            Iter = Fd_ATib(Iter);
          };
        };
      };
    };
  };
  Inv_next_leaf2 = Iter;

  return Inv_next_leaf2;
}

/*-----------------------------------------------------LES FONCTIONS d'affichage--------------------------------------------*/
//definie les couleurs
void SetColor(int color)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}


//recupere la hauteur
int getHeight(Pointeur_ATib root)
{
  if (root == NULL)
    return 0;
  int leftHeight = getHeight(Fg_ATib(root));
  int rightHeight = getHeight(Fd_ATib(root));
  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


//recupere le nbr de noeuds
int countNodes(Pointeur_ATib root)
{
  // Si l'arbre est vide, il n'y a pas de nœud
  if (root == NULL)
  {
    return 0;
  }

  // Sinon, compte le nœud actuel, plus les nœuds dans les sous-arbres gauche et droit
  return 1 + countNodes(Fg_ATib(root)) + countNodes(Fd_ATib(root));
}


//remplie la matrice qui contient l'arbre 
void fillMatrix(Pointeur_ATib root, char matrix[][148], int row, int col, int space)
{
  if (root == NULL)
    return;
  char buffer[10];
  sprintf(buffer, "%d", Struct1_Tib(Info_ATib(root)));
  int len = strlen(buffer);
  int pos = col - len / 2;
  for (int i = 0; i < len; i++)
  {
    matrix[row][pos + i] = buffer[i];
  }

  if (Fg_ATib(root) != NULL)
  {
    matrix[row + 1][col] = '|';
    matrix[row + 1][col - 1] = '-';
    for (int i = 1; i < space; i++)
    {
      matrix[row + 1][col - i] = '-';
    }
    fillMatrix(Fg_ATib(root), matrix, row + 2, col - space, space / 2);
  }
  if (Fd_ATib(root) != NULL)
  {
    matrix[row + 1][col] = '|';
    matrix[row + 1][col + 1] = '-';
    for (int i = 1; i < space; i++)
    {
      matrix[row + 1][col + i] = '-';
    }
    fillMatrix(Fd_ATib(root), matrix, row + 2, col + space, space / 2);
  }
}


//affiche cette matrice 
void printMatrix(char matrix[][148], int height, char wanted[10])
{
  char temp[10];
  int l;
  bool visited = FALSE;
  for (int i = 0; i < height; i++)
  {
    int j = 0;
    while (matrix[i][j] != '\0')
    {
      l = j;
      int k = 0;
      while (matrix[i][l] != ' ' && matrix[i][l] != '\0' && matrix[i][l] != '-' && matrix[i][l] != '|')
      {
        temp[k] = matrix[i][l];
        k++;
        l++;
      }
      temp[k] = '\0';
      if (visited == FALSE)
      {
        if (strcmp(temp, wanted) == 0)
        {
          SetColor(12);
          visited = TRUE; // Utilise la couleur rouge pour la valeur spécifique
        }
      }
      if (matrix[i][j] == ' ')
      {
        printf(" ");
        SetColor(7); // Réinitialise à la couleur par défaut
      }
      else
        printf("%c", matrix[i][j]);
      j++; // Passer au caractère suivant après la fin du mot
    }

    printf("\n");
  }
}
int rec[1000006];


//affiche l'zrbre en vertical si le nombre de noeuds est trop important 
void printTreeVertical(Pointeur_ATib Root, int height, int wanted)
{

  int i;
  if (Root == NULL)
    return;
  for (i = 0; i < height; i++)
  {
    if (i == height - 1)
    {
      SetColor(7);
      printf("%s---", rec[height - 1] ? "|" : "");
    }
    else
    {
      SetColor(7);
      printf("%s   ", rec[i] ? "|" : " ");
    }
  }
  if (Struct1_Tib(Info_ATib(Root)) == wanted)
  {
    SetColor(12); // Red color
    printf("%d\n", Struct1_Tib(Info_ATib(Root)));
  }
  else
  {
    SetColor(7); // Default console color
    printf("%d\n", Struct1_Tib(Info_ATib(Root)));
  }
  rec[height] = 1;
  printTreeVertical(Fg_ATib(Root), height + 1, wanted);
  rec[height] = 0;
  printTreeVertical(Fd_ATib(Root), height + 1, wanted);
}


//la fonction qui affiche notre arbre horizontale ou vertical si il y'a trop de noeuds 
void printTree(Pointeur_ATib root, int highlightVal)
{
  if (countNodes(root) > 20)
  {
    printTreeVertical(root, 0, highlightVal);
    Sleep(400);
  }
  else
  {

    char ch[10];
    sprintf(ch, "%d", highlightVal);

    // Calcul de la hauteur de l'arbre
    int height = getHeight(root) * 2 - 1;

    // Initialisation de la matrice
    char matrix[height][148];
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < 148; j++)
      {
        matrix[i][j] = ' ';
      }
      matrix[i][147] = '\0'; // Assure que chaque ligne est terminée par '\0' pour printf
    }

    // Remplissage de la matrice avec les valeurs des nœuds
    fillMatrix(root, matrix, 0, 73, 25); // si tu veux ajuster l'espace entre les fils tu n'as qu'a changer la valeur du dernier parametre

    // Affichage de la matrice
    printMatrix(matrix, height, ch);
    Sleep(1000);
  }
}

//cette fonction creer l'arbre d'exemple du TP 
void CreateExempleTree(Pointeur_ATib *Root)
{
  K = malloc(sizeof(Type_Tib));
  L = malloc(sizeof(Type_Tib));
  int _Izw2;
  for (_Izw2 = 0; _Izw2 < 1; ++_Izw2)
    T_Root[_Izw2] = malloc(sizeof(Type_Tib));
  S_K.Champ1 = 45;
  S_K.Champ2 = False;
  Init_struct_Tib(K, S_K);
  T_Root[0] = K;
  Creer_arb_ATib(&(*Root), T_Root, 1);
  S_L.Champ1 = 20;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(*Root, Temp);
  Aff_pere_ATib(Temp, *Root);
  S_L.Champ1 = 65;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(*Root, Temp);
  Aff_pere_ATib(Temp, *Root);
  S_L.Champ1 = 35;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fg_ATib(*Root), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(*Root));
  S_L.Champ1 = 85;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fd_ATib(*Root), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(*Root));
  S_L.Champ1 = 10;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fg_ATib(*Root), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(*Root));
  S_L.Champ1 = 55;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fd_ATib(*Root), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(*Root));
  S_L.Champ1 = 50;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fg_ATib(Fd_ATib(*Root)), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(Fd_ATib(*Root)));
  S_L.Champ1 = 58;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fg_ATib(Fd_ATib(*Root)), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(Fd_ATib(*Root)));
  S_L.Champ1 = 56;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root))), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fg_ATib(Fd_ATib(*Root))));
  S_L.Champ1 = 57;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fg_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root)))), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root)))));
  S_L.Champ1 = 60;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root))), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fg_ATib(Fd_ATib(*Root))));
  S_L.Champ1 = 62;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fd_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root)))), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fd_ATib(Fg_ATib(Fd_ATib(*Root)))));
  S_L.Champ1 = 95;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fd_ATib(Fd_ATib(*Root)), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fd_ATib(*Root)));
  S_L.Champ1 = 75;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fd_ATib(Fd_ATib(*Root)), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fd_ATib(*Root)));
  S_L.Champ1 = 98;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fd_ATib(Fd_ATib(Fd_ATib(Fd_ATib(*Root))), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fd_ATib(Fd_ATib(*Root))));
  S_L.Champ1 = 90;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fd_ATib(Fd_ATib(Fd_ATib(*Root))), Temp);
  Aff_pere_ATib(Temp, Fd_ATib(Fd_ATib(Fd_ATib(*Root))));
  S_L.Champ1 = 88;
  S_L.Champ2 = False;
  Init_struct_Tib(L, S_L);
  Creernoeud_ATib(&Temp);
  Aff_info_ATib(Temp, L);
  Aff_fg_ATib(Fg_ATib(Fd_ATib(Fd_ATib(Fd_ATib(*Root)))), Temp);
  Aff_pere_ATib(Temp, Fg_ATib(Fd_ATib(Fd_ATib(Fd_ATib(*Root)))));
}

//ces fonctions concernent l'affichage du Menu 

void printHorizontalLine(int width)
{
  printf("+");
  for (int i = 0; i < width - 2; i++)
  {
    printf("-");
  }
  printf("+\n");
}

// Fonction pour centrer du texte dans une largeur donnée
void printCenteredText(char *text, int width)
{
  int padding = (width - strlen(text)) / 2;
  printf("|");
  for (int i = 0; i < padding; i++)
  {
    printf(" ");
  }
  printf("%s", text);
  for (int i = 0; i < padding; i++)
  {
    printf(" ");
  }
  if (strlen(text) % 2 != 0)
  {
    printf(" ");
  }
  printf("|\n");
}




void center_text(char* text,int width) 
{
    int padding = (width - strlen(text)) / 2;
  for (int i = 0; i < padding; i++)
  {
    printf(" ");
  }
  printf("%s", text);
  for (int i = 0; i < padding; i++)
  {
    printf(" ");
  }
  if (strlen(text) % 2 != 0)
  {
    printf(" ");
  }
  printf("\n");
}



void ESI(int width)
{
    printf("\033[1;34m");
    center_text("  ______   _____    _____ ",width);
    center_text(" |  ____| | ____|  |_   _|",width);
    center_text(" | |__    | |___     | |  ",width);
    center_text(" |  __|   |___  |    | |  ",width);
    center_text(" | |____   ___| |   _| |_ ",width);
    center_text(" |______| |_____|  |_____|",width);
    printf("\033[0m");
}

void printOption(char *text,bool isSelected,int width)
{
  if (isSelected)
  {
    printf("\033[1;31;40m");
    printCenteredText(text,width);
    printf("\033[0m");

  }
  else
  {
    printCenteredText(text,width);
  }
}


int main()
{

  int width = 140;
  CreateExempleTree(&Root);
  int choice;
  bool treeCreated = FALSE;
  int nb_noeud = 5;

  system("cls");
    printf("\n\n");
    ESI(width);
    printf("\n\n");
    center_text("REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE",width);
    center_text("MINISTERE DE L'ENSEIGNEMENT SUPERIEUR ET DE LA RECHERCHE SCIENTIFIQUE",width);
    center_text("ECOLE NATIONALE SUPERIEURE D'INFORMATIQUE",width);
    printf("\n\n\n");
    center_text("CPI 1                     Annee 2023/2024",width);
    printf("\n\n");
    center_text("TP EN ALGORITHMIQUE ET STRUCTURES DE DONNEES DYNAMIQUES (ALSDD)",width);
    printf("\n\n");
    center_text("Realise par : Sid Jamyl et Belaidi Walid",width);
    printf("\n\n");
    center_text("Section : D  |  Groupe : 13",width);
    printf("\n\n\n\n");
    printf("\033[1;34m");
    center_text("Appuyez sur n'importe quelle touche pour continuer",width);
    printf("\033[0m");
    getch();



  int selected_option = 0;
  while(1)
    {

    char carac;
    char options[7][100] = {"1. Lancer le programme du TP ( 10 arbres de 100 noeuds ) ","2. Creer un arbre binaire aleatoire",
    "3. Parcourir Notre arbre De Bas en Haut de Gauche a Droite BB-LR","4. Parcourir Notre arbre en Bas en Haut de Droite a Gauche BB-RL"
    ,"5. Parcourir Notre arbre Feuille par Feuille de Gauche a Droite LL-LR","6. Parcourir Notre arbre Feuille par Feuille de Droite a Gauche LL-RL",
    "7. Quitter"};
    

     srand(time(NULL));

    // Efface l'écran
    system("cls");

    // Définit la largeur de l'interface

    // Imprime le cadre supérieur de la grille
    printHorizontalLine(width);


    // Imprime le texte du menu centré
    printCenteredText("Menu :", width);
    printHorizontalLine(width);


     for (int i = 0; i < 7; i++) {
            printOption(options[i], i == selected_option,width);
        }
      printHorizontalLine(width);




        int ch = getch();
        if (ch == 224) {
            ch = getch();
            switch (ch) {
                case 72:
                    selected_option = (selected_option - 1 + 7) % 7;
                    break;
                case 80:
                    selected_option = (selected_option + 1) % 7;
                    break;
                default:
                    break;
            }
        } 
        
      else if (ch == '\r') {
      switch (selected_option)
      {
      case 0:
      nb_noeud = 100;
      for (int i = 0; i <= 10; i++)
      {
        Randomarbre(&Racine, &nb_noeud);
        Randomarbre_verif(&Racine);
        Bblr(&Racine, &L1);
        Bblr_verif(&Racine, &L1);
        Bbrl(&Racine, &L1);
        Bbrl_verif(&Racine, &L1);
        Llrl(&Racine);
        Llrl_verif(&Racine);
        Lllr(&Racine);
        Lllr_verif(&Racine);
         carac = getch();
        if(carac == '\r'){
            break;
        }}
      
     
    case 1:
      printf("Combien de noeuds voulez vous dans votre arbre ? : ");
      scanf("%d", &nb_noeud);
      Randomarbre(&Racine, &nb_noeud);
      Randomarbre_verif(&Racine);

      treeCreated = TRUE;
      carac = getch();
      if(carac == '\r'){
           break;
      }
     
    case 2:
      if (treeCreated)
      {
        Bblr(&Racine, &L1);
        Bblr_verif(&Racine, &L1);
      }
      else
      {
        printf("Veuillez d'abord créer un arbre.\n");
      }

       carac = getch();
                if(carac == '\r'){
                    break;
                }  
    case 3:
      if (treeCreated)
      {
        Bbrl(&Racine, &L1);
        Bbrl_verif(&Racine, &L1);
      }
      else
      {
        printf("Veuillez d'abord créer un arbre.\n");
      }
       carac = getch();
                if(carac == '\r'){
                    break;
                }
    case 4:
      if (treeCreated)
      {
        Lllr(&Racine);
        Lllr_verif(&Racine);
      }
      else
      {
        printf("Veuillez d'abord créer un arbre.\n");
      }
      carac = getch();
                if(carac == '\r'){
                    break;
                }
    case 5:
      if (treeCreated)
      {
         Llrl(&Racine);
        Llrl_verif(&Racine);
      }
      else
      {
        printf("Veuillez d'abord créer un arbre.\n");
      }
      break;
    case 6:
      printf("Au revoir !\n");
      exit(EXIT_SUCCESS);
    default:
      printf("Choix invalide. Veuillez choisir une option valide.\n");
       carac = getch();
                if(carac == '\r'){
                    break;
                }
    }
  }

}
}