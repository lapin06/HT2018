<h1>Séance 1 : 10/12/18 : Début du projet</h1>
<h2> Aujourd'hui nous avons démarré notre projet qui s'intitule "Color Rabbit prediction"</h2>
 <li>
  <ul><h3> Organisation du travail </h3></ul>
     <p>Nous avons découpé les étapes du projet en fonction des séances, pour cela nous nous sommes mis d'accord pour un planning que j'ai ensuite réalisé. Cela m'a prit la moitié de la séance car il est difficile de prévoir le temps que l'on mettra pour chaque étape du code et de la construction, ce planning sera disponible dans /HT2018 </p>
 
 <ul><h3>Cahier des charges</h3></ul>
  <p>Ensuite j'ai réalisé le cahier des charges correspondant au projet, celui-ci sera aussi disponible dans le répertoire principal (temps: 1h15) </p>
  
  <ul><h3> Communication Arduino </h3></ul>
  <p>Dans la dernière demi heure j'ai commencé à faire des recherches sur comment faire parler une carte Arduino, ce qui est une grande partie de notre projet. j'ai trouvé assez rapidement le code relatif à cela, mais pour le réaliser il faut importer la librairie tolkiez, j'ai alors rencontré un problème de compilation avec cette librairie. je résoudrai surement ce problème chez moi ou la séance suivante. L'idée est la suivante: le Lapin et en fait celui qui va parler tout le long du tour ( ce tour n'a pas besoin de d'interactions avec nous pour fonctionner), cela implique qu'il devra lui même désigner quels parties colorier, il dira bonjour etc... </p>
  </li>

<h1>Séance 2 : 17/12/18 : communication arduino avec Sparkfun Voice box shield</h1>
<li>
<ul><h3> Utilisation de Sparkfun Voicebox Shield </h3>
<p> J'ai abandoné l'idée d'utiliser la librairie tolkiez.h qui est une librairie permettant d'écrire un code pour faire parler la carte Arduino avec l'aide d'un haut parleur. En effet je n'arrivais pas à résoudre les problèmes de compilation.

Je suis donc passer au Sparkfun Voicebox qui est composé d'une carte voiceBox, d'une carte arduino et d'un haut parleur. Le but étant de pouvoir faire parler notre lapin avec ce haut parleur, avec lequel on peut mettre une carte mémoire qui va pouvoir mémoriser ce que notre lapin va dire. On a donc besoin de la librairie "software serial" pour parler au SpeakJet (voiceBox). J'ai donc commencer mes recherches et j'ai pu trouver un github qui explique comment se servir de ce voicebox, accompagné d'un code. </p>

<h4> problème de compilation </h4>
<p> J'ai téléchargé le code et j'ai passé du temps à comprendre les différents points de cette voicebox ( par exemple les sorties/entrées RST, RDY,SPK), et à comprendre comment cabler tout cela(nous avions déjà en stock le matériel).
Je me suis ensuite retrouvé face à un problème de compilation de nouveau, cette fois j'ai réussi à comprendre ce problème et j'ai donc cherché une solution. PROBLEME: "narrowing conversion of '200' from 'int' to 'char' inside { }" char permet de prendre des nombres en 7bit (et permet de mettre un signe devant) or dans ma chaine de caractère j'ai des nombres en 8bit ( tous les nombres >=100) j'ai donc trouvé la solution en mettant devant char : unsigned , cela permet d'enlever le bit réservé au signe, donc char est dorénavant en 8bit et peut aller jusqu'a 255. </p>

<p> mais ce n'était pas le seul soucis... en effet je n'arrivais toujours pas à compiler mon programme, alors que sur l'ordinateur de mon binôme , la compilation se faisait sans erreur. j'ai pu résoudre ce problème en téléchargeant la version la plus récente d'Arduino. j'ai testé mon programme en faisant dire à la carte " hello " . Cela fonctionne! </p>

<p> Tout ce temps passé à essayer de résoudre les problèmes de compilation et à re-télécharger Arduino m'a fait perdre un temps précieux. Cependant aillant réussi à faire fonctionner le haut parleur, je pourrai rattraper tout ce temps pendant les vacances en écrivant le code pour faire parler arduino ( un code qu'il faut travailler car chaque lettre ou syllabe est codé d'une manière spéciale, et qui plus est, en anglais) . </p>

