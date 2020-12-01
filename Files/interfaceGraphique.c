#include "interfaceGraphique.h"

#include <stdio.h>

/********************************************************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

#include <sys/types.h>

void  debug_afficher ( char* message );

void* debug_malloc   ( size_t size );
void  debug_free     ( void*  ptr  );

#endif

/********************************************************************************************************/

#ifndef IMAGE_BMP__H
#define IMAGE_BMP__H

#include <stdint.h>

typedef struct
 {
  uint32_t tailleDuFichier;
  uint32_t offsetImage;

  uint32_t tailleEntete;
  uint32_t largeur;
  uint32_t hauteur;
  uint16_t nbPlans;
  uint16_t nbBitsParPixel;
  uint32_t compression;
  uint32_t tailleZoneImage;
  uint32_t resolutionVerticale;
  uint32_t resolutionHorizontale;
  uint32_t nbCouleursPalette;
  uint32_t nbCouleursImportantes;
  uint16_t nbOctetsDeBourrage;
  uint8_t* donnees;
 }
 ImageBMP;

ImageBMP* ImageBMP_lire     ( char*     _nomDuFichier  );
void      ImageBMP_detruire ( ImageBMP* _imageBMP      );
void      ImageBMP_afficher ( ImageBMP* _imageBMP      ,
                              int       _avecLesPixels );

#endif

/********************************************************************************************************/

#ifndef LISTE_CHAINEE__H
#define LISTE_CHAINEE__H

#include <stdint.h>

typedef struct strNoeud Noeud;

struct strNoeud
 {
  void*  information;
  Noeud* suivant;
  Noeud* precedent;
 };

typedef struct
 {
  Noeud*   premier;
  Noeud*   dernier;
  uint16_t nbNoeuds;
 }
 ListeChainee;

ListeChainee* ListeChainee_creer            ( void                               );


ListeChainee* ListeChainee_detruire         ( ListeChainee* _liste               ,
                                              int           _avecLesInformations );

uint16_t      ListeChainee_nbNoeuds         ( ListeChainee* _liste               );

int32_t       ListeChainee_ajouterALaFin    ( ListeChainee* _liste               ,
                                              void*         _information         );

int32_t       ListeChainee_ajouterAuDebut   ( ListeChainee* _liste               ,
                                              void*         _information         );

int32_t       ListeChainee_inserer          ( ListeChainee* _liste               ,
                                              void*         _information         ,
                                              uint16_t      _rang                );

void*         ListeChainee_supprimerALaFin  ( ListeChainee* _liste               );

void*         ListeChainee_supprimerAuDebut ( ListeChainee* _liste               );

void*         ListeChainee_supprimer        ( ListeChainee* _liste               ,
                                              uint16_t      _rang                );

void          ListeChainee_supprimerTout    ( ListeChainee* _liste               );

void*         ListeChainee_lireALaFin       ( ListeChainee* _liste               );

void*         ListeChainee_lireAuDebut      ( ListeChainee* _liste               );

void*         ListeChainee_lire             ( ListeChainee* _liste               ,
                                              uint16_t      _rang                );

int           ListeChainee_estVide          ( ListeChainee* _liste               );

void          ListeChainee_afficher         ( ListeChainee* _liste               );

#endif

/********************************************************************************************************/

#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <stdint.h>



typedef struct
 {
  char* nomDeLEvenement;
  void  (*fct) ( uint64_t , uint64_t , uint64_t );
 }
 GestionnaireDEvenements;

typedef struct
 {
  ListeChainee* listeDesGestionnaires;
 }
 LesGestionnairesDEvenements;

GestionnaireDEvenements*     GestionnaireDEvenements_creer                     ( char*                       _nomDeLEvenement          ,
                                                                                 void (* _fct) ( uint64_t , uint64_t , uint64_t )      );

GestionnaireDEvenements*     GestionnaireDEvenements_detruire                  ( GestionnaireDEvenements*     _gestionnaireDEvenements );


LesGestionnairesDEvenements* LesGestionnairesDEvenements_creer                 ( void                                                  );

LesGestionnairesDEvenements* LesGestionnairesDEvenements_detruire              ( LesGestionnairesDEvenements* _lesGestionnaires        );

uint16_t                     LesGestionnairesDEvenements_NbGestionnaires       ( LesGestionnairesDEvenements* _lesGestionnaires        );

int32_t                      LesGestionnairesDEvenements_ajouterUnGestionnaire ( LesGestionnairesDEvenements* _lesGestionnaires        ,
                                                                                 char*                        _nomDeLEvenement         ,
                                                                                 void (*_fct) ( uint64_t , uint64_t , uint64_t )       );

GestionnaireDEvenements*     LesGestionnairesDEvenements_lireParLeNom          ( LesGestionnairesDEvenements* _lesGestionnaires        ,
                                                                                 char*                        _nomDeLEvenement         );

GestionnaireDEvenements*     LesGestionnairesDEvenements_lireParLeNumero       ( LesGestionnairesDEvenements* _lesGestionnaires        ,
                                                                                 uint16_t                     _numero                  );


GestionnaireDEvenements*     LesGestionnairesDEvenements_supprimerParLeNom     ( LesGestionnairesDEvenements* _lesGestionnaires   ,
                                                                                 char*                     _nomDeLEvenement ) ;

GestionnaireDEvenements*     LesGestionnairesDEvenements_supprimerParLeNumero  ( LesGestionnairesDEvenements* _lesGestionnaires   ,
                                                                                 uint16_t                  _numero          ) ;

#endif

/********************************************************************************************************/

#ifndef SCENE__H
#define SCENE__H

#include <stdint.h>



#define INTERFACE_GRAPHIQUE__SEGMENT__         1
#define INTERFACE_GRAPHIQUE__RECTANGLE__       2
#define INTERFACE_GRAPHIQUE__CERCLE__          3
#define INTERFACE_GRAPHIQUE__ARC_DE_CERCLE__   4
#define INTERFACE_GRAPHIQUE__CADRE_D_IMAGE__   5

typedef struct
 {
  uint8_t type;

  float   fondRouge;
  float   fondVert;
  float   fondBleu;

  float   formeRouge;
  float   formeVert;
  float   formeBleu;

  double  x;
  double  y;
  double  x2;
  double  y2;
 }
 InterfaceGraphique_Segment;

typedef struct
 {
  uint8_t type;

  float   fondRouge;
  float   fondVert;
  float   fondBleu;

  float   formeRouge;
  float   formeVert;
  float   formeBleu;

  double  x;
  double  y;
  double  x2;
  double  y2;
 }
 InterfaceGraphique_Rectangle;

typedef struct
 {
  uint8_t type;

  float   fondRouge;
  float   fondVert;
  float   fondBleu;

  float   formeRouge;
  float   formeVert;
  float   formeBleu;

  double  x;
  double  y;
  double  rayon;
 }
 InterfaceGraphique_Cercle;

typedef struct
 {
  uint8_t type;

  float    fondRouge;
  float    fondVert;
  float    fondBleu;

  float    formeRouge;
  float    formeVert;
  float    formeBleu;

  double   x;
  double   y;
  double   rayon;
  double   angleDepart;
  double   angleOuverture;
 }
 InterfaceGraphique_ArcDeCercle;

typedef struct
 {
  uint8_t  type;

  float    fondRouge;
  float    fondVert;
  float    fondBleu;

  float    formeRouge;
  float    formeVert;
  float    formeBleu;

  double   x;
  double   y;

  float    zoom_x;
  float    zoom_y;

  uint16_t idImage;
 }
 InterfaceGraphique_CadreDImage;

typedef union
 {
  uint8_t                         type;
  InterfaceGraphique_Segment      segment;
  InterfaceGraphique_Rectangle    rectangle;
  InterfaceGraphique_Cercle       cercle;
  InterfaceGraphique_ArcDeCercle  arcDeCercle;
  InterfaceGraphique_CadreDImage  cadreDImage;
 }
 InterfaceGraphique_Forme;

typedef struct
 {
  ListeChainee* listeDesFormesGraphiques;
  ListeChainee* listeDesImages;
 }
 InterfaceGraphique_Scene;


InterfaceGraphique_Scene*       Scene_creer                  ( void                                      );

InterfaceGraphique_Scene*       Scene_detruire               ( InterfaceGraphique_Scene* _scene          );

uint16_t                        Scene_getNbImages            ( InterfaceGraphique_Scene* _scene          );

int32_t                         Scene_chargerUneImage        ( InterfaceGraphique_Scene* _scene          ,
                                                               ImageBMP*                 _image          );

ImageBMP*                       Scene_lireUneImage           ( InterfaceGraphique_Scene* _scene          ,
                                                               uint16_t                  _idImage        );

ImageBMP*                       Scene_dechargerUneImage      ( InterfaceGraphique_Scene* _scene          ,
                                                               uint16_t                  _idImage        );

uint16_t                        Scene_getNbFormes            ( InterfaceGraphique_Scene* _scene          );

InterfaceGraphique_Segment*     Scene_creerUnSegment         ( double                    _x1             ,
                                                               double                    _y1             ,
                                                               double                    _x2             ,
                                                               double                    _y2             ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      );

