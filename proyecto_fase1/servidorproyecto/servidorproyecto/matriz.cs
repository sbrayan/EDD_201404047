using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Diagnostics;
namespace servidorproyecto
{
    public class matriz
    {
        private nodomatriz inicio;
       // private nodomatriz nuevo;
        private nodoencabezadomatriz primero;
        private nodoencabezadomatriz primerofila;
        private nodoencabezadomatriz efilas1;
        private nodoencabezadomatriz ecolumnas1;
        public nodoencabezadomatriz eFilas11;

        public nodomatriz Inicio
        {
            get { return inicio; }
            set { inicio = value; }
        }

        public nodoencabezadomatriz Primerofila
        {
            get { return primerofila; }
            set { primerofila = value; }
        }

       /*  public nodomatriz Nuevo
        {
            get { return nuevo; }
            set { nuevo = value; }
        } */

        public nodoencabezadomatriz Primero
        {
            get { return primero; }
            set { primero = value; }
        }
        public nodoencabezadomatriz EFilas
        {
            get { return efilas1; }
            set { efilas1 = value; }
        }
        public nodoencabezadomatriz EColumnas
        {
            get { return ecolumnas1; }
            set { ecolumnas1 = value; }
        } 

        //nodomatriz inicio = new nodomatriz();
        //nodomatriz nuevo = new nodomatriz();
       // nodoencabezadomatriz primero = null;
        // nodomatriz posiciony;

          public matriz()
        {
          //  eFilas11 = new nodoencabezadomatriz():

         }

 






        public void insertarencabezado(nodoencabezadomatriz nuevo)
        {
            if (Primero == null)
            {
                Primero = nuevo;
            }
            else
            {
                if(nuevo.Id< Primero.Id) //insercion al inicio
                {

                    nuevo.Siguiente = Primero;
                    Primero.Anterior = nuevo;
                    Primero = nuevo;
                }
                else
                {
                    nodoencabezadomatriz actual = Primero;
                    while (actual.Siguiente != null)
                    {
                        if (nuevo.Id < actual.Siguiente.Id)  //insercion en el medio
                        {


                            nuevo.Siguiente = actual.Siguiente;
                            actual.Siguiente.Anterior = nuevo;
                            nuevo.Anterior = actual;
                            actual.Siguiente = nuevo;
                            break;

                        }
                        actual = actual.Siguiente;
                    }
                    if (actual.Siguiente == null) //insercion al final
                    {
                        

                        actual.Siguiente = nuevo;
                        nuevo.Anterior = actual;
                    }
                }
            }

        }


        public void insertarencabezadofila(nodoencabezadomatriz nuevo)
        {
            if (Primerofila == null)
            {
                Primerofila = nuevo;
            }
            else
            {
                if (nuevo.Id < Primerofila.Id) //insercion al inicio
                {

                    nuevo.Siguiente = Primerofila;
                    Primerofila.Anterior = nuevo;
                    Primerofila = nuevo;
                }
                else
                {
                    nodoencabezadomatriz actual = Primerofila;
                    while (actual.Siguiente != null)
                    {
                        if (nuevo.Id < actual.Siguiente.Id)  //insercion en el medio
                        {


                            nuevo.Siguiente = actual.Siguiente;
                            actual.Siguiente.Anterior = nuevo;
                            nuevo.Anterior = actual;
                            actual.Siguiente = nuevo;
                            break;

                        }
                        actual = actual.Siguiente;
                    }
                    if (actual.Siguiente == null) //insercion al final
                    {


                        actual.Siguiente = nuevo;
                        nuevo.Anterior = actual;
                    }
                }
            }

        }

        nodoencabezadomatriz getEncabezadofila(int id1)
        {
            // return null;

            nodoencabezadomatriz actual = Primerofila;
            while (actual != null)
            {
                if (actual.Id == id1)
                {
                    return actual;
                }
                actual = actual.Siguiente;
            }
            return null;
        }




        nodoencabezadomatriz getEncabezado(int id1)
        {
           // return null;

            nodoencabezadomatriz actual = Primero;
            while (actual != null)
            {
                if (actual.Id == id1)
                {
                    return actual;
                }
                actual = actual.Siguiente;
            }
            return null;
        }

