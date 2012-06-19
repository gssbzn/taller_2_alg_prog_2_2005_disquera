
/******************************************************************************/
int compararcadenas(char *cad1, char *cad2){
    /*compara cadenas caracter a caracter con tolower*/   
    int i;   
    int resultado;   
    resultado=0;   
    
    if (strlen(cad1)!=strlen(cad2)) resultado=-1;   
    
    for (i=0;(unsigned)i<(unsigned)strlen(cad1) && resultado==0;i++) {      
        if (tolower(cad1[i])!=tolower(cad2[i])) resultado=-1;   
    }   
    return resultado;/*devuelve 0 si son iguales, -1 si son distintos*/
}

/*************************OPERACIONES CON CANTANTES****************************/

void llenar_cantantes(ifstream *puntero, int N, ptr_nodo_cantante cant_act){
     int i;
     ptr_nodo_cantante cant_ant;
     
     for(i=1;i<N;i++){
		    cant_ant=cant_act;
            cant_act=new(nodo_cantante);
            puntero->getline(cant_act->info.nombre, LONG, '\n');
            puntero->getline(cant_act->info.nacionalidad, LONG, '\n');
		    cant_act->primer_cd=NULL;
		    cant_act->primera_cancion=NULL;
		    cant_ant->prox=cant_act;
		                   
	    }     
}

void mostrar_cantantes(disqueras L){
     ptr_nodo_cantante cant_act;
     cant_act=L.cantantes;
     while (cant_act!=NULL){
           puts(cant_act->info.nombre);
           puts(cant_act->info.nacionalidad);
           cant_act=cant_act->prox;
     }
}

ptr_nodo_cantante buscar_cantante(disqueras L, char *cantante){
    ptr_nodo_cantante act;
    act=L.cantantes;
    while (act!=NULL){
              if(compararcadenas(act->info.nombre,cantante)==0){
                  return(act);
              }              
              act=act->prox;
        }
        return(act);
}

/*****************************OPERACIONES CON CDS******************************/

void llenar_cds(ifstream *puntero, int M, ptr_nodo_cd cd_act){
     int i;
     char linea[LONG];
     ptr_nodo_cd cd_ant;
     
     for(i=1;i<M;i++){
            cd_ant=cd_act;
            cd_act=new(nodo_cd);
		    puntero->getline(cd_act->info.titulo, LONG, '\n');
            puntero->getline(cd_act->info.codigo, LONG, '\n');
            puntero->getline(cd_act->info.disquera, LONG, '\n');       	
       	    puntero->getline(linea, LONG, '\n');
            cd_act->info.ano=atoi(linea);
            cd_act->primer_cantante=NULL;
            cd_act->primera_cancion=NULL;
            cd_ant->prox=cd_act;
                                            
        }
}

void mostrar_cds(disqueras L){
     ptr_nodo_cd cd_act;
     cd_act=L.cds;
     while (cd_act!=NULL){
           puts(cd_act->info.titulo);
           puts(cd_act->info.codigo);
           puts(cd_act->info.disquera);
           printf("%d\n",cd_act->info.ano);
           cd_act=cd_act->prox;
     }
}

ptr_nodo_cd buscar_cd(disqueras L, char *cd){
    ptr_nodo_cd act;
    act=L.cds;
    while (act!=NULL){
              if(compararcadenas(act->info.titulo,cd)==0){
                  return(act);
              }              
              act=act->prox;
        }
        return(act);
}

/*************************OPERACIONES CON CANCIONES****************************/     

void llenar_canciones(ifstream *puntero, int W, ptr_nodo_cancion canc_act){
     int i;
     char linea[LONG];
     ptr_nodo_cancion canc_ant;
     for(i=1;i<W;i++){
         canc_ant=canc_act;
         canc_act=new(nodo_cancion);
		 puntero->getline(canc_act->info.titulo, LONG, '\n');
         puntero->getline(linea, LONG, '\n');
         canc_act->info.duracion=atoi(linea);
         canc_act->primer_cantante=NULL;
         canc_act->primer_cd=NULL;
         canc_ant->prox=canc_act;                                             
     }
}

void mostrar_canciones(disqueras L){
     ptr_nodo_cancion canc_act;
     canc_act=L.canciones;
     while (canc_act!=NULL){
           puts(canc_act->info.titulo);
           printf("%d\n",canc_act->info.duracion);
           canc_act=canc_act->prox;
     }
}

