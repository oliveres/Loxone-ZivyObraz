# Loxone-ZivyObraz
Kód Pico C do Loxone pro posílání dat 1x za 5 minut do ŽivýObraz.eu

1. V Loxone Configu si přidejte na Miniserver "Virtuální výstup" a nastavte adresu pro poosílání dle dokumentace (http://in.zivyobraz.eu) bez lomítka na konci
2. Pod tento "Virtuální výstup" vytvořte "Virtuální výstup příkazu" a v nastavení ponechte GET do pole "Instrukce při zapnutí" vložte následující příkaz `?import_key=apiklic<v>` (ano, na konci klíče je `<v>` bez znaku `&` protože toto je řešeno v programu)
3. Přidejte funkční blok "Program" a vložte do něj kód z tohoto repozitáře, upravte v něm podle potřeby na začátku počet hodnot které budete posílat a jejich názvy
4. Propojte Txt1 výstup bloku "Program" s Virtuálním výstupem příkazu, který jste před tím vytvořili. Na vstupy I1 - I13 podle potřeby můžete posílat hodnoty

Upozorňuji, že na ŽivýObraz se hodnoty objeví až po 5 minutách! Případně upravte řádek `26` kódu a místo 300 dejte 30 pro testování, pro trvalé nasazení nastavte 300 vteřin (5 minut), toto je smysl tohoto programu.
