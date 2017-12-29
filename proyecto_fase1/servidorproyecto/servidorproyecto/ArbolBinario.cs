using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Diagnostics;

namespace servidorproyecto
{
    public class ArbolBinario
    {
        private static int contadoraux;

        private static Listatopdiez listatop;
        private static listatopuniperdidas listatoperdido;
     
             
       Listatopdiez ltop10 = ArbolBinario.instanciatop();
        listatopuniperdidas ltop10p = ArbolBinario.instanciaperdido();

        public static Listatopdiez instanciatop()
        {
            if (listatop == null)
                listatop = new Listatopdiez();

            return listatop;
        }
        public static listatopuniperdidas instanciaperdido()
        {
            if (listatoperdido == null)
            {
                listatoperdido = new listatopuniperdidas();
            }
            return listatoperdido;
        }




        int contarnodos = ArbolBinario.Contadornodos();

        public static int Contadornodos()
        {
            if (contadoraux==0)
                contadoraux =contadoraux+1;

            return contadoraux;
        }

        public nodoarbol raiz;

        public ArbolBinario()
        {
            raiz = null;
        }

        public nodoarbol buscar(string info)
        {
            return buscar1(raiz, info);

        }

        public nodoarbol buscar1(nodoarbol actual,string info)
        {
            if (actual == null)
            {
                return null;
            }

            int comparacion = string.Compare(info, actual.Nickname);
            if (comparacion == 0)
            {
                return actual;
            }
            else
            {
                return buscar1(comparacion < 0 ? actual.Izquierda : actual.Derecha, info);
            }
        }


        public void insertarlistausuario(string nicknameusuario,string nickopo,string udesple, string usobre, string udes,int bgano)
        {
            nodoarbol usuarioactual=buscar(nicknameusuario);
            nododobleenlazada nuevolista = new nododobleenlazada(nickopo, udesple, usobre, udes, bgano);
            if (usuarioactual == null)
            {

            }
            else
            {
                if (usuarioactual.InicioLista == null)
                {
                    usuarioactual.InicioLista = nuevolista;
                    
                }
                else
                {
                    nododobleenlazada actual = usuarioactual.InicioLista;
                    while (actual != null)
                    {
                        if (actual.Siguiente == null)
                        {
                            actual.Siguiente = nuevolista;
                            nuevolista.Anterior = actual;
                            break;
                        }
                        actual = actual.Siguiente;
                    }
                }
            }

        }



        public bool insertar(string info,string contras, string corree,string stado)
        {
          /*  string contras = "123";
            string corree = "brian@gmail.com";
            string stado = "inactivo";*/
            contadoraux = contadoraux + 1;
        
            if (buscar(info) == null)
            {
                if (raiz == null)
                {
                    raiz = new nodoarbol(info,contras,corree,stado,contadoraux);
                    return true;
                }
                else
                {
                    return insertar1(raiz, new nodoarbol(info, contras, corree, stado,contadoraux));
                }
            }

            return false;
        }

        public bool insertar1(nodoarbol actual, nodoarbol nuevo)
        {
            if (string.Compare(nuevo.Nickname, actual.Nickname) < 0)
            {
                if (actual.Izquierda == null)
                {
                    actual.Izquierda = nuevo;
                    return true;
                }
                else
                {
                    return insertar1(actual.Izquierda, nuevo);
                }
            }
            else
            {
                if (actual.Derecha == null)
                {
                    actual.Derecha = nuevo;
                    return true;
                }
                else
                {
                    return insertar1(actual.Derecha, nuevo);
                }
            }
        }
        //*******FIN INSERCION*******


      

       public void espejo()
        {
           espejo1(this.raiz);

        }
        public nodoarbol espejo1(nodoarbol actual)
        {
            if (actual != null)
            {
                nodoarbol t = actual.Izquierda;
                actual.Izquierda = actual.Derecha;
                actual.Derecha = t;
                espejo1(actual.Derecha);
                espejo1(actual.Izquierda);

            }
            return actual;
        }




        public void preOrdengeneral()
        {

            preOrdengeneral1(raiz);
           
        }
        public void preOrdengeneral1(nodoarbol rai)
        {
            if (rai != null)
            {
                if (rai.Izquierda != null)
                {
                    StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt", true);
                    grafo2.WriteLine("\"node" + rai.Contador + "\"" + ":f0->\"node" + rai.Izquierda.Contador + "\":f1;\n");
                    grafo2.Close();
                }

                preOrdengeneral1(rai.Izquierda);

                if (rai.Derecha != null)
                {                
                    StreamWriter grafo1 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt", true);
                    grafo1.WriteLine("\"node" + rai.Contador + "\"" + ":f2->\"node" + rai.Derecha.Contador + "\":f1;\n");
                    grafo1.Close();
                }


                preOrdengeneral1(rai.Derecha);
            }
            // grafo2.Close();


        }


