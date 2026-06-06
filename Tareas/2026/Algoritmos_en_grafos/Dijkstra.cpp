#include "bits/stdc++.h"
#define definir_tipo typedef
#define principal main
#define retornar return
#define usando using
#define espacio_de_nombre namespace
#define cadena string
#define tupla tuple
#define intercambiar swap
#define la_transmisi_n_en_vivo_de_cadena stringstream
#define centrada cin
#define csalida cout
#define cerror cerr
#define imprimirf printf
#define escanearf scanf
#define NULO NULL
#define base_de_ios ios_base
#define sincronizar_con_stdio sync_with_stdio
#define mientras while
#define para for
#define hacer_mientras do_while
#define ordenar sort
#define inicio begin
#define fin end
#define rinicio rbegin
#define rfin rend
#define siguiente_permutaci_n next_permutation
#define empujar_atr_s push_back
#define eliminar_atr_s pop_back
#define empujar_adelante push_front
#define eliminar_adelante pop_front
#define eliminar pop
#define empujar push
#define cima top
#define vac_o empty
#define cola_de_prioridad priority_queue
#define m_s_grande greater
#define menos less
#define mayor_o_igual greater_equal
#define less_equal menor_o_igual
#define plantilla template
#define primero first
#define segundo second
#define estructura struct
#define conjunto set
#define mapa map
#define autom_tico auto
#define insertar insert
#define contar count
#define borrar erase
#define asignar assign
#define encontrar find
#define l_mite_inferior lower_bound
#define l_mite_superior upper_bound
#define empate tie
#define subcadena substr
#define conseguir_l_nea getline
#define par pair
#define hacer_par make_pair
#define finl endl
#define tama_o size
#define tama_o_de sizeof
#define conjunto_de_memorias memset
#define m_nimo min
#define m_ximo max
#define __mcd __gcd
#define valor_absoluto abs
#define si if
#define interruptor switch
#define cola queue
#define pila stack
#define constante const
#define si_no else
#define corriente_de_entrada_salida iostream
#define romper break
#define continuar continue
#define caso case
#define mapa_desordenado unordered_map
#define conjunto_desordenado unordered_set
#define atr_s back
#define frente front
#define estructura struct
#define clase class
#define privado private
#define p_blico public
#define permutaci_n_previa prev_permutation
#define falso false
#define verdadero true
#define revertir reverse
#define llenar fill
#define YYYY and //No parecía muy buena idea tener definiciones con una sola letra.
#define OOOO or
#define operador operator
#define MUCHO LLONG_MAX
#define mucho INT_MAX
#define poco INT_MIN
#define POCO LLONG_MIN
#define conjunto_de_bits bitset
#define asignar assign
#define ra_z_cuadrada sqrt
#define ra_z_c_bica cbrt
#define freabrir freopen
#define si_transmisi_n_en_vivo ifstream
#define de_transmisi_n_en_vivo ofstream
#define est__abierto is_open
#define cerrar close
#define conseguir get
#define techo ceil
#define piso floor
#define redondear round
#define poder pow
#define l_mites_num_ricos numeric_limits
definir_tipo int entero;
definir_tipo long long largo_largo;
definir_tipo long int entero_largo;
definir_tipo short int entero_corto;
definir_tipo __int128 __entero128;
definir_tipo float flotar;
definir_tipo double doble;
definir_tipo long double doble_largo;
definir_tipo char caracter;
definir_tipo void nada;
definir_tipo unsigned int no_signeado_entero;
definir_tipo unsigned long long no_signeado_largo_largo;
definir_tipo unsigned long int no_signeado_entero_largo;
definir_tipo unsigned short int no_signeado_entero_corto;
definir_tipo unsigned __int128 no_signeado___entero128;
definir_tipo bool booleano;
usando espacio_de_nombre std;
estructura Arista{
    entero v;
    doble_largo Peso;
    Arista(entero b, doble_largo p){
        v = b;
        Peso = p;
    }
};
estructura Punto{
    doble_largo x, y;
    Punto(entero a, entero b){
        x = (doble_largo)a;
        y = (doble_largo)b;
    }
    doble_largo Distancia(constante Punto& a){
        retornar ra_z_cuadrada((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }
};
booleano operador<(constante Arista& a, constante Arista& b){
    si(a.Peso < b.Peso) retornar 1;
    si(a.Peso > b.Peso) retornar 0;
    retornar a.v < b.v;
}
entero principal(){
    base_de_ios::sincronizar_con_stdio(0);
    centrada.empate(NULO);
    entero Inicio, Final;
    cadena Origen, Destino;
    conjunto<Arista> Cola;
    vector<Punto> Lugares = {Punto(0, 0), Punto(1, 1), Punto(2, 2), Punto(1, 0), Punto(0, 1), Punto(2, 0), Punto(0, 2), Punto(2, 1), Punto(1, 2), Punto(3, 3), Punto(2, 3), Punto(3, 2)};
    vector< vector<Arista> > Grafo(12);
    mapa<cadena, entero> Mapita;
    Mapita["Universidad Cat_lica Boliviana"] = 0;
    Mapita["Estadio"] = 1;
    Mapita["Plaza Murillo"] = 2;
    Mapita["Prado"] = 3;
    Mapita["Mercado De Las Brujas"] = 4;
    Mapita["Mirador Killi Killi"] = 5;
    Mapita["Valle De La Luna"] = 6;
    Mapita["Plaza Avaroa"] = 7;
    Mapita["Calle Sagarnaga"] = 8;
    Mapita["Museo Nacional De Arte"] = 9;
    Mapita["Parque Bartolina Sisa"] = 10;
    Mapita["Bosque De Bolognia"] = 11;
    mapa<entero, cadena> Revertir;
    para(autom_tico E: Mapita){
        Revertir[E.segundo] = E.primero;
    }
    vector< par<entero, entero> > Aristas;
    Aristas.empujar_atr_s(hacer_par(0, 3));
    Aristas.empujar_atr_s(hacer_par(0, 4));
    Aristas.empujar_atr_s(hacer_par(3, 7));
    Aristas.empujar_atr_s(hacer_par(5, 7));
    Aristas.empujar_atr_s(hacer_par(5, 11));
    Aristas.empujar_atr_s(hacer_par(4, 6));
    Aristas.empujar_atr_s(hacer_par(4, 2));
    Aristas.empujar_atr_s(hacer_par(1, 6));
    Aristas.empujar_atr_s(hacer_par(1, 2));
    Aristas.empujar_atr_s(hacer_par(1, 8));
    Aristas.empujar_atr_s(hacer_par(7, 2));
    Aristas.empujar_atr_s(hacer_par(6, 10));
    Aristas.empujar_atr_s(hacer_par(8, 10));
    Aristas.empujar_atr_s(hacer_par(2, 9));
    Aristas.empujar_atr_s(hacer_par(11, 9));
    Aristas.empujar_atr_s(hacer_par(10, 9));
    para(autom_tico E: Aristas){
        entero a = E.primero, b = E.segundo;
        Grafo[a].empujar_atr_s(Arista(b, Lugares[a].Distancia(Lugares[b])));
        intercambiar(a, b);
        Grafo[a].empujar_atr_s(Arista(b, Lugares[a].Distancia(Lugares[b])));
    }
    cerror<<"¿Cuál es el lugar inicial?\n";
    conseguir_l_nea(centrada, Origen);
    si(Mapita.contar(Origen) == 0){
        csalida<<"No se encuentra el origen entre los lugares disponibles.\n";
        retornar 0;
    }
    cerror<<"¿Cuál es el lugar final?\n";
    conseguir_l_nea(centrada, Destino);
    si(Mapita.contar(Destino) == 0){
        csalida<<"No se encuentra el destino entre los lugares disponibles.\n";
        retornar 0;
    }
    Inicio = Mapita[Origen];
    Final = Mapita[Destino];
    vector<doble_largo> Distancias(12, (doble_largo)222222);
    vector<entero> Padres(12, -2);
    Distancias[Inicio] = (doble_largo)0;
    Cola.insertar(Arista(Inicio, (doble_largo)0));
    mientras(!Cola.vac_o()){
        entero Nodo = Cola.inicio()->v;
        doble_largo Distancia = Cola.inicio()->Peso;
        Cola.borrar(Cola.inicio());
        //cerror<<Padres[Nodo]<<" "<<Nodo<<" "<<Distancias[Nodo]<<"\n";
        si(Distancia > Distancias[Nodo]) continuar;
        para(autom_tico E: Grafo[Nodo]){
            si(Distancias[E.v] <= Distancia + E.Peso) continuar;
            Distancias[E.v] = Distancia + E.Peso;
            Cola.insertar(Arista(E.v, Distancias[E.v]));
            Padres[E.v] = Nodo;
        }
        /*para(autom_tico E: Distancias){
            cerror<<E<<" ";
        }
        cerror<<"\n";*/
    }
    si(Distancias[Final] >= (doble_largo)2222){
        csalida<<"No se puede llegar de"<<Origen<<" a "<<Destino<<".";
        retornar 0;
    }
    csalida<<"La distancia entre "<<Origen<<" y "<<Destino<<" es "<<Distancias[Final]<<".\nLa ruta es: ";
    vector<entero> Ruta;
    para(entero Nodo = Final; Nodo != -2; Nodo = Padres[Nodo]){
        Ruta.empujar_atr_s(Nodo);
    }
    revertir(Ruta.inicio(), Ruta.fin());
    csalida<<Revertir[Ruta[0]];
    para(entero i = 1; i < Ruta.tama_o(); i++){
        csalida<<" -> "<<Revertir[Ruta[i]];
    }
    csalida<<".";
    retornar 0;
}