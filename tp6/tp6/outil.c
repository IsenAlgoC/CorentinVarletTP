#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :            VARLET            Prénom :       CORENTIN           */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compléter code ici pour tableau
	int idx;

	if (rep->nb_elts < MAX_ENREG)
	{
		*(rep->tab + rep->nb_elts ) = enr;
		rep->nb_elts += 1;
		rep->est_trie = false;


	}
	else {
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST

	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
		




	}


#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{		
		if ((indice > -1) && (indice < rep->nb_elts))  /* et que l'indice pointe a l'interieur */
		{
			for (int compt = indice; compt < rep->nb_elts - 1; compt++) {
				*(rep->tab + compt) = *(rep->tab + compt + 1);
			}

			rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
			modif = true;
		}
		else {
			modif = false;
		}
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code à compléter ici
	printf_s("%s\t %s\t %s", enr.nom, enr.prenom, enr.tel);

} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code à compléter ici
	// comme fonction affichage_enreg, mais avec présentation alignées des infos
	
	printf_s("|%-30s|%-20s|%-20s",enr.nom, enr.prenom, enr.tel );
	printf_s("\n");
	
} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                */
  /*on compare si enr2 est plus grand que enr1 */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code à compléter ici
	if (strcmp(enr1.nom, enr2.nom)<0) {
		return true;
	}
	if ((strcmp(enr1.nom, enr2.nom )== 0)) {// si 2 personnes ont le meme nom
		if ((strcmp(enr1.prenom, enr2.prenom) < 0)) {
			return true;
		}
		if ((strcmp(enr1.prenom, enr2.prenom) == 0) ){// si deux personne ont le même nom et prenom
			for (int i = 0; i < MAX_TEL; i++) {
				if (enr1.tel < enr2.tel) {
					return true;
				}
			}

		}
	}
	else return(false);

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	 //ajouter code ici pour tableau
	Enregistrement tableau_tampon;
	int compteur = 0;
	int tmp = 0;
	for ( compteur = 0; compteur < (rep->nb_elts - 1); compteur++)
	{
		for ( tmp = (rep->nb_elts - 1); tmp > compteur; tmp--) // on compare les noms un à un en remontant
		{
			if (!est_sup(*(rep->tab + compteur), *(rep->tab + tmp))) {// condition de permutations
				tableau_tampon = *(rep->tab + compteur);
				*(rep->tab + compteur) = *(rep->tab + tmp);
				*(rep->tab + tmp) = tableau_tampon;
			}

		}
	}
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		


#ifdef IMPL_TAB
							// ajouter code ici pour tableau
	
	
	int compt = 0;
	for (compt = 0; compt < MAX_NOM; compt++) {
		tmp_nom[compt] = (nom[compt]);

	}

	_strupr_s(tmp_nom, MAX_NOM);

	ind_fin = rep->nb_elts;
	while( (trouve == false) && ( i != ind_fin)){
		strcpy_s(tmp_nom2, MAX_NOM,rep->tab[i].nom);
		_strupr_s(tmp_nom2, MAX_NOM);

		if (strcmp(tmp_nom, tmp_nom2) == 0) {
			trouve = true;
			
		}
		i++;
	}
	
#else
#ifdef IMPL_LIST
							// ajouter code ici pour Liste
	SingleLinkedListElem* tmp = rep->liste->head;		// on met le pointeur sur la tête de la liste
	for (i = 0; i < rep->liste->size; i++) {
		if (_stricmp(nom, tmp->pers.nom) == 0) {		// on compare en allant notre maillon avec les autres
			trouve = true;
			return i - 1;
			break;										
		}
		tmp = tmp->next;								
	}
	return -1;

	
#endif
#endif

	return((trouve) ? (i-1) : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s)
{
	// compléter code ici
	//isdigit verifie si c'est un caractère non numérique 
	int compteur = 0;
	int var = 0;
	if (s == NULL) {// on vérifie si l'adresse n'est pas vide
		return;
	
	}
	for (compteur = 0; compteur < strlen(s); compteur++) {// on recherche les evnetuels caractère non numeriques pour les supprimer 
		if (isdigit(*(s + compteur)) == 0) {
			for (var = s + compteur; var < strlen(s); var++) {
				s[var] = s[var + 1];// on fait un décalage à gauche pour éliminer la valeur non désirée
				s[strlen(s)] = 0;
			}
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	if( (fopen_s(&fic_rep, nom_fichier, " w +") != 0) || (fic_rep==NULL)){// on vérifie si le fichier est ouvert et s'il existe
		return ERROR;
	}
	int compt = 0;
	for (compt = 0; compt < rep->est_trie; compt++) {// on vient écrire nom, prénom, numéro dans le fichier
		fprintf("%s;", rep->tab[compt].nom);
		fprintf("%s;", rep->tab[compt].prenom);
		fprintf("%s\n", rep->tab[compt].tel);
	}
	fclose(fic_rep);
	



#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */