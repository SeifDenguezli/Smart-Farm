#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "equipement.h"


void
on_buttonListeEmployes_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
GtkWidget *listeemp;
GtkWidget *window;
listeemp = create_windowListeEmployes();
gtk_widget_show(listeemp);
treeview = lookup_widget(listeemp, "treeview");
afficher_employe(treeview);
window = lookup_widget(button,"windowGestionEmployes");
gtk_widget_destroy(window);




}


void
on_buttonSupprimeEmploye_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *liste;
windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimerEmploye();
gtk_widget_show(windowSupprimer);

liste = lookup_widget (windowSupprimer, "treeview5");
afficher_employe(liste);

}


void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutEmploye;
GtkWidget *windowModifier;
GtkWidget *windowListeEmployes;
GtkWidget *windowpointage;
windowSupprimer = lookup_widget(button, "windowSupprimerEmploye");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierEmploye");
gtk_widget_destroy(windowModifier);

windowAjoutEmploye = lookup_widget(button, "windowAjoutEmploye");
gtk_widget_destroy(windowAjoutEmploye);


windowListeEmployes = lookup_widget(button, "windowListeEmployes");
gtk_widget_destroy(windowListeEmployes);
windowpointage = lookup_widget(button, "windowPointage");
gtk_widget_destroy(windowpointage);


windowMenu = create_windowGestionEmployes();
gtk_widget_show(windowMenu);





}


void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAjoutEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionEmployes");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutEmploye");
windowAjout = create_windowAjoutEmploye();
gtk_widget_show(windowAjout);






}


void
on_buttonModifEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowMenu;
GtkWidget *liste;

windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierEmploye();
gtk_widget_show(windowModifier);

liste = lookup_widget (windowModifier, "treeview4");
afficher_employe(liste);


}

int choixseif[] = {0,0}; //Homme ou femme pour la fonction ajout employe
int choix1seif[] = {0,0};//Homme ou femme pour la fonction Modifier Employe

int i; //variable pour savoir le numero d'identifiant 
void
on_buttonAjouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
Employe p;
Employe e;
int fail=0;
FILE *fp1;
fp1 = fopen("utilisateurs.bin", "rb");
if (fp1==NULL)
    {
	i = 0; //Id = 0 si le fichier n'existe pas (pas d'employe ajouté)
    }
    
 
    else
    {
	while (fread(&p,sizeof(p),1,fp1))
	{
		i = p.id; // i prends la valeur du dernier employe ajouté
	}
    }
fclose(fp1);
i++; // si le dernier employe ajouté à un id=5 donc i=6 ou si il nya pas d'employe, i commence de 1

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *dialog;


input1 = lookup_widget(button, "entryNom");
input2 = lookup_widget(button, "entryPrenom");
input3 = lookup_widget(button, "entryCin");
input4 = lookup_widget(button, "entryGsm");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));

if (choixseif[0]==1)
strcpy(p.sexe,"Homme");
else if (choixseif[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;
if(((choixseif[0]==1) && (choixseif[1]==1)) || ((choixseif[0]==0) && (choixseif[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
{
windowErreur = create_windowChamps();
gtk_widget_show(windowErreur);
fail=1;
}
fp1 = fopen("utilisateurs.bin", "rb");
if(fp1==NULL)
{
	return;
}
else
{
while (fread(&e, sizeof(e), 1, fp1))
{
	if(strcmp(e.cin, p.cin)==0)
	{
		dialog = create_dialog6();
		gtk_widget_show(dialog);
		fail = 1;
		break;
	}
}
fclose(fp1);
}

if (fail==0)
{
ajouter_employe(p);
windowSuccees = create_dialog1();
gtk_widget_show(windowSuccees);
}

}


void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Employe e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonModif"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowModifierEmploye");
treeview1 = lookup_widget(window, "treeview1");
chercher_employe(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_employeModif(treeview1);

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[30];
int id;
GtkWidget *windowSuccees;
Employe p;
Pointage e;
GtkWidget *input;
input = lookup_widget(button, "entryUsername");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input)));
id = id_supprimer_employe(p, cin);
supprimer_employe(p,cin);
supprimer_pointage(e, id);
windowSuccees = create_dialog3();
gtk_widget_show(windowSuccees);
}


/*void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{



}
*/

void
on_checkbuttonMale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixseif[0] = 1;
else
choixseif[0] = 0;
}


