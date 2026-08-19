/**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE ENTIERS**/
  /** Piles **/

  typedef Pointeur_Ai Typeelem_PAi ;
  typedef struct Maillon_PAi * Pointeur_PAi ;
  typedef   Pointeur_PAi  Typepile_PAi  ;

  struct Maillon_PAi
    {
      Typeelem_PAi  Val ;
      Pointeur_PAi Suiv ;
    } ;

  void Creerpile_PAi( Pointeur_PAi *P )
    { *P = NULL ; }

  bool Pilevide_PAi ( Pointeur_PAi P )
    { return  (P == NULL ); }

  void Empiler_PAi ( Pointeur_PAi *P,  Typeelem_PAi Val )
    {
      Pointeur_PAi Q;

      Q = (struct Maillon_PAi *) malloc( sizeof( struct Maillon_PAi))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PAi ( Pointeur_PAi *P,  Typeelem_PAi *Val )
    {
      Pointeur_PAi Sauv;

      if (! Pilevide_PAi (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }

   
  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai A3=NULL;
  Pointeur_Ai R=NULL;
  Pointeur_Ai B=NULL;
  Pointeur_Ai C=NULL;
  Pointeur_Ai P=NULL;
  Pointeur_Ai Q=NULL;
  Pointeur_Ai P1=NULL;
  Pointeur_PAi Pi=NULL;
  Pointeur_Ai Premier1=NULL;
  Pointeur_Ai Premier2=NULL;
  int Ma;
  int Mi;
  int M;
  int N;
  int I;
  int  _Px1;
  int  _Px2;
  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  int Min (int a, int b)
    {
      if (a < b) return(a);
      else return(b);
    }


  /** Prototypes des fonctions **/

  int  Maxtree (Pointeur_Ai *A) ;
  int  Mintree (Pointeur_Ai *A) ;
  bool  Estabr (Pointeur_Ai *A) ;
  int  Minimum (int *A , int *B) ;
  Pointeur_Ai Feuilleplusgauche (Pointeur_Ai *R) ;
  void Afficher_pile (Pointeur_PAi *Pi);
  void Chemin_pere_racine (Pointeur_Ai *Racine , int *Val , Pointeur_PAi *Pi);
  bool  Recherche (Pointeur_Ai *A , int *Val) ;
  void Ins (Pointeur_Ai *A , int *Val);
  void Generer_bst (Pointeur_Ai *A , int *N);
  void Inordre (Pointeur_Ai *Racine);
  Pointeur_Ai Premierinordre (Pointeur_Ai *R) ;
  void Depilement (Pointeur_PAi *Pi , Pointeur_Ai *N , bool *Possible);
  Pointeur_Ai Suivant_inordre (Pointeur_PAi *Pi , Pointeur_Ai *P) ;
  void Preordre (Pointeur_Ai *Racine);
  Pointeur_Ai Montee_gauche_fd (Pointeur_PAi *Pi , Pointeur_Ai *P1) ;
  Pointeur_Ai Premier_preordre (Pointeur_Ai *Racine) ;
  Pointeur_Ai Suivant_preordre (Pointeur_PAi *Pi , Pointeur_Ai *P) ;
  void Postordre (Pointeur_Ai *R);
  Pointeur_Ai Premier_postordre (Pointeur_Ai *R) ;
  Pointeur_Ai Suivant_postordre (Pointeur_PAi *Pi , Pointeur_Ai *P , Pointeur_Ai *Racine) ;
  void Inordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Preordre_preordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Postordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Preordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Inordre_preordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  bool  Inclusion (Pointeur_Ai *A1 , Pointeur_Ai *A2) ;
  bool  Valide (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3) ;

  int  Maxtree (Pointeur_Ai *A)
    {
      /** Variables locales **/
      int  Maxtree2 ;
      Pointeur_Ai Iter=NULL;
      Pointeur_Ai Maa=NULL;
      Pointeur_PAi Pi=NULL;

      /** Corps du module **/
     Iter  =  Premierinordre ( & *A ) ;
     while( Iter != NULL)  {
       Maa  =  Iter ;
       Iter  =  Suivant_inordre ( & Pi , & Iter ) ;
     
     } ;
     Maxtree2  =  Info_Ai ( Maa ) ;
   
     return Maxtree2 ;
    }
  int  Mintree (Pointeur_Ai *A)
    {
      /** Variables locales **/
      int  Mintree2 ;

      /** Corps du module **/
     Mintree2  =  Info_Ai ( Premierinordre ( & *A ) ) ;
   
     return Mintree2 ;
    }
  bool  Estabr (Pointeur_Ai *A)
    {
      /** Variables locales **/
      bool  Estabr2 ;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;
      Pointeur_Ai _Px3=NULL;
      Pointeur_Ai _Px4=NULL;

      /** Corps du module **/
     Estabr2  =  True ;
     if( *A == NULL)   {
       Estabr2  =  True ;
       }
     else
       {
       if( Fg_Ai ( *A ) != NULL)   {
         _Px1 =  Fg_Ai ( *A );
         if( Info_Ai ( *A ) < Maxtree ( &_Px1))   {
           Estabr2  =  False ;
         
         } }
       else
         {
         if( Fd_Ai ( *A ) != NULL)   {
           _Px2 =  Fd_Ai ( *A ) ;
           if( Info_Ai ( *A ) > Mintree ( &_Px2))   {
             Estabr2  =  True ;
           
           } }
         else
           {
           _Px3 =  Fg_Ai ( *A ) ;
           _Px4 =  Fd_Ai ( *A ) ;
           Estabr2  =  Estabr ( &_Px3) && Estabr ( &_Px4) ;
         
         }
       }
     }
     return Estabr2 ;
    }
    
    
  int  Minimum (int *A , int *B)
    {
      /** Variables locales **/
      int  Minimum2 ;

      /** Corps du module **/
     if( ( *A <= *B )) {
       Minimum2  =  *A ;
       }
     else
       {
       Minimum2  =  *B ;
     
     }
     return Minimum2 ;
    }
  Pointeur_Ai Feuilleplusgauche (Pointeur_Ai *R)
    {
      /** Variables locales **/
      Pointeur_Ai Feuilleplusgauche2 =NULL;
      Pointeur_Ai P=NULL;
      bool Continu;

      /** Corps du module **/
     P  =  *R ;
     Continu  =  True ;
     while( ( Continu == True )) {
       while( ( Fg_Ai ( P ) != NULL )) {
         P  =  Fg_Ai ( P ) ;
       
       } ;
       if( ( Fd_Ai ( P ) != NULL )) {
         P  =  Fd_Ai ( P ) ;
         }
       else
         {
         Continu  =  False ;
       
       }
     } ;
     Feuilleplusgauche2  =  P ;
   
     return Feuilleplusgauche2 ;
    }
  void Afficher_pile (Pointeur_PAi *Pi)
    {
      /** Variables locales **/
      Pointeur_Ai Noeud=NULL;

      /** Corps du module **/
     while( ( ! Pilevide_PAi ( *Pi ) )) {
       Depiler_PAi (& *Pi , &Noeud ) ;
       printf ( " %d", Info_Ai(Noeud) ) ;
     
     }
    }
  void Chemin_pere_racine (Pointeur_Ai *Racine , int *Val , Pointeur_PAi *Pi)
    {
      /** Variables locales **/
      Pointeur_Ai R=NULL;
      Pointeur_Ai Nettoyage=NULL;

      /** Corps du module **/
     if( ! Pilevide_PAi ( *Pi )) {
       while( ! Pilevide_PAi ( *Pi )) {
         Depiler_PAi (& *Pi , &Nettoyage ) ;
       
       } ;
     
     } ;
     R  =  *Racine ;
     if( ( R != NULL )) {
       while( ( Info_Ai ( R ) != *Val ) && ( R != NULL )) {
         if( ( *Val > Info_Ai ( R ) )) {
           Empiler_PAi (& *Pi , R ) ;
           R  =  Fd_Ai ( R ) ;
           }
         else
           {
           Empiler_PAi (& *Pi , R ) ;
           R  =  Fg_Ai ( R ) ;
         
         } ;
       
       } ;
     
     }
    }
  bool  Recherche (Pointeur_Ai *A , int *Val)
    {
      /** Variables locales **/
      bool  Recherche2 ;
      Pointeur_Ai R=NULL;
      bool Stop;

      /** Corps du module **/
     R  =  *A ;
     Stop  =  False ;
     while( ( R != NULL ) && ( ! Stop )) {
       if( Info_Ai ( R ) == *Val)   {
         Stop  =  True ;
       
       } ;
       if( *Val < Info_Ai ( R ))   {
         R  =  Fg_Ai ( R ) ;
         }
       else
         {
         if( *Val > Info_Ai ( R ))   {
           R  =  Fd_Ai ( R ) ;
         
         }
       }
     } ;
     if( Stop == True)   {
       Recherche2  =  True ;
       }
     else
       {
       Recherche2  =  False ;
     
     }
     return Recherche2 ;
    }
  void Ins (Pointeur_Ai *A , int *Val)
    {
      /** Variables locales **/
      Pointeur_Ai R=NULL;
      Pointeur_Ai Per=NULL;

      /** Corps du module **/
     if( *A == NULL)   {
       Creernoeud_Ai (& *A ) ;
       Aff_info_Ai ( *A , *Val ) ;
       }
     else
       {
       R  =  *A ;
       Per  =  R ;
       while( R != NULL)  {
         if( *Val <= Info_Ai ( R ))   {
           Per  =  R ;
           R  =  Fg_Ai ( R ) ;
           }
         else
           {
           Per  =  R ;
           R  =  Fd_Ai ( R ) ;
         
         }
       } ;
       if( *Val <= Info_Ai ( Per ))   {
         Creernoeud_Ai (& R ) ;
         Aff_info_Ai ( R , *Val ) ;
         Aff_fg_Ai ( Per , R ) ;
         }
       else
         {
         Creernoeud_Ai (& R ) ;
         Aff_info_Ai ( R , *Val ) ;
         Aff_fd_Ai ( Per , R ) ;
       
       }
     }
    }
  void Generer_bst (Pointeur_Ai *A , int *N)
    {
      /** Variables locales **/
      int K;
      int I;

      /** Corps du module **/
     Creernoeud_Ai (& *A ) ;
     K  =  Aleanombre(10000 ) ;
     Aff_info_Ai ( *A , K ) ;
     for( I  =  1 ;I <=  *N - 1 ; ++I) {
       K  =  Aleanombre(10000 ) ;
       while( ( Recherche ( & *A , & K ) == True ))  {
         K  =  Aleanombre(10000 ) ;
       
       } ;
       Ins ( & *A , & K ) ;
     
     }
    }
  void Inordre (Pointeur_Ai *Racine)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( ( *Racine != NULL )) {
       _Px1 =  Fg_Ai ( *Racine ) ;
       Inordre ( &_Px1) ;
       printf ( " %d", Info_Ai(*Racine) ) ;
       _Px2 =  Fd_Ai ( *Racine ) ;
       Inordre ( &_Px2) ;
     
     }
    }
  Pointeur_Ai Premierinordre (Pointeur_Ai *R)
    {
      /** Variables locales **/
      Pointeur_Ai Premierinordre2 =NULL;
      Pointeur_Ai N=NULL;

      /** Corps du module **/
     N  =  *R ;
     while( ( Fg_Ai ( N ) != NULL )) {
       N  =  Fg_Ai ( N ) ;
     
     } ;
     Premierinordre2  =  N ;
   
     return Premierinordre2 ;
    }
  void Depilement (Pointeur_PAi *Pi , Pointeur_Ai *N , bool *Possible)
    {

      /** Corps du module **/
     if( ! Pilevide_PAi ( *Pi )) {
       Depiler_PAi (& *Pi , &*N ) ;
       *Possible  =  True ;
       }
     else
       {
       *Possible  =  False ;
     
     }
    }
  Pointeur_Ai Suivant_inordre (Pointeur_PAi *Pi , Pointeur_Ai *P)
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_inordre2 =NULL;
      bool Stop;
      Pointeur_Ai N=NULL;
      bool Possible;

      /** Corps du module **/
     if( *P == NULL) {
       Suivant_inordre2  =  NULL ;
       }
     else
       {
       if( Fd_Ai ( *P ) != NULL) {
         *P  =  Fd_Ai ( *P ) ;
         while( Fg_Ai ( *P ) != NULL) {
           *P  =  Fg_Ai ( *P ) ;
         
         } ;
         Suivant_inordre2  =  *P; }
       else
         {
         Depilement ( & *Pi , & N , & Possible ) ;
         Stop  =  False ;
         while( ( Stop == False ) && ( Possible == True )) {
           if( ( *P == Fg_Ai ( N ) )) {
             Stop  =  True; }
           else
             {
             *P  =  N ;
             Depilement ( & *Pi , & N , & Possible ) ;
           
           } ;
         
         } ;
         if( Stop == True) {
           Suivant_inordre2  =  N; }
         else
           {
           Suivant_inordre2  =  NULL;
         } ;
       
       } ;
     
     } ;
   
     return Suivant_inordre2 ;
    }
  void Preordre (Pointeur_Ai *Racine)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( ( *Racine != NULL )) {
       printf ( " %d", Info_Ai(*Racine) ) ;
       _Px1 =  Fg_Ai ( *Racine ) ;
       Preordre ( &_Px1) ;
       _Px2 =  Fd_Ai ( *Racine ) ;
       Preordre ( &_Px2) ;
     
     }
    }
  Pointeur_Ai Montee_gauche_fd (Pointeur_PAi *Pi , Pointeur_Ai *P1)
    {
      /** Variables locales **/
      Pointeur_Ai Montee_gauche_fd2 =NULL;
      bool Stop;
      bool Possible;
      bool Mg;
      Pointeur_Ai Per=NULL;
      Pointeur_Ai N=NULL;

      /** Corps du module **/
     Stop  =  False ;
     Depilement ( & *Pi , & N , & Possible ) ;
     if( ( Pilevide_PAi ( *Pi ) == True )) {
       if( ( N != NULL ) && ( Fd_Ai ( N ) != *P1 )) {
         Montee_gauche_fd2  =  Fd_Ai ( N ) ;
         }
       else
         {
         Montee_gauche_fd2  =  NULL ;
       
       } }
     else
       {
       while( ( Stop == False ) && ( ! Pilevide_PAi ( *Pi ) )) {
         Depilement ( & *Pi , & Per , & Possible ) ;
         if( ( Fg_Ai ( Per ) == N )) {
           Mg  =  True ;
           }
         else
           {
           Mg  =  False ;
         
         } ;
         if( ( Fd_Ai ( Per ) != NULL ) && ( Mg == True )) {
           Montee_gauche_fd2  =  Fd_Ai ( Per ) ;
           Stop  =  True ;
         
         } ;
         Empiler_PAi (& *Pi , Per ) ;
         Depilement ( & *Pi , & N , & Possible ) ;
       
       } ;
       if( ( Stop == False )) {
         Montee_gauche_fd2  =  NULL ;
       
       }
     }
     return Montee_gauche_fd2 ;
    }
  Pointeur_Ai Premier_preordre (Pointeur_Ai *Racine)
    {
      /** Variables locales **/
      Pointeur_Ai Premier_preordre2 =NULL;

      /** Corps du module **/
     Premier_preordre2  =  *Racine ;
   
     return Premier_preordre2 ;
    }
  Pointeur_Ai Suivant_preordre (Pointeur_PAi *Pi , Pointeur_Ai *P)
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_preordre2 =NULL;
      Pointeur_Ai N=NULL;
      Pointeur_Ai Sauv=NULL;
      bool Stop;

      /** Corps du module **/
     Stop  =  False ;
     if( Fg_Ai ( *P ) != NULL) {
       Suivant_preordre2  =  Fg_Ai ( *P ) ;
       }
     else
       {
       if( Fd_Ai ( *P ) != NULL) {
         Suivant_preordre2  =  Fd_Ai ( *P ) ;
         }
       else
         {
         if( ! Pilevide_PAi ( *Pi )) {
           Depiler_PAi (& *Pi , &Sauv ) ;
           if( ( Fd_Ai ( Sauv ) != NULL ) && ( Fg_Ai ( Sauv ) == *P )) {
             Suivant_preordre2  =  Fd_Ai ( Sauv ) ;
             }
           else
             {
             Empiler_PAi (& *Pi , Sauv ) ;
             Suivant_preordre2  =  Montee_gauche_fd ( & *Pi , & *P ) ;
           
           }
         }
       }
     }
     return Suivant_preordre2 ;
    }
  void Postordre (Pointeur_Ai *R)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( ( *R != NULL )) {
       _Px1 =  Fg_Ai ( *R ) ;
       Postordre ( &_Px1) ;
       _Px2 =  Fd_Ai ( *R ) ;
       Postordre ( &_Px2) ;
       printf ( " %d", Info_Ai(*R) ) ;
     
     }
    }
  Pointeur_Ai Premier_postordre (Pointeur_Ai *R)
    {
      /** Variables locales **/
      Pointeur_Ai Premier_postordre2 =NULL;
      Pointeur_Ai P=NULL;
      bool Continu;

      /** Corps du module **/
     P  =  *R ;
     Continu  =  True ;
     while( ( Continu == True )) {
       while( ( Fg_Ai ( P ) != NULL )) {
         P  =  Fg_Ai ( P ) ;
       
       } ;
       if( ( Fd_Ai ( P ) != NULL )) {
         P  =  Fd_Ai ( P ) ;
         }
       else
         {
         Continu  =  False ;
       
       }
     } ;
     Premier_postordre2  =  P ;
   
     return Premier_postordre2 ;
    }
  Pointeur_Ai Suivant_postordre (Pointeur_PAi *Pi , Pointeur_Ai *P , Pointeur_Ai *Racine)
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_postordre2 =NULL;
      Pointeur_Ai N=NULL;
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     if( ! Pilevide_PAi ( *Pi )) {
       Depiler_PAi (& *Pi , &N ) ;
       if( ( N == *Racine ) && ( Fd_Ai ( N ) == *P )) {
         Suivant_postordre2  =  *Racine ;
         }
       else
         {
         Empiler_PAi (& *Pi , N ) ;
         if( ( ( Fd_Ai ( N ) == *P ) ) || ( ( Fg_Ai ( N ) == *P ) && ( Fd_Ai ( N ) == NULL ) )) {
           Suivant_postordre2  =  N ;
           }
         else
           {
           _Px1 =  Fd_Ai ( N ) ;
           Suivant_postordre2  =  Feuilleplusgauche ( &_Px1) ;
         
         }
       } }
     else
       {
       Suivant_postordre2  =  NULL ;
     
     }
     return Suivant_postordre2 ;
    }
  void Inordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      Pointeur_PAi Pi=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Corps du module **/
     *A3  =  NULL ;
     P  =  Premierinordre ( & *A1 ) ;
     Q  =  Premier_postordre ( & *A2 ) ;
     while( ( P != NULL ) && ( Q != NULL )) {
       _Px1 =  Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) ;
       Ins ( & *A3 , &_Px1) ;
       if( ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P ) ) && ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( Q ) )) {
         _Px2 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px2, & Pi ) ;
         P  =  Suivant_inordre ( & Pi , & P ) ;
         }
       else
         {
         if( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P )) {
           _Px3 =  Info_Ai ( P ) ;
           Chemin_pere_racine ( & *A1 , &_Px3, & Pi ) ;
           P  =  Suivant_inordre ( & Pi , & P ) ;
           }
         else
           {
           _Px4 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px4, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
     if( ( P != NULL )) {
       while( ( P != NULL )) {
         _Px5 =  Info_Ai ( P ) ;
         Ins ( & *A3 , &_Px5) ;
         _Px6 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px6, & Pi ) ;
         P  =  Suivant_inordre ( & Pi , & P ) ;
       
       } }
     else
       {
       if( ( Q != NULL )) {
         while( ( Q != NULL )) {
           _Px7 =  Info_Ai ( Q ) ;
           Ins ( & *A3 , &_Px7) ;
           _Px8 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px8, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
   
    }
  void Preordre_preordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai Q=NULL;
      Pointeur_Ai P=NULL;
      Pointeur_PAi Pi=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Corps du module **/
     *A3  =  NULL ;
     P  =  Premier_preordre ( & *A1 ) ;
     Q  =  Premier_preordre ( & *A2 ) ;
     while( ( P != NULL ) && ( Q != NULL )) {
       _Px1 =  Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) ;
       Ins ( & *A3 , &_Px1) ;
       if( ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P ) ) && ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( Q ) )) {
         _Px2 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px2, & Pi ) ;
         P  =  Suivant_preordre ( & Pi , & P ) ;
         }
       else
         {
         if( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P )) {
           _Px3 =  Info_Ai ( P ) ;
           Chemin_pere_racine ( & *A1 , &_Px3, & Pi ) ;
           P  =  Suivant_preordre ( & Pi , & P ) ;
           }
         else
           {
           _Px4 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px4, & Pi ) ;
           Q  =  Suivant_preordre ( & Pi , & Q ) ;
         
         }
       }
     } ;
     if( ( P != NULL )) {
       while( ( P != NULL )) {
         _Px5 =  Info_Ai ( P ) ;
         Ins ( & *A3 , &_Px5) ;
         _Px6 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px6, & Pi ) ;
         P  =  Suivant_preordre ( & Pi , & P ) ;
       
       } }
     else
       {
       if( ( Q != NULL )) {
         while( ( Q != NULL )) {
           _Px7 =  Info_Ai ( Q ) ;
           Ins ( & *A3 , &_Px7) ;
           _Px8 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px8, & Pi ) ;
           Q  =  Suivant_preordre ( & Pi , & Q ) ;
         
         }
       }
     } ;
   
    }
  void Postordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      Pointeur_PAi Pi=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Corps du module **/
     *A3  =  NULL ;
     P  =  Premier_postordre ( & *A1 ) ;
     Q  =  Premier_postordre ( & *A2 ) ;
     while( ( P != NULL ) && ( Q != NULL )) {
       _Px1 =  Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) ;
       Ins ( & *A3 , &_Px1) ;
       if( ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P ) ) && ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( Q ) )) {
         _Px2 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px2, & Pi ) ;
         P  =  Suivant_postordre ( & Pi , & P , & *A1 ) ;
         }
       else
         {
         if( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P )) {
           _Px3 =  Info_Ai ( P ) ;
           Chemin_pere_racine ( & *A1 , &_Px3, & Pi ) ;
           P  =  Suivant_postordre ( & Pi , & P , & *A1 ) ;
           }
         else
           {
           _Px4 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px4, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
     if( ( P != NULL )) {
       while( ( P != NULL )) {
         _Px5 =  Info_Ai ( P ) ;
         Ins ( & *A3 , &_Px5) ;
         _Px6 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px6, & Pi ) ;
         P  =  Suivant_postordre ( & Pi , & P , & *A1 ) ;
       
       } }
     else
       {
       if( ( Q != NULL )) {
         while( ( Q != NULL )) {
           _Px7 =  Info_Ai ( Q ) ;
           Ins ( & *A3 , &_Px7) ;
           _Px8 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px8, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
   
    }
  void Preordre_postordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      Pointeur_PAi Pi=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Corps du module **/
     *A3  =  NULL ;
     P  =  Premier_preordre ( & *A1 ) ;
     Q  =  Premier_postordre ( & *A2 ) ;
     while( ( P != NULL ) && ( Q != NULL )) {
       _Px1 =  Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) ;
       Ins ( & *A3 , &_Px1) ;
       if( ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P ) ) && ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( Q ) )) {
         _Px2 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px2, & Pi ) ;
         P  =  Suivant_preordre ( & Pi , & P ) ;
         }
       else
         {
         if( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P )) {
           _Px3 =  Info_Ai ( P ) ;
           Chemin_pere_racine ( & *A1 , &_Px3, & Pi ) ;
           P  =  Suivant_preordre ( & Pi , & P ) ;
           }
         else
           {
           _Px4 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px4, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
     if( ( P != NULL )) {
       while( ( P != NULL )) {
         _Px5 =  Info_Ai ( P ) ;
         Ins ( & *A3 , &_Px5) ;
         _Px6 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px6, & Pi ) ;
         P  =  Suivant_preordre ( & Pi , & P ) ;
       
       } }
     else
       {
       if( ( Q != NULL )) {
         while( ( Q != NULL )) {
           _Px7 =  Info_Ai ( Q ) ;
           Ins ( & *A3 , &_Px7) ;
           _Px8 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px8, & Pi ) ;
           Q  =  Suivant_postordre ( & Pi , & Q , & *A2 ) ;
         
         }
       }
     } ;
   
    }
  void Inordre_preordre (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai Q=NULL;
      Pointeur_Ai P=NULL;
      Pointeur_PAi Pi=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Corps du module **/
     *A3  =  NULL ;
     P  =  Premierinordre ( & *A1 ) ;
     Q  =  Premier_preordre ( & *A2 ) ;
     while( ( P != NULL ) && ( Q != NULL )) {
       _Px1 =  Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) ;
       Ins ( & *A3 , &_Px1) ;
       if( ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P ) ) && ( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( Q ) )) {
         _Px2 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px2, & Pi ) ;
         P  =  Suivant_inordre ( & Pi , & P ) ;
         }
       else
         {
         if( Min ( Info_Ai ( P ) , Info_Ai ( Q ) ) == Info_Ai ( P )) {
           _Px3 =  Info_Ai ( P ) ;
           Chemin_pere_racine ( & *A1 , &_Px3, & Pi ) ;
           P  =  Suivant_inordre ( & Pi , & P ) ;
           }
         else
           {
           _Px4 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px4, & Pi ) ;
           Q  =  Suivant_preordre ( & Pi , & Q ) ;
         
         }
       }
     } ;
     if( ( P != NULL )) {
       while( ( P != NULL )) {
         _Px5 =  Info_Ai ( P ) ;
         Ins ( & *A3 , &_Px5) ;
         _Px6 =  Info_Ai ( P ) ;
         Chemin_pere_racine ( & *A1 , &_Px6, & Pi ) ;
         P  =  Suivant_inordre ( & Pi , & P ) ;
       
       } }
     else
       {
       if( ( Q != NULL )) {
         while( ( Q != NULL )) {
           _Px7 =  Info_Ai ( Q ) ;
           Ins ( & *A3 , &_Px7) ;
           _Px8 =  Info_Ai ( Q ) ;
           Chemin_pere_racine ( & *A2 , &_Px8, & Pi ) ;
           Q  =  Suivant_preordre ( & Pi , & Q ) ;
         
         }
       }
     } ;
   
    }
  bool  Inclusion (Pointeur_Ai *A1 , Pointeur_Ai *A2)
    {
      /** Variables locales **/
      bool  Inclusion2 ;
      bool Gauchetrouve;
      bool Droitetrouve;
      bool Noeud;
      int _Px1;
      Pointeur_Ai _Px2=NULL;
      Pointeur_Ai _Px3=NULL;

      /** Corps du module **/
     if( *A1 == NULL)   {
       Inclusion2  =  True ;
       }
     else
       {
       if( *A2 == NULL)   {
         Inclusion2  =  False ;
         }
       else
         {
         _Px1 =  Info_Ai ( *A1 ) ;
         Noeud  =  Recherche ( & *A2 , &_Px1) ;
         if( Noeud)   {
           _Px2 =  Fg_Ai ( *A1 ) ;
           Gauchetrouve  =  Inclusion ( &_Px2, & *A2 ) ;
           _Px3 =  Fd_Ai ( *A1 ) ;
           Droitetrouve  =  Inclusion ( &_Px3, & *A2 ) ;
           Inclusion2  =  Gauchetrouve && Droitetrouve ;
           }
         else
           {
           Inclusion2  =  False ;
         
         }
       }
     }
     return Inclusion2 ;
    }
  bool  Valide (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      bool  Valide2 ;

      /** Corps du module **/
     Valide2  =  Estabr ( & *A3 ) && Inclusion ( & *A1 , & *A3 ) && Inclusion ( & *A2 , & *A3 ) ;
   
     return Valide2 ;
    }
   


