typedef struct
{
char username[20];
char password[20];

}compt;


typedef struct 
{
char nom[20];
char prenom[20];
char sexe[20];
char date_naissance[20];
char gsm[20];
char cin[20];
int taux_abs;
compt c;
}Employe;

void ajout_employe(Employe e);

void modifier_employe(char cin[]); //(retour les données de l'employé en tant que pointeur)

void supprimer_employe(char cin[]);

void liste_employes(); //affichage simple

Employe meilleur_employe(); //Selon taux d'abs

void taux_abs(); //ajouter un char dans la structure int note (diminue ou auguement selon abs)