InterfaceGraphique_Rectangle*   Scene_creerUnRectangle       ( double                    _x1             ,
                                                               double                    _y1             ,
                                                               double                    _x2             ,
                                                               double                    _y2             ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

InterfaceGraphique_Cercle*      Scene_creerUnCercle          ( double                    _xc             ,
                                                               double                    _yc             ,
                                                               double                    _rayon          ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

InterfaceGraphique_ArcDeCercle* Scene_creerUnArcDeCercle     ( double                    _xc             ,
                                                               double                    _yc             ,
                                                               double                    _rayon          ,
                                                               double                    _angleDepart    ,
                                                               double                    _angleOuverture ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

InterfaceGraphique_CadreDImage* Scene_creerUnCadreDImage     ( double                    _x              ,
                                                               double                    _y              ,
                                                               float                     _zoom_x         ,
                                                               float                     _zoom_y         ,
                                                               uint16_t                  _idImage        );

int32_t                         Scene_ajouterUnSegment       ( InterfaceGraphique_Scene* _scene          ,
                                                               double                    _x1             ,
                                                               double                    _y1             ,
                                                               double                    _x2             ,
                                                               double                    _y2             ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      );

int32_t                         Scene_ajouterUnRectangle     ( InterfaceGraphique_Scene* _scene          ,
                                                               double                    _x1             ,
                                                               double                    _y1             ,
                                                               double                    _x2             ,
                                                               double                    _y2             ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

int32_t                         Scene_ajouterUnCercle        ( InterfaceGraphique_Scene* _scene          ,
                                                               double                    _xc             ,
                                                               double                    _yc             ,
                                                               double                    _rayon          ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

int32_t                         Scene_ajouterUnArcDeCercle   ( InterfaceGraphique_Scene* _scene          ,
                                                               double                    _xc             ,
                                                               double                    _yc             ,
                                                               double                    _rayon          ,
                                                               double                    _angleDepart    ,
                                                               double                    _angleOuverture ,
                                                               float                     _formeRouge     ,
                                                               float                     _formeVert      ,
                                                               float                     _formeBleu      ,
                                                               float                     _fondRouge      ,
                                                               float                     _fondVert       ,
                                                               float                     _fondBleu       );

int32_t                         Scene_ajouterUnCadreDImage   ( InterfaceGraphique_Scene* _scene          ,
                                                               double                    _x              ,
                                                               double                    _y              ,
                                                               float                     _zoom_x         ,
                                                               float                     _zoom_y         ,
                                                               uint16_t                  _idImage        );

InterfaceGraphique_Forme*       Scene_lireUneForme           ( InterfaceGraphique_Scene* _scene          ,
                                                               uint16_t                  _numero         );

InterfaceGraphique_Forme*       Scene_supprimerUneForme      ( InterfaceGraphique_Scene* _scene          ,
                                                               uint16_t                  _numero         );

void                            Scene_effacer                ( InterfaceGraphique_Scene* _scene          );

#endif

/********************************************************************************************************/

#ifndef SYSTEME_GRAPHIQUE_X11__H
#define SYSTEME_GRAPHIQUE_X11__H

#include <stdint.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>



typedef struct
 {
  uint16_t                     largeur;
  uint16_t                     hauteur;
  char*                        titre;

  Display*                     affichage;
  Window                       fenetre;
  Atom                         wm_delete_window;
  void*                        contexteGraphique;
  XVisualInfo*                 modeDeVisualisation;
  long                         eventMask;

  LesGestionnairesDEvenements* lesGestionnairesDEvenements;

  int                          fermer;
  long                         date;

  InterfaceGraphique_Scene*    scene;
 }
 Fenetre_X11;


Fenetre_X11* Fenetre_X11_creer                    ( char*        _titre       ,
                                                    uint16_t     _largeur     ,
                                                    uint16_t     _hauteur     );

Fenetre_X11* Fenetre_X11_detruire                 ( Fenetre_X11* _fenetre_X11 );

void         Fenetre_X11_gererEvenements          ( Fenetre_X11* _fenetre_X11 );

void         Fenetre_X11_arreterGestionEvenements ( Fenetre_X11* _fenetre_X11 );

void         Fenetre_X11_rafraichirFenetre        ( Fenetre_X11* _fenetre_X11 );

#endif


/********************************************************************************************************/

#ifndef OPEN_GL__H
#define OPEN_GL__H

#include <GL/gl.h>
#include <GL/glx.h>



typedef struct
 {
  uint8_t      typeDeContexte;   // OPENGL = 1;

  Fenetre_X11* fenetre_X11;

  GLXContext   glx;

  GLdouble     gauche;
  GLdouble     droite;
  GLdouble     bas;
  GLdouble     haut;
  GLdouble     proche;
  GLdouble     eloigne;
 }
 ContexteOpenGL;


ContexteOpenGL* ContexteOpenGL_creer               ( Fenetre_X11*                    _fenetre_X11    );

ContexteOpenGL* ContexteOpenGL_detruire            ( ContexteOpenGL*                 _contexteOpenGL );

int             ContexteOpenGL_activer             ( ContexteOpenGL*                 _contexteOpenGL );

void            ContexteOpenGL_rafraichir          ( ContexteOpenGL*                 _contexteOpenGL );

void            ContexteOpenGL_specifierLimites2D  ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     GLdouble                        _gauche         ,
                                                     GLdouble                        _droite         ,
                                                     GLdouble                        _bas            ,
                                                     GLdouble                        _haut           );

void            ContexteOpenGL_afficherScene       ( ContexteOpenGL*                 _contexteOpenGL );

void            ContexteOpenGL_afficherSegment     ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     InterfaceGraphique_Segment*     _segment        );

void            ContexteOpenGL_afficherRectangle   ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     InterfaceGraphique_Rectangle*   _rectangle      );

void            ContexteOpenGL_afficherCercle      ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     InterfaceGraphique_Cercle*      _cercle         );

void            ContexteOpenGL_afficherArcDeCercle ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     InterfaceGraphique_ArcDeCercle* _arcDeCercle    );

void            ContexteOpenGL_afficherCadreDImage ( ContexteOpenGL*                 _contexteOpenGL ,
                                                     InterfaceGraphique_CadreDImage* _image          );

#endif

/********************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

void debug_afficher ( char* message )
 {
  fprintf ( stderr , "%s" , message );
 }

void* debug_malloc ( size_t size )
 {
  void* ptr = NULL;

  //printf ("On fait un malloc de %lu octets\n", size);

  ptr = malloc ( size );

  //perror ("");
  //printf (" => ptr = %p\n", ptr);

  return ptr;
 }

void debug_free ( void* ptr )
 {
  //printf ("On fait un free à l'adresse %p\n", ptr);

  free ( ptr );

  //perror ("");
 }

/********************************************************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>



GestionnaireDEvenements* GestionnaireDEvenements_creer ( char* _nomDeLEvenement                           ,
                                                         void  (* _fct ) ( uint64_t , uint64_t , uint64_t ) )
 {
  GestionnaireDEvenements* gestionnaire = NULL;

  if ( _nomDeLEvenement && _fct )
   {
    if ( strlen ( _nomDeLEvenement) > 0 )
     {
      gestionnaire = ( GestionnaireDEvenements* ) debug_malloc ( sizeof (GestionnaireDEvenements) );

      if ( gestionnaire )
       {
        gestionnaire->nomDeLEvenement = ( char* ) debug_malloc ( strlen ( _nomDeLEvenement ) + 1 );

        if ( gestionnaire->nomDeLEvenement )
              {
               strcpy ( gestionnaire->nomDeLEvenement , _nomDeLEvenement );
               gestionnaire->fct = _fct;
              }
         else {
               debug_afficher ( " Le rang est incorrect ");

               gestionnaire = GestionnaireDEvenements_detruire ( gestionnaire );
              }
       }
     }
   }

  return gestionnaire;
 }

GestionnaireDEvenements* GestionnaireDEvenements_detruire ( GestionnaireDEvenements* _gestionnaireDEvenements )
 {
  if ( _gestionnaireDEvenements )
   {
    if ( _gestionnaireDEvenements->nomDeLEvenement )
     {
      free ( _gestionnaireDEvenements->nomDeLEvenement );
     }

    debug_free ( _gestionnaireDEvenements );
   }

  return NULL;
 }

LesGestionnairesDEvenements* LesGestionnairesDEvenements_creer ( void )
 {
  LesGestionnairesDEvenements* lesGestionnaires = ( LesGestionnairesDEvenements* ) debug_malloc ( sizeof ( LesGestionnairesDEvenements ) );

  if ( lesGestionnaires )
   {
    lesGestionnaires->listeDesGestionnaires = ListeChainee_creer ();

    if ( lesGestionnaires->listeDesGestionnaires == NULL )
     {
      perror ("Problème de création de la liste des gestionnaires");

      lesGestionnaires = LesGestionnairesDEvenements_detruire ( lesGestionnaires );
     }
   }

  return lesGestionnaires;
 }

LesGestionnairesDEvenements* LesGestionnairesDEvenements_detruire ( LesGestionnairesDEvenements* _lesGestionnaires )
 {
  if ( _lesGestionnaires )
   {
    ListeChainee_detruire ( _lesGestionnaires->listeDesGestionnaires , 1 );

    debug_free ( _lesGestionnaires );
   }

  return NULL;
 }

uint16_t LesGestionnairesDEvenements_NbGestionnaires ( LesGestionnairesDEvenements* _lesGestionnaires )
 {
  uint16_t nbGestionnaires = 0;

  if ( _lesGestionnaires )
   {
    nbGestionnaires = ListeChainee_nbNoeuds ( _lesGestionnaires->listeDesGestionnaires );
   }

  return nbGestionnaires;
 }

int32_t LesGestionnairesDEvenements_ajouterUnGestionnaire ( LesGestionnairesDEvenements* _lesGestionnaires    ,
                                                             char*                       _nomDeLEvenement     ,
                                                             void  (*_fct) ( uint64_t , uint64_t , uint64_t ) )
 {
  int32_t numeroGestionnaire = -1;

  if ( _lesGestionnaires )
   {
    if ( _lesGestionnaires->listeDesGestionnaires )
     {
      GestionnaireDEvenements* gest = LesGestionnairesDEvenements_lireParLeNom ( _lesGestionnaires ,
                                                                                 _nomDeLEvenement  );

      if ( !gest )
            {
             gest = GestionnaireDEvenements_creer ( _nomDeLEvenement , _fct );

             if ( gest )
                   {
                    numeroGestionnaire = ListeChainee_ajouterALaFin ( _lesGestionnaires->listeDesGestionnaires , gest );
                   }
              else {
                    perror ("Problème de création du gestionnaire");
                   }
            }
       else {
             perror ("Le gestionnaire existe déjà");
            }
     }
   }

  return numeroGestionnaire;
 }

GestionnaireDEvenements* LesGestionnairesDEvenements_lireParLeNom ( LesGestionnairesDEvenements* _lesGestionnaires ,
                                                                    char*                        _nomDeLEvenement  )
 {
  GestionnaireDEvenements* gestionnaireRecherche = NULL; // On suppose que ça s'est mal passé

  if ( _lesGestionnaires )
   {
    for ( uint16_t g=0 ; g<_lesGestionnaires->listeDesGestionnaires->nbNoeuds && !gestionnaireRecherche ; g++)
     {
      GestionnaireDEvenements* gestionnaire = ListeChainee_lire ( _lesGestionnaires->listeDesGestionnaires , g );  // PAS DU TOUT OPTIMAL A REVOIR

      if ( gestionnaire )
       {
        if ( strcmp ( gestionnaire->nomDeLEvenement , _nomDeLEvenement ) == 0 )
         {
          gestionnaireRecherche = gestionnaire;
         }
       }
     }
   }

  return gestionnaireRecherche;
 }

GestionnaireDEvenements* LesGestionnairesDEvenements_lireParLeNumero ( LesGestionnairesDEvenements* _lesGestionnaires ,
                                                                       uint16_t                     _numero           )
 {
  GestionnaireDEvenements* gestionnaire = NULL; // On suppose que ça s'est mal passé

  if ( _lesGestionnaires )
   {
    gestionnaire = ListeChainee_lire ( _lesGestionnaires->listeDesGestionnaires , _numero );
   }

  return gestionnaire;
 }

GestionnaireDEvenements* LesGestionnairesDEvenements_supprimerParLeNom    ( LesGestionnairesDEvenements* _lesGestionnaires ,
                                                                            char*                        _nomDeLEvenement  );

GestionnaireDEvenements* LesGestionnairesDEvenements_supprimerParLeNumero ( LesGestionnairesDEvenements* _lesGestionnaires ,
                                                                            uint16_t                     _numero           );

/********************************************************************************************************/



