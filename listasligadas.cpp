// 20/09/2023
// feito por Silvio Zechin
// trabalho com listas ligadas



#include <iostream>



using namespace std;
//tipificação de struct para lista ligada
struct listaligada
{
	int numero;//a lista será ordenada por aqui
	int qualquercoisa; //item genérico; podia ser preço, idade, nome, etc...
	listaligada* proximo; //membro para apontador
};



listaligada* CABECA = NULL; //o primeiro da lista ou head (cabeça)
listaligada* CAUDA = NULL; //o último ou tail (cauda)



int main()
{
	//3 apontadores genéricos para struct:
	listaligada* novo; 	listaligada* atual; listaligada* anterior; listaligada* proximo;



	listaligada* atual1 = NULL; listaligada* atual2 = NULL;
	listaligada* anterior1 = NULL; listaligada* anterior2 = NULL; //apontadores para realizar a troca de posicoes
	listaligada* tempPoint = NULL; // para realizar as trocas



	//dados genéricos para o programa:
	char op; int n, qqc; //membro 1 n=numero; membro2 qqc=qualquer coisa
	int numero1; int numero2; //numero a ser removido na opcao 8 e para realizar a troca na opcao f
	bool estaEmOrdem; //bool para exercicio c
	int temporario; // para organizar a lista no exercicio d
	int contador = 0; //contador para exercicio e





	do
	{
		cout << "\n\nLISTA LIGADA-EXERCICIO DIDATICO (TRABALHO COOPERATIVO) ------------------------------------------\n";
		cout << "[1:listar]\n[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]" << "\n"
			<< "[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]\n"
			<< "[a:limpa lista][b:init lista com 3 nos][c:lista ordenada? (sim/nao)][d:ordena lista][e:conta nos]\n"
			<< "[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor]\n[j: escrever cabeca e cauda]\n[0:SAIR]\n"
			<< "Op?";
		cin >> op;//MENU
		switch (op)
		{
			// --------------------------------------------------------------------------------------------------------------------- 1:LISTAR
		case '1':
			if (CABECA == NULL)
			{
				cout << "\nA LISTA ESTA VAZIA\n";
			}
			else
			{
				atual = CABECA;
				while (atual != NULL)
				{
					cout << (*atual).numero << "  -  " << (*atual).qualquercoisa << endl;
					atual = (*atual).proximo;
				}
			}
			break;
			// --------------------------------------------------------------------------------------------------------------------- 2:INSERE PRIMEIRO
		case '2':
			novo = (listaligada*)malloc(sizeof(listaligada));
			cout << "\nNUMERO: ";
			cin >> (*novo).numero;
			cout << "\nQUALQUER COISA: ";
			cin >> (*novo).qualquercoisa;



			if ((*novo).numero >= (*CABECA).numero)
			{
				cout << "\nO NUMERO INSERIDO E MAIOR OU IGUAL AO VALOR DO PRIMEIRO NO\n";
				free(novo);
			}
			else
			{
				atual = CABECA;
				(*novo).proximo = atual;
				CABECA = novo;
			}
			break;
			// --------------------------------------------------------------------------------------------------------------------- 3:INSERE NO FIM
		case '3':
			novo = (listaligada*)malloc(sizeof(listaligada));
			cout << "\nNUMERO: ";
			cin >> (*novo).numero;
			cout << "\nQUALQUER COISA: ";
			cin >> (*novo).qualquercoisa;



			if ((*novo).numero <= (*CAUDA).numero)
			{
				cout << "\nO NUMERO INSERIDO E MENOR OU IGUAL AO VALOR DO ULTIMO NO\n";
				free(novo);
			}
			else
			{
				(*CAUDA).proximo = novo;
				(*novo).proximo = NULL;
				CAUDA = novo;
			}
			break;
			// --------------------------------------------------------------------------------------------------------------------- 4:INSERE AO MEIO
		case '4':
			novo = (listaligada*)malloc(sizeof(listaligada));
			cout << "\nNUMERO: ";
			cin >> (*novo).numero;
			cout << "\nQUALQUER COISA: ";
			cin >> (*novo).qualquercoisa;



			atual = CABECA;





			while ((*atual).proximo != NULL)
			{
				if ((*novo).numero < (*(*atual).proximo).numero && (*novo).numero >(*atual).numero)
				{
					(*novo).proximo = (*atual).proximo;
					(*atual).proximo = novo;



				}
				atual = (*atual).proximo;
			}





			break;
			// --------------------------------------------------------------------------------------------------------------------- 5:INSERE COMPLETO
		case '5':
			novo = (listaligada*)malloc(sizeof(listaligada));
			cout << "\nNUMERO: ";
			cin >> (*novo).numero;
			cout << "\nQUALQUER COISA: ";
			cin >> (*novo).qualquercoisa;



			if ((*novo).numero <= (*CABECA).numero)
			{
				atual = CABECA;
				(*novo).proximo = atual;
				CABECA = novo;
			}



			else if ((*novo).numero >= (*CAUDA).numero)
			{
				(*CAUDA).proximo = novo;
				(*novo).proximo = NULL;
				CAUDA = novo;
			}
			else if ((*novo).numero > (*CABECA).numero && (*novo).numero < (*CAUDA).numero)
			{
				atual = CABECA;





				while ((*atual).proximo != NULL)
				{
					if ((*novo).numero < (*(*atual).proximo).numero && (*novo).numero >(*atual).numero)
					{
						(*novo).proximo = (*atual).proximo;
						(*atual).proximo = novo;



					}
					atual = (*atual).proximo;
				}
			}



			break;
			// --------------------------------------------------------------------------------------------------------------------- 6:REMOVE CABEÇA
		case '6':
			atual = CABECA;
			CABECA = (*atual).proximo;
			free(atual);



			cout << "\nA PRIMEIRA ENTRADA FOI REMOVIDA\n";
			break;
			// --------------------------------------------------------------------------------------------------------------------- 7:REMOVE CAUDA
		case '7':
			atual = (*CABECA).proximo;
			anterior = CABECA;
			while ((*atual).proximo != NULL)
			{
				anterior = atual;
				atual = (*atual).proximo;
			}



			CAUDA = anterior;
			(*anterior).proximo = NULL;
			free(atual);
			cout << "\nA ULTIMA ENTRADA FOI REMOVIDA\n";
			break;
			// --------------------------------------------------------------------------------------------------------------------- 8:REMOVE AO MEIO
		case '8':
			novo = NULL;
			atual = NULL; anterior = NULL;
			cout << "\nINFORME O VALOR DO NO QUE DESEJA REMOVER: ";
			cin >> numero1;
			atual = (*CABECA).proximo;
			anterior = CABECA;
			while ((*atual).proximo != NULL)
			{
				if ((*atual).numero == numero1)
				{
					novo = atual;
					(*anterior).proximo = (*novo).proximo;
				}
				anterior = atual;
				atual = (*atual).proximo;
			}
			free(novo);
			cout << "\nO NO FOI REMOVIDO\n";
			break;
			// --------------------------------------------------------------------------------------------------------------------- 9:REMOVE COMPLETO

		//2023-09-26
		//opcao de remover qualquer no da lista
		//feito por Silvio Zechin

		case '9':



			cout << "\nINFORME O VALOR DO NO QUE DESEJA REMOVER: ";
			cin >> numero1;

			// verificar se a lista esta vazia
			if (CABECA == NULL)
			{
				
				cout << "\nA LISTA ESTA VAZIA\n";
			}

			//caso o numero seja o primeiro da lista
			else if (numero1 == (*CABECA).numero)
			{
				if (CAUDA == CABECA) // caso a lista tenha apenas um no, a cauda deverá ser NULL também
				{
					CAUDA = NULL;
				}
				atual = CABECA;
				CABECA = (*atual).proximo;
				free(atual);
				cout << "\nO NO FOI REMOVIDO\n";
			}

			//caso seja a cauda
			else if (numero1 == (*CAUDA).numero)
			{
				atual = (*CABECA).proximo; // atual toma valor segundo no
				anterior = CABECA;
				while ((*atual).proximo != NULL)
				{
					anterior = atual;
					atual = (*atual).proximo;
				}



				CAUDA = anterior; // cauda se torna o penultimo no
				(*anterior).proximo = NULL; // penultimo no aponta para NULL
				free(atual);
				cout << "\nO NO FOI REMOVIDO\n";
			}

			//caso o numero seja um no no meio da lista ou ele nao exista
			else
			{
				novo = NULL;
				atual = NULL;
				anterior = NULL; // declaro os ponteiros usados como NULL por boas praticas
				atual = (*CABECA).proximo; //atual toma o valor do segundo nó
				anterior = CABECA; //anterior toma o valor de CABECA
				while (atual != CAUDA) //ciclo enquanto nao chegar a cauda
				{
					if ((*atual).numero == numero1) //caso o numero de atual seja igual ao fornecido pelo usuario
					{
						novo = atual; // salvo a posicao de atual
						(*anterior).proximo = (*novo).proximo; //faço o nó anterior apontar ao proximo do no que salvei, removendo ele da lista
					}
					anterior = atual;
					atual = (*atual).proximo;
				}
				free(novo); //libero o espaço do nó

				if (novo == NULL) // caso o numero fornecido nao tenha sido encontrado na lista
				{
					cout << "\n O NO NAO FOI ENCONTRADO\n";
				}
				else
				{
					cout << "\nO NO FOI REMOVIDO\n";
				}
			}


			break;
			// --------------------------------------------------------------------------------------------------------------------- a:LIMPA LISTA
		case 'a':
			//limpar a lista, libertando a memória dos nós:
			atual = CABECA;
			while (atual != NULL)
			{
				anterior = atual;//guarda o endereço que tem que ser libertado
				atual = (*atual).proximo;
				free(anterior);//liberta o espaço reservado pelo malloc
			}
			//tdos os nós foram libertados; há que recolocar as pontas:
			CABECA = NULL;
			CAUDA = NULL;
			break;
			// --------------------------------------------------------------------------------------------------------------------- b:INICIALIZA COM 3 NÓS "fixos"
		case 'b':
			//primeiro nó:
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço		
			CABECA = novo;
			(*novo).numero = 1;
			(*novo).qualquercoisa = 1111;
			(*novo).proximo = NULL;
			//segundo nó:
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço		
			(*CABECA).proximo = novo;
			(*novo).numero = 5;
			(*novo).qualquercoisa = 5555;
			(*novo).proximo = NULL;
			//terceiro nó:
			atual = novo; //para atar o último neste (novo vem de trás)
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço					
			(*atual).proximo = novo;
			(*novo).numero = 9;
			(*novo).qualquercoisa = 9999;
			(*novo).proximo = NULL;
			//antes de terminar, definir o último da lista:
			CAUDA = novo;
			break;
			// --------------------------------------------------------------------------------------------------------------------- c:LISTA ORDENADA? SIM/NÃO
		case 'c':
			estaEmOrdem = true;
			if (CABECA == NULL || (*CABECA).proximo == NULL)
			{
				estaEmOrdem = true;
			}
			else
			{
				atual = (*CABECA).proximo;
				anterior = CABECA;
				while (atual != NULL)
				{
					if ((*atual).numero < (*anterior).numero)
					{
						estaEmOrdem = false;
					}
					anterior = atual;
					atual = (*atual).proximo;
				}
			}



			if (estaEmOrdem)
			{
				cout << "\nA LISTA ESTA ORDENADA DE FORMA CRESCENTE\n";
			}
			else
			{
				cout << "\nA LISTA NAO ESTA ORDENADA\n";
			}



			break;
			// --------------------------------------------------------------------------------------------------------------------- d:ORDENA LISTA
		case 'd':
			if (CABECA == NULL || (*CABECA).proximo == NULL)
			{
				cout << "\nA LISTA FOI ORDENADA\n";
			}
			else
			{



				bool trocou = true; // condicao para parar o ciclo
				while (trocou)
				{
					trocou = false; //mando o ciclo se encerrar
					atual = CABECA;
					while (atual != NULL && atual->proximo != NULL) 
					{
						if (atual->numero > atual->proximo->numero) // caso o no seja maior que o proximo (no 2)
						{

							tempPoint = atual->proximo; // salva posicao do no 2
							atual->proximo = atual->proximo->proximo; // no aponta ao proximo do proximo, pulando o no 2
							tempPoint->proximo = atual; //no2 aponta ao atual
							if (CABECA == atual) //caso seja a cabeca, ela entao aponta ao no 2
								CABECA = tempPoint;
							else //caso nao seja a cabeca
							{
								anterior = CABECA; //nova variavel toma valor de cabeca e percorre a lista
								while (anterior->proximo != atual)
									anterior = anterior->proximo;
								anterior->proximo = tempPoint;
							}
							trocou = true; //mandamos o ciclo se repetir
						}
						else
							atual = atual->proximo; //caso o numero esteja em ordem fazemos o ciclo continuar
					}
				}
				atual = CABECA;
				while (atual != NULL)
				{
					if (atual->proximo == NULL)
					{
						CAUDA = atual;
					}
					atual = atual->proximo;
				}
				cout << "\nA LISTA FOI ORDENADA\n";
			}
			break;
			// --------------------------------------------------------------------------------------------------------------------- e:CONTA NÓS	
		case 'e':
			atual = CABECA;
			contador = 0;
			while (atual != NULL)
			{
				atual = (*atual).proximo;
				contador++;
			}



			cout << "\nEXISTEM " << contador << " NOS NA LISTA.\n";



			break;
			// --------------------------------------------------------------------------------------------------------------------- f:LER 2 NUMS; EXISTEM? TROCAR NÓS
		case 'f':
			cout << "\nDIGITE O PRIMEIRO NUMERO (MENOR): ";
			cin >> numero1;
			cout << "\nDIGITE O SEGUNDO NUMERO (MAIOR): ";
			cin >> numero2;

			//inicializa os apontadores como NULL
			atual1 = NULL;
			atual2 = NULL;
			anterior1 = NULL;
			anterior2 = NULL;


			if (numero1 == numero2) // caso os dois numeros sao iguais, nao há troca
			{
				cout << "\nOS NUMEROS INSERIDOS SAO IGUAIS\n";
				break;
			}
			else // recolher o endereço dos nos e anteriores
			{
				anterior = NULL;
				atual = CABECA;
				while (atual != NULL)
				{
					if ((*atual).numero == numero1)
					{
						atual1 = atual;
						anterior1 = anterior;
					}
					else if ((*atual).numero == numero2)
					{
						atual2 = atual;
						anterior2 = anterior;
					}
					anterior = atual;
					atual = (*atual).proximo;



				}
				if (atual1 == NULL)
				{
					cout << "\nO PRIMEIRO NUMERO INSERIDO NAO FOI ENCONTRADO NA LISTA\n";
					break;
				}
				else if (atual2 == NULL)
				{
					cout << "\nO SEGUNDO NUMERO INSERIDO NAO FOI ENCONTRADO NA LISTA\n";
					break;
				}
			}



			// caso num1 = cabeca e num2 consecutivo



			if (numero1 == (*CABECA).numero && numero2 == CABECA->proximo->numero)
			{
				if (CAUDA->numero == numero2)
				{
					CAUDA = atual1;
				}
				tempPoint = atual2->proximo;
				CABECA = atual2;
				atual2->proximo = atual1;
				atual1->proximo = tempPoint;



			}



			// caso o numero 1 seja a cabeca
			else if (numero1 == (*CABECA).numero)
			{
				if (CAUDA->numero == numero2)
				{
					CAUDA = atual1;
				}
				tempPoint = (*atual2).proximo;
				CABECA = atual2;
				(*atual2).proximo = (*atual1).proximo;



				(*anterior2).proximo = atual1;
				(*atual1).proximo = tempPoint;



			}





			// caso sejam numeros consecutivos



			else if (atual2 == (*atual1).proximo)
			{
				if (CAUDA->numero == numero2)
				{
					CAUDA = atual1;
				}
				anterior1->proximo = atual2;
				atual1->proximo = atual2->proximo;
				atual2->proximo = atual1;



			}



			// caso os dois estejam no meio da lista e nao sejam consecutivos



			else if (atual1 != NULL && atual2 != NULL)
			{
				if (CAUDA->numero == numero2)
				{
					CAUDA = atual1;
				}
				tempPoint = atual1->proximo;
				atual1->proximo = atual2->proximo;
				atual2->proximo = tempPoint;



				anterior1->proximo = atual2;
				anterior2->proximo = atual1;





			}





			break;
			// --------------------------------------------------------------------------------------------------------------------- g:INVERTER A LISTA
		case 'g':



			anterior = NULL;
			atual = CABECA;
			proximo = NULL;
			while (atual != NULL) {
				proximo = (*atual).proximo;
				(*atual).proximo = anterior;
				anterior = atual;
				atual = proximo;



				if (anterior->proximo == NULL)
				{
					CAUDA = anterior;
				}
			}
			CABECA = anterior;



			break;
			// --------------------------------------------------------------------------------------------------------------------- H:INVERTER A LISTA
		case 'H':
			cout << "\n\nEXERCICIO PRATICO COM LISTA LIGADA\nO objetivo e elaborar as opcoes 5 e 9.\nPara isso, comecar pelas mais simples:\n"
				<< "Exemplo: 2->3->4->5\n"
				<< "Sera pedido que alguns formandos facam as opcionais, para no final \njuntar tudo e o exercicio ficar completo."
				<< "\nNesse caso: respeitar a organizacao do codigo, nao usar funcoes, \ncomentar todas a linhas relevantes, identificar autor e data.\nObrigado. :)\n\n";



			break;



		case 'j':



			cout << "\nCABECA - " << CABECA->numero;
			cout << "\nCAUDA - " << CAUDA->numero;
			break;
			// --------------------------------------------------------------------------------------------------------------------- 0:SAIR
		case '0':
			cout << "\n fim do programa...\n";
			break;
			// --------------------------------------------------------------------------------------------------------------------- DEFAULT
		default:
			cout << "\7"; //beep do sistema
			break;
		}
	} while (op != '0');
}