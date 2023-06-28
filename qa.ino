
char che[38]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','1','2','3','4','5','6','7','8','9','0'};
String ret[38]={"00000000","00000001","00000010","00000011","00001000","00001001","00001010","00001011","00001110","00001111",
"00010001","00010010","00010011","00011000","00011001","00011010","00011011","00011110","00011111",
"00100001","00100010","00100011","00101000","00101001","00101010","00101011","00101110","00101111",
"00110001","00110010","00110011","00111000","00111001","00111010","00111011","00111110"};
String ecc;
int a=0;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  String brk;
  String str=Serial.readString();
  int siz=str.length();
  char ch[siz];
  str.toCharArray(ch,siz);
  for(int i=0;i<siz;i++)
  {
    brk=con(ch[i]);
    int s=brk.length();
    char ser[s];
    brk.toCharArray(ser,s);
    for(a;a<8;a++)
    {
      Serial.print(1);
      gen("1");
      
    }
    for(int j=0;j<s;j++)
    {
      Serial.print(ser[j]);
      gen(ser[j]);
    }
  }
}

void gen(char x)
{
  if(x=='1')
  {
    digitalWrite(8,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(8,LOW);
    delay(100);
  }
}

String con(char ch)
{
  for(int i=0;i<=37;i++)
  {
   if(ch==che[i])
   return ret[i];
  }
  
}
