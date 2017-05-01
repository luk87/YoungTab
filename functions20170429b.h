//We define the four functions computing the dimension of the tableaux, one for each classical Lie algebra, func_A, func_B, 
//func_C and func _D  
//For any function  the matrices r and h define the content of the different cells of the tableuax. 
//The floats r and h are the product of all the elements in the cell, h is given by the hook rule.
    
 void rank_function (GtkWidget *one,  gpointer user_data)
{  
  
  data *ptr;
  ptr= (data *) user_data;
  char str_count[11] = {1};
  ptr->num=gtk_combo_box_get_active (GTK_COMBO_BOX(ptr->combo1));
  ptr->num+=1;
  sprintf(str_count, "%d", ptr->num);
  gtk_label_set_text(GTK_LABEL(ptr->label1), str_count ); 
  gtk_label_set_text(GTK_LABEL(ptr->label2), str_count );
  gtk_label_set_text(GTK_LABEL(ptr->label3), str_count );
  gtk_label_set_text(GTK_LABEL(ptr->label4), str_count );
 
 
  return ;  
  
}
 
 
 
 //function computing the dimension of tableaux for algebra of type A
 
 
 
  void func_A (GtkWidget *name, gpointer user_data)
{
   
  
  
  tableaux *ptr;
  ptr= (tableaux *) user_data;
  
  char str_count[10] = {0};
  
  
  if(ptr->control == FALSE){
    
    gtk_label_set_text(GTK_LABEL(ptr->label1), "no" );
    goto jump1;
  };
  
  
  
  ptr->n=gtk_combo_box_get_active (GTK_COMBO_BOX(ptr->combo1));
  
  int n=ptr->n+1;
  
  if(n<= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label1), "-" );
    goto jump1;
  };
  
int dim=0;    

int **rvalue;
int **hook;
float h=1.0;
float r=1.0;


int ncolumn= ptr->cellinrow[0];
int nrow=ptr->cellincolumn[0];


int i=0;
int j=0;
int a=0;



while(j < ncolumn){
while(i < nrow){
if(ptr->cellinrow[i]-j> 0){a+=1;};
i+=1;  
}

ptr->cellincolumn[j]=a;
a=0;
i=0;
j+=1;
};

j=0;
i=0;


  hook=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    hook[i]=(int *) malloc(ptr->cellinrow[i]*sizeof(int));/*columns*/
   };


  
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
hook[i][j]=ptr->cellinrow[i]+ptr->cellincolumn[j]-i-j-1;   
//printf("%d\n",hook[i][j]);
};
};


rvalue=(int **) malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    rvalue[i]=(int *) malloc(ncolumn*sizeof(int));/*columns*/
   };
   
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=0;   
};
};
   

i=0;
j=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=n+1+j-i; 
//printf("%d\n",rvalue[i][j]);
};
};




j=0;
i=0;
int l=0;
int m=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){

for(l=0; l<nrow; ++l){
for(m=0; m<ptr->cellinrow[l]; ++m){

    
if(rvalue[i][j] == hook[l][m] && rvalue[i][j] != 1 && hook[l][m] != 1 ){rvalue[i][j]=1; hook[l][m]=1;
};

    
};
};
    
    
};
};


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){

for(l=0; l<nrow; ++l){
for(m=0; m<ptr->cellinrow[l]; ++m){

    
if(rvalue[i][j] == hook[l][m] && rvalue[i][j] != 1 && hook[l][m] != 1 ){rvalue[i][j]=1; hook[l][m]=1;
};

    
};
};
    
    
};
};


i=0;
j=0;



for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(hook[i][j] > 0){h=h*hook[i][j];
if(h>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label1), "over" );
    goto jump1;};    
if(h <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label1), "-" );
  goto jump1;};
    
}
else{};

};
};



i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
r=r*rvalue[i][j];

if(r > FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label1), "over" );
    goto jump1;};
if(r <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label1), "-" );
  goto jump1;};
//printf("%d\n",rvalue[i][j]);
};
};


dim=r/h;
//printf("%d\n\n",dim);
//printf("float max is %f\n\n", FLT_MAX);

//printf("%d\n %f\n %f\n", dim,r,h);
 if(dim <= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label1), "-" );
    goto jump1;
  };
  

   //printf("%d\n\n",dim);

  sprintf(str_count, "%d", dim);
  gtk_label_set_text(GTK_LABEL(ptr->label1), str_count ); 

free(rvalue);
free(hook);

jump1:
return ;

}

 //function computing the dimension of tableaux for algebra of type B


void func_B (GtkWidget *name, gpointer user_data)
{
  
  tableaux *ptr;
  ptr= (tableaux *) user_data;
  char str_count[10] = {1};
  
  ptr->n=gtk_combo_box_get_active (GTK_COMBO_BOX(ptr->combo1));
  
  int n=ptr->n+1;
  
  
  if(ptr->control == FALSE){
    
    gtk_label_set_text(GTK_LABEL(ptr->label2), "no" );
    goto jump2;
  };
  
   if(n<= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label2), "-" );
    goto jump2;
  };
  
  
  
  
  
