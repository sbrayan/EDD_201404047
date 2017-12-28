using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{
   

    
    public class nodoarbol
    {
        private string nickname;
        private string contrasenia;
        private string correo;
        private string estado;
        private nodoarbol izq;
        private nodoarbol der;
        private int contador;
        private nododobleenlazada iniciolista;
        public nodoarbol(string nick,string contra,string corre,string stad,int contadoor)
        {
           
            Nickname = nick;
            Contrasenia = contra;
            Correo = corre;
            Estado = stad;
            Izquierda = null;
            Derecha = null;
            InicioLista = null;
            
            Contador = contadoor;

        }

        public nododobleenlazada InicioLista
        {
            get { return iniciolista; }
            set { iniciolista = value; }
        }
        public nodoarbol Izquierda
        {
            get { return izq; }
            set { izq = value; }
        }

        public nodoarbol Derecha
        {
            get { return der; }
            set { der = value; }
        }

        public int Contador
        {
            get { return contador; }
            set { contador = value; }
        }


        public string Nickname
        {
            get { return nickname; }
            set { nickname = value; }
        }

        public string Correo
        {
            get { return correo; }
            set { correo = value; }
        }

        public string Contrasenia
        {
            get { return contrasenia; }
            set { contrasenia = value; }
        }

        public string Estado
        {
            get { return estado; }
            set { estado = value; }
        }

    }
}