
typedef struct data{
  
   GtkWidget *label1;
   GtkWidget *label2;
   GtkWidget *label3;
   GtkWidget *label4;
    
   GtkWidget *combo1;
   
   gint num;
   //gchar *numc;
   } data;
  
   
 typedef struct tableaux{
      GtkWidget *label1;
      GtkWidget *label2;
      GtkWidget *label3;
      GtkWidget *label4;
      GtkWidget *combo1;
      //GtkWidget *imagestatus;
      int **ncell;
      int n;
      int control;
      int *cellinrow;
      int *cellincolumn;
      
    } tableaux;
    
  /*  
typedef struct cells{
        int **ncell;
      
    }cells;*/