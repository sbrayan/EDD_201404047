using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Diagnostics;

namespace servidorproyecto
{
    public class Listatopdiez
    {
        public nodotop inicio;
        public Listatopdiez()
        {
           // inicio = null;
        }

        public nodotop buscarlistatop10(string nicknamee)
        {
            if (inicio == null)
            {
                return null;
            }
            else
            {
                nodotop auxiliar = inicio;
                while (auxiliar != null)
                {
                    if (auxiliar.Nickname == nicknamee)
                    {
                        
                        return auxiliar;
                        
                    }
                   
                    auxiliar = auxiliar.Siguiente;
                }
                return null;
            }

        }

        public void insertaralfinal(string nick,int juegos)
        {
            nodotop nuevo = new nodotop(nick, juegos);
            if (inicio == null)
            {
                inicio = nuevo;
            }
            else
            {
                nodotop auxiliar = inicio;
                while (auxiliar != null)
                {
                    if (auxiliar.Siguiente == null)
                    {
                        auxiliar.Siguiente = nuevo;
                        nuevo.Anterior = auxiliar;
                        break;
                    }
                    auxiliar = auxiliar.Siguiente;
                }
            }

        }

        public void ordenar()
        {
          
            if (inicio == null)
            {
                return;
            }
            else
            {
                nodotop auxuno = inicio;
                nodotop auxdos = inicio;
                while (auxuno != null)
                {
                    if (auxuno.Siguiente != null)
                    {
                        auxdos = auxdos.Siguiente;
                        while (auxdos != null)
                        {
                            if (auxuno.JuegosGanados < auxdos.JuegosGanados)
                            {
                                int auxjuegos = auxuno.JuegosGanados;
                                string auxnickname = auxuno.Nickname;

                                auxuno.JuegosGanados = auxdos.JuegosGanados;
                                auxuno.Nickname = auxdos.Nickname;

                                auxdos.JuegosGanados = auxjuegos;
                                auxdos.Nickname = auxnickname;
                            }
                            auxdos = auxdos.Siguiente;
                        }

                    }
                    auxuno = auxuno.Siguiente;
                    auxdos = auxuno;
                }

            }
        }


        public void mostrar()
        {
            int contaaux = 1;
            int contaaux2 = 2;
            nodotop aux = inicio;
            StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\top10.txt");
            grafo2.WriteLine("digraph G{");
            while (aux.Siguiente != null)
            {
               grafo2.WriteLine("\""+contaaux+aux.Nickname+","+aux.JuegosGanados+"\"->\""+contaaux2+aux.Siguiente.Nickname+","+aux.Siguiente.JuegosGanados+"\"");
               grafo2.WriteLine("\"" +contaaux2 + aux.Siguiente.Nickname + "," + aux.Siguiente.JuegosGanados + "\"->\"" + contaaux + aux.Nickname + "," + aux.JuegosGanados + "\"");
                contaaux++;
                contaaux2++;
                aux = aux.Siguiente;
            }
            grafo2.WriteLine("}");
           
            grafo2.Close();

            try
            {
                using (var dot = new Process())
                {
                    // dot.StartInfo.Verb = "runas"; // Run process as admin.
                    dot.StartInfo.FileName = @"C:\Program Files (x86)\Graphviz2.38\bin\dot.exe";
                    dot.StartInfo.WorkingDirectory = @"C:/Users/Admin/Documents/Visual Studio 2015/Projects/servidorproyecto";
                    dot.StartInfo.Arguments = "-Tpng  top10.txt -o top10.png ";
                    dot.Start();
                    dot.WaitForExit();
                }


            }
            catch (Exception e)
            {

            }


        }
    }
}