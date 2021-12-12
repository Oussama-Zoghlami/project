#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "function.h"


enum {
CIN,
NOM,
PRENOM,
JOUR,
MOIS,
ANNEE,
TYPE,
RECLAMATION,
COLUMNS
};


//ajouter
void ajouter_service(Service s) {
FILE *f;
f=fopen("etudiant.txt","a+");
if(f!=NULL) {
fprintf(f,"%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,s.d.jour,s.d.mois,s.d.annee,s.reclamation);
fclose(f);
}
}


//chercher
int chercher(char cin[]) {
Service s;
int trouve=0;
FILE *f;
f=fopen("etudiant.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s %s %s %d %d %d %s",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF) {
if(strcmp(cin,s.cin)==0) {
trouve=1;
printf("%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,s.d.jour,s.d.mois,s.d.annee,s.reclamation);
}
}
}

return trouve;
}

//affichage 
void afficher(char nom_fichier[]){
FILE *f;
Service s;
f=fopen(nom_fichier,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %d %d %d %s",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF) {
printf("%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,s.d.jour,s.d.mois,s.d.annee,s.reclamation);
}
}
else {
printf("impossible !\n");
}
}

//supprimer
void supprimer(char cin[]) {
FILE *f;
FILE *g;
Service s;
f=fopen("etudiant.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s %s %s %d %d %d %s",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF) {
if(strcmp(cin,s.cin)!=0) {
g=fopen("exemple.txt","a+");
if(g!=NULL) {
fprintf(g,"%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,s.d.jour,s.d.mois,s.d.annee,s.reclamation);
fclose(g);
}
}
}
fclose(f);
}
remove("etudiant.txt");
rename("exemple.txt","etudiant.txt");
} 




//modifier 
void modifier_service(char cin[],char nom_modifier[],char prenom_modifier[],char type_modifier[],int jour, int mois,int annee,char reclamation_modifier[]){
FILE *f;
FILE *g;
Service s;
int trouve;
trouve=chercher(cin);
f=fopen("etudiant.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s %s %s %d %d %d %s",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF) {
if(strcmp(cin,s.cin)!=0) {
g=fopen("exemple.txt","a+");
if(g!=NULL) {
fprintf(g,"%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,s.d.jour,s.d.mois,s.d.annee,s.reclamation);
fclose(g);
}
}
else {
g=fopen("exemple.txt","a+");
if(g!=NULL) {
fprintf(g,"%s %s %s %s %d %d %d %s \n",s.cin,nom_modifier,prenom_modifier,type_modifier,jour,mois,annee,reclamation_modifier);
fclose(g);
}
}
}
fclose(f);
}
remove("etudiant.txt");
rename("exemple.txt","etudiant.txt");
} 



//fonction dashbord (tache 2)
int service_reclame(int nb_reclamation_foyer,int nb_reclamation_resto){
FILE *f;
Service s;
f=fopen("etudiant.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %d %d %d %s",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF) {
if(strcmp(s.type,"Hebergement")==0){
nb_reclamation_foyer++;
}
else if(strcmp(s.type,"Restauration")==0){
nb_reclamation_resto++;
}
}
fclose(f);
}
else {
printf("impossible douvrir le fichier\n");
}
if(nb_reclamation_foyer > nb_reclamation_resto) {
return 1;
}
else if (nb_reclamation_foyer < nb_reclamation_resto) {
return 2;
}
else {
return 3;
}
}

//remplissage
void remplir(Service s,char cin[],char nom[],char prenom[], char type[], char reclamation[] )
{

  FILE *f;
  f=fopen("etudiant.txt","r+");
  if(f==NULL)
  { 
    return;
  }
  else
  { 
    while(fscanf(f,"%s %s %s %s %d %d %d %s \n",s.cin,s.nom,s.prenom,s.type,&s.d.jour,&s.d.mois,&s.d.annee,s.reclamation)!=EOF)
    {
       if(strcmp(s.cin,cin)==0)
       {
         strcpy(nom,s.nom);
	 strcpy(prenom,s.prenom);
         strcpy(type,s.type);
 	 strcpy(reclamation,s.reclamation);  
       }
   }
   fclose(f);    
   }
    
}

//affichage
void afficher_etudiant(GtkWidget *liste) {
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
char cin[20];
char nom[20];
char prenom[20];
char jour[20];
char mois[20];
char annee[20];
char type[20];
char reclamation[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",JOUR,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",MOIS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",ANNEE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes(" reclamation",renderer, "text",RECLAMATION,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f=fopen("etudiant.txt","r");
    if(f==NULL)
    {
      return;
    }
    else
    {
      f=fopen("etudiant.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,type,jour,mois,annee,reclamation)!=EOF)
         {
           gtk_list_store_append (store, &iter);
           gtk_list_store_set (store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,TYPE,type,JOUR,jour,MOIS,mois,ANNEE,annee,RECLAMATION,reclamation,-1);

         }
      fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
    }
  }
}





























