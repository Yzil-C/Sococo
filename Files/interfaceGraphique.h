#ifndef INTERFACE_GRAPHIQUE_H
#define INTERFACE_GRAPHIQUE_H

#include <stdint.h>

void    creerFenetre             (
                                   char*    _titre           ,
                                   uint16_t _largeur         ,
                                   uint16_t _hauteur
                                 );

void    detruireFenetre          (
                                   void
                                 );

void    gererEvenements          (
                                   void
                                 );

void    arreterGestionEvenements (
                                   void
                                 );

void    specifierLimites         (
                                   double   _gauche          ,
                                   double   _droite          ,
                                   double   _bas             ,
                                   double   _haut
                                 );

void    specifierGestionnaire    (
                                   char*    _nomDeLEvenement ,
                                   void*    _fct
                                 );

void    effacerDessin            (
                                   void
                                 );

void    dessinerSegment          (
                                   double   _x1              ,
                                   double   _y1              ,
                                   double   _x2              ,
                                   double   _y2              ,
                                   float    _rouge           ,
                                   float    _vert            ,
                                   float    _bleu
                                 );

void    dessinerRectangle        (
                                   double   _x1              ,
                                   double   _y1              ,
                                   double   _x2              ,
                                   double   _y2              ,
                                   float    _rougeForme      ,
                                   float    _vertForme       ,
                                   float    _bleuForme       ,
                                   float    _rougeFond       ,
                                   float    _vertFond        ,
                                   float    _bleuFond
                                 );

void    dessinerCercle           (
                                   double   _x               ,
                                   double   _y               ,
                                   double   _rayon           ,
                                   float    _rougeForme      ,
                                   float    _vertForme       ,
                                   float    _bleuForme       ,
                                   float    _rougeFond       ,
                                   float    _vertFond        ,
                                   float    _bleuFond
                                 );

void    dessinerArcDeCercle      (
                                   double   _x               ,
                                   double   _y               ,
                                   double   _rayon           ,
                                   double   _angleDepart     ,
                                   double   _angleOuverture  ,
                                   float    _rougeForme      ,
                                   float    _vertForme       ,
                                   float    _bleuForme       ,
                                   float    _rougeFond       ,
                                   float    _vertFond        ,
                                   float    _bleuFond
                                 );

void    dessinerImage            (
                                   double   _x               ,
                                   double   _y               ,
                                   float    _zoom_x          ,
                                   float    _zoom_y          ,
                                   uint16_t _idImage
                                 );


int32_t chargerImageBMP          (
                                   char*    _nomDuFichier
                                 );


#endif
