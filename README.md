// ----------------------------------------------------------------------- //
// /////////////////////////////////////////////////////////////////////// //
// +---------------------------------------------------------------------+ //
// |     Driver softwaroveho serioveho rozhrani (polovicni duplex)       | //
// |                     Verze 2.00 Build 071128                         | //
//                             target: 89...                             | //
#define                           C51RD2                                 | //
// |                                                                     | //
// |                       Copyright Tomas Hujer                         | //
// |                           (c) 2005-2007                             | //
// |                    thomas.hoodger(at)gmail.com                      | //
// |                                                                     | //
// |             zakladni princip vychazi z driveru v A51                | //
// |                  (c)2003-2007 Elitronic s.r.o.                      | //
// |                   by K.L.soft & Milan Slovak                        | //
// |                                                                     | //
// +---------------------------------------------------------------------+ //
// /////////////////////////////////////////////////////////////////////// //
// ----------------------------------------------------------------------- //
//                                  TODO                                   //
// ----------------------------------------------------------------------- //
//                                                                         //
//  - Nefunkcni odesilani znaku presmerovanim vystupu, zrejme bude nutne   //
//    prepracovat vysilani znaku na prime s cekanim na odeslani            //
//                                                                         //
//  - Nutno prepocitat pocty instrukci a aktualizovat hodnoty casovace     //
//    pro presnost casovani                                                //
//                                                                         //
// ----------------------------------------------------------------------- //
//                            Version history                              //
// ----------------------------------------------------------------------- //
// Release        Note                                                     //
// ----------------------------------------------------------------------- //
//  1.4         Objevena chyba, pri soucasnem pouziti driveru s driverem   //
//              pro HW232 a softwarovem echovani se pri pokusu o odeslani  //
//              vice znaku po sobe znaky zkomoli, a prestane fungovat      //
//              prijmani znaku                                             //
//                                                                         //
//  1.5         Zmena indexace, zruseni porovnavani indexu pro zapis       //
//              a cteni mezi sebou, pridany registry obsahujici pocet      //
//              znaku v bufferech chyba se zatuhnutim komunikace opravena, //
//              avsak pokud je zapsano vice znaku za sebou bez cekani,     //
//              dojde ke zkomoleni, ale vysilani funguje dal.              //
//                                                                         //
//  1.7         Osetreni nahodneho prepisu indexu prijimaciho a vysilaciho //
//              bufferu. Pri vyprazdneni bufferu jsou jeho indexy          //
//              nulovany.                                                  //
//                                                                         //
//  1.8         Prirazeni pinu presunuto do externiho souboru sw_uart.def  //
//                                                                         //
//  2.0         Prepracovano do C51, odladena funkcni verze, zjednoduseny  //
//              funkce pro ukladani znaku a priznaku ramce, pouzita        //
//              Pomocna promenna pro ulozeni vsech prichozich bitu,        //
//              vysledny znak a stavy jsou kontrolovany az po dokonceni    //
//              prijmu. Odecty instrukci od casoveho intervalu nejsou      //
//              provedeny. Casy odpovidaji rychlosti, mereno v simulatoru  //
//              Nutno overit presnost.                                     //
//                                                                         //
// ----------------------------------------------------------------------- //
// Hodnota casovace 0 se nastavuje na dobu trvani jednoho bitu.            //
//                                                                         //
// Pro 4800Bd a @11.0592MHz je to -192                                     //
// Pro 9600Bd a @18.432MHz je to -160                                      //
//                                                                         //
// Pro start prijmu se nastavuje timer0 na polovicku trvani jednoho bitu   //
// minus doba trvani instrukci od externiho preruseni 1 do odstartovani    //
// casovace 1 a od preruseni casovace 1 do precteni rxd1                   //
// (celkem ? cyklu)                                                        //
//                                                                         //
// Pro 4800Bd a @11.0592MHz je to -66                                      //
// Pro 9600Bd a @18.432MHz je to -50                                       //
//                                                                         //
// Rutina preruseni pouziva registrovou banku 2                            //
//                                                                         //
// ----------------------------------------------------------------------- //