        public void preOrden()
        {
           // cout << endl;
            //cout << "*****Recorrido PreOrden*****" << endl;
            preOrden1(raiz);
           // cout << "*****Fin Recorrido PreOrden*****" << endl;
        }
       public void preOrden1(nodoarbol rai)
        {


            
           // grafo.open("arbol.txt", ios::app);

            if (rai != null)
            {
                
                if (rai.Izquierda != null)
                {

                    StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt", true);
                   // grafo2.WriteLine("digraph G{");

                    //envez de correo iba contador
                    grafo2.WriteLine( "\"node"+rai.Contador+ "\"" + ":f0->\"node" +rai.Izquierda.Contador+ "\":f1;\n");
                    grafo2.Close();
                }


               
                preOrden1(rai.Izquierda);

                if (rai.Derecha != null)
                {

                    StreamWriter grafo1 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt", true);

                    grafo1.WriteLine( "\"node" + rai.Contador +"\"" + ":f2->\"node"+ rai.Derecha.Contador+ "\":f1;\n");
                    grafo1.Close();
                }

               
                preOrden1(rai.Derecha);
            }
           // grafo2.Close();


        }


        public void inOrdengeneral()
        {
            // cout << endl;
            // cout << "*****Recorrido InOrden*****" << endl;
            inOrdengeneral2(this.raiz);
            //cout << "*****Fin Recorrido InOrden*****" << endl;
        }


        public void inOrdengeneral2(nodoarbol actual1)
        {


            if (actual1 != null)
            {
                inOrdengeneral2(actual1.Izquierda);
                StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt", true);

                grafo2.Write("node" + actual1.Contador + "[label = \"<f0> |<f1>");
                grafo2.Write(actual1.Nickname + "|<f2>\"];\n");

               if (actual1.InicioLista == null)
                {

                }
                else
                {
                    int auxbandera = 1;
                    int auxbandera2 = 2;
                    grafo2.WriteLine("\"node" + actual1.Contador + "\":f1->\""+auxbandera+actual1.Nickname+"\";");
                    nododobleenlazada auxiliar = actual1.InicioLista;
                    while (auxiliar.Siguiente != null)
                    {
                       grafo2.Write("\""+auxbandera+ actual1.Nickname+"\"->\""+auxbandera2+actual1.Nickname+"\";");
                       grafo2.Write("\""+auxbandera2+actual1.Nickname + "\"->\""+auxbandera+ actual1.Nickname + "\";");
                        auxiliar = auxiliar.Siguiente;
                        auxbandera++;
                        auxbandera2++;

                    } 
                }

                grafo2.Close();
                inOrdengeneral2(actual1.Derecha);
            }


        }

        public void inOrden()
        {
           // cout << endl;
           // cout << "*****Recorrido InOrden*****" << endl;
            inOrden2(this.raiz);
            //cout << "*****Fin Recorrido InOrden*****" << endl;
        }


        public void inOrden2(nodoarbol actual1)
        {

           
           if (actual1 != null)
            {
                inOrden2(actual1.Izquierda);
                StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt", true);

                grafo2.Write( "node" +actual1.Contador +"[label = \"<f0> |<f1>");
                grafo2.Write(actual1.Nickname + "|<f2>\"];\n");
                grafo2.Close();
               


                inOrden2(actual1.Derecha);
            }

           
        }


        public void creararbol()
        {
            StreamWriter grafoo = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt");
            grafoo.WriteLine("");
            grafoo.Close();

            StreamWriter grafo = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt", true);
            grafo.WriteLine("digraph G{");
           
            grafo.WriteLine( "node [shape = record,height = .1];\n");
            grafo.Close();
             
            inOrden();
            preOrden();

            StreamWriter grafo3 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbol1.txt", true);
            grafo3.WriteLine("}");
            grafo3.Close();

            try
            {
                using (var dot = new Process())
                {
                    // dot.StartInfo.Verb = "runas"; // Run process as admin.
                    dot.StartInfo.FileName = @"C:\Program Files (x86)\Graphviz2.38\bin\dot.exe";
                    dot.StartInfo.WorkingDirectory = @"C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto";
                    dot.StartInfo.Arguments = "-Tpng  arbol1.txt -o arbol.png ";
                    dot.Start();
                    dot.WaitForExit();
                }


            }
            catch (Exception e)
            {

            }
        }


