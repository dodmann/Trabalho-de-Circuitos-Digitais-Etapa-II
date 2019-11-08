void setup(){
    //Setar as portas de 2 a 8 para modo de saída
    for(int i = 2; i < 9; i++){
      pinMode(i, OUTPUT);
    }

    //Setar as portas de 9 a 12 como entrada, para o decodificador
    for(int i = 9; i < 13; i++){
      pinMode(i, INPUT);
    }
}

/* Função para representar o display de 7 segmentos
*  Parâmetros: boolean(a,b,c,d,e,f,g)
*  Retorno: void
*  Os parâmetros passados dentro da função foram invertidos
*  para facilitar o entendimento (devido ao display estar em modo anode)
*/ 
void instrucao(bool a, bool b, bool c, bool d,bool e,bool f,bool g) {
    digitalWrite(2, !a);
    digitalWrite(3, !b);
    digitalWrite(4, !c);
    digitalWrite(5, !d);
    digitalWrite(6, !e);
    digitalWrite(7, !f);
    digitalWrite(8, !g);
}


/* Função para exibir o número no display de 7 segmentos
*  Parâmetros: char(letra)
*  Retorno: void
*/ 
void montaNumero(char letra) {
  	switch (letra) {
    	case '0':
    	instrucao(true,true,true,true,true,true,false);
   		break;
      
        case '1':
    	instrucao(false,true,true,false,false,false,false);
   		break;
      
        case '2':
    	instrucao(true,true,false,true,true,false,true);
   		break;
      
        case '3':
    	instrucao(true,true,true,true,false,false,true);
   		break;
      
        case '4':
    	instrucao(false,true,true,false,false,true,true);
   		break;
      
        case '5':
    	instrucao(true,false,true,true,false,true,true);
   		break;
      
        case '6':
    	instrucao(true,false,true,true,true,true,true);
   		break;
      
        case '7':
    	instrucao(true,true,true,false,false,false,false);
   		break;
      
        case '8':
    	instrucao(true,true,true,true,true,true,true);
   		break;
      
        case '9':
    	instrucao(true,true,true,true,false,true,true);
   		break;
      
        case 'A':
    	instrucao(true,true,true,false,true,true,true);
   		break;
      
        case 'B':
    	instrucao(false,false,true,true,true,true,true);
   		break;
      
        case 'C':
    	instrucao(true,false,false,true,true,true,false);
   		break;
      
        case 'D':
    	instrucao(false,true,true,true,true,false,true);
   		break;
      
        case 'E':
    	instrucao(true,false,false,true,true,true,true);
   		break;
      
        case 'F':
    	instrucao(true,false,false,false,true,true,true);
   		break;
	}
}


void loop(){
    bool A, B, C, D;
    A = digitalRead(12);
    B = digitalRead(11);
    C = digitalRead(10);
    D = digitalRead(9);
  
    if(!A && !B && !C && !D){
      montaNumero('0');
    }

    if(!A && !B && !C && D){
      montaNumero('1');
    }

    if(!A && !B && C && !D){
      montaNumero('2');
    }

    if(!A && !B && C && D){
      montaNumero('3');
    }

    if(!A && B && !C && !D){
      montaNumero('4');
    }

    if(!A && B && !C && D){
      montaNumero('5');
    }

    if(!A && B && C && !D){
      montaNumero('6');
    }

    if(!A && B && C && D){
      montaNumero('7');
    }

    if(A && !B && !C && !D){
      montaNumero('8');
    }

    if(A && !B && !C && D){
      montaNumero('9');
    }

    if(A && !B && C && !D){
      montaNumero('A');
    }

    if(A && !B && C && D){
      montaNumero('B');
    }

    if(A && B && !C && !D){
      montaNumero('C');
    }

    if(A && B && !C && D){
      montaNumero('D');
    }

    if(A && B && C && !D){
      montaNumero('E');
    }

    if(A && B && C && D){
      montaNumero('F');
    }
}