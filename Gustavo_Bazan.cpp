/*
  Gustavo Bazan
  C.I.:17.777.408
  seccion 22
*/

#include "Gustavo_Bazan_lib.h"
#include "Gustavo_Bazan_imp.cpp"
//#include <conio.h>

// Cuerpo del programa  
int main(){
	ifstream puntero;
    ofstream salida;
    char opc, aux[LONG], linea[LONG];
    int i, j, N, M, W, X, P, Y, Q, Z, R, A, B, C;
	disqueras L;
	//cantante
	ptr_nodo_cantante cant_act, cant_ant;
	//cd
	ptr_nodo_cd cd_act, cd_ant;
	//cancion
	ptr_nodo_cancion canc_act, canc_ant;
	//cantante cd
	ptr_nodo_cantante_cd  fil_ant1, fil_act1, col_ant1, col_act1, L1;
	//cantante_cancion
	ptr_nodo_cantante_cancion fil_ant2, fil_act2, col_ant2, col_act2, L2;
	//cancion_cd
	ptr_nodo_cancion_cd fil_ant3, fil_act3, col_ant3, col_act3, L3;
	cant_act = NULL;
	cd_act = NULL;
	canc_act = NULL;
	
	strcpy(aux,"disquera.in");
	puntero.open(aux, ios::in);
    
    
	if (puntero==NULL)/*SI NO SE PUEDE ABRIR EL FICHERO*/
		printf("\n\n\n***ERROR*** No se ha podido encontrar el archivo");   
    else {/*SI SE PUEDE ABRIR*/
        //CARGAR CANTANTES
        puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        N=atoi(linea);
               
        cant_act=new(nodo_cantante);
        L.cantantes=cant_act;
        cant_ant=NULL;
        puntero.getline(cant_act->info.nombre, LONG, '\n');
        puntero.getline(cant_act->info.nacionalidad, LONG, '\n');
        llenar_cantantes(&puntero, N, cant_act);
        
	    /*mostrar_cantantes(L);
	    system("pause");
	    system("cls");*/
	    
	    //CARGAR CDS
	    puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        M=atoi(linea);
        
        cd_act=new(nodo_cd);
        L.cds=cd_act;
        cd_ant=NULL;
        puntero.getline(cd_act->info.titulo, LONG, '\n');
        puntero.getline(cd_act->info.codigo, LONG, '\n');
        puntero.getline(cd_act->info.disquera, LONG, '\n');       	
       	puntero.getline(linea, LONG, '\n');
        cd_act->info.ano=atoi(linea);
        llenar_cds(&puntero, M, cd_act);
        
        /*mostrar_cds(L);
        system("pause");
        system("cls");*/
        
        //CARGAR CANCIONES
        puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        W=atoi(linea);
        
        canc_act=new(nodo_cancion);
        L.canciones=canc_act;
        canc_ant=NULL;
        puntero.getline(canc_act->info.titulo, LONG, '\n');
        puntero.getline(linea, LONG, '\n');
        canc_act->info.duracion=atoi(linea);
        llenar_canciones(&puntero, W, canc_act);
        
        /*mostrar_canciones(L);
        system("pause");
        system("cls");*/
        
         //CARGAR CD-CANTANE
        puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        X=atoi(linea);
        
        col_act1=new(nodo_cantante_cd);
        fil_act1=col_act1;
        fil_ant1=NULL;
        col_ant1=fil_ant1;
        L1=fil_act1;
        puntero.getline(linea, LONG, '\n');
        cant_act=buscar_cantante(L, linea);
        if(cant_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        puntero.getline(linea, LONG, '\n');
        P=atoi(linea);
        puntero.getline(linea, LONG, '\n');
            
        cd_act=buscar_cd(L, linea);
        if(cd_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        if(cant_act->primer_cd==NULL) cant_act->primer_cd=fil_act1;
        if(cd_act->primer_cantante==NULL)cd_act->primer_cantante=fil_act1;
        
        col_act1->cantante=cant_act;
        col_act1->cd=cd_act;
        llenar_col1(&puntero, L, P, col_act1, cant_act);
       
        llenar_fil1(&puntero, L, X, fil_act1);
        
        /*mostrar_cantante_cd(L1);
        system("pause");
        system("cls");*/
         
        //CARGAR CANCION-CANTANE
        puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        Y=atoi(linea);
        
        col_act2=new(nodo_cantante_cancion);
        fil_act2=col_act2;
        fil_ant2=NULL;
        col_ant2=fil_ant2;
        L2=fil_act2;
        puntero.getline(linea, LONG, '\n');
        canc_act=buscar_cancion(L, linea);
        if(canc_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        puntero.getline(linea, LONG, '\n');
        Q=atoi(linea);
        puntero.getline(linea, LONG, '\n');
        cant_act=buscar_cantante(L, linea);
        if(cant_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        fil_act2->cancion=canc_act;
        col_act2->cantante=cant_act;
        col_act2->sig_col=NULL;
        if(canc_act->primer_cantante==NULL) canc_act->primer_cantante=fil_act2;
        if(cant_act->primera_cancion==NULL) cant_act->primera_cancion=fil_act2;
        llenar_col2(&puntero, L, Q, col_act2, canc_act);
        
        llenar_fil2(&puntero, L, Y, fil_act2);
        
        /*mostrar_cantante_cancion(L2);        
        system("pause");
        system("cls");*/
        
        //CARGAR CANCION-CD
        puntero.getline(linea, LONG, '\n');
		puntero.getline(linea, LONG, '\n');
        Z=atoi(linea); 
        
        col_act3=new(nodo_cancion_cd);
        fil_act3=col_act3;
        fil_ant3=NULL;
        col_ant3=fil_ant3;
        L3=fil_act3;
        puntero.getline(linea, LONG, '\n');
        cd_act=buscar_cd(L, linea);
        if(cd_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        puntero.getline(linea, LONG, '\n');
        R=atoi(linea);
        puntero.getline(linea, LONG, '\n');
        canc_act=buscar_cancion(L, linea);
        if(canc_act==NULL) {printf("Error de lectura"); puntero.close(); exit(1);}
        fil_act3->cd=cd_act;
        col_act3->cancion=canc_act;
        col_act3->sig_col=NULL;
        if(cd_act->primera_cancion==NULL) cd_act->primera_cancion=fil_act3;
        if(canc_act->primer_cd==NULL) canc_act->primer_cd=fil_act3;
                       
        llenar_col3(&puntero, L, R, col_act3, cd_act);
        llenar_fil3(&puntero, L, Y, fil_act3);
        
        
        //mostrar_cancion_cd(L3);
              
        //CONSULTAS Y SALIDAS
        //puntero.getline(linea, LONG, '\n');
        strcpy(aux,"disquera.out");
        salida.open(aux, ios::out);
        canc_act=NULL;
        puntero.getline(linea, LONG, '\n');
        puntero.getline(linea, LONG, '\n');
        A=atoi(linea);
        salida << "Consulta de Cantantes" << endl;
        
        for(i=0;i<A;i++){
            
            puntero.getline(linea, LONG, '\n');
            cant_act=buscar_cantante(L, linea);
            if(cant_act==NULL) {printf("Error de lectura");; puntero.close(); salida.close(); exit(1);}
            salida << "Cantante #" <<i+1 << ": "<< linea << endl;
            fil_act2=L2;
            salida << endl;
            salida << "Canciones" << endl;
            while(fil_act2!=NULL){
                col_act2=fil_act2;
                while(col_act2!=NULL){
                    if(compararcadenas(col_act2->cantante->info.nombre,linea)==0){
                        salida << col_act2->cancion->info.titulo << endl;
						
                    }
                    col_act2=col_act2->sig_col;
                }
                fil_act2=fil_act2->sig_fil;
            }
            fil_act1=L1;
            salida << endl;
            salida << "CD\'s" << endl;
            while(fil_act1!=NULL){
                col_act1=fil_act1;
                while(col_act1!=NULL){
                    if(compararcadenas(col_act1->cantante->info.nombre,linea)==0){
                        salida << col_act1->cd->info.titulo << endl;
						
                    }
                    col_act1=col_act1->sig_col;
                }
                fil_act1=fil_act1->sig_fil;
            }
            salida << endl;           
        }
        
        puntero.getline(linea, LONG, '\n');
        puntero.getline(linea, LONG, '\n');
        B=atoi(linea);
        salida << endl;
        salida << "Consulta de CD\'s" << endl;        
        
        for(i=0;i<B;i++){
            puntero.getline(linea, LONG, '\n');
            salida << "CD #" << i+1 << ": "<< linea << endl;
            cd_act=buscar_cd(L, linea);
            if(cd_act==NULL) {printf("Error de lectura");; puntero.close(); salida.close(); exit(1);}
            salida << "Cantantes" << endl;
            fil_act1=L1;
            while(fil_act1!=NULL){
                col_act1=fil_act1;
                while(col_act1!=NULL){
                    if(compararcadenas(col_act1->cd->info.titulo,linea)==0){
                        salida << col_act1->cantante->info.nombre<< endl;                                                                                  
                    }
                    col_act1=col_act1->sig_col;
                }
                fil_act1=fil_act1->sig_fil;
            }
            
            fil_act3=L3;
            salida << endl;
            salida << "Canciones" << endl;
            while(fil_act3!=NULL){
                col_act3=fil_act3;
                while(col_act3!=NULL){
                    if(compararcadenas(col_act3->cd->info.titulo,linea)==0){
                        salida << col_act3->cancion->info.titulo << endl;                                                                                 
                    }
                    col_act3=col_act3->sig_col;
                }
                fil_act3=fil_act3->sig_fil;
            }
            salida << endl;             
        }
	    
	    puntero.getline(linea, LONG, '\n');
        puntero.getline(linea, LONG, '\n');
        C=atoi(linea);
        salida << "Consulta de Canciones" << endl;        
        
        for(i=0;i<C;i++){
            puntero.getline(linea, LONG, '\n');
            salida << "Cancion #" << i+1 << ": "<< linea << endl;
            canc_act=buscar_cancion(L, linea);
            if(canc_act==NULL) {printf("Error de lectura");; puntero.close(); salida.close(); exit(1);}
            salida << endl;
            salida << "Cantantes" << endl;
            fil_act2=L2;
            while(fil_act2!=NULL){
                col_act2=fil_act2;
                while(col_act2!=NULL){
                    if(compararcadenas(col_act2->cancion->info.titulo,linea)==0){
                        salida << col_act2->cantante->info.nombre<< endl;                                                                                 
                    }
                    col_act2=col_act2->sig_col;
                }
                fil_act2=fil_act2->sig_fil;
            }
                        
            fil_act3=L3;
            salida << endl;
            salida << "CD\'s" << endl;
            while(fil_act3!=NULL){
                col_act3=fil_act3;
                while(col_act3!=NULL){
                    if(compararcadenas(col_act3->cancion->info.titulo,linea)==0){
                        salida << col_act3->cd->info.titulo << endl;                                      
                    }
                    col_act3=col_act3->sig_col;
                }
                fil_act3=fil_act3->sig_fil;
            }            
            salida << endl;             
        }
        
        puntero.close();
        salida.close();
    }
    //getch();
    return(0);
}
