using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{
    public class nodotopdestruido
    {

        private string nickname;
        private int uniperdidas;
        private nodotopdestruido siguiente;
        private nodotopdestruido anterior;

        public nodotopdestruido(string nicknamee, int destruido)
        {
            Nickname = nicknamee;
            UniPerdidas = destruido;
            Siguiente = null;
            Anterior = null;

        }

        public string Nickname
        {
            get { return nickname; }
            set { nickname = value; }

        }

        public int UniPerdidas
        {
            get { return uniperdidas; }
            set { uniperdidas = value; }

        }

        public nodotopdestruido Siguiente
        {
            get { return siguiente; }
            set { siguiente = value; }

        }
        public nodotopdestruido Anterior
        {
            get { return anterior; }
            set { anterior = value; }

        }
    }
}