ptr_nodo_cancion buscar_cancion(disqueras L, char *cancion){
    ptr_nodo_cancion act;
    act=L.canciones;
    while (act!=NULL){
              if(compararcadenas(act->info.titulo,cancion)==0){
                  return(act);
              }              
              act=act->prox;
        }
        return(act);
}

/******************************************************************************/

void llenar_col1(ifstream *puntero, disqueras L, int P, ptr_nodo_cantante_cd col_act, ptr_nodo_cantante cant_act){
     int i;
     char linea[LONG];
     ptr_nodo_cd cd_act;
     ptr_nodo_cantante_cd col_ant;
     
     for(i=1;i<P;i++){
            col_ant=col_act;
            col_act=new(nodo_cantante_cd);
            col_act->sig_col=NULL;
            puntero->getline(linea, LONG, '\n');
            cd_act=buscar_cd(L, linea);
            if(cd_act!=NULL){
                col_act->cd=cd_act;
                col_act->cantante=cant_act;
            }
            if(cd_act->primer_cantante==NULL)cd_act->primer_cantante=col_act;
            col_ant->sig_col=col_act;      
                                                         
     }
}

void llenar_fil1(ifstream *puntero, disqueras L, int X, ptr_nodo_cantante_cd fil_act){
     int P, i;
     char linea[LONG];
     ptr_nodo_cd cd_act;
     ptr_nodo_cantante cant_act;
     ptr_nodo_cantante_cd fil_ant, col_act, col_ant;
     
     for(i=1;i<X;i++){
            fil_ant=fil_act;
            col_act=new(nodo_cantante_cd);
            fil_act=col_act;
            fil_ant->sig_fil=fil_act;
            fil_act->sig_fil=NULL;
            col_ant=fil_ant;
            puntero->getline(linea, LONG, '\n');
            cant_act=buscar_cantante(L, linea);
            if(cant_act!=NULL){
                puntero->getline(linea, LONG, '\n');
                P=atoi(linea);
                puntero->getline(linea, LONG, '\n');
            
                cd_act=buscar_cd(L, linea);
                if(cant_act->primer_cd==NULL) cant_act->primer_cd=fil_act;
                if(cd_act->primer_cantante==NULL)cd_act->primer_cantante=fil_act;
            }
            fil_act->cantante=cant_act;
            fil_act->cd=cd_act;
            col_act->cantante=cant_act;
            col_act->cd=cd_act;
            llenar_col1(puntero, L, P, col_act, cant_act);
            
        }
}

void mostrar_cantante_cd(ptr_nodo_cantante_cd L){
     ptr_nodo_cantante_cd fil_act, col_act;
     fil_act=L;
        
     while(fil_act!=NULL){
         col_act=fil_act;
         puts(fil_act->cantante->info.nombre);
         while(col_act!=NULL){
             puts(col_act->cd->info.titulo);
             col_act=col_act->sig_col;
         }
         fil_act=fil_act->sig_fil;
     }
}

/******************************************************************************/

void llenar_col2(ifstream *puntero, disqueras L, int Q, ptr_nodo_cantante_cancion col_act, ptr_nodo_cancion canc_act){
     int j;
     char linea[LONG];
     ptr_nodo_cantante cant_act;
     ptr_nodo_cantante_cancion col_ant;
     
     for(j=1;j<Q;j++){
            col_ant=col_act;
            col_act=new(nodo_cantante_cancion);
            col_act->sig_col=NULL;
            puntero->getline(linea, LONG, '\n');
            cant_act=buscar_cantante(L, linea);
            if(cant_act!=NULL){
                col_act->cancion=canc_act;
            	col_act->cantante=cant_act;
            	if(canc_act->primer_cantante==NULL) canc_act->primer_cantante=col_act;
                if(cant_act->primera_cancion==NULL) cant_act->primera_cancion=col_act;
            }
                        
            col_ant->sig_col=col_act;      
            
        }
}

