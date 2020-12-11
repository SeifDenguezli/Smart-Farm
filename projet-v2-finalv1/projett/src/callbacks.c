#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


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
windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimerEmploye();
gtk_widget_show(windowSupprimer);

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
windowSupprimer = lookup_widget(button, "windowSupprimerEmploye");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierEmploye");
gtk_widget_destroy(windowModifier);

windowAjoutEmploye = lookup_widget(button, "windowAjoutEmploye");
gtk_widget_destroy(windowAjoutEmploye);


windowListeEmployes = lookup_widget(button, "windowListeEmployes");
gtk_widget_destroy(windowListeEmployes);


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
windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierEmploye();
gtk_widget_show(windowModifier);

}

int choix[] = {0,0}; //Homme ou femme pour la fonction ajout employe
int choix1[] = {0,0};//Homme ou femme pour la fonction Modifier Employe

int i; //variable pour savoir le numero d'identifiant 
void
on_buttonAjouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
Employe p;
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

if (choix[0]==1)
strcpy(p.sexe,"Homme");
else if (choix[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;
if(((choix[0]==1) && (choix[1]==1)) || ((choix[0]==0) && (choix[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
{
windowErreur = create_windowChamps();
gtk_widget_show(windowErreur);
}
else
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
GtkWidget *windowSuccees;
Employe p;
GtkWidget *input;
input = lookup_widget(button, "entryUsername");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_employe(p,cin);
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
choix[0] = 1;
else
choix[0] = 0;
}


void
on_checkbuttonFemelle_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[1] = 1;
else
choix[1] = 0;

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

if (choix1[0]==1)
strcpy(p.sexe,"Homme");
else if (choix1[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;

if(((choix1[0]==1) && (choix1[1]==1)) || ((choix1[0]==0) && (choix1[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
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
choix1[0] = 1;
else
choix1[0] = 0;

}


void
on_checkbuttonModifierFemelle_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;

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
FILE *fp;
Employe e;
char id[30];
fp = fopen("utilisateurs.bin", "rb");
windowMain = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMain);
windowPointage = create_windowPointage();
gtk_widget_show(windowPointage);


combobox = lookup_widget(windowPointage, "comboboxentryID");
combobox1 = lookup_widget(windowPointage, "comboboxentryIDTaux");
while (fread(&e,sizeof(e),1,fp))
{
sprintf(id,"%d",e.id); //convert employe id from int to char 
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox), id); //append id's in combobox from user file(window de Pointage)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1), id); //append id's in combobox from user file(window de TAUX)
}




}


void
on_buttonCofirmerPointage_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{


Pointage p;
GtkWidget *identifiant;
GtkWidget *spin1, *spin2, *spin3;
GtkWidget *etat;
char tmp[30];

identifiant = lookup_widget(button, "comboboxentryID");
spin1 = lookup_widget(button,"spinbuttonJourPoint");
spin2 = lookup_widget(button,"spinbuttonMoisPoint");
spin3 = lookup_widget(button,"spinbuttonAnneePoint");
etat = lookup_widget(button,"comboboxentryEtat");

strcpy(tmp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
p.employe.id = atoi(tmp);


p.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
p.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
p.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));
strcpy(p.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
pointage(p);

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
treeview3 = lookup_widget(button, "treeview3");
afficher_taux(treeview3);

	tauxABS(&res, x1, x2);
	sprintf(res1, "%d%%", res);

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
GtkWidget *window;
FILE *fp1, *fp;
fp = fopen("pointage.bin","rb");
fp1 = fopen("calc.bin","wb");
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Employe e;
Pointage p;
char ident[30];
char id[30];
input = lookup_widget(button, "comboboxentryIDTaux");
buttonEnable = lookup_widget(button, "buttonConsulter"); //Pointeur sur bouton Consulter
strcpy(ident,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
treeview3 = lookup_widget(button, "treeview3");
chercher_employe_taux(e, ident, &ok);
if (ok)
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

afficher_taux(treeview3);


}

