Hola = [
"Estaba la pajara pinta a la sombra del verde limon con el pico picaba la rama con las alas recoge la flor".split(),
"Homero Simpson".split(),
"Este problema no tiene acentos o simbolos raros del espanol a proposito".split(),
"alguna vez pensaron que podria pasar si una persona absolutamente sin conocimientos de LLM se pone a querer disenar una LLM".split(),
"La llamariamos PLM Pathetic Language Model".split(),
"Saben lo que es una LLM Veamos la definicion segun Pepe Argento".split(),
"Una LLM es como una maquina que se trago medio internet libros pavadas discusiones de gente al pedo y ahora te contesta como si supiera Vos le preguntas algo y la cosa esa arma una respuesta palabra por palabra tratando de sonar inteligente".split(),
"Ahora como creamos una PLM Y no se pero va a ser tu trabajo al final de este problema".split(),
"Nuestro amigo Penguino esta creando una PLM pero decide alimentarla de informacion absolutamente necesaria es decir sus problemas de la OBI algunas frases de sus series favoritas y claro ehhh sus canciones favoritas".split(),
'Por ejemplo escucharon esa que dice Por favor te lo pido solo vete no penses que esto es amor yo se que nada es pa siempre'.split(),
"Leyeron Mafalda Siempre me rio con esta tira".split(),
"QUE OPINAN EN TU CASA DE COMO ANDAN LAS COSAS PUF POR LO MENOS SON OPTIMISTAS EN LA MIA OPINAN QUE PUAJ".split(),
"Podrian demandarme por incluir esa imagen Ojala que no Por cierto PARAPATINTINTIRINTIN".split(),
'En fin me estoy desviando de la tematica del problema donde estaba Ah si Series favoritas ehmmm A penguino le encanta Los simpsons How I Met Your Mother LOST The office Severance Vieron el final de la primera temporada QUE FINAL SHE IS ALIVE'.split(),
"Y los numeros de LOST cuatro ocho quince dieciseis veintitres cuarenta y dos top numeros de la historia un sinsentido monumental pero dentro de la serie encajaba lo juro".split(),
"Ok ya PLMs Crear una PLM es como comer una naranja.".split(),
"Bueno la verdad ya me aburri de redactar es momento de revelar la verdadera identidad de Penguino: Penguino es el verdadero creador de estos problemas".split(),
"Pensaron que Penguino era Dario No senor Dario murio de una sobredosis de azucar el Octubre del 16.".split(),
"Pero revivio Ahora esta vivo".split(),
"Fua quisiera contar esa historia pero que flojera seguuir redactando".split(),
"Ah si una PLM agarra un texto y solo produce la siguiente palabra dependiendo de la palabra previa".split(),
"Basate en el contenido de este problema y como haria Penguino una PLM para hacer la tuya".split(),
"La entrada contiene muchas palabras cada una en una linea La ultima palabra es MAGUMBO".split(),
'Para cada palabra tu PLM debe predecir la palabra que sigue no imprimas nada para la palabra MAGUMBO'.split(),
'Si no hay continuacion para la palaaabra que se te da imprime LOL'.split(),
'Y si no entrenamos con esa palabrita no se imprime XDDDDDDD'.split(),
'Cada caso de prueba tendra palabras de una sola linea de texto usada para entrenar a la PLM'.split(),
'puntos Cada caso de prueba da puntos son casos de prueba'.split()]
while True:
    Siguiente = "Nada_por_ahora."
    Palabra = input()
    if Palabra == "MAGUMBO":
        exit(0)
    Mal = False
    Hay = False
    Lol = False
    for x in Hola:
        i = 0
        Posici_n = []
        while i < len(x):
            if x[i] == Palabra:
                Posici_n.append(i)
            i += 1
        for p in Posici_n:
            Hay = True
            if p + 1 < len(x):
                if Siguiente != "Nada_por_ahora.":
                    Mal = True
                Siguiente = x[p + 1]
            else:
                Lol = True
    if Mal:
        print("MAGUMBO")
    elif not Hay:
        print("XDDDDDDD")
    elif Lol:
        print("LOL")
    else:
        print(Siguiente)