void
on_checkbuttonFemelle_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixseif[1] = 1;
else
choixseif[1] = 0;

}





gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonRefresh_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listeemp;
listeemp = create_windowListeEmployes();
treeview = lookup_widget(listeemp, "treeview");
afficher_employe(treeview);


}

char tmps[30];// stocker dans la variable tmps le cin de l'utilisateur a modifier pour l'utiliser dans l'affichage
void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

Employe e;
GtkWidget *input1;
GtkWidget *windowModification;
//char cin[30];
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entryUsername");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierEmploye();
gtk_widget_show(windowModification);
// *********************************	SET TEXT TO ENTRIES	***************************
GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7;
if(fp!=NULL)
{
while (fread(&e, sizeof(e), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryModifierNom");
	gtk_entry_set_text(GTK_ENTRY(output1), e.nom);

	output2 = lookup_widget(windowModification, "entryModifierPrenom");
	gtk_entry_set_text(GTK_ENTRY(output2), e.prenom);

	output3 = lookup_widget(windowModification, "entryModifierCin");
	gtk_entry_set_text(GTK_ENTRY(output3), e.cin);

	output4 = lookup_widget(windowModification, "entryModifierGsm");
	gtk_entry_set_text(GTK_ENTRY(output4), e.gsm);

	output5 = lookup_widget(windowModification, "spinbuttonModifierJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), e.date_naissance.jour);


	output6 = lookup_widget(windowModification, "spinbuttonModifierMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), e.date_naissance.mois);


	output7 = lookup_widget(windowModification, "spinbuttonModifierAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7), e.date_naissance.annee);

}
}
////////////////////////////////////////////////////////
fclose(fp);
}


void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

Employe p;
FILE *fp1;
fp1 = fopen("utilisateurs.bin", "rb");
if (fp1==NULL)
    {
	i = 0;
    }
    
 
    else
    {
	while (fread(&p,sizeof(p),1,fp1))
	{
		if (strcmp(p.cin,tmps)==0){
		i = p.id; // i prends la valeur de l'employe qui a la cin à rechercher
		break;}
	}
    }

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *windowM;


input1 = lookup_widget(button, "entryModifierNom");
input2 = lookup_widget(button, "entryModifierPrenom");
input3 = lookup_widget(button, "entryModifierCin");
input4 = lookup_widget(button, "entryModifierGsm");
Jour = lookup_widget(button, "spinbuttonModifierJour");
Mois = lookup_widget(button, "spinbuttonModifierMois");
Annee = lookup_widget(button, "spinbuttonModifierAnnee");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));

if (choix1seif[0]==1)
strcpy(p.sexe,"Homme");
else if (choix1seif[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;

if(((choix1seif[0]==1) && (choix1seif[1]==1)) || ((choix1seif[0]==0) && (choix1seif[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
{
windowErreur = create_windowChamps();
gtk_widget_show(windowErreur);
}
else
{
modifier_employe(p, tmps);  
windowSuccees = create_dialog2();
gtk_widget_show(windowSuccees);
windowM = lookup_widget(button, "ModifierEmploye");
gtk_widget_destroy(windowM);
}




}


void
on_checkbuttonModifierMale_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1seif[0] = 1;
else
choix1seif[0] = 0;

}


void
on_checkbuttonModifierFemelle_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1seif[1] = 1;
else
choix1seif[1] = 0;

}


void
on_RechercherSupp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview2;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Employe e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonSupprimer"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowSupprimerEmploye");
treeview2 = lookup_widget(window, "treeview2");
chercher_employe(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_employeModif(treeview2);

}


void
on_buttonPointage_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowPointage;
GtkWidget *windowMain;
GtkWidget *combobox;//pointeur combobox dynamique
GtkWidget *combobox1;
GtkWidget *buttonEnable;
FILE *fp, *fp2;
Employe e;
char id[30];
fp = fopen("utilisateurs.bin", "rb");
windowMain = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMain);
windowPointage = create_windowPointage();
gtk_widget_show(windowPointage);

buttonEnable = lookup_widget(windowPointage, "buttonChercherTaux");
combobox = lookup_widget(windowPointage, "comboboxentryID");
combobox1 = lookup_widget(windowPointage, "comboboxentryIDTaux");
if(fp!=NULL)
{
while (fread(&e,sizeof(e),1,fp))
{
sprintf(id,"%d",e.id); //convert employe id from int to char 
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox), id); //append id's in combobox from user file(window de Pointage)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1), id); //append id's in combobox from user file(window de TAUX)
}
fclose(fp);
}
fp2 = fopen("pointage.bin","rb");
if(fp2==NULL)
{
	gtk_widget_set_sensitive(buttonEnable, FALSE);
}
//fclose(fp2);

}


