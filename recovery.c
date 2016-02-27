#include<gtk/gtk.h>
#include<webkit/webkit.h>
#include<stdio.h>
#include<string.h>

static void destroy (GtkWidget *window, gpointer data);
static void button_clicked(GtkWidget *button, gpointer data);
static void new_tab(GtkWidget *button, GtkWidget *notebook);
static void close_tab(GtkWidget *button, GtkNotebook *notebook);
void activate(GtkWidget* widget, gpointer* wid);
void progress (WebKitWebView *web, gint progress,gpointer* data);
void finished (WebKitWebView  *web_view, WebKitWebFrame *frame,gpointer*  data);
	GtkWidget *window, *table, *label1, *label2, *child1, *child2, *notebook, *hbox1, *hbox2, *close_button;
    GtkWidget *menubar, *file, *edit, *help, *filemenu, *editmenu, *helpmenu;
    GtkWidget *new, *open,  *copy, *cut, *paste, *content, *about, *forward, *back, *stop, *home, *download, *bookmark;
    GtkWidget *vbox1, *vbox2,*label3, *label4, *label5, *label6, *label7, *label8, *logo, *search_entry, *search_button;
    GtkWidget  *label9, *label10, *label11, *label12, *lable13, *lable14, *plus_button, *url_entry, *go_button, *hbox, *vbox, *scroll_window;
    GtkWidget *hbox3, *hboxsk, *hboxsk1, *hboxsk2,*hboxsk3, *hboxsk4,*hboxsk5, *hboxsk6,*hboxsk7, *hboxsk8, *hboxsk9, *hbox_web, *vbox_web, *web, *hboxs, *image;
	GdkColor green,red,blue,yellow,black;

int main(int argc, char *argv[])
{
    GtkWidget *close;


    GtkAccelGroup *group;
	
	logo = gtk_image_new_from_file("logo1.jpg");



    gtk_init (&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "WELCOME TO RECOVERY BROWSER");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_window_set_default_size(GTK_WINDOW(window),700,700);
    gtk_window_set_resizable(GTK_WINDOW(window),TRUE);
   
     
    gtk_window_present(GTK_WINDOW(window));



    group=gtk_accel_group_new();
    menubar = gtk_menu_bar_new();
    
    //creating of menu items
    file = gtk_menu_item_new_with_label("File");
    edit = gtk_menu_item_new_with_label("Edit");
    help = gtk_menu_item_new_with_label("Help"); 
    //like creating groups for sub menus
    filemenu = gtk_menu_new();
    editmenu = gtk_menu_new();
    helpmenu = gtk_menu_new();

    //assigning each group of submenu to the main menu

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editmenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),  edit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

    //now creating the file menu content
    new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, group);
    open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, group);
    close=gtk_image_menu_item_new_from_stock(GTK_STOCK_CLOSE, group);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), close);

    //now creating the edit menu content
    cut = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT,group);
    copy = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, group);
    paste = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), cut);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), copy);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), paste);

    //now creating the help menu content
    content=gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP, group);
    about=gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT,group);
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), content);
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);

//code for url entry
	url_entry = gtk_entry_new();
	search_entry = gtk_entry_new();
	
	gtk_entry_set_text(GTK_ENTRY(url_entry), "http://");
