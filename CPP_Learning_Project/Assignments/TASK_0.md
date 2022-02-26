# Se familiariser avec l'existant

## A- Exécution

Compilez et lancez le programme.

Allez dans le fichier `tower_sim.cpp` et recherchez la fonction responsable de gérer les inputs du programme.

La fonction responsable de la gestion des inputs du programme est "TowerSimulation::create_keystrokes()".

Sur quelle touche faut-il appuyer pour ajouter un avion ? Il faut appuyer sur la touche "c".
Comment faire pour quitter le programme ? Il faut appuyer sur la touche "X" ou "Q".
A quoi sert la touche 'F' ? Elle sert à passer en mode plein écran.

Ajoutez un avion à la simulation et attendez.
Quel est le comportement de l'avion ? L'avion commence par atterrir et va se garer au terminal, et ensuite il reprend son service et ainsi de suite.
Quelles informations s'affichent dans la console ?
Les informations qui s'affichent dans la console sont:
-les informations sur l'atterissage et décollage des avions.
-les informations sur la fin et reprise de service des avions.

Ajoutez maintenant quatre avions d'un coup dans la simulation.
Que fait chacun des avions ?
Les avions ont le même comportement sauf que si les trois terminals sont occupés, l'avion restant continuera de voler jusqu'à liberation d'un des terminals.

## B- Analyse du code

Listez les classes du programme à la racine du dossier src/.
Pour chacune d'entre elle, expliquez ce qu'elle représente et son rôle dans le programme.
-Aircraft-> Représente un avion, elle peut dessiner un avion, le faire se déplacer et d'avoir les propritétés de l'avion.
-Airport-> Représente un aéroport, elle permet de créer un aéroport avec une liste de terminal et une tour de contrôle.
-AirportType-> Représente le type d'un aéroport, contient les coordonnées importantes du centre de chaque aéroport comme le début et la fin des runways. Chaque AirportType peut générer des chemins pour atterrir et décoller.
-AircraftTypes-> Représente le type d'un avion, elle stocke les limites de vitesse et d'accélération mais aussi de la texture.
Il y a 3 types prédéfinis.
-Terminal -> Représente un terminal, elle gère le débarquement d'un avion, chaque terminal ne peut gérer le débarquement que d'un seul avion à la fois.
-TowerSimulation-> Classe qui s'occupe de la gestion de la simulation (création de l'aéroport, création des avions etc.).
-Tower-> Représente la tour de contrôle. S'occupe de donner des instructions aux avions (par exemple si un terminal est libre, Tower donne l'autorisation à un avion d'atterir etc.).
-Waypoint-> Représente un point du chemin d'un avion, c'est un Point3D contenant l'information de si ce point se trouve au sol, sur un terminal ou en l'air.
-Displayable-> Classe abstraite qui forme la base pour tous les objets pouvant être affichés sur l'écran.
-DynamicObject-> Classe abstraite qui forme la base de tous les objets pouvant se déplacer.
-Texture2D-> Représente une texture qui sera affichée avec Texture2D::draw.
-Image-> Classe permettant la gestion des octets d'une image dans la mémoire qui sera utilisé par Texture2D.
-MediaPath-> Classe permettant de gérer l'accès aux PNG.


Pour les classes `Tower`, `Aircaft`, `Airport` et `Terminal`, listez leurs fonctions-membre publiques et expliquez précisément à quoi elles servent.

Aircraft:
    -get_flight_num: renvoie l'identifiant du vol.
    -distance_to: renvoie la distance de l'avion par rapport à un point.
    -display: affiche l'avion.
    -move: permet de déplacer l'avion.
Airport:
    -get_tower: renvoie la tour de contrôle de l'aéroport.
    -display: affiche l'aéroport.
    -move: met à jour les terminaux de l'aéroport par rapport au contexte.