void
on_buttonCofirmerPointage_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{


Pointage p;
GtkWidget *identifiant;
GtkWidget *spin1, *spin2, *spin3;
GtkWidget *etat;
GtkWidget *dialog;
GtkWidget *buttonEnable;
char tmp[30];

identifiant = lookup_widget(button, "comboboxentryID");
spin1 = lookup_widget(button,"spinbuttonJourPoint");
spin2 = lookup_widget(button,"spinbuttonMoisPoint");
spin3 = lookup_widget(button,"spinbuttonAnneePoint");
etat = lookup_widget(button,"comboboxentryEtat");
buttonEnable = lookup_widget(button, "buttonChercherTaux");

dialog = create_windowChamps();

p.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
p.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
p.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));


if((gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant))==NULL) || (gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat))==NULL))
{
	gtk_widget_show(dialog);

}
else
{
strcpy(tmp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
p.employe.id = atoi(tmp);
strcpy(p.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
gtk_widget_set_sensitive(buttonEnable, TRUE);
pointage(p);

}
}


void
on_buttonConsulter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

Pointage p;
int res;
int x1,x2;
char res1[30];

char id[30];
char ident[30];
GtkWidget *identifiant;
GtkWidget *treeview3;
GtkWidget *label;
label = lookup_widget(button, "labelTaux");
identifiant = lookup_widget(button, "comboboxentryIDTaux");
strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
//treeview3 = lookup_widget(button, "treeview3");
//afficher_taux(treeview3);

	res = tauxABS();
	sprintf(res1, "Taux d'absenteisme : %d%%", res);

gtk_label_set_text(GTK_LABEL(label),res1);


}


void
on_buttonChercherTaux_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *dialog;
FILE *fp1, *fp;
fp = fopen("pointage.bin","rb");
fp1 = fopen("calc.bin","wb");
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
int ok1;
Employe e;
Pointage p;
char ident[30];
char id[30];
input = lookup_widget(button, "comboboxentryIDTaux");
buttonEnable = lookup_widget(button, "buttonConsulter"); //Pointeur sur bouton Consulter
dialog = create_dialog5();
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input))==NULL)
{
	gtk_widget_show(dialog);
}
else
{
strcpy(ident,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
treeview3 = lookup_widget(button, "treeview3");
chercher_employe_taux(e, ident, &ok);
check(p, ident, &ok1);
if ((ok) && (ok1))
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE
if((fp1==NULL))
{
return;
}
else
{
	while (fread(&p,sizeof(p),1,fp))
	{
		sprintf(id, "%d", p.employe.id);
		if(strcmp(id,ident)==0)
		{
		fwrite(&p, sizeof(p), 1 ,fp1);
		}	
	}

}
fclose(fp);
fclose(fp1);

afficher_taux(treeview3, ident);

}
}


void
on_buttonRefreshTaux_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelMeilleur;
GtkWidget *liste;
GtkWidget *img;
int identifiantFinal;
int x1, x2;
int res;
int meilleurEmp=100;
int id;
char meilleurCh[100];
labelMeilleur = lookup_widget(button, "label66");
img = lookup_widget(button, "image52");
FILE *fp;
Pointage p;
fp = fopen("pointage.bin", "rb");
if(fp==NULL)
{
	return;
}
else
{
while (fread(&p, sizeof(p), 1, fp))
{
	x1 = premier(p.employe.id);
	deuxieme(p.employe.id, &x2);
	if(x2==0)
	{
		gtk_label_set_text(GTK_LABEL(labelMeilleur), "Erreur!");
		break;
	}
	else
	{
	res = (x1*100)/x2;
	}
	if(res<meilleurEmp)
	{
		meilleurEmp = res;
		id = p.employe.id;
	}
}
sprintf(meilleurCh, "Meilleur Taux : %d%%", meilleurEmp);
gtk_label_set_text(GTK_LABEL(labelMeilleur), meilleurCh);
}
fclose(fp);
liste = lookup_widget(button, "treeview6");
afficher_meilleur_employe(liste, id);
gtk_widget_show(img);


}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1");
gtk_widget_destroy(window);


}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowChamps");
gtk_widget_destroy(window);

}