#include <errno.h>
#include <stdio.h>
#include <stdlib.h>



/************************************************************************************************************/
/*                                                                                                          */
/* LE FORMAT BMP (http://projet.eu.org/pedago/sin/ISN/7-format_BMP.pdf)                                     */
/*                                                                                                          */
/* L'entête du fichier est composé de quatre champs :                                                       */
/*                                                                                                          */
/*   1. La signature (sur 2 octets), indiquant qu'il s'agit d'un fichier BMP à l'aide des deux caractères : */
/*                                                                                                          */
/*        - BM indique qu'il s'agit d'un Bitmap Windows.                                                    */
/*        - BA indique qu'il s'agit d'un Bitmap OS/2.                                                       */
/*        - CI indique qu'il s'agit d'une icône couleur OS/2.                                               */
/*        - CP indique qu'il s'agit d'un pointeur de couleur OS/2.                                          */
/*        - IC indique qu'il s'agit d'une icône OS/2.                                                       */
/*        - PT indique qu'il s'agit d'un pointeur OS/2.                                                     */
/*                                                                                                          */
/*   2. La taille totale du fichier en octets (codée sur 4 octets)                                          */
/*   3. Un champ réservé (sur 4 octets)                                                                     */
/*   4. L'offset de l'image (sur 4 octets):                                                                 */
/*      l'adresse relative du début des informations concernant l'image par rapport au début du fichier     */
/*                                                                                                          */
/*                                                                                                          */
/* L'entête de l'image est composé de plusieurs champs :                                                    */
/*                                                                                                          */
/*   1. La signature de l'entête de l'image en octets (codée sur 4 octets).                                 */
/*      Les valeurs hexadécimales suivantes sont possibles suivant le type de format BMP :                  */
/*                                                                                                          */
/*        - 0x28 pour Windows 3.1x, 95, NT, ...                                                             */
/*        - 0x0C pour OS/2 1.x                                                                              */
/*        - 0xF0 pour OS/2 2.x                                                                              */
/*                                                                                                          */
/*   2. La largeur de l'image (sur 4 octets), c'est-à-dire le nombre de pixels horizontalement              */
/*   3. La hauteur de l'image (sur 4 octets), c'est-à-dire le nombre de pixels verticalement                */
/*   4. Le nombre de plans (sur 2 octets). Cette valeur vaut toujours 1                                     */
/*   5. La profondeur de codage de la couleur(sur 2 octets), c'est-à-dire le nombre de bits utilisés pour   */
/*      coder la couleur. Cette valeur peut-être égale à 1, 4, 8, 16, 24 ou 32                              */
/*   6. La méthode de compression (sur 4 octets). Cette valeur vaut 0 lorsque l'image n'est pas compressée, */
/*      ou bien 1, 2 ou 3 suivant le type de compression utilisé :                                          */
/*                                                                                                          */
/*        - 1 pour un codage RLE de 8 bits par pixel                                                        */
/*        - 2 pour un codage RLE de 4 bits par pixel                                                        */
/*        - 3 pour un codage bitfields, signifiant que la couleur est codé par un triple masque représenté  */
/*            par la palette                                                                                */
/*                                                                                                          */
/*   7. La taille totale de l'image en octets (sur 4 octets).                                               */
/*   8. La résolution horizontale (sur 4 octets)                                                            */
/*   9. La résolution verticale (sur 4 octets)                                                              */
/*  10. Le nombre de couleurs de la palette (sur 4 octets)                                                  */
/*  11. Le nombre de couleurs importantes de la palette (sur 4 octets).                                     */
/*      Ce champ peut être égal à 0 lorsque chaque couleur a son importance.                                */
/*                                                                                                          */
/*                                                                                                          */
/* */
/************************************************************************************************************/

ImageBMP* ImageBMP_lire ( char* _nomDuFichier )
 {
  ImageBMP* image   = NULL;
  FILE*     fichier = fopen ( _nomDuFichier , "r");

  if ( fichier == NULL )
        {
         perror ( " Erreur de lecture du fichier ");
        }
   else {
         uint8_t tampon [4];

         fread ( tampon , 2 , 1 , fichier );

         if ( tampon[0] != 'B' || ( tampon[1] != 'M' ) )
               {
                fprintf ( stderr, "Le fichier %s n'est pas un fichier bitmap => Code=%c%c.\n", _nomDuFichier ,
                                                                                               tampon[0]     ,
                                                                                               tampon[1]     );
               }
          else {
                printf ( "Lecture du fichier %s\n", _nomDuFichier );

                image = (ImageBMP*) debug_malloc ( sizeof (ImageBMP) );

                if ( image == NULL )
                      {
                       perror ( " Erreur de création de la structure image ");
                      }
                 else {
                       fread ( tampon , 4 , 1 , fichier );
                       image->tailleDuFichier = *( (uint32_t*) tampon );

                       fseek (fichier, 4, SEEK_CUR);

                       fread ( tampon , 4 , 1 , fichier );
                       image->offsetImage = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->tailleEntete = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->largeur = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->hauteur = *( (uint32_t*) tampon );

                       fread ( tampon , 2 , 1 , fichier );
                       image->nbPlans = *( (uint16_t*) tampon );

                       fread ( tampon , 2 , 1 , fichier );
                       image->nbBitsParPixel = *( (uint16_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->compression = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->tailleZoneImage = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->resolutionVerticale = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->resolutionHorizontale = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->nbCouleursPalette = *( (uint32_t*) tampon );

                       fread ( tampon , 4 , 1 , fichier );
                       image->nbCouleursImportantes = *( (uint32_t*) tampon );


                       if ( image->nbBitsParPixel != 24 )
                             {
                              fprintf (stderr, "%s n'est pas un type d'image BMP qui peut être traité : \n", _nomDuFichier);

                              ImageBMP_afficher ( image , 0 );

                              debug_free (image);
                              image = NULL;
                             }
                        else {
                              image->nbOctetsDeBourrage = ( 4 - ( ( image->largeur * 3 ) % 4 ) ) % 4;

                              //ImageBMP_afficher ( image , 0 );

                              image->tailleZoneImage = image->largeur * image->hauteur * 3;

                              image->donnees            = (uint8_t*) debug_malloc ( image->tailleZoneImage );

                              if ( image->donnees == NULL )
                                    {
                                     perror ("On n'a pas pu réserver de la place ne mémoire pour stocker l'image");

                                     debug_free (image);
                                     image = NULL;
                                    }
                               else {
                                     fseek (fichier, image->offsetImage, SEEK_SET);


                                     for ( uint32_t ligne = 0 ; ligne < image->hauteur ; ligne++ )
                                      {
                                       for ( uint32_t colonne = 0 ; colonne < image->largeur ; colonne++ )
                                        {
                                         fread ( image->donnees + ( ligne * image->largeur + colonne ) * 3 + 2  , 1 , 1 , fichier );
                                         fread ( image->donnees + ( ligne * image->largeur + colonne ) * 3 + 1  , 1 , 1 , fichier );
                                         fread ( image->donnees + ( ligne * image->largeur + colonne ) * 3      , 1 , 1 , fichier );
/*
                                         printf ("l=%u c=%u => r=%u, v=%u et b=%u\n", ligne,
                                                                                      colonne,
                                                                                      image->donnees [ ( ligne * image->largeur + colonne ) * 3 ],
                                                                                      image->donnees [ ( ligne * image->largeur + colonne ) * 3 + 1 ],
                                                                                      image->donnees [ ( ligne * image->largeur + colonne ) * 3 + 2 ] );
*/
                                        }

                                       fseek ( fichier , image->nbOctetsDeBourrage , SEEK_CUR );
                                      }
                                    }

                             }
                      }
               }
         }

  return image;
 }

void ImageBMP_detruire ( ImageBMP* _imageBMP )
 {
  if ( _imageBMP )
   {
    if ( _imageBMP->donnees )
     {
      debug_free ( _imageBMP->donnees );
     }

    debug_free ( _imageBMP );
   }
 }

void ImageBMP_afficher ( ImageBMP* _imageBMP , int _avecLesPixels )
 {
  if ( _imageBMP )
   {
    printf ( " - taille totale du fichier           : %u\n", _imageBMP->tailleDuFichier       );
    printf ( " - offset                             : %u\n", _imageBMP->offsetImage           );
    printf ( " - taille entête de l'image           : %u\n", _imageBMP->tailleEntete          );
    printf ( " - largeur                            : %u\n", _imageBMP->largeur               );
    printf ( " - hauteur                            : %u\n", _imageBMP->hauteur               );
    printf ( " - nbPlans                            : %u\n", _imageBMP->nbPlans               );
    printf ( " - nbBitsParPixel                     : %u\n", _imageBMP->nbBitsParPixel        );
    printf ( " - compression                        : %u\n", _imageBMP->compression           );
    printf ( " - tailleZoneImage                    : %u\n", _imageBMP->tailleZoneImage       );
    printf ( " - résolution verticale               : %u\n", _imageBMP->resolutionVerticale   );
    printf ( " - résolution horizontale             : %u\n", _imageBMP->resolutionHorizontale );
    printf ( " - nombre de couleurs dans la palette : %u\n", _imageBMP->nbCouleursPalette     );
    printf ( " - nombre de couleurs importantes     : %u\n", _imageBMP->nbCouleursImportantes );
    printf ( " - nombre d'octets de bourrage        : %u\n", _imageBMP->nbOctetsDeBourrage    );
    printf ( " - donnees                            : %p\n", _imageBMP->donnees               );
    printf ( "\n" );

    if ( _avecLesPixels )
     {
      if ( _imageBMP->donnees )
       {
        for ( uint32_t ligne = 0 ; ligne < _imageBMP->hauteur ; ligne++ )
         {
          for ( uint32_t colonne = 0 ; colonne < _imageBMP->largeur ; colonne++ )
           {
            printf ( "Pixel à la ligne %3u et la colonne %3u => rouge = %02X , vert = %02X , bleu = %02X\n" ,
                     ligne                                                                       ,
                     colonne                                                                     ,
                     * ( _imageBMP->donnees + ( ligne * _imageBMP->largeur + colonne ) * 3     ) ,
                     * ( _imageBMP->donnees + ( ligne * _imageBMP->largeur + colonne ) * 3 + 1 ) ,
                     * ( _imageBMP->donnees + ( ligne * _imageBMP->largeur + colonne ) * 3 + 2 ) );
           }
         }
       }
     }
   }
 }

/********************************************************************************************************/



#include <stdlib.h>
#include <stdio.h>



ListeChainee* ListeChainee_creer ( void )
 {
  ListeChainee* liste = (ListeChainee*) debug_malloc ( sizeof (ListeChainee) );

  if ( liste )
        {
         liste->premier  = NULL;
         liste->dernier  = NULL;
         liste->nbNoeuds = 0;
        }
   else {
         debug_afficher ( " Erreur de création de la structure ListeChainee ");
        }

  return liste;
 }

ListeChainee*  ListeChainee_detruire ( ListeChainee* _liste               ,
                                       int           _avecLesInformations )
 {
  if ( _liste )
   {
    Noeud* noeud   = _liste->premier;
    Noeud* suivant = NULL;

    while ( noeud )
     {
      suivant = noeud->suivant;

      if ( _avecLesInformations )
       {
        if ( noeud->information )
         {
          debug_free ( noeud->information );
         }
       }

      debug_free ( noeud );

      noeud = suivant;
     }

    debug_free ( _liste );
   }

  return NULL;
 }

uint16_t ListeChainee_nbNoeuds ( ListeChainee* _liste )
 {
  uint16_t nbNoeuds = 0;

  if ( _liste )
   {
    nbNoeuds = _liste->nbNoeuds;
   }

  return nbNoeuds;
 }

int32_t ListeChainee_ajouterALaFin ( ListeChainee* _liste       ,
                                     void*         _information )
 {
  int32_t numeroDuNoeud = -1; // On suppose qu'on n'a pas pu faire l'insertion

  if ( _liste )
   {
    Noeud* nouveauNoeud = ( Noeud* ) debug_malloc ( sizeof (Noeud) );

    if ( nouveauNoeud )
     {
      nouveauNoeud->information = _information;
      nouveauNoeud->suivant     = NULL;
      nouveauNoeud->precedent   = NULL;

      if ( _liste->nbNoeuds == 0 )
            {
             _liste->premier  = nouveauNoeud;
             _liste->dernier  = nouveauNoeud;
             _liste->nbNoeuds = 1;
            }
       else {
             _liste->dernier->suivant  = nouveauNoeud;
             nouveauNoeud->precedent   = _liste->dernier;

             _liste->dernier           = nouveauNoeud;
             _liste->nbNoeuds         += 1;
            }

      numeroDuNoeud = _liste->nbNoeuds - 1;
     }
     else {
           perror ("");

          }
   }

  return numeroDuNoeud;
 }

int32_t ListeChainee_ajouterAuDebut ( ListeChainee* _liste       ,
                                      void*         _information )
 {
  int32_t numeroDuNoeud = -1; // On suppose qu'on n'a pas pu faire l'insertion

  if ( _liste )
   {
    Noeud* nouveauNoeud = ( Noeud* ) debug_malloc ( sizeof (Noeud) );

    if ( nouveauNoeud )
     {
      nouveauNoeud->information = _information;
      nouveauNoeud->suivant     = NULL;
      nouveauNoeud->precedent   = NULL;

      if ( _liste->nbNoeuds == 0 )
            {
             _liste->premier  = nouveauNoeud;
             _liste->dernier  = nouveauNoeud;
             _liste->nbNoeuds = 1;
            }
       else {
             _liste->premier->precedent  = nouveauNoeud;
             nouveauNoeud->suivant       = _liste->premier;

             _liste->premier             = nouveauNoeud;
             _liste->nbNoeuds           += 1;
            }

      numeroDuNoeud = _liste->nbNoeuds - 1;
     }
   }

  return numeroDuNoeud;
 }

int32_t ListeChainee_inserer ( ListeChainee* _liste       ,
                               void*         _information ,
                               uint16_t      _rang        )
 {
  int32_t numeroDuNoeud = -1; // On suppose qu'on n'a pas pu faire l'insertion

  if ( _liste )
   {
    if ( _rang > _liste->nbNoeuds )
          {
           debug_afficher ( " Le rang est incorrect ");
          }
     else {
           Noeud* nouveauNoeud = ( Noeud* ) debug_malloc ( sizeof (Noeud) );

           if ( nouveauNoeud )
            {
             nouveauNoeud->information = _information;
             nouveauNoeud->suivant     = NULL;
             nouveauNoeud->precedent   = NULL;

             if ( _liste->nbNoeuds == 0 )
                   {
                    _liste->premier  = nouveauNoeud;
                    _liste->dernier  = nouveauNoeud;
                    _liste->nbNoeuds = 1;
                   }
              else {
                    // On choisit si on part du début ou de la fin

                    if ( _rang <= _liste->nbNoeuds / 2 )
                          {
                           Noeud* noeud = _liste->premier;

                           for ( uint16_t i=0 ; i<_rang-1 ; i++ )
                            {
                             noeud = noeud->suivant;
                            }

                           Noeud* suivant = noeud->suivant;

                           noeud->suivant     = nouveauNoeud;

                           if ( suivant )
                            suivant->precedent = nouveauNoeud;

                           nouveauNoeud->suivant   = suivant;
                           nouveauNoeud->precedent = noeud;

                           _liste->nbNoeuds += 1;
                          }
                     else {
                           Noeud* noeud = _liste->dernier;

                           for ( uint16_t i=_liste->nbNoeuds-1 ; i>_rang ; i-- )
                            {
                             noeud = noeud->precedent;
                            }

                           Noeud* precedent = noeud->precedent;

                           noeud->precedent   = nouveauNoeud;

                           if ( precedent )
                            precedent->suivant = nouveauNoeud;

                           nouveauNoeud->suivant   = noeud;
                           nouveauNoeud->precedent = precedent;

                           _liste->nbNoeuds += 1;
                          }
                   }

             numeroDuNoeud = _rang;
            }
          }
    }

  return numeroDuNoeud;
 }

void* ListeChainee_supprimerALaFin  ( ListeChainee* _liste )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _liste->nbNoeuds > 0 )
     {
      informationRecuperee = _liste->dernier->information;

      Noeud* noeud = _liste->dernier->precedent;

      noeud->suivant = NULL;

      debug_free ( _liste->dernier );

      _liste->dernier = noeud;

      _liste->nbNoeuds -= 1;
     }
   }

  return informationRecuperee;
 }