int dim=0;    

int **rvalue;
int **hook;
float h=1.0;
float r=1.0;


int ncolumn= ptr->cellinrow[0];
int nrow=ptr->cellincolumn[0];


int i=0;
int j=0;
int a=0;


while(j < ncolumn){
while(i < nrow){
if(ptr->cellinrow[i]-j> 0){a+=1;};
i+=1;  
}

ptr->cellincolumn[j]=a;
a=0;
i=0;
j+=1;
};

j=0;
i=0;


hook=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    hook[i]=(int *) malloc(ptr->cellinrow[i]*sizeof(int ));/*columns*/
   };


  
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
hook[i][j]=ptr->cellinrow[i]+ptr->cellincolumn[j]-i-j-1;   
//printf("%d\n",hook[i][j]);
};
};








rvalue=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    rvalue[i]=(int *) malloc(ncolumn*sizeof(int));/*columns*/
   };
   
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=0;   
};
};
   

i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(i < j){rvalue[i][j]=i+j-ptr->cellincolumn[i]-ptr->cellincolumn[j];}
else{rvalue[i][j]=ptr->cellinrow[i]+ptr->cellinrow[j]-i-j-2;}
};
};






i=0;
j=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=2*n+1+rvalue[i][j];
};
};  



j=0;
i=0;
int l=0;
int m=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){

for(l=0; l<nrow; ++l){
for(m=0; m<ptr->cellinrow[l]; ++m){

    
if(rvalue[i][j] == hook[l][m] && rvalue[i][j] != 1 && hook[l][m] != 1 ){rvalue[i][j]=1; hook[l][m]=1;
};

    
};
};
    
    
};
};



i=0;
j=0;



for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(hook[i][j] > 0){h=h*hook[i][j];
    
 if(h>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label2), "over" );
    goto jump2;};
if(h <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label2), "-" );
  goto jump2;};
    
}
else{};

};
};



i=0;
j=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
r=r*rvalue[i][j];

if(r>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label2), "over" );
    goto jump2;};
if(r <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label2), "-" );
  goto jump2;};
};
};  



dim=r/h;

if(dim <= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label2), "-" );
    goto jump2;
  };
   //printf("%d\n\n",dim);

  sprintf(str_count, "%d", dim);
  gtk_label_set_text(GTK_LABEL(ptr->label2), str_count ); 


free(rvalue);
free(hook);

jump2:
return ;

}

 //function computing the dimension of tableaux for algebra of type C


void  func_C (GtkWidget *name, gpointer user_data)
{
  tableaux *ptr;
  ptr= (tableaux *) user_data;
  char str_count[10] = {1};
  
  ptr->n=gtk_combo_box_get_active (GTK_COMBO_BOX(ptr->combo1));
  
  int n=ptr->n+1;
  
  
  if(ptr->control == FALSE){
    
    gtk_label_set_text(GTK_LABEL(ptr->label3), "no" );
    goto jump3;
  };
  
  
  if(n<= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label3), "-" );
    goto jump3;
  };
  
  
int dim=0;    

int **rvalue;
int **hook;
float h=1.0;
float r=1.0;


int ncolumn= ptr->cellinrow[0];
int nrow=ptr->cellincolumn[0];


int i=0;
int j=0;
int a=0;


while(j < ncolumn){
while(i < nrow){
if(ptr->cellinrow[i]-j> 0){a+=1;};
i+=1;  
}

ptr->cellincolumn[j]=a;
a=0;
i=0;
j+=1;
};

j=0;
i=0;


hook=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    hook[i]=(int *) malloc(ptr->cellinrow[i]*sizeof(int));/*columns*/
   };


  
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
hook[i][j]=ptr->cellinrow[i]+ptr->cellincolumn[j]-i-j-1;   
//printf("%d\n",hook[i][j]);
};
};







rvalue=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    rvalue[i]=(int *) malloc(ncolumn*sizeof(int ));/*columns*/
   };
   
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=0;   
};
};
   

i=0;
j=0;
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
  
if(i > j){rvalue[i][j]=ptr->cellinrow[i]+ptr->cellinrow[j]-i-j;}
else{rvalue[i][j]=i+j+2-ptr->cellincolumn[i]-ptr->cellincolumn[j];};
};
};  


i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=2*n+rvalue[i][j];
};
}; 





j=0;
i=0;
int l=0;
int m=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){

for(l=0; l<nrow; ++l){
for(m=0; m<ptr->cellinrow[l]; ++m){

    
if(rvalue[i][j] == hook[l][m] && rvalue[i][j] != 1 && hook[l][m] != 1 ){rvalue[i][j]=1; hook[l][m]=1;
};

    
};
};
    
    
};
};



i=0;
j=0;