void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog5");
gtk_widget_destroy(window);

}


void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog6");
gtk_widget_destroy(window);

}


void
on_buttonGenererPire_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *labelPire;
GtkWidget *liste;
GtkWidget *img;
int identifiantFinal;
int x1, x2;
int res;
int pireEmp=0;
int id;
char pireCh[100];
labelPire = lookup_widget(button, "label79");
img = lookup_widget(button, "image53");
FILE *fp;
Pointage p;
fp = fopen("pointage.bin", "rb");
if(fp==NULL)
{
	return;
}
else
{
while (fread(&p, sizeof(p), 1, fp))
{
	x1 = premier(p.employe.id);
	deuxieme(p.employe.id, &x2);
	if(x2==0)
	{
		gtk_label_set_text(GTK_LABEL(labelPire), "Erreur!");
		break;
	}
	else
	{
	res = (x1*100)/x2;
	}
	if(res>pireEmp)
	{
		pireEmp = res;
		id = p.employe.id;
	}
}
sprintf(pireCh, "Pire Taux : %d%%", pireEmp);
gtk_label_set_text(GTK_LABEL(labelPire), pireCh);
}
fclose(fp);
liste = lookup_widget(button, "treeview7");
afficher_meilleur_employe(liste, id);
gtk_widget_show(img);


}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/


/*********************************************Acceuil button*********************************************/

void
on_acceuil_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gesteq;
GtkWidget *windowmenu1;
GtkWidget *windowmenu2;
GtkWidget *windowmenu3;
GtkWidget *windowmenu4;
GtkWidget *windowmenu5;
gesteq = create_gesteq ();
gtk_widget_show (gesteq);
windowmenu1=lookup_widget(button,"Recheq");
gtk_widget_destroy(windowmenu1);
windowmenu5=lookup_widget(button,"tache2");
gtk_widget_destroy(windowmenu5);
windowmenu2=lookup_widget(button,"supeq");
gtk_widget_destroy(windowmenu2);
windowmenu3=lookup_widget(button,"listeq");
gtk_widget_destroy(windowmenu3);
windowmenu4=lookup_widget(button,"ajoutereq");
gtk_widget_destroy(windowmenu4);
}
/*********************************************Retour**********************************************************/

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}

/************************************************Deco*******************************************************/
void
on_deco_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

/**************************************************Ajout window show*****************************************************/
void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutereq;
GtkWidget *windowmenu;
ajoutereq = create_ajoutereq ();
gtk_widget_show (ajoutereq);
windowmenu=lookup_widget(objet,"gesteq");
gtk_widget_destroy(windowmenu);

}

/************************************************Modif window show*******************************************************/
void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *recheq;
GtkWidget *windowmenu;
GtkWidget *treeview5;
GtkWidget *treev;
recheq = create_Recheq ();
gtk_widget_show (recheq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);

treev=lookup_widget(recheq,"treev");
listeModif(treev);
treeview5=lookup_widget(recheq,"treeview5");
liste(treeview5);

}

/*************************************************Supp window show******************************************************/
void
on_supp_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview6;
GtkWidget *supeq;
GtkWidget *windowmenu;
GtkWidget *treesupp;
supeq = create_supeq ();
gtk_widget_show (supeq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
treesupp=lookup_widget(supeq,"treev");
listeModif(treesupp);
treeview6=lookup_widget(supeq,"treeview6");
liste(treeview6);

}

