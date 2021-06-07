#include<stdio.h>
    #include<stdlib.h>
    #include<String.h>
    int lookfor(int);
    void voircontrat();
    void creercontrat();
    int rech(int);
    void ajoutervoiture();
    void retournervoiture();
    void modifiercontrat();
    void modifiervoiture();
    void supprimercontrat();
    void MenuPrincipal();
    void location();
    void gestiondevoitures();
    int gestiondeclients();
    void modifier_alloc();
    void modifiervoiture_generale();
    void supVoi();
    void afficher();
    int RC(int);
    void supCli();
    void MCL();
    void AFC();
    int cost(int,int);
    void louervoiture();
    
    
    
    
     void main() // c'est la premiÃ¨re chose Ã  etre afficher, ce menu permet de choisir l'action prochaine Ã  executer.//
    {
        int choix;
    
    	printf("***BIENVENUE A VOTRE AGENCE DE LOCATION DE VOITURE***\n\n");
    	printf("Saisir le numero correspondant au service\n");
        printf("\n                   Location..............................1   \n");         
        printf("\n                   Gestion voitures......................2   \n");
        printf("\n                   Gestion clients.......................3   \n");
        printf("\n                   Quitter...............................4   \n");
      printf("\n\n                                Votre choix  :  ");
    
        scanf("%d",&choix);
    
    
    
        switch(choix)
        {
            case 1 : location();
            break;
            case 2 : gestiondevoitures();
            break;
            case 3 : gestiondeclients();
            break;
            case 4 : break;
        }
    }
        
        
        
        
        typedef struct Voiture
    {
    
     int idVoiture;
     char marque[15];
     char nomVoiture[15];
     char couleur[7];
     int nbplaces;
     int prixJour;
     char allocation[4];
    } voiture; 
    
    typedef struct Date{
        int jour;
        int mois;
        int annee;
    }date;
    
    typedef struct contratLocation
    {
     float numContrat;
     int idVoiture;
     int idClient;
     date debut;
     date fin;
     int cout;
    } contrat; 
    
    typedef struct Client
    {
     int idClient;
     char nom[20];
     char prenom[20];
     int cin;
     char adresse[15];
     int telephone;
    }client; 
    
    
    
    /*----------------recherche de countrat location*/
    
    
    contrat SAA;
    voiture NV;
    
    int lookfor(int num)
    {
        FILE *f;
        f=fopen("contrat.txt","r");
        if(f==NULL)
            printf("Contrat inexistant \n");
        else
        {
            do
            {
                fscanf(f, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout );
                if(SAA.numContrat==num)
                {
                    fclose(f);
                    return 1;
                }
            } while (!feof(f));
            fclose(f);
        }
        return -1;
    }
    
    
    void voircontrat() //on saisie le numero du contrat dont nous voulons les informations,  et on verifie son existence avec la fonction lookfor() s'il existe on affiche les informations,sinon on redemande la saisie du numero exact de contrat*/
    {
        FILE *f;
        int num;
        f=fopen("contrat.txt","r"); //*ouverture en mode "read"*/
        printf("saisir le numero du contrat que vous voulez Visualiser\n"); /*numero de contrat*/
        scanf("%d",&num);
        fscanf(f, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout );
        if (lookfor(num)==1)// si le numero de contrat saisi existe dans le fichier
        {
            printf("Les informations concernant votre contrat\n");  //on affiche les informations sur l'ecran
            printf("l'id de voiture : %d \n", SAA.idVoiture );
            printf("l'id ce client : %d \n", SAA.idClient );
            printf("la date de debut : %d / %d / %d \n",SAA.fin.jour,SAA.fin.mois,SAA.fin.annee);
            printf("la date de fin : %d /%d /%d \n",SAA.fin.jour,SAA.fin.mois,SAA.fin.annee );
            printf("le cout : %d\n",SAA.cout);
        }else  // sinon un message sera afficher que ce numero n'existe pas
        {
            printf("Ce numero de contrat n'existe pas \n");
        }
        fclose(f);
        location();// retour au menu precedent.
    }
    
    
    
    void modifiercontrat()
    {
        FILE *f,*fl;
        int id ;
        int rep;
        printf("Saisir l'id du contrat a modifier \n");
        scanf("%d",&id);
        fflush(stdin);
        if(lookfor(id)==1)
            {
                printf("Tapez 1 pour continuer la modification;\n Tapez 0 pour annuler\n");
                scanf("%d",&rep);
                fflush(stdin);
                if(rep==1)
                    {
                        f=fopen("contrat.txt","r");
                        fl=fopen("file.txt","a");
                        if(fl==NULL)
                            printf("fichier pas ouvertire \n");
                        else
                            {
                                do
                                {
                                    fscanf(f, "%d ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout);
                                    if(id==SAA.numContrat)
                                        {
                                            SAA.numContrat=id;
                                              printf("saisir le nouveau id de voiture \n");
                                              scanf("%d",&SAA.idVoiture);
                                              printf("saisir le nouveau id de client qui loue la voiture \n");
                                            scanf("%d",&SAA.idClient);
                                            printf("saisir la date du debut\n");
                                            printf("jour :\t");
                                            scanf("%d",&SAA.debut.jour);
                                            printf("mois :\t");
                                            scanf("%d",&SAA.debut.mois);
                                            printf("annee :\t");
                                            scanf("%d",&SAA.debut.annee);
                                            printf("\nsaisir la date de la fin\n");
                                            printf("jour :\t");
                                            scanf("%d",&SAA.fin.jour);
                                            printf("mois :\t");
                                            scanf("%d",&SAA.fin.mois);
                                            printf("annee :\t");
                                            scanf("%d",&SAA.fin.annee);
                                            printf("saisir le nouveau cout \n");
                                            scanf("%d",&SAA.cout);
                                        }
                                            fprintf(fl, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout);
    
                                }while(!feof(f));
                                fclose(f);
                                fclose(fl);
                                remove("contrat.txt");
                                rename("file.txt","contrat.txt");
                                printf("\n contrat modifie avec succes\n");
    
                            }
                    }
                else
                    printf("la modification est annulee");
    
            }
        else
            printf("\n Ce numero de contrat n'existe pas \n");
        location();
    }
    
    void supprimercontrat()
    {
        FILE *f , *fl;
        int rep; ;
        int id;
        printf("Saisir le numero du contrat a supprimer \n");
        scanf("%d",&id);
        fflush(stdin);
        if(lookfor(id)==1)
            {
                printf("Tapez 1 pour supprimer;\n Tapez 0 pour annuler\n\n");
                scanf("%d",&rep);
                fflush(stdin);
                if(rep==1)
                    {
                        f=fopen("contrat.txt","r");
                        fl=fopen("fich.txt","a");
                        if(fl==NULL)
                        printf("Impossible d'ouvrir le fichier'\n");
                        else
                        {
                            do
                            {
                                fscanf(f, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout );
                                if(id != SAA.numContrat)
                                    {
                                        fprintf(fl, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",SAA.numContrat,SAA.idVoiture,SAA.idClient,SAA.debut.jour,SAA.debut.mois,SAA.debut.annee,SAA.fin.jour,SAA.fin.mois,SAA.fin.annee,SAA.cout );
                                    }
                            }while(!feof(f));
                            fclose(f);
                            fclose(fl);
                            remove("contrat.txt");
                            rename("fich.txt","contrat.txt");
                            printf("\n Contrat supprime avec succes\n");
    
                        }
                    }
                else
                    printf("\n Suppression annulee \n");
            }
        else
            printf("Ce numero de contrat n'existe pas \n");
        location();
    }
    
    
    void creercontrat() // on demande de saisir les donnees relatives au nouveau contrat
    {
        FILE *f;
        f=fopen("contrat.txt","a");
        printf("Saisir le numero du contrat \t" );
        scanf("%d",&SAA.numContrat);
        printf("Saisir l'id de la voiture a louer \t");
        scanf("%d",&SAA.idVoiture);
        printf("Saisir l'id de client qui loue la voiture \t");
        scanf("%d",&SAA.idClient);
        printf("Saisir la date du debut\n");
        printf("jour :\t");
        scanf("%d",&SAA.debut.jour);
        printf("mois :\t");
        scanf("%d",&SAA.debut.mois);
        printf("annee :\t");
        scanf("%d",&SAA.debut.annee);
        printf("Saisir la date de la fin\n");
        printf("jour :\t");
        scanf("%d",&SAA.fin.jour);
        printf("mois :\t");
        scanf("%d",&SAA.fin.mois);
        printf("annee :\t");
        scanf("%d",&SAA.fin.annee);
        printf("saisir le cout \t");
        scanf("%d",&SAA.cout);
        fprintf(f,"%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",SAA.numContrat,SAA.idVoiture,SAA.idClient,SAA.debut.jour,SAA.debut.mois,SAA.debut.annee,SAA.fin.jour,SAA.fin.mois,SAA.fin.annee,SAA.cout );
    }
    
    
    
    
    void retournervoiture()// on saisie l'id de la voiture qu'on veut retourner et on verifie son existence, on saisit le numero du contrat creer
                            // Le client rend la voiture lou�e, on actualise la voiture comme "disponible" pour une nouvelle location
                            
    {
        FILE *f,*fl;
        int id,num;
        printf("Saisir l'id de la voiture retournee \n");
        scanf("%d",&id);
        f=fopen("voiture.txt","a");
        fl=fopen("contrat.txt","a");
        fscanf(f,"%d ,%s ,%s ,%s ,%d ,%d ,%s\n",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
        if(rech(id) != 1) // l'id de voiture saisi n'existe pas
        {
            printf("Veuillez resaisir l'id de la voiture retournee");//on redemande la saisie de l'id voiture
            scanf("%d",&id);
        }
        printf("Veuillez saisir le numero de votre contrat \n");
        scanf("%d",&num);
        fscanf(fl, "%f ,%d ,%d ,%d /%d /%d ,%d /%d /%d ,%d\n",&SAA.numContrat,&SAA.idVoiture,&SAA.idClient,&SAA.debut.jour,&SAA.debut.mois,&SAA.debut.annee,&SAA.fin.jour,&SAA.fin.mois,&SAA.fin.annee,&SAA.cout );
        if(lookfor(num) != 1) //le numero de contrat n'existe pas
        {
            printf("Veuillez saisir correctement le numero de votre contrat \n");//on remande la saisie du numero de contrat
            scanf("%d",&num);
    
        }
        supprimercontrat();// on fait appel a cette fonction qui supprime le contrat dont le meme numero saisi
        printf("Votre contrat est supprimee \n");
        printf("Changer la valeur de l'alllocation a 0\n");
        modifier_alloc();
        printf("Merci d'avoir choisir notre agence\n");
        location();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*-------------------------------------------------------*/
    
    /*	voiture NV;   */
        
        /*---------- fonction rechercher------- */
        //cette fonction permet l'access au ficher des voitures et de retourner 1 si un Identifient de voiture passÃ© en paramÃ¨tres existe et -1 sinon
                      //en faisant le fscanf() ligne par ligne. Et la meme chose pour les deux autres fonctions; RC () pour les clients et lookfor() pour les contrats
        int rech(int Numrech)
        {
        FILE *F;
        F= fopen("voiture.txt","r");
        
    do{
        fscanf(F,"%d,%s,%s,%s,%d,%d,%s \n",&NV.idVoiture ,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
        fflush(stdin);
        if(NV.idVoiture==Numrech)
        {
        fclose(F);
        return 1;
        }
    }while(!feof(F));
    fclose(F);
    return-1;
        }
        
        
        /*--------- fonction d ajouter les voitures-------- */
        void ajoutervoiture(){
                                    // on ouvre le fichier en mode "append", ce qui permet d'ajouter une autre voiture a la fin du fichier sans ecraser le contenu existant dans ce fichier.
        FILE *F;
        int num;
        F= fopen("voiture.txt","a");
        printf("\n Entrez le Numero du nouveau Voiture:");
        scanf("%d",&num);
        fflush(stdin);
        while(rech(num)==1) //verification de l'existence de l'id saisi.
        {
        printf("\n exist deja !!!");
          printf("Entre le nouveau Numero");
              scanf("%d",&num);
    
        }
        NV.idVoiture=num;
        printf("\n Entres la marque de voiture:   ");
        gets(NV.marque);
        fflush(stdin);
        printf("\n Entres le Nom de voiture:   ");
        gets(NV.nomVoiture);
        fflush(stdin);
        printf("\n Entres la couleure de voiture:   ");
        gets(NV.couleur);
        fflush(stdin);
        
    printf("\n Entres EntLocation de voiture:   ");
        gets(NV.allocation);
        fflush(stdin);
        
        
        printf("\n Entres le prixjour de voiture:   ");
        scanf( "%d",&NV.prixJour);
        fflush(stdin);
        
        printf("\n Entres nbplaces de voiture:    ");
        scanf( "%d",&NV.nbplaces);
        fflush(stdin);
        
        // on fait ensuite le fprintf() pour ecrire tous ces informations enregistrees sur la nouvelle voiture dans notres fichier voiture.txt.
        
        fprintf(F,"%d,%s,%s,%s,%d,%d,%s \n",NV.idVoiture ,NV.marque,NV.nomVoiture,NV.couleur,NV.nbplaces,NV.prixJour,NV.allocation);
        fclose(F);
        gestiondevoitures();
        }
        
        
            /* ---------fonction de modification les voitures---------- */
            
            //procedure de modification d'une voiture
     
            
            void modifiervoiture()
                                             // cette fonction fait le choix entre modification generale de la voiture
    {                      									//et modifier le champs "allocation" seulement pour faciliter la tache
        int choix;        											 //lors de la location et le retour des voitures.
    
      
        
    
       
        printf("\n                  Modification generale........................1   ");
        printf("\n                  Modifier allocation..........................2   ");
        printf("\n                  Quitter......................................4  ");
        printf("\n               \xba                                                     \xba");
      
        printf("\n\n          Votre choix  :  ");
    
        scanf("%d",&choix);
    
    
    
        switch(choix)
        {
            case 1 : modifiervoiture_generale();
            break;
            case 2 : modifier_alloc();
            break;
            case 3 : gestiondevoitures();
            break;
        }
    }
    void modifier_alloc() //on saisie l'id de la voiture a modifier puis on verifie son existence, si oui on demande d'assurer la modification et
    {                     //chaque fois qu'on lit une ligne dans le fichier contenant les voitures(ouvert en mode "read") on l'ecrit dans un fichier
                          //temporaire ouvert em mode "append",et si l'id d'une ligne est le meme que l'id saisie on demande la nouvelle valeur du champs
                          //allocation et puis on l'ecrit dans le nouveau fichier. et apres on ecrase le premier ficher et on renomme
                          //le fichier temporaire par le meme nom que le fichier supprime.
        FILE *f,*fl;
        int id ;
        int rep;
        printf("Saisir l'id de la voiture a modifier \t");
        scanf("%d",&id);
        fflush(stdin);
        if(rech(id)==1) // l'id  saisi existe dans le fichier
            {
                printf("Voulez vous vraiment modifier cette voiture? 0(Annuler);1(Modifier) \t"); //on confirme la modification
                scanf("%d",&rep);
                fflush(stdin);
                if(rep==1)// la reponse de la confirmation est oui
                    {
                        f=fopen("voiture.txt","r"); //on ouvre le fichier contenant les voitures en mode "read"
                        fl=fopen("deuxvoiture.txt","a"); //le fichier temporaire cree en mode "append" pour effectuer les modification.
                                do
                                {
                                    // on fait la lecture ligne par ligne tout au long du fichier
                               /*     fscanf(f,"%d ,%s ,%s ,%s ,%d ,%d ,%d\n",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation); */
                                    if(id==NV.idVoiture) // si on est arriveÃ© a la ligne dont l'id de voiture est le meme que l'id saisi
                                    {
                                        NV.idVoiture=id;
                                        printf("la nouvelle allocation :\t"); // on demande la nouvelle valeur du champ
                                        scanf("%d",&NV.allocation);
                                    }
                                    //on copie les lignes du premier fichier dans le deuxieme ainsi que les modifications effectuÃ©es.
                                    /*fprintf(fl,"%d ,%s ,%s ,%s ,%d ,%d ,%d\n",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation); */
    
                                }while(!feof(f));
                                fclose(f); // on ferme les deux fichiers
                                fclose(fl);
                                remove("voiture.txt"); // suppression du premier
                                rename("deuxvoiture.txt","voiture.txt"); //renommage du deuxieme
                                printf("\n Voiture modifiee avec succes\n"); // et voila .
                    }
                else
                    printf("la modification est annulee"); // la reponse de la confirmation est non
    
            }
        else
            printf("\n cet id de voiture n'existe pas \n"); // l'id saisi n'existe pas dans le fichier
    
    }
    
    void modifiervoiture_generale()  //on saisie l'id de la voiture a modifier et on verifie son existence, si oui on demande d'assurer la modification et
                                    //chaque fois qu'on lit une ligne dans le fichier contenant les voitures(ouvert en mode "read") on l'ecrit dans un fichier
                                      //temporaire ouvert em mode "append",et si l'id d'une ligne est le meme que l'id saisie on demande les nouvelles valeurs des champs
                                      //et puis on les ecrit dans le nouveau fichier. et apres on ecrase le premier ficher et on renomme
                                      //le fichier temporaire par le meme nom que le fichier supprime.
                                      //on suit les memes etapes que la fonction modifier_enloc();
                                      //les memes aussi pour les fonctions modifierclient() et modifiercontrat().
    {
        FILE *f,*fl;
        int id ;
        int rep;
        printf("Saisir l'id de la voiture a modifier \t");
        scanf("%d",&id);
        fflush(stdin);
        if(rech(id)==1)
            {
                printf("Voulez vous vraiment modifier cette voiture? 0(Annuler); 1(Modifier) \t");
                scanf("%d",&rep);
                fflush(stdin);
                if(rep==1)
                    {
                        f=fopen("voiture.txt","r");
                        fl=fopen("deuxvoiture.txt","a");
                                do
                                {
                                /*    fscanf(f,"%d ,%s ,%s ,%s ,%d ,%d ,%d\n",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation); */
                                    if(id==NV.idVoiture)
                                    {
                                        NV.idVoiture=id;
                                        printf("Saisir la nouvelle marque :\t");    //si on est arrivÃ© Ã  une ligne dont l'id de voiture
                                        scanf("%s",&NV.marque);                    //est le meme que l'id saisi on demande de saisir les nouvelle valeurs
                                        printf("Saisir le nouveau nom : \t");       //des champs
                                        scanf("%s",&NV.nomVoiture);
                                        printf("Saisir la nouvelle couleur :\t");
                                        scanf("%s",&NV.couleur);
                                        printf("Saisir le nouveau nombre de places :\t");
                                        scanf("%d",&NV.nbplaces);
                                        printf("Saisir le nouveau prix du jour :\t");
                                        scanf("%d",&NV.prixJour);
                                        printf("Allocation :\t");
                                        scanf("%d",NV.allocation);
                                    }
                                    fprintf(fl,"%d ,%s ,%s ,%s ,%d ,%d ,%d\n",NV.idVoiture,NV.marque,NV.nomVoiture,NV.couleur,NV.nbplaces,NV.prixJour,NV.allocation );
    
                                }while(!feof(f));
                                fclose(f);
                                fclose(fl);
                                remove("voiture.txt");
                                rename("deuxvoiture.txt","voiture.txt");
                                printf("\n Voiture modifiee avec succes\n");
                    }
                else
                    printf("La modification est annulee");
    
            }
        else
            printf("\n Cet id de voiture n'existe pas \n");
        gestiondevoitures();
    }
    
            
            
            
            
            
            
            
    
    
    /*---------supprimer voiture ------*/
    
    
    //on saisie l'id de la voiture a supprimer et on verifie son existence, si oui on demande d'assurer la suppression et
                           //on copie toutes lignes du fichier contenant les voitures et ouvert en mode "read" dans un autre fichier temporaire
                            //crÃ©e SAUF la ligne qu'on veut supprimer ... et puis on supprime le premier fichier et on renomme
                            //le fichier temporaire par le meme nom que le fichier supprimÃ©.
                            //les memes etapes aussi pour les fonctions supcli() et supprimercontrat().
     void supVoi()
     {
         
         char rep;
         int NumRech;
         printf("\n Entre le Numero de la voiture a supprimer:   ");
         scanf("%d",&NumRech);
         fflush(stdin);
         if(rech(NumRech)==1)
         {printf("\n Voulez vous vraiment supprimer O/N");
         scanf("%c",&rep);
         fflush(stdin);
    if(rep=='o'||rep=='O')
        {
            FILE *F,*FICH;
            F= fopen("voiture.txt","r");
            FICH= fopen("deuxvoiture.txt","a");
            do{
                fscanf(F,"%d,%s,%s,%s,%d,%d,%s \n",&NV.idVoiture ,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
                if(NumRech!=NV.idVoiture){
                    fprintf(FICH,"%d,%s,%s,%s,%d,%d,%s \n",&NV.idVoiture ,NV.marque,NV.nomVoiture,NV.couleur,NV.nbplaces,NV.prixJour,NV.allocation);
                
                }
            }while(feof(F));
            fclose(F); 
            fclose(FICH);
            remove("voiture.txt");
            rename("deuxvoiture.txt","voiture.txt");
            printf("\n la modification est reussi:");
         }
     }
     else
     {printf("\n Le numero de voiture n'existe pas");
     }
      
    }
    
    
    
    /* ----------------affichage ---------------*/
        void afficher(){
            FILE *F;
            int i=1;
            F= fopen("voiture.txt","r");
            printf("\n \n  La liste des voiture:   ");
            do{
                fscanf(F,"%d,%s,%s,%s,%d,%d,%s \n",&NV.idVoiture ,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
                fflush(stdin);
            
                printf("%d  \t",NV.idVoiture);
                printf("%s  \t",NV.marque);
                printf("%s  \t",NV.nomVoiture);
                printf("%s  \t",NV.couleur);
                printf("%d  \t",NV.nbplaces);
                printf("%d  \t",NV.prixJour);
                printf("%s  \t",NV.allocation);
                fflush(stdin);
                break;	
            }while(!feof(F));
            
            fclose(F);
              
        }
        
        
        
        /*------------------------------------------------------------------GESTION DES CLIENTS---------------------------------------------------------------------------------------------*/
        
        
        client ID;
        
        
        
        int RC(int NRC){
            FILE *F;
            F =fopen("Client.txt","r");
            do{
                fscanf(F,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
                fflush(stdin);
                    if(ID.idClient==NRC)
        {fclose(F);
        return 1;
        }
    }while(!feof(F));
    fclose(F);
    return-1;
      gestiondeclients();
        }
        
        /*-----------------------AJOUTER client--------------*/
        void AjouterCl(){
                FILE *f;
        int num;
        f=fopen("Client.txt.txt","a");
        printf("Saisir l'id du nouveau client \n");
        scanf("%d",&num);
        ID.idClient=num;
        printf("Saisir le nom du nouveau client \n");
        scanf("%s",&ID.nom);
        fflush(stdin);
        printf("Saisir le prenom du nouveau client\n");
        scanf("%s",&ID.prenom);
        fflush(stdin);
        printf("Saisir le CIN du nouveau client \n");
        scanf("%d",&ID.cin);
        fflush(stdin);
        printf("Saisir l'adresse du nouveau client \n");
        scanf("%s",&ID.adresse);
        fflush(stdin);
        printf("Saisir le telephone du nouveau client \n");
        scanf("%d",&ID.telephone);
        fflush(stdin);
        fprintf(f,"%d ,%s ,%s ,%d ,%s ,%d \n",ID.idClient,ID.nom,ID.prenom,ID.cin,ID.adresse,ID.telephone);
        fclose(f);
        gestiondeclients();
    }
    
    
    
    
    
    /*------------suppression-----------*/
    
        void supCli()
     {
         
         char rep;
         int NumRech;
         printf("\n Entrer le numero de la voiture a supprimer:   ");
         scanf("%d",&NumRech);
         fflush(stdin);
         if(RC(NumRech)==1)
         {printf("\n voulez vous vraiment supprimer ? O/N");
         scanf("%c",&rep);
         fflush(stdin);
    if(rep=='o'||rep=='O')
        {
            FILE *F,*FICH;
            F= fopen("Client.txt","r");
            FICH= fopen("deuxClient.txt","a");
            do{
    fscanf(F,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
                if(NumRech!=ID.idClient){
                    fprintf(FICH,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
                
                }
            }while(feof(F));
            fclose(F); 
            fclose(FICH);
            remove("Client.txt");
            rename("deuxClient.txt","Client.txt");
            printf("\n La modification est reussie \n");
         }
     }
     else
     {printf("\n Le numero de client n'existe pas");
     }
      gestiondeclients();
    }
    
        /*----------Modification--------*/
        void MCL()
        {
            FILE *F,*FICH;
            int num;
            char rep='n';
            printf("\n Entrez le numero de client a Modifier:  ");
            scanf("%d",&num);
            fflush(stdin);
            if(RC(num)==1){
                printf("\n Voulez vous vraiment modifier O/N? :  ");
                scanf("%c",&rep);
                fflush(stdin);
                printf("%c",rep);
                if(rep=='o'||rep=='O')
                {
                        F= fopen("Client.txt","r");
                        
                        FICH= fopen("deuxClient.txt","a");
                    do{
                        fscanf(F,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
                        if(num==ID.idClient){
                            ID.idClient=num;
                            printf("saisir le nouveau nom: \n");
                            scanf("%s ",ID.nom);
                            fflush(stdin);
                            printf("saisir le nouveau prenom: \n");
                            scanf("%s ",ID.prenom);
                            fflush(stdin);
                            printf("saisir la nouvelle CIN: \n");
                            scanf("%d ",ID.cin);
                            fflush(stdin);
                            printf("saisir la nouvelle adresse: \n");
                            scanf("%s ",ID.adresse);
                            fflush(stdin);
                            printf("saisir le nouveau numero de telephone:\n");
                            scanf("%d ",ID.telephone);
                            fflush(stdin);
                        }
                        fprintf(FICH,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
                    }while(!feof(F));
                    fclose(F); 
            fclose(FICH);
            remove("Client.txt");
            rename("deuxClient.txt","Client.txt");
            printf("\n La modification est reussie:");
                }
                else
                {printf(" \n Modification annulee \n");
                }
            }
            else 
            printf("\n le nemero existe pas ");
            
             gestiondeclients();
        }
        
             /*----------afficher le client--------*/
    
    void AFC(){
         // on lit dans le fichier ligne par ligne et on l'affiche
        
        FILE *F;
        F=fopen("Client.txt","r");
        printf("La liste des clients est :  \n\n");
        printf("Numero\t NOM \t PRENOM \t CIN\t ADRESSE \t TELE \n\n");
        do
        {
            fscanf(F,"%d,%s,%s,%d,%s,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
            fflush(stdin);
            printf("%d\t",ID.idClient);
            printf("%s\t",ID.nom);
            printf("%s\t",ID.prenom);
            printf("%d\t",ID.cin);
            printf("%s\t",ID.adresse);
            printf("%d\t",ID.telephone);
        }while(!feof(F));
        fclose(F);
        gestiondeclients();
        //on retourne au menu precedent.et on fait la meme chose pour la fonction listedeclients().
    }
    
    
    /*-----------------------------------------------------------------------------------------------------------------------*/
    
    
    void gestiondevoitures()
    {
        int choix;
    
       
        printf("\n                Liste des voitures...............................1    ");
        printf("\n                Ajouter voiture.................................2   ");
        printf("\n                Modifier voiture................................3   ");
        printf("\n                Supprimer voiture...............................4    ");
        printf("\n                Retour..........................................5   ");
       
        printf("\n\n                                Votre choix  :  ");
    
        scanf("%d",&choix);
        switch(choix)
        {
            case 1 : afficher();
            break;
            case 2 : ajoutervoiture();
            break;
            case 3 : modifiervoiture();
            break;
            case 4 : supVoi();
            break;
            case 5 : MenuPrincipal();
            break;
        }
    }
    
    
    
    
    int gestiondeclients()
    {
        int choix;
    
        
        printf("\n                 Liste de clients...............................1    ");
        printf("\n                 Ajouter client.................................2     ");
        printf("\n                 Modifier client................................3     ");
        printf("\n                 Supprimer client...............................4     ");
        printf("\n                 Retour.........................................5     ");
        printf("\n                                                                       ");
        printf("\n\n                                Votre choix  :  ");
    
        scanf("%d",&choix);
    
        switch(choix){
                    case 1:AFC(); break;
                    case 2:AjouterCl(); break;
                    case 3: MCL(); break;
                    case 4: supCli(); break;
                    case 5 : break;
        }
    }
    
    
    
    
    
    
       
       
       
       
       
       
       void location()
    {
        int choix;
    
       
        printf("\n                Visualiser contrat...............................1    ");
        printf("\n                Louer voiture....................................2  ");
        printf("\n                Retourner voiture................................3   ");
        printf("\n                Modifier contrat.................................4   ");
        printf("\n                Supprimer contrat................................5    ");
        printf("\n                Retour...........................................6    ");
        printf("\n\n                                Votre choix  :  ");
    
        scanf("%d",&choix);
    
        switch(choix)
        {
            case 1 : voircontrat();
            break;
            case 2 : louervoiture();
            break;
            case 3 : retournervoiture();
            break;
            case 4 : modifiercontrat();
            break;
            case 5 :supprimercontrat();
            break;
            case 6 : MenuPrincipal();
            break;
        }
    }
    
    
    
         
         
         void MenuPrincipal()
    {
        int choix;
    
        
        printf("\n                   Location..............................1   \n");
        printf("\n                   Gestion voitures......................2   \n");
        printf("\n                   Gestion clients.......................3   \n");
        printf("\n                   Quitter...............................4   \n");
        printf("\n\n                                Votre choix  :  ");
    
        scanf("%d",&choix);
    
        switch(choix)
        {
            case 1 : location();
            break;
            case 2 : gestiondevoitures();
            break;
            case 3 : gestiondeclients();
            break;
            case 4 : MenuPrincipal();
            break;
        }
    }
    
         
         
        
        
        
        
        
        
        
        
        /*----------GS--------*/
        
        
        int cost(int idv,int nbj)// cette fonction calcule le prix total de location d'une voiture, apres avoir verifier que son id pass� en argument existe
                            // dans le fichier en fonction du prix du jour de chaque voiture
    {
        FILE *fv;
        int cost=0,price=0;
        fv=fopen("voiture.txt","r");
        do
        {
            fscanf(fv,"%d ,%s ,%s ,%s ,%d ,%d ,%d \n",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
            if (idv==NV.idVoiture)
            {
                price=NV.prixJour;
                cost=price*nbj;
            }
    
        }while(!feof(fv));
        fclose(fv);
        return cost;
    }
    
    
    void louervoiture()//on saisie l'id du client qui veut louer la voiture,si cet id n'exixte pas dans le fichier myclients.txt on lui
                        // assure qu'il doit s'enregister parmi les clients de l'agence, on affiche ensuite la liste des voitures disponibles
                        //on demande la saisie de lid de voiture a� louer et le nombre de jours de location, puis on calcule le cout
                        //on demande au client de remplir le contrat et de changer la valeur du champs allocation pour indiquer
                        // que la voiture n'est pas disponible
    {
        FILE *fv,*fc,*ft;
        int idc,idv,nbj ,c;
        printf("Saisir votre id\n");
        scanf("%d",&idc);
        fc=fopen("Client.txt","r");
        fscanf(fc,"%d ,%s ,%s ,%d ,%s ,%d \n",&ID.idClient,&ID.nom,&ID.prenom,&ID.cin,&ID.adresse,&ID.telephone);
        if(rech(idc) != 1)
        {
            printf("Veuillez enregistrer vos informations en premier\n");
            printf("Ajouter client\n");
            AjouterCl();
            printf("Maintenant vous pouver louer une voiture\n");
        }
    
        fv=fopen("voiture.txt","r");
        while(!feof(fv))
        {
            fscanf(fv,"%d ,%s ,%s ,%s ,%d ,%d ,%s ",&NV.idVoiture,&NV.marque,&NV.nomVoiture,&NV.couleur,&NV.nbplaces,&NV.prixJour,&NV.allocation);
            if (NV.allocation==0)
            {
                printf("L'id de la voiture : %d\t\n",NV.idVoiture);
                printf("Marque : %s\t\n",NV.marque);
                printf("Nom: %s\t\n",NV.nomVoiture);
                printf("Couleur: %s\t\n",NV.couleur);
                printf("Nombre de places : %d\t\n",NV.nbplaces);
                printf("Prix du jour : %d\t\n",NV.prixJour);
                printf("Allocation : %s\t\n",NV.allocation);
            }
        }
        printf("Veuillez saisir l'id de la voiture a louer:\n");
        scanf("%d",&idv);
        printf("Combien de jours voulez vous louer la voiture ?\n");
        scanf("%d",&nbj);
        c=cost(idv,nbj);
        printf("Vous devez payer alors %d MAD\n",c );
        printf("Veuillez remplir le contrat suivant :\n");
        creercontrat();
        printf("Changer la valeur de l'allocation en 1\n");
        modifier_alloc(); // changer la valeur de champs Ã  1
        printf("Merci d'avoir choisi notre agence\n");
        fclose(fv);
        fclose(fc);
        location();
    }
        
        
        
        
        
        
        /*--------------------Menuuuuuuuu-----------------*/
        
        
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            
