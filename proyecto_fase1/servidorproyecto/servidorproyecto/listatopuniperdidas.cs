using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Diagnostics;
namespace servidorproyecto
{
    public class listatopuniperdidas
    {

        public nodotopdestruido inicio;
        public listatopuniperdidas()
        {
            // inicio = null;
        }

        public nodotopdestruido buscarlistatop(string nicknamee)
        {
            if (inicio == null)
            {
                return null;
            }
            else
            {
                nodotopdestruido auxiliar = inicio;
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




        public void insertaralfinal(string nick, int perd)
        {
            nodotopdestruido nuevo = new nodotopdestruido(nick,perd);
            if (inicio == null)
            {
                inicio = nuevo;
            }
            else
            {
                nodotopdestruido auxiliar = inicio;
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
                nodotopdestruido auxuno = inicio;
                nodotopdestruido auxdos = inicio;
                while (auxuno != null)
                {
                    if (auxuno.Siguiente != null)
                    {
                        auxdos = auxdos.Siguiente;
                        while (auxdos != null)
                        {
                            if (auxuno.UniPerdidas < auxdos.UniPerdidas)
                            {
                                int auxjuegos = auxuno.UniPerdidas;
                                string auxnickname = auxuno.Nickname;

                                auxuno.UniPerdidas = auxdos.UniPerdidas;
                                auxuno.Nickname = auxdos.Nickname;

                                auxdos.UniPerdidas = auxjuegos;
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
            nodotopdestruido aux = inicio;
            StreamWriter grafo2 = new StreamWriter("C:\\Users\\Admin\\Documents\\Visual Studio 2015\\Projects\\servidorproyecto\\top10destruido.txt");
            grafo2.WriteLine("digraph G{");
            while (aux.Siguiente != null)
            {
                grafo2.WriteLine("\"" + contaaux + aux.Nickname + "," + aux.UniPerdidas + "\"->\"" + contaaux2 + aux.Siguiente.Nickname + "," + aux.Siguiente.UniPerdidas + "\"");
                grafo2.WriteLine("\"" + contaaux2 + aux.Siguiente.Nickname + "," + aux.Siguiente.UniPerdidas + "\"->\"" + contaaux + aux.Nickname + "," + aux.UniPerdidas + "\"");
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
                    dot.StartInfo.Arguments = "-Tpng  top10destruido.txt -o top10destruido.png ";
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