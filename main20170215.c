


#include <gtk/gtk.h>
#include <malloc.h>
#include <glib.h>
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <cairo.h>
#include <unistd.h>
#include <limits.h>
#include "typedef.h"
#include "functions20170215.h"





int tabside=20;






GtkWidget *g_rankA;
GtkWidget *g_rankB;
GtkWidget *g_rankC;
GtkWidget *g_rankD;
GtkWidget *g_dimA;
GtkWidget *g_dimB;
GtkWidget *g_dimC;
GtkWidget *g_dimD;
GtkWidget *g_combobox1;
GtkTreeModel *g_list1;
GtkWidget *g_button1;
GtkWidget *g_area;
GtkWidget *g_image2;

static cairo_surface_t *surface = NULL;


static void clear_surface (void)
{
  cairo_t *cr;
  cr = cairo_create (surface);
  cairo_set_source_rgb (cr, 0.3,0.3,0.3);
  cairo_paint (cr);
  cairo_destroy (cr);
  
  return;
}


static gboolean configure_event_cb (GtkWidget *widget, 
                                    GdkEventConfigure *event, 
                                    gpointer data)
{
  if (surface)
    cairo_surface_destroy (surface);
    surface = gdk_window_create_similar_surface (gtk_widget_get_window (widget),
                                               CAIRO_CONTENT_COLOR,
                                               gtk_widget_get_allocated_width (widget),
                                               gtk_widget_get_allocated_height (widget));

  
  clear_surface ();

  return TRUE;
}



static gboolean draw_cb (GtkWidget *widget,  
                         cairo_t   *cr,  
                         gpointer   data)
{
  cairo_set_source_surface (cr, surface, 0, 0);
  cairo_paint (cr);

  return FALSE;
}


static void draw_cell (GtkWidget *widget,  
                        gdouble    x,  
                        gdouble    y, 
                        gpointer   user_data)
{
  
    
  tableaux *ptr;
  ptr= (tableaux *) user_data;
    
  cairo_t *cr;

  int nx;
  int ny;
  int k=0;
  int l=0;
  int i=0;
  int j=0;
  
  
  
  int size=20;
  
  nx= (int) x/size;
  ny= (int) y/size;
  
  int xmod= (int) (nx+1)*size;
  int ymod= (int) (ny+1)*size;
  
  
  
  
  
  while(i<tabside){
      if(ptr->ncell[i][ny+1]==88){
      k+=1;};       
      i+=1;};
      //printf("%d %d\n",k,ny+1);     
    ptr->ncell[k][ny+1]=88;
    xmod=(k+2)*size;
  
    
 
    
 
ptr->control=TRUE;
for(i=0;i<tabside;i++){
k=0;
for(j=0;j<tabside-1;j++){ 
  
if(ptr->ncell[i][j] == 88 && ptr->ncell[i][j+1] != 88) {k+=1;}
  else;
};
if(k>1){ptr->control=FALSE;}
else;
};


i=0;
j=0;
k=0;







for(i=0;i<tabside;i++){
for(j=0;j<tabside;j++){ 
  
if(ptr->ncell[j][i] == 88){k+=1;};
  
};
  
  if(k != 0){ptr->cellinrow[l]=k;
  //if(ptr->cellinrow[l] != 0){printf("riga %d celle %d\n",l,ptr->cellinrow[l]);};
  l+=1;
  };
  k=0;};

i=0;
j=0;
k=0;
l=0;

for(i=0;i<tabside;i++){
for(j=0;j<tabside;j++){if(ptr->ncell[i][j] == 88){k+=1;}; };
  if( k != 0){ptr->cellincolumn[l]=k;
  //if(ptr->cellinrow[l] != 0){printf("colonna %d celle %d\n",l,ptr->cellincolumn[l]);};
    l+=1;};
  k=0;};


int ncolumn= ptr->cellinrow[0];
int nrow=ptr->cellincolumn[0];

i=0;
for(i=0; i<ncolumn; i++){
  if(ptr->cellinrow[i] < ptr->cellinrow[i+1]){ptr->control=FALSE;}
  else;};

  
  
  cr = cairo_create (surface);
  cairo_set_source_rgb (cr, 0,0,0);
  cairo_rectangle (cr, xmod-size, ymod-size, size, size);
  cairo_set_line_width(cr, 4);
  cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER); 
  cairo_stroke(cr);
  
  cairo_rectangle (cr, xmod-size+1, ymod-size+1, size-2, size-2);
  cairo_set_source_rgb (cr, 255,255,255);
  cairo_fill (cr);

  cairo_destroy (cr);

  

   func_A (widget, ptr);
   func_B (widget, ptr);
   func_C (widget, ptr);
   func_D (widget, ptr);
  
  
  gtk_widget_queue_draw_area (widget, xmod-size, ymod-size, size, size);
  
  return ;
}

