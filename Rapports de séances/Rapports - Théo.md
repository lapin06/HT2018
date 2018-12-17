
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
    <img src=../Ressources/cablage.jpg>
   <p>On peut donc y lire à gauche le clablage relatif au branchement dans notre boite à feutre et à droite les branchements relatif à notre boite ou se situe notre prédiction ( le lapin ).
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
<h2> Séance 2 - 17/12/18 - Les capteurs et differents calculs </h2>
<li>   
  <ul><h3>Les branchements des Capteurs et Porgramme</h3></ul>
    <p>Le materiel a été livré nous allos donc pouvoir commencer. Suite au programme fait précédemment, j'effectue les branchements que vous pouvez voir ci-dessous.</p>
    <p> Je televerse donc le programme 1-LECTURE_CAPTEUR afin de voir si tout fonction. Tout fonctionne, si un feutre est retirer la littre ralatif au premier mot de la couleur s'affiche. Ainsi pour un feutre retirer nous avons la couleur qui a été choisis par le spectateur. Il faut cependant prendre en compte comportement du spectateur qui peut prendre deux feutres, pour essayer de nous faire echoucher. C'est la raison pourlaquelle j'ai rajouter une condition qui fait que si le feutre n'a pas été remis dans le pot ou si deux feutres ont été choisi un message s'affiche afin que le lapin dise subtilement au spectateur de ne choisir qu'un feutre. Attention ce message doit etre assez subtile pour que le spetctateur repose son feutre sans se rendre compte que nous savons qu'il a prit deux fautre sinon il n'y a plus d'interet a ce tour.</p>
    </p></li>
     <img src=s2.png>
     <br>
     
     
<li>   <ul><h3>Etudes des comportements des Capteurs et mise en situation</h3></ul></li>
    <p> Suite a une mise en situation des 4 feutres et des 4 marqueurs nous remarquons quelques imprevus:</p>
  <li><ul> Si les Capteurs sont plonger dans de l'oscurité ou en exposition à la lumiere, la distance de détéction du feutre n'est pas la meme. Vous pouvez en effet voir ceci ci dessous.</ul>
    <li><ul>Tout les capteurs ne sont pas sensible exactement de la même maniere.</ul></li>
    <li><ul>La taille des capteur est plus imposante que prevu du a la carte a puce.</ul></li>
    <img src=../Ressources/Capteur_Etapes.PNG>
      
Ainsi le positionnement des capteurs dans la boites est remise en question:
<li>
  <ul>Posé au fond du pot a crayon et orienté vers le ciel;</ul>
  <p>       avantage:       fonctionne toujours</p>
  <p>        inconveniant:  Risque d'etre visible par le spectateur</p>
  </li>
  
<ul>Plaqué contre une parois</ul>
  <p>       avantage:       Invisible pour le spectateur</p>
  <p>       inconveniant:   Une plus grosse boite est necessaire , quelques problemes pour certains capteur du a l'obscurité<p>
    </li>

<li>   
  <ul><h3>Quelques lois de mails</h3></ul>
    <p>
    </p></li>
    
    
    
