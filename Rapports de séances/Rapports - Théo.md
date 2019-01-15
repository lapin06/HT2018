


<h2> Séance 1 - 10/12/18 - Commencement du projet </h2>
<li>   
  <ul><h3>Les préparatifs:</h3></ul>
    <p>Pour le commencement de notre projet, "Color Rabbit Prediction", j'ai tout d'abord créé notre github, et assisté ma partenaire pour le cahier des charges, que vous pouvez retrouver dans un dossier, ainsi que notre graphique de Gantt.

Afin de mieux nous organiser, j'ai d2couper le travail à effectuer en plusieur fonctions pour pouvoir se concentrer sur chaque tâche et ne pas s'éparpiller;
    exemple des Porgrammes:0-Main, 1-Capteur, 2-Servo , etc...
    </p></li>
 
  <li><ul><h3>Organisation des futur branchements:</h3></ul>
    <p> Dans le but de pouvoir penser à tout nos composants, leur utilitée et le fonctionnement globale de notre system, j'ai fait quelques schémas à completer si besoin sur les branchement de nos deux Cartes avec chaque composant.
    Vous pouvez trouver ceci ci-dessous</p>
    <img src=../Ressources/Cablage2.png>
  <p>--------------------------------------------Schéma Cablage selon boites -------------------------------------------------------------</p>
  
   <p>On peut donc y lire en haut le clablage relatif au branchement dans notre boite à feutre et en bas les branchements relatifs à notre boite ou se situe notre prédiction ( le lapin ).
    Les composants semblent tous y être même si il reste à determiner les valeurs des resistances et des batteries.</p>
  </ul></li>
  
  <li><ul><h3>Programme 1-Capteurs:</h3></ul>
  <p> J'ai donc commencé par écrire notre premier prorammme consistant à detecter lorsqu'un feutre sera retiré du pots. Donc lorsque le capteur detecte qu'il n'y a plus d'objet.
 Selon le marqueur choisit, le capteur en question se déclanche et retourne une valeur.
 Nous verrons si cela fonctionne à l'arrivée du matériel, pour que nous puissions faire les branchements.
  Par ailleur, j'ai également commencé à relier la fonction 1-Capteur à la fonction 0-Main, en prenant en compte la valeur retourner par le capteur et la lire dans cette fonction princile qui agira en conséquence de ce choix, ceci reste à approfondir.
  </p> 
  </li>


<br>
<br>
<br>
<h2> Séance 2 - 17/12/18 - Les capteurs et differents calculs </h2>
<li>   
  <ul><h3>Les branchements des Capteurs et Porgramme</h3></ul>
    <p>Le materiel a été livré nous allos donc pouvoir commencer. Suite au programme fait précédemment, j'effectue les branchements que vous pouvez voir ci-dessous:</p>
  <img src=../Ressources/S2-Cap.PNG>
  <p><em>-----------------------------------------Cablage des Capteurs de la "boite a feutre"-------------------------------------------------- </em></p>
    <p> Je televerse donc le programme 1-LECTURE_CAPTEUR afin de voir si tout fonctionne... Tout fonctionne, si un feutre est retirer la lettre relatif au premier à la premiere lettre du  mot de la couleur s'affiche. Ainsi pour un feutre retiré nous avons la couleur qui a été choisis par le spectateur. Il faut cependant prendre en compte comportement du spectateur qui peut prendre deux feutres, pour essayer de nous faire echoucher. C'est la raison pour laquelle j'ai rajouter une condition qui fait que si le feutre n'a pas été remis dans le pot ou si deux feutres ont été choisi un message s'affiche afin que le lapin dise subtilement au spectateur de ne choisir qu'un feutre. Attention ce message doit etre assez subtile pour que le spetctateur repose son feutre sans se rendre compte que nous savons qu'il a prit deux feutres sinon il n'y a plus d'interet à ce tour.</p>
    </p></li>
     
     
     
