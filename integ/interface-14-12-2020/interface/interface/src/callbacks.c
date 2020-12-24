#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "equipement.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

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
on_sure_activate                       (GtkButton       *button,
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

