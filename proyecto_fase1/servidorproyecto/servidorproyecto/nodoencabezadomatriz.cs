using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{
    public class nodoencabezadomatriz
    {

        private int id;
        private nodoencabezadomatriz siguiente;
        private nodoencabezadomatriz anterior;
        private nodomatriz acceso;

        public nodoencabezadomatriz(int aydi)
        {
            Id = aydi;
            Siguiente = null;
            Anterior = null;

        }

        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        public nodoencabezadomatriz Siguiente
        {
            get { return siguiente; }
            set { siguiente = value; }
        }

        public nodoencabezadomatriz Anterior
        {
            get { return anterior; }
            set { anterior = value; }
        }

        public nodomatriz Acceso
        {
            get { return acceso; }
            set { acceso = value; }
        }
    }

}