#include "bits/stdc++.h"
#define definir_tipo typedef
#define principal main
#define retornar return
#define usando using
#define espacio_de_nombre namespace
#define cadena string
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
definir_tipo int entero;
definir_tipo long long largo_largo;
definir_tipo long int entero_largo;
definir_tipo short int entero_corto;
definir_tipo __int128 __entero128;
definir_tipo float flotar;
definir_tipo double doble;
definir_tipo char caracter;
definir_tipo void nada;
definir_tipo unsigned int no_signeado_entero;
definir_tipo unsigned long long no_signeado_largo_largo;
definir_tipo unsigned long int no_signeado_entero_largo;
definir_tipo unsigned short int no_signeado_entero_corto;
definir_tipo unsigned __int128 no_signeado___entero128;
usando espacio_de_nombre std;
estructura Arista{
    entero v;
    largo_largo Peso;
    Arista(entero b, largo_largo p){
        v = b;
        Peso = p;
    }
};
bool operador<(constante Arista& a, constante Arista& b){
    si(a.Peso < b.Peso) retornar 1;
    si(a.Peso > b.Peso) retornar 0;
    retornar a.v < b.v;
}
entero principal(){
    base_de_ios::sincronizar_con_stdio(0);
    centrada.empate(NULO);
    entero n, m;
    centrada>>n>>m;
    conjunto<Arista> Cola;
    vector< vector<Arista> > Grafo(n);
    mientras(m--){
        entero a, b;
        largo_largo c;
        centrada>>a>>b>>c;
        a--;
        b--;
        Grafo[a].empujar_atr_s(Arista(b, c));
    }
    vector<largo_largo> Distancias(n, MUCHO);
    Distancias[0] = 0LL;
    Cola.insertar(Arista(0, 0LL));
    mientras(!Cola.vac_o()){
        entero Nodo = Cola.inicio()->v;
        largo_largo Distancia = Cola.inicio()->Peso;
        Cola.borrar(Cola.inicio());
        si(Distancia > Distancias[Nodo]) continuar;
        para(autom_tico E: Grafo[Nodo]){
            si(Distancias[E.v] <= Distancia + E.Peso) continuar;
            Distancias[E.v] = Distancia + E.Peso;
            Cola.insertar(Arista(E.v, Distancias[E.v]));
        }
    }
    para(autom_tico E: Distancias) csalida<<E<<" ";
    retornar 0;
}