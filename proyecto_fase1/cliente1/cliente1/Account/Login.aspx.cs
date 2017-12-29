using System;
using System.Web;
using System.Web.UI;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.Owin;
using Owin;
using cliente1.Models;

namespace cliente1.Account
{
    public partial class Login : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
          /* // RegisterHyperLink.NavigateUrl = "Register";
            // Habilite esta opción una vez tenga la confirmación de la cuenta habilitada para la funcionalidad de restablecimiento de contraseña
            //ForgotPasswordHyperLink.NavigateUrl = "Forgot";
            OpenAuthLogin.ReturnUrl = Request.QueryString["ReturnUrl"];
            var returnUrl = HttpUtility.UrlEncode(Request.QueryString["ReturnUrl"]);
            if (!String.IsNullOrEmpty(returnUrl))
            {
               // RegisterHyperLink.NavigateUrl += "?ReturnUrl=" + returnUrl;
            } */
        }

        protected void LogIn(object sender, EventArgs e)
        {
            string nickk = Email.Text;
            string pass = Password.Text;
    
            if(nickk=="admin") 
                {
                if (pass == "admin")
                {
                    Response.Redirect("~/Account/Administrador");
                }

            }
        }
    }
}