using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{
    public class nodotop
    {

        private string nickname;
        private int juegosganados;
        private nodotop siguiente;
        private nodotop anterior;

        public nodotop(string nicknamee, int juegosg)
        {
            Nickname = nicknamee;
            JuegosGanados = juegosg;
            Siguiente = null;
            Anterior = null;

        }

        public string Nickname
        {
            get { return nickname; }
            set { nickname = value; }

        }

        public int JuegosGanados
        {
            get { return juegosganados; }
            set { juegosganados = value; }

        }

        public nodotop Siguiente
        {
            get { return siguiente; }
            set { siguiente = value; }

        }
        public nodotop Anterior
        {
            get { return anterior; }
            set { anterior = value; }

        }
    }
}