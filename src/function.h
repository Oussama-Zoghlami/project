typedef struct {
int jour;
int mois;
int annee;
}Date;
typedef struct {
char cin[20];
char nom[20];
char prenom[20];
char type[20];
Date d;
char reclamation[1000];
}Service;

void ajouter_service(Service s);
int chercher(char cin[]);
void modifier_service(char cin[],char nom_modifier[],char prenom_modifier[],char type_modifier[],int jour, int mois,int annee,char reclamation_modifier[]);
void supprimer(char cin[]);
void afficher_etudiant(GtkWidget *liste);
void remplir(Service s,char cin[],char nom[],char prenom[], char type[], char reclamation[] );
int service_reclame(int nb_reclamation_foyer,int nb_reclamation_resto);