static gboolean button_press_event_cb (GtkWidget  *widget, 
                                       GdkEventButton *event,   
                                       gpointer   user_data)
{
  tableaux *ptr;
  ptr= (tableaux *) user_data;
  int i=0;
  int j=0;
  
  if (surface == NULL)
    return FALSE;

  if (event->button == GDK_BUTTON_PRIMARY)
    {
      draw_cell (widget, event->x, event->y, user_data);
      
    }
  else if (event->button == GDK_BUTTON_SECONDARY)
    { 
      
      for(i=0;i<tabside;i++){
       for(j=0;j<tabside;j++){
      
	 ptr->ncell[i][j]=0;
	 
      };

    };
    
     for(i=0;i<tabside;i++){ptr->cellincolumn[i]=0;};
      for(i=0;i<tabside;i++){ptr->cellinrow[i]=0;};
      
      ptr->control=TRUE;
      
      clear_surface ();
      gtk_label_set_text(GTK_LABEL(ptr->label1), "-" );
      gtk_label_set_text(GTK_LABEL(ptr->label2), "-" );
      gtk_label_set_text(GTK_LABEL(ptr->label3), "-" );
      gtk_label_set_text(GTK_LABEL(ptr->label4), "-" );
      gtk_widget_queue_draw (widget);
      
    }


    return TRUE;
}






int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window1;
    
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/YoungTab20161006.glade", NULL);
 
    window1= GTK_WIDGET(gtk_builder_get_object(builder, "YoungTab20161006"));
    
    
    g_image2 = GTK_WIDGET(gtk_builder_get_object(builder, "image2"));
    g_rankA = GTK_WIDGET(gtk_builder_get_object(builder, "rankA"));
    g_rankB = GTK_WIDGET(gtk_builder_get_object(builder, "rankB"));
    g_rankC = GTK_WIDGET(gtk_builder_get_object(builder, "rankC"));
    g_rankD = GTK_WIDGET(gtk_builder_get_object(builder, "rankD"));
    g_dimA = GTK_WIDGET(gtk_builder_get_object(builder, "dimA"));
    g_dimB = GTK_WIDGET(gtk_builder_get_object(builder, "dimB"));
    g_dimC = GTK_WIDGET(gtk_builder_get_object(builder, "dimC"));
    g_dimD = GTK_WIDGET(gtk_builder_get_object(builder, "dimD"));
    g_button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    
    g_combobox1 = GTK_WIDGET(gtk_builder_get_object(builder, "combobox1"));
    g_area = GTK_WIDGET(gtk_builder_get_object(builder, "drawingarea1"));
   // g_list1 = GTK_WIDGET(gtk_builder_get_object(builder, "liststore1"));

   struct data dat;
 
   dat.label1=g_rankA;
   dat.label2=g_rankB;
   dat.label3=g_rankC;
   dat.label4=g_rankD;
   dat.num=0;
   dat.combo1=g_combobox1;

    
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
      
  
  
  struct tableaux tab;
    
  tab.label1=g_dimA;
  tab.label2=g_dimB;
  tab.label3=g_dimC;
  tab.label4=g_dimD;
  tab.combo1=g_combobox1;
  tab.control=TRUE;
  
  
  
  tab.cellinrow=(int *) calloc(tabside,sizeof(int));
  tab.cellincolumn=(int *) calloc(tabside,sizeof(int));
  
  
  gtk_image_set_from_stock(g_image2, GTK_STOCK_DISCARD, GTK_ICON_SIZE_MENU);
  
  
   
   int i=0;
   
   
   tab.ncell=(int **) calloc(tabside,sizeof(int *));
   for(i=0;i<tabside;i++){
    tab.ncell[i]=(int *) calloc(tabside,sizeof(int));
   };


   
  g_signal_connect(g_combobox1,"changed", G_CALLBACK(rank_function), &dat);
  g_signal_connect (g_area, "draw",   G_CALLBACK (draw_cb), &tab);
  g_signal_connect (g_area,"configure-event", G_CALLBACK (configure_event_cb), NULL);
  g_signal_connect (g_area, "button-press-event",  G_CALLBACK (button_press_event_cb), &tab);
  //g_signal_connect(g_button1,"clicked", G_CALLBACK(clear_surface), NULL);
  
  tab.n=0;
  
//   printf("%d\n\n", dat.num);
//   tab.n=gtk_combo_box_get_active (GTK_COMBO_BOX(g_combobox1));;
//   printf("%d\n\n", tab.n);
//   tab.n=5;
  
  
   g_signal_connect(g_combobox1,"changed", G_CALLBACK(func_A), &tab);
   g_signal_connect(g_combobox1,"changed", G_CALLBACK(func_B), &tab);
   g_signal_connect(g_combobox1,"changed", G_CALLBACK(func_C), &tab);
   g_signal_connect(g_combobox1,"changed", G_CALLBACK(func_D), &tab);
   
  
   
    gtk_widget_set_events (g_area, GDK_EXPOSURE_MASK
			 | GDK_LEAVE_NOTIFY_MASK
			 | GDK_BUTTON_PRESS_MASK
			 | GDK_POINTER_MOTION_MASK
			 | GDK_POINTER_MOTION_HINT_MASK
			 | GDK_KEY_RELEASE_MASK);
    

   g_signal_connect(g_area, "button-press-event", G_CALLBACK(func_A), &tab);
   g_signal_connect(g_area, "button-press-event", G_CALLBACK(func_B), &tab);
   g_signal_connect(g_area, "button-press-event", G_CALLBACK(func_C), &tab);
   g_signal_connect(g_area, "button-press-event", G_CALLBACK(func_D), &tab);
    
  
   
    gtk_widget_show_all (window1); 
    
        
     
    g_signal_connect (G_OBJECT(window1), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    
        
    
    g_object_unref(builder);
    
    gtk_main();

    
    
    
    
    return 0;
}


void user_function2 ()
{
  
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    count++;
    sprintf(str_count, "%d", count);
      
    

  gtk_label_set_text(GTK_LABEL(g_rankA), str_count); 
  
  g_free (str_count);
  
  return;
}