<li>   <ul><h3>Etudes des comportements des Capteurs et mise en situation</h3></ul></li>
    <p> Suite a une mise en situation des 4 feutres et des 4 marqueurs nous remarquons quelques imprevus. En effet, si les capteurs sont plongés dans de l'oscurité ou en exposition à la lumiere, la distance de détéction du feutre n'est pas la même. De plus, tout les capteurs ne sont pas sensible exactement de la même maniere.Enfin, la taille des capteur est plus imposante que prevu du à la carte a puce, etc...    <img src=../Ressources/Capteur_Etapes.PNG>
      <p><em>-------------------------------------------- Distance de detection des capteurs ---------------------------------------------------</em></p>
Ainsi le positionnement des capteurs dans la boites est remise en question:
<li>
  <ul>Posé au fond du pot a crayon et orienté vers le ciel;</ul>
  <p>       avantage:       fonctionne toujours</p>
  <p>        inconveniant:  Risque d'etre visible par le spectateur</p>
  <br>
<ul>Plaqué contre une parois:</ul>
  <p>       avantage:       Invisible pour le spectateur</p>
  <p>       inconveniant:   Une plus grosse boite est necessaire , quelques problemes pour certains capteur du a l'obscurité<p>
    </li>
    <p> La securité du fonctionnement du tour  mais aussi concerver le secret étant primordial. Nous choisissons donc la methode 2 , a savoir dissimuler les capteur dans la paroi, à nous de bien les camoufler. </p>
<li>   
  <ul><h3> Modifiction de la fonction 1-Lecture_Capteur pour la préparation du Bluetooth</h3></ul>
    <p> Arès reflexions sur les capteurs, il faut à présent penser à la structure logique de notre tour ( son dérouelment).Je decide donc de preparer les codes pour faires le liens entre les deux cartes arduino. En effet la carte arduino dans la boite à feutre va envoyer une lettre (fait par le programme précédent) par bluetooth à l'autre carte. En consequence l'autre Carte (Carte dans la boite du lapin) devra agir selon la réponse. Ceci m'amène donc à créer un code avec une succetion de "if" selon chaque action du spectateur.