//images for buttons
	plus_button = gtk_button_new();
    close_button = gtk_button_new();
    go_button = gtk_button_new();
	forward = gtk_button_new();
	back = gtk_button_new();
	stop = gtk_button_new();
	home = gtk_button_new();
	download = gtk_button_new();
	bookmark = gtk_button_new();
	search_button = gtk_button_new();
	
	g_object_set(forward, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(back, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(stop, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(home, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(download, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(bookmark, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(go_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(close_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(plus_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(search_button, "relief", GTK_RELIEF_NONE, NULL);
	
	
	gtk_widget_set_size_request(forward, 20,20);
	gtk_widget_set_size_request(back, 20,20);
	gtk_widget_set_size_request(search_button, 40,40);
	gtk_widget_set_size_request(stop, 20,20);
	gtk_widget_set_size_request(home, 20,20);
	gtk_widget_set_size_request(download, 20,20);
	gtk_widget_set_size_request(bookmark, 20,20);
	gtk_widget_set_size_request(menubar, 200,0);
	gtk_widget_set_size_request(url_entry, 800,30);
	gtk_widget_set_size_request(search_entry, 300,30);
	
	
	hboxsk = gtk_hbox_new(FALSE, 0);
	hboxsk1 = gtk_hbox_new(FALSE, 0);
	hboxsk2 = gtk_hbox_new(FALSE, 0);
	hboxsk3 = gtk_hbox_new(FALSE, 0);
	hboxsk4 = gtk_hbox_new(FALSE, 0);
	hboxsk5 = gtk_hbox_new(FALSE, 0);
	hboxsk6 = gtk_hbox_new(FALSE, 0);
	hboxsk7 = gtk_hbox_new(FALSE, 0);
	hboxsk8 = gtk_hbox_new(FALSE, 0);
	hboxsk9 = gtk_hbox_new(FALSE, 0);
	
	image = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk), image);
	gtk_container_add(GTK_CONTAINER(forward), hboxsk);
	gtk_widget_show_all(forward);
	
	
	image = gtk_image_new_from_stock(GTK_STOCK_CLOSE, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk1), image);
	gtk_container_add(GTK_CONTAINER(stop), hboxsk1);
	gtk_widget_show_all(stop);
	
	image = gtk_image_new_from_stock(GTK_STOCK_GO_BACK, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk2), image);
	gtk_container_add(GTK_CONTAINER(back), hboxsk2);
	gtk_widget_show_all(back);
	

	image = gtk_image_new_from_stock(GTK_STOCK_HOME, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk3), image);
	gtk_container_add(GTK_CONTAINER(home), hboxsk3);
	gtk_widget_show_all(home);


	image = gtk_image_new_from_stock(GTK_STOCK_GO_DOWN, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk4), image);
	gtk_container_add(GTK_CONTAINER(download), hboxsk4);
	gtk_widget_show_all(download);
	
	
	image = gtk_image_new_from_stock(GTK_STOCK_ADD, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk5), image);
	gtk_container_add(GTK_CONTAINER(bookmark), hboxsk5);
	gtk_widget_show_all(bookmark);


	image = gtk_image_new_from_stock(GTK_STOCK_CLOSE, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk6), image);
	gtk_container_add(GTK_CONTAINER(close_button), hboxsk6);
	gtk_widget_show_all(close_button);
	
	image = gtk_image_new_from_stock(GTK_STOCK_FIND, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk7), image);
	gtk_container_add(GTK_CONTAINER(go_button), hboxsk7);
	gtk_widget_show_all(go_button);
	
	image = gtk_image_new_from_stock(GTK_STOCK_ADD, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk8), image);
	gtk_container_add(GTK_CONTAINER(plus_button), hboxsk8);
	gtk_widget_show_all(plus_button);
	
	image = gtk_image_new_from_stock(GTK_STOCK_FIND, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk9), image);
	gtk_container_add(GTK_CONTAINER(search_button), hboxsk9);
	gtk_widget_show_all(search_button);



    /*code for tab
     * please try to remeber*/

     notebook = gtk_notebook_new();
     hbox1 = gtk_hbox_new(TRUE, 0);
     hbox2 = gtk_hbox_new(TRUE, 2);
     hbox3 = gtk_hbox_new(TRUE, 2);
     hbox = gtk_hbox_new(FALSE, 0);
     hboxs = gtk_hbox_new(FALSE, 0);
	 hbox_web= gtk_hbox_new(1, 0);
     vbox = gtk_vbox_new(FALSE, 2);
     vbox_web = gtk_vbox_new(FALSE, FALSE);
     
     web = webkit_web_view_new();
	 gtk_box_pack_start(GTK_BOX(hbox_web),web,0,0,0);
     //gtk_container_add(GTK_CONTAINER(hbox_web), web);
     //gtk_container_add (GTK_CONTAINER (scroll_window), web);

	 
     gtk_widget_set_size_request(go_button, 40,10);
     gtk_widget_set_size_request(hbox2, 10,20);
     
     label1 = gtk_label_new("new tab");
     label2= gtk_label_new(" \n\n\n\n\n\n");
     label3= gtk_label_new("    ");
     label4= gtk_label_new(" ");
     label5= gtk_label_new(" ");
     label6= gtk_label_new(" ");
     label7= gtk_label_new(" \t\t\t\t");
     label8= gtk_label_new(" ");
     label9= gtk_label_new(" \t\tSearch");
     label10= gtk_label_new(" ");
     label11= gtk_label_new(" ");
     label12= gtk_label_new("\t\t\t\t");
     lable13= gtk_label_new("\t\t\t\t");
     
     gtk_box_pack_start(GTK_BOX(hbox1), close_button, TRUE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(hbox1), label1, FALSE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox1), plus_button, FALSE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), back, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), stop, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), forward, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), url_entry, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), go_button, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), label3, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), home, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), bookmark, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), download, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), label7, TRUE, TRUE, 5);
    
     gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, FALSE, 0);
     gtk_container_add(GTK_CONTAINER(vbox), hbox_web);     
     gtk_box_pack_start(GTK_BOX(vbox_web), logo, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), label9, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), search_entry, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), search_button, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), label10, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), hboxs, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label2, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label4, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label5, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label6, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox_web), vbox_web, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox_web), lable13, TRUE, TRUE, 0);
     //gtk_box_pack_start(GTK_BOX(vbox), hbox_web, TRUE, TRUE, 0); 
     gtk_box_pack_start(GTK_BOX(window), vbox, TRUE, TRUE, 0);

     //append to pages to the notebook.
     
     gtk_notebook_append_page(GTK_NOTEBOOK(notebook), vbox,hbox1);
     //gtk_notebook_append_page(GTK_NOTEBOOK(notebook), label8, plus_button);
     
     //gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_TOP);

	

	
	
	


	

	
    //adding the menu to a vertical box
    vbox1 = gtk_vbox_new(FALSE,5);
     
    gtk_box_pack_start(GTK_BOX(hbox2), menubar, FALSE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(vbox1), hbox2, FALSE, TRUE, 5);
     
    gtk_box_pack_start(GTK_BOX(vbox1), notebook, TRUE, TRUE, 5);
    
    //my callback signals
    g_signal_connect(GTK_OBJECT(window), "destroy",GTK_SIGNAL_FUNC(destroy),NULL);
    g_signal_connect(GTK_OBJECT(close_button), "clicked", GTK_SIGNAL_FUNC(close_tab), (gpointer) notebook);
    g_signal_connect(GTK_OBJECT(go_button), "clicked", GTK_SIGNAL_FUNC(button_clicked), "go");
    g_signal_connect(GTK_OBJECT(plus_button), "clicked", GTK_SIGNAL_FUNC(new_tab), (gpointer) notebook);
    g_signal_connect(GTK_OBJECT(search_button), "clicked", GTK_SIGNAL_FUNC(button_clicked), "search");
    g_signal_connect(GTK_OBJECT(stop), "clicked", GTK_SIGNAL_FUNC(button_clicked), "stop");
    g_signal_connect(GTK_OBJECT(forward), "clicked", GTK_SIGNAL_FUNC(button_clicked), "forward");
    g_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(button_clicked), "back");
    g_signal_connect(GTK_OBJECT(home), "clicked", GTK_SIGNAL_FUNC(button_clicked), "home");
    g_signal_connect(GTK_OBJECT(download), "clicked", GTK_SIGNAL_FUNC(button_clicked), "download");
    g_signal_connect(GTK_OBJECT(bookmark), "clicked", GTK_SIGNAL_FUNC(button_clicked), "bookmark");
    
    g_signal_connect(url_entry, "activate",  G_CALLBACK(activate), web);
	g_signal_connect(WEBKIT_WEB_VIEW(web),"load-progress-changed",G_CALLBACK(progress),url_entry);
	g_signal_connect(WEBKIT_WEB_VIEW(web),"load-finished",G_CALLBACK(finished),url_entry);
    
    gtk_container_add(GTK_CONTAINER(window), vbox1);
    
    gtk_widget_grab_focus (web);
    gtk_widget_show_all(hboxsk);
    gtk_widget_show_all(hboxsk1);
    gtk_widget_show_all(hboxsk2);
    gtk_widget_show_all(hboxsk3);
    gtk_widget_show_all(hboxsk4);
    gtk_widget_show_all(hboxsk5);
    gtk_widget_show_all(hboxsk6);
    gtk_widget_show_all(vbox1);
    gtk_widget_show_all(vbox);
    gtk_widget_show_all(hbox);
    gtk_widget_show_all(hbox1);
    gtk_widget_show_all(hbox2);
    gtk_widget_show_all(hbox3);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

