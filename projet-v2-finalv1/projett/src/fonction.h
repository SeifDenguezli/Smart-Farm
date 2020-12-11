#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Naissance;
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
    Naissance date_naissance;
    char cin[20];
    char gsm[20];
    int id;
    compt compt;
}Employe;

typedef struct
{
	Employe employe;
	Naissance date;
	char etat[30];
	
}Pointage;


void  ajouter_employe(Employe e);
void afficher_employe(GtkWidget *liste);
void supprimer_employe(Employe e, char cin[]);
void modifier_employe(Employe h, char cin[]);
void chercher_employe(Employe e, char cin[20], int *ok);//pointeur ok pour verifier eistance du utilisateur recherché
void afficher_employeModif(GtkWidget *liste);
void afficher_employeSupp(GtkWidget *liste);
void afficher_taux(GtkWidget *liste);
void chercher_employe_taux(Employe e, char id[20], int *ok);
void pointage(Pointage p);
void  tauxABS(int *res, int x1, int x2);