Le code semble etre pret, même si non complet, la connection des Bluetooths sera pris en charge par mon binome.
    </p></li>
    
    
  <br>
  <br>
 <h2> Séance Bonus Vacance 1/2 - 21/12/18 - Notre première création </h2>
  <li><ul><h3> Conception de notre boite à feutre</h3></ul>
  
  <p> Nous nous retrouvons aujourd'hui a la Fablab de la Telecom Valley sur le site des Templier pour réaliser notre boite un feutre. Je rappelle que le but de cette boite et de ressembler a un pot a feutre tout à fait classique, mais qui doit en realiter cacher tout notre premier assemblage que vous pouvez retrouver dans Séance 1 de mon rapport précédent. Suite au test effectué durant les séances précédentes je peux donc commencer à dresser un plan de notre Boite, en parallèle de ca mon Binome dresse également un autre plan pour que nous puissons choisir le plus facile à réaliser. Ainsi que le pot le plus naturel, non suspect. Passons a la réalisation.</p>
  <br>
  <p><em>--------------------------------------------------------1.Planification--------------------------------------------------------------</em></p>
   <img src=../Ressources/boite11.PNG>
   <p> Voici le plan de la maquette à réaliser. Nous sommes ici a échelle réelle (2 carreaux= 1 centimètre). Chaque composant a été mesuré et placé soigneusement selon sa taille et son utilisation pour maximiser la place.Nous ne connaissons toujours pas la batterie que nous allons choisir donc dans le doute non prenons un grand espace vide (relatif) si besoin.</p>    
  <p><em>--------------------------------------------------------2.Modélisation---------------------------------------------------------------</em></p>
   <img src=../Ressources/boite22.PNG>
   <p>Il est a présent temps de modeliser ceci grace a un lociel de generateur de boite cependant dans notre cas il y a une petite subtilité. Notre boite devant contenir les feutre nous devons donc l'ouvrir en créant un recipiant pour acceuillir les feutres. Nous créons donc deux boite l'une imbriqué dans l'autre comme vous pouvez le voir dans le resultat final</p>
   
  <p><em>--------------------------------------------------------3.Découpage Laser------------------------------------------------------------</em></p>
  <img src=../Ressources/boite44.PNG>
  <p> Une fois la modélisation faite, direction le fablab de la silicon valley, ou une machine prevu a cet effet decoupe nos plan effectué. Vous pouvoir voir ici ce travail plutot eblouissant, du 
  <a href=https://www.youtube.com/watch?v=cO1AD-aDM-o> découpage laser.  </a></p>
  
  <p><em>--------------------------------------------------------4.Assemenblage---------------------------------------------------------------</em><p>
   <img src=../Ressources/boite33.PNG>
  <p> Enfin l'asssemblgee, dont vous pouvez voir le resultat ci dessus. Actuellemnt retenu avec de simpe morceaux de scotch, en attendant de remplir cette boite de notre montage et d'etre certain que tout fonctionne...</p>
  
  
  <br>
  <br>
 <h2> Séance Bonus Vacance  2/2 - 28/12/18 - Le lapin, un beau parleur </h2>
 
 <li><ul><h3> Ecriture du Scripte relatif au texte du lapin</h3></ul>
 <p> Je commence par prendre mon stylo pour rediger le texte que le lapin prononcera si tout fonctionne. Ce texte comporte de nombreuses conctraintes que nous n'avons pas forcément lors ce que nous faisons un tour par nous même. Il faut prendre en compte le timing qui peut varier d'une personne à l'autre avec ses actions donc le tour sera différents selon le spectateur qui est le seul a tout faire.</p>
  <p>L'humour va devoir être travaillé d'une autre manière. Un robot faisant une blague peut être un succés ou au contraire un enorme raté. Il faut prendre en compte que le spectateur fait quatre fois la même action donc il faut veiller à ne pas avoir un texte rébarbartif. L'idéal est d'incorporer le magicien dans le tour, en le faisant dialoguer avec le lapin, de cette maniere ce tour à vraiement une utilité, un interet professionel sinon celui-ci n'est qu'un jouet. Il faut donc prevoir l'interaction avec le magicien, les rires eventuels du public etc...</p>
  <p>Tout ceci de maniere subtil pour que le spectateur ne comprennent pas qu'il y ai des capteur qui informe le lapin de la situation, le but etant de jouer sur la psycologie des spectatuer pour pouvoir leur <strong> faire croire que l'on ne sait rien alors que l'on sait tout </strong>. Le but etant de creer un vrai tour de mentalime puissant,d'un niveau professionel tel l'original "color pen prediction" donnant ainsi envie au spectateur d'en voir encore plus.Vous pouvez retrouver le scripte dans la dossier document: "Script lapin"</p>
  </li>
  
  
  <br>
  <br>
  <h2> Séance 3 - 07/01/19 - Bluetooths et LED </h2>
  <li><ul><h3> Connection des Bluetooths maitre-esclave</h3></ul>
  <p>Nous connectons les deux bluetooths au montage respectif, le maitre sur le montage de la boite au marqueur et l'esclave sur la boite du lapin. Suite a un problème de fonctionnement du bluetooth "esclave", nous ne pouvons pas connecter ces deux entre eux. En fin de séance le problème a été resolu.De mon coté tout semble fonctionner avec le bluetooth maitre. Ainsi nous rattraperons se retard hors séance...</p>
  <p>Travail hors séance complementaire:  Nous arrivons enfin a conecter les deux bluetooth entre eux! Cependant quand nous envyons un message du maitre a l'esclave celui ci ressoit un caractère spécial : "?". Ainsi je supose qu'il s'agit du erreur de communication entre les bluetooth tel la vitesse de dialogue, cependant celle-ci semble etre la même.  </p>
 
  
  <li><ul><h3> Bouton poussoir d'activation et LED de controle</h3></ul>
   <img src=../Ressources/CB2.jpg>
  <p>-----------------------------------------Montage boite feutre - avec bluetooth, bouton et led-----------------------------------</p>
  <p> Suite au retard technique du bluetooth de ma camarade j'avance de mon coté pour gagner du temps. J'éffectue les branchements ci-dessus, me permettant de pour voir connecter la boite a feutre en bluetooth. De plus celle ci sera activable quand nous le souhaitons grace a un bonton pressoir. Ainsi pas besoin d'ouvrir la boite et autre quand nous voulons lancer le tour. L'avantage d'avoir choisi un bouton pressoir plutot qu'un bouton on/off est la rappidité et la facilité de l'activé. En effet si celui-ci depasse pas besoin de reflechir un milième de seconde. En effet, la pression sur le bouton doit de faire de manière rapide et sans regarder  pour que ceci soit discret. Puisque le but étant de faire comme s'il sagissait d'un pot ordinaire. </p>
  <p> La sécurité avant tout! Je choisis donc de rajouter une led a chaque boite. Ceci dans le but d'être sur que les deux boites sont opperationelles. Un fois le bouton presser , les deux LEDs s'activeront simulatenement à l'arrière des deux boites pour que seul le magicien puisse voir que tout fonctionne...Pour la boite à feutre tout fonctionne, en attente des bluetooth pour pourvoir activé la led de l'autre boite et faire parler le lapin</p>
  </li>
   
   <li><ul><h3>Studio d'enregistrement pour la voix du lapin - Hors séance </h3></ul>
  <p> Le dispositif de stockage par carte SD pour la communication du lapin vient d'arriver! Commençons par enregistrer les paroles du lapin, la voix sera en réalité simplement celle de mon binome et notre studio d'enregistrement un simple smartphone. </p>