void* ListeChainee_supprimerAuDebut ( ListeChainee* _liste )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _liste->nbNoeuds > 0 )
     {
      informationRecuperee = _liste->premier->information;

      Noeud* noeud = _liste->premier->suivant;

      noeud->precedent = NULL;

      debug_free ( _liste->premier );

      _liste->premier = noeud;

      _liste->nbNoeuds -= 1;
     }
   }

  return informationRecuperee;
 }

void* ListeChainee_supprimer ( ListeChainee* _liste ,
                               uint16_t      _rang  )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _rang > _liste->nbNoeuds )
          {
           debug_afficher ( " Le rang est incorrect ");
          }
     else {
           Noeud* noeud = NULL;

           if ( _rang < _liste->nbNoeuds / 2 )
                 {
                  noeud = _liste->premier;

                  for ( uint16_t i=0 ; i<_rang ; i++ )
                   {
                    noeud = noeud->suivant;
                   }
                 }
            else {
                  noeud = _liste->dernier;

                  for ( uint16_t i=_liste->nbNoeuds-1 ; i>_rang ; i-- )
                   {
                    noeud = noeud->precedent;
                   }
                 }

           if ( noeud )
            {
             Noeud* suivant   = noeud->suivant;
             Noeud* precedent = noeud->precedent;

             precedent->suivant = suivant;
             suivant->precedent = precedent;

             informationRecuperee = noeud->information;

             debug_free ( noeud );

             _liste->nbNoeuds -= 1;
            }
          }
    }

  return informationRecuperee;
 }

void ListeChainee_supprimerTout ( ListeChainee* _liste )
 {
  if ( _liste )
   {
    Noeud* noeud   = _liste->premier;
    Noeud* suivant = NULL;

    while ( noeud )
     {
      suivant = noeud->suivant;

      if ( noeud->information )
       {
        debug_free ( noeud->information );
       }

      debug_free ( noeud );

      noeud = suivant;
     }

    _liste->dernier  = NULL;
    _liste->premier  = NULL;
    _liste->nbNoeuds = 0;
   }
 }

void* ListeChainee_lireALaFin  ( ListeChainee* _liste )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _liste->nbNoeuds > 0 )
     {
      informationRecuperee = _liste->dernier->information;
     }
   }

  return informationRecuperee;
 }

void* ListeChainee_lireAuDebut ( ListeChainee* _liste )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _liste->nbNoeuds > 0 )
     {
      informationRecuperee = _liste->premier->information;
     }
   }

  return informationRecuperee;
 }

void* ListeChainee_lire ( ListeChainee* _liste ,
                          uint16_t      _rang  )
 {
  void* informationRecuperee = NULL;

  if ( _liste )
   {
    if ( _rang > _liste->nbNoeuds )
          {
           debug_afficher ( " Le rang est incorrect ");
          }
     else {
           Noeud* noeud = NULL;

           if ( _rang < _liste->nbNoeuds / 2 )
                 {
                  noeud = _liste->premier;

                  for ( int i=0 ; i<_rang ; i++ )
                   {
                    noeud = noeud->suivant;
                   }
                 }
            else {
                  noeud = _liste->dernier;

                  for ( int i=_liste->nbNoeuds-1 ; i>_rang ; i-- )
                   {
                    noeud = noeud->precedent;
                   }
                 }

           if ( noeud )
            {
             informationRecuperee = noeud->information;
            }
          }
    }

  return informationRecuperee;
 }

int ListeChainee_estVide ( ListeChainee* _liste )
 {
  int estVide = 1;

  if ( _liste )
   {
    estVide = _liste->nbNoeuds == 0;
   }

  return estVide;
 }

void ListeChainee_afficher ( ListeChainee* _liste )
 {
  if ( _liste )
   {
    if ( _liste->nbNoeuds == 0 )
          {
           printf ("La liste chainée est vide\n");
          }
     else {
           printf ("La liste chainée contient %u élément%s :\n", _liste->nbNoeuds , ( _liste->nbNoeuds > 1 ? "s" : "") );

           Noeud* noeud = _liste->premier;

           for ( uint16_t i=0 ; i<_liste->nbNoeuds ; i++ )
            {
             printf ( " - Noeud %3u : Adr=%14p , Suiv=%14p , Prec=%14p , Info=%14p\n",          i                   ,
                                                                                       (void*) (noeud)              ,
                                                                                       (void*) (noeud->suivant)     ,
                                                                                       (void*) (noeud->precedent)   ,
                                                                                       (void*) (noeud->information) );
             noeud = noeud->suivant;
            }
          }
   }
 }

/********************************************************************************************************/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>



