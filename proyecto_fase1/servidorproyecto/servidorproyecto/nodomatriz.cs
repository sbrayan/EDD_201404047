using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{
    public class nodomatriz
    {

        private int posx;
        private int posy;
        private int val;
        private int nivel;
        private nodomatriz siguiente;
        private nodomatriz anterior;
        private nodomatriz arriba;
        private nodomatriz abajo;
        private nodomatriz profArriba;
        private nodomatriz profAbajo;
        
       

       public nodomatriz(int fila, int columna,int valor,int level)
        {
            Posx = columna;
            Posy = fila;
            Valor = valor;
            Nivel = level;
            Siguiente = null;
            Anterior = null;
            Arriba = null;
            Abajo = null;
            ProfArriba = null;
            ProfAbajo = null;           

        } 

        public int Posx
        {
            get { return posx; }
            set { posx = value;  }
        }

        public int Nivel
        {
            get { return nivel; }
            set { nivel = value; }
        }


        public int Posy
        {
            get { return posy; }
            set { posy = value;}
        }

        public nodomatriz Siguiente
        {
            get { return siguiente; }
            set { siguiente = value; }            
            
        }

        public nodomatriz Anterior
        {
            get { return anterior; }
            set { anterior = value; }
        }

        public nodomatriz Arriba
        {
            get { return arriba; }
            set { arriba = value; }
        }

        public nodomatriz Abajo
        {
            get { return abajo; }
            set { abajo = value; }
        }

        public int Valor
        {
            get { return val; }
            set { val = value; }
        }

        public nodomatriz ProfArriba
        {
            get { return profArriba; }
            set { profArriba = value; }
        }

        public nodomatriz ProfAbajo
        {
            get { return profAbajo; }
            set { profAbajo = value; }
        }


    }
}