void llenar_fil2(ifstream *puntero, disqueras L, int Y, ptr_nodo_cantante_cancion fil_act){
     int Q, i;
     char linea[LONG];
     ptr_nodo_cancion canc_act;
     ptr_nodo_cantante cant_act;
     ptr_nodo_cantante_cancion fil_ant, col_act, col_ant;
     
     for(i=1;i<Y;i++){
            fil_ant=fil_act;
            col_act=new(nodo_cantante_cancion);
            fil_act=col_act;
            fil_ant->sig_fil=fil_act;
            fil_act->sig_fil=NULL;
            col_ant=fil_ant;
            puntero->getline(linea, LONG, '\n');
            canc_act=buscar_cancion(L, linea);
           
            puntero->getline(linea, LONG, '\n');
            Q=atoi(linea);
            puntero->getline(linea, LONG, '\n');
            
            cant_act=buscar_cantante(L, linea);
            fil_act->cantante=cant_act;
            fil_act->cancion=canc_act;
            col_act->cantante=cant_act;
            col_act->cancion=canc_act;
            col_act->sig_col=NULL;
            if(canc_act->primer_cantante==NULL) canc_act->primer_cantante=fil_act;
            if(cant_act->primera_cancion==NULL) cant_act->primera_cancion=fil_act;
            llenar_col2(puntero, L, Q, col_act, canc_act);
            
     }
}

void mostrar_cantante_cancion(ptr_nodo_cantante_cancion L){
     ptr_nodo_cantante_cancion fil_act, col_act;
     
     fil_act=L;
        
     while(fil_act!=NULL){
         col_act=fil_act;
         puts(fil_act->cancion->info.titulo);
         while(col_act!=NULL){
             puts(col_act->cantante->info.nombre);
             col_act=col_act->sig_col;
         }
         fil_act=fil_act->sig_fil;
     }
}

/******************************************************************************/
void llenar_col3(ifstream *puntero, disqueras L, int R, ptr_nodo_cancion_cd col_act, ptr_nodo_cd cd_act){
     int j;
     char linea[LONG];
     ptr_nodo_cancion canc_act;
     ptr_nodo_cancion_cd col_ant;
     
      for(j=1;j<R;j++){
            col_ant=col_act;
            col_act=new(nodo_cancion_cd);
            col_act->sig_col=NULL;
            puntero->getline(linea, LONG, '\n');
            canc_act=buscar_cancion(L, linea);
            if(canc_act!=NULL){
                col_act->cd=cd_act;
                col_act->cancion=canc_act;
            }
            if(cd_act->primera_cancion==NULL) cd_act->primera_cancion=col_act;
            if(canc_act->primer_cd==NULL) canc_act->primer_cd=col_act;
            col_ant->sig_col=col_act;      

        }
}

void llenar_fil3(ifstream *puntero, disqueras L, int Z, ptr_nodo_cancion_cd fil_act){
     int R, i;
     char linea[LONG];
     ptr_nodo_cancion canc_act;
     ptr_nodo_cd cd_act;
     ptr_nodo_cancion_cd fil_ant, col_act, col_ant;
     
     for(i=1;i<Z;i++){
            fil_ant=fil_act;
            col_act=new(nodo_cancion_cd);
            fil_act=col_act;
            fil_ant->sig_fil=fil_act;
            fil_act->sig_fil=NULL;
            col_ant=fil_ant;
            puntero->getline(linea, LONG, '\n');
            cd_act=buscar_cd(L, linea);
           
            puntero->getline(linea, LONG, '\n');
            R=atoi(linea);
            puntero->getline(linea, LONG, '\n');
            canc_act=buscar_cancion(L, linea);
            fil_act->cancion=canc_act;
            fil_act->cd=cd_act;
            col_act->cancion=canc_act;
            col_act->cd=cd_act;
            col_act->sig_col=NULL;
            if(cd_act->primera_cancion==NULL) cd_act->primera_cancion=fil_act;
            if(canc_act->primer_cd==NULL) canc_act->primer_cd=fil_act;
            llenar_col3(puntero, L, R, col_act, cd_act);
            
        }
}

void mostrar_cancion_cd(ptr_nodo_cancion_cd L){
     ptr_nodo_cancion_cd fil_act, col_act;
     
     fil_act=L;
        
     while(fil_act!=NULL){
         col_act=fil_act;
         puts(fil_act->cd->info.titulo);
         while(col_act!=NULL){
             puts(col_act->cancion->info.titulo);
             col_act=col_act->sig_col;
         }
         fil_act=fil_act->sig_fil;
     }
}
