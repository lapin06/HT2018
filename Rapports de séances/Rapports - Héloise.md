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
<h1>Séance 3 : 07/01/19 : Bluetooth et boite feutre</h1>
<li>
 <ul><h3> Connexion des bluetooth </h3></ul>
 <p> Lors de cette séance nous avons essayé de connecter les bluetooths entre eux ( En forçant les fils rentrent ). Mon binôme s'est occupé du bluetooth maitre quant à moi je m'occupais d'initiliser l'esclave, j'ai eu des problèmes de téléversements, les commandes AT ne répondaient pas. Le problème a été résolu petit à petit, il fallait résoudre quelques soucis comme la vitesse de communication entre l'ordinateur et la carte qui devait être initialisée dans un ordre précis. Nous avons pu trouver l'esclave avec le maitre, le maitre s'appareillait bien mais l'esclave non. On se verra dans la semaine pour résoudre ce problème. </p>
 
 <ul><h3> Boite feutre et capteurs </h3></ul>
 <p> Après avoir fait la boite des feutres, j'ai réfléchis à un moyen de placer les capteurs pour qu'il y ai le moins d'interférences possibles. A deux nous avons trouvé la solution de les mette "débout" le long de la boite. J'ai donc pris les mésures nécessaires. J'ai également indiqué l'endroit ou nous devront percer la boite afin de faire tenir les capteurs. Vous pouvez voir le résultats ci-dessous:
  <img src= ../Ressources/dessin_capteurs_boite.jpg.JPG>
  <img src= ../Ressources/position_capteurs.jpg.JPG> </p>
 
 <p> Avant la prochaine séance, nous voulons apparailler les bluetooth correctement ainsi que percer la boite pour mettres les capteurs et les feutres. De mon coté je commencerai le code du servomoteur.
Nous attendons encore le module de communication pour pouvoir enregistrer nos voix.</p> </li>

<h1>Séance 4 : 14/01/19 : finalisation de la boite feutre</h1>
<li>
 <ul><h3> Travail hors séances </h3></ul>
 <h4> boite feutre </h4>
 <p> Nous avons fini la boite de feutre! Etape par étape nous avons finalisé cette boite en commençant par percer les fameux trous pour les capteurs. Ensuite nous avons positionné les capteurs et fait plusieurs test pour voir si tout allait bien. L'étape suivante consistée à réaliser des compartiments dans la boite afin que chaque feutre ai son propre espace pour ne pas que les capteurs interfèrent ou que les feutres aillent sur le mauvais capteur. Afin de rendre la boite plus naturelle nous avons fait un trou dans la boite pour pouvoir mettre une règle dedans. J'ai peint la boite de feutre en noir. Nous avons ensuite réalisé notre propre studio d'enregistrement pour le lapin. Un peu de miel et de lait et hop c'est parti pour prendre une voix aigue ( notre but était de le rendre enfantin et narcissique). 
Pour finir, Mon binome travaillait sur la connexion des deux bluetooth car il y avait toujours un problème avec le blutooth esclave pendant que je travaillais sur la boite du lapin. 
  <img src= ../Ressources/perçage.JPG>
  <img src= ../Ressources/capteurs_trous.JPG> </p>
 
 <h4> boite du lapin et servomoteur </h4>
 <p> J'ai donc réfléchis au design de la boite du lapin car l'objectif et simple: Lorsque c'est la fin du tour le servomoteur, positionné à l'interieur en haut de la boite du lapin, qui relie avec un crochet les deux parties de la boite, tourne pour enlever le crochet et les deux cotés de la boite tombent pour laisser place au lapin. Le code du servomoteur etait plutot simple car nous lui demandons seulement une rotation de environ 9 degrès ( les mesures seront plus précises plus tard ). Vous pouvez donc voir le code ci-dessous:
#include<Servo.h>;
Servo servo;

void setup(){
  servo.attach(2,544,2400);
}
void loop (){
 servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);
 }
  ce code sera inséré au code des capteurs. Il fallait cependant que je réfléchisse à la répartition du poid car les deux cotés de la boite doivent tomber vers l'extérieur. plusieurs otpions : soit des poids apparant en dehors de la boite pour forcer les cotés à tomber, mais cela ferait pression sur le servomoteur et donc cette idée est secondaire. La deuxième option est de jouer sur le design de la boite pour faire basculer automatiquement les deux cotés. Avec du papier, j'ai donc fait un premier essai de cette boite. Le premier essai était plutot concluant. 
  <img src = ../Ressources/boite_lapin.JPG> </p>
  
  <ul><h3> Durant la séance </h3></ul>
  <h4> finalisation boite et blutooth </h4>
  <p> Je me suis occupée de finaliser la boite feutres en réalisant les derniers collages ( les compartiments). Ensuite nous avons réussi à mettre en relation les deux bluetooth, en testant le programme des capteurs avec la boite et les bluetooth, tout fonctionne. </p>
  <h4> Communication lapin </h4>
  <p> Ca y est notre commande du module serial MP3 permettant de jouer des musiques avec une carte SD reliée à l'arduino est arrivé! JE peux enfin terminer la partie comminication qui est un élément clé du tour. J'ai pu trouver chez moi une mini carte SD ainsi qu'un adaptateur. Il ne manque plus que le code. En réalisant des recherches j'ai trouvé plusieurs tuto nous expliquant comment faire marcher ce module.
