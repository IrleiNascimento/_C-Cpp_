/*
 * File:   main->c
 * Author: Irlei
 *
 * Created on 7 de Junho de 2013, 00:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>

#define SOMAR 1
#define  DIV 2
#define MULT 3
#define SUB 4
#define MOD 5
#define EXP 6



#define BUILDER_XML_FILE "calcWin.xml" // definido uma macro para o xml a ser carregado

typedef struct {
    int tipo_opr; //tipo da operação do momento
    double calculo; //declaração do tipo double para todos o valores digitados as conversões serõa feitas nas funções de resultado
    double v_parcial;
    char valor_final[256]; // apresentará o resultado no painel
    gboolean *virgula;
    gboolean *igual;
} OPERACAO;// guarda os valores temporario do calculo
typedef struct {
    GtkWidget *janela;
    GtkWidget *painel_resultado;
    GtkWidget *button_ce;
    GtkWidget *button_mod;
    GtkWidget *button_exp;
    GtkWidget *button_9;
    GtkWidget *button_8;
    GtkWidget *button_7;
    GtkWidget *button_6;
    GtkWidget *button_5;       // variáveis que representará cada objeto contido na interface( arquivo xml)
    GtkWidget *button_4;
    GtkWidget *button_3;
    GtkWidget *button_2;
    GtkWidget *button_1;
    GtkWidget *button_0;
    GtkWidget *button_div;
    GtkWidget *button_mult;
    GtkWidget *button_soma;
    GtkWidget *button_sub;
    GtkWidget *button_igual;
    GtkWidget *button_vigula;
    GtkWidget *fixed1;
    GtkWidget *painel_parcial;
    OPERACAO operacao;  //durante todo o prcesso a calculadora carregará um base de dados de suas operações
} Calc_win;

void init_Calc(Calc_win *calc,GtkBuilder *builder);//inicia a interface grafica da calculadora
void init_Operacao(OPERACAO *opr);//inica a struct que guarda a operaçoes temporaria dos calculos
void limpar(GtkButton *button,Calc_win *calc);// função que será utiizada pelo botão CE
void inserir( GtkButton *button,Calc_win *calc);// funcão que será chamada para cada digito pressionado
void soma( GtkButton *button,Calc_win *calc);// função do  botão soma
void dividir(GtkButton *button,Calc_win *calc);// função do  botão divisão
void multiplicar(GtkButton *button,Calc_win *calc);// função do  botão multiplicação
void expoente(GtkButton *button,Calc_win *calc);// função do  botão expoente
void oprMod(GtkButton *button,Calc_win *calc);// função do  botão mod(resto da divisao)
void subtrair(GtkButton *button,Calc_win *calc);// função do  botão subtração
void resultado(GtkButton *button,Calc_win *calc);// função do  botão igual
void virgulaPress(GtkButton *button,Calc_win *calc);// função que registra se o botão virgula foi pressionado
void mudarSinal(Calc_win *calc,int opr);// função que modificará o sinal durante um mudanção repentina de operação
void operacaoCalc(GtkButton *button,Calc_win *calc);// função que realizará o calculo parcial das operações
char *formataResultado(double valor); // como todos os valores estão em double e precisarão ser convertidos para string, na maioria dos casos alguns valores precisarão ser omitidos , como zero depois da virgula por exemplo
void formatPainelParcial(Calc_win *calc);// utiliza a função formataResultado() e mostra o valor parcial no painel superir


int main(int argc, char** argv) {
    Calc_win *calc;
    calc= g_slice_new (Calc_win);// aloca memoria para nova istancia da calculadora
    gtk_init (&argc, &argv);
    GtkBuilder              *builder;
    GError                  *err=NULL;
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, BUILDER_XML_FILE, &err)==0) {
        g_error_free (err); // se o arquivo xml apresentar problemas , o pregrama será finalizado
return FALSE;
    }
    init_Calc(calc ,builder); // carrega todas as propriedades da calculadora
    init_Operacao(&calc->operacao);// prepara a estrutura de dados das operações



    gtk_widget_show (calc->janela);
 /* Create a PangoLayout, set the font and text */
    gtk_main ();
    g_slice_free (Calc_win, calc);
    return(EXIT_SUCCESS);
}
void init_Calc(Calc_win *calc,GtkBuilder *builder) {
    // passando os objetos do xml para a struct
    calc->janela = GTK_WIDGET (gtk_builder_get_object(builder,"calcWin"));
    calc->button_0 =GTK_WIDGET (gtk_builder_get_object (builder, "button_0"));
    calc->button_1 =GTK_WIDGET (gtk_builder_get_object (builder, "button_1"));
    calc->button_2 =GTK_WIDGET (gtk_builder_get_object (builder, "button_2"));
    calc->button_3 =GTK_WIDGET (gtk_builder_get_object (builder, "button_3"));
    calc->button_4 =GTK_WIDGET (gtk_builder_get_object (builder, "button_4"));
    calc->button_5 =GTK_WIDGET (gtk_builder_get_object (builder, "button_5"));
    calc->button_6 =GTK_WIDGET (gtk_builder_get_object (builder, "button_6"));
    calc->button_7 =GTK_WIDGET (gtk_builder_get_object (builder, "button_7"));
    calc->button_8 =GTK_WIDGET (gtk_builder_get_object (builder, "button_8"));
    calc->button_9 =GTK_WIDGET (gtk_builder_get_object (builder, "button_9"));
    calc->button_div =GTK_WIDGET (gtk_builder_get_object (builder, "button_div"));
    calc->button_mult =GTK_WIDGET (gtk_builder_get_object (builder, "button_mult"));
    calc->button_sub =GTK_WIDGET (gtk_builder_get_object (builder, "button_sub"));
    calc->button_soma =GTK_WIDGET (gtk_builder_get_object (builder, "button_soma"));
    calc->button_mod =GTK_WIDGET (gtk_builder_get_object (builder, "button_mod"));
    calc->button_exp =GTK_WIDGET (gtk_builder_get_object (builder, "button_exp"));
    calc->button_ce =GTK_WIDGET (gtk_builder_get_object (builder, "button_ce"));
    calc->button_igual =GTK_WIDGET (gtk_builder_get_object (builder, "button_igual"));
    calc->button_vigula = GTK_WIDGET (gtk_builder_get_object (builder, "button_vigula"));
    calc->painel_resultado =GTK_WIDGET (gtk_builder_get_object (builder, "painel_resultado"));
    calc->fixed1 = GTK_WIDGET (gtk_builder_get_object (builder, "fixed1"));
    calc->painel_parcial = GTK_WIDGET (gtk_builder_get_object (builder, "painel_parcial"));
// declarando a tarefa de cada  botão
    g_signal_connect (G_OBJECT (calc->janela), "destroy", G_CALLBACK (gtk_main_quit),(gpointer)calc->janela);
    g_signal_connect (G_OBJECT (calc->button_0), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_1), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_2), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_3), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_4), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_5), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_6), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_7), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_8), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_9), "clicked", G_CALLBACK (inserir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_igual), "clicked", G_CALLBACK (resultado),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_ce), "clicked", G_CALLBACK (limpar),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_soma), "clicked", G_CALLBACK (soma),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_sub), "clicked", G_CALLBACK (subtrair),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_exp), "clicked", G_CALLBACK (expoente),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_div), "clicked", G_CALLBACK (dividir),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_mult), "clicked", G_CALLBACK (multiplicar),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_mod), "clicked", G_CALLBACK (oprMod),(gpointer)calc);
    g_signal_connect (G_OBJECT (calc->button_vigula), "clicked", G_CALLBACK (virgulaPress),(gpointer)calc);


