#include <gtk/gtk.h>
// Programa que cria uma janela com uma barra de menu

//gcc `pkg-config --cflags gtk+-3.0` menu.c `pkg-config --libs gtk+-3.0`


static void itemMenu(GtkWidget *widget, gpointer data){
    g_print("Item de Menu 1 clicado\n");
    return;
}

static void retorno(GtkWidget *widget, gpointer data){

    g_print("Item de Menu 2: %s\n", (char *)data);
    return;
}

int main(int argc, char **argv){

    gtk_init(&argc, &argv);
    GtkWidget *janela, *vbox;
    GtkWidget *menuBar, *menu, *menuItem, *menuItem2;

    // Config da janela
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(janela), 400 ,400);
    gtk_window_set_title( GTK_WINDOW(janela) , "Programa que cria de menu");

    g_signal_connect(janela, "destroy", G_CALLBACK(gtk_main_quit) ,NULL);

    // Comeco da parte do menu
    // Criando box e orientacao dele
    vbox = gtk_box_new(1, 0);
    
    // Anexando a box na janela
    gtk_container_add(GTK_CONTAINER(janela), vbox);

    // Criando menu bar
    menuBar = gtk_menu_bar_new();

    // Criando menu
    menu = gtk_menu_new();

    // Criando menu item com titulo
    menuItem = gtk_menu_item_new_with_label("Menu 1");
    menuItem2 = gtk_menu_item_new_with_label("Item de menu 1");

    // Atribuindo acao ao menu item 2 com activate
    g_signal_connect(menuItem2, "activate", G_CALLBACK(itemMenu), NULL);


    // Transformando menuItem em menu
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuItem), menu);

    // Anexando menu item 2 em menu
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem2);
    
    // Anexando menuItem(que se tornou menu) na menuBar
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), menuItem);

    // Segundo menu
    GtkWidget *m1, *m2, *m3,*vbox2;


    m1 = gtk_menu_new();
    m2 = gtk_menu_item_new_with_label("Menu 2");
    m3 = gtk_menu_item_new_with_label("Item de menu 2");

    g_signal_connect(m3, "activate", G_CALLBACK(retorno), (gpointer)"realmente deu certo");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(m2), m1);
    gtk_menu_shell_append(GTK_MENU_SHELL(m1), m3);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), m2);

    
    // Anexando a menuBar na box(que decide qual orientacao)
    gtk_box_pack_start(GTK_BOX(vbox), menuBar, 0, 0, 0);






    gtk_widget_show_all(janela);
    gtk_main();

    return 0;
}