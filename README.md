# Programmazione 1

## Compilatore
g++ <nomefile.cc> -> compila file (comando da eseguire all'interno della cartella del file).
COMPILAZIONE file MULTIPLI (al file principale do il nome main): g++ <main.cc>
./a.out -> esegue l'ultimo file compilato.
ls -> mostra percorsi all'intermo del percorso in cui sono.
cd <nomepercorso> -> apre il percorso scritto.
cd /mnt/c/esempiP1 -> va alla cartella esempi Programmazione 1 su Windows 11.

## Git
git clone <link> -> clona repository sulla macchina locale.
git add . -> aggiunge tutte le modifiche effettuate nel repository alle modifiche che verrano salvate.
git commit -m "<messaggio>" -> salva tutte le modifiche sul repository locale.
git push -> invia le modifiche del repository locale online.
git pull -> copia le modifica, del repository da github a locale.

## Valgrid
INSTALLARE:
  sudo apt update
  sudo apt upgrade
  sudo apt install valgrind
  valgrind --version   //Verifica installazione
COMPILAZIONE ed ESECUZIONE:
  g++ -g nomefile.cc
  valgrind ./a.out

## SEQUENZE DI ESCAPE COMUNI:
Escape    Character represented
  \b        Backspace (cancella un carattere a sinistra)
  \n        Newline (va a capo)
  \t		    Tab
  \\		    Backslash (\)
  \'		    Apostrofo
  \"		    Virgolette

## Valori Buleani
NOT (!) = valore opposto di quel valore (si usa una una sola variabile)
AND (&&) = stesso valore restituisce quel valore 
OR (||) = true se un valore è true
XOR = true se sono valori diversi (true o false)
  valore booleano:    true = 1     false = 0
  valore booleano: true=1 false=0

## Maiuscole e minuscole
(a sempre minore b, A sempre minore a)
Assumo che il valore delle Maiuscole precede le minuscole
E carattere in input è una lettera
Maiuscole = minore di 91
minuscole = maggiore di 91
Assumo che il valore delle minuscole precede le Maiuscole

## Variabili
Se inizializzo variabile senza assegnarli valore fuori main è una variabile globale con valore = 0.
Se inizializzo variabile dentro main senza assegnarli valore non so quale valore assume.
QUINDI assegna sempre valore a variabile inizializzata.
IN GENERALE: cercare di NON usare variabili globali, in caso devono essere costanti e con nomi maiuscoli (es: const int Y;).

## Espressione condizionale ( condizione ? valore_se_vero : valore_se_falso )
ESEMPIO SEMPLICE ( i==5 ? n=1  : n=0 ):
if (i==5) {
  n=1;
} else {
  n=0;
}
ESEMPIO COMPLESSO ( found ? location-1 : -1 ):
if (found) {
  return location - 1; // Restituisce questo se 'found' è vero
} else {
  return -1;           // Restituisce questo se 'found' è falso
}

## Ordine operatori (dal più alto al più basso)
Operatori unari e di precedenza più alta: ::, (), ++ (prefisso), sizeof, * (indiretto), & (indirizzo), ~, !.
Moltiplicativi: * (moltiplicazione), / (divisione), % (modulo).
Additivi: + (addizione), - (sottrazione).
Shifts bit a bit: <<, >>.
Relazionali: <, <=, >, >=.
Di uguaglianza: ==, !=.
AND bit a bit: &.
OR bit a bit: ^.
OR esclusivo bit a bit: |.
AND logico: &&.
OR logico: ||.
Espressione condizionale: ?:.
Assegnazione: =, +=, -=, *= ecc.

## LIBRERIE UTILI
#include <iomanip>
  setw(n) //Stampa n spazi.
  numero << setprecision(n) //Stampa n cifre del "numero" (senza approssimazione).
  numuro << fixed << setprecision(n) //Stampa n cifre di "numero" (con approssimazione).
#include <cctype>
  isalnum(c) //Carattere "c" è alfanumerico? True=1 False=0.
  toupper(c) //Converte "c" da minuscola a Maiuscola (NB: SOLO SE "c" è minuscolo NON il contrario o altri casi).
#include <cstdlib>
  srand(time(NULL)); //(quando inizializzo)  ->  rand() //(quando la uso).
  atoi(argv[1]) //Converte una stringa in int.
  atof(argv[2]) //Converte una stringa in double.
#include <cstring>
  strlen(s) //Lunghezza stringa "s" senza terminatore.
  strcpy(s,t) //Copia (sovrascrivendo) stringa "t" in stringa "s" e restituisce "s".
  strcat(s,t) //Copia in coda stringa "t" in stringa "s" e restituisce "s".

## TUTTI I CASI DI UTILIZZO PUNTATORI
| Cosa voglio fare                   |        Sintassi       | Perché                                            |
| ---------------------------------- | --------------------- | ------------------------------------------------- |
| Puntare a una variabile normale    |        *p = &x        | x non è un indirizzo                              |
| Puntare a un puntatore             |        *p = &p        | serve l’indirizzo del puntatore                   |
| Copiare un indirizzo già esistente |  (*p = &x) -> *q = p  | p (essendo un puntatore) contiene già l’indirizzo |
## Quando usare Riferimento o Puntatore
|   Caso                                      | Usa riferimento | Usa puntatore |
| ------------------------------------------- | --------------- | ------------- |
| Modificare una variabile passata a funzione |   ✔️            |   ✔️         |
| Evitare valori nulli                        |   ✔️            |   ❌         |
| Devi poter cambiare ciò a cui “punta”       |   ❌            |   ✔️         |
| Allocazione dinamica                        |   ❌            |   ✔️         |
| Strutture dati dinamiche (liste, alberi)    |   ❌            |   ✔️         |
## Puntatori (*pd) RICORDA: puntatore ha come valore l'indirizzo della variabile a cui punta
1) INZIALIZZAZIONE: int *pd = &x (NOTA: Sempre inizializzare puntatore e dirgli a cosa puntare).
2) Nuova variabile (con suo spazio in memoria). 
3) IMPORTANTE: puntatore punta all'indirizzo di un'altra variabile assumendo come valore il suo indirizzo, però se uso *pd ottengo anche valore a cui punta.
4) L'indirizzo a cui punta il puntatore può essere cambiato
5) ESEMPIO: *pd = 5 (cambia il valode di pd con 5).
## Altre tipologie di puntatori
1) Puntatori a void
2) Puntatori a costante
3) Costanti puntatori
4) Costanti puntatore a costante
5) Puntatori a puntatori
## Riferimenti a
1) INZIALIZZAZIONE: int &y = x
2) Alias (sinonimo) di una variabile, NON è una copia di quella variabile.
3) Non ha uno spazio in memoria dedicato.
4) Dopo esser stato inizializzato e legato PER SEMPRE a quella variabile, non si può "sciogliere" il legame o cambiare variabile.
## Significato operatori "&" e "*"
&x -> ottengo indirizzo di x (variabile)
*pd -> ottengo valore numerico di pd (puntatore) -> INFATTI: Se scrivessi SOLO pd -> otterei indirizzo di pd (puntatore).

