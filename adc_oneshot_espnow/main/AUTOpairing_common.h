#ifndef AUTOpairing_common_H
#define AUTOpairing_common_H

// message types
#define DATA      0b00000001
#define PAIRING   0b00000000
#define NODATA    0b00000011
#define PAN_DATA  0b00000010
#define MASK_MSG_TYPE 0b00000011

// PAN address
#define MASK_PAN 0b00111100
#define PAN_OFFSET 2

// message flags
#define CHECK   0b10000000

#define MAX 100

char * messType2String(uint8_t type)
{
  char *text;
  char *buffer = malloc(MAX);
  switch (type & MASK_MSG_TYPE)
  {
    case PAN_DATA :
    text = " DATOS PAN";
    break;
    case DATA :
    text = " DATOS";
    break;
    case PAIRING :
    text = " EMPAREJAMIENTO";
    break;
    case NODATA :
    text = " SIN_DATOS";
    break;
    default: text = " Desconocido";
  }
  sprintf(buffer,"%s PAN: %d",text,(type&MASK_PAN)>>PAN_OFFSET);
  if(type & CHECK)
  {
	  strcat(buffer," & SOLICITA MENSAJES");
  }
  return buffer;
}

// this method will print all the 32 bits of a number
long long dec2bin(int n) {
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}



// network node types
#define GATEWAY 0
#define ESPNOW_DEVICE 1

struct struct_pairing {      // new structure for pairing
    uint8_t msgType;
    uint8_t id;
    uint8_t macAddr[6];
    uint8_t channel;
    uint8_t padding[3];
};


struct struct_espnow {      // esp-now message structure
    uint8_t msgType;
    uint8_t payload[249];
};
/*
//-----------------------------------------------------
// devuelve 2 caracteres HEX para un byte
inline String one_b2H(uint8_t data)
{
  return (String(data, HEX).length()==1)? String("0")+String(data, HEX) : String(data, HEX);
}

String byte2HEX (uint8_t *mac)
{
  String _deviceMac="";
  for (int i=0; i<6; i++) _deviceMac += one_b2H(mac[i]);
  for (auto & c: _deviceMac) c = toupper(c);
    
  return _deviceMac;
}

//-----------------------------------------------------
// compara dos MACs
inline bool igualMAC(uint8_t *mac1, uint8_t *mac2)
{
  for(int i=0; i<6; i++) if(mac1[i] != mac2[i]) return false;
  return true;
}

//-----------------------------------------------------
// devuelve 6 bytes de la MAC en texto

void HEX2byte(uint8_t *mac, char* texto)
{ 
    char * pos=texto;
     for (size_t count = 0; count < 6 ; count++) {
        sscanf(pos, "%2hhx", &mac[count]);
        pos += 2;
    }
}
*/

#endif