static void destroy (GtkWidget *window, gpointer data)
{
	gtk_main_quit();
}


static void new_tab(GtkWidget *button, GtkWidget *notebook1)
{
	
	gint page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook1));
	logo = gtk_image_new_from_file("logo.jpg");

	
	//code for url entry
	url_entry = gtk_entry_new();
	search_entry = gtk_entry_new();
	
	gtk_entry_set_text(GTK_ENTRY(url_entry), "http://");
//images for buttons
	plus_button = gtk_button_new();
    close_button = gtk_button_new();
    go_button = gtk_button_new();
	forward = gtk_button_new();
	back = gtk_button_new();
	stop = gtk_button_new();
	home = gtk_button_new();
	download = gtk_button_new();
	bookmark = gtk_button_new();
	search_button = gtk_button_new();
	
	g_object_set(forward, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(back, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(stop, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(home, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(download, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(bookmark, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(go_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(close_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(plus_button, "relief", GTK_RELIEF_NONE, NULL);
	g_object_set(search_button, "relief", GTK_RELIEF_NONE, NULL);
	
	
	gtk_widget_set_size_request(forward, 20,20);
	gtk_widget_set_size_request(back, 20,20);
	gtk_widget_set_size_request(search_button, 40,40);
	gtk_widget_set_size_request(stop, 20,20);
	gtk_widget_set_size_request(home, 20,20);
	gtk_widget_set_size_request(download, 20,20);
	gtk_widget_set_size_request(bookmark, 20,20);
	gtk_widget_set_size_request(menubar, 200,0);
	gtk_widget_set_size_request(url_entry, 800,30);
	gtk_widget_set_size_request(search_entry, 300,30);
	
	
	hboxsk = gtk_hbox_new(FALSE, 0);
	hboxsk1 = gtk_hbox_new(FALSE, 0);
	hboxsk2 = gtk_hbox_new(FALSE, 0);
	hboxsk3 = gtk_hbox_new(FALSE, 0);
	hboxsk4 = gtk_hbox_new(FALSE, 0);
	hboxsk5 = gtk_hbox_new(FALSE, 0);
	hboxsk6 = gtk_hbox_new(FALSE, 0);
	hboxsk7 = gtk_hbox_new(FALSE, 0);
	hboxsk8 = gtk_hbox_new(FALSE, 0);
	hboxsk9 = gtk_hbox_new(FALSE, 0);
	
	image = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk), image);
	gtk_container_add(GTK_CONTAINER(forward), hboxsk);
	gtk_widget_show_all(forward);
	
	
	image = gtk_image_new_from_stock(GTK_STOCK_CLOSE, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk1), image);
	gtk_container_add(GTK_CONTAINER(stop), hboxsk1);
	gtk_widget_show_all(stop);
	
	image = gtk_image_new_from_stock(GTK_STOCK_GO_BACK, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk2), image);
	gtk_container_add(GTK_CONTAINER(back), hboxsk2);
	gtk_widget_show_all(back);
	

	image = gtk_image_new_from_stock(GTK_STOCK_HOME, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk3), image);
	gtk_container_add(GTK_CONTAINER(home), hboxsk3);
	gtk_widget_show_all(home);


	image = gtk_image_new_from_stock(GTK_STOCK_GO_DOWN, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk4), image);
	gtk_container_add(GTK_CONTAINER(download), hboxsk4);
	gtk_widget_show_all(download);
	
	
	image = gtk_image_new_from_stock(GTK_STOCK_ADD, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk5), image);
	gtk_container_add(GTK_CONTAINER(bookmark), hboxsk5);
	gtk_widget_show_all(bookmark);


	image = gtk_image_new_from_stock(GTK_STOCK_CLOSE, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk6), image);
	gtk_container_add(GTK_CONTAINER(close_button), hboxsk6);
	gtk_widget_show_all(close_button);
	
	image = gtk_image_new_from_stock(GTK_STOCK_FIND, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk7), image);
	gtk_container_add(GTK_CONTAINER(go_button), hboxsk7);
	gtk_widget_show_all(go_button);
	
	image = gtk_image_new_from_stock(GTK_STOCK_FIND, GTK_ICON_SIZE_BUTTON);
	gtk_box_pack_start_defaults(GTK_BOX(hboxsk9), image);
	gtk_container_add(GTK_CONTAINER(search_button), hboxsk9);
	gtk_widget_show_all(search_button);



    /*code for tab
     * please try to remeber*/

     hbox1 = gtk_hbox_new(TRUE, 0);
     hbox2 = gtk_hbox_new(TRUE, 2);
     hbox3 = gtk_hbox_new(TRUE, 2);
     hbox = gtk_hbox_new(FALSE, 0);
     hboxs = gtk_hbox_new(FALSE, 0);
     hbox_web= gtk_hbox_new(FALSE, FALSE);
     vbox = gtk_vbox_new(FALSE, 2);
     vbox_web = gtk_vbox_new(0, 0);
	 
	 web = webkit_web_view_new();
	 gtk_box_pack_start(GTK_BOX(hbox_web),web,0,0,0);
 	 //gtk_container_add(GTK_CONTAINER(hbox_web), web);
 
	 
     gtk_widget_set_size_request(go_button, 40,10);
     gtk_widget_set_size_request(hbox2, 10,20);
     
     label1 = gtk_label_new("new tab");
     label2= gtk_label_new(" \n\n\n\n\n\n");
     label3= gtk_label_new("    ");
     label4= gtk_label_new(" ");
     label5= gtk_label_new(" ");
     label6= gtk_label_new(" ");
     label7= gtk_label_new(" \t\t\t\t");
     label8= gtk_label_new(" ");
     label9= gtk_label_new(" \t\tSearch");
     label10= gtk_label_new(" ");
     label11= gtk_label_new(" ");
     label12= gtk_label_new("\t\t\t\t");

	
	
	
	
     gtk_box_pack_start(GTK_BOX(hbox1), close_button, TRUE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(hbox1), label1, FALSE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), back, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), stop, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), forward, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), url_entry, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), go_button, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), label3, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), home, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), bookmark, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), download, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox), label7, TRUE, TRUE, 5);
     

     gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, FALSE, 0);
     //gtk_container_add(GTK_CONTAINER(vbox), hbox_web);     
     gtk_box_pack_start(GTK_BOX(vbox_web), logo, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), label9, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), search_entry, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), search_button, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hboxs), label10, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), hboxs, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label2, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label4, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label5, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox_web), label6, TRUE, TRUE, 0);
     
     gtk_box_pack_start(GTK_BOX(hbox_web), vbox_web, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(hbox_web), lable13, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox), hbox_web, TRUE, TRUE, 0); 
     //gtk_box_pack_start(GTK_BOX(window), vbox, TRUE, TRUE, 0);
     
     /*gtk_box_pack_start(GTK_BOX(hbox_web),vbox_web,FALSE,TRUE,0);
     //gtk_box_pack_start(GTK_BOX(hbox_web), lable13,0,0,0);
     gtk_box_pack_start(GTK_BOX(vbox), hbox_web, TRUE, TRUE, 0);*/

	page++;

	gtk_notebook_insert_page(GTK_NOTEBOOK(notebook1), vbox, hbox1, page);
	gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1), page);
		
	g_signal_connect(GTK_OBJECT(window), "destroy",GTK_SIGNAL_FUNC(destroy),NULL);
    g_signal_connect(GTK_OBJECT(close_button), "clicked", GTK_SIGNAL_FUNC(close_tab), (gpointer) notebook);
    g_signal_connect(GTK_OBJECT(go_button), "clicked", GTK_SIGNAL_FUNC(button_clicked), "go");
    g_signal_connect(GTK_OBJECT(search_button), "clicked", GTK_SIGNAL_FUNC(button_clicked), "search");
    g_signal_connect(GTK_OBJECT(stop), "clicked", GTK_SIGNAL_FUNC(button_clicked), "stop");
    g_signal_connect(GTK_OBJECT(forward), "clicked", GTK_SIGNAL_FUNC(button_clicked), "forward");
    g_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(button_clicked), "back");
    g_signal_connect(GTK_OBJECT(home), "clicked", GTK_SIGNAL_FUNC(button_clicked), "home");
    g_signal_connect(GTK_OBJECT(download), "clicked", GTK_SIGNAL_FUNC(button_clicked), "download");
    g_signal_connect(GTK_OBJECT(bookmark), "clicked", GTK_SIGNAL_FUNC(button_clicked), "bookmark");
    g_signal_connect(url_entry, "activate",  G_CALLBACK(activate), web);
	g_signal_connect(web,"load-progress-changed",G_CALLBACK(progress),url_entry);
	g_signal_connect(web,"load-finished",G_CALLBACK(finished),url_entry);
    gtk_container_add(GTK_CONTAINER(window), vbox1);
    
    gtk_widget_grab_focus (web);
    gtk_widget_show_all(hboxsk);
    gtk_widget_show_all(hboxsk1);
    gtk_widget_show_all(hboxsk2);
    gtk_widget_show_all(hboxsk3);
    gtk_widget_show_all(hboxsk4);
    gtk_widget_show_all(hboxsk5);
    gtk_widget_show_all(hboxsk6);
    gtk_widget_show_all(vbox1);
    gtk_widget_show_all(vbox);
    gtk_widget_show_all(hbox);
    gtk_widget_show_all(hbox1);
    gtk_widget_show_all(hbox2);
    gtk_widget_show_all(hbox3);
    gtk_widget_show_all(hbox_web);
    gtk_widget_show_all(vbox_web);
    gtk_widget_show_all(window);
}

