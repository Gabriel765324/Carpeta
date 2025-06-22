#include "combo.h"
#include "bits/stdc++.h"
using namespace std;
string guess_sequence(int n){
  string r;
  if(press("AB") > 0){
    if(press("A") == 1) r = "A";
    else r = "B";
  } else {
    if(press("X") == 1) r = "X";
    else r = "Y";
  }
  vector<string> Auxiliar;
  if(r == "A") Auxiliar = {"B", "XB", "XX", "XY"};
  else if(r == "B") Auxiliar = {"A", "XA", "XX", "XY"};
  else if(r == "X") Auxiliar = {"A", "BA", "BB", "BY"};
  else if(r == "Y") Auxiliar = {"A", "BA", "BB", "BX"};
  for(int i = 1; i < n - 1; i++){
    int Valor = press(r + Auxiliar[0] + r + Auxiliar[1] + r + Auxiliar[2] + r + Auxiliar[3]);
    switch(r[0]){
      case 'A':
        if(Valor == i) r += 'Y';
        else if(Valor == i + 1) r += 'B';
        else if(Valor == i + 2) r += 'X';
      break;
      case 'B':
        if(Valor == i) r += 'Y';
        else if(Valor == i + 1) r += 'A';
        else if(Valor == i + 2) r += 'X';
      break;
      case 'X':
        if(Valor == i) r += 'Y';
        else if(Valor == i + 1) r += 'A';
        else if(Valor == i + 2) r += 'B';
      break;
      case 'Y':
        if(Valor == i) r += 'X';
        else if(Valor == i + 1) r += 'A';
        else if(Valor == i + 2) r += 'B';
      break;
    }
  }
  if(n > 1){
    if(press(r + "A" + r + "B") == n){
      if(press(r + "A") == n) r += "A";
      else r += "B";
    } else {
      if(press(r + "X") == n) r += "X";
      else r += "Y";
    }
  }
  //cerr<<r;
  return r;
}