GError *er;
    gtk_window_set_default_icon_from_file ("gnome-calculator.png",er); // icone do programa
    g_object_unref (G_OBJECT (builder));
    gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),"0");// iniciando painel com valor zero
}
void init_Operacao(OPERACAO *opr) {
    opr->tipo_opr=0;
    opr->v_parcial=0;// iniciando a estrutura das operações
    opr->calculo=0;
    opr->virgula= FALSE;
    opr->igual = FALSE;
}
void limpar(GtkButton *button,Calc_win *calc) {
    gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),"0");
    gtk_entry_set_text(GTK_ENTRY(calc->painel_parcial),"");
    calc->operacao.v_parcial=0;
    calc->operacao.calculo=0;
    calc->operacao.virgula= FALSE;
}
void inserir( GtkButton *button,Calc_win *calc) {
    if(calc->operacao.igual){
     gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),"");
     calc->operacao.igual=FALSE;
    }
    if(!g_strcmp0(gtk_button_get_label(button),",")&&
            !g_strcmp0(gtk_entry_get_text(GTK_ENTRY(calc->painel_resultado)),"0")) {
        gtk_entry_append_text(GTK_ENTRY(calc->painel_resultado),gtk_button_get_label(button));
        return TRUE;

    } else if( !g_strcmp0(gtk_entry_get_text(GTK_ENTRY(calc->painel_resultado)),"0")) {
        gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),"");
    }
    gtk_entry_append_text(GTK_ENTRY(calc->painel_resultado),gtk_button_get_label(button));
    calc->operacao.calculo = atof(gtk_entry_get_text(GTK_ENTRY(calc->painel_resultado)));
}
void resultado(GtkButton *button,Calc_win *calc) {
    operacaoCalc(button,calc);
    sprintf(calc->operacao.valor_final,"%s", formataResultado(calc->operacao.calculo)) ;
    gtk_entry_set_text(GTK_ENTRY(calc->painel_parcial),"");
    calc->operacao.v_parcial=0;
    gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),calc->operacao.valor_final);
    calc->operacao.igual = TRUE;
}
void soma( GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,SOMAR);
    operacaoCalc(button,calc);
    return TRUE;
}
void dividir(GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,DIV);
    operacaoCalc(button,calc);
}
void multiplicar(GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,MULT);
    operacaoCalc(button,calc);
}
void expoente(GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,EXP);
    operacaoCalc(button,calc);
}
void oprMod(GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,MOD);
    operacaoCalc(button,calc);
}
void subtrair(GtkButton *button,Calc_win *calc) {
    mudarSinal(calc,SUB);
    operacaoCalc(button,calc);
}
char *formataResultado(double valor) {
    char str[256];
    int i;
    int count=0;
    sprintf(str,"\n%f",valor);
    g_strreverse(str);
    for(i=0; i<strlen(str); i++) {
        if(str[i]=='0') {
            str[i]=' ';    // eliminado os `zeros` desnecessarios
            if(str[i+1]==',')
                str[i+1]=' ';
        } else {
            break;
        }
    }
    g_strreverse(str);
    return  str;
}
void virgulaPress(GtkButton *button,Calc_win *calc) {
    calc->operacao.virgula= TRUE;
    inserir(button,calc);
}
void operacaoCalc(GtkButton *button,Calc_win *calc) {
    gtk_entry_set_text(GTK_ENTRY(calc->painel_resultado),"");
    if(calc->operacao.v_parcial>0) {
        switch(calc->operacao.tipo_opr) {
        case SOMAR:
            if( calc->operacao.calculo ==0) {
                calc->operacao.calculo =(calc->operacao.v_parcial+calc->operacao.v_parcial);
            } else {
                calc->operacao.calculo += calc->operacao.v_parcial;
            }
            break;
        case MULT:
            if( calc->operacao.calculo ==0) {
                calc->operacao.calculo =(calc->operacao.v_parcial*calc->operacao.v_parcial);
            } else {
                calc->operacao.calculo = (calc->operacao.v_parcial*calc->operacao.calculo) ;
            }

            break;
        case DIV:
            if( calc->operacao.calculo ==0) {

                calc->operacao.calculo =(calc->operacao.v_parcial/calc->operacao.v_parcial);
            } else {

                calc->operacao.calculo = (calc->operacao.v_parcial/calc->operacao.calculo) ;
            }
            break;
        case SUB:
            if( calc->operacao.calculo ==0) {
                calc->operacao.calculo =(calc->operacao.v_parcial-calc->operacao.v_parcial);
            } else {
                calc->operacao.calculo = (calc->operacao.v_parcial-calc->operacao.calculo) ;
            }
            break;
        case MOD:
            if( calc->operacao.calculo ==0) {
                calc->operacao.calculo = fmod(calc->operacao.v_parcial,calc->operacao.v_parcial);
            } else {
                calc->operacao.calculo = fmod(calc->operacao.v_parcial,calc->operacao.calculo);
            }

            break;
        case EXP:
            if( calc->operacao.calculo ==0) {
                calc->operacao.calculo = pow(calc->operacao.v_parcial,calc->operacao.v_parcial);
            } else {
                calc->operacao.calculo = pow(calc->operacao.v_parcial,calc->operacao.calculo);
            }

            break;
        default:
            break;
        }
    }

    formatPainelParcial(calc);
    }
