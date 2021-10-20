#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){

  string nome;
  string telefone;
  string end;
  int id;
  int menu=1;
  int contador=0;
  int controlador=20;
  while(menu!=0)
  {

        cout<< "Agenda Telefônica\n";

        cout<<"Digite (1) para adicionar contato\n";
        cout<<"Digite (2) para visulizar contato\n";
        cout<<"Digite (3) para remover contato\n";
        cout<<"Digite (0) para sair\n";
        cin>>menu;

    if(menu==1)
    {
        ofstream ArquivoGerado;
        ArquivoGerado.open("saida.txt");

  if(!ArquivoGerado)
    {
     cout<<"Não pode ser aberto\n";
     abort();
    }
            if(contador==1)
            {
                ifstream guardar;
               guardar.open("saida.text");

            if(!guardar)
        {
            cout<<"Não pode ser aberto"<<endl;
        }
    int id3;
    string nome3,telefone3,end3;

    while(guardar>>id3>>nome3>>telefone3>>end3)
        {
                ArquivoGerado<<id3<<setw(10)<<"|"<<nome3<<setw(10)<<"|"<<telefone3<<setw(10)<<"|"<<end3<<endl;
        }
               guardar.close();
                contador=0;
             }


        ArquivoGerado.close();
        ofstream Arquivorecebe;
        Arquivorecebe.open("saida.txt", ios:: app);

      if(!Arquivorecebe)
      {
        cout<<"Não pode ser aberto"<<endl;
      }
        string menu1="s";

      while(menu1!="sair")
      {
        id=rand()%100;
        cout<<"Digite o nome: "<<endl;
        cin>>nome;
        cout<<"Digite o telefone: "<<endl;
        cin>>telefone;
        cout<<"Digite o endereço: "<<endl;
        cin.ignore();
        getline(cin, end);
        cout<<"parar, digite sair. continuar, digite 0 "<<endl;
        cin>>menu1;
        Arquivorecebe<<id<<setw(10)<<"|"<<nome<<setw(10)<<
        "|"<<telefone<<setw(10)<<"|"<<end<<endl;
        controlador--;



      }
      Arquivorecebe.close();

      if(controlador==1)
      {
        cout<<"Memória cheia\n";
      }
      if(controlador==0)
      {
        break;
      }
    }
    if(menu==2)
    {

      ifstream ArquivoLeitura;
      ArquivoLeitura.open("saida.txt");
      if(!ArquivoLeitura)
      {
        cout<<"Não pode ser aberto\n";
      }
      cout<<"Id"<<setw(10)<<"|"<<"Nome"<<setw(10)<<"|"<<"Telefone"<<setw(10)<<"|"<<"Endereço"<<endl;

      int id1;
      string nome1,telefone1, end1;

      while(ArquivoLeitura>>id1>>nome1>>telefone1>>end1)
      {
        cout<<id1<<setw(10)<<nome1<<setw(10)<<telefone1<<setw(10)<<end1<<endl;
      }
      ArquivoLeitura.close();


    }
    if(menu==3)
    {
      contador=0;
      ifstream arqescrita;
      arqescrita.open("saida.txt");
      if(!arqescrita)
      {
        cout<<"Não pode ser aberto"<<endl;
        abort();
      }
      ofstream arqleitura;
      arqleitura.open("saida.text");
      if(!arqleitura)
      {
        cout<<"Não pode ser aberto"<<endl;
        abort();
      }
      int id2, excluir;
      string nome2,telefone2, end2;

      cout<<"Digite o que quer Excluir"<<endl;
      cin>>excluir;

      while(arqescrita>>id2>>nome2>>telefone2>>end2)
      {
        if(excluir!=id2)
        {
          arqleitura<<id2<<setw(10)<<"|"<<nome2<<setw(10)<<"|"<<telefone2<<setw(10)<<"|"<<end2<<endl;
        }
      }
     arqescrita.close();
      arqleitura.close();



       contador=1;
       controlador++;

  }
  return 0;
  }
}