/***********************************************Liste d'equipement********************************************************/
void
on_list_clicked                        (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *windowmenu;
GtkWidget *listeq;
GtkWidget *treeview1;
GtkWidget *combo;
FILE *f;
FILE *f1;
equipement e;
equipement c;
listeq = create_listeq ();
gtk_widget_show (listeq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
treeview1=lookup_widget(listeq,"treeview1");
liste(treeview1);
combo=lookup_widget(listeq,"combobox1");
//gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(c.marque));


/*f=fopen("equipement.bin","rb");
f1=fopen("test1.bin","a+b");
 if (f==NULL)
{return;}
while(fread(&e,sizeof(e),1,f))
	{	
	 		
  	 		fwrite(&c,sizeof(c),1,f1);
			fclose(f1);
			f1=fopen("test1.bin","rb");
			while(fread(&c,sizeof(c),1,f1))
			if(strcmp(e.marque,c.marque)==1)
			{fwrite(&e,sizeof(e),1,f1);
				
			}

		 gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(e.marque));
	}



fclose(f); */
		   /****************************OO******DOUTE*********OO*****************************/
 	 	/*************************OO*********DOUTE***********OO***************************/
		/***********************OO***********DOUTE*************OO*************************/
		/*********************OO*************DOUTE***************OO***********************/
}


/*********************************************Ajouter eqiupement**********************************************************/
void
on_ajouteq_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
equipement P;
GtkWidget *output=NULL;
GtkWidget *ajoutereq;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *dialog1;
GtkWidget *dialog3;
FILE *f;
char reference[30];
equipement h;
int fail=0;
int pass=0;

type=lookup_widget(objet,"entrytyp");
design=lookup_widget(objet,"entrydesign");
ref=lookup_widget(objet,"entryref");
marque=lookup_widget(objet,"entrymarq");
prix=lookup_widget(objet,"entryprix");
stock=lookup_widget(objet,"stockentry");
strcpy(P.type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(P.designation,gtk_entry_get_text(GTK_ENTRY(design)));
strcpy(P.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(P.prixachat,gtk_entry_get_text(GTK_ENTRY(prix)));
strcpy(P.stock,gtk_entry_get_text(GTK_ENTRY(stock)));           
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(P.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
f=fopen("equipement.bin","a+b");
if(f==NULL)
	{return;}
else { 
while(fread(&h,sizeof(h),1,f) )
{ fail=0;
		if(strcmp(h.ref,reference)==0)
		{
		/*dialog1=create_dialog1();
		gtk_widget_show(dialog1);*/
		fail=1;
		}
		if(fail==1)
		{pass=1;}
 

	
}

 
if((strcmp(P.type,"")==0)||(strcmp(P.designation,"")==0) || (strcmp(P.ref,"")==0)  || (strcmp(P.marque,"")==0) || (strcmp(P.prixachat,"")==0) || (strcmp(P.stock,"")==0)||(pass==1))
{

dialog1=create_dialog1has();
gtk_widget_show(dialog1);
return;

}
else {

ajouterequipement(P);
dialog3=create_dialog3has();
gtk_widget_show(dialog3);

}
}
}



/**********************************************Interactive search*********************************************************/
gboolean
on_treeview1_start_interactive_search  (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return TRUE;
}
/****************************************************Supprimer l'equipement***************************************************/

void
on_supbut_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input;  
  GtkWidget *output;
  GtkWidget *dialog4;

  equipement P;
                                        
char ref1[20];
 input=lookup_widget(button,"chersupp");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer(ref1);
supprimert2(ref1);
dialog4=create_dialog3has();
gtk_widget_show(dialog4);

}
/**********************************************Chercher ref*********************************************************/
void
on_refrechbut_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *treev;
  GtkWidget *treeview5;
  GtkWidget *buttonactiv;
 GtkWidget *input;  
GtkWidget *Recheq;
  equipement P;
int verif;
 char ref1[50];
 input=lookup_widget(button,"rechref");
buttonactiv= lookup_widget(button,"mod");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
Recheq=lookup_widget(button,"Recheq");
treev=lookup_widget(Recheq,"treev");
cherchereq(P,ref1,&verif);
if(verif)
gtk_widget_set_sensitive(buttonactiv, TRUE);
else
gtk_widget_set_sensitive(buttonactiv, FALSE);
listeModif(treev);
treeview5=lookup_widget(button,"treeview5");
liste(treeview5);



}

/*******************************************************************************************************/
void
on_treeview1_set_scroll_adjustments    (GtkTreeView     *treeview,
                                        GtkAdjustment   *hadjustment,
                                        GtkAdjustment   *vadjustment,
                                        gpointer         user_data)
{

}

/*********************************************actualiser**********************************************************/
void
on_Actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{


}
/**************************************************window modif+entry*****************************************************/
char ref1[30];

void
on_mod_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
equipement P;
GtkWidget *window;
GtkWidget *input;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *recheq;
GtkWidget *buttonactiv;

FILE *f;

input=lookup_widget(button,"rechref");
strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
window=create_modificationwindow();
gtk_widget_show(window);

/* Reading entries */
f=fopen("modtemp.bin","rb");
while(fread(&P,sizeof(P),1,f))
{
type=lookup_widget(window,"type");
gtk_entry_set_text(GTK_ENTRY(type),P.type);
design=lookup_widget(window,"designation");
gtk_entry_set_text(GTK_ENTRY(design),P.designation);
ref=lookup_widget(window,"refrence");
gtk_entry_set_text(GTK_ENTRY(ref),P.ref);
marque=lookup_widget(window,"marque");
gtk_entry_set_text(GTK_ENTRY(marque),P.marque);
prix=lookup_widget(window,"prixachat");
gtk_entry_set_text(GTK_ENTRY(prix),P.prixachat);
stock=lookup_widget(window,"stock");
gtk_entry_set_text(GTK_ENTRY(stock),P.stock);
}
recheq=lookup_widget(button,"Recheq");
buttonactiv= lookup_widget(recheq,"mod");
gtk_widget_set_sensitive(buttonactiv, FALSE);

fclose(f);




}

