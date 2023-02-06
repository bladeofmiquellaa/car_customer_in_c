#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int price, tip;
  char model[40],date[40],status[40];
} Cars;

typedef struct {
  int pid;
  char name[40], gender[40];
} Customers;

void add_car(){
	
	char model[50];
	char date[50];
	char status[50];
	int price, tip;
	FILE *fp;
	    
    printf("Model: ");
    scanf("%s", &model);
    
	printf("Date: ");
    scanf("%s", &date);
    
    printf("Price: ");
    scanf("%d", &price);
    
    printf("Tip: ");
    scanf("%d", &tip);   
    printf("Status: ");
    scanf("%s", &status);
    printf("\n");
    fp = fopen("cars.txt", "a");
    fprintf(fp, "%s %s %d %d %s", model, date, price,tip,status);
    fprintf(fp, "%s", "\n");
    
    fclose(fp);

      
}
void customer_sign_up(){
	
	char name[50];
	char gender[50];
	int pid;
	FILE *fp;
	
	printf("Name: ");
    scanf("%s", &name);
    
    printf("Gender: ");
    scanf("%s", &gender);
    
    printf("Personal Id: ");
    scanf("%d", &pid);
    
   
    printf("\n");
    fp = fopen("customers.txt", "a");
    fprintf(fp, "%s %s %d", name, gender, pid);
    fprintf(fp, "%s", "\n");    
    fclose(fp);
	
}
void read_car_file(){
	Cars cars[200];
FILE* file=fopen("cars.txt","r");
char buffer[200];
int i=0;

fgets(buffer,200,file); 
while(!feof(file)){
	Cars* c=cars+i;
	sscanf(buffer,"%s %s %d %d %s",c->model,c->date,&c->price,&c->tip,c->status);
	fgets(buffer,200,file);//note
	 i++;
}
int n=i;
int ihelp;
char chelp[50];


for(int r=0;r<n;r++){
	for(int q=r+1;q<n;q++){
		  if (cars[r].price < cars[q].price) 
                {
                   ihelp = cars[r].price;
                   cars[r].price = cars[q].price;
                   cars[q].price = ihelp;
                           
                    
                   //====================================================== 
                    
                    size_t fmndestination_size = sizeof (chelp);
                    strncpy(chelp, cars[r].model, fmndestination_size);
                    chelp[fmndestination_size - 1] = '\0';
                    
                    size_t smndestination_size = sizeof (cars[r].model);
                    strncpy(cars[r].model, cars[q].model, smndestination_size);
                    cars[r].model[smndestination_size - 1] = '\0';
                    
                    size_t tmndestination_size = sizeof (cars[q].model);
                    strncpy(cars[q].model, chelp, tmndestination_size);
                    cars[q].model[tmndestination_size - 1] = '\0';
                    
                     //====================================================== 
                     
                    size_t fddestination_size = sizeof (chelp);
                    strncpy(chelp, cars[r].date, fddestination_size);
                    chelp[fddestination_size - 1] = '\0';
                    
                    size_t sddestination_size = sizeof (cars[r].date);
                    strncpy(cars[r].date, cars[q].date, sddestination_size);
                    cars[r].date[sddestination_size - 1] = '\0';
                    
                    size_t tddestination_size = sizeof (cars[q].date);
                    strncpy(cars[q].date, chelp, tddestination_size);
                    cars[q].date[tddestination_size - 1] = '\0';
                    
                     //====================================================== 
                     
                                    
                   ihelp = cars[r].tip;
                   cars[r].tip = cars[q].tip;
                   cars[q].tip = ihelp;
                  
                    //====================================================== 
 
 
                    size_t fstdestination_size = sizeof (chelp);
                    strncpy(chelp, cars[r].status, fstdestination_size);
                    chelp[fstdestination_size - 1] = '\0';
                    
                    size_t sstdestination_size = sizeof (cars[r].status);
                    strncpy(cars[r].status, cars[q].status, sstdestination_size);
                    cars[r].status[sstdestination_size - 1] = '\0';
                    
                    size_t tstdestination_size = sizeof (cars[q].status);
                    strncpy(cars[q].status, chelp, tstdestination_size);
                    cars[q].status[tstdestination_size - 1] = '\0';
                    
 
 
                               
                   
                }
	}
}

 printf("\n");
for(i=0;i<n;i++){
	printf("%s %s %d %d %s \n",cars[i].model,cars[i].date,cars[i].price,cars[i].tip,cars[i].status);
}
printf("\n");
}
 void read_customer_file(){
 		
 			Customers customers[200];
FILE* file=fopen("customers.txt","r");
//if(file==NULL){
//	
//}
char buffer[200];
int i=0;

fgets(buffer,200,file);
while(!feof(file)){
	Customers* c=customers+i;
	sscanf(buffer,"%s %s %d",c->name,c->gender,&c->pid);
	fgets(buffer,200,file); //*****note******
	 i++;
}
int n=i;
int ihelp;
char chelp[50];
for(int r=0;r<n;r++){
	for(int q=r+1;q<n;q++){
		  if (customers[r].pid < customers[q].pid) 
                {
                   ihelp = customers[r].pid;
                   customers[r].pid = customers[q].pid;
                   customers[q].pid = ihelp;
                   //====================================================
                    size_t fndestination_size = sizeof (chelp);
                    strncpy(chelp, customers[r].name, fndestination_size);
                    chelp[fndestination_size - 1] = '\0';
                    
                    size_t sndestination_size = sizeof (customers[r].name);
                    strncpy(customers[r].name, customers[q].name, sndestination_size);
                    customers[r].name[sndestination_size - 1] = '\0';
                    
                    size_t tndestination_size = sizeof (customers[q].name);
                    strncpy(customers[q].name, chelp, tndestination_size);
                    customers[q].name[tndestination_size - 1] = '\0';
                    
                   //====================================================== 
                    
                    size_t fgdestination_size = sizeof (chelp);
                    strncpy(chelp, customers[r].gender, fgdestination_size);
                    chelp[fgdestination_size - 1] = '\0';
                    
                    size_t sgdestination_size = sizeof (customers[r].gender);
                    strncpy(customers[r].gender, customers[q].gender, sgdestination_size);
                    customers[r].gender[sgdestination_size - 1] = '\0';
                    
                    size_t tgdestination_size = sizeof (customers[q].gender);
                    strncpy(customers[q].gender, chelp, tgdestination_size);
                    customers[q].gender[tgdestination_size - 1] = '\0';
                    
                     //====================================================== 
                 
                               
                   
                }
	}
}

 printf("\n");
for(i=0;i<n;i++){
	printf(" %s %s %d \n",customers[i].name,customers[i].gender,customers[i].pid);
}
printf("\n");
 		
 		
 		
	 }
    void car_for_customer(){
	 	
	char name[50];
	char model[50];
	int nameflag=0;
	int modelflag=0;
	FILE *fp;
	
	Cars cars[200];
	
	
	printf("Name: ");
    scanf("%s", &name);
    
    printf("Model: ");
    scanf("%s", &model);
    
    	
FILE* file=fopen("cars.txt","r");
if(file==NULL){
	
}
char buffer[200];
int i=0;

fgets(buffer,200,file);
while(!feof(file)){
	Cars* c=cars+i;
	sscanf(buffer,"%s %s %d %d %s",c->model,c->date,&c->price,&c->tip,c->status);
	fgets(buffer,200,file);
	 i++;
}

for(int j=0;j<i;j++){
	if(strcmp(cars[j].model, model)==0){
		modelflag=1;
	}
}
    //============================
    	Customers customers[200];
FILE* cfile=fopen("customers.txt","r");
if(file==NULL){
	
}
char cbuffer[200];
i=0;

fgets(buffer,200,cfile);
while(!feof(cfile)){
	Customers* cu=customers+i;
	sscanf(buffer,"%s %s %d",cu->name,cu->gender,&cu->pid);
	fgets(buffer,200,cfile);
	 i++;
} 

for(int j=0;j<i;j++){
	if(strcmp(customers[j].name, name)==0){	
		nameflag=1;
	}
}
	 	if((nameflag==1)&&(modelflag==1)){
	 		 fp = fopen("car_for_customer.txt", "a");
    fprintf(fp, "%s %s", name, model);
    fprintf(fp, "%s", "\n");    
    fclose(fp);
		 }
	 }
	 void lottery(){
	 	Customers customers[200];
FILE* cfile=fopen("customers.txt","r");

char cbuffer[200];
int i=0;

fgets(cbuffer,200,cfile);
while(!feof(cfile)){
	Customers* cu=customers+i;
	sscanf(cbuffer,"%s %s %d",cu->name,cu->gender,&cu->pid);
	fgets(cbuffer,200,cfile);
	 i++;
} 
	srand ( time(NULL) );
	 	int customer_rand=rand()%(i-1);
	     
	     
	 	 
	 	
	 	//=======================
	 		Cars cars[200];
FILE* file=fopen("cars.txt","r");
if(file==NULL){
	
}
char buffer[200];
i=0;

fgets(buffer,200,file);
while(!feof(file)){
	Cars* c=cars+i;
	sscanf(buffer,"%s %s %d %d %s",c->model,c->date,&c->price,&c->tip,c->status);
	fgets(buffer,200,file);
	 i++;
}

        srand ( time(NULL) );
	 	int car_rand=rand()%(i-1);

	     FILE* cfc = fopen("car_for_customer.txt", "a");
    fprintf(cfc, "%s %s", customers[customer_rand].name,cars[car_rand].model );
    fprintf(cfc, "%s", "\n");    
    fclose(cfc);
	 }
void main(int argc, char *argv[]) {
	int input=1;

  while(input!=0){
  
  printf("1) Add Car \n"); 
  printf("2) Print Car List \n"); 
  printf("3) Customer Signup \n"); 
  printf("4) Print Customer List \n"); 
  printf("5) Car for Customer \n"); 
  printf("6) Lottery \n");
  printf("0) Exit \n"); 

  printf("Choose a number: ");
  scanf("%d", &input);

  if(input==1){
  	add_car();
  
  }
  if(input==2){
  	read_car_file();
  }
  if(input==3){
  	customer_sign_up();
  }
  
  if(input==4){
  	read_customer_file();
  }
  if(input==5){
  	car_for_customer();
  }
  if(input==6){
  	lottery();
  }
  
}
}