void close_tab(GtkWidget *button, GtkNotebook *notebook){
	gint page_num = gtk_notebook_get_current_page(notebook);
	gtk_notebook_remove_page(notebook, page_num);
	gtk_notebook_set_current_page(notebook, (page_num));
}


void button_clicked(GtkWidget *button, gpointer data)
{
	char *test = (char *) data;
	const char *url_fxn;
	//comparing the data and implementing each require button function
	
	if((strcmp(test,"back"))==0){
		webkit_web_view_go_back(WEBKIT_WEB_VIEW(web));
	}
		
	else if((strcmp(test,"forward"))==0){
		webkit_web_view_go_forward(WEBKIT_WEB_VIEW(web));
	}
		
	else if((strcmp(test,"stop"))==0){
		webkit_web_view_stop_loading(WEBKIT_WEB_VIEW(web));
	}
		
	else if((strcmp(test,"go"))==0){
		hbox_web= gtk_hbox_new(1, 0);
		gtk_box_pack_start(GTK_BOX(hbox_web),web,0,0,0);
		gtk_box_pack_start(GTK_BOX(vbox),hbox_web,0,0,0);
		gtk_widget_hide(vbox_web);
		url_fxn = gtk_entry_get_text(GTK_ENTRY(url_entry));
		gtk_entry_progress_pulse(GTK_ENTRY(url_entry));
		webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),url_fxn);
	}
	
	
}

void activate(GtkWidget* widget, gpointer* wid)
{
	const char *uri;
	GtkWidget* web = GTK_WIDGET(wid);
	uri = gtk_entry_get_text(GTK_ENTRY(widget));
	gtk_entry_progress_pulse(GTK_ENTRY(widget));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),uri);
 
}
void progress (WebKitWebView *web, gint progress,gpointer* data)
{
	GtkWidget* wid = GTK_WIDGET(data);
	gtk_entry_set_progress_fraction (GTK_ENTRY(wid),progress);
}
 
void finished (WebKitWebView  *web_view, WebKitWebFrame *frame,gpointer*  data)

{
	GtkWidget* wid = GTK_WIDGET(data);
	gtk_entry_set_progress_fraction (GTK_ENTRY(wid),0.0);
}
