#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "function.h"

int n;
void
on_ZOGbuttonajout_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *ajouter;

   reclamation_etudiant=lookup_widget(objet,"reclamation_etudiant");
   gtk_widget_destroy(reclamation_etudiant);
   ajouter=create_ajouter();
   gtk_widget_show(ajouter);
}


void
on_ZOGbuttonmodifier_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *modifier;

   reclamation_etudiant=lookup_widget(objet,"reclamation_etudiant");
   gtk_widget_destroy(reclamation_etudiant);
   modifier=create_modifier();
   gtk_widget_show(modifier);
}


void
on_ZOGbuttonsuprimer_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *suprimer;

   reclamation_etudiant=lookup_widget(objet,"reclamation_etudiant");
   suprimer=create_suprimer();
   gtk_widget_show(suprimer);
}


void
on_ZOGbuttonretour_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_ZOGbuttonreponse_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *reponse;

   reclamation_etudiant=lookup_widget(objet,"reclamation_etudiant");
   gtk_widget_destroy(reclamation_etudiant);
   reponse=create_reponse();
   gtk_widget_show(reponse);
}


void
on_ZOGbuttonretour1_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *ajouter;

   ajouter=lookup_widget(objet,"ajouter");
   gtk_widget_destroy(ajouter);
   reclamation_etudiant=create_reclamation_etudiant();
   gtk_widget_show(reclamation_etudiant);
}


void
on_ZOGbuttonterminer_clicked           (GtkButton       *ob,
                                        gpointer         user_data)
{
   Service s;
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6,*input7,*input8;
   GtkWidget *ajouter;

   ajouter=lookup_widget(ob,"ajouter");

   input1=lookup_widget(ob,"cin");
   input2=lookup_widget(ob,"nom");
   input3=lookup_widget(ob,"prenom");
   input4=lookup_widget(ob,"ZOGspinbuttonjour");
   input5=lookup_widget(ob,"ZOGspinbuttonmois");
   input6=lookup_widget(ob,"ZOGspinbuttonannee");
   input7=lookup_widget(ob,"combobox_service");
   input8=lookup_widget(ob,"texte");

   strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
   s.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
   s.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
   s.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
   strcpy(s.reclamation,gtk_entry_get_text(GTK_ENTRY(input8)));
   

   ajouter_service(s);
}


void
on_ZOGbuttonterminer1_clicked          (GtkButton       *ob,
                                        gpointer         user_data)
{
   Service s;
   char ch1[20];
   char ch2[20];
   char ch3[20];
   char ch4[20];
   int j;
   int m;
   int a;
   char ch5[20];
   GtkWidget *input1, *input2, *input3, *input4, *input5, *input6,*input7,*input8;
   GtkWidget *modifier;

   modifier=lookup_widget(ob,"modifier");

   input1=lookup_widget(ob,"cinmodif");
   input2=lookup_widget(ob,"nommodif");
   input3=lookup_widget(ob,"prenommodif");
   input4=lookup_widget(ob,"ZOGspinbuttonjour1");
   input5=lookup_widget(ob,"ZOGspinbuttonmois1");
   input6=lookup_widget(ob,"ZOGspinbuttonannee1");
   input7=lookup_widget(ob,"comboboxentry2");
   input8=lookup_widget(ob,"texte2");

   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(input3)));
   j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
   m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
   a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
   strcpy(ch4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
   strcpy(ch5,gtk_entry_get_text(GTK_ENTRY(input8)));
   modifier_service(ch1,ch2,ch3,ch4,j,m,a,ch5);
}


void
on_ZOGbuttonchercher_clicked           (GtkButton       *ob,
                                        gpointer         user_data)
{
   Service s;
   int t;
   int k=-1;
   int m=-1;
   char ch1[50];
   char ch2[50];
   char ch3[50];
   char ch4[50];
   char ch5[50];
   GtkWidget *input1, *output2, *output3, *output4, *output5;
   input1=lookup_widget(ob,"cinmodif");
   output2=lookup_widget(ob,"nommodif");
   output3=lookup_widget(ob,"prenommodif");
   output4=lookup_widget(ob,"comboboxentry2");
   output5=lookup_widget(ob,"texte2");

   strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input1)));
   t=chercher(ch1);
   if (t==1)
      {
           remplir(s,ch1,ch2,ch3,ch4,ch5);
           gtk_entry_set_text(output2,ch2);
           gtk_entry_set_text(output3,ch3);
	   gtk_entry_set_text(output5,ch5);
	   if(strcmp(ch4,"Hebergement")==0)
 		{		
 		k=0;
		}
	   else if (strcmp(ch4,"Restauration")==0)
	       {		
		k=1;
		}
	   gtk_combo_box_set_active(GTK_COMBO_BOX(output4),k);
      }
}