ContexteOpenGL* ContexteOpenGL_creer ( Fenetre_X11* _fenetre_X11 )
 {
  ContexteOpenGL* contexte = NULL;

  /*** Verification de la disponibilite des extensions GLX ***/

  int errorBase;
  int eventBase;

  if ( !glXQueryExtension ( _fenetre_X11->affichage ,
                            &errorBase              ,
                            &eventBase              ) )
        {
         perror ("Les extensions GLX ne sont pas disponibles");
        }
   else {
         /*** Specification du mode de visualisation ***/

         int caracteristiques []  = {
                                      GLX_RGBA         ,
                                      GLX_DEPTH_SIZE   ,
                                      16               ,
                                      GLX_DOUBLEBUFFER ,
                                      None
                                    };

         _fenetre_X11->modeDeVisualisation = glXChooseVisual (                 _fenetre_X11->affichage   ,
                                                               DefaultScreen ( _fenetre_X11->affichage ) ,
                                                               caracteristiques                          );

         if ( _fenetre_X11->modeDeVisualisation == NULL )
               {
                perror ("Mode de visualisation non disponible");
               }
          else {
                /*** Création de la structure ***/

                contexte = ( ContexteOpenGL* ) debug_malloc ( sizeof (ContexteOpenGL) );

                if ( contexte )
                 {
                  /*** Creation du lien GLX ***/

                  contexte->fenetre_X11 = _fenetre_X11;

                  contexte->glx         = glXCreateContext (
                                                             _fenetre_X11->affichage           ,
                                                             _fenetre_X11->modeDeVisualisation ,
                                                             NULL                              ,
                                                             GL_TRUE
                                                           );

                  // Projection par défaut équivalent à faire glOrtho(-1, 1, -1, 1, 1, -1)

                  contexte->typeDeContexte = 1;

                  contexte->gauche         = -1;
                  contexte->droite         =  1;
                  contexte->bas            = -1;
                  contexte->haut           =  1;
                  contexte->proche         =  1;
                  contexte->eloigne        = -1;

                  if ( contexte->glx == NULL )
                   {
                    perror ("Echec dans la creation du contexte graphique OpenGL");

                    debug_free (contexte);

                    contexte = NULL;
                   }
                 }
               }
         }

  return contexte;
 }

ContexteOpenGL* ContexteOpenGL_detruire ( ContexteOpenGL* _contexteOpenGL )
 {
  if ( _contexteOpenGL )
   {
    debug_free ( _contexteOpenGL );
   }

  return NULL;
 }

int ContexteOpenGL_activer ( ContexteOpenGL* _contexteOpenGL )
 {
  int retour = 0;

  if ( _contexteOpenGL )
   {
    if ( !glXMakeCurrent ( _contexteOpenGL->fenetre_X11->affichage ,
                           _contexteOpenGL->fenetre_X11->fenetre   ,
                           _contexteOpenGL->glx                    ) )
          {
           perror ("Echec pour rendre le contexte graphique OpenGL courant");
          }
     else {
           retour = 1;
          }
   }

  return retour;
 }

void ContexteOpenGL_rafraichir  ( ContexteOpenGL* _contexteOpenGL )
 {
  if ( _contexteOpenGL )
   {
    glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    glClear (GL_COLOR_BUFFER_BIT);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glOrtho ( _contexteOpenGL->gauche  ,
              _contexteOpenGL->droite  ,
              _contexteOpenGL->bas     ,
              _contexteOpenGL->haut    ,
              _contexteOpenGL->proche  ,
              _contexteOpenGL->eloigne );

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();

    ContexteOpenGL_afficherScene ( _contexteOpenGL );

    GLenum e = glGetError();

    if ( e!=GL_NO_ERROR )
     {
      perror ("Erreur d'OpenGL");
     }

    glFlush();

    glXSwapBuffers ( _contexteOpenGL->fenetre_X11->affichage ,
                     _contexteOpenGL->fenetre_X11->fenetre   );
   }
 }

void ContexteOpenGL_specifierLimites2D ( ContexteOpenGL* _contexteOpenGL ,
                                         GLdouble        _gauche         ,
                                         GLdouble        _droite         ,
                                         GLdouble        _bas            ,
                                         GLdouble        _haut           )
 {
  if ( _contexteOpenGL )
   {
    _contexteOpenGL->gauche  = _gauche;
    _contexteOpenGL->droite  = _droite;
    _contexteOpenGL->bas     = _bas;
    _contexteOpenGL->haut    = _haut;
    _contexteOpenGL->proche  =  1;
    _contexteOpenGL->eloigne = -1;
   }
 }

void ContexteOpenGL_afficherScene ( ContexteOpenGL* _contexteOpenGL )
 {
  if ( _contexteOpenGL )
   {
    if ( _contexteOpenGL->fenetre_X11 )
     {
      if ( _contexteOpenGL->fenetre_X11->scene )
       {
        uint16_t nbFormes = Scene_getNbFormes ( _contexteOpenGL->fenetre_X11->scene );

        for ( uint16_t f = 0 ; f < nbFormes ; f++ )
         {
          InterfaceGraphique_Forme* forme = Scene_lireUneForme ( _contexteOpenGL->fenetre_X11->scene , f );

          if ( forme )
           {
            switch ( forme->type )
             {
              case INTERFACE_GRAPHIQUE__SEGMENT__       : ContexteOpenGL_afficherSegment     ( _contexteOpenGL , (InterfaceGraphique_Segment*)     forme ); break;
              case INTERFACE_GRAPHIQUE__RECTANGLE__     : ContexteOpenGL_afficherRectangle   ( _contexteOpenGL , (InterfaceGraphique_Rectangle*)   forme ); break;
              case INTERFACE_GRAPHIQUE__CERCLE__        : ContexteOpenGL_afficherCercle      ( _contexteOpenGL , (InterfaceGraphique_Cercle*)      forme ); break;
              case INTERFACE_GRAPHIQUE__ARC_DE_CERCLE__ : ContexteOpenGL_afficherArcDeCercle ( _contexteOpenGL , (InterfaceGraphique_ArcDeCercle*) forme ); break;
              case INTERFACE_GRAPHIQUE__CADRE_D_IMAGE__ : ContexteOpenGL_afficherCadreDImage ( _contexteOpenGL , (InterfaceGraphique_CadreDImage*) forme ); break;
             }
           }
         }
       }
     }
   }
 }

void ContexteOpenGL_afficherSegment ( ContexteOpenGL*             _contexteOpenGL ,
                                      InterfaceGraphique_Segment* _segment        )
 {
  if ( _contexteOpenGL && _segment )
   {
    glColor3f ( _segment->formeRouge ,
                _segment->formeVert  ,
                _segment->formeBleu  );

    glBegin (GL_LINES);
     glVertex2d ( _segment->x  , _segment->y  );
     glVertex2d ( _segment->x2 , _segment->y2 );
    glEnd();
   }
 }

void ContexteOpenGL_afficherRectangle ( ContexteOpenGL*               _contexteOpenGL ,
                                        InterfaceGraphique_Rectangle* _rectangle      )
 {
  if ( _contexteOpenGL && _rectangle )
   {
    if ( ( _rectangle->fondRouge >= 0 ) &&
         ( _rectangle->fondVert  >= 0 ) &&
         ( _rectangle->fondBleu  >= 0 ) )
     {
      glColor3f ( _rectangle->fondRouge ,
                  _rectangle->fondVert  ,
                  _rectangle->fondBleu  );

      glBegin (GL_QUADS);
       glVertex2d ( _rectangle->x  , _rectangle->y  );
       glVertex2d ( _rectangle->x2 , _rectangle->y  );
       glVertex2d ( _rectangle->x2 , _rectangle->y2 );
       glVertex2d ( _rectangle->x  , _rectangle->y2 );
      glEnd();
     }

    glColor3f ( _rectangle->formeRouge ,
                _rectangle->formeVert  ,
                _rectangle->formeBleu  );

    glBegin (GL_LINE_LOOP);
     glVertex2d ( _rectangle->x  , _rectangle->y  );
     glVertex2d ( _rectangle->x2 , _rectangle->y  );
     glVertex2d ( _rectangle->x2 , _rectangle->y2 );
     glVertex2d ( _rectangle->x  , _rectangle->y2 );
    glEnd();
   }
 }

void ContexteOpenGL_afficherCercle ( ContexteOpenGL*            _contexteOpenGL ,
                                     InterfaceGraphique_Cercle* _cercle         )
 {
  if ( _contexteOpenGL && _cercle )
   {
    double angle;

    if ( ( _cercle->fondRouge >= 0 ) &&
         ( _cercle->fondVert  >= 0 ) &&
         ( _cercle->fondBleu  >= 0 ) )
     {
      glColor3f ( _cercle->fondRouge ,
                  _cercle->fondVert  ,
                  _cercle->fondBleu  );

      glVertex2d ( _cercle->x , _cercle->y );

      glBegin (GL_TRIANGLE_FAN);
       for (angle=0; angle <= M_PI * 2; angle += M_PI/45.0)
        glVertex2d ( _cercle->x + _cercle->rayon * cos (angle) ,
                     _cercle->y + _cercle->rayon * sin (angle) );
      glEnd();
     }

    glColor3f ( _cercle->formeRouge ,
                _cercle->formeVert  ,
                _cercle->formeBleu  );

    glBegin (GL_LINE_LOOP);
     for (angle=0; angle < M_PI * 2; angle += M_PI/45.0)
      glVertex2d ( _cercle->x + _cercle->rayon * cos (angle) ,
                   _cercle->y + _cercle->rayon * sin (angle) );
    glEnd();
   }
 }

void ContexteOpenGL_afficherArcDeCercle ( ContexteOpenGL*                 _contexteOpenGL ,
                                          InterfaceGraphique_ArcDeCercle* _arcDeCercle    )
 {
  if ( _contexteOpenGL && _arcDeCercle )
   {
    double angle;

    double angleD = _arcDeCercle->angleDepart * M_PI / 180.0;
    double angleF = _arcDeCercle->angleOuverture * M_PI / 180.0 + angleD;

    if ( ( _arcDeCercle->fondRouge >= 0 ) &&
         ( _arcDeCercle->fondVert  >= 0 ) &&
         ( _arcDeCercle->fondBleu  >= 0 ) )
     {
      glColor3f ( _arcDeCercle->fondRouge ,
                  _arcDeCercle->fondVert  ,
                  _arcDeCercle->fondBleu  );

      glBegin (GL_TRIANGLE_FAN);

        glVertex2d ( _arcDeCercle->x , _arcDeCercle->y );

        for ( angle  = angleD ;
              angle <= angleF ;
              angle += M_PI/36.0                                  )
         {
          glVertex2d ( _arcDeCercle->x + _arcDeCercle->rayon * cos (angle) ,
                       _arcDeCercle->y + _arcDeCercle->rayon * sin (angle) );
         }

      glEnd();
     }

    glColor3f ( _arcDeCercle->formeRouge ,
                _arcDeCercle->formeVert  ,
                _arcDeCercle->formeBleu  );

    glBegin (GL_LINE_LOOP);

      glVertex2d ( _arcDeCercle->x , _arcDeCercle->y );

      for ( angle  = angleD ;
            angle <= angleF ;
            angle += M_PI/36.0                                  )
       {
        glVertex2d ( _arcDeCercle->x + _arcDeCercle->rayon * cos (angle) ,
                     _arcDeCercle->y + _arcDeCercle->rayon * sin (angle) );
       }

    glEnd();
   }
 }