<img src=../Ressources/C1.jpg> 
  <p>---------------------------------------------Enregistrement de la voix---------------------------------------------------------------</p>
  <p>Après reflexions, nous choisissons de prendre une voix aigu pour donner au lapin un aire prétentieux, enfantin et humoristique. Nous aurions également pu prendre une voix tres grave pour lui donner un style dépréssif, de fumeur , tel un vieux magicien. Comme prévu dans le script nous découpons l'enregistrement en plusieurs séquence pour faire passer l'enregistrement selon les actions du spectateurs...</p>
  
<li><ul><h3>Assemblage final de la boite à feutre et premier test - Hors séance </h3></ul>  
  <p>Nous continuons donc à pofiner la boite à feutre par étape :</p>
<img src=../Ressources/C3.jpg>
  <p>------------------------------------------------------Assemblage et perfectionnement------------------------------------------------</p>
  <p> <li><ul>Etape 1: Perçage et ponçage des troue pour la disposition des cateurs </ul>
    <ul> Etape 2: Mise en place des compartiments pour les feutres </ul>
    <ul>Etape 3: Ajout d'une fente pour mettre une regle ou autre pour simuler une veritable boite a feutre </ul>
    </li>
    Une fois tout ses étapes faite je m'occupe de verifié que les capteurs fonctions bien dans la boite,c'est a dire que les parrois ne pertubent pas les capteurs. Vous pouvez voir ici, le bon fonctionnement de la boite! Afin de pofiner la boite mon biinome se charge de peindre la boite puis nous la decorerons telle une boite d'enfant.</p>
  
  
  <br>
  <br>
  <h2> Séance 3 - 14/01/19 - Finalisation bluetooth et recherche de batterie </h2>
  
  <li><ul>1er Test avec bluetooth operationel </ul>
  <p> Après un temps de compréhension de l'utilisation des temps de communications entre bluetooths, et l'utilisayion du "/n/t", nous arrivons enfin a faire communiquer les deux bluetooths. On remarque ainsi avec le code que j'avais effectué au préalable que tout fonctionne comme prevu ormi la possibilité de changé de feutre une fois pris qui est a revoir par securité.
Vous pouvez voir ci-dessous la demonstration complete du fonctionnement de la boite arduino: fonctionnement.</p>
  <li><ul>Preparation code boite a lapin </ul>
  <p> Alors que mon binome continue a s'approprier le dispositif de communication je lui prepare alors le structure du code selon les messages recu du bluetooth. Vous pouvez donc retrouver le squelette de ce programme dans le dossier code. J'incorpore la </p>
  <li><ul>Dertermination tention batterie - Hors séance</ul>
  <li><ul>preparation Bonus - posibilité de faire l'original colo pern prediction </ul>
  <p>