<h4> je vous invite à aller voir la vidéo où Spark nous dit bonjour, en clickant sur le lien suivant: <a href="https://www.youtube.com/watch?v=zQq6gc-LgdA"/> Sparkfun hello </h4> </li>

<h1>Travail 1 (hors Séances) : 21/12/18 : Sparkfun et boite des feutres</h1>
<li>
 <ul><h3> Approndissement de la librairie Sparkfun </h3></ul>
 <p> Aujourd'hui je me suis un peu plus penché sur la librairie Sparkfun pour pouvoir comprendre vraiment comment cela fonctionne et pour commencer à coder des phrases en anglais par moi même. Je me suis confrontée à plusieurs soucis, dont le plus gros et que, ce que dis notre carte Arduino et particulèrement inaudible quand on ne connait pas la phrase en anglais... Il faut donc que je cherche si Sparkfun permet aussi de modifier la voix pour éviter cette voix robotique trop métalisée. Le deuxième soucis et que le code permet de coder des prononciations et pas des syllabes, j'ai passé donc énormément de temps pour simplement lui faire dire "Rabbit" (=lapin) car il fallait trouver le code relatif aux lettres ou sons, puis ensuite trouver le code chiffré correspondant. En aillant écrite toutes les phrases que notre arduino doit dire, on s'est rendu compte que cela aller me prendre un temps considérable pour tout coder et d'autant plus que cela sera à peine compréhensible. On se retrouve donc face à une impasse. 
Nous avons pensé à une possibilité et nous demanderont la faisabilité de celle-ci par mail:
   Enregistrer nous même nos voix car nous avons la possiblité de mettre une carte mémoire sur Sparkfun. </p>

 <ul><h3> Schema de la boite de feutre </h3></ul>  
 <p> Aujourd'hui nous avons pris la décision de faire la maquette de la boite de feutre étant donné que le code des capteurs était fait.
 Nous avons donc réalisé deux schémas car nous ne savions pas si nous devions faire une boite ronde ou carré ( l'avantage de la boite ronde était que celle-ci faisait plus naturellement pot de feutre). Vous pouvez voir les schemas ci-dessous avec les dimensions prises:
 
 <img src= ../Ressources/schema_boite_feutre_rectangle.JPG>
 <img src= ../Ressources/schema_boite_feutre_ronde.JPG>
 <img src= ../Ressources/schema_boite_feutre_ronde_2.JPG> </p>
 
 <ul><h3> fabrication de la maquette de la boite de feutre </h3></ul> 
 <p> Nous nous sommes renseigné hier pour savoir où réaliser notre maquette, par chance le gérant de l'atelier avait un créneau pour nous aujourd'hui. Nous sommes donc allé aux Templiers à l'atelier et nous avons demandé conseil sur la forme de la boite. Le spécialiste nous a conseillé la boite rectangle car cela serait beaucoup plus pratique et réalisable. Il nous a également montré comment créer notre patron grâce au logiciel "LibreCad" où au logiciel qui crée directement une boite avec les dimensions que l'on veut, de plus, les pièces sont découpées de telle sorte que l'on peut les assembler directement comme un puzzle.  Nous avons donc utilisé ce deuxième logiciel pour créer notre patron avec les bonnes mesures. Une vidéo du découpage nos pièces avec le laser est disponible sur notre chaine youtube. La boite est prète. Vous pouvez la voir ci-dessous:
 
 <img src= ../Ressources/boite_feutre_1.JPG>
 <img src= ../Ressources/boite_feutre_2.JPG> </p>
 
 <ul><h3> Essai avec les bluetooth </h3></ul> 
 <p> Nous avons essayé de connecter les bluetooth entre eux, mais nous n'avons pas réussi à brancher le bluetooth "maitre" ( les fils ne rentraient pas) donc nous verrons la prochaine fois si on trouve une autre solution. 
 Pour ma part, je vais avancer sur le code des phrases en anglais dans le cas où nous n'avons pas d'autres solutions pour la communication </p>
  </li>
