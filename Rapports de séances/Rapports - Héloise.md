# Séance 1 : 10/12/18 : Début du projet
<h2> Aujourd'hui nous avons démarré notre projet qui s'intitule "Color Rabbit prediction"</h2>
 <li>
  <ul><h3> Organisation du travail </h3></ul>
     <p>Nous avons découpé les étapes du projet en fonction des séances, pour cela nous nous sommes mis d'accord pour un planning que j'ai ensuite réalisé. Cela m'a prit la moitié de la séance car il est difficile de prévoir le temps que l'on mettra pour chaque étape du code et de la construction, ce planning sera disponible dans /HT2018 </p>
 
 <ul><h3>Cahier des charges</h3></ul>
  <p>Ensuite j'ai réalisé le cahier des charges correspondant au projet, celui-ci sera aussi disponible dans le répertoire principal (temps: 1h15) </p>
  
  <ul><h3> Communication Arduino </h3></ul>
  <p>Dans la dernière demi heure j'ai commencé à faire des recherches sur comment faire parler une carte Arduino, ce qui est une grande partie de notre projet. j'ai trouvé assez rapidement le code relatif à cela, mais pour le réaliser il faut importer la librairie tolkiez, j'ai alors rencontré un problème de compilation avec cette librairie. je résoudrai surement ce problème chez moi ou la séance suivante. L'idée est la suivante: le Lapin et en fait celui qui va parler tout le long du tour ( ce tour n'a pas besoin de d'interactions avec nous pour fonctionner), cela implique qu'il devra lui même désigner quels parties colorier, il dira bonjour etc... </p>
  </li>

#Séance 2 : 17/02/18 : communication arduino
<li>
<ul><h3> Utilisation de Sparkfun Voicebox Shield </h3>
<p> J'ai abandoné l'idée d'utiliser la librairie tolkiez.h qui est une librairie permettant d'écrire un code pour faire parler la carte Arduino avec l'aide d'un haut parleur. En effet je n'arrivais pas à résoudre les problèmes de compilation.

Je suis donc passer au Sparkfun Voicebox qui est composé d'une carte voiceBox, d'une carte arduino et d'un haut parleur. Le but étant de pouvoir faire parler notre lapin avec ce haut parleur, avec lequel on peut mettre une carte mémoire qui va pouvoir mémoriser ce que notre lapin va dire. On a donc besoin de la librairie "software serial" pour parler au SpeakJet (voiceBox). J'ai donc commencer mes recherches et j'ai pu trouver un github qui explique comment se servir de ce voicebox, accompagné d'un code. </p>

<h4> problème de compilation </h4>
<p> J'ai téléchargé le code et j'ai passé du temps à comprendre les différents points de cette voicebox ( par exemple les sorties/entrées RST, RDY,SPK), et à comprendre comment cabler tout cela(nous avions déjà en stock le matériel).
Je me suis ensuite retrouvé face à un problème de compilation de nouveau, cette fois j'ai réussi à comprendre ce problème et j'ai donc cherché une solution. PROBLEME: "narrowing conversion of '200' from 'int' to 'char' inside { }" char permet de prendre des nombres en 7bit (et permet de mettre un signe devant) or dans ma chaine de caractère j'ai des nombres en 8bit ( tous les nombres >=100) j'ai donc trouvé la solution en mettant devant char : unsigned , cela permet d'enlever le bit réservé au signe, donc char est dorénavant en 8bit et peut aller jusqu'a 255. </p>

<p> mais ce n'était pas le seul soucis... en effet je n'arrivais toujours pas à compiler mon programme, alors que sur l'ordinateur de mon binôme , la compilation se faisait sans erreur. j'ai pu résoudre ce problème en téléchargeant la version la plus récente d'Arduino. j'ai testé mon programme en faisant dire à la carte " hello " . Cela fonctionne! </p>

<p> Tout ce temps passé à essayer de résoudre les problèmes de compilation et à re-télécharger Arduino m'a fait perdre un temps précieux. Cependant aillant réussi à faire fonctionner le haut parleur, je pourrai rattraper tout ce temps pendant les vacances en écrivant le code pour faire parler arduino ( un code qu'il faut travailler car chaque lettre ou syllabe est codé d'une manière spéciale, et qui plus est, en anglais) . </p>
