#include "fonction.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
NOM,
PRENOM,
SEXE,
DATE_NAISSANCE,
CIN,
GSM,
ID,
COLUMNS
};


void ajouter_employe(Employe e)
{
    FILE *fp;
    fp = fopen("utilisateurs.bin", "ab+");
    if (fp!=NULL)
    {
        

        fwrite(&e, sizeof(e), 1, fp);
        
    }
    else
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
fclose(fp);
}

void afficher_employe(GtkWidget *liste)
{
Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;

FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("utilisateurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("utilisateurs.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void supprimer_employe(Employe e, char cin[])
{

FILE *fp1, *fp2;
    fp1 = fopen("utilisateurs.bin", "rb");
    fp2 = fopen("temp.bin", "ab+");
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
    else
    {
        while (fread(&e, sizeof(e), 1, fp1))
        {
            if (strcmp(cin, e.cin)!=0)
                fwrite(&e, sizeof(e), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("utilisateurs.bin");
    rename("temp.bin", "utilisateurs.bin");
}

void chercher_employe(Employe e, char cin[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("utilisateurs.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&e, sizeof(e), 1, fp))
{
	if (strcmp(cin, e.cin)==0)
	{
		fwrite(&e, sizeof(e), 1, fp1);
		*ok=1; // ok prends la valeur 1 si cin existe *********** sinon ok = 0
	}

}
}
fclose(fp);
fclose(fp1);
}

void afficher_employeModif(GtkWidget *liste)
{
Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("temp1.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void modifier_employe(Employe h, char cin[])
{
FILE *fp1, *fp2;
Employe e;
fp1 = fopen("utilisateurs.bin", "rb");
fp2 = fopen("tmpp.bin","ab+");
if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&e,sizeof(e),1,fp1))
	{
		if (strcmp(e.cin,cin)!=0)
			fwrite(&e,sizeof(e),1,fp2);
		else
		{
			fwrite(&h,sizeof(h),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("utilisateurs.bin");
rename("tmpp.bin", "utilisateurs.bin");

}




