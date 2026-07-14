#include "EscapeStory.h"

#include <utility>

namespace {

ScenePtr make_scene(std::vector<std::string> narrations,
                    std::vector<std::string> decisions)
{
    auto scene = std::make_shared<Scene>();
    scene->set_narrations(std::move(narrations));
    scene->set_decisions(std::move(decisions));
    return scene;
}

ScenePtr make_ending(std::vector<std::string> narrations)
{
    return make_scene(std::move(narrations), {});
}

void link(ScenePtr parent, std::vector<ScenePtr> children)
{
    parent->set_next_scenes(std::move(children));
}

}

ScenePtr build_escape_story(Language lang)
{
    auto t = [&](const char* es, const char* en) -> std::string {
        return lang == Language::Spanish ? std::string(es) : std::string(en);
    };

    auto inicio = make_scene({
        t("Eres Frank Morris, un prisionero genio de 35 anos en Alcatraz, una "
          "prision de maxima seguridad en una isla remota. Eres conocido "
          "por tus habilidades excepcionales. Estas cansado de estar encerrado por "
          "lo que decides llevar a cabo un audaz plan de escape. Cada eleccion que "
          "tomes sera crucial para el exito de tu fuga.\n",

          "You are Frank Morris, a 35-year-old genius inmate at Alcatraz, a "
          "maximum security prison on a remote island. You are known for your "
          "exceptional skills. Tired of being locked up, you decide to carry out "
          "a daring escape plan. Every choice you make will be crucial to your "
          "success.\n"),

        t("Estas ideando un plan para escapar pero te haces la pregunta de si "
          "necesitas un companero de escape",

          "You are planning your escape, but you ask yourself if you need an "
          "escape partner"),

        t("Miras a Clarence, un tipo creativo, es conocido por sus "
          "distintas fugas en las diferentes carceles por las que paso",

          "You look at Clarence, a creative guy known for his many escapes in "
          "the different prisons he has been through"),

        t("decides ir en solitario o prefieres escapar con Clarence?",

          "Do you go solo or do you prefer to escape with Clarence?")
    }, {
        t("Solitario", "Solo"),
        t("Clarence", "Clarence")
    });

    auto Solitario = make_scene({
        t("Confias en tu ingenio y en tus habilidades por lo "
          "que decides hacer el escape en solitario",

          "You trust your ingenuity and skills, so you decide to escape solo"),

        t("Te pones a pensar formas de como salir de tu celda, la unica manera es "
          "por la ventana de barrotes",

          "You think about how to get out of your cell. The only way is through "
          "the barred window"),

        t("Un dia notas que los demas presos colgaban sabanas en sus celdas "
          "cuando los pasillos estaban llenos de personas ",

          "One day you notice that other inmates hang sheets in their cells "
          "when the hallways are crowded"),

        t("decides hacer una prueba poniendo tu sabana de tal forma que tape lo "
          "que estas haciendo o prefieres esperar otra manera de escape?",

          "Do you test by hanging your sheet to cover what you are doing, or do "
          "you wait for another way to escape?")
    }, {
        t("Poner sabana", "Hang the sheet"),
        t("esperar otra opcion de escape", "Wait for another escape option")
    });

    auto c_sabana = make_scene({
        t("Los guardias se acostumbran a ver tu sabana, por lo "
          "que no te ponen problema",

          "The guards get used to seeing your sheet, so they don't give you "
          "trouble"),

        t("Ahora necesitas un destornillador. Como decides obtenerlo?",

          "Now you need a screwdriver. How do you get it?")
    }, {
        t("Utilizar metal para crearlo", "Use metal to make one"),
        t("robarlo del area de metales", "Steal it from the metal shop")
    });

    auto c_crear = make_scene({
        t("Decides crear tu propio destornillador",

          "You decide to make your own screwdriver"),

        t("Utilizas unas hojas de acero para crear el destornillador "
          "y darle forma",

          "You use steel sheets to shape the screwdriver"),

        t("logras quitar con el destornillador la primera parte de la ventana",

          "You manage to remove the first part of the window with the "
          "screwdriver"),

        t("tienes que cortar la segunda parte con una hoja de sierra",

          "You need to cut the second part with a saw blade"),

        t("como la consigues?",

          "How do you get it?")
    }, {
        t("le pagas a un guardia para que te la consiga",
          "Bribe a guard to get it for you"),
        t("la robas del area de metales", "Steal it from the metal shop")
    });

    auto fin_robar = make_ending({
        t("Un dia en el que estas en el area de metales, intentas meter la "
          "herramienta en tu ropa interior",

          "One day at the metal shop, you try to hide the tool in your "
          "underwear"),

        t("en el momento que vas a salir suena el detector de metales, y eres "
          "descubierto",

          "As you are about to leave, the metal detector goes off and you are "
          "discovered"),

        t("te requisan, te hacen quitar la ropa y finalmente descubren el objeto",

          "They search you, make you take off your clothes, and find the "
          "object"),

        t("eres castigado y llevado a tu celda de vuelta ",

          "You are punished and taken back to your cell")
    });

    auto c_pagar = make_scene({
        t("Decides sobornar al guardia",

          "You decide to bribe the guard"),

        t("el acepta tu suborno y te trae la hoja de sierra",

          "He accepts the bribe and brings you the saw blade"),

        t("ya tienes la forma de escapar de tu celda",

          "Now you have a way to escape your cell"),

        t("tienes que pensar como salir de la isla una vez pasada la reja",

          "You need to figure out how to leave the island once past the gate"),

        t("Recuerdas haber visto sacos en un cuarto de lavanderia, "
          "con estos puedes hacer una balsa para poder pasar a la isla, "
          "tambien tienes la opcion de atravesarla nadando. "
          "cual decides?",

          "You remember seeing sacks in a laundry room. You can use them to "
          "build a raft to cross to the mainland, or you can try swimming. "
          "Which do you choose?")
    }, {
        t("Hacer la balsa", "Build the raft"),
        t("Arriesgarte y pasarla nadando", "Risk it and swim across")
    });

    auto c_balsa = make_scene({
        t("Llega el dia en el que vas a salir de tu celda",

          "The day to leave your cell has come"),

        t("coges el destornillador, y abres la primera parte de la ventana",

          "You grab the screwdriver and open the first part of the window"),

        t("coges la hoja de sierra y cortas la segunda parte de la ventana, "
          "logras salir al patio",

          "You take the saw blade and cut the second part of the window, "
          "making it to the yard"),

        t("te encuentras con una reja de 5 metros de altura",

          "You come across a 5-meter high fence"),

        t("tienes las siguientes opciones para pasar el obstaculo",

          "You have the following options to get past it")
    }, {
        t("cortar la reja con la sierra con riesgo de hacer ruido y ser "
          "descubierto",

          "Cut the fence with the saw, risking noise and discovery"),
        t("trepar la reja pero dejar la balsa y tener que buscar otra forma "
          "de atravesar la isla",

          "Climb the fence but leave the raft behind and find another way "
          "across the island")
    });

    auto fin_nadar1 = make_ending({
        t("Llega el dia en el que vas a salir de tu celda",

          "The day to leave your cell has come"),

        t("coges el destornillador, y abres la primera parte de la ventana ",

          "You grab the screwdriver and open the first part of the window"),

        t("coges la hoja de sierra y cortas la segunda parte de la ventana, "
          "logras salir al patio ",

          "You take the saw blade and cut the second part, making it to the "
          "yard"),

        t("te encuentras con una reja de 5 metros de altura",

          "You come across a 5-meter high fence"),

        t("decides cortar la reja con la sierra y nadar hasta la costa ",

          "You decide to cut the fence and swim to the coast"),

        t("mueres ahogado y eres devorado por los tiburones",

          "You drown and are devoured by sharks")
    });

    auto fin_cortar1 = make_ending({
        t("Logras cortar la reja sin que se den cuenta los guardias",

          "You cut the fence without the guards noticing"),

        t("utilizas la balsa previamente hecha con los sacos",

          "You use the raft you previously made from the sacks"),

        t("emprendes tu viaje hacia tu libertad",

          "You begin your journey to freedom"),

        t("pero en medio del trayecto, unos guardias que iban en barco te "
          "encuentran y te vuelven a encerrar",

          "But halfway through, guards on a boat find you and take you back"),

        t("te dan 50 anos mas por el intento de fuga y "
          "quedas encerrado de por vida en Alcatraz",

          "You get 50 more years added to your sentence and remain locked up "
          "in Alcatraz for life")
    });

    auto c_trepar1 = make_scene({
        t("Logras trepar el obstaculo de la reja pero tuviste que dejar la "
          "balsa, ves que unos guardias dejan su barco en la costa un momento "
          "para descansar. Tienes las siguientes opciones",

          "You climb the fence but had to leave the raft behind. You see some "
          "guards leave their boat on the shore for a moment to rest. You "
          "have the following options")
    }, {
        t("robar el barco", "Steal the boat"),
        t("irte nadando a la costa", "Swim to the coast")
    });

    auto fin_robarbarco = make_ending({
        t("Logras robar el barco y consigues tu libertad. "
          "haz completado tu objetivo, "
          "lo siguiente es escapar de la persecusion, "
          "esto ya no es nuestro problema, "
          "suerte con eso",

          "You steal the boat and gain your freedom. You have completed your "
          "objective. Escaping the pursuit is your next problem. Good luck "
          "with that")
    });

    auto fin_nadar2 = make_ending({
        t("Decides irte nadando hacia la costa",

          "You decide to swim to the coast"),

        t("No tienes suerte en tu intento de escape",

          "You have no luck in your escape attempt"),

        t("te ahogas y te devoran los tiburones",

          "You drown and are devoured by sharks")
    });

    auto esperar = make_scene({
        t("Decides esperar otra opcion de escape",

          "You decide to wait for another escape option"),

        t("pasan los dias. Te fijas que las cerraduras de las puertas "
          "tienen dos puntos de colores, unas son verdes y otras son rojas",

          "Days pass. You notice the door locks have two colored dots, some "
          "are green and others are red"),

        t("tienes que escoger una llave para poder replicarla, cual escoges?",

          "You need to pick a key to replicate. Which do you choose?")
    }, {
        t("llave verde", "Green key"),
        t("llave roja", "Red key")
    });

    auto c_verdes = make_scene({
        t("Logras replicar la llave para las puertas verdes",

          "You manage to replicate the key for green doors"),

        t("decides comenzar tu plan de escape abriendo las puertas uno y dos "
          "y logras salir",

          "You start your escape plan by opening doors one and two, making "
          "your way out"),

        t("te encuentras con una reja de 5 metros. que decides hacer?",

          "You come across a 5-meter fence. What do you do?")
    }, {
        t("cortar la reja", "Cut the fence"),
        t("trepar la reja", "Climb the fence")
    });

    auto c_cortar2 = make_scene({
        t("Logras pasar la reja",

          "You get past the fence"),

        t("Ahora te encuentras con el problema de como salir de la isla",

          "Now you face the problem of how to leave the island"),

        t("a lo lejos se ve que se acerca lentamente un barco de guardias, "
          "te escondes para que no te vean",

          "In the distance you see a guard boat approaching slowly. You hide "
          "so they don't see you"),

        t("Los guardias se bajan del barco para buscar porque les avisaron "
          "de unos ruidos por esa zona. tienes las siguientes opciones a "
          "realizar",

          "The guards get off the boat to investigate because they were "
          "alerted of noises in the area. You have the following options")
    }, {
        t("Dejar pasar la oportunidad e irte nadando",
          "Let the opportunity pass and swim"),
        t("robar el barco arriesgandote a que te capturen o que te disparen",
          "Steal the boat, risking capture or being shot")
    });

    auto fin_nadar3 = make_ending({
        t("Decides dejar pasar la oportunidad "
          "e irte nadando hacia la costa",

          "You decide to let the opportunity pass and swim to the coast"),

        t("tienes suerte y llegaste al otro lado",

          "You get lucky and make it to the other side"),

        t("estas en libertad",

          "You are free")
    });

    auto fin_robarbarco2 = make_ending({
        t("Decides robar el barco de los guardias "
          "antes de que te subas uno de los guardias te nota",

          "You decide to steal the guard boat. Before you can board, one of "
          "the guards notices you"),

        t("es un novato por lo que el miedo se apodera de el y "
          "te dispara",

          "He is a rookie and fear takes over. He shoots you"),

        t("caes muerto al mar no has logrado tu objetivo",

          "You fall dead into the sea. You did not achieve your goal")
    });

    auto c_rojas = make_scene({
        t("Notas que hay muy pocas puertas rojas",

          "You notice there are very few red doors"),

        t("Posiblemente no puedas escapar replicando la llave "
          "de las puertas rojas",

          "You might not be able to escape by replicating the red door key"),

        t("quieres seguir replicando la llave roja o empiezas a crear "
          "la verde?",

          "Do you keep working on the red key or start making the green one?")
    }, {
        t("crear la llave de las puertas verdes",
          "Make the green door key"),
        t("seguir haciendo la llave", "Keep working on the red key")
    });

    auto fin_rojas = make_ending({
        t("Logras recrear la llave de las puertas rojas",

          "You manage to recreate the red door key"),

        t("Decides empezar a hacer tu plan de escape",

          "You decide to start your escape plan"),

        t("pasas una puerta que se abria con la puerta roja, pasas a la "
          "segunda y te das cuenta que no se puede abrir con la roja "
          "de la desesperacion intentas abrirla pero "
          "un guardia te escucha y eres recapturado",

          "You pass through a door that opens with the red key. At the second "
          "door you realize it won't open with the red key. In desperation you "
          "try to force it, but a guard hears you and you are recaptured"),

        t("no logras tu libertad",

          "You do not gain your freedom")
    });

    auto Clarence = make_scene({
        t("Escoges a Clarence como companero de escape",

          "You choose Clarence as your escape partner"),

        t("Te acercas a Clarence y le preguntas si quiere escapar. "
          "El acepta.",

          "You approach Clarence and ask if he wants to escape. He accepts."),

        t("Ambos van a hablar a tu celda. Le cuentas que el respiradero "
          "de la celda esta suelto. Pero el propone robarle las llaves "
          "a un guardia",

          "You both go to your cell. You tell him the cell vent is loose, "
          "but he suggests stealing a guard's keys instead")
    }, {
        t("Proponer romper el respiradero",
          "Suggest breaking the vent"),
        t("Aceptar robarle las llaves a un guardia",
          "Agree to steal the guard's keys")
    });

    auto c_respiradero = make_scene({
        t("Clarence acepta la idea y te cuenta sobre robar cucharas y hacer "
          "herramientas caseras para terminar de soltar el respiradero",

          "Clarence agrees and tells you about stealing spoons to make "
          "homemade tools to fully loosen the vent"),

        t("Despues de varios dias ya tienen varias herramientas y sueltan "
          "el respiradero. El hueco es del tamano para que una persona "
          "pueda pasar",

          "After several days you have enough tools and loosen the vent. "
          "The hole is big enough for a person to fit through"),

        t("Pero deben buscar la manera de ocultarlo para que los guardias "
          "no se den cuenta",

          "But you need to hide it so the guards don't notice"),

        t("Clarence propone hacer un respiradero de carton, pintandolo "
          "de forma exacta.",

          "Clarence suggests making a cardboard vent, painting it to look "
          "exact")
    }, {
        t("Aceptar la idea", "Accept the idea"),
        t("Propones taparlo con una manta",
          "Suggest covering it with a blanket")
    });

    auto cr_carton = make_scene({
        t("Clarence se dedica a hacer un respiradero de carton y a "
          "pintarlo durante el dia",

          "Clarence spends the day making a cardboard vent and painting it"),

        t("Mientras tu buscas la manera de entrar al hueco por la noche "
          "sin que se den cuenta de tu ausencia. Clarence propone hacer "
          "cabezas falsas con pelo de la peluqueria.",

          "Meanwhile you figure out how to enter the hole at night without "
          "being noticed. Clarence suggests making fake heads with hair from "
          "the barbershop."),

        t("En la noche logran tapar el respiradero con uno falso y hacen "
          "sus cabezas falsas.",

          "At night you cover the vent with a fake one and make your dummy "
          "heads"),

        t("Deciden entrar al hueco para investigar mas. Encuentran una "
          "ventilacion por la que pueden pasar al techo",

          "You decide to enter the hole to investigate further. You find a "
          "ventilation shaft that leads to the roof"),

        t("Pero esta con candado, Clarence propone limar el candado",

          "But it has a padlock. Clarence suggests filing it off")
    }, {
        t("Limar el candado", "File the padlock"),
        t("Proponer romper el candado con un martillo",
          "Suggest breaking the padlock with a hammer")
    });

    auto cr_limar = make_scene({
        t("Empiezas a limar el candado pero es muy demorado, decides "
          "turnarte cada noche con Clarence",

          "You start filing the padlock but it takes long. You take turns "
          "each night with Clarence"),

        t("Despues de largas noches limando el candado por fin consiguen "
          "abrir la ventilacion. Ambos suben la escalera para el techo de "
          "la carcel. Se dan cuenta que hay guardias vigilando y vuelven "
          "a la celda",

          "After long nights of filing, you finally open the ventilation "
          "shaft. Both of you climb to the prison roof, but see guards "
          "watching and go back to the cell"),

        t("Necesitan la parte mas importante del plan, como abandonar la "
          "isla. Clarence propone robar un barco de los guardias",

          "You need the most important part of the plan - how to leave the "
          "island. Clarence suggests stealing a guard boat")
    }, {
        t("Robar barco de los guardias",
          "Steal the guard boat"),
        t("Proponer hacer una balsa a base de impermeables y chalecos "
          "salvavidas",

          "Suggest building a raft from raincoats and life vests")
    });

    auto fin_balsa = make_ending({
        t("Clarence acepta la idea y te elogia por tu inteligencia.",

          "Clarence agrees and praises your intelligence."),

        t("Los dias siguientes ambos se dedican a robar impermeables y a "
          "fabricar la balsa y chalecos salvavidas.",

          "In the following days you both steal raincoats and build the raft "
          "and life vests."),

        t("Consiguen crear la balsa y dos chalecos salvavidas. En la noche "
          "siguiente ambos preparan las cabezas falsas y ponen los "
          "respiraderos falsos para que no noten su ausencia",

          "You finish the raft and two life vests. The next night you prepare "
          "the dummy heads and fake vents so no one notices your absence"),

        t("Suben al techo y saltando varias vallas llegan a la costa de la "
          "isla. Ambos se ponen los chalecos salvavidas y ponen la balsa "
          "en el agua. Logran escapar con exito de Alcatraz sin que ningun "
          "guardia lo notara.",

          "You climb to the roof and jump several fences to reach the island "
          "shore. Both of you put on the life vests and launch the raft. "
          "You successfully escape Alcatraz without any guard noticing.")
    });

    auto cr_martillo = make_scene({
        t("Creas un martillo a base de diferentes materiales que hay en "
          "la celda. Golpeas el candado varias veces hasta que lo rompes",

          "You make a hammer from various materials in the cell. You strike "
          "the padlock several times until it breaks"),

        t("Clarence y tu logran subir al techo de la prision, pero hiciste "
          "mucho ruido y los guardias estan en camino. Que haces?",

          "You and Clarence reach the prison roof, but you made too much "
          "noise and guards are coming. What do you do?")
    }, {
        t("Intentar escapar de todas formas",
          "Try to escape anyway"),
        t("Volver a la celda rapidamente",
          "Go back to the cell quickly")
    });

    auto fin_barco = make_ending({
        t("Tu y Clarence bajan del tejado saltando varias vallas hasta el "
          "muelle en donde estan los barcos de los guardias",

          "You and Clarence jump several fences down to the dock where the "
          "guard boats are"),

        t("Hay varios guardias siguiendote pero te subes a un barco con "
          "Clarence. Sin embargo no encuentras las llaves y los guardias "
          "ya te rodearon.",

          "Several guards are chasing you but you board a boat with Clarence. "
          "However, you can't find the keys and the guards have surrounded "
          "you."),

        t("Te vuelven a encerrar a ti y a Clarence.",

          "You and Clarence are locked up again.")
    });

    auto cm_celda = make_scene({
        t("Tu y Clarence vuelven a la celda y se hacen los dormidos.",

          "You and Clarence go back to the cell and pretend to be asleep."),

        t("Un guardia viene a investigar el fuerte sonido que causo romper "
          "el candado. Entran a tu celda para investigar. Descubre el "
          "respiradero falso pero cuando va llamar a otros guardias, lo "
          "golpeas con el martillo dejandolo inconsciente.",

          "A guard comes to investigate the noise. He enters your cell and "
          "finds the fake vent, but as he goes to call other guards, you hit "
          "him with the hammer, knocking him out."),

        t("Clarence le roba la tarjeta de policia y todas las llaves que "
          "tiene, junto a su pistola y taser. Te da la pistola y la "
          "tarjeta de policia.",

          "Clarence steals the guard's badge, keys, gun, and taser. He gives "
          "you the gun and the badge."),

        t("La tarjeta de policia permite abrir las celdas, Clarence quiere "
          "liberar a los demas y que haya una guerra contra los guardias",

          "The badge can open cells. Clarence wants to free the others and "
          "start a war against the guards")
    }, {
        t("Aceptar", "Accept"),
        t("Negarle la idea y decir que escapen solo ellos dos",
          "Refuse and say they should escape alone")
    });

    auto abrir_celdas = make_ending({
        t("Le abren la celda a los demas reclusos y una alarma empieza a "
          "sonar",

          "You open the cells for the other inmates and an alarm starts "
          "blaring"),

        t("Varios guardias llegan para controlar las cosas, le disparas a "
          "varios policias desde tu celda y varios reclusos estan luchando "
          "tambien.",

          "Guards arrive to take control. You shoot at several officers "
          "while inmates fight alongside you."),

        t("Sin embargo, vienen muchisimos mas guardias con armas pesadas. "
          "Te disparan a ti y a Clarence. Ambos mueren al instante.",

          "But many more guards arrive with heavy weapons. They shoot you "
          "and Clarence. Both die instantly.")
    });

    auto escapar_barco = make_scene({
        t("Clarence se molesta pero continua contigo. Con la tarjeta y las "
          "llaves logran pasar varias puertas sin ser vistos. Pero un "
          "guardia los detiene en la ultima puerta y le dispara a Clarence. "
          "Le disparas al guardia y cae al piso.",

          "Clarence is upset but continues with you. Using the badge and "
          "keys you pass several doors unseen. But a guard stops you at the "
          "last door and shoots Clarence. You shoot the guard and he falls."),

        t("Clarence esta sangrando en el piso y las alarmas se activaron. "
          "Tienes que decidir si dejarlo o no.",

          "Clarence is bleeding on the floor and alarms are going off. You "
          "must decide whether to leave him.")
    }, {
        t("Dejar a Clarence", "Leave Clarence"),
        t("Quedarse a defender a Clarence",
          "Stay and defend Clarence")
    });

    auto dejar_clarence = make_ending({
        t("Decides dejar a Clarence y escapar de la carcel tu solo. Al "
          "salir de la prision varios guardias te siguen disparando. "
          "Sin embargo, logras salir ileso y montarte a un barco.",

          "You leave Clarence and escape the prison alone. As you exit, "
          "several guards shoot at you. Yet you make it out unharmed and "
          "board a boat."),

        t("Usas todas las llaves y logras que el barco encienda, escapando "
          "de Alcatraz con exito y solo...",

          "You try all the keys and manage to start the boat, escaping "
          "Alcatraz successfully and alone...")
    });

    auto quedarse_clarence = make_ending({
        t("Vienen varios guardias a capturarte. Te piden bajar el arma "
          "pero te niegas. Te disparan varias veces y mueres.",

          "Several guards come to capture you. They order you to drop your "
          "weapon but you refuse. You are shot multiple times and die."),

        t("Clarence fue llevado al hospital y sobrevivio.",

          "Clarence was taken to the hospital and survived.")
    });

    auto cr_manta = make_ending({
        t("A Clarence no le gusta la idea pero acepta",

          "Clarence does not like the idea but accepts"),

        t("Durante el dia un guardia pasa por la celda y observa la manta. "
          "Entra a averiguar y se da cuenta que hay un hueco.",

          "During the day a guard passes by the cell and notices the "
          "blanket. He enters to check and finds the hole."),

        t("Manda a buscarte y te castigan por tratar de escapar de la "
          "carcel y danar la celda.",

          "He calls for backup and you are punished for attempting to "
          "escape and damaging the cell.")
    });

    auto fin_llaves = make_ending({
        t("Clarence explica el plan, el cual consiste en llamar a un "
          "guardia en la noche a la celda, robarle las llaves y que tu "
          "lo noqueas",

          "Clarence explains the plan: call a guard to the cell at night, "
          "steal his keys, and you knock him out"),

        t("Se hace de noche y llamas al guardia, se acerca y le dices "
          "que te sientes enfermo",

          "Night falls. You call the guard over and tell him you feel sick"),

        t("El guardia abre la puerta. Clarence se pone detras de el y "
          "le roba las llaves.",

          "The guard opens the door. Clarence gets behind him and steals "
          "the keys."),

        t("Intentas noquear al guardia y fallas. Te golpea en la cara y "
          "le dispara con el taser a Clarence, dejandolo inmovil.",

          "You try to knock out the guard but fail. He punches you and "
          "tases Clarence, leaving him immobilized."),

        t("El plan fallo y te aumentaron el tiempo en la carcel.",

          "The plan failed and your sentence was extended.")
    });

    link(c_trepar1, {fin_robarbarco, fin_nadar2});
    link(c_balsa, {fin_cortar1, c_trepar1});
    link(c_pagar, {c_balsa, fin_nadar1});
    link(c_crear, {c_pagar, fin_robar});
    link(c_sabana, {c_crear, fin_robar});
    link(c_cortar2, {fin_nadar3, fin_robarbarco2});
    link(c_verdes, {c_cortar2, c_cortar2});
    link(c_rojas, {c_verdes, fin_rojas});
    link(esperar, {c_verdes, c_rojas});
    link(Solitario, {c_sabana, esperar});
    link(inicio, {Solitario, Clarence});
    link(Clarence, {c_respiradero, fin_llaves});
    link(c_respiradero, {cr_carton, cr_manta});
    link(cr_carton, {cr_limar, cr_martillo});
    link(cr_limar, {fin_barco, fin_balsa});
    link(cr_martillo, {fin_barco, cm_celda});
    link(cm_celda, {abrir_celdas, escapar_barco});
    link(escapar_barco, {dejar_clarence, quedarse_clarence});

    return inicio;
}