/*******************************************************************************************************/

void
on_treev_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
/*******************************************Confirmer modif************************************************************/

void
on_confirm_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
equipement P;
//equipement h;
GtkWidget *output=NULL;
GtkWidget *ajoutereq;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *dialog1;
GtkWidget *windowmenu;
GtkWidget *buttonactiv;

GtkWidget *tache2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;

tache2=create_tache2();
radiobutton1=lookup_widget(tache2,"radiobutton1");
radiobutton2=lookup_widget(tache2,"radiobutton2");
radiobutton3=lookup_widget(tache2,"radiobutton3");
radiobutton4=lookup_widget(tache2,"radiobutton4");
    

type=lookup_widget(button,"type");
design=lookup_widget(button,"designation");
ref=lookup_widget(button,"refrence");
marque=lookup_widget(button,"marque");
prix=lookup_widget(button,"prixachat");
stock=lookup_widget(button,"stock");
strcpy(P.type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(P.designation,gtk_entry_get_text(GTK_ENTRY(design)));
strcpy(P.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(P.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(P.prixachat,gtk_entry_get_text(GTK_ENTRY(prix)));
strcpy(P.stock,gtk_entry_get_text(GTK_ENTRY(stock)));


if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
     {
             strcpy(P.situation,"libre");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
                 {
               strcpy(P.situation,"ocuppe");
                 }
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
     {
             strcpy(P.etat,"fonctionel");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
                 {
               strcpy(P.etat,"defaillant");
                 }


if((strcmp(P.type,"")==0)||(strcmp(P.designation,"")==0) || (strcmp(P.ref,"")==0)  || (strcmp(P.marque,"")==0) || (strcmp(P.prixachat,"")==0) || (strcmp(P.stock,"")==0))
{
dialog1=create_dialog1has();
gtk_widget_show(dialog1);
}
else {
modif_eq(P,ref1);
modif_eq2(P,ref1);

windowmenu=lookup_widget(button,"modificationwindow");
gtk_widget_destroy(windowmenu);

}



}
/***********************************etat window + new collumns**********************************************/

void
on_etateq_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
char refer[30];
equipement e;
FILE *f;
GtkWidget *combo;
GtkWidget *tache2;
GtkWidget *windowmenu;

f=fopen("equipement.bin","rb");
tache2=create_tache2();
gtk_widget_show(tache2);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
combo=lookup_widget(tache2,"comboboxentry2");
if(f==NULL)
{
return;
}
while(fread(&e,sizeof(e),1,f))
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(e.ref));
}
fclose(f);



GtkWidget *treeview2;



//gtk_widget_destroy(windowmenu);
treeview2=lookup_widget(tache2,"treeview2");
listeficher(treeview2);
}


/********************************************Dialog***********************************************************/
void
on_format_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
dialog2=create_dialog2has();
gtk_widget_show(dialog2);
}

/**********************************************Dialog sure*********************************************************/
void
on_sure_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
remove("equipement.bin");
remove("modtemp.bin");
remove("eq.bin");
dialog2=lookup_widget(button,"dialog2has");
gtk_widget_destroy(dialog2);
}

