<h1><strong>     ------------------   RAPPORT - THEO LEMAIRE   ------------------- </strong>  </h1>


<br/>
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
  
  
  
  <br/>
  <br>
  <h2> Séance 4 - 14/01/19 - Finalisation bluetooth et Bonus </h2>
  
  <li><ul><h3>1er Test avec bluetooth operationel <h3></ul>
  <p> Après un temps de compréhension de l'utilisation des temps de communications entre bluetooths, et l'utilisayion du "/n/t", nous arrivons enfin à faire communiquer les deux bluetooths. On remarque ainsi avec le code que j'avais effectué au préalable que tout fonctionne comme prevu ormi la possibilité de changé de feutre une fois pris qui est a revoir par securité.
Vous pouvez voir ci-dessous la demonstration complete du fonctionnement de la boite arduino: fonctionnement.</p>
  <p>---------------------------------------------------------------------------------------------------------------------------------</p>
  <img src=../Ressources/20-3.jpg
  <p>---------------------------------------------------------------------------------------------------------------------------------------</p>
  
  <li><ul><h3>Preparation code boite a lapin</h3> </ul>
  <p> Alors que mon binome continue à s'approprier le dispositif de communication je lui prépare alors le structure du code selon les messages recu du bluetooth. Vous pouvez donc retrouver le squelette de ce programme dans le dossier code: 2-LAPIN. J'incorpore également la led de controle comme dans la boite à feutre afin de verifier si chacune des boites est operationelle quand on lance le tour. Vous pouvez donc retrouver cette methode à la suite du message obtenu par le bluetooth : "PRET". Je laisse donc soin à mon binome de completer  sa partie si son dispositif avance. Je vais aussi me pencher sur son dispsitif pour un gain de temps. </p>
  <img src=../Ressources/20-2.jpg>
  <p>------------------------------------------------Test communication avec boite lapin ------------------------------------------------</p>
  <br/>
<li><ul><h3>Preparation Bonus - posibilité de faire l'original colo pen prediction<h3> </ul>
  <p> Par estimation de notre projet en fonction du temps restant le travail a finir est :
  <li><ul>1.Fabriquer boite lapin</ul>
    <ul>2.Faire fonctionner le dispositif de communication et se l'approprier</ul>
    <ul>3.Trouver les bonnes batteries selon leur tension, ampérage...</ul>
    <ul>4.Fixer chaque élément dans chaque boite</ul>
      </li>
    Ainsi je me rend compte que pour la fin de la séance je ne peux pas avancer alors avec le soutien de mon binome, je realise la version classique du color pen prediction simplement avec notre téléphone. En effet cette fois ci une fois un marqueur choisi une led s'allumera comme vous pouvez le voir ci dessous et ainsi le magicien pourra lui meme faire le tour.</p>
      <img src=../Ressources/20-1.jpg>
  <p> ---------------------------------------------Préparation si besoin du tour original -------------------------------------------------</p>
  <p> J'insere donc un deuxieme bouton poussoir à la boite à feutre. En cas d'activation, le tour ne sera plus avec la peluche mais bien avec le telephone. Le code en lui même reste simple. Le plus dur à faire risque d'appareiller un deuxieme bluetooth esclave sur ce même maitre....A suivre</p>
  
  
  
  <br/>
  <p>--------------------------------------------------------------------------------------------------------------------------------------</p>
  <p>--------------------------------------------------------------------------------------------------------------------------------------</p>
  
  
  
  <br/>
 
  <h2> Séance 5 - 04/02/2019 - Independence des boites et preparation de la boite à lapin </h2>
  
