#ifndef ESCENAS_H
#define ESCENAS_H

#include "./Classes/Escena.h"

/* CREACIÓN DE ESCENAS:
Aqui se crea la historia completa
Se conforma por escenas

* Narraciones vector<string>: Es lo que se le cuenta al usuario
* Decisiones vector<string>: Son las decisiones posibles que puede tomar el
usuario

sig_escenas vector<Escena>: Es un vector conformado por Escenas. Su indice
coincide con el de decisiones
*/

// Devuelve la escena inicial
Escena obtener_escena_inicial() {
  Escena inicio;
  inicio.narraciones = {
      "Eres Frank Morris, un prisionero genio de 35 años en Alcatraz, una "
      "prisión de maxima seguridad en una isla remota. Eres conocido "
      "por tus habilidades excepcionales. Estas cansado de estar encerrado por "
      "lo que decides llevar a cabo un audaz plan de escape. Cada elección que "
      "tomes será crucial para el éxito de tu fuga.\n",

      "Estas ideando un plan para escapar pero te haces la pregunta de si "
      "necesitas un compañero de escape",
      "Miras a Clarence, un tipo creativo, es conocido por sus "
      "distintas fugas en las diferentes carceles por las que pasó",
      "¿decides ir en solitario o prefieres escapar con Clarence?"};
  inicio.decisiones = {"Solitario", "Clarence"};
  Escena Solitario;
  Solitario.narraciones = {
      "Confias en tu ingenio y en tus habilidades por lo "
      "que decides hacer el escape en solitario",
      "Te pones a pensar formas de como salir de tu celda, la unica manera es "
      "por la ventana de barrotes",
      "Un dia notas que los demás presos colgaban sabanas en sus celdas "
      "cuando los pasillos estaban llenos de personas ",
      "¿decides hacer una prueba poniendo tu sabana de tal forma que tape lo "
      "que estas haciendo o prefieres esperar otra manera de escape?"};
  Solitario.decisiones = {"Poner sabana", "esperar otra opción de escape"};

  Escena c_sabana;
  c_sabana.narraciones = {
    "Los guardias se acostumbran a ver tu sabana, por lo "
 "que no te ponen problema",
 "Ahora necesitas un destornillador"
 "¿Como decides obtenerlo?"};
  c_sabana.decisiones = {"Utilizar metal para crearlo","robarlo del area de metales"};
  
  Escena c_crear;
  c_crear.narraciones = {
    "Decides crear tu propio destornillador",
    "Utilizas unas hojas de acero para crear el destornillador "
    "y darle forma",
    "logras quitar con el destornillador la primera parte de la ventana",
    "tienes que cortar la segunda parte con una hoja de sierra",
    "¿como la consigues?"};
  c_crear.decisiones = {"le pagas a un guardia para que te la consiga","la robas del area de metales"};

  Escena fin_robar;
  fin_robar.narraciones = {
    "Un dia en el que estas en el area de metales, intentas meter la herramienta en tu ropa interior",
    "en el momento que vas a salir suena el detector de metales, y eres descubierto",
    "te requisan, te hacen quitar la ropa y finalmente descubren el objeto",
    "eres castigado y llevado a tu celda de vuelta "};

  Escena c_pagar;
  c_pagar.narraciones = {
    "Decides sobornar al guardia",
    "el acepta tu suborno y te trae la hoja de sierra",
    "ya tienes la forma de escapar de tu celda",
    "tiene que pensar como salir salir de la isla una vez pasada la reja",
    "Recuerdas haber visto sacos un cuarto de lavanderia, "
    "con estsos puedes hacer una balsa para poder pasar a la isla, tambien tienes la opción de atravesarla nadando"
    "¿cuál decides?"};
  c_pagar.decisiones = {"Hacer la balsa","Arriesgarte y pasarla nadando"};
  
  Escena c_balsa;
  c_balsa.narraciones = {
    "Llega el dia en el que vas a salir de tu celda",
    "coges el destornillador, y abres la primera parte de la ventana",
    "coges la hoja de sierra y cortas la segunda parte de la ventana, logras salir al patio",
    "te encuentras con una reja de 5 metros de altura",
    "tienes las siguientes opciones para pasar el obstaculo"};
  c_balsa.decisiones = {"cortar la reja con la sierra con riesgo de hacer ruido y ser decubiero","trepar la reja pero dejar la balsa y tener que buscar otra forma de atravesar la isla"};

  Escena fin_nadar1;
  fin_nadar1.narraciones = { 
    "Llega el dia en el que vas a salir de tu celda",
    "coges el destornillador, y abres la primera parte de la ventana ",
    "coges la hoja de sierra y cortas la segunda parte de la ventana, logras salir al patio ",
    "te encuentras con una reja de 5 metros de altura",
    "decides cortar la reja con la sierra y nadar hasta la costa ",
    "mueres ahogado y eres devorado por los tiburones"};

  Escena fin_cortar1;
  fin_cortar1.narraciones = {"Logras cortar la reja sin que se den cuenta los guardias",
    "utilizas la balsa previamente hecha con los sacos",
    "emprendes tu viaje hacia tu libertad",
    "pero en medio del trayecto, unos guardias que iban en barco te encuentran y te vuelven a encerrar",
    "te dan 50 años mas por el intento de fuga y "
    "quedas encerrado de por vida en Alcatraz"};

  Escena c_trepar1;
  c_trepar1.narraciones = {
    "Logras trepar el obstaculo de la reja pero tuviste que dejar la balsa,"
    "ves que unos guardias dejan su barco en la costa un momento para descnasar"
    "tienes las siguientes opciones"};
  c_trepar1.decisiones = {"robar el barco","irte nadando a la costa"};

  Escena fin_robarbarco;
  fin_robarbarco.narraciones = {
    "Logras robar el barco y  consigues tu libertad"
    "haz completado tu objetivo",
    "lo siguiente es escapar de la persecusion",
    "esto ya no es nuestro problema",
    "suerte con eso"};

  Escena fin_nadar2;
  fin_nadar2.narraciones = {"Decides irte nadando hacia la costa",
    "No tienes suerte en tu intento de escape",
    "te ahogas y te deboran los tiburones"
    };
  
  Escena esperar;
  esperar.narraciones = {
      "Decides esperar otra opción de escape",
      "pasan los dias, Te fijas que las cerraduras de las puertas "
    "tienen dos puntos de colores, unas son verdes y otras son rojas",
    "tienes que escoger una llave para poder replicarla, ¿cuál escoges?"};
  esperar.decisiones = {"llave verde","llave roja"};
      
  Escena c_verdes;
  c_verdes.narraciones = {
    "Logras replicar la llave para las puertas verdes",
    "decides comenzar tu plan de escape abriendo las puertas uno y dos y logras salir",
    "te encuentras con una reja de 5 metros"
    "¿que decides hacer?"
    };
  c_verdes.decisiones = {"cortar la reja","trepar la reja"};

  Escena c_cortar2;
  c_cortar2.narraciones = {
    "Logras pasar la reja",
    "Ahora te encuentras con el problema de como salir de la isla",
    "a lo lejos se ve que se acerca lentamente un barco de guardias, te escondes para que no te vean",
    "Los guardias se bajan del barco para buscar porque les avisaron de unos ruidos por esa zona"
    "tienes las siguientes opciones a realizar"};
  c_cortar2.decisiones = {"Dejar pasar la oportunidad e irte nadando","robar el barco arriesgandote a que te capturen o que te disparen"};

  Escena fin_nadar3;
  fin_nadar3.narraciones = {
    "Decides dejar pasar la oportunidad"
    " e irte nadando hacia la costa",
    "tienes suerte y llegaste al otro lado",
    "estas en libertad"};

  Escena fin_robarbarco2;
  fin_robarbarco2.narraciones = {
    "Decides robar el barco de los guardias"
    "antes de que te subas uno de los guardias te nota",
    "es un novato por lo que el miedo se apodera de el y"
    " te dispara",
    "caes muerto al mar"
    "no has logrado tu objetivo"};

  Escena c_rojas;
  c_rojas.narraciones = {
    "Notas que hay muy pocas puertas rojas",
    "Posiblemente no puedas escapar replicando la llave "
    "de las puertas rojas",
    "¿quieres seguir replicando la llave roja o empiezas a crear la verde?"};
  c_rojas.decisiones = {"crear la llave de las puertas verdes","seguir haciendo la llave"};

  Escena fin_rojas;
  fin_rojas.narraciones = {
    "Logras recrear la llave de las puertas rojas",
    "Decides empezar a hacer tu plan de escape",
    "pasas una puerta que se habria con la puerta roja, pasas a la segunda y te das cuenta que no se puede abrir con la roja"
    "de la desesperacion intentas abrirla pero "
    "un guardia te escucha y eres recapturado",
    "no logras tu libertad"};


  Escena Clarence;
  Clarence.narraciones = {
      "Escoges a Clarence como compañero de escape",
      "Te acercas a Clarence y le preguntas si quiere escapar. Él acepta.",
      "Ambos van a hablar a tu celda. Le cuentas que el respiradero de la "
      "celda esta suelto. Pero el propone robarle las llaves a un guardia"};
  Clarence.decisiones = {"Proponer romper el respiradero",
                         "Aceptar robarle las llaves a un guardia"};

  Escena c_respiradero;
  c_respiradero.narraciones = {
      "Clarence acepta la idea y te cuenta sobre robar cucharas y hacer "
      "herramientas caseras para terminar de soltar el respiradero",
      "Despues de varios días ya tienen varias herramientas y sueltan el "
      "respiradero. El hueco es del tamaño para que una persona pueda pasar",
      "Pero deben buscar la manera de ocultarlo para que los guardias no se "
      "den cuenta",
      "Clarence propone hacer un respiradero de cartón, pintandolo de forma "
      "exacta."};
  c_respiradero.decisiones = {"Aceptar la idea",
                              "Propones taparlo con una manta"};

  Escena cr_carton;
  cr_carton.narraciones = {
      "Clarence se dedica a hacer un respiradero de "
      "carton y a pintarlo durante el día",
      "Mientras tu buscas la manera de entrar al hueco "
      "por la noche sin que se den cuenta de tu ausencia. Clarence propone "
      "hacer cabezas falsas con pelo de la peluqueria.",
      "En la noche logran tapar el respiradero con uno falso y hacen sus "
      "cabezas falsas.",
      "Deciden entrar al hueco para investigar más. Encuentran una ventilación "
      "por la que pueden pasar al techo",
      "Pero está con candado, Clarence propone limar el candado"};

  cr_carton.decisiones = {"Limar el candado",
                          "Proponer romper el candado con un martillo"};

  Escena cr_limar;
  cr_limar.narraciones = {
      "Empiezas a limar el candado pero es muy demorado, decides turnarte cada "
      "noche con Clarence",
      "Despues de largas noches limando el candado por fin consiguen abrir la "
      "ventilación. Ambos suben la escalera para el techo de la carcel. Se dan "
      "cuenta que hay guardias vigilando y vuelven a la celda",
      "Necesitan la parte más importante del plan, como abandonar la isla. "
      "Clarence propone robar un barco de los guardias"};
  cr_limar.decisiones = {
      "Robar barco de los guardias",
      "Proponer hacer una balsa a base de impermeables y chalecos salvavidas"};

  Escena fin_balsa;
  fin_balsa.narraciones = {
      "Clarence acepta la idea y te elogia por tu inteligencia.",
      "Los días siguientes ambos se dedican a robar impermeables y a fabricar "
      "la "
      "balsa y chalecos salvavidas.",
      "Consiguen crear la balsa y dos chalecos salvavidas. En la noche "
      "siguiente "
      "ambos preparan las cabezas falsas y ponen los respiraderos falsos para "
      "que no noten su ausencia",
      "Suben al techo y saltando varias vallas llegan a la costa de la isla. "
      "Ambos se ponen los chalecos salvavidas y ponen la balsa en el agua. "
      "Logran escapar con exito de Alcatraz sin que ningún guardia lo notara."};

  Escena cr_martillo;
  cr_martillo.narraciones = {
      "Creas un martillo a base de diferentes materiales que hay en la celda. "
      "Golpeas el candado varias veces hasta que lo rompes",
      "Clarence y tu logran subir al techo de la prisión, pero hiciste mucho "
      "ruido y los guardias están en camino. ¿Qué haces?"};
  cr_martillo.decisiones = {"Intentar escapar de todas formas",
                            "Volver a la celda rapidamente"};

  Escena fin_barco;
  fin_barco.narraciones = {
      "Tu y Clarence bajan del tejado saltando varias vallas hasta el muelle "
      "en donde estan los "
      "barcos de los guardias",
      "Hay varios guardias siguiendote pero te subes a un barco con Clarence. "
      "Sin embargo no encuentras las llaves y los guardias ya te rodearon.",
      "Te vuelven a encerrar a ti y a Clarence."};

  Escena cm_celda;
  cm_celda.narraciones = {
      "Tu y Clarence vuelven a la celda y se hacen los dormidos.",
      "Un guardia viene a investigar el fuerte sonido que causo romper el "
      "candado. Entran a tu celda para investigar. Descubre el respiradero "
      "falso pero cuando va llamar a otros guardias, lo golpeas con el "
      "martillo dejandolo inconsciente.",
      "Clarence le roba la tarjeta de policia y todas las llaves que tiene, "
      "junto a su pistola y taser. Te da la pistola y la tarjeta de policia.",
      "La tarjeta de policia permite abrir las celdas, Clarence quiere liberar "
      "a los demás y que haya una guerra contra los guardias"};
  cm_celda.decisiones = {"Aceptar",
                         "Negarle la idea y decir que escapen solo ellos dos"};

  Escena abrir_celdas;
  abrir_celdas.narraciones = {
      "Le abren la celda a los demas reclusos y una alarma empieza a sonar",
      "Varios guardias llegan para controlar las cosas, le disparas a varios "
      "policias desde tu celda y varios reclusos están luchando también.",
      "Sin embargo, vienen muchisimos más guardias con armas pesadas. Te "
      "disparan a ti y a Clarence. Ambos mueren al instante."};

  Escena escapar_barco;
  escapar_barco.narraciones = {
      "Clarence se molesta pero continua contigo. Con la tarjeta y las llaves "
      "logran pasar varias puertas sin ser vistos. Pero un guardia los detiene "
      "en la ultima puerta y le dispara a Clarence. Le disparas al guardia y "
      "cae al piso.",
      "Clarence esta sangrando en el piso y las alarmas se activaron. Tienes "
      "que decidir si dejarlo o no."};
  escapar_barco.decisiones = {"Dejar a Clarence",
                              "Quedarse a defender a Clarence"};

  Escena dejar_clarence;
  dejar_clarence.narraciones = {
      "Decides dejar a Clarence y escapar de la carcel tu solo. Al salir de la "
      "prision varios varios guardias te siguen disparando. Sin embargo, "
      "logras "
      "salir ileso y montarte a un barco.",
      "Usas todas las llaves y logras que el barco encienda, escapando de "
      "Alcatraz con exito y solo..."};

  Escena quedarse_clarence;
  quedarse_clarence.narraciones = {
      "Vienen varios guardias a capturarte. Te piden bajar el arma pero te "
      "niegas. Te disparan varias veces y mueres.",
      "Clarence fue llevado al hospital y sobrevivió."};

  Escena cr_manta;
  cr_manta.narraciones = {
      "A Clarence no le gusta la idea pero acepta",
      "Durante el día un guardia pasa por la celda y observa la manta. Entra a "
      "averiguar y se da cuenta que hay un hueco.",
      "Manda a buscarte y te castigan por tratar de escapar de la carcel y "
      "dañar la celda."};

  Escena fin_llaves;
  fin_llaves.narraciones = {
      "Clarence explica el plan, el cual consiste en llamar a un guardia en la "
      "noche a la celda, robarle las llaves y que tu lo noqueas",
      "Se hace de noche y llamas al guardia, se acerca y le dices que te "
      "sientes enfermo",
      "El guardia abre la puerta. Clarence se pone detras de el y le roba las "
      "llaves.",
      "Intentas noquear al guardia y fallas. Te golpea en la cara y le dispara "
      "con el taser a Clarence, dejandolo inmovil.",
      "El plan falló y te aumentaron el tiempo en la carcel."};

  cr_limar.sig_escenas = {fin_barco, fin_balsa};
  escapar_barco.sig_escenas = {dejar_clarence, quedarse_clarence};

  cm_celda.sig_escenas = {abrir_celdas, escapar_barco};
  cr_martillo.sig_escenas = {fin_barco, cm_celda};

  cr_carton.sig_escenas = {cr_limar, cr_martillo};

  c_respiradero.sig_escenas = {cr_carton, cr_manta};

  Clarence.sig_escenas = {c_respiradero, fin_llaves};
  

  c_trepar1.sig_escenas = {fin_robarbarco,fin_nadar2};
  
  c_balsa.sig_escenas = {fin_cortar1,c_trepar1};
  
  c_pagar.sig_escenas = {c_balsa,fin_nadar1};
  
  c_crear.sig_escenas = {c_pagar,fin_robar};
    
  c_sabana.sig_escenas = {c_crear,fin_robar};
  

  c_cortar2.sig_escenas = {fin_nadar3,fin_robarbarco2};

  c_verdes.sig_escenas = {c_cortar2,c_cortar2};

  c_rojas.sig_escenas = {c_verdes,fin_rojas};

  esperar.sig_escenas = {c_verdes,c_rojas};
  
  Solitario.sig_escenas = {c_sabana, esperar};

  inicio.sig_escenas = {Solitario, Clarence};

  return inicio;
}

#endif
