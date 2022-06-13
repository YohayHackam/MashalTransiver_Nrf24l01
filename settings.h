#define NODE_ID 0 //id 0 is remote control

#define CE 9    //CE pin connected to NRF24 
#define CSN 10  //CSN pin connected to NRF24 

#define RED_LED 2 
#define YELLOW_LED 3
#define GREEN_LED 4

#define LED_TIMEOUT 500 //led startup reset
uint8_t error= 0; //error id
int test=0; //test testing connection

byte flag_pins[]={RED_LED,YELLOW_LED,GREEN_LED};

struct dataStruct  
    {   
    uint8_t targetId =1;             //where is data Finel Target
    char commandSign ='F';             //What type of command / respons is data source
    uint8_t commandValue =0;             //Value of command / respons    
    } sendData,recivedData;                 // This can be accessed in the form:  myData.Xposition  etc.