Terminal:
    -in_use: Permet de savoir si le terminal est utilisé ou pas.
    -is_servicing: Permet de savoir si le terminal a fini l'entretien d'un avion ou non. (vrai si l'entretien n'est pas fini et faux sinon).
    -assign_craft: assigne un avion au terminal et donc ce terminal devient occupé.
    -start_service: commence l'entretien d'un avion (affichage du message "now servicing" suivi de l'identifiant de l'avion).
    -finish_service: libere le terminal une fois l'entretien de l'avion fini.
    -move: permet d'actualisation du terminal.
Tower:
    -get_instructions: elle décide du chemin que doit suivre un avion et enregistre un avion si un des terminaux est libre.
    -arrived_at_terminal: vérifie qu'un avion est bien arrivé à un terminal et lance l'entretien de l'avion.
Réalisez ensuite un schéma présentant comment ces différentes classes intéragissent ensemble.

Quelles classes et fonctions sont impliquées dans la génération du chemin d'un avion ?

Depuis la méthode Aircraft::move() : si WaypointQueue est vide, on fait appel à Tower::get_instruction(). Si l'avion n'est pas dans un terminal, Tower::get_instruction() fait appel à Airport::reserve_terminal qui va reserver un terminal pour l'avion. Si un terminal est libre, Airport::reserve_terminal renvoie une séquence de waypoints jusqu'au terminal libre ainsi que le numéro du terminal, en revanche la fonction renvoie un vector vide et n'importe quel nombre si aucun terminal n'est libre. Cela se fait grâce à l'appel à Terminal::assign_craft() qui va assigner l'avion au terminal correspondant.

Quel conteneur de la librairie standard a été choisi pour représenter le chemin ?
Expliquez les intérêts de ce choix.

une std::deque est utilisée pour représenter le chemin.
les intérêts de ce choix sont que cela permet l'ajout d'éléments à la fin de la queue ainsi la récupération des éléments au début de la queue et tout cela en complexité constante.

## C- Bidouillons !

1) Déterminez à quel endroit du code sont définies les vitesses maximales et accélération de chaque avion.
Le Concorde est censé pouvoir voler plus vite que les autres avions.
Modifiez le programme pour tenir compte de cela.

Elles sont définies dans "aircraft_types.hpp" dans la structure "AircraftType" avec les champs max_ground_speed, max_air_speed, max_accel.
On change les valeurs de l'avion censées représenter l'avion Concorde, de telle sorte que sa vitesse et accélération max soient supérieures à celle des autres avions.

2) Identifiez quelle variable contrôle le framerate de la simulation.
Ajoutez deux nouveaux inputs au programme permettant d'augmenter ou de diminuer cette valeur.
Essayez maintenant de mettre en pause le programme en manipulant ce framerate. Que se passe-t-il ?\
Ajoutez une nouvelle fonctionnalité au programme pour mettre le programme en pause, et qui ne passe pas par le framerate.

La variable qui contrôle le framerate de la simulation est DEFAULT_TICKS_PER_SEC dans le fichier config.hpp.
Le programme crash car une division par 0 est effectuée.


3) Identifiez quelle variable contrôle le temps de débarquement des avions et doublez-le.

La variable qui contrôle le temps de débarquement des avions est SERVICE_CYCLES dans le fichier config.hpp.

4) Lorsqu'un avion a décollé, il réattérit peu de temps après.
Faites en sorte qu'à la place, il soit retiré du programme.\
Indices :\
A quel endroit pouvez-vous savoir que l'avion doit être supprimé ?Dans la fonction timer de opengl_interface. 

Pourquoi n'est-il pas sûr de procéder au retrait de l'avion dans cette fonction ?
Car on risque d'avoir une erreur de segmentation.
A quel endroit de la callstack pourriez-vous le faire à la place ?
Dans la fonction move de dynamic_object. 

Que devez-vous modifier pour transmettre l'information de la première à la seconde fonction ?
un booleen qui renverra false si l'avion doit être retiré.

on ajoute un attribut "service_done" qui indique si l'avion est déja passé par un terminal (ajout dans aircraft.hpp). Il vaudra false au départ et passera à True dans Tower::get_instruction apres service effectué.