void ContexteOpenGL_afficherCadreDImage ( ContexteOpenGL*                 _contexteOpenGL ,
                                          InterfaceGraphique_CadreDImage* _image          )
 {
  if ( _contexteOpenGL && _image )
   {
    glPixelStorei ( GL_UNPACK_ALIGNMENT , 1 );
    glRasterPos2d ( _image->x      , _image->y );
    glPixelZoom   ( _image->zoom_x , _image->zoom_y ) ;

    ImageBMP* imageBMP = Scene_lireUneImage ( _contexteOpenGL->fenetre_X11->scene , _image->idImage );

    glDrawPixels  ( imageBMP->largeur ,
                    imageBMP->hauteur ,
                    GL_RGB            ,   // Format
                    GL_UNSIGNED_BYTE  ,   // Type
                    imageBMP->donnees );
   }
 }


/********************************************************************************************************/


#include <stdlib.h>
#include <stdio.h>



InterfaceGraphique_Scene* Scene_creer ( void )
 {
  InterfaceGraphique_Scene* scene = (InterfaceGraphique_Scene*) debug_malloc ( sizeof (InterfaceGraphique_Scene) );

  if ( scene )
   {
    scene->listeDesFormesGraphiques = ListeChainee_creer ();
    scene->listeDesImages           = ListeChainee_creer ();

    if ( scene->listeDesFormesGraphiques == NULL ||
         scene->listeDesImages           == NULL )
     {
      scene = Scene_detruire ( scene );
     }
   }

  return scene;
 }

InterfaceGraphique_Scene* Scene_detruire ( InterfaceGraphique_Scene* _scene )
 {
  if ( _scene )
   {
    ListeChainee_detruire ( _scene->listeDesFormesGraphiques , 1 );
    ListeChainee_detruire ( _scene->listeDesImages           , 1 );

    free ( _scene );
   }

  return NULL;
 }

uint16_t Scene_getNbImages ( InterfaceGraphique_Scene* _scene )
{
 uint16_t nbImages = 0;

 if ( _scene )
  {
   nbImages = ListeChainee_nbNoeuds ( _scene->listeDesImages );
  }

 return nbImages;
}

int32_t Scene_chargerUneImage ( InterfaceGraphique_Scene* _scene ,
                                ImageBMP*                 _image )
 {
  int32_t numeroImage = -1; // On suppose que ça s'est mal passé

  if ( _scene && _image )
   {
    numeroImage = ListeChainee_ajouterALaFin ( _scene->listeDesImages , _image );
   }

  return numeroImage;
 }

ImageBMP* Scene_lireUneImage ( InterfaceGraphique_Scene* _scene   ,
                               uint16_t                  _idImage )
 {
  ImageBMP* image = NULL;

  if ( _scene )
   {
    image = ListeChainee_lire ( _scene->listeDesImages , _idImage );
   }

  return image;
 }

ImageBMP* Scene_dechargerUneImage ( InterfaceGraphique_Scene* _scene   ,
                                    uint16_t                  _idImage )
 {
  ImageBMP* image = NULL;

  if ( _scene )
   {
    image = ListeChainee_supprimer ( _scene->listeDesImages , _idImage );
   }

  return image;
 }

uint16_t Scene_getNbFormes ( InterfaceGraphique_Scene* _scene )
 {
  uint16_t nbFormes = 0;

  if ( _scene )
   {
    nbFormes = ListeChainee_nbNoeuds ( _scene->listeDesFormesGraphiques );
   }

  return nbFormes;
 }

InterfaceGraphique_Segment* Scene_creerUnSegment ( double _x1         ,
                                                   double _y1         ,
                                                   double _x2         ,
                                                   double _y2         ,
                                                   float  _formeRouge ,
                                                   float  _formeVert  ,
                                                   float  _formeBleu  )
 {
  InterfaceGraphique_Segment* segment = ( InterfaceGraphique_Segment* ) debug_malloc ( sizeof ( InterfaceGraphique_Segment ) );

  if ( segment )
        {
         segment->type       = INTERFACE_GRAPHIQUE__SEGMENT__;

         segment->x          = _x1;
         segment->y          = _y1;

         segment->x2         = _x2;
         segment->y2         = _y2;

         segment->formeRouge = _formeRouge;
         segment->formeVert  = _formeVert;
         segment->formeBleu  = _formeBleu;

         segment->fondRouge  = -1;
         segment->fondVert   = -1;
         segment->fondBleu   = -1;
        }
   else {
         debug_afficher ( " Erreur de création de la structure InterfaceGraphique_Segment ");
        }

  return segment;
 }

InterfaceGraphique_Rectangle* Scene_creerUnRectangle ( double _x1         ,
                                                       double _y1         ,
                                                       double _x2         ,
                                                       double _y2         ,
                                                       float  _formeRouge ,
                                                       float  _formeVert  ,
                                                       float  _formeBleu  ,
                                                       float  _fondRouge  ,
                                                       float  _fondVert   ,
                                                       float  _fondBleu   )
 {
  InterfaceGraphique_Rectangle* rectangle = ( InterfaceGraphique_Rectangle* ) debug_malloc ( sizeof ( InterfaceGraphique_Rectangle ) );

  if ( rectangle )
        {
         rectangle->type       = INTERFACE_GRAPHIQUE__RECTANGLE__;

         rectangle->x          = _x1;
         rectangle->y          = _y1;

         rectangle->x2         = _x2;
         rectangle->y2         = _y2;

         rectangle->formeRouge = _formeRouge;
         rectangle->formeVert  = _formeVert;
         rectangle->formeBleu  = _formeBleu;

         rectangle->fondRouge  = _fondRouge;
         rectangle->fondVert   = _fondVert;
         rectangle->fondBleu   = _fondBleu;
        }
   else {
         debug_afficher ( " Erreur de création de la structure InterfaceGraphique_Rectangle ");
        }

  return rectangle;
 }

InterfaceGraphique_Cercle* Scene_creerUnCercle ( double _xc         ,
                                                 double _yc         ,
                                                 double _rayon      ,
                                                 float  _formeRouge ,
                                                 float  _formeVert  ,
                                                 float  _formeBleu  ,
                                                 float  _fondRouge  ,
                                                 float  _fondVert   ,
                                                 float  _fondBleu   )
 {
  InterfaceGraphique_Cercle* cercle = ( InterfaceGraphique_Cercle* ) debug_malloc ( sizeof ( InterfaceGraphique_Cercle ) );

  if ( cercle )
       {
        cercle->type       = INTERFACE_GRAPHIQUE__CERCLE__;

        cercle->x          = _xc;
        cercle->y          = _yc;

        cercle->rayon      = _rayon;

        cercle->formeRouge = _formeRouge;
        cercle->formeVert  = _formeVert;
        cercle->formeBleu  = _formeBleu;

        cercle->fondRouge  = _fondRouge;
        cercle->fondVert   = _fondVert;
        cercle->fondBleu   = _fondBleu;
       }
  else {
        debug_afficher ( " Erreur de création de la structure InterfaceGraphique_Cercle ");
       }

 return cercle;
}

InterfaceGraphique_ArcDeCercle* Scene_creerUnArcDeCercle ( double _xc             ,
                                                           double _yc             ,
                                                           double _rayon          ,
                                                           double _angleDepart    ,
                                                           double _angleOuverture ,
                                                           float  _formeRouge     ,
                                                           float  _formeVert      ,
                                                           float  _formeBleu      ,
                                                           float  _fondRouge      ,
                                                           float  _fondVert       ,
                                                           float  _fondBleu       )
 {
  InterfaceGraphique_ArcDeCercle* arcDeCercle = ( InterfaceGraphique_ArcDeCercle* ) debug_malloc ( sizeof ( InterfaceGraphique_ArcDeCercle ) );

  if ( arcDeCercle )
        {
         arcDeCercle->type           = INTERFACE_GRAPHIQUE__ARC_DE_CERCLE__;

         arcDeCercle->x              = _xc;
         arcDeCercle->y              = _yc;

         arcDeCercle->rayon          = _rayon;
         arcDeCercle->angleDepart    = _angleDepart;
         arcDeCercle->angleOuverture = _angleOuverture;

         arcDeCercle->formeRouge     = _formeRouge;
         arcDeCercle->formeVert      = _formeVert;
         arcDeCercle->formeBleu      = _formeBleu;

         arcDeCercle->fondRouge      = _fondRouge;
         arcDeCercle->fondVert       = _fondVert;
         arcDeCercle->fondBleu       = _fondBleu;
        }
   else {
         debug_afficher ( " Erreur de création de la structure InterfaceGraphique_ArcDeCercle ");
        }

  return arcDeCercle;
 }

InterfaceGraphique_CadreDImage* Scene_creerUnCadreDImage ( double   _x       ,
                                                           double   _y       ,
                                                           float    _zoom_x  ,
                                                           float    _zoom_y  ,
                                                           uint16_t _idImage )
 {
  InterfaceGraphique_CadreDImage* cadreDImage = ( InterfaceGraphique_CadreDImage* ) debug_malloc ( sizeof ( InterfaceGraphique_CadreDImage ) );

  if ( cadreDImage )
        {
         cadreDImage->type       = INTERFACE_GRAPHIQUE__CADRE_D_IMAGE__;

         cadreDImage->x          = _x;
         cadreDImage->y          = _y;

         cadreDImage->zoom_x     = _zoom_x;
         cadreDImage->zoom_y     = _zoom_y;
         cadreDImage->idImage    = _idImage;

         cadreDImage->formeRouge = -1;
         cadreDImage->formeVert  = -1;
         cadreDImage->formeBleu  = -1;

         cadreDImage->fondRouge  = -1;
         cadreDImage->fondVert   = -1;
         cadreDImage->fondBleu   = -1;
        }
   else {
         debug_afficher ( " Erreur de création de la structure InterfaceGraphique_CadreDImage ");
        }

  return cadreDImage;
 }

