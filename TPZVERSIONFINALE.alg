S
   SOIENT
       A1 , A2 , A3 , R , B , C DES ARB ;
       P , Q DES ARB ;
       P1 UN ARB ;
       Pi UNE PILE DE ARB ;
       Premier1 , Premier2 DES ARB ;
       Chemin_pere_racine : ACTION ;
       Afficher_pile : ACTION ;
       Recherche : FONCTION ( BOOLEEN ) ;
       Feuilleplusgauche : FONCTION ( ARB ) ;
       Minimum : FONCTION ( ENTIER ) ;
       Ins : ACTION ;
       Depilement : ACTION ;
       Generer_bst : ACTION ;
       Inordre : ACTION ;
       Premierinordre : FONCTION ( ARB ) ;
       Suivant_inordre : FONCTION ( ARB ) ;
       Montee_gauche_fd : FONCTION ( ARB ) ;
       Preordre : ACTION ;
       Premier_preordre : FONCTION ( ARB ) ;
       Suivant_preordre : FONCTION ( ARB ) ;
       Postordre : ACTION ;
       Premier_postordre : FONCTION ( ARB ) ;
       Suivant_postordre : FONCTION ( ARB ) ;
       Preordre_postordre : ACTION ;
       Inordre_postordre : ACTION ;
       Preordre_preordre : ACTION ;
       Postordre_postordre : ACTION ;
       Inordre_preordre : ACTION ;
       Maxtree : FONCTION ( ENTIER ) ;
       Mintree : FONCTION ( ENTIER ) ;
       Ma , Mi DES ENTIER ;
       Estabr : FONCTION ( BOOLEEN ) ;
       M , N , I DES ENTIER ;
       Inclusion : FONCTION ( BOOLEEN ) ;
       Valide : FONCTION ( BOOLEEN ) ;
       Nbnoeud : FONCTION ( ENTIER ) ;
      
   DEBUT
       A1 := NIL ;
       A2 := NIL ;
       A3 := NIL ;
       POUR I := 1 , 10 , 1

           APPEL Generer_bst ( A1 , 50 ) ;
           APPEL Generer_bst ( A2 , 50 ) ;
           APPEL Preordre_postordre ( A1 , A2 , A3 ) ;
           SI ( Valide ( A1 , A2 , A3 ) = FAUX ) :
               ECRIRE ( ' A3 N EST PAS VALIDE' ) ;
              
           FSI ;
           A3 := NIL ;
           APPEL Inordre_postordre ( A1 , A2 , A3 ) ;
           SI ( Valide ( A1 , A2 , A3 ) = FAUX ) :
               ECRIRE ( ' A3 N EST PAS VALIDE' ) ;
              
           FSI ;
           A3 := NIL ;
           APPEL Preordre_preordre ( A1 , A2 , A3 ) ;
           SI ( Valide ( A1 , A2 , A3 ) = FAUX ) :
               ECRIRE ( ' A3 N EST PAS VALIDE' ) ;
              
           FSI ;
           A3 := NIL ;
           APPEL Postordre_postordre ( A1 , A2 , A3 ) ;
           SI ( Valide ( A1 , A2 , A3 ) = FAUX ) :
               ECRIRE ( ' A3 N EST PAS VALIDE' ) ;
              
           FSI ;
           A3 := NIL ;
           APPEL Inordre_preordre ( A1 , A2 , A3 ) ;
           SI ( Valide ( A1 , A2 , A3 ) = FAUX ) :
               ECRIRE ( ' A3 N EST PAS VALIDE' ) ;
              
           FSI ;
          
       FPOUR ;
      
   FIN
   FONCTION Maxtree ( A ) : ENTIER
   SOIT
       A UN ARB ;
       SOIT Iter UN ARB ;
       SOIT Maa UN ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       Iter := Premierinordre ( A ) ;
       TQ Iter <> NIL :
           Maa := Iter ;
           Iter := Suivant_inordre ( Pi , Iter ) ;
          
       FTQ ;
       Maxtree := INFO ( Maa ) ;
      
   FIN
   FONCTION Mintree ( A ) : ENTIER
   SOIT
       A UN ARB ;
      
   DEBUT
       Mintree := INFO ( Premierinordre ( A ) ) ;
      
   FIN
   FONCTION Estabr ( A ) : BOOLEEN
   SOIT
       A UN ARB ;
      
   DEBUT
       Estabr := VRAI ;
       SI A = NIL :
           Estabr := VRAI ;
          
       SINON
           SI FG ( A ) <> NIL :
               SI INFO ( A ) < Maxtree ( FG ( A ) ) :
                   Estabr := FAUX ;
                  
               FSI
           SINON
               SI FD ( A ) <> NIL :
                   SI INFO ( A ) > Mintree ( FD ( A ) ) :
                       Estabr := VRAI ;
                      
                   FSI
               SINON
                   Estabr := Estabr ( FG ( A ) ) ET Estabr ( FD ( A ) ) ;
                  
               FSI
           FSI
       FSI
   FIN
   FONCTION Minimum ( A , B ) : ENTIER ;
   SOIENT
       A , B DES ENTIERS ;
      
   DEBUT
       SI ( A <= B )
           Minimum := A ;
          
       SINON
           Minimum := B ;
          
       FINSI
   FIN
   FONCTION Feuilleplusgauche ( R ) : ARB
   SOIENT
       R UN ARB ;
       P UN ARB ;
       Continu UN BOOLEEN ;
      
   DEBUT
       P := R ;
       Continu := VRAI ;
       TANTQUE ( Continu = VRAI )
           TANTQUE ( FG ( P ) <> NIL )
               P := FG ( P ) ;
              
           FTQ ;
           SI ( FD ( P ) <> NIL )
               P := FD ( P ) ;
              
           SINON
               Continu := FAUX ;
              
           FSI
       FTQ ;
       Feuilleplusgauche := P ;
      
   FIN
   ACTION Afficher_pile ( Pi )
   SOIENT
       Pi UNE PILE DE ARB ;
       Noeud UN ARB ;
      
   DEBUT
       TANTQUE ( NON PILEVIDE ( Pi ) )
           DEPILER ( Pi , Noeud ) ;
           ECRIRE ( INFO ( Noeud ) ) ;
          
       FTQ
   FIN
   ACTION Chemin_pere_racine ( Racine , Val , Pi )
   SOIENT
       Racine UN ARB ;
       Val UN ENTIER ;
       Pi UNE PILE DE ARB ;
       R UN ARB ;
       Nettoyage UN ARB ;
      
   DEBUT
       SI NON PILEVIDE ( Pi )
           TANTQUE NON PILEVIDE ( Pi )
               DEPILER ( Pi , Nettoyage ) ;
              
           FTQ ;
          
       FINSI ;
       R := Racine ;
       SI ( R <> NIL )
           TANTQUE ( INFO ( R ) <> Val ) ET ( R <> NIL )
               SI ( Val > INFO ( R ) )
                   EMPILER ( Pi , R ) ;
                   R := FD ( R ) ;
                  
               SINON
                   EMPILER ( Pi , R ) ;
                   R := FG ( R ) ;
                  
               FINSI ;
              
           FINTANTQUE ;
          
       FINSI
   FIN
   FONCTION Recherche ( A , Val ) : BOOLEEN
   SOIENT
       A UN ARB ;
       R UN ARB ;
       Val UN ENTIER ;
       Stop UN BOOLEEN ;
      
   DEBUT
       R := A ;
       Stop := FAUX ;
       TQ ( R <> NIL ) ET ( NON Stop )
           SI INFO ( R ) = Val :
               Stop := VRAI ;
              
           FSI ;
           SI Val < INFO ( R ) :
               R := FG ( R ) ;
              
           SINON
               SI Val > INFO ( R ) :
                   R := FD ( R ) ;
                  
               FSI
           FSI
       FTQ ;
       SI Stop = VRAI :
           Recherche := VRAI ;
          
       SINON
           Recherche := FAUX ;
          
       FSI
   FIN
   ACTION Ins ( A , Val )
   SOIENT
       A UN ARB ;
       Val UN ENTIER ;
       R UN ARB ;
       Per UN ARB ;
      
   DEBUT
       SI A = NIL :
           CREERNOEUD ( A ) ;
           AFF_INFO ( A , Val ) ;
          
       SINON
           R := A ;
           Per := R ;
           TQ R <> NIL :
               SI Val <= INFO ( R ) :
                   Per := R ;
                   R := FG ( R ) ;
                  
               SINON
                   Per := R ;
                   R := FD ( R ) ;
                  
               FSI
           FTQ ;
           SI Val <= INFO ( Per ) :
               CREERNOEUD ( R ) ;
               AFF_INFO ( R , Val ) ;
               AFF_FG ( Per , R ) ;
              
           SINON
               CREERNOEUD ( R ) ;
               AFF_INFO ( R , Val ) ;
               AFF_FD ( Per , R ) ;
              
           FSI
       FSI
   FIN
   ACTION Generer_bst ( A , N )
   SOIENT
       A UN ARB ;
       N UN ENTIER ;
       K UN ENTIER ;
       I UN ENTIER ;
      
   DEBUT
       CREERNOEUD ( A ) ;
       K := ALEANOMBRE ( 1000 ) ;
       AFF_INFO ( A , K ) ;
       POUR I := 1 , N - 1 :
           K := ALEANOMBRE ( 1000 ) ;
           TQ ( Recherche ( A , K ) = VRAI ) :
               K := ALEANOMBRE ( 1000 ) ;
              
           FTQ ;
           APPEL Ins ( A , K ) ;
          
       FPOUR
   FIN
   ACTION Inordre ( Racine )
   SOIENT
       Racine UN ARB ;
      
   DEBUT
       SI ( Racine <> NIL )
           APPEL Inordre ( FG ( Racine ) ) ;
           ECRIRE ( INFO ( Racine ) ) ;
           APPEL Inordre ( FD ( Racine ) ) ;
          
       FINSI
   FIN
   FONCTION Premierinordre ( R ) : ARB ;
   SOIENT
       R UN ARB ;
       N UN ARB ;
      
   DEBUT
       N := R ;
       TQ ( FG ( N ) <> NIL )
           N := FG ( N ) ;
          
       FTQ ;
       Premierinordre := N ;
      
   FIN
   ACTION Depilement ( Pi , N , Possible )
   SOIENT
       Pi UNE PILE DE ARB ;
       N UN ARB ;
       Possible UN BOOLEEN ;
      
   DEBUT
       SI NON PILEVIDE ( Pi )
           DEPILER ( Pi , N ) ;
           Possible := VRAI ;
          
       SINON
           Possible := FAUX ;
          
       FINSI
   FIN
   FONCTION Suivant_inordre ( Pi , P ) : ARB ;
   SOIENT
       Pi UNE PILE DE ARB ;
       P UN ARB ;
       Stop UN BOOLEEN ;
       N UN ARB ;
       Possible UN BOOLEEN ;
      
   DEBUT
       SI P = NIL
           Suivant_inordre := NIL ;
          
       SINON
           SI FD ( P ) <> NIL
               P := FD ( P ) ;
               TQ FG ( P ) <> NIL
                   P := FG ( P ) ;
                  
               FTQ ;
               Suivant_inordre := P
           SINON
               APPEL Depilement ( Pi , N , Possible ) ;
               Stop := FAUX ;
               TQ ( Stop = FAUX ) ET ( Possible = VRAI )
                   SI ( P = FG ( N ) )
                       Stop := VRAI
                   SINON
                       P := N ;
                       APPEL Depilement ( Pi , N , Possible ) ;
                      
                   FSI ;
                  
               FTQ ;
               SI Stop = VRAI
                   Suivant_inordre := N
               SINON
                   Suivant_inordre := NIL
               FSI ;
              
           FSI ;
          
       FSI ;
      
   FIN
   ACTION Preordre ( Racine )
   SOIENT
       Racine UN ARB ;
      
   DEBUT
       SI ( Racine <> NIL )
           ECRIRE ( INFO ( Racine ) ) ;
           APPEL Preordre ( FG ( Racine ) ) ;
           APPEL Preordre ( FD ( Racine ) ) ;
          
       FINSI
   FIN
   FONCTION Montee_gauche_fd ( Pi , P1 ) : ARB ;
   SOIENT
       Pi UNE PILE DE ARB ;
       P1 UN ARB ;
       Stop , Possible , Mg DES BOOLEENS ;
       Per , N DES ARB ;
      
   DEBUT
       Stop := FAUX ;
       APPEL Depilement ( Pi , N , Possible ) ;
       SI ( PILEVIDE ( Pi ) = VRAI )
           SI ( N <> NIL ) ET ( FD ( N ) <> P1 )
               Montee_gauche_fd := FD ( N ) ;
              
           SINON
               Montee_gauche_fd := NIL ;
              
           FSI
       SINON
           TANTQUE ( Stop = FAUX ) ET ( NON PILEVIDE ( Pi ) )
               APPEL Depilement ( Pi , Per , Possible ) ;
               SI ( FG ( Per ) = N )
                   Mg := VRAI ;
                  
               SINON
                   Mg := FAUX ;
                  
               FSI ;
               SI ( FD ( Per ) <> NIL ) ET ( Mg = VRAI )
                   Montee_gauche_fd := FD ( Per ) ;
                   Stop := VRAI ;
                  
               FINSI ;
               EMPILER ( Pi , Per ) ;
               APPEL Depilement ( Pi , N , Possible ) ;
              
           FTQ ;
           SI ( Stop = FAUX )
               Montee_gauche_fd := NIL ;
              
           FSI
       FSI
   FIN
   FONCTION Premier_preordre ( Racine ) : ARB ;
   SOIENT
       Racine UN ARB ;
      
   DEBUT
       Premier_preordre := Racine ;
      
   FIN
   FONCTION Suivant_preordre ( Pi , P ) : ARB ;
   SOIENT
       Pi UNE PILE DE ARB ;
       P UN ARB ;
       N UN ARB ;
       Sauv UN ARB ;
       Stop UN BOOLEEN ;
      
   DEBUT
       Stop := FAUX ;
       SI FG ( P ) <> NIL
           Suivant_preordre := FG ( P ) ;
          
       SINON
           SI FD ( P ) <> NIL
               Suivant_preordre := FD ( P ) ;
              
           SINON
               SI NON PILEVIDE ( Pi )
                   DEPILER ( Pi , Sauv ) ;
                   SI ( FD ( Sauv ) <> NIL ) ET ( FG ( Sauv ) = P )
                       Suivant_preordre := FD ( Sauv ) ;
                      
                   SINON
                       EMPILER ( Pi , Sauv ) ;
                       Suivant_preordre := Montee_gauche_fd ( Pi , P ) ;
                      
                   FINSI
               FINSI
           FINSI
       FINSI
   FIN
   ACTION Postordre ( R )
   SOIENT
       R UN ARB ;
      
   DEBUT
       SI ( R <> NIL )
           APPEL Postordre ( FG ( R ) ) ;
           APPEL Postordre ( FD ( R ) ) ;
           ECRIRE ( INFO ( R ) ) ;
          
       FINSI
   FIN
   FONCTION Premier_postordre ( R ) : ARB
   SOIENT
       R UN ARB ;
       P UN ARB ;
       Continu UN BOOLEEN ;
      
   DEBUT
       P := R ;
       Continu := VRAI ;
       TANTQUE ( Continu = VRAI )
           TANTQUE ( FG ( P ) <> NIL )
               P := FG ( P ) ;
              
           FTQ ;
           SI ( FD ( P ) <> NIL )
               P := FD ( P ) ;
              
           SINON
               Continu := FAUX ;
              
           FSI
       FTQ ;
       Premier_postordre := P ;
      
   FIN
   FONCTION Suivant_postordre ( Pi , P , Racine ) : ARB ;
   SOIENT
       Pi UNE PILE DE ARB ;
       P UN ARB ;
       N UN ARB ;
       Racine UN ARB ;
      
   DEBUT
       SI NON PILEVIDE ( Pi )
           DEPILER ( Pi , N ) ;
           SI ( N = Racine ) ET ( FD ( N ) = P )
               Suivant_postordre := Racine ;
              
           SINON
               EMPILER ( Pi , N ) ;
               SI ( ( FD ( N ) = P ) ) OU ( ( FG ( N ) = P ) ET ( FD ( N ) = NIL ) )
                   Suivant_postordre := N ;
                  
               SINON
                   Suivant_postordre := Feuilleplusgauche ( FD ( N ) ) ;
                  
               FINSI
           FINSI
       SINON
           Suivant_postordre := NIL ;
          
       FINSI
   FIN
   ACTION Inordre_postordre ( A1 , A2 , A3 )
   SOIENT
       A1 , A2 , A3 DES ARB ;
       SOIENT P , Q DES ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       A3 := NIL ;
       P := Premierinordre ( A1 ) ;
       Q := Premier_postordre ( A2 ) ;
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           APPEL Ins ( A3 , MIN ( INFO ( P ) , INFO ( Q ) ) ) ;
           SI ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P ) ) ET ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( Q ) )
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_inordre ( Pi , P ) ;
              
           SINON
               SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
                   APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
                   P := Suivant_inordre ( Pi , P ) ;
                  
               SINON
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FSI
           FSI
       FTQ ;
       SI ( P <> NIL )
           TANTQUE ( P <> NIL )
               APPEL Ins ( A3 , INFO ( P ) ) ;
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_inordre ( Pi , P ) ;
              
           FTQ
       SINON
           SI ( Q <> NIL )
               TANTQUE ( Q <> NIL )
                   APPEL Ins ( A3 , INFO ( Q ) ) ;
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FTQ
           FSI
       FSI ;
      
   FIN
   ACTION Preordre_preordre ( A1 , A2 , A3 )
   SOIENT
       A1 , A2 , A3 DES ARB ;
       SOIENT Q , P DES ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       A3 := NIL ;
       P := Premier_preordre ( A1 ) ;
       Q := Premier_preordre ( A2 ) ;
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           APPEL Ins ( A3 , MIN ( INFO ( P ) , INFO ( Q ) ) ) ;
           SI ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P ) ) ET ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( Q ) )
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_preordre ( Pi , P ) ;
              
           SINON
               SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
                   APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
                   P := Suivant_preordre ( Pi , P ) ;
                  
               SINON
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_preordre ( Pi , Q ) ;
                  
               FSI
           FSI
       FTQ ;
       SI ( P <> NIL )
           TANTQUE ( P <> NIL )
               APPEL Ins ( A3 , INFO ( P ) ) ;
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_preordre ( Pi , P ) ;
              
           FTQ
       SINON
           SI ( Q <> NIL )
               TANTQUE ( Q <> NIL )
                   APPEL Ins ( A3 , INFO ( Q ) ) ;
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_preordre ( Pi , Q ) ;
                  
               FTQ
           FSI
       FSI ;
      
   FIN
   ACTION Postordre_postordre ( A1 , A2 , A3 )
   SOIENT
       A1 , A2 , A3 DES ARB ;
       SOIENT P , Q DES ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       A3 := NIL ;
       P := Premier_postordre ( A1 ) ;
       Q := Premier_postordre ( A2 ) ;
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           APPEL Ins ( A3 , MIN ( INFO ( P ) , INFO ( Q ) ) ) ;
           SI ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P ) ) ET ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( Q ) )
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_postordre ( Pi , P , A1 ) ;
              
           SINON
               SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
                   APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
                   P := Suivant_postordre ( Pi , P , A1 ) ;
                  
               SINON
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FSI
           FSI
       FTQ ;
       SI ( P <> NIL )
           TANTQUE ( P <> NIL )
               APPEL Ins ( A3 , INFO ( P ) ) ;
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_postordre ( Pi , P , A1 ) ;
              
           FTQ
       SINON
           SI ( Q <> NIL )
               TANTQUE ( Q <> NIL )
                   APPEL Ins ( A3 , INFO ( Q ) ) ;
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FTQ
           FSI
       FSI ;
      
   FIN
   ACTION Preordre_postordre ( A1 , A2 , A3 )
   SOIENT
       A1 , A2 , A3 DES ARB ;
       SOIENT P , Q DES ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       A3 := NIL ;
       P := Premier_preordre ( A1 ) ;
       Q := Premier_postordre ( A2 ) ;
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           APPEL Ins ( A3 , MIN ( INFO ( P ) , INFO ( Q ) ) ) ;
           SI ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P ) ) ET ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( Q ) )
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_preordre ( Pi , P ) ;
              
           SINON
               SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
                   APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
                   P := Suivant_preordre ( Pi , P ) ;
                  
               SINON
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FSI
           FSI
       FTQ ;
       SI ( P <> NIL )
           TANTQUE ( P <> NIL )
               APPEL Ins ( A3 , INFO ( P ) ) ;
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_preordre ( Pi , P ) ;
              
           FTQ
       SINON
           SI ( Q <> NIL )
               TANTQUE ( Q <> NIL )
                   APPEL Ins ( A3 , INFO ( Q ) ) ;
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_postordre ( Pi , Q , A2 ) ;
                  
               FTQ
           FSI
       FSI ;
      
   FIN
   ACTION Inordre_preordre ( A1 , A2 , A3 )
   SOIENT
       A1 , A2 , A3 DES ARB ;
       SOIENT Q , P DES ARB ;
       SOIT Pi UNE PILE DE ARB ;
      
   DEBUT
       A3 := NIL ;
       P := Premierinordre ( A1 ) ;
       Q := Premier_preordre ( A2 ) ;
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           APPEL Ins ( A3 , MIN ( INFO ( P ) , INFO ( Q ) ) ) ;
           SI ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P ) ) ET ( MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( Q ) )
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_inordre ( Pi , P ) ;
              
           SINON
               SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
                   APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
                   P := Suivant_inordre ( Pi , P ) ;
                  
               SINON
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_preordre ( Pi , Q ) ;
                  
               FSI
           FSI
       FTQ ;
       SI ( P <> NIL )
           TANTQUE ( P <> NIL )
               APPEL Ins ( A3 , INFO ( P ) ) ;
               APPEL Chemin_pere_racine ( A1 , INFO ( P ) , Pi ) ;
               P := Suivant_inordre ( Pi , P ) ;
              
           FTQ
       SINON
           SI ( Q <> NIL )
               TANTQUE ( Q <> NIL )
                   APPEL Ins ( A3 , INFO ( Q ) ) ;
                   APPEL Chemin_pere_racine ( A2 , INFO ( Q ) , Pi ) ;
                   Q := Suivant_preordre ( Pi , Q ) ;
                  
               FTQ
           FSI
       FSI ;
      
   FIN
   FONCTION Inclusion ( A1 , A2 ) : BOOLEEN
   SOIENT
       A1 , A2 DES ARB ;
       Gauchetrouve , Droitetrouve , Noeud DES BOOLEEN ;
      
   DEBUT
       SI A1 = NIL :
           Inclusion := VRAI ;
          
       SINON
           SI A2 = NIL :
               Inclusion := FAUX ;
              
           SINON
               Noeud := Recherche ( A2 , INFO ( A1 ) ) ;
               SI Noeud :
                   Gauchetrouve := Inclusion ( FG ( A1 ) , A2 ) ;
                   Droitetrouve := Inclusion ( FD ( A1 ) , A2 ) ;
                   Inclusion := Gauchetrouve ET Droitetrouve ;
                  
               SINON
                   Inclusion := FAUX ;
                  
               FSI
           FSI
       FSI
   FIN
   FONCTION Nbnoeud ( A ) : ENTIER
   SOIT
       A UN ARB ;
      
   DEBUT
       SI R = NIL :
           Nbnoeud := 0 ;
          
       SINON
           Nbnoeud := 1 + Nbnoeud ( FG ( A ) ) + Nbnoeud ( FD ( A ) ) ;
          
       FSI
   FIN
   FONCTION Valide ( A1 , A2 , A3 ) : BOOLEEN
   SOIENT
       A1 , A2 , A3 DES ARB ;
       R UN BOOLEEN ;
      
   DEBUT
       R := FAUX ;
       SI Nbnoeud ( A3 ) = Nbnoeud ( A1 ) + Nbnoeud ( A2 ) :
           R := VRAI ;
          
       FSI ;
       Valide := Estabr ( A3 ) ET Inclusion ( A1 , A3 ) ET Inclusion ( A2 , A3 ) ET R ;
      
   FIN