5) Lorsqu'un objet de type `Displayable` est créé, il faut ajouter celui-ci manuellement dans la liste des objets à afficher.
Il faut également penser à le supprimer de cette liste avant de le détruire.
Faites en sorte que l'ajout et la suppression de `display_queue` soit "automatiquement gérée" lorsqu'un `Displayable` est créé ou détruit.

On modifie le constructeur et le destructeur de Displayable pour respectivement ajouter des objets qui doivent être afficher à la display_queue mais aussi supprimer des objets contenus dans cette même display_queue.
On rend le champs display_queue static pour pouvoir y accéder depuis le constructeur et le destructeur de la classe Displayable.

Pourquoi n'est-il pas spécialement pertinent d'en faire de même pour `DynamicObject` ?

Parceque les objets qui sont des DynamicObject sont aussi des objets Displayable (Aircraft et Airport étendent DynamicObject et Displayable).

6) La tour de contrôle a besoin de stocker pour tout `Aircraft` le `Terminal` qui lui est actuellement attribué, afin de pouvoir le libérer une fois que l'avion décolle.
Cette information est actuellement enregistrée dans un `std::vector<std::pair<const Aircraft*, size_t>>` (size_t représentant l'indice du terminal).
Cela fait que la recherche du terminal associé à un avion est réalisée en temps linéaire, par rapport au nombre total de terminaux.
Cela n'est pas grave tant que ce nombre est petit, mais pour préparer l'avenir, on aimerait bien remplacer le vector par un conteneur qui garantira des opérations efficaces, même s'il y a beaucoup de terminaux.\
Modifiez le code afin d'utiliser un conteneur STL plus adapté. Normalement, à la fin, la fonction `find_craft_and_terminal(const Aicraft&)` ne devrait plus être nécessaire.

On utilisera comme conteneur STL std::map<const Aircraft*,size_t> plutot que std::vector<std::pair<const Aircraft*,size_t>>.
Ce conteneur contiendra pour chaque avion l'index du terminal qui lui est associé, les accès se font en complexité O(1).

## D- Théorie

1) Comment a-t-on fait pour que seule la classe `Tower` puisse réserver un terminal de l'aéroport ?

2) En regardant le contenu de la fonction `void Aircraft::turn(Point3D direction)`, pourquoi selon-vous ne sommes-nous pas passer par une réference ?
Pensez-vous qu'il soit possible d'éviter la copie du `Point3D` passé en paramètre ?

## E- Bonus

Le temps qui s'écoule dans la simulation dépend du framerate du programme.
La fonction move() n'utilise pas le vrai temps. Faites en sorte que si.
Par conséquent, lorsque vous augmentez le framerate, la simulation s'exécute plus rapidement, et si vous le diminuez, celle-ci s'exécute plus lentement.

Dans la plupart des jeux ou logiciels que vous utilisez, lorsque le framerate diminue, vous ne le ressentez quasiment pas (en tout cas, tant que celui-ci ne diminue pas trop).
Pour avoir ce type de résultat, les fonctions d'update prennent généralement en paramètre le temps qui s'est écoulé depuis la dernière frame, et l'utilise pour calculer le mouvement des entités.

Recherchez sur Internet comment obtenir le temps courant en C++ et arrangez-vous pour calculer le dt (delta time) qui s'écoule entre deux frames.
Lorsque le programme tourne bien, celui-ci devrait être quasiment égale à 1/framerate.
Cependant, si le programme se met à ramer et que la callback de glutTimerFunc est appelée en retard (oui oui, c'est possible), alors votre dt devrait être supérieur à 1/framerate.

Passez ensuite cette valeur à la fonction `move` des `DynamicObject`, et utilisez-la pour calculer les nouvelles positions de chaque avion.
Vérifiez maintenant en exécutant le programme que, lorsque augmentez le framerate du programme, vous n'augmentez pas la vitesse de la simulation.

Ajoutez ensuite deux nouveaux inputs permettant d'accélérer ou de ralentir la simulation.
