/* memmove example */
#include <stdio.h>
#include <string.h>
#include<vector>
using namespace std;
void sample_strcpy(){
  char a[]="abc111";
  char b[5];
  memmove(b,a,sizeof(a));

  // int * a=nullptr;
  // sizeof(a);
  // strcpy(b,a);
  printf("%s\n",b);

}
void sample1(){
    char str[] = "memmove can be very useful......";
  // useful:6 bytes; ......:6 bytes
  // str+20: u, str+15: v
  printf("str+20: %c, str+15: %c\n",str[20],str[15]);

  memmove (str+20,str+15,11); //dest<-src length?
  puts (str);
}

void sample2(){
    char str[] = "hello";
  // useful:6 bytes; ......:6 bytes
  // str+20: u, str+15: v
  printf("str: %c, str+2: %c\n",str[0],str[2]);

  memmove (str,str+2,2); //dest<-src length?
  puts (str);
}

void sample3(){
    char str[] = "hello";
  // useful:6 bytes; ......:6 bytes
  // str+20: u, str+15: v
  printf("str+4: %c, str: %c\n",str[0],str[2]);

  memmove (str+4,str,5); //dest<-src length?
  puts (str);
}
int main ()
{
  // sample1();
  // sample2();
  // sample3();
  // sample_strcpy();
  // char *a=".";
  // if(a[0]=='.'){
  //   printf("1");
  // }else{

  // }
  // int a=0;
  // if(a==0){
  //   a++;
  // }
  // {
  //   a++;
  // }
  // printf("%d",a);

  char* c[2];//c: [] []

  char argument1[]="hello1";
  char argument2[]="hello2";

  char* arguments[3]={
    "test1","test2","test3"
  };

  memmove(c[0],argument1,sizeof(argument1));
  memmove(c[1],argument2,sizeof(argument2));

  printf("%s,%s\n",c[0],c[1]);

  char* c2[3];
  memmove(c2,&arguments[1],sizeof(arguments));

  printf("%s,%s\n",c2[0],c2[1]);

  vector<int> v(10,0);
  vector<vector<int>>w(10,vector(10,0));

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cout<<w[i][j];
    }
  }
  return 0;
}