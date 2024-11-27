                  Platformă de educație online 
Introducere În era digitală, sistemele de educație online au devenit din ce în ce mai populare. Aceste platforme permit studenților să acceseze cursuri și materiale de studiu oriunde și oricând. În acest proiect, vom crea o platformă care permite gestionarea cursurilor online și înscrierea studenților folosind concepte de programare orientată pe obiecte (POO). Platforma va oferi funcționalități de bază precum: 
• Adăugarea și gestionarea cursurilor.
• Înscrierea și administrarea studenților la cursuri.
• Vizualizarea informațiilor despre cursuri și elevi.
Descrierea datelor de intrare și ieșire
Date de intrare: o Elevi: Numele, ID-ul, user ,parola, datele de contact și lista de cursuri la care sunt înscriși. o Cursuri: Numele cursului, profesorul responsabil, numărul maxim de elevi și lista elevilor înscriși. o Profesori: Numele profesorului, user , parola și cursurile pe care le predă, sterge si adauga elevi. o Admin : Tine evidenta cursurilor , are user si parola adauga si sterge elevi , profesori si cursuri
Date de ieșire: o Liste cu cursurile disponibile și detaliile fiecărui curs. o Liste cu elevii înscriși la fiecare curs. o Detalii individuale despre un elev, incluzând cursurile la care acesta este înscris . o Detalii despre un curs, incluzând lista elevilor și profesorul responsabil.
Modul de rezolvare Vom folosi clase pentru a modela principalele entități din platformă:
Clasa Student: Această clasă va reprezenta un elev înscris pe platformă.
Clasa Curs: Clasa care reprezintă un curs disponibil pe platformă.
Clasa Profesor: Reprezintă profesorul care predă unul sau mai multe cursuri.
Clasa Admin : Reprezinta adminul ce gestioneaza cursurile , elevii si profesorii.
Clasa PlatformaEducatie: Sistemul principal care gestionează cursurile, profesorii și elevii. 
Fiecare clasă va avea proprietăți și metode specifice, folosind principiile de incapsulare, moștenire și polimorfism, acolo unde este necesar