/*************************************************Dialog non******************************************************/
void
on_notsure_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
dialog2=lookup_widget(button,"dialog2has");
gtk_widget_destroy(dialog2);

}

/*************************************************Supp reference cherch******************************************************/
void
on_chersup_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *treesupp;
  GtkWidget *buttonactiv;
 GtkWidget *input;  
GtkWidget *supeq;
GtkWidget *treeview6;
  equipement P;
int verif;
 char ref1[50];
 input=lookup_widget(button,"chersupp");
buttonactiv= lookup_widget(button,"supbut");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
supeq=lookup_widget(button,"supeq");
treesupp=lookup_widget(supeq,"treesupp");
cherchereq(P,ref1,&verif);
if(verif)
gtk_widget_set_sensitive(buttonactiv, TRUE);
else
gtk_widget_set_sensitive(buttonactiv, FALSE);
listeModif(treesupp);
treeview6=lookup_widget(button,"treeview6");
liste(treeview6);




}



/**************************************************************************************/
void
on_sauv_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{ char item[20];
GtkWidget *combo;
GtkWidget *tache2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;
GtkWidget *treeview2;
equipement P;
radiobutton1=lookup_widget(button,"radiobutton1");
radiobutton2=lookup_widget(button,"radiobutton2");
radiobutton3=lookup_widget(button,"radiobutton3");
radiobutton4=lookup_widget(button,"radiobutton4");

FILE *f,*f1;
tache2=create_tache2();
combo=lookup_widget(button,"comboboxentry2");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo))==NULL)
{return;}
else
{
strcpy(item,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
}
f=fopen("equipement.bin","rb");
f1=fopen("eq.bin","ab+");


while(fread(&P,sizeof(P),1,f))
{
if(strcmp(item,P.ref)==0)
{


if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
     {
             strcpy(P.situation,"libre");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
                 {
               strcpy(P.situation,"ocuppe");
                 }
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
     {
             strcpy(P.etat,"fonctionel");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
                 {
               strcpy(P.etat,"defaillant");
                 }
fwrite(&P,sizeof(P),1,f1);

}


}
fclose(f);
fclose(f1);
treeview2=lookup_widget(button,"treeview2");
listeficher(treeview2);




}




void
on_closebutton1has_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *close;
close=lookup_widget(button,"dialog1has");
gtk_widget_destroy(close);
}


void
on_stat1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
GtkWidget *lablebi;
GtkWidget *defaille;
GtkWidget *fois;

GtkWidget *treeview3;
int def;
char text[20]="";
tache2=lookup_widget(button,"tache2");
def=calcul_defaillement();
sprintf(text,"%d",def);
lablebi=lookup_widget(button,"testlab");
gtk_label_set_text(lablebi,text);
defaille=lookup_widget(button,"label69");
gtk_label_set_text(defaille,"Defaillé");
fois=lookup_widget(button,"label70");
gtk_label_set_text(fois,"fois");


treeview3=lookup_widget(button,"treeview3");
listedefaillant(treeview3);
}


void
on_stat2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
GtkWidget *utilise;
GtkWidget *fois1;
GtkWidget *treeview4;
GtkWidget *utilisation; 
int ut;
char text1[20]="";
tache2=lookup_widget(button,"tache2");
ut=calcul_utilisation();
sprintf(text1,"%d",ut);
utilisation=lookup_widget(button,"label72");
gtk_label_set_text(utilisation,text1);
utilise=lookup_widget(button,"label71");
gtk_label_set_text(utilise,"Utilisé");
fois1=lookup_widget(button,"label73");
gtk_label_set_text(fois1,"fois");


treeview4=lookup_widget(tache2,"treeview4");
listeut(treeview4);
}







void
on_succeshas_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialogsuc;
dialogsuc=lookup_widget(button,"dialog3has");
gtk_widget_destroy(dialogsuc);

}





gboolean
on_eventbox1_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

GtkWidget *windowHsan;
GtkWidget *window;
windowHsan = create_gesteq();
gtk_widget_show(windowHsan);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
  return FALSE;
}


gboolean
on_eventbox2_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
GtkWidget *windowSeif;
GtkWidget *window;
windowSeif = create_windowGestionEmployes();
gtk_widget_show(windowSeif);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
  return FALSE;
}