        public void insertarmatriz(int fila, int columna, int id1,int nivel)
        {
            nodomatriz nuevo1 = new nodomatriz(fila, columna, id1,nivel);

            nodoencabezadomatriz filaa = getEncabezadofila(fila);

            if (filaa == null)//si no exisste el encabezado entonces se crea
            {
                filaa = new nodoencabezadomatriz(fila);
                insertarencabezadofila(filaa);
                filaa.Acceso = nuevo1;

            }
            else
            {
                if (nuevo1.Posx < filaa.Acceso.Posx)
                {
                    nuevo1.Siguiente = filaa.Acceso;
                    filaa.Acceso.Anterior = nuevo1;
                    filaa.Acceso = nuevo1;
                }
                else
                {
                    nodomatriz actual = filaa.Acceso;
                    while (actual.Siguiente != null)
                    {
                        if (nuevo1.Posx < actual.Siguiente.Posx)
                        {


                            nuevo1.Siguiente = actual.Siguiente;
                            actual.Siguiente.Anterior = nuevo1;
                            nuevo1.Anterior = actual;//anterior
                            actual.Siguiente = nuevo1;
                            break;
                        }
                        actual = actual.Siguiente;
                    }

                    if (actual.Siguiente == null) //Inserción al final
                    {
                        actual.Siguiente = nuevo1;
                        nuevo1.Anterior = actual;

                    }
                }


            }//fin de filas

            //insercion columna
            nodoencabezadomatriz columnaa = getEncabezado(columna);


            if (columnaa == null) //Si no existe encabezado se crea.
            {
                columnaa = new nodoencabezadomatriz(columna);
                insertarencabezado(columnaa);
                columnaa.Acceso = nuevo1;

            }
            else
            {
                if (nuevo1.Posy < columnaa.Acceso.Posy) //Inserción al inicio
                {
                    nuevo1.Abajo = columnaa.Acceso;
                    columnaa.Acceso.Arriba = nuevo1;
                    columnaa.Acceso = nuevo1;

                }
                else
                {
                    nodomatriz actuaal = columnaa.Acceso;
                    while (actuaal.Abajo != null)
                    {
                        if (nuevo1.Posy < actuaal.Abajo.Posy) //Inserción en el medio
                        {
                            nuevo1.Abajo = actuaal.Abajo;
                            actuaal.Abajo.Arriba = nuevo1;
                            nuevo1.Arriba = actuaal;
                            actuaal.Abajo = nuevo1;
                            break;

                        }
                        actuaal = actuaal.Abajo;

                    }

                    if (actuaal.Abajo == null) //Inserción al final
                    {
                        actuaal.Abajo = nuevo1;
                        nuevo1.Arriba = actuaal;

                    }
                }




            }
        }  //*****************************fin del metodo insertar columna

        public void insertarmatriznivelcero(int fila, int columna, int id1,int nivel)
        {
            nodomatriz nuevo1 = new nodomatriz(fila, columna, id1,nivel);

            nodoencabezadomatriz filaa = getEncabezadofila(fila);

            if (filaa == null)//si no exisste el encabezado entonces se crea
            {
                filaa = new nodoencabezadomatriz(fila);
                insertarencabezadofila(filaa);
                filaa.Acceso = nuevo1;

            }
            else
            {
                int auxnivel = filaa.Acceso.Nivel;
                if (auxnivel == 1)
                {
                    if (nuevo1.Posx < filaa.Acceso.Posx)//insercion al inicio
                    {
                        nuevo1.Siguiente = filaa.Acceso;
                        filaa.Acceso.Anterior = nuevo1;
                        filaa.Acceso = nuevo1;
                    }
                    else
                    {
                        nodomatriz actual = filaa.Acceso;
                        while (actual.Siguiente != null)
                        {
                            if (nuevo1.Posx < actual.Siguiente.Posx)
                            {


                                nuevo1.Siguiente = actual.Siguiente;
                                actual.Siguiente.Anterior = nuevo1;
                                nuevo1.Anterior = actual;//anterior
                                actual.Siguiente = nuevo1;
                                break;
                            }
                            actual = actual.Siguiente;
                        }

                        if (actual.Siguiente == null) //Inserción al final
                        {
                            actual.Siguiente = nuevo1;
                            nuevo1.Anterior = actual;

                        }
                    }





                }
                else if (auxnivel == 2)
                {

                }
                else if (auxnivel == 3)
                {

                }
                


            }//fin de filas

            //insercion columna
            nodoencabezadomatriz columnaa = getEncabezado(columna);


            if (columnaa == null) //Si no existe encabezado se crea.
            {
                columnaa = new nodoencabezadomatriz(columna);
                insertarencabezado(columnaa);
                columnaa.Acceso = nuevo1;

            }
            else
            {
                if (nuevo1.Posy < columnaa.Acceso.Posy) //Inserción al inicio
                {
                    nuevo1.Abajo = columnaa.Acceso;
                    columnaa.Acceso.Arriba = nuevo1;
                    columnaa.Acceso = nuevo1;

                }
                else
                {
                    nodomatriz actuaal = columnaa.Acceso;
                    while (actuaal.Abajo != null)
                    {
                        if (nuevo1.Posy < actuaal.Abajo.Posy) //Inserción en el medio
                        {
                            nuevo1.Abajo = actuaal.Abajo;
                            actuaal.Abajo.Arriba = nuevo1;
                            nuevo1.Arriba = actuaal;
                            actuaal.Abajo = nuevo1;
                            break;

                        }
                        actuaal = actuaal.Abajo;

                    }

                    if (actuaal.Abajo == null) //Inserción al final
                    {
                        actuaal.Abajo = nuevo1;
                        nuevo1.Arriba = actuaal;

                    }
                }




            }
        }

