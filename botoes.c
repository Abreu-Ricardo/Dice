#include <gtk/gtk.h>
// COMPILAR COM:
// gcc `pkg-config --cflags gtk+-3.0` boxes.c `pkg-config --libs gtk+-3.0`



static void retorno(GtkWidget *widget, gpointer data){
    g_print("Botao pressionado\n");
    return;
}

static void retorno2(GtkWidget *widget, gpointer data){
    g_print("Botao2 pressionado!\n");
    return;
}

int main(int argc, char **argv){

    gtk_init(&argc, &argv);
    GtkWidget *janela, *titulo, *botao, *botao2, *hbox;

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(janela, 400, 400);
    gtk_window_set_title(GTK_WINDOW(janela), "Boxes");

    g_signal_connect(janela, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    titulo  = gtk_label_new("texto do label");
    botao   = gtk_button_new_with_label("texto do botao!");
    botao2  = gtk_button_new_with_label("texto do botao 222!");
    g_signal_connect(botao, "released", G_CALLBACK(retorno), NULL);
    g_signal_connect(botao2, "released", G_CALLBACK(retorno2), NULL);
    
    //hbox   = gtk_hbox_new(0, 0); N USAR COM O hbox eh defasado
    // primeiro parametro define se eh vertical(0) ou horizontal
    hbox   = gtk_box_new(1, 0);
    
    // gtk_box_pack_start_defaults com isso  esses 3 parametros de baixo sao preenchidos automaticamente    
    
    // Ultimos 3 parametros definem como vai funcionar o dimensionamento
    gtk_box_pack_start(GTK_BOX(hbox) , titulo, 1, 1, 3);
    gtk_box_pack_start(GTK_BOX(hbox) , botao , 1, 1, 3);
    gtk_box_pack_start(GTK_BOX(hbox) , botao2, 1, 1, 3);

    gtk_container_add(GTK_CONTAINER(janela), hbox);



    gtk_widget_show_all(janela); // Abilitar a exibicao da janela
    gtk_main();                  // Loop para rodar a janela
    return 0;
}