<li><ul><h3>Recherche des batteries</h3></ul></li>
<p> Pour rendre les deux boites independantes je me lance dans la recherches des batteries des deux boites. Les principales caracteristiques qui nous intéresses pour nos batteries sont la tension, l'ampérage. Aprés mesure a l'aide d'un Amperemètre et d'un Voltmètre je determine les caracteristiques de chacun des composants.</p>
   <li><ul> <li>Capteurs Boite:  3-5V --- 0,01A</li>
    <li>Bluetooth HC05:  3,5-5V --- 0,3A</li></ul>
    <p> etc... Ainsi il est possible de prendre une petite batterie qui serait capable de rentrer dans notre boite a feutre comme prévu. Après recherche , j'ai finalement choisit les batteries suivante:
 
  <li> Boite a feutre: Il nous faut une petite batterie! une toute petite batterie!</li>
  <img src= ../Ressources/batt.jpg>
  <p>--------------------------------------------Batterie boite à feutre --------------------------------------------------------------------</p>
  <li> Boite à lapin:5V suffiront et pour la place ne vous inquietez pas !
  <img src=../Ressources/batterie2.jpg></li>
  <p>----------------------------------------------Batterie Boite à Lapin-----------------------------------------------------------------</p>
   
   
<li><ul><h3>Preparation boite lapin</h3></ul></li>
<p> Mon binome à reussi faire parler notre lapin! Ainsi elle peut completer mon code squelette que j'avais fait au préalable et nous allons pouvoir tester l'assemblage de nos deux travaux! Mais avant certaines finalisations je m'attaque la boite à Lapin. Après plusieurs version de boite, plusieurs semaine de reflexionns, plusieurs maquettes, nous avons enfin choisit notre model de boite à lapin! Les principaux critères pour le choix étaient; le disgn, les dimensions pour les transports, l'effet visuel de l'ouverture, l'originalité, la securité pour les poinds de bascule et evité la casse du servo moteur lors de l'ouvertur etc...Ainsi le model choisit est...</p>
<img src=../Ressources/boitelapin.png>
<p>------------------------------------------------------- Quelques idées -----------------------------------------------------------------</p>
<p> Je suis donc reparti dans la modelisation d'une nouvelle boite, en effctuant les mêmes étapes que la première en plus complexe cette fois-ci avec l'ouverture a bascule de la boite .
  <img src=../Ressources/b3.PNG>
  <p>------------------------------------------- Modeliastion boite à encoches pour notre lapin ------------------------------------------</p>







<br/>
<br/>

<h2> Séance 6 - 11/02/19 - Communication et assemblage </h2>

<li><ul><h3> Interaction et communiaction des deux boites </h3></ul></li>
<p>Suite à un problème de cable du module bluetooth HC06 nous mettons du temps à mettre en marche notre fabuleux tour. Suite a cela nous recontrons quelques autres petits problèmes techniques avant la mise en marche de la communication. Comme par exemple le message bluetooth à envoyer, les problèmes du au dispositif mp3, etc... Après avoir reglé tout ses problèmes et le travail approfondit de mon binome, nous arrivons a lancer le tour comme prévu. En effet, une fois apres avoir appuyé discretement derriere la boite a feutre la led s'active pour confimer l'allumage, la boite à lapin reçoit l'information. Et celle-ci commence a presenter notre le tour! <p>
  <p> A présent il faut voir si la suite fonctionne bien. En effet si a chaque feutre tout se passe bien et si nous arrivons à enchener plusieur messages sans les intereferer.</p>
  
  <li><ul><h3> Les petites boites </h3></ul></li>
  <ul><h5>finition de la petite boite a feutre </h5></ul>
  <p> Je me lance alors, dans le perfectionnement de la petite boite à feutre. Je reprend donc tout les cablage et les retaillent chaque cable de chaque composant pour les adapter à la boite.  Aussi bien pour les capteurs, bluetooth,  led... Je fais egalement des perçages dans la boite pour la LED et Le(s) bouton(s).</p>
  
  <img src=../Ressources/face.jpg>
  <p> --------------------------------------------- Faces de la boite à feutre ( exterieur et interieur ) ----------------------------------</p>
  
  <p> Je décide de garder le bouton poussoir et le faire sortir un minimum par discrétion et de même pour la LED. En effet, même si ces deux seront derrière les boites nous ne sommes pad a l'abbrit d'un spectateur curieux...</p>
  
  
  
  
  
  
  
  
  
  <br/>
  <br/>
  
  <h2>Séance Bonus Vacances 1/3 - 14/02/2019 -  Premiere présentation du Tour et decoupe laser boite lapin </h2>
  
  <li><ul><h3> La premiere présentation, la victoire est encore loin... </h3></ul></li>
