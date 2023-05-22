//Oliveto Goñi Agustín Div 1D

#define A 11
#define B 10
#define C 9
#define D 8
#define E 7
#define F 6
#define G 5
#define RED 13
#define GREEN 12
#define botonSube 4
#define botonBaja 3
#define botonStop 2

int contadorPiso = 0;
bool montacargaEnFuncionamientoSubiendo = false;
bool montacargaEnFuncionamientoBajando = false;
int piso;

int sensorLuz = A5;
int valorSensor;

int sensorInc = A4;
int lectura;


void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  Serial.begin(9600);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(A0, OUTPUT);
  
  pinMode(sensorInc, INPUT);
}


void loop()
{
  lectura = digitalRead(sensorInc);
  if(lectura == LOW)
  {
    
    Serial.println("Se detuvo el montacargas por una leve inclinacion");
  }
  else
  {
    Serial.println("el montacargas funciona con normalidad");
  }              
  
  
  if(contadorPiso == 0)
  {
  	prendeCero();
  }
  if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
  {
    subirMontacargas();
    encendido();
    pisoMontacarga();
  }
   else
  {
    apagado();
  }
  if(digitalRead(botonStop) == HIGH)
  {
    detenerMontacargasSubiendo();
  }
  
   
  
  if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
  { 
    bajarMontacargas();
    encendido();
    pisoMontacarga();
  }
  else
  {
    apagado();
  }
  if(digitalRead(botonStop) == HIGH)
  {
    detenerMontacargasBajando();
  }
   
  valorSensor = analogRead(sensorLuz);
    
  if(valorSensor > 20)
  {
    digitalWrite(A0, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(A0, LOW); 
  }
  
}



void pisoMontacarga()
{	
   piso = contadorPiso;
  
   switch(piso)
    {
      case 0:
       if(digitalRead(botonSube) == HIGH)
       {
          prendeCero();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true)
        {
           apagaVisualizador();
           prendeCero();
           printYDelay();
           detenerMontacargasBajando();
        }
      break;
      case 1:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {  
          apagaVisualizador();
          prendeUno();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeUno();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          } 
        }
      break;
      case 2:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeDos();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
          
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeDos();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
      case 3:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeTres();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        { 
           apagaVisualizador();
           prendeTres();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
      case 4:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeCuatro();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeCuatro();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
     case 5:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeCinco();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeCinco();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
     case 6:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeSeis();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeSeis();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
     case 7:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeSiete();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeSiete();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
     case 8:
     	if(montacargaEnFuncionamientoSubiendo == true || digitalRead(botonSube) == HIGH)
       {
          apagaVisualizador();
          prendeOcho();
          printYDelay();
          if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso + 1;
          }
       }
     	if(montacargaEnFuncionamientoBajando == true || digitalRead(botonBaja) == HIGH)
        {
           apagaVisualizador();
           prendeOcho();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
      break;
      case 9:
     	if(montacargaEnFuncionamientoSubiendo == true)
       {
          apagaVisualizador();
          prendeNueve();
          printYDelay();
          detenerMontacargasSubiendo();
       }
     	if(digitalRead(botonBaja) == HIGH)
        {	
           prendeNueve();
           printYDelay();
           if(digitalRead(botonStop) == LOW)
          {
            contadorPiso = contadorPiso - 1;
          }
        }
     break;
   }
}

// Funciones para subir o bajar

void subirMontacargas()
{
  if(montacargaEnFuncionamientoSubiendo != true)
  {
    montacargaEnFuncionamientoSubiendo = true;
    Serial.println("Se preciono el boton para subir el montacargas");
  }
}

void bajarMontacargas() 
{
  if(montacargaEnFuncionamientoBajando != true) 
  {
    montacargaEnFuncionamientoBajando = true;
    Serial.println("Se preciono el boton para bajar el montacargas");
  }
}

void detenerMontacargasSubiendo() 
{
  if(montacargaEnFuncionamientoSubiendo != false)
  {
    montacargaEnFuncionamientoSubiendo = false;
    Serial.println("Se detuvo el montacargas");
  }
}

void detenerMontacargasBajando() 
{
  if(montacargaEnFuncionamientoBajando != false)
  {
    montacargaEnFuncionamientoBajando = false;
    Serial.println("Se detuvo el montacargas");
  }
}

// Funciones leds

void encendido()
{
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
}
void apagado()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, HIGH);
}


// Funciones visualizador 7 segmentos

void apagaVisualizador()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void prendeCero()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
}
void prendeUno()
{
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void prendeDos()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
}
void prendeTres()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
}
void prendeCuatro()
{
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void prendeCinco()
{
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void prendeSeis()
{
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void prendeSiete()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void prendeOcho()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void prendeNueve()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

// Consola

void printYDelay()
{
  Serial.print("El montacarga esta en el piso: ");
  Serial.println(contadorPiso);
  delay(3000);
}