voici le cablage:
 <img src = ../Ressources/schema_MP3.png>
Le premier code trouvé est plutot compliqué à comprendre mais je ne le laisse pas de coté vous pouvez le voir à l'addresse suivante:
 
<a href="https://www.hackster.io/javier-munoz-saez/arduino-mp3-player-catalex-2effef">CODE 1</a>
 En allant sur youtube, j'ai trouvé un tuto plutot simple pour faire fonctionner le module, j'ai donc suivis les étapes à la lettre, écris le code relatif... mais cela ne fonctionne pas! Je ne comprends pas d'ou l'erreur provient. Il faut que je test d'autre code pour un trouver un qui fonctionne et que je comprends bien. C'est donc la dessus que je passerai mes prochains temps libres hors séances car il faut absolument que cela fonctionne. je vous met en lien la vidéo que j'ai trouvé avec le code et les étapes à suivre: 
<a href="https://www.youtube.com/watch?v=rdKk-1MRMqY">VIDEO CODE</a> </p>

<h1>Travail Hors séances : 31/01/19 : Communication et lapin </h1>
<li>
 <ul><h3> Communication Serial MP3 </h3></ul>
 <p> Ca y est notre lapin peut enfin parler ! Maintenant qu"il peut parler il ne s'arretera pas de si tôt! J'ai réussi à faire fonctionner le programme ( le premier que j'avais annoncé plus haut ). Sûrement un problème de branchement ou simplement que je n'avais pas bien compris le code. La démonstartion en vidéo est disponible sur notre chaine youtube. Le seul soucis qu'il fallait régler et que le programme ne pouvait lire que seulement une chanson à la fois, et nous , nous avons besoin de pouvoir lire plusieurs fichiers audios en fonction de ce qu'il choisit. "En fonction de" j'ai donc résolu ce problème en traduisant cette phrase par des boucles " if ". Si le moniteur serie lit " 1" alors il va jouer telle chanson, si le moniteur lit "2" il jouera alors une autre chanson. J'ai également brancher des hauts parleurs et avec un modifieur de watt pour pouvoir bien entendre sans les écouteurs. Tout est presque pret. Prochaine étape c'est d'incorporer le code, donc les enregistrements audio dans le code de la carte du lapin. 
  Le bluetooth esclave recevra et lira une information, par exemple OKV ( donc choix du feutre vert ) et donc dans la boucle " if (OKV) " on lira l'enregitrement audio associé. je n'ai pas les enregristrements audio (d'ailleurs on les garde en surprise donc pas de démonstration de voix!) donc je vais me contenter d'ajouter le code sans ceci pour l'instant.
  Tout prend forme petit à petit... </p>
 <br>
 <ul><h3> Notre assistant le lapin est prêt pour son show ! </h3></ul>
 <p> ABRACADABRA et hop notre vedette est enfin parmi nous ! J'ai donc fais les magasins pour acheter à notre lapin sa tenue de scène très spéciale... Après avoir fait les essayages en live, celui-ci était plutôt content de ses habits ! Chapeau ok.. t-shirt ok.. pantalon ok.. chaussettes?? NON !! impossible de trouver en magasin les chaussettes qu'il voulait ... VERTES en même temps, qu'elle idée de lui mettre en tête d'avoir des chaussettes vertes c'est cool. Ce n'était pas très malin de notre part. Je ne voulais pas le décevoir alors j'ai décidé d'acheter un tissu vert et des coudres moi-même ! le pauvre il ne s'imagine pas ce qui lui attend...</p>
  <br>
  <p>J'ai donc passé ma journée à retoucher ses vétements car oui il fallait pratiquemet tous les retoucher, monsieur lapin est très exigeant et a une morphologie bien particulière... c'est parti pour faire des trous dans son bonnet pour faire passer ses oreilles, un trou dans le pantalon pour faire passer sa petite queue toute ronde, et surtout couper les jambes du pantalon !! Mais ce pantalon n'était pas une mince affaire car il s'éffiloche quand on le coupe.. il a donc fallu que je retrousse mes manches et que je m'applique davantage pour lui faire des ourlets! Vous pouvez voir la vidéo avec/sans ourlets sur notre chaine youtube pour comprendre pourquoi cela a était nécessaire. sur la photo ci-dessous, à droite SANS ourlets à gauche AVEC: 
 <img src= ../Ressources/ourlets.JPG></p>
  <br> 
  <p>C'est à peine si j'ose vous parler de mes talents de couturière si je vous montre les chaussettes que j'ai fais. Mais l'essentiel est que les chaussettes sont à sa taille et qu'elles lui plaisent. ouf!  
   <img src= ../Ressources/chaussettes_coutures.JPG>
   <img src= ../Ressources/Chaussettes.JPG> </p>
 <br>
 <p> Ca y est notre vedette est prète et elle hésite pas à prendre la pause... 
  <img src= ../Ressources/face.JPG>
  <img src= ../Ressources/profil.JPG> </p>