<p> Nous nous lançons pour notre première présentation du tour complet. Et c'est a ce moment la que l'on comprend que le travail est loin d'être fini. En effet, l'inteligence  que j'ai créé pour notre boite à feutre a quelques limites. Je n'arrive pas complètemment a realiser mes pensées. Je continu donc a chercher comment un spectateur peut choisir de reposer un feutre une fois choisit sans que tout le programme ne se détruise pas. En effet même dans la version classque le magicien ne propose pas au spectateur de savoir s'il veut changer de feutre nous non avant de colorier. Alord qu'ici, le fait de pouvoir proposer de changer de feutre serait vraiment un renfocement de l'effet. Je continue donc ma reflexion...</p>

  <li><ul><h3> Le casse - tête </h3></ul></li>
  <p>Après deux après-midi au fab lab nous parvenons à decouper toute nos boites. Pour la grande boite, nous nous lançons dans les collages du socle de la boite a lapin ou se trouvera la carte, le bluetooth et autres composants auditifs. Suite à  un probleme technique nous somme contraint de refaire notre petite estrade de la boite. Mais finalement nous y arrivons. Une fois chez moi je me lance alors dans l'assemblage de cette boite. ET c'est alors que les problemes commencent ...</p>
<img src=../Ressources/lap.jpg>
<p>-------------------------------------------------------------Boite à lapin assemblée-----------------------------------------------------<p>
  <p> Hélas pour moi cet assemblage n'a pas été si simple. La fixation faite à l'aide des charnières a  entrainé une ouverture (une fente) entre les deux boites du haut alors que nous desiront qu'elles restent collé pour ne pas dévoiler le lapin... Pour combler ce défaut j'ai dont decoupé des encauches de la tailles des charnières pour compler cet espace. De plus suite a la très grande precisiton de la machine à decoupe il n'y a aucun jeu entre l'élévateur et la boite d'ouverture. Ainsi j'ai donc du poncer les parrois pour faciliter l'ouverture. On notera au passage que comme prévu, la boite s'ouvre parfaite sans ajout de poid sur les cotés. De plus l'ouverture est très rapide... Par peur de casse du bois ou du servo moteur, il est nécéssaire d'ajouter des bande de mousse pour amortir les parois pendant la chute. Enfin, par erreur de notre par les troues pour les enceintes sont trop petits 40mm au lieu de 46mm de diamètre, je décide donc de poncer les troues pour les agrandir </p>

  
 </br>

