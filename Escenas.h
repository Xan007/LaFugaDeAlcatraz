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

      "Estas ideando un plan pero para esto necesitas un compañero de escape.",
      "Miras a John, un hombre meticuloso, es conocido por sus fugas en "
      "carceles anteriores",
      "ademas es un preso designado al area cocina",
      "Al lado de el está Clarence, un tipo creativo, es conocido por usar "
      "distintas maneras de robar bancos de forma creativa"};
  inicio.decisiones = {"John", "Clarence"};

  Escena John;
  John.narraciones = {
      "Escoges a John como compañero de escape",
      "Te acercas a John proponiendole escapar juntos de la carcel. Él acepta "
      "y durantes varios dias conversan sobre las posibilidades que hay",
      "un día en el que estaba preparando la comida para los prisioneros",
      "Jhon ve entrar a un viejo amigo de infancia llamado Diego"
      "el cual se encargaba de traer los alimentos "
      "John le propone la idea de llevarte a ti y a John en uno de "
      "los contenedores donde traen la comida, el amigo acepta ya que le "
      "debia unos favores,"
      "te propone hacer este escape o esperar e idear otro plan "
      "¿que escoges?"};
  John.decisiones = {"Aceptar el plan", "esperar otra opción de escape"};

  Escena c_contenedores;
  c_contenedores.narraciones = {
      "decidiste aceptar este plan de escape por lo que "
      "ahora tienes que escontrar el momento perfecto para hacerlo ",
      "un dia en el que es turno de Diego de traer los alimentos "
      "John te hace la señal para"  
      "que vayas a la cocina, una ves allí ",
      "en el momento de entrar a los contenedores y escapar, entra un "
      "inesperado guardia de seguridad, tienes la opción de golpearlo o "
      "sobornarlo",
      "¿cual escoges?"};
  c_contenedores.decisiones = {"golpear al guardia", "sobornar al guardia"};

  Escena c_esperar;
  c_esperar.narraciones = {
      "Decides esperar otra opción de escape"
      "escuchas a unos guardias hablar sobre el problema de humedad"
      "que presenta la carcel en estos momentos,",
      "por lo que tienes una nueva opcion de escape a traves de cavar un hueco "
      "en la pared,"
      "¿le comentas esto a Jhon con la posibilidad de que uno de los dos quede "
      "encerrado"
      "o decides escapar en solitario con mas posibilidades de exito?"};
  c_esperar.decisiones = {"decirle a john y arriesgarse",
                          "cavar el hueco solo"};

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

  Escena c_llaves;
  c_llaves.narraciones = {
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

  Clarence.sig_escenas = {c_respiradero, c_llaves};

  // c_contenedores = {c_golpear, c_sobornar};
  John.sig_escenas = {c_contenedores, c_esperar};

  inicio.sig_escenas = {John, Clarence};

  return inicio;
}

#endif