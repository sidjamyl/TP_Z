


SOIENT
       /*----------------Creation de L'arbre aleatoire------------*/

       /*Cette procedure Creer un arbre aleatoire dont la racine est R , avec N noeuds */
       Randomarbre UNE ACTION;

       /*Cette procedure verifie si un arbre est un BST (arbre binaire)*/
       Randomarbre_VERIF UNE ACTION;




       /*---------------------Premier parcours et 3eme parcours------*/
       BBLR,BBRL UNE ACTION ; /*Ces fonctions effectuent les parcours 1 et 3*/
       BBLR_VERIF,BBRL_VERIF DES ACTIONS; /* ces fonctions verifient les parcours 1 et  3*/


       /*---------------------Deuxieme parcours et 4 eme parcours------*/
       LLLR,LLRL DES ACTIONS;    /*Ces fonctions effectuent les parcours 2 et 4*/
       LLLR_VERIF,LLRL_VERIF DES ACTIONS;  /* ces fonctions verifient les parcours 2 et  4*/


        /*----------------------Fonction intermediaire-------------------*/
       INSERT_LIST UNE ACTION;
       BranchTravesral,INV_BRANCHTRAVERSAL UNE ACTION;
       COMPARELIST UNE FONCTION(BOOLEEN);
       COPYTREE UNE FONCTION(ARB DE (entier,booleen)) ;
       REINITIALISERarbre UNE ACTION;
       INORDER_VERIF UNE ACTION;
       last_leaf UNE FONCTION(ARB DE (entier,booleen));
       inv_last_leaf,inv_next_leaf,next_leaf : FONCTION (ARB DE (ENTIER,BOOLEEN));
        FirstLeaf UNE ACTION;



         Root,TEMP,RACINE,Racine_copy UN ARB DE ( ENTIER , BOOLEEN ) ;
       K,L UNE STRUCTURE (ENTIER,BOOLEEN);
       iter un  ARB DE (ENTIER,BOOLEEN);
       Li,L1,L2 UNE LISTE;
       i un entier;

   DEBUT


        /* ce qui suit concerne la creation de l'arbre d'exemple du TP */
        INIT_STRUCT(K,[45,faux]);
        CREER_ARB(root,[K]);




        INIT_STRUCT(L,[20,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(root,TEMP);
        AFF_PERE(TEMP,root);



        INIT_STRUCT(L,[65,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(root,TEMP);
        AFF_PERE(TEMP,root);

        INIT_STRUCT(L,[35,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(fg(root),TEMP);
        AFF_PERE(TEMP,FG(root));

        INIT_STRUCT(L,[85,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FD(root),TEMP);
        AFF_PERE(TEMP,FD(root)) ;

        INIT_STRUCT(L,[10,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FG(root),TEMP);
        AFF_PERE(TEMP,FG(root));



        INIT_STRUCT(L,[55,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FD(root),TEMP);
        AFF_PERE(TEMP,FD(root)) ;



        INIT_STRUCT(L,[50,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FG(FD(root)),TEMP);
        AFF_PERE(TEMP,FG(FD(root))) ;

        INIT_STRUCT(L,[58,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FG(FD(root)),TEMP);
        AFF_PERE(TEMP,FG(FD(root)));






        INIT_STRUCT(L,[56,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FD(FG(FD(root))),TEMP);
        AFF_PERE(TEMP,FD(FG(FD(root))));


        INIT_STRUCT(L,[57,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FG(FD(FG(FD(root)))),TEMP);
        AFF_PERE(TEMP,FG(FD(FG(FD(root)))));

        INIT_STRUCT(L,[60,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FD(FG(FD(root))),TEMP);
        AFF_PERE(TEMP,FD(FG(FD(root))));


        INIT_STRUCT(L,[62,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FD(FD(FG(FD(root)))),TEMP);
        AFF_PERE(TEMP,FD(FD(FG(FD(root)))));

        INIT_STRUCT(L,[95,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FD(FD(root)),TEMP);
        AFF_PERE(TEMP,FD(FD(root))) ;


        INIT_STRUCT(L,[75,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FD(FD(root)),TEMP);
        AFF_PERE(TEMP,FD(FD(root))) ;



        INIT_STRUCT(L,[98,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FD(FD(FD(FD(root))),TEMP);
        AFF_PERE(TEMP,FD(FD(FD(root)))) ;


        INIT_STRUCT(L,[90,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FD(FD(FD(root))),TEMP);
        AFF_PERE(TEMP,FD(FD(FD(root)))) ;


        INIT_STRUCT(L,[88,faux]) ;
        CREERNOEUD(TEMP);
        AFF_INFO(TEMP,L);
        AFF_FG(FG(FD(FD(FD(root)))),TEMP);
        AFF_PERE(TEMP,FG(FD(FD(FD(root))))) ;

        /*ce qui suit est le programme principale*/
        POUR i:= 1,10  /*10 arbres*/

             APPEL RANDOMarbre(Racine,100);  /*100 noeuds*/
             APPEL Randomarbre_verif(racine)  ;
             APPEL BBLR(Racine,L1);
             APPEL BBLR_verif(Racine,L1);
             APPEL BBRL(Racine,L1);
             APPEL BBRL_verif(Racine,L1);
             APPEL LLRL(Racine);
             APPEL LLRL_verif(Racine);
             APPEL LLLR(Racine);
             APPEL LLLR_verif(Racine);

        Fpour;


   FIN







ACTION Randomarbre ( R , N )
   SOIENT
       R UN ARB DE ( ENTIER , BOOLEEN ) ;
       N , Cmp , Random DES ENTIERS ;
       Iter , Temps UN ARB DE ( ENTIER , BOOLEEN ) ;
       Trouv UN BOOLEEN ;
       S,J UNE STRUCTURE (ENTIER,BOOLEEN);
   DEBUT
        ECRIRE('NOUS ALLONS PROCEDER A LA CREATION De L ARBRE SES NOEUDS SONT :');
        Random := ALEANOMBRE(100);

        INIT_STRUCT ( J , [ Random , FAUX ] ) ;
        CREERNOEUD ( R ) ;
        AFF_INFO ( R , J ) ;

       Cmp := 1 ;
       TQ Cmp < N :
          Iter := R ;
          Trouv := FAUX ;
          Random := ALEANOMBRE(100);


       TQ Trouv = FAUX :


                SI Random = STRUCT(INFO ( Iter ),1) :
                     Trouv := vrai;
                     cmp := cmp -1;
                FSI;


               SI Random < STRUCT(INFO ( Iter ),1) :
                   SI ( FG ( Iter ) = NIL ) :

                       INIT_STRUCT ( S , [ Random , FAUX ] ) ;
                       CREERNOEUD ( Temps ) ;
                       AFF_INFO ( Temps , S ) ;
                       AFF_FG ( Iter , Temps ) ;
                       AFF_PERE(TEMPs,iter);
                       Trouv := VRAI ;
                       ecrire(STRUCT(info(temps),1) );


                   SINON
                       Iter := FG ( Iter ) ;
                   FSI
               FSI;

               SI Random > STRUCT(INFO ( Iter ),1) :
                   SI ( FD ( Iter ) = NIL ) :
                       INIT_STRUCT ( S , [ Random , FAUX ] ) ;
                       CREERNOEUD ( Temps ) ;
                       AFF_INFO ( Temps , S ) ;
                       AFF_FD ( Iter , Temps ) ;
                       AFF_PERE(TEMPs,iter);
                       Trouv := VRAI ;
                       ecrire(STRUCT(info(temps),1) );
                   SINON
                       Iter := FD ( Iter )
                   FSI ;




               FSI ;
           FTQ ;
             Cmp := Cmp + 1 ;
       FTQ ;

   FIN

ACTION Randomarbre_VERIF(rac)
SOIT
    L,iter UNE LISTE DE ENTIERS;
    rac un ARB DE (entiers,booleen);
    correcte un booleen;
DEBUT
     correcte := vrai;
     CREER_LISTE(L,[0]);
     iter := L;
     APPEL INORDER_VERIF(rac,L);
     TQ((suivant(iter) # NIL) et (CORRECTE = vrai))
             si ( valeur(iter) > valeur(suivant(iter)) )
                 correcte := faux;
             FSI;
             iter := suivant(iter);
      FTQ;

      SI correcte = vrai
         ecrire('ARBRE CORRECTEMENT CONSTRUIT !!!!!');
      SINON
         ecrire('ARBRE MAL CONSTRUIT');
      fsi;
FIN




/*-------------------------------LE 1 et 3 PARCOURS ----------------------*/


/*Voici comment nous allons effectuer le parcours :
-on descend vers la premiere feuille et a chaque noeud si celui si a
un fils droit et gauche on empile le fils droit
-une fois arrivé a une feuille on remonte et on met les champs des
noeuds parcourue a visited jusqu'a la racine ou trouver un noeud deja visited
-on depile et recommence l'operation jusqu'a ce que la pile sois vide et le
parent du noeud courant est visited (nous avons parcourue tout les noeuds)
*/
Action BBLR(root,L1)
Soit
    L1 une liste de entier;
    iter,root UN ARB DE (ENTIER,BOOLEEN) ;
    Stack UNE PILE DE ARB DE (ENTIER,BOOLEEN)  ;
    allVisited UN BOOLEEN;
    isaleaf,adeuxenfants,aquefilsgauche,aquefilsdroit,apasdepere UN BOOLEEN ;
DEBUT
     ECRIRE('NOUS ALLONS PROCEDER AU PARCOURS BBLR : ');
     iter := root ;
     CREERPILE(Stack);
     allvisited := FAUX;
     TQ allvisited = faux :
        TQ (allvisited = faux  ) :
           isaleaf := faux;
           adeuxenfants := faux;
           aquefilsgauche := faux;
           aquefilsdroit := faux;

           TQ ( isaleaf = faux )  :
               adeuxenfants := faux;
               aquefilsgauche := faux;
               aquefilsdroit := faux;
               apasdepere := faux ;

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isaleaf := vrai;
              FSI;

              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isaleaf := VRAI ;
                  SINON
                       aquefilsgauche := VRAI;
                  FSI;
              FSI;


              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isaleaf := VRAI ;
                  SINON
                       aquefilsdroit := VRAI;
                  FSI;
              FSI;



              SI ( FD(iter) # NIL ) ET ( FG(iter) # NIL ) :
                  SI ( STRUCT(info(FD(iter)),2) = VRAI  ) ET  (STRUCT(info(FG(iter)),2) = VRAI ):
                      isaleaf := VRAI ;
                  FSI;

                  SI ( STRUCT(info(FD(iter)),2) = VRAI  ) ET  (STRUCT(info(FG(iter)),2) = FAUX ) :
                       aquefilsgauche:= VRAI;
                  FSI;



                  SI ( STRUCT(info(FD(iter)),2) = FAUX  ) ET  (STRUCT(info(FG(iter)),2) = VRAI ) :
                       aquefilsdroit:= VRAI;
                  FSI;



                  SI ( STRUCT(info(FD(iter)),2) = FAUX  ) ET  (STRUCT(info(FG(iter)),2) = FAUX ) :
                       adeuxenfants:= VRAI;
                  FSI;


              FSI;



              SI ( adeuxenfants = vrai ) :
                 EMPILER(STACK,FD(iter));
                 iter := FG(iter);
              FSI ;

            SI ( aquefilsgauche = vrai )
               iter := FG(iter);
            FSI;


        SI (aquefilsdroit = vrai )
           iter := FD(iter);
        FSI ;



        FTQ  ;

        TQ  ( apasdepere = faux ) :
            SI ((pere(iter)) = NIL )
                apasdepere := VRAI;

            SINON
                 SI STRUCT(info(pere(iter)),2) = VRAI
                    apasdepere := VRAI;
                 FSI;
            FSI;
                      APPEL INSERT_LIST(L1,STRUCT(info(iter),1));
                      AFF_STRUCT(info(iter),2,VRAI);
                      ECRIRE(STRUCT(info(iter),1));
                      iter := pere(iter);
        FTQ ;

        SI Pilevide(Stack) = FAUX  :
           DEPILER(stack,iter)  ;
           apasdepere := FAUX;
        SINON
             allvisited := VRAI;
         FSI;
     FTQ;
     FTQ;
     APPEL REINITIALISERarbre(root);
FIN



/* DE meme pour cette fonction sauf que on descend a droite et on empile le fils gauche*/
ACTION BBRL ( root,L1  )
Soit

    iter,root UN ARB DE (ENTIER,BOOLEEN) ;
    Stack UNE PILE DE ARB DE (ENTIER,BOOLEEN)  ;
    allVisited UN BOOLEEN;
    isaleaf,adeuxenfants,aquefilsgauche,aquefilsdroit,apasdepere UN BOOLEEN ;
    L1 UNE LISTE DE ENTIERS;
DEBUT
     ECRIRE('NOUS ALLONS PROCEDER AU PARCOURS BBRL : ');
     iter := root ;
     CREERPILE(Stack);
     allvisited := FAUX;
     TQ allvisited = faux :
        TQ (allvisited = faux  ) :
           isaleaf := faux;
           adeuxenfants := faux;
           aquefilsgauche := faux;
           aquefilsdroit := faux;

           TQ ( isaleaf = faux )  :
               adeuxenfants := faux;
               aquefilsgauche := faux;
               aquefilsdroit := faux;
               apasdepere := faux ;

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isaleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isaleaf := VRAI ;
                  SINON
                       aquefilsgauche := VRAI;
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isaleaf := VRAI ;
                  SINON
                       aquefilsdroit := VRAI;
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isaleaf := VRAI ;
                  FSI;

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       aquefilsgauche:= VRAI;
                  FSI;



                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       aquefilsdroit:= VRAI;
                  FSI;



                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       adeuxenfants:= VRAI;
                  FSI;


              FSI;



              SI ( adeuxenfants = vrai ) :
                 EMPILER(STACK,FG(iter));
                 iter := FD(iter);
              FSI ;

            SI ( aquefilsgauche = vrai )
               iter := FD(iter);
            FSI;


        SI (aquefilsdroit = vrai )
           iter := FG(iter);
        FSI ;



        FTQ  ;

        TQ  ( apasdepere = faux ) :
            SI ((pere(iter)) = NIL )
                apasdepere := VRAI;

            SINON
                 SI STRUCT(info(pere(iter)),2) = VRAI
                    apasdepere := VRAI;
                 FSI;
            FSI;
                      APPEL INSERT_LIST(L1,STRUCT(info(iter),1));
                      AFF_STRUCT(info(iter),2,VRAI);
                      ECRIRE(STRUCT(info(iter),1));
                      iter := pere(iter);
        FTQ ;

        SI Pilevide(Stack) = FAUX  :
           DEPILER(stack,iter)  ;
           apasdepere := FAUX;
        SINON
             allvisited := VRAI;
         FSI;
     FTQ;
     FTQ;
      APPEL REINITIALISERarbre(root);
FIN

/*cette fonction va parcourir l'arbre branche par branche et mettre les elements dans une liste
 si l'element n'existe pas deja puis comparer la liste avec la liste crée lors du vrai parcours*/

ACTION BBRL_VERIF(rac,L1)
SOIENT
      rac,iter un ARB DE (entiers,BOOLEEN);
      L2,L1 UNE LISTE;
      isleaf UN BOOLEEN;
      STACK UNE PILE DE ENTIER;
DEBUT
    CREERPILE(STACK);
    APPEL BranchTravesral(rac,stack,L2);
     SI ( COMPARELIST(L1,L2) = vrai )
        ecrire ('LE PARCOURS EST CORRECTE');
     SINON
          ecrire('LE PARCOURS EST FAUX');
     FSI;
FIN

/*cette fonction va parcourir l'arbre branche par branche et mettre les elements dans une liste
 si l'element n'existe pas deja puis comparer la liste avec la liste crée lors du vrai parcours*/
ACTION BBLR_VERIF(rac,L1)
SOIENT
      rac,iter un ARB DE (entiers,BOOLEEN);
      L2,L1 UNE LISTE;
      isleaf UN BOOLEEN;
      STACK UNE PILE DE ENTIER;
DEBUT
    CREERPILE(STACK);
    APPEL BranchTravesral(rac,stack,L2);
     SI ( COMPARELIST(L1,L2) = vrai )
        ecrire ('LE PARCOURS EST CORRECTE !!');
     SINON
          ecrire('LE PARCOURS EST FAUX !!');
     FSI;
FIN








/*-----------------------------------------LES parcours 2 et 4----------------*/


/* Pour effectuer ce parcours on trouvera d'abord la premiere feuille
et on met son champ visited puis on trouve la prochaine feuille avec
next_leaf et on la met visited jusqu'a trouver la derniere feuille
dans ce cas on remonte a la racine*/

 ACTION LLLR (rac)
SOIENT
rac,temp UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN);
isleaf,allvisited UN BOOLEEN  ;
DEBUT
ECRIRE('NOUS ALLONS PROCEDER AU PARCOURS LLLR :');
allvisited := faux;
TQ ( allvisited = faux )
APPEL FirstLeaf(rac,iter,isleaf) ;

  SI (iter = rac) ET (isleaf = vrai)
     allvisited := VRAI;
  FSI;

TANTQUE (iter <> last_leaf(rac)  ) :
           AFF_STRUCT(info(iter),2,VRAI);
           ECRIRE(STRUCT(info(iter),1));
           iter := next_leaf(rac,iter) ;
FINTANTQUE  ;


     AFF_STRUCT(info(iter),2,VRAI);
     ECRIRE(STRUCT(info(iter),1));
     iter :=rac  ;

FTQ;
APPEL REINITIALISERARBRE(rac);
FIN

/* Pour effectuer ce parcours on trouvera d'abord la premiere
feuille et on met son champ visited puis on trouve la prochaine feuille avec
next_leaf et on la met visited jusqu'a trouver la derniere feuille dans
ce cas on remonte a la racine sauf que cette fois ci de droite a gauche*/

ACTION LLRL (rac)
SOIENT
rac,temp UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN);
isleaf,allvisited UN BOOLEEN  ;
DEBUT
ECRIRE('NOUS ALLONS PROCEDER AU PARCOURS LLRL : ');
allvisited := faux;
TQ (allvisited = faux )
iter := last_leaf(rac);

  SI (iter = rac)
     allvisited := VRAI;
  FSI;
TANTQUE (iter <> inv_last_leaf(rac)  ) :
           AFF_STRUCT(info(iter),2,VRAI);
            ECRIRE(STRUCT(info(iter),1));
            iter := inv_next_leaf(rac,iter);
FINTANTQUE  ;
     AFF_STRUCT(info(iter),2,VRAI);
     ECRIRE(STRUCT(info(iter),1));
     iter :=rac  ;
FTQ;
APPEL REINITIALISERARBRE(rac);
FIN

/*on verifie le parcours en supprimant les feuilles et a a fin il ne devrait en rester aucune*/
ACTION LLLR_verif (rac)
SOIENT
rac,temp,per,racine_copy,parent UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN);
isleaf,allvisited UN BOOLEEN  ;
DEBUT
racine_copy := COPYTREE(rac,parent);
allvisited := faux;
TQ ( allvisited = faux )
APPEL FirstLeaf(racine_copy,iter,isleaf) ;

  SI (iter = racine_copy) ET (isleaf = vrai)
     allvisited := VRAI;
  FSI;

TANTQUE (iter <> last_leaf(racine_copy)  ) :

           si pere(iter) # NIL
              per := pere(iter);

            temp := iter ;
            iter := next_leaf(racine_copy,iter) ;
            si temp = fg(per)
               AFF_FG(per,NIL);
            SINON
               AFF_FD(per,NIL);
            FSI;
            LIBERERNOEUD(temp);
            SINON
                 racine_copy := NIL;
            FSI;



FINTANTQUE  ;

           si pere(iter) # NIL
              per := pere(iter);
              temp := iter ;
            si temp = fg(per)
               AFF_FG(per,NIL);
            SINON
               AFF_FD(per,NIL);
            FSI;
            LIBERERNOEUD(temp);
            SINON
                 racine_copy := NIL;
           FSI;
           iter := racine_copy;

FTQ;

SI racine_copy = NIL :
   ecrire('LE PARCOURS EST CORRECTE !!!!');
SINON
     ecrire('LE PARCOURS EST FAUX !!!!!');
FSI;
FIN



/*on verifie le parcours en supprimant les feuilles et a a fin il ne devrait en rester aucune*/
ACTION LLRL_VERIF (rac)
SOIENT
rac,temp,per,racine_copy,parent UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN);
isleaf,allvisited UN BOOLEEN  ;
DEBUT
racine_copy := COPYTREE(rac,parent);
allvisited := faux;
TQ (allvisited = faux )
iter := last_leaf(racine_copy);

  SI (iter = racine_copy)
     allvisited := VRAI;
  FSI;
TANTQUE (iter <> inv_last_leaf(racine_copy)  ) :
            si pere(iter) # NIL
              per := pere(iter);

            temp := iter ;
            iter := inv_next_leaf(racine_copy,iter) ;
            si temp = fg(per)
               AFF_FG(per,NIL);
            SINON
               AFF_FD(per,NIL);
            FSI;
            LIBERERNOEUD(temp);
            SINON
                 racine_copy := NIL;
            FSI;
FINTANTQUE  ;

       si pere(iter) # NIL
              per := pere(iter);
              temp := iter ;
            si temp = fg(per)
               AFF_FG(per,NIL);
            SINON
               AFF_FD(per,NIL);
            FSI;
            LIBERERNOEUD(temp);
            SINON
                 racine_copy := NIL;
           FSI;
           iter := racine_copy;
FTQ;


SI racine_copy = NIL :
   ecrire('LE PARCOURS EST CORRECTE !!');
SINON
     ecrire('LE PARCOUR EST FAUX !!!!');
FSI;
FIN

/*---------------------------------Les fonctions intermediaires-----------*/
ACTION REINITIALISERarbre(rac)
SOIT
    rac un ARB de (entier,booleen);
DEBUT
     SI (rac # nil)
     APPEL REINITIALISERarbre(fg(rac));
     AFF_STRUCT(info(rac),2,FAUX) ;
     APPEL REINITIALISERarbre(fd(rac));
     fsi;
FIN


FONCTION COPYTREE(rac,parent) : ARB de (ENTIERS,BOOLEEN)
soient
      rac,temp,parent un arb de (entiers,booleen);
DEBUT
     SI rac = NIL
        COPYTREE := NIL;
     SINON
        CREERNOEUD(temp);
        AFF_INFO(TEMP,info(rac));
        AFF_FD(temp,COPYTREE(fd(rac),temp));
        AFF_FG(temp,COPYTREE(fg(rac),temp));
        AFF_PERE(temp,parent);
        COPYTREE := TEMP;
     FSI ;
FIN

ACTION INORDER_VERIF(rac,L)
SOIT
rac un ARB DE (entiers,Booleen);
iter une liste DE ENTIER;
correcte UN BOOLEEN;
L UNE LISTE DE ENTIER;
DEBUT
     iter := L;
     SI rac # NIL  :
        APPEL INORDER_VERIF(fg(rac),L);
        APPEL INSERT_LIST(L, STRUCT(info(rac),1)  );
        APPEL INORDER_VERIF(fd(rac),L);
     FSI;

FIN


/*Insere une valeur dans une liste */
ACTION INSERT_LIST(L1,val)
SOIENT
      L1,iter,temp UNE LISTE;
      val UN ENTIER;
      doublon UN BOOLEEN;
DEBUT
     iter := L1;
     doublon := FAUX;
     si iter = NIL :
        ALLOUER(iter) ;
        AFF_VAl(iter,val);
     SINON
     TQ ( (SUIVANT(iter) # NIL) ET (doublon = FAUX))
        SI ( valeur(iter) # val )
           iter := SUIVANT(iter);
        SINON
        doublon := VRAI ;
        FSI;
     FTQ;

     SI doublon = faux
        ALLOUER(temp) ;
        AFF_ADR(iter,temp);
        AFF_VAl(temp,val);
     FSI;
     fsi;
FIN





FONCTION COMPARELIST(L1,L2) : BOOLEEN
SOIENT
      L1,L2 des listes DE ENTIERS ;
      iter1,iter2 DES LISTES DE ENTIERS;
      EGALE UN BOOLEEN;
DEBUT
     EGALE := VRAI;
     iter1 := L1;
     iter2 := L2;
     TQ ( (iter1 # NIL) ET (iter2 # NIL) ET (EGALE= VRAI))
        SI valeur(iter1) # valeur(iter2)
           egale := FAUX
        FSI;
        iter1 := suivant(iter1);
        iter2 := suivant (iter2);
     FTQ;
     si ((iter1 = NIL) et (iter2 # nil))  ou   (  (iter1 # NIL) et (iter2 = nil) )
        egale := FAUX;
     FSI;
COMPARELIST := egale
FIN



ACTION BranchTravesral (RAC,stack,L1)
soit
rac un arb de (entier,booleen);
STACK une PILE de ENTIER  ;
L1 UNE LISTE DE ENTIERS;
temp un entier;
DEBUT

SI( rac # NIL )

EMPILER(STACK, STRUCT(info(rac),1));
SI ( (fd(rac) = NIL) ET (fg(rac) = NIL) )

   TQ(PILEVIDE(STACK) # VRAI )
                      DEPILER(STACK,temp);
                      APPEL INSERT_LIST(L1,temp);

   FTQ;
FSI;
APPEL BranchTravesral(fg(rac),stack,L1);
APPEL BranchTravesral(fd(rac),stack,L1);
FSI;
FIN






ACTION INV_BRANCHTRAVERSAL (RAC,stack,L1)
soit
rac un arb de (entier,booleen);
STACK une PILE de ENTIER  ;
L1 UNE LISTE DE ENTIERS;
temp un entier;
DEBUT

SI( rac # NIL )

EMPILER(STACK, STRUCT(info(rac),1));
SI ( (fd(rac) = NIL) ET (fg(rac) = NIL) )

   TQ(PILEVIDE(STACK) # VRAI )
                      DEPILER(STACK,temp);
                      APPEL INSERT_LIST(L1,temp);

   FTQ;
FSI;
APPEL INV_BRANCHTRAVERSAL(fd(rac),stack,L1);
APPEL INV_BRANCHTRAVERSAL(fg(rac),stack,L1);
FSI;
FIN






FONCTION last_leaf(rac):ARB DE (ENTIER,BOOLEEN)
SOIENT
rac UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN) ;
isleaf UN BOOLEEN;
DEBUT
iter:=rac   ;
isleaf := faux;

TQ ( isleaf = faux )  :

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FD(iter);
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FG(iter);
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isleaf := VRAI ;
                  FSI;

              SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       iter := FD(iter);
                 SINON

                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       iter := FG(iter);
                 SINON


                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                      iter := FD(iter);
                  FSI;
               FSI;
               FSI;
               FSI;
FINTANTQUE ;
last_leaf := iter
FIN


ACTION FirstLeaf(root,iter,isleaf)
soit
    root,iter UN ARB DE (entier,booleen);
    isleaf UN BOOLEEN ;
DEBUT
     iter:=root   ;
     isleaf := faux;
    TQ ( isleaf = faux )  :

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FD(iter);
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FG(iter);
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isleaf := VRAI ;
                  FSI;

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       iter := FD(iter);
                  SINON
                         SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       iter := FG(iter);
                       SINON

                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                      iter := FG(iter);
                  FSI;
                  FSI;
                  FSI;
              FSI;


FINTANTQUE ;

fin



FONCTION next_leaf (rac,feui) : ARB DE (ENTIER,BOOLEEN)
SOIENT
feui,iter,rac,dernier UN ARB DE (ENTIER,BOOLEEN);
isleaf,afilsdroit UN BOOLEEN;
a une chaine;
Debut

   iter:=feui ;
   isleaf := FAUX;
   afilsdroit := faux;
   dernier := iter;
   iter:=PERE(iter) ;



   TANTQUE (afilsdroit = faux ) :
   SI ( FD(iter) # NIL )

       SI ( STRUCT (INFO(FD(iter)),2) = FAUX)

            si ( fd(iter) # dernier )

               afilsdroit := vrai ;
            sinon
              dernier := iter;
              iter:=PERE(iter) ;
          fsi;
     SINON

           dernier := iter;
          iter:=PERE(iter) ;
     FSI;
   FSI;

 SI ( FD(iter) = NIL )

        dernier := iter;
        iter := PERE(iter);

   FSI;







FINTANTQUE   ;
iter := FD(iter) ;

 TQ ( isleaf = faux )  :

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FD(iter);
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FG(iter);
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isleaf := VRAI ;
                  FSI;

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       iter := FD(iter);
                  SINON
                         SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       iter := FG(iter);
                       SINON

                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                      iter := FG(iter);
                  FSI;
                  FSI;
                  FSI;
              FSI;
FINTANTQUE ;


next_leaf:=iter ;




FIN



FONCTION inv_last_leaf(rac):ARB DE (ENTIER,BOOLEEN)
SOIENT
rac UN ARB DE (ENTIER,BOOLEEN);iter UN ARB DE (ENTIER,BOOLEEN) ;
isleaf UN BOOLEEN;
DEBUT
iter:=rac   ;
isleaf := faux;

TQ ( isleaf = faux )  :

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FD(iter);
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FG(iter);
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isleaf := VRAI ;
                  FSI;

              SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       iter := FD(iter);
                 SINON

                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       iter := FG(iter);
                 SINON


                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                      iter := FG(iter);
                  FSI;
               FSI;
               FSI;
               FSI;
FINTANTQUE ;
inv_last_leaf := iter ;
FIN



FONCTION inv_next_leaf (rac,feui) : ARB DE (ENTIER,BOOLEEN)
 SOIENT
feui,iter,rac,dernier UN ARB DE (ENTIER,BOOLEEN);
isleaf,afilsdroit UN BOOLEEN;
a une chaine;
Debut

   iter:=feui ;
   isleaf := FAUX;
   afilsdroit := faux;
   dernier := iter;
   iter:=PERE(iter) ;

   TANTQUE (afilsdroit = faux ) :
   SI ( FG(iter) # NIL )

       SI ( STRUCT (INFO(FG(iter)),2) = FAUX)

            si ( fG(iter) # dernier )

               afilsdroit := vrai ;
            sinon
              dernier := iter;
              iter:=PERE(iter) ;
          fsi;
     SINON

           dernier := iter;
          iter:=PERE(iter) ;
     FSI;
   FSI;

 SI ( FG(iter) = NIL )
        dernier := iter;
        iter := PERE(iter);

   FSI;

FINTANTQUE   ;
iter := FG(iter) ;

 TQ ( isleaf = faux )  :

              SI ( FG(iter) = NIL ) ET ( FD(iter) = NIL ) :
                  isleaf := vrai;
              FSI;

              SI ( FD(iter) # NIL ) ET ( FG(iter) = NIL ) :
                  SI  STRUCT(info(FD(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FD(iter);
                  FSI;
              FSI;


              SI ( FG(iter) # NIL ) ET ( FD(iter) = NIL ) :
                  SI  STRUCT(info(FG(iter)),2) = VRAI    :
                      isleaf := VRAI ;
                  SINON
                       iter := FG(iter);
                  FSI;
              FSI;



              SI ( FG(iter) # NIL ) ET ( FD(iter) # NIL ) :

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ):
                      isleaf := VRAI ;
                  FSI;

                  SI ( STRUCT(info(FG(iter)),2) = VRAI  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                       iter := FD(iter);
                  SINON
                         SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = VRAI ) :
                       iter := FG(iter);
                       SINON

                  SI ( STRUCT(info(FG(iter)),2) = FAUX  ) ET  (STRUCT(info(FD(iter)),2) = FAUX ) :
                      iter := FD(iter);
                  FSI;
                  FSI;
                  FSI;
              FSI;
FINTANTQUE ;


inv_next_leaf:=iter ;




FIN
















