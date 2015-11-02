#ifndef TEST_HISTOGRAMME_INCLUDED
#define TEST_HISTOGRAMME_INCLUDED

// #include <classe.hpp>
// #include <histogramme.hpp>

// Le type de l'histogramme va changer au cours du TP:
//  - C'est une classe au départ,
//  - Ensuite ça devient un template.
// D'où le typedef:

// typedef Histogramme Histo;
// typedef Histogramme<> Histo;

TEST ( TestHistogramme, Classe ) {
/*
 Classe c1(5.0,10.0);
 Classe c2;

 c1.ajouter();
 c1.ajouter();

 c2.setBorneInf(7.0);
 c2.setBorneSup(13.0);
 c2.setQuantite(24);
 c2.ajouter();

 EXPECT_EQ ( c1.getBorneInf(), 5.0 );
 EXPECT_EQ ( c1.getBorneSup(), 10.0 );
 EXPECT_EQ ( c1.getQuantite(), 2 );

 EXPECT_EQ ( c2.getBorneInf(), 7.0 );
 EXPECT_EQ ( c2.getBorneSup(), 13.0 );
 EXPECT_EQ ( c2.getQuantite(), 25 );
*/
}

TEST ( TestHistogramme, CreationVide ) {
/*
 Histo h(0.0,20.0,10);

 Histo::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                         i  = 0;

 while (it != h.getClasses().end()) {
  EXPECT_EQ ( it->getBorneInf(), 2*i );
  EXPECT_EQ ( it->getBorneSup(), 2*(i+1) );
  ++it;
  ++i;
 }

 EXPECT_EQ ( i, 10 );
*/
}

TEST ( TestHistogramme, CreationAvecEchantillon ) {
/*
 Echantillon echantillon;
 double      val;

 unsigned classes[10] = {0};

 srand(time(0));

 for (unsigned i = 0 ; i<20 ; ++i) {
  val=double(rand())/RAND_MAX*20.0;
  classes[unsigned(val)/2]++;
  echantillon.ajouter(Valeur(val));
 }

 Histo h(0.0,20.0,10);

 h.ajouter(echantillon);

 Histo::classes_t::const_iterator it = h.getClasses().begin();
 unsigned                         i  = 0;

 while (it != h.getClasses().end()) {
  EXPECT_EQ ( classes[i], it->getQuantite() );
  ++it;
  ++i;
 }
 */
}

#endif // TEST_HISTOGRAMME_INCLUDED