for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(hook[i][j] > 0){h=h*hook[i][j];
if(h>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label3), "over" );
    goto jump3;};    
if(h <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label3), "-" );
  goto jump3;};    
    
}
else{};

};
};



i=0;
j=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
r=r*rvalue[i][j];
if(r>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label3), "over" );
    goto jump3;};
    if(r <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label3), "-" );
  goto jump3;};
};
};  

dim=r/h;
if(dim <= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label3), "-" );
    goto jump3;
  };

   //printf("%d\n\n",dim);

  sprintf(str_count, "%d", dim);
  gtk_label_set_text(GTK_LABEL(ptr->label3), str_count ); 


free(rvalue);
free(hook);

jump3:

return ;

}

//function computing the dimension of tableaux for algebra of type A


void func_D (GtkWidget *name, gpointer user_data)
{
  
tableaux *ptr;
  ptr= (tableaux *) user_data;
  char str_count[10] = {1};
  
  ptr->n=gtk_combo_box_get_active (GTK_COMBO_BOX(ptr->combo1));
  
  int n=ptr->n+1;  
  
//   if(ptr->control == TRUE){
//     
//    GdkColor color;
//   gdk_color_parse ("#000000", &color);
//   gtk_widget_modify_fg (GTK_LABEL(ptr->label4), GTK_STATE_NORMAL, &color);
//     
//   };
  
  if(ptr->control == FALSE){
//      GdkColor color;
//   gdk_color_parse ("#FFBF00", &color);
//   gtk_widget_modify_fg (GTK_LABEL(ptr->label4), GTK_STATE_NORMAL, &color);
    
   //gtk_label_set_attributes(GTK_LABEL(ptr->label4),red);
    
     //gtk_image_get_stock(ptr->imagestatus, "yes", NULL);
     gtk_label_set_text(GTK_LABEL(ptr->label4), "no");
    goto jump4;
  };
  
  if(n<= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label4), "-" );
    goto jump4;
  };
  
  
int dim=0;    

int **rvalue;
int **hook;
float h=1.0;
float r=1.0;


int ncolumn= ptr->cellinrow[0];
int nrow=ptr->cellincolumn[0];


int i=0;
int j=0;
int a=0;


while(j < ncolumn){
while(i < nrow){
if(ptr->cellinrow[i]-j> 0){a+=1;};
i+=1;  
}

ptr->cellincolumn[j]=a;
a=0;
i=0;
j+=1;
};

j=0;
i=0;


hook=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    hook[i]=(int *) malloc(ptr->cellinrow[i]*sizeof(int));/*columns*/
   };


  
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
hook[i][j]=ptr->cellinrow[i]+ptr->cellincolumn[j]-i-j-1;   
//printf("%d\n",hook[i][j]);
};
};





i=0;
j=0;


rvalue=(int **)malloc(nrow*sizeof(int *));/*rows*/  
  for(i=0; i<nrow; ++i){ 
    rvalue[i]=(int *) malloc(ncolumn*sizeof(int));/*columns*/
   };
   
for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=0;   
};
};
   

i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(i < j){rvalue[i][j]=i+j-ptr->cellincolumn[i]-ptr->cellincolumn[j];}
else{rvalue[i][j]=ptr->cellinrow[i]+ptr->cellinrow[j]-i-j-2;};
};
};  




i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
rvalue[i][j]=2*n+rvalue[i][j];
};
};  


j=0;
i=0;
int l=0;
int m=0;


for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
l=0;
m=0;
    
for(l=0; l<nrow; ++l){
for(m=0; m<ptr->cellinrow[l]; ++m){

    
if(rvalue[i][j] == hook[l][m] && rvalue[i][j] != 1 && hook[l][m] != 1 ){rvalue[i][j]=1; hook[l][m]=1;};

};
};
    
    
};
};



i=0;
j=0;



for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
if(hook[i][j] > 0){h=h*hook[i][j];
if(h>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label4), "over" );
    goto jump4;};    
if(h <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label4), "-" );
  goto jump4;};    
}
else{};

};
};



i=0;
j=0;

for(i=0; i<nrow; ++i){
for(j=0; j<ptr->cellinrow[i]; ++j){
r=r*rvalue[i][j];
if(r>FLT_MAX){//overflow control sequence
    gtk_label_set_text(GTK_LABEL(ptr->label4), "over" );
    goto jump4;};
if(r <0 ){
 gtk_label_set_text(GTK_LABEL(ptr->label4), "-" );
  goto jump4;};
};
};  



dim=r/h;


if(dim <= 0){
    
    gtk_label_set_text(GTK_LABEL(ptr->label4), "-" );
    goto jump4;
  };

   //printf("%d\n\n",dim);

  sprintf(str_count, "%d", dim);
  gtk_label_set_text(GTK_LABEL(ptr->label4), str_count ); 





free(rvalue);
free(hook);

jump4:
return ;

}

