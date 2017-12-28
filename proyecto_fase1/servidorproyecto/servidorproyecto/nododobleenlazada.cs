using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servidorproyecto
{


    public class nododobleenlazada
    {

        private string nickoponente;
        private string unidesplegadas;
        private string unisobrevivientes;
        private string unidestruidas;
        private int banderagano;
        private nododobleenlazada siguiente;
        private nododobleenlazada anterior;

        public nododobleenlazada(string opon, string udesple, string usobre, string udes, int band)
        {
            Nickoponente = opon;
            UniDesplegadas = udesple;
            UniSobreviviente = usobre;
            UniDestruidas = udes;
            BandeGano = band;
            Siguiente = null;
            Anterior = null;
        }

        public string Nickoponente
        {
            get { return nickoponente; }
            set { nickoponente = value; }
        }

        public string UniDesplegadas
        {
            get { return unidesplegadas; }
            set { unidesplegadas = value; }
        }

        public string UniSobreviviente
        {
            get { return unisobrevivientes; }
            set { unisobrevivientes = value; }
        }

        public string UniDestruidas
        {
            get { return unidestruidas; }
            set { unidestruidas = value; }
        }
        public int BandeGano
        {
            get { return banderagano; }
            set { banderagano = value; }
        }

        public nododobleenlazada Siguiente
        {
            get { return siguiente; }
            set { siguiente = value; }
        }

        public nododobleenlazada Anterior
        {
            get { return anterior; }
            set { anterior = value; }
        }
    }
}