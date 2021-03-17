#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dice.h"

// VER Dynamic List view em gtk
//gcc `pkg-config --cflags gtk+-3.0` dado.c `pkg-config --libs gtk+-3.0`

GtkTextBuffer *textbuffer;
char *texto;


void escreve(int dado, int valor){
    
    FILE *history;
    int tam=-1;

    history = fopen("in.txt","wra+");

    fseek(history, 0, SEEK_END);
    tam = ftell(history);
    //rewind(history);

    //memset(texto, 0, tam);
    sprintf(texto, "%sd%d valor: %d \n", texto, dado, valor); 
    fprintf(history, "%s", texto);


    fscanf(history, "%[^'32']", texto);

    fclose(history);

    gtk_text_buffer_set_text(textbuffer, texto, -1);
}

static void botao_clicado(GtkWidget *widget, gpointer data){
    //g_print("botao clicado: %s\n", (char *)data);

    char *string = (char *)data;
    int dado = strtol(string, NULL, 10);
    int valor = roll(dado, 1);

    escreve(dado, valor);


    g_print("d%d valor: %d \n", dado, valor);

}

int main(int argc, char **argv){

    gtk_init(&argc,&argv);

    GtkWidget *janela, *botao[8];
    GtkWidget *grid;
    GtkWidget *sidebar, *stack;

    // Janela config
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(janela), 400 ,400);
    gtk_window_set_title(GTK_WINDOW(janela), "D20");
    gtk_window_set_icon_from_file(GTK_WINDOW(janela), "Icon/Dice.png", NULL);
    g_signal_connect(janela, "destroy", G_CALLBACK(gtk_main_quit), NULL);

   
    // Criando a area de texto
    GtkWidget *textarea;
    GtkTextTagTable *tagtable;
    // GtkTextBuffer *textbuffer;
    GtkTextTag *tag;
    GtkTextMark *mark;

    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *entrada = gtk_entry_new();



    // Linkando a textarea com o scroll para ter scroll na area de texto
    textarea = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scroll), textarea);
    textbuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textarea));
   
    FILE *f;
    f = fopen("in.txt", "rwa+");
    fseek(f, 0, SEEK_END);
    int tam = ftell(f);
    rewind(f);
    
    //char *texto = "\n\nHello, this is some text";
    texto = malloc(sizeof(char) * tam);
    
    fscanf(f, "%[^'EOF']", texto);
    fclose(f);

    printf("%s\n", texto);

    // GtkWidget *label;
    // label = gtk_label_new("asdad\nasdasd\nasdasd\nasdasd\nasdasd\nasdasda\nsdasd\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad555555555555555555555\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\nasdad\n");
      

    // Anexando buffer em
    gtk_text_buffer_set_text (textbuffer, texto, -1);
    //gtk_container_add(GTK_CONTAINER(textarea), label);

    botao[0] = gtk_button_new_with_label("D2");
    botao[1] = gtk_button_new_with_label("D4");
    botao[2] = gtk_button_new_with_label("D6");
    botao[3] = gtk_button_new_with_label("D8");
    botao[4] = gtk_button_new_with_label("D10");
    botao[5] = gtk_button_new_with_label("D12");
    botao[6] = gtk_button_new_with_label("D20");
    botao[7] = gtk_button_new_with_label("D100");
    //botao[8] = gtk_button_new_with_label("*SAIR*");
    botao[8] = gtk_button_new();

    // Colocando imagem do X no botao[8]
    GtkWidget *image = gtk_image_new_from_file("x.jpeg");
    gtk_button_set_image(GTK_BUTTON(botao[8]), image);
    
     g_signal_connect( botao[0], "clicked", G_CALLBACK(botao_clicado), (gpointer)"2");
     g_signal_connect( botao[1], "clicked", G_CALLBACK(botao_clicado), (gpointer)"4");
     g_signal_connect( botao[2], "clicked", G_CALLBACK(botao_clicado), (gpointer)"6");
     g_signal_connect( botao[3], "clicked", G_CALLBACK(botao_clicado), (gpointer)"8");
     g_signal_connect( botao[4], "clicked", G_CALLBACK(botao_clicado), (gpointer)"10");
     g_signal_connect( botao[5], "clicked", G_CALLBACK(botao_clicado), (gpointer)"12");
     g_signal_connect( botao[6], "clicked", G_CALLBACK(botao_clicado), (gpointer)"20");
     g_signal_connect( botao[7], "clicked", G_CALLBACK(botao_clicado), (gpointer)"100");
     g_signal_connect( botao[8], "clicked", G_CALLBACK(gtk_main_quit), NULL);


    grid = gtk_grid_new();

    // Primeira linha
    gtk_grid_attach(GTK_GRID(grid), botao[0], 1 ,0 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[1], 2 ,0 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[2], 3 ,0 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[3], 4 ,0 ,1 ,1);

   

    // Segunda linha
    gtk_grid_attach(GTK_GRID(grid), botao[4], 1 ,1 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[5], 2 ,1 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[6], 3 ,1 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[7], 4 ,1 ,1 ,1);
    
    // Botao sair
    // Testar gtk_grid_attach(GTK_GRID(grid), botao[8], 0 ,0 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), botao[8], 0 ,0 ,1 ,1);

    // Anexando a area de texto e o scroll
    //gtk_grid_attach(GTK_GRID(grid), textarea, 0 ,1 ,1 ,1);
    gtk_grid_attach(GTK_GRID(grid), scroll,  0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entrada, 0, 1, 1, 1);
    

    //gtk_grid_set_row_spacing(GTK_GRID(grid), 50);
    gtk_grid_set_column_homogeneous (GTK_GRID(grid), 1);
    gtk_grid_set_row_homogeneous (GTK_GRID(grid), 1);


    gtk_container_add(GTK_CONTAINER(janela), grid);


    // FILE *arquivo;
    // char t[100];

    // arquivo = fopen("valores.txt", "rw");

    // fprintf(arquivo, "CHAAAMMMAAA\n No Arquivo dado.c\n");
    
    // fscanf(arquivo, "%[^'32']s", t);

    // fclose(arquivo);

    // printf("AQUI %s \n", t);

    gtk_widget_show_all(janela);
    gtk_main();
    return 0;
}