        public void creararbolgeneral()
        {
            StreamWriter grafoo = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt");
            grafoo.WriteLine("");
            grafoo.Close();

            StreamWriter grafo = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt", true);
            grafo.WriteLine("digraph G{");

            grafo.WriteLine("node [shape = record,height = .1];\n");
            grafo.Close();

            inOrdengeneral();
            preOrdengeneral();

            StreamWriter grafo3 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\arbolgeneral.txt", true);
            grafo3.WriteLine("}");
            grafo3.Close();

            try
            {
                using (var dot = new Process())
                {
                    // dot.StartInfo.Verb = "runas"; // Run process as admin.
                    dot.StartInfo.FileName = @"C:\Program Files (x86)\Graphviz2.38\bin\dot.exe";
                    dot.StartInfo.WorkingDirectory = @"C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto";
                    dot.StartInfo.Arguments = "-Tpng  arbolgeneral.txt -o arbolgeneral.png ";
                    dot.Start();
                    dot.WaitForExit();
                }


            }
            catch (Exception e)
            {

            }
        }



        public void csvcargarusuarios()
        {
            int auxinicio = 0;

            List<string[]> parsedData = new List<string[]>();
            using (StreamReader readFile = new StreamReader("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\usuarios.csv"))
            {
                string line;
                string[] row;

                while ((line = readFile.ReadLine()) != null)
                {
                    if (auxinicio == 0)
                    {
                        row = line.Split(',');

                        parsedData.Add(row);
                        // insertar(row[0]);
                        auxinicio = 2;
                    }
                    else
                    {
                        row = line.Split(',');
                        Console.WriteLine(row);
                        parsedData.Add(row);
                        insertar(row[0], row[1], row[2],row[3]);

                    }
                  
                }
            }
        } //fin csvcargar usuarios


        public void csvcargarlistausuarios()
        {
            int auxinicio = 0;

            List<string[]> parsedData = new List<string[]>();
            using (StreamReader readFile = new StreamReader("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\juegos.csv"))
            {
                string line;
                string[] row;

                while ((line = readFile.ReadLine()) != null)
                {
                    if (auxinicio == 0)
                    {
                        row = line.Split(',');

                        parsedData.Add(row);
                        // insertar(row[0]);
                        auxinicio = 2;
                    }
                    else
                    {
                        row = line.Split(',');
                        Console.WriteLine(row);
                        parsedData.Add(row);
                        insertarlistausuario(row[0],row[1],row[2],row[3],row[4],Convert.ToInt32(row[5]));

                        nodotop aux = ltop10.buscarlistatop10(row[0]);
                        nodotopdestruido auxdestruido = ltop10p.buscarlistatop(row[0]);

                        if (aux!=null)//quiere decir que si lo encontro
                        {
                            aux.JuegosGanados = aux.JuegosGanados + 1;


                        }
                        else if (aux==null)
                        {
                            //se inserta
                            if (Convert.ToInt32(row[5]) == 1){ //1 gano, 0 perdio
                                ltop10.insertaralfinal(row[0], Convert.ToInt32(row[5]));
                            }
                            else
                            {
                                ltop10.insertaralfinal(row[0], 0);
                            }
                        }
                        //fin top 10 de jugadores con mas partidasd ganadas

                        //**************************para encontrar top 10 de unidades destruidas******
                        if (auxdestruido != null)//quiere decir que si lo encontro
                        {
                           
                            auxdestruido.UniPerdidas = auxdestruido.UniPerdidas + Convert.ToInt32(row[4]);


                        }
                        else if (auxdestruido == null)
                        {
                            //se inserta
                            
                                ltop10p.insertaralfinal(row[0], Convert.ToInt32(row[4]));
                            
                        }



                    }

                }
                ltop10.ordenar();
                ltop10.mostrar();
                ltop10p.ordenar();
                ltop10p.mostrar();
            }
        } //fin csvcargar usuarios


        public int calcularRamas()
        {
            inOrdencontar(this.raiz);
            return contadoraux;
        }
        

          

        public void inOrdencontar(nodoarbol actual1)
        {


            if (actual1 != null)
            {
                contarnodos = contarnodos + 1;
                inOrdencontar(actual1.Izquierda);
                contarnodos = contarnodos + 1;
                inOrdencontar(actual1.Derecha);
            }
          


        }




        public int calcularAltura()
        {
            if (this.raiz == null)
            {
                return 0;
            }
            else
            {
                return calcularAltura1(raiz);
            }
        }


       public int calcularAltura1(nodoarbol actual)
        {
            if (actual == null)
            {
                return 0;
            }
            else
            {
                int hi = calcularAltura1(actual.Izquierda);
                int hd = calcularAltura1(actual.Derecha);
                return (hi > hd ? hi : hd) + 1;
            }
        }


        public int getNodosHoja()
        {
            if (this.raiz == null)
            {
                return 0;
            }
            else
            {
                return getNodosHoja1(this.raiz);
            }
        }

       public int getNodosHoja1(nodoarbol actual)
        {
            if (actual == null)
            {
                return 0;
            }
            else
            {
                if (actual.Izquierda == null && actual.Derecha == null)
                {
                    return 1;
                }
                else
                {
                    return getNodosHoja1(actual.Izquierda) + getNodosHoja1(actual.Derecha);
                }
            }
        }

    }
}