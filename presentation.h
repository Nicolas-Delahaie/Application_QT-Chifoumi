#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include <QTimer>

#include "modele.h"


class ChifoumiVue;
class Presentation : public QObject
{
    Q_OBJECT
public:    
    //Initialisaitons
    explicit Presentation(Modele* m, QObject* parent = nullptr);

    //Getters / Setters
    Modele* getModele();            //Récupere le modèle
    ChifoumiVue* getVue();          //Récupere la vue
    void setModele(Modele *m);      //Associe le modèle à la présentation
    void conexionVue(ChifoumiVue*); //Lie la vue a la presentation

    //Evenements
    void jouer(Modele::UnCoup);     //Joue en fonction du coup de l utilisateur

public slots:
    //Slots externes (activés par la vue)
    void demanderNouvellePartie();  //Signal demandant une nouvelle partie
    void demanderCiseau();          //Slot demandant de jouer le ciseau
    void demanderPierre();          //Slot demandant de jouer la pierre
    void demanderPapier();          //Slot demandant de jouer le papier

private:
    //Composantes
    Modele *_leModele;      //Le modèle
    ChifoumiVue *_laVue;    //La vue
};

#endif // PRESENTATION_H