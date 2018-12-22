


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
    <p> Suite a une mise en situation des 4 feutres et des 4 marqueurs nous remarquons quelques imprevus. En effet, si les capteurs sont plongés dans de l'oscurité ou en exposition à la lumiere, la distance de détéction du feutre n'est pas la même. De plus, tout les capteurs ne sont pas sensible exactement de la même maniere.Enfin, la taille des capteur est plus imposante que prevu du à la carte a puce, etc...
    <img src=../Ressources/Capteur_Etapes.PNG>
      <p><em>-------------------------------------------- Distance de detection des capteurs ------------------------------------------------</em></p>
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
 <h2> Séance Bonus Vacance - 21/12/18 - Nos premières créations </h2>
  <li><ul><h3> Conception de notre boite à feutre</h3></ul>
  
  <p> Nous nous retrouvons aujourd'hui a la Fablab de la Telecom Valley sur le site des Templier pour réaliser notre boite un feutre. Je rappelle que le but de cette boite et de ressembler a un pot a feutre tout à fait classique, mais qui doit en realiter cacher tout notre premier assemblage que vous pouvez retrouver dans Séance 1 de mon rapport précédent. Suite au test effectué durant les séances précédentes je peux donc commencer à dresser un plan de notre Boite, en parallèle de ca mon Binome dresse également un autre plan pour que nous puissons choisir le plus facile à réaliser. Ainsi que le pot le plus naturel, non suspect. Passons a la réalisation.</p>
  <br>
  <p><em>--------------------------------------------------------1.Planification--------------------------------------------------------------</em></p>
   <img src=../Ressources/boite11.PNG>
  <p><em>--------------------------------------------------------2.Modélisation---------------------------------------------------------------</em></p>
   <img src=../Ressources/boite22.PNG>
  <p><em>--------------------------------------------------------3.Découpage Laser------------------------------------------------------------</em></p>
  <img src=../Ressources/boite 44.PNG>
  <a href=https://www.youtube.com/watch?v=cO1AD-aDM-o> video </a>
  <p><em>--------------------------------------------------------4.Assemenblage---------------------------------------------------------------</em><p>
   <img src=../Ressources/boite33.PNG>
 </li>
  
    
    