void formatPainelParcial(Calc_win *calc) {
    char str[256];
    if(calc->operacao.calculo!=0 ) {
        sprintf(str, "%s",formataResultado(calc->operacao.calculo)) ;
        gtk_entry_set_text(GTK_ENTRY(calc->painel_parcial),"");
        gtk_entry_append_text(GTK_ENTRY(calc->painel_parcial),str);
        mudarSinal(calc,calc->operacao.tipo_opr);
        calc->operacao.v_parcial = calc->operacao.calculo;
    }

}
void mudarSinal(Calc_win *calc,int opr) {
    int len = strlen(gtk_entry_get_text(GTK_ENTRY(calc->painel_parcial)));
    char str[len];
    strcpy(str,gtk_entry_get_text(GTK_ENTRY(calc->painel_parcial)));
    switch(opr) {
    case SOMAR:
        str[len-1]='+';
        calc->operacao.tipo_opr=SOMAR;
        break;
    case MULT:
        str[len-1]='*';
        calc->operacao.tipo_opr=MULT;
        break;
    case DIV:
        str[len-1]='/';
        calc->operacao.tipo_opr=DIV;
        break;
    case SUB:
        str[len-1]='-';
        calc->operacao.tipo_opr=SUB;
        break;
    case MOD:
        str[len-1]='%';
        calc->operacao.tipo_opr=MOD;
        break;
    case EXP:
        str[len-1]='^';
        calc->operacao.tipo_opr=EXP;
        break;
    default:
        break;
    }
    gtk_entry_set_text(GTK_ENTRY(calc->painel_parcial),str);

}


