# **The good, the bad and the zombie**

## Assignment for "Programming Techinques" at National Technical University of Athens department of Electrical and Computer Engineering.

---

**The good, the bad and the zombie**

The game consists of Good, bad and zombie characters. Each character has 100 hit points in a circular linked list (world).

Bad characaters can attack both good and zombie.

Good characters can attack both bad and zombie. When they hit a zombie, they have 20% probability to cure it with 40% probability to become good and 60% bad character.

Zombie characters can attack both good and bad. They have 10% to turn them to zombies in each attack.

Each character is created in a wrapper class Person. The game ends when all characters are one kind in the world.


Report:

Δομή του Προγράμματος:
Οι κλάσεις του προγράμματος είναι: Η κλάση wrapper Person
H κλάση Character
H κλάση Good
H κλάση Bad
H κλάση Zombie H κλάση World
Η κλάση wrapper Person:
-Έχει ένα ακέραιο αριθμό hit_points που δειχνεί τους πόντους του person. -Ένα δείκτη σε χαρακτήρα της character με τον οποιόν είναι συνδεμένος ο person. (has_character)
-Την λογική μεταβλήτη is_dead που μαζί με την μέθοδο die η οποία δεχέται τα hit_points του person μας δείχνει αν το αντικείμενο person πρέπει να διαγραφτεί από το παιχνίδι (στην περίπτωση που hit_points==0 και is_dead==true)
-Την μέθοδο hit που δέχεται ως όρισμα έναν person στον οποίο γίνεται η επιθέση και αναλόγα με το person που την κάλεσε καλεί την virtual attack και της περνάει τον person στον οποίο γίνεται η επιθέση.
-Την μέθοδο get_hp η οποία επιστρέφει τους πόντους του person που την καλεί.
-Την μέθοδο Type η οποία καλεί την get_character_type.
-Έναν constructor (όχι τον default) που δέχεται έναν ακέραιο και με την χρήση της switch δημιουργεί τους χαρακτηρές της character.
Η κλάση Character:
-Έχει ένα δείκτη σε στοιχείο της person με τον οποιόν είναι συνδεμένος ο character. (is_attached_to)
-Την μέθοδο get_character_type που δέχεται ως όρισμα έναν person και επιστρέφει τον τύπο του character με τον οποίο είναι συνδεδεμένος ο person. -Έναν ακέραιο character_points που δείχνει τους πόντους του χαρακτήρα character και κατά συνέπεια είναι ίδιος με τα hit_points του person.
-Την μέθοδο lower_hp η οποία μείωνει τους πόντους character_points.
-Την μέθοδο convert η οποία δέχεται ως ορίσματα τον χαρακτήρα που θα αλλάξουμε και έναν ακέραιο ο οποίος χρησιμοποιείται από την switch για να αλλάξει κατάλληλα τον χαρακτήρα.
-virtual destructor
Η κλάση Good:
-Κληρονομεί την character και έχει επείσης την virtual μέθοδο attack. -virtual destructor
Η κλάση Bad:
-Κληρονομεί την character και έχει επείσης την virtual μέθοδο attack. -virtual destructor
Η κλάση Zombie:
-Κληρονομεί την character και έχει επείσης την virtual μέθοδο attack. -virtual destructor
Η κλάση World:
-Έναν constructor (οχι τον default) οποίος δέχεται ένα ακεράιο y και δημιουργει μια κυκλική λίστα μεγέθους y προσβάσιμη μόνο στην World.
-Την μέθοδο game που εκτελεί το παιχνίδι.
Σημαντικό είναι επίσης να αναφέρουμε ότι στις κλάσεις Person και Character έχουμε setters και getters για την ανάκτηση και την αλλαγή μεταβλητών που είναι private.
Ροή του προγράμματος:
Το πρόγραμμα έχει έναν ακέραιο αριθμό για να seed-άρει την rand() στην main τον οποίο τον έχω βάλει 999 (αλλάζει από τον κώδικα μόνο) και
δέχεται από τον χρήστη έναν ακέραιο αριθμό για το μέγεθος του κόσμου. Στην συνέχεια καλεί τον constructor της world, ο καλεί τον constructor της person οποίος δημιουργεί persons και characters με τυχαία πιθανότητα good,bad και zombie με την εντολη switch. (0 για good, 1 για bad και 2 για zombie) Oι persons που δημιουγούνται τοποθετούνται
στην κυκλική λίστα pList αφού πρώτα βάλουμε τα is_attached_to και character_points να δείχνουν σωστά με τις εξής εντολές:
p.gethas_character()->setis_attached_to(p); p.gethas_character()->setcharacter_points(p.gethit_points());
Δηλαδή με setters και getters αφού οι μεταβλητές είναι private.
Στην συνέχεια καλείται η μέθοδος Game στην οποία δημιουργούμε δύο
iterators it,in που δείχνουν στον person που επιτείθεται (προσωρινο pe) και που του επιτείθονται (προσωρινό next). Ο pe καλεί την hit και της περνάει με αναφορά τον person της in. Η hit καλεί ανάλογα με τον τύπο has_character του pe την attack της καταλληλης κλασης και της περνάει τον person της in με αναφορά.
Όπως έχει περιγραφτεί στην εκφώνηση η attack κάνει τον ελέγχο για του τύπους των pe, next και αντιστοιχα καλεί την lower_hp που μείωνει τα character_points ή την convert η οποία δέχεται ως ορίσματα τον χαρακτήρα που θα αλλάξουμε και έναν ακέραιο ο οποίος χρησιμοποιείται από την switch για να αλλάξει κατάλληλα τον χαρακτήρα (0 good, 1 bad και 2 zombie). H μέθοδος των αλλαγών είναι:
1)αν επιτιθεται bad τοτε μειωνει τα hit_points σε good και zombie κατα -10
2)αν επιτιθεται good τοτε μειωνει τα hit_points σε bad κατα -10 και εχει 20% πιθανότητα να γιατρέψει το zombie και να το κάνει 40% πιθ. good και 60% πιθ. bad με την convert διατηροντας τα hit_points του.
3)αν επιτιθεται zombie τοτε μειωνει τα hit_points σε bad και goof κατα -10 με 90% πιθανότητα ενώ με 10%πιθ. να τα μετατρέψει σε zombie με την convert διατηροντας τα hit_points του.
(Οι παραπάνω πιθανότητες υπολογίζονται με τυχαίο τρόπο από την rand() που

έχουμε seed-άρει).
Μετά το πέρας της attack η hit είναι υπεύθυνη για να φέρει τα hit_points και is_attached_to να δείχνουν σωστά και η ροή επιστρέφει στην game. Στην συνέχεια ελέγχουμε αν ο person που χτυπηθηκε ειναι νεκρος με την
die και αν ειναι τον διαγραφουμε απο την λιστα με την εντολή:
in=pList.erase(in);
O γυρος συνεχιζεται με τους καταλληλους ελεγχους και αλλαγες στους δείκτες in και it μέχρι it==pList.end() ή μέχρι να πεθάνει ο τελευταιος χαρακτήρας της λίστας pList. Μέτα το τελος του γυρου εμφανιζονται οι τυποι person που έμειναν μαζί με
hit_points τους και ελεγχουμε αν ειναι ολα ιδια ή όχι με τις done1 και done. Το i που δειχνει τους γυρους αυξανεται και συνεχιζεται το παιχνίδι μέχρι i==100 ή done=false.
Για το προγραμμα απαιτουνται τα εξης: #include <iostream>
#include <typeinfo>
#include <list>
#include <random> #include <stdlib.h> #include<time.h> using namespace std;


Παρακατω φαίνεται το διάγραμμα σχέσεων των κλάσεων:

[//]: # (Images)

[image1]: ./images/Image1.png "Image 1"

![image1]

---


