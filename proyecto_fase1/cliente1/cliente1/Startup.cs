using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(cliente1.Startup))]
namespace cliente1
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