void
on_ZOGbuttonretour2_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *modifier;

   modifier=lookup_widget(objet,"modifier");
   gtk_widget_destroy(modifier);
   reclamation_etudiant=create_reclamation_etudiant();
   gtk_widget_show(reclamation_etudiant);
}


void
on_ZOGbuttonsuprimer1_clicked          (GtkButton       *ob,
                                        gpointer         user_data)
{
   GtkWidget *input1;
   GtkWidget *suprimer;
   char cin[20];

   suprimer=lookup_widget(ob,"suprimer");

   input1=lookup_widget(ob,"cinsupp");

   strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
   supprimer(cin);
}


void
on_ZOGbuttonokay_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input,*output;
GtkWidget *studentanswer;
FILE *f;
int trouve=0;
char cin[20];
char cinverif[20];
char reponse[20];
char texte[100];
char ch1[100]="votre reclamation est : ";
input=lookup_widget(button,"entry8");
output=lookup_widget(button,"studentanswer");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("reponse.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s \n",cinverif,reponse)!=EOF) {
if(strcmp(cin,cinverif)==0) {
trouve=1;
strcat(ch1,reponse);
strcpy(texte,ch1);
}
}
if (trouve==0) {
gtk_label_set_text(GTK_LABEL(output),"votre reclamation est : en attente");
}
else {
gtk_label_set_text(GTK_LABEL(output),texte);
}
}
}

void
on_ZOGbuttonretour3_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *reponse;

   reponse=lookup_widget(objet,"reponse");
   gtk_widget_destroy(reponse);
   reclamation_etudiant=create_reclamation_etudiant();
   gtk_widget_show(reclamation_etudiant);
}


void
on_btnTerminer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output,*input;
FILE *f;
char cin[20];
char texte1[20];
input=lookup_widget(button,"cinreponse");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

if (n==1)
{strcpy(texte1,"accepter");
}
else
if (n==2) {
strcpy(texte1,"refuser");
}
f=fopen("reponse.txt","a+");
if(f!=NULL){
fprintf(f,"%s %s \n",cin,texte1);
fclose(f);
}
}


void
on_btnRetour_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher, *reponse_admin;
GtkWidget *treeview1;

   reponse_admin=lookup_widget(button,"reponse_admin");
   gtk_widget_destroy(reponse_admin);
   fenetre_afficher=create_fenetre_afficher();
   gtk_widget_show(fenetre_afficher);
   treeview1=lookup_widget(fenetre_afficher,"ZOGtreeview1");
afficher_etudiant(treeview1);
}


void
on_btnReponse_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_afficher, *reponse_admin;

   fenetre_afficher=lookup_widget(button,"fenetre_afficher");
   gtk_widget_destroy(fenetre_afficher);
   reponse_admin=create_reponse_admin();
   gtk_widget_show(reponse_admin);

}


void
on_buttonretour_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *reclamation_etudiant, *fenetre_afficher;

   fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
   gtk_widget_destroy(fenetre_afficher);
   reclamation_etudiant=create_reclamation_etudiant();
   gtk_widget_show(reclamation_etudiant);

}


void
on_afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation_etudiant;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
reclamation_etudiant=lookup_widget(objet,"reclamation_etudiant");
gtk_widget_destroy(reclamation_etudiant);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"ZOGtreeview1");
afficher_etudiant(treeview1);
}

////////////////////////radio button///////////////////////
void

on_ZOGradiobutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=2;}

}


void
on_ZOGradiobutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=1;}


}


void
on_ZOGbuttonplus_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
int nbH=0;
int nbR=0;
int result;
char ch1[200];
output=lookup_widget(button,"labelmsg");
result=service_reclame(nbH,nbR);
strcpy(ch1,"Le service le plus réclamé est : ");
if(result==1) {
strcat(ch1,"Hebergement");
}
else if(result==2) {
strcat(ch1,"Restauration");
}
else if(result==3) {
strcat(ch1,"egaux");
}
gtk_label_set_text(GTK_LABEL(output),ch1);
}