## Funzioni o Procedure (NOTA: procedura = funzione void)
1) funzione int, double, ... = FUNZIONE
2) funzione void = PROCEDURA
1. parametri formali = parametri della definizione
2. parametri attuali = parametri della chiamata

## FUNZIONI RICORSIVE
├── VOID (produce effetti)
|     |
|     ├── tail recursive (chiamata ricorsiva = ultima istruzione)
|     |
|     └── NON tail recursive (c'è codice dopo la chiamata ricorsiva)
│
|
└── RETURN (produce un valore)
      |
      ├── calcolo al RITORNO
      |                 |
      │                 └── NON tail recursive (c'è codice dopo la chiamata ricorsiva)
      |
      └── calcolo all’ANDATA (con accomulatore)
                        |
                        └── tail recursive (chiamata ricorsiva = ultima istruzione)

## Array e Funzioni
Gli array vengono passati per riferimento alla funzione (cioè sono dei puntatori), allora è meglio mettere davanti "const" a "int myArray [dim]" (dim è un numero costante); int funzione (const int myArray [dim]);
Quando passi un array a una funzione, diventa un puntatore, la dimensione si perde.
Negli array 1D il compilatore non ha bisogno della dimensione, semplicemente gli scorre tutti un numero stabilito di volte (dim).
Negli array 2D invece DEVE sapere la dimensione della riga, serve la seconda dimensione (DIM2) che indica il numero di colonne (cioè gli elementi di ogni riga prima di dover passare alla riga successiva).

## Stringhe
- cin.getline(s, DIM) -> legge
...