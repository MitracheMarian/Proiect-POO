# Proiect-POO TEMA 22
## Titlul proiectului: Platforma de tutoriale video
Programul va contine un fisier in care se vor gasi informatii despre tutorialele video. Acestea vor fi asezate in mai multe categorii. Fiecare tutorial video va avea:
- id
- topic
- titlu
- descriere

Un fisier in care se vor gasii detaliile despre utilizatori:
- tip
- user
- parola

Un fisier menit sa stocheze accesarile de tutoriale ale studentilor:
- studentul care a accesat
- id-ul tutorialului accesat
- data la care a accesat
- ora la care a accesat

Sunt prezente urmatoarele clase:
- Utilizator care se ocupa cu stocarea datelor despre utilizatori
- Admin care se ocupa cu atributiile pe care le are adminul
- Student care se ocupa cu atributiile pe care le are studentul
- Tutorial care se ocupa cu stocarea datelor despre tutoriale
- Istoric care se ocupa cu socarea datelor de accesare ale studentilor
- IncarcareActualizare care se ocupa cu incarcarea datelor din fisier si actualizarea fisierelor
- Platforma este cea care uneste toate aceste functionalitati

Fiecare categorie de persoane va avea anumite atribute cum ar fi: 
- Administratorul poate adauga persoane sau sa le stearga, poate adauge tutoriale video sau sa le stearga, sa acceseze un istoric al cautarilor studentilor, sa acceseze lista de tutoriale sau lista de utilizatori;
- Studentul poate cauta dupa topic si viziona tutoriale, acesta avand si un istoric al videoclipurilor accesate;
- Vizitatorul poate doar sa vada lista de tutoriale.