int32_t Scene_ajouterUnSegment ( InterfaceGraphique_Scene* _scene      ,
                                 double                    _x1         ,
                                 double                    _y1         ,
                                 double                    _x2         ,
                                 double                    _y2         ,
                                 float                     _formeRouge ,
                                 float                     _formeVert  ,
                                 float                     _formeBleu  )
 {
  int32_t numeroFigure = -1; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    InterfaceGraphique_Segment* segment = Scene_creerUnSegment ( _x1         ,
                                                                 _y1         ,
                                                                 _x2         ,
                                                                 _y2         ,
                                                                 _formeRouge ,
                                                                 _formeVert  ,
                                                                 _formeBleu  );

    if ( segment )
     {
      numeroFigure = ListeChainee_ajouterALaFin ( _scene->listeDesFormesGraphiques , segment );
     }
   }

  return numeroFigure;
 }

int32_t Scene_ajouterUnRectangle ( InterfaceGraphique_Scene* _scene      ,
                                   double                    _x1         ,
                                   double                    _y1         ,
                                   double                    _x2         ,
                                   double                    _y2         ,
                                   float                     _formeRouge ,
                                   float                     _formeVert  ,
                                   float                     _formeBleu  ,
                                   float                     _fondRouge  ,
                                   float                     _fondVert   ,
                                   float                     _fondBleu   )
 {
  int32_t numeroFigure = -1; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    InterfaceGraphique_Rectangle* rectangle = Scene_creerUnRectangle ( _x1         ,
                                                                       _y1         ,
                                                                       _x2         ,
                                                                       _y2         ,
                                                                       _formeRouge ,
                                                                       _formeVert  ,
                                                                       _formeBleu  ,
                                                                       _fondRouge  ,
                                                                       _fondVert   ,
                                                                       _fondBleu   );

    if ( rectangle )
     {
      numeroFigure = ListeChainee_ajouterALaFin ( _scene->listeDesFormesGraphiques , rectangle );
     }
   }

  return numeroFigure;
 }

int32_t Scene_ajouterUnCercle ( InterfaceGraphique_Scene* _scene      ,
                                double                    _xc         ,
                                double                    _yc         ,
                                double                    _rayon      ,
                                float                     _formeRouge ,
                                float                     _formeVert  ,
                                float                     _formeBleu  ,
                                float                     _fondRouge  ,
                                float                     _fondVert   ,
                                float                     _fondBleu   )
 {
  int32_t numeroFigure = -1; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    InterfaceGraphique_Cercle* cercle = Scene_creerUnCercle ( _xc         ,
                                                              _yc         ,
                                                              _rayon      ,
                                                              _formeRouge ,
                                                              _formeVert  ,
                                                              _formeBleu  ,
                                                              _fondRouge  ,
                                                              _fondVert   ,
                                                              _fondBleu   );

    if ( cercle )
     {
      numeroFigure = ListeChainee_ajouterALaFin ( _scene->listeDesFormesGraphiques , cercle );
     }
   }

  return numeroFigure;
 }


int32_t Scene_ajouterUnArcDeCercle  ( InterfaceGraphique_Scene* _scene          ,
                                      double                    _xc             ,
                                      double                    _yc             ,
                                      double                    _rayon          ,
                                      double                    _angleDepart    ,
                                      double                    _angleOuverture ,
                                      float                     _formeRouge     ,
                                      float                     _formeVert      ,
                                      float                     _formeBleu      ,
                                      float                     _fondRouge      ,
                                      float                     _fondVert       ,
                                      float                     _fondBleu       )
 {
  int32_t numeroFigure = -1; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    InterfaceGraphique_ArcDeCercle* arcDeCercle = Scene_creerUnArcDeCercle ( _xc             ,
                                                                             _yc             ,
                                                                             _rayon          ,
                                                                             _angleDepart    ,
                                                                             _angleOuverture ,
                                                                             _formeRouge     ,
                                                                             _formeVert      ,
                                                                             _formeBleu      ,
                                                                             _fondRouge      ,
                                                                             _fondVert       ,
                                                                             _fondBleu       );

    if ( arcDeCercle )
     {
      numeroFigure = ListeChainee_ajouterALaFin ( _scene->listeDesFormesGraphiques , arcDeCercle );
     }
   }

  return numeroFigure;
 }

int32_t Scene_ajouterUnCadreDImage ( InterfaceGraphique_Scene* _scene   ,
                                     double                    _x       ,
                                     double                    _y       ,
                                     float                     _zoom_x  ,
                                     float                     _zoom_y  ,
                                     uint16_t                  _idImage )
 {
  int32_t numeroFigure = -1; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    InterfaceGraphique_CadreDImage* cadreDImage = Scene_creerUnCadreDImage ( _x       ,
                                                                             _y       ,
                                                                             _zoom_x  ,
                                                                             _zoom_y  ,
                                                                             _idImage );

    if ( cadreDImage )
     {
      numeroFigure = ListeChainee_ajouterALaFin ( _scene->listeDesFormesGraphiques , cadreDImage );
     }
   }

  return numeroFigure;
 }

InterfaceGraphique_Forme* Scene_lireUneForme ( InterfaceGraphique_Scene* _scene  ,
                                               uint16_t                  _numero )
 {
  InterfaceGraphique_Forme* figure = NULL; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    figure = ListeChainee_lire ( _scene->listeDesFormesGraphiques , _numero );
   }

  return figure;
 }

InterfaceGraphique_Forme* Scene_supprimerUneForme ( InterfaceGraphique_Scene* _scene  ,
                                                    uint16_t                  _numero )
 {
  InterfaceGraphique_Forme* figure = NULL; // On suppose que ça s'est mal passé

  if ( _scene )
   {
    figure = ListeChainee_supprimer ( _scene->listeDesFormesGraphiques , _numero );
   }

  return figure;
 }

void Scene_effacer ( InterfaceGraphique_Scene* _scene )
 {
  if ( _scene )
   {
    ListeChainee_supprimerTout ( _scene->listeDesFormesGraphiques );
   }
 }

/********************************************************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>




Fenetre_X11* Fenetre_X11_creer ( char*    _titre   ,
                                 uint16_t _largeur ,
                                 uint16_t _hauteur )
 {
  Fenetre_X11* fenetre_X11 = ( Fenetre_X11* ) debug_malloc ( sizeof (Fenetre_X11) );

  if ( fenetre_X11 == NULL )
        {
         debug_afficher ( "Erreur de création de la structure fenetre_X11 ");
        }
   else {
         /*** Stockage des caractéristiques de la fenêtre ***/

         fenetre_X11->largeur = _largeur;
         fenetre_X11->hauteur = _hauteur;

         fenetre_X11->titre   = ( char* ) debug_malloc ( strlen (_titre) + 1 );

         if ( fenetre_X11->titre == NULL )
               {
                debug_afficher ( "Erreur de création de la structure fenetre_X11 ");

                fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
               }
          else {
                strcpy ( fenetre_X11->titre , _titre );

                /*** Creation d'une connexion vers le serveur X ***/

                fenetre_X11->affichage = XOpenDisplay ( NULL );

                if ( fenetre_X11->affichage == NULL )
                      {
                       debug_afficher ("On ne peut pas se connecter au serveur X");

                       fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
                      }
                 else {
                       /*** Creation du contexte graphique OpenGL ***/

                       fenetre_X11->contexteGraphique = ContexteOpenGL_creer ( fenetre_X11 );

                       if ( fenetre_X11->contexteGraphique == NULL )
                             {
                              debug_afficher ("On ne peut pas créer le contexte graphique");

                              fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
                             }
                        else {
                              /*** Creation de la fenetre X Window ***/

                              fenetre_X11->eventMask = KeyPressMask        |   // KeyPressMask      : pour gérer l'enfoncement d'une touche du clavier
                                                       KeyReleaseMask      |   // KeyReleaseMask    : pour gérer le relâchement d'une touche du clavier
                                                       ButtonPressMask     |   // ButtonPressMask   : pour gérer l'enfoncement d'un bouton de la souris (boutons 1 à 5)
                                                       ButtonReleaseMask   |   // ButtonReleaseMask : pour gérer le relâchement d'un boutond de la souris (boutons 1 à 5)
                                                       PointerMotionMask   |   // PointerMotionMask : pour gérer les mouvements de la souris sans tenir compte des boutons
                                                                               // ButtonMotionMask  : pour gérer les mouvements de la souris lorsque l'un des 5 boutons est enfoncé
                                                                               // Button1MotionMask : pour gérer les mouvements de la souris lorsque le bouton 1 est enfoncé
                                                                               // Button2MotionMask : pour gérer les mouvements de la souris lorsque le bouton 2 est enfoncé
                                                                               // Button3MotionMask : pour gérer les mouvements de la souris lorsque le bouton 3 est enfoncé
                                                                               // Button4MotionMask : pour gérer les mouvements de la souris lorsque le bouton 4 est enfoncé
                                                                               // Button5MotionMask : pour gérer les mouvements de la souris lorsque le bouton 5 est enfoncé
                                                       ExposureMask        |
                                                       StructureNotifyMask |
                                                       FocusChangeMask     |
                                                       EnterWindowMask     |
                                                       LeaveWindowMask ;

                              XSetWindowAttributes attributs;

                              attributs.colormap         = XCreateColormap (              fenetre_X11->affichage                     ,
                                                                                           RootWindow ( fenetre_X11->affichage                   ,
                                                                                                        fenetre_X11->modeDeVisualisation->screen ) ,
                                                                                                        fenetre_X11->modeDeVisualisation->visual   ,
                                                                                           AllocNone
                                                                                         );

                              attributs.background_pixel = 0;
                              attributs.border_pixel     = 0;
                              attributs.event_mask       = fenetre_X11->eventMask;


                              fenetre_X11->fenetre = XCreateWindow (              fenetre_X11->affichage                     ,
                                                                     RootWindow ( fenetre_X11->affichage                   ,
                                                                                  fenetre_X11->modeDeVisualisation->screen ) ,
                                                                                  0                                          ,
                                                                                  0                                          ,
                                                                                  fenetre_X11->largeur                       ,
                                                                                  fenetre_X11->hauteur                       ,
                                                                                  0                                          ,
                                                                                  fenetre_X11->modeDeVisualisation->depth    ,
                                                                                  InputOutput                                ,
                                                                                  fenetre_X11->modeDeVisualisation->visual   ,
                                                                                  CWBorderPixel | CWColormap | CWEventMask   ,
                                                                                  &attributs                                 );

                              fenetre_X11->wm_delete_window = XInternAtom( fenetre_X11->affichage , "WM_DELETE_WINDOW", 0 );

                              // XSetWMProtocols ( fenetre_X11->affichage , fenetre_X11->fenetre, &(fenetre_X11->wm_delete_window), 1);

                              XSetStandardProperties ( fenetre_X11->affichage ,
                                                       fenetre_X11->fenetre   ,
                                                       fenetre_X11->titre     ,
                                                       fenetre_X11->titre     ,
                                                       None                   ,
                                                       NULL                   ,
                                                       0                      ,
                                                       NULL                   );

                              if ( ContexteOpenGL_activer ( fenetre_X11->contexteGraphique ) == 0 )
                                    {
                                     debug_afficher ( "Erreur d'activation du contexte graphique");

                                     fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
                                    }
                               else {
                                     XMapWindow ( fenetre_X11->affichage ,
                                                  fenetre_X11->fenetre   );

                                     fenetre_X11->fermer=0;

                                     fenetre_X11->lesGestionnairesDEvenements = LesGestionnairesDEvenements_creer ();

                                     if ( fenetre_X11->lesGestionnairesDEvenements == NULL )
                                           {
                                            debug_afficher ( "Erreur de création du gestionnaire d'événements");

                                            fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
                                           }
                                      else {
                                            fenetre_X11->scene = Scene_creer ();

                                            if ( fenetre_X11->scene == NULL )
                                             {
                                              debug_afficher ( "Erreur de création de la scène");

                                              fenetre_X11 = Fenetre_X11_detruire ( fenetre_X11 );
                                             }
                                           }
                                    }
                             }
                      }
               }
        }

  return fenetre_X11;
 }