        //***************************************************** crear matriz***********************************

        public void mostrarmatriz()
        {
            StreamWriter grafo = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\grafo.txt");
            grafo.WriteLine("digraph G{");
            grafo.WriteLine("node[shape=box, style=filled, color=Gray95];");
            grafo.WriteLine("edge[color=black];");
            grafo.WriteLine("rankdir=UD;");
            grafo.WriteLine("{rank=min;\"Matriz\";");


            //-------------------------------------
            nodoencabezadomatriz eColumna = Primero;

            while (eColumna != null)
            {
                grafo.WriteLine("\"x"+eColumna.Id+"\";");


                eColumna = eColumna.Siguiente;
            }
            grafo.WriteLine("};\n");
            //--------------------------------------

            grafo.WriteLine("\n");

            //--------------------------------------
            nodoencabezadomatriz eFila = Primerofila;
           

            while (eFila != null)
            {
                grafo.WriteLine("{rank=same;"+"\"" +"y"+eFila.Id+ "\";");
                nodomatriz actual = eFila.Acceso;
                while (actual != null)
                {
                    grafo.WriteLine("\""+ actual.Valor+":"+actual.Posy+ ","+actual.Posx+ "\";");



                    actual = actual.Siguiente;
                }
                grafo.WriteLine( "};\n");

                eFila = eFila.Siguiente;
            }

            //----------------------------------------



            grafo.WriteLine("\n");
            //---------------------------------------- toca aqui creo yo

            nodoencabezadomatriz eFila2 =Primerofila;
            //cout << "Recorrido Por Filas: ";

            while (eFila2 != null)
            {
                //grafo<<"{rank=same;"<<"\""<<eFila->id<<"\";";
                nodomatriz actual = eFila2.Acceso;
                while (actual != null)
                {
                    if (actual.Abajo == null)
                    {

                    }
                    else
                    {
                        grafo.WriteLine("\"" +actual.Valor+":" + actual.Posy + "," + actual.Posx + "\"" +"->" + "\"" + actual.Abajo.Valor + ":" + actual.Abajo.Posy + "," + actual.Abajo.Posx + "\";");

                    }

                    if (actual.Arriba == null)
                    {

                    }
                    else
                    {
                        grafo.WriteLine( "\""+ actual.Valor + ":" + actual.Posy + "," + actual.Posx + "\"" + "->" + "\"" + actual.Arriba.Valor + ":" +actual.Arriba.Posy + "," + actual.Arriba.Posx + "\";");

                    }



                    actual = actual.Siguiente;
                }
                // grafo<<"};\n";

                eFila2 = eFila2.Siguiente;
            }

            //---------------------------------------

            grafo.WriteLine( "\n");

            //---------------------------------------

            nodoencabezadomatriz eColumna2 = Primero;

            while (eColumna2 != null)
            {
                grafo.WriteLine( "\"" +"x" + eColumna2.Id + "\"->\"" + eColumna2.Acceso.Valor +":" + eColumna2.Acceso.Posy + "," + eColumna2.Acceso.Posx + "\";");


                eColumna2 = eColumna2.Siguiente;
            }
            //------------------------------------------

            grafo.WriteLine("\n");
            //-----------------------------------------


            nodoencabezadomatriz eFila3 = Primerofila;
            //cout << "Recorrido Por Filas: ";

            while (eFila3 != null)
            {
                //grafo<<"{rank=same;"<<"\""<<eFila->id<<"\";";
                nodomatriz actual = eFila3.Acceso;
                while (actual != null)
                {
                    if (actual.Siguiente == null)
                    {

                    }
                    else
                    {
                        grafo.WriteLine( "\"" + actual.Valor + ":" + actual.Posy + ","+ actual.Posx + "\"" + "->" +"\"" + actual.Siguiente.Valor + ":" + actual.Siguiente.Posy + "," + actual.Siguiente.Posx + "\"" + "[constraint=false];");

                    }

                    if (actual.Anterior == null)
                    {

                    }
                    else
                    {
                        grafo.WriteLine( "\"" + actual.Valor +":" + actual.Posy + ","+ actual.Posx + "\"" + "->" + "\"" + actual.Anterior.Valor + ":" + actual.Anterior.Posy + "," + actual.Anterior.Posx + "\"" +"[constraint=false];");

                    }



                    actual = actual.Siguiente;  //aqui iba derecha
                }
               

                eFila3 = eFila3.Siguiente;
            }
            //------------------------------------------------------------------


            grafo.WriteLine( "\n");

            //-----------------------------------------------------------------


            nodoencabezadomatriz eFila4 = Primerofila;

            while (eFila4 != null)
            {
                grafo.WriteLine( "\"" +"y"+ eFila4.Id + "\"->\"" + eFila4.Acceso.Valor + ":" + eFila4.Acceso.Posy + "," + eFila4.Acceso.Posx + "\";");


                eFila4 = eFila4.Siguiente;
            }
            //------------------------------------------------------------------


            grafo.WriteLine( "\n");

            //-------------------------------------------------------------------


            nodoencabezadomatriz eColumna3 = Primero;
            grafo.WriteLine( "Matriz -> " +"\"" + "x" + eColumna3.Id + "\";");

            while (eColumna3 != null)
            {
                if (eColumna3.Siguiente == null)
                {

                }
                else
                {
                    grafo.WriteLine( "\"" + "x" + eColumna3.Id+ "\"->\"" +"x" + eColumna3.Siguiente.Id + "\";");

                }



                eColumna3 = eColumna3.Siguiente;
            }

            //--------------------------------------------------------------------

            grafo.WriteLine("\n");
            //--------------------------------------------------------------------


            nodoencabezadomatriz eFila5 = Primerofila;
            grafo.WriteLine( "Matriz -> "+"\"" + "y" + eFila5.Id + "\"[rankdir=UD];");

            while (eFila5 != null)
            {
                if (eFila5.Siguiente == null)
                {

                }
                else
                {
                    grafo.WriteLine( "\"" + "y" + eFila5.Id + "\"->\"" + "y" + eFila5.Siguiente.Id + "\"[rankdir=UD];");

                }



                eFila5 = eFila5.Siguiente;
            }



            //--------------------------------------------------------------------

            grafo.WriteLine("}");
            grafo.Close();
            

        }

        public void llamarapintarmatriz()
        {
            try
            {
                using (var dot = new Process())
                {
                   // dot.StartInfo.Verb = "runas"; // Run process as admin.
                    dot.StartInfo.FileName = @"C:\Program Files (x86)\Graphviz2.38\bin\dot.exe";
                    dot.StartInfo.WorkingDirectory = @"C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto"; 
                    dot.StartInfo.Arguments = "-Tpng  grafo.txt -o graph.png ";
                    dot.Start();
                    dot.WaitForExit();
                }


                /*
                ProcessStartInfo hola = new ProcessStartInfo(@"C:\Program Files (x86)\Graphviz2.38\bin\dot.exe");
                hola.Arguments = "-Tpng C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto/grafo.txt -o  C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto/maatriz.png -maatriz.dot";
                Process.Start(hola); */

            }
            catch (Exception e)
            {

            }

        }

    }


    


}