<h2>Séance Bonus Vacances 2/3 - 21/02/2019 - Quelques problèmes...</h2>
  <li><ul><h3> Les problemes de la petite boite </h3></ul></li>
  <li><ul><h4> La lecture </h4></ul></li>
  <p> Je me rend très vite compte qu'il y a un problème avec notre boite à feutre et les capteurs, concernant la détection de feutres. En effet un simple mouvement de boite peut parfois entrainer la deterction ou non d'un feutre... Ainsi la detection devient trop aléatoire et donc trop dangereuse... Ainsi je décide de donner un petit coup de pouce au capteur en créant de rampes pour conduire directements les feutres dans un positionnement optimal pour leur détections. </p>
  <img src=../Ressources/dans.jpg>
 <p> ------------------------------------------------------------Rampe de détéection-----------------------------------------------------</p>
 <p> Ainsi peut importe la manière dont le spectateur dispose le feutre celui-ci sera detecté grâce à cette rampe. Même s'il est vrai qu'a cause de cette rampe le placement des feutre dans la boite devient moins naturel moins desordoné, trop carré... Ceci donne un aire suspcet à la boite à feutre... Mais pour le moment nous n'avons pas d'autre choix... Car nous devons être sur de la detection sinon tout tombe à l'eau et le lapin ne saura plus quoi dire</p>
 
  <li><ul><h4> La compression </h4></ul></li>
  <p> Nous somme confronté à un problème majeur...Le manque de place. Nous le savons notre boiteà feutre est déjà volumineuse et pourtant tou ne semble pas rentrer dans la boite alors qu'il n'y a pas encore la batterie.  En effet la carte et la plaquettes sont a l'etroit...Sans oublié la grande quandtité de fils vu le nombre de composant. etc...
  Ainsi je me lance dans la decoupe de file pour optimiser l'escape de stockage. dans un premier temps je m'occupe de fixer la led et le bouton poussoir et de souder ceci; </p>
  <img src=../Ressources/soud.jpg>
 <p>----------------------------------------Ma première prise en main d'un fer à souder !!!--------------------------------------------</p>
 <p> Et j'enchaine en decoupant, denudant et soudant de cables pour elminimer au maximum de quantité de cable mais pas trop car en effet il faut pouvoir garder une certaine accecibilité au composant. C'est pour ça que la tache devient diffcile...Pour l'instant je n'ai pas encore reussi a fermer la boite sans la tenir...A suivre</p>
 
 
 
 
 
 
 </br>
 <h2> Séance Bonus Vacances 3/3 - 23/02/2019 - Code et Décoration </h2>
 <li><ul><h3> Un peu de couleur!</h3></ul>
 <img src=../Ressources/peind.jpg>
  <p>------------------------------------------------Un Premier jet de peinture--------------------------------------------------------</p>
  
  <p> En passant les details, apres quelques heures de peintures, de retouches, etc... Voici un premier resultat de l'avancement de la boite à lapin actuel. Nous avons eu l'idée de rajouter de un rideau de scene sur l'avant et ecrire "MAGIC" ou "MAGIC RABBIT" sur le socle et éventuellement incorporer des led pour le disgn. Ceci étant voir car le temps nous est compté. </p>
  </li>
  <li><ul><h3> Code boite a feutre V4 </h3><ul>
 <p> J'ajoute à la version 3 les extraits manquant que nous avons constaté lors de notre première représentation. Les codes manquants étant la possibilitée de changer de feutre. IL ne reste plus qu'a tester ce lundi si tout marche comme prevu ou s'il est nécéssaire de continuer les recherches.</p>
  
  
  </br>
  <h2> Séance 7 - 25/02/2019 - La réunion de nos travaux </h2>
  <li><ul><h3>Système d'ouverture de la boite a lapin </h3</ul>
    <p> Nous realisé l'attaque motorité de la boite du lapin permettant l'ouverture et la fermeture de la boite. En effet, à l'aide d'un servo moteur que nous fixons minutieusement à la parois interieur superieur de la boite. Auquel nous vissons, un tige metalique que l'on courbe, tel un crochet. De l'autre coté, sur deuxieme porte de la boite se trouve un ecrou qui servira de maintient lorsque le crochet sera aggripé dedans et une fois le servo activé, le corchet se lebère de la tigee et ainsi les deux potres de la boites sont libres ( et donc tombe sous l'effet de leurs poids). Voici une image plus comprénsible du mecanisme: [IMAGE A METTRE].
      
  </p>
  <p> Ainsi nous réalisons apres un quelques temps que le systeme n'est pas completement stable ( risque de bascule sur les cotés). Ainsi j'ai l'idée d'inserer de la mousse dans les fentes du bas pour stabiliser le tout mais egalement pour tenter de ralentir la chute de la boite qui semble etre très rapide et qui pourrait entrainer un risque de casse du servo moteur </p>
      
  <li><ul><h3>Les problèmes de la boite à lapin </h3</ul>
  <li><ul><h4> Poblème de place </h4></ul>
    <p></p></li>
  <li><ul><h4> Un simple bouton poussoir</h4></ul>
    <p></p></li>
  </li>
      