//-----------------LES MODULES DE SIMULATION   
   
   
int hauteur_maximale(Pointeur_Ai A)
{
if (A == NULL)
        return -1;
    else {
        return max(hauteur_maximale(Fg_Ai(A)), hauteur_maximale(Fd_Ai(A))) + 1;
    }
}

int hauteur_minimale(Pointeur_Ai p)
{
if (p==NULL)
{
return -1;
}
else return Min(hauteur_minimale(p->Fg)+1,hauteur_minimale(p->Fd)+1);
}

int hauteur(Pointeur_Ai A) {
    if (A == NULL)
        return -1;
    else {
        return max(hauteur(Fg_Ai(A)), hauteur(Fd_Ai(A))) + 1;
    }
}



void nbnod(Pointeur_Ai A, int level, int* count) {
    if (A == NULL)
        return;
    if (level == 0)
        (*count)++;
    else if (level > 0) {
        nbnod(Fg_Ai(A), level - 1, count);
        nbnod(Fd_Ai(A), level - 1, count);
    }
}




void noeudparniveau(Pointeur_Ai A,FILE* fichier ) {
    int height=hauteur(A);
    int i;
    for (i = 0; i <= height; i++) {
        int count = 0;
        nbnod(A, i, &count);
        fprintf(fichier," %d,", count);
    }
      fprintf(fichier,"\n");      
}
 
 
    int max (int a, int b)
    {
      if (a > b) return(a);
      else return(b);
    }
 

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     A1  =  NULL ;
     A2  =  NULL ;
     A3  =  NULL ;
     
     
     clock_t start = clock();
       
       
    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;
    FILE* fichier4 = NULL;
    FILE* fichier5 = NULL;
    FILE* fichier6 = NULL;
    FILE* fichier7 = NULL;

   
   
    //les fichiers suivants vont contenir les resultats de la simulation
    fichier1 = fopen("test1.txt", "w");//ce fichier va contenir les hauteurs maximales des arbres A3
    fichier2 = fopen("test2.txt", "w");//ce fichier va contenir les hauteures minimales des arbres A3
    fichier3 = fopen("test3.txt", "w");// ce fichier va contenir le nombre de noeuds par niveau des arbres A3 pour la 1ere fusion
   
    fichier4 = fopen("test4.txt", "w");// ce fichier va contenir le nombre de noeuds par niveau des arbres A3 pour la 2eme fusion
    fichier5 = fopen("test5.txt", "w");// ce fichier va contenir le nombre de noeuds par niveau des arbres A3 pour la 3eme fusion
    fichier6 = fopen("test6.txt", "w");// ce fichier va contenir le nombre de noeuds par niveau des arbres A3 pour la 4eme fusion
    fichier7 = fopen("test7.txt", "w");// ce fichier va contenir le nombre de noeuds par niveau des arbres A3 pour la 5eme fusion

     
     
     
    
     for( I  =  1 ;I <= 50; ++I){
      _Px1 =  10000;
       Generer_bst ( & A1 , &_Px1 ) ;
        _Px2 =  10000 ;
       Generer_bst ( & A2 ,&_Px2 ) ;
       //premiere fusion ---------------------------------------------
        Preordre_postordre ( & A1 , & A2 , & A3 ) ;
        fprintf(fichier1, "%d,",hauteur_maximale(A3) );
        fprintf(fichier2, "%d,",hauteur_minimale(A3) );
        noeudparniveau(A3, fichier3);
       
       if( Valide ( & A1 , & A2 , & A3 )==False)   
	   {
         printf ( " %s", "A3 NON VALIDE " ) ;
         printf ( "\n\n") ;
       
       } ;
       //2eme fusion-----------------------------------------------
       A3  =  NULL ;
       Inordre_postordre ( & A1 , & A2 , & A3 ) ;
        fprintf(fichier1, "%d,",hauteur_maximale(A3) );
        fprintf(fichier2, "%d,",hauteur_minimale(A3) );
        noeudparniveau(A3, fichier4);
       
       
     if( Valide ( & A1 , & A2 , & A3 )==False)   
	   {
         printf ( " %s", "A3 NON VALIDE " ) ;
         printf ( "\n\n") ;
       
       } ;
       //3eme fusion-----------------------------------------------
       A3  =  NULL ;
       Preordre_preordre ( & A1 , & A2 , & A3 ) ;
        fprintf(fichier1, "%d,",hauteur_maximale(A3) );
        fprintf(fichier2, "%d,",hauteur_minimale(A3) );
        noeudparniveau(A3,fichier5 );
       
       if( Valide ( & A1 , & A2 , & A3 )==False)   
	   {
         printf ( " %s", "A3 NON VALIDE " ) ;
         printf ( "\n\n") ;
       
       } ;
       
        //4eme fusion------------------------------------------------
       A3  =  NULL ;
       Postordre_postordre ( & A1 , & A2 , & A3 ) ;
        fprintf(fichier1, "%d,",hauteur_maximale(A3) );
        fprintf(fichier2, "%d,",hauteur_minimale(A3) );
        noeudparniveau(A3,fichier6);
       
       
if( Valide ( & A1 , & A2 , & A3 )==False)   
	   {
         printf ( " %s", "A3 NON VALIDE " ) ;
         printf ( "\n\n") ;
       
       } ;
       //5eme fusion-----------------------------------------------
       A3  =  NULL ;
       Inordre_preordre ( & A1 , & A2 , & A3 ) ;
       fprintf(fichier1, "%d",hauteur_maximale(A3) );
       fprintf(fichier2, "%d",hauteur_minimale(A3) );
       noeudparniveau(A3, fichier7);
       
  if( Valide ( & A1 , & A2 , & A3 )==False)   
	   {
         printf ( " %s", "A3 NON VALIDE " ) ;
         printf ( "\n\n") ;
       
       } ;
       
       fprintf(fichier1,"\n");
       fprintf(fichier2,"\n");
     } ;
    fclose(fichier1);
fclose(fichier2);
fclose(fichier3);
     fclose(fichier4);
     fclose(fichier5);
     fclose(fichier6);
     fclose(fichier7);
     
     
         
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
printf("Temps d'exécution : %f secondes\n", duration);
printf(" \n fin du programme \n");
system("PAUSE");
return 0;
    } 
