using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace servidorproyecto
{

    /// <summary>
    /// Descripción breve de WebService1
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // Para permitir que se llame a este servicio web desde un script, usando ASP.NET AJAX, quite la marca de comentario de la línea siguiente. 
    // [System.Web.Script.Services.ScriptService]
    
    public class WebService1 : System.Web.Services.WebService
    {

      
        private static ArbolBinario nnuevo;
        private static matriz mmatriz;
        public Listatopdiez pruebalista;
       
        matriz nuevo = WebService1.instanciamatriz();
        ArbolBinario abb = WebService1.instanciarbol();

        public static ArbolBinario instanciarbol()
        {
            if (nnuevo == null)
                nnuevo = new ArbolBinario();

            return nnuevo;
        }

        public static matriz instanciamatriz()
        {
            if (mmatriz == null)
                mmatriz = new matriz();

            return mmatriz;
        }




        [WebMethod]
        public string insertaramatriz(int fila, int columna,int c,int nivel)
        {
            //nuevo.insertarmatriz(3, 2, 1);
            //nuevo.insertarmatriz(4, 2, 2);
            nuevo.insertarmatriz(fila, columna, c,nivel);
           // nuevo.insertarmatriz(fila+1, columna+ 1, c + 1);
            nuevo.mostrarmatriz();
            nuevo.llamarapintarmatriz();
            return "bien";
        }


        [WebMethod]
        public string insertarusuario(string nickname,string contra, string corre,string stado)
        {
           abb.insertar(nickname,contra,corre,stado);
         
            return "bien";
        }

        [WebMethod]
        public void mostraarbolespejo()
        {
            abb.espejo();
             abb.creararbol();
            abb.espejo();
            //nnuevo.creararbol();

        }

        [WebMethod]
        public void mostraarbol()
        {
            abb.creararbol();
            //nnuevo.creararbol();

        }

        [WebMethod]
        public void mostraarbolconlistas()
        {
            abb.creararbolgeneral();
            //nnuevo.creararbol();

        }


        [WebMethod]
        public int calcularCantidadRamas()
        {
            int ramas = 0;
            int nodos = abb.calcularRamas();
            nodos = nodos - 1;
            int hojas = abb.getNodosHoja();
            ramas = nodos - hojas;
            return ramas;
            //nnuevo.creararbol();

        }

        [WebMethod]
        public string cargarusuarios()
        {
            abb.csvcargarusuarios();
            return "si";
            //nnuevo.creararbol();

        }



        [WebMethod]
        public string cargarlistausuarios()
        {
            abb.csvcargarlistausuarios();
            return "si";
            //nnuevo.creararbol();

        }

        [WebMethod]
        public int obteneralturaarbolbinario()
        {
            int auxaltura= abb.calcularAltura();
            return auxaltura;
            //nnuevo.creararbol();

        }

        [WebMethod]
        public int obtenerNodosHojas()
        {
            int auxaltura = abb.getNodosHoja();
            return auxaltura;
            //nnuevo.creararbol();

        }
    }


}