Fenetre_X11* Fenetre_X11_detruire ( Fenetre_X11* _fenetre_X11 )
 {
 // effacerDessin ();

 // detruireTableauDesImages ();

  if ( _fenetre_X11 )
   {
    XCloseDisplay ( _fenetre_X11->affichage);

    if ( _fenetre_X11->titre )
     {
      debug_free ( _fenetre_X11->titre );
     }

    _fenetre_X11->contexteGraphique           = ContexteOpenGL_detruire              ( _fenetre_X11->contexteGraphique           );
    _fenetre_X11->lesGestionnairesDEvenements = LesGestionnairesDEvenements_detruire ( _fenetre_X11->lesGestionnairesDEvenements );
   }

  return NULL;
 }

void Fenetre_X11_arreterGestionEvenements ( Fenetre_X11* _fenetre_X11 )
 {
  if ( _fenetre_X11 )
   {
    _fenetre_X11->fermer = 1;
   }
 }

void Fenetre_X11_gererEvenements ( Fenetre_X11* _fenetre_X11 )
 {
  struct timespec dateIteration;
  struct timespec dateDebut;

  clock_gettime ( CLOCK_MONOTONIC, &dateDebut );

  GestionnaireDEvenements* gest                 = NULL;
  void (*fct) ( uint64_t , uint64_t , uint64_t) = NULL;

  do
   {
    clock_gettime (CLOCK_MONOTONIC, &(dateIteration));

    gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "PERIODIQUE" );

    if ( gest )
     {
      fct = gest->fct;

      if ( fct )
       {
        int64_t difference = ( ( dateIteration.tv_sec * 1000000000 ) + dateIteration.tv_nsec ) -
                             ( ( dateDebut    .tv_sec * 1000000000 ) + dateDebut    .tv_nsec );

        (*fct) ( (uint64_t) difference , 0 , 0 );
       }
     }

    XEvent event;

    gest = NULL;
    fct  = NULL;

    /*
    XNextEvent ( _fenetre_X11->affichage, &event);  // C'est bloquant
    if ( 1 )
    */

    if ( XCheckWindowEvent ( _fenetre_X11->affichage ,
                             _fenetre_X11->fenetre   ,
                             _fenetre_X11->eventMask ,
                             &event ) )
     {
      switch (event.type)
       {
        case KeyPress      : gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "TOUCHE ENFONCEE" );

                             if ( gest )
                              {
                               fct = gest->fct;

                               if ( fct )
                                {
                                 (*fct) ( event.xkey.keycode , event.xkey.x , event.xkey.y );
                                }
                              }

                             break;

        case KeyRelease    : gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "TOUCHE RELACHEE" );

                             if ( gest )
                              {
                               fct = gest->fct;

                               if ( fct )
                                {
                                 (*fct) ( event.xkey.keycode , event.xkey.x , event.xkey.y );
                                }
                              }

                             break;

        case ButtonPress   : gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "CLIC ENFONCE" );

                             if ( gest )
                              {
                               fct = gest->fct;

                               if ( fct )
                                {
                                 (*fct) ( event.xbutton.button , event.xbutton.x , event.xbutton.y );
                                }
                              }

                             break;

        case ButtonRelease : gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "CLIC RELACHE" );

                             if ( gest )
                              {
                               fct = gest->fct;

                               if ( fct )
                                {
                                 (*fct) ( event.xbutton.button , event.xbutton.x , event.xbutton.y );
                                }
                              }

                             break;

        case MotionNotify  : gest = LesGestionnairesDEvenements_lireParLeNom ( _fenetre_X11->lesGestionnairesDEvenements , "DEPLACEMENT SOURIS" );

                             if ( gest )
                              {
                               fct = gest->fct;

                               if ( fct )
                                {
                                 (*fct) ( 0 , event.xmotion.x , event.xmotion.y );
                                }
                              }

                             break;

        case ClientMessage : if ( (Atom) event.xclient.data.l[0] == _fenetre_X11->wm_delete_window )
                              {
                               _fenetre_X11->fermer = 1;
                              }
       }

      // https://tronche.com/gui/x/xlib/events/processing-overview.html
      // https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html#XButtonEvent

     }

    Fenetre_X11_rafraichirFenetre ( _fenetre_X11 );
   }
   while ( _fenetre_X11->fermer == 0 );
 }

void Fenetre_X11_rafraichirFenetre ( Fenetre_X11* _fenetre_X11 )
 {
  if ( _fenetre_X11 )
   {
    ContexteOpenGL_rafraichir ( _fenetre_X11->contexteGraphique );
   }
 }

//https://nachtimwald.com/2009/11/01/x11-intercept-window-close-event/

/********************************************************************************************************/

/********************************************************************************************************/

/********************************************************************************************************/

static Fenetre_X11* fenetre = NULL;

void creerFenetre (
                    char*    _titre   ,
                    uint16_t _largeur ,
                    uint16_t _hauteur
                  )
 {
  fenetre = Fenetre_X11_creer ( _titre   ,
                                _largeur ,
                                _hauteur );
 }

void detruireFenetre ( void )
 {
  Fenetre_X11_detruire ( fenetre );
 }

void gererEvenements ( void )
 {
  Fenetre_X11_gererEvenements ( fenetre );
 }

void arreterGestionEvenements ( void )
 {
  Fenetre_X11_arreterGestionEvenements ( fenetre );
 }

void specifierLimites (
                        double _gauche ,
                        double _droite ,
                        double _bas    ,
                        double _haut
                      )
 {
  if ( fenetre )
   {
    ContexteOpenGL_specifierLimites2D  ( fenetre->contexteGraphique ,
                                         _gauche                    ,
                                         _droite                    ,
                                         _bas                       ,
                                         _haut                      );
   }
 }

void specifierGestionnaire (
                             char* _nomDeLEvenement ,
                             void* _fct
                           )
 {
  void (*fct) (uint64_t, uint64_t, uint64_t) = (void (*) (uint64_t,uint64_t, uint64_t)) _fct;

  if ( fenetre )
   {
    LesGestionnairesDEvenements_ajouterUnGestionnaire ( fenetre->lesGestionnairesDEvenements ,
                                                        _nomDeLEvenement                     ,
                                                        fct                                  );
   }
 }

void effacerDessin ()
 {
  if ( fenetre )
   {
    Scene_effacer ( fenetre->scene );
   }
 }

void dessinerSegment (
                       double   _x1              ,
                       double   _y1              ,
                       double   _x2              ,
                       double   _y2              ,
                       float    _rouge           ,
                       float    _vert            ,
                       float    _bleu
                     )
 {
  if ( fenetre )
   {
    Scene_ajouterUnSegment ( fenetre->scene ,
                             _x1            ,
                             _y1            ,
                             _x2            ,
                             _y2            ,
                             _rouge         ,
                             _vert          ,
                             _bleu          );
   }
 }

void dessinerRectangle (
                         double _x1         ,
                         double _y1         ,
                         double _x2         ,
                         double _y2         ,
                         float  _rougeForme ,
                         float  _vertForme  ,
                         float  _bleuForme  ,
                         float  _rougeFond  ,
                         float  _vertFond   ,
                         float  _bleuFond
                       )
 {
  if ( fenetre )
   {
    Scene_ajouterUnRectangle ( fenetre->scene ,
                               _x1            ,
                               _y1            ,
                               _x2            ,
                               _y2            ,
                               _rougeForme    ,
                               _vertForme     ,
                               _bleuForme     ,
                               _rougeFond     ,
                               _vertFond      ,
                               _bleuFond      );
   }
 }

void dessinerCercle (
                      double _x          ,
                      double _y          ,
                      double _rayon      ,
                      float  _rougeForme ,
                      float  _vertForme  ,
                      float  _bleuForme  ,
                      float  _rougeFond  ,
                      float  _vertFond   ,
                      float  _bleuFond
                    )
 {
  if ( fenetre )
   {
    Scene_ajouterUnCercle ( fenetre->scene ,
                            _x             ,
                            _y             ,
                            _rayon         ,
                            _rougeForme    ,
                            _vertForme     ,
                            _bleuForme     ,
                            _rougeFond     ,
                            _vertFond      ,
                            _bleuFond      );
   }
 }

void dessinerArcDeCercle (
                           double _x              ,
                           double _y              ,
                           double _rayon          ,
                           double _angleDepart    ,
                           double _angleOuverture ,
                           float  _rougeForme     ,
                           float  _vertForme      ,
                           float  _bleuForme      ,
                           float  _rougeFond      ,
                           float  _vertFond       ,
                           float  _bleuFond       )
 {
  if ( fenetre )
   {
    Scene_ajouterUnArcDeCercle ( fenetre->scene  ,
                                 _x              ,
                                 _y              ,
                                 _rayon          ,
                                 _angleDepart    ,
                                 _angleOuverture ,
                                 _rougeForme     ,
                                 _vertForme      ,
                                 _bleuForme      ,
                                 _rougeFond      ,
                                 _vertFond       ,
                                 _bleuFond       );
   }
 }

void dessinerImage (
                     double   _x       ,
                     double   _y       ,
                     float    _zoom_x  ,
                     float    _zoom_y  ,
                     uint16_t _idImage
                   )
 {
  if ( fenetre )
   {
    Scene_ajouterUnCadreDImage ( fenetre->scene ,
                                 _x             ,
                                 _y             ,
                                 _zoom_x        ,
                                 _zoom_y        ,
                                 _idImage       );
   }
 }

int32_t chargerImageBMP ( char* _nomDuFichier )
 {
  int32_t numeroImage = -1;

  if ( fenetre )
   {
    ImageBMP* imageBMP = ImageBMP_lire ( _nomDuFichier );

    if ( imageBMP )
     {
      numeroImage = Scene_chargerUneImage ( fenetre->scene , imageBMP );
     }
   }

  return numeroImage;
 }


