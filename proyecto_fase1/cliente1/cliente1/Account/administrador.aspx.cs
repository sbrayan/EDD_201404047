using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace cliente1.Account
{
    public partial class administrador : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

           

        }

        public void Cargar1(object sender,EventArgs e)
        {
            Response.Redirect("~/Account/Login");

        }
    }
}