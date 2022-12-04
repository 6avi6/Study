using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Security.Policy;
using System.Threading;
using System.Xml.Linq;
using Microsoft.SqlServer.Server;
using OpenQA.Selenium;
//lib for chrome dirvers
using OpenQA.Selenium.Chrome;
//lib for wait until
using OpenQA.Selenium.Support.UI;
//lib for actions
using OpenQA.Selenium.Interactions;



namespace WebAuto
{
    
    internal class Program
    {
        static public int licznik_bić =0;
        static void Main(string[] args)
        {

            IWebDriver driver = new ChromeDriver();
            string url = "https://www.margonem.pl/";
            string login = "adusiek";
            string password ="Adam123.";

            

            login_to(login, password,url,driver);
            while (true)
            {
                attack("npc181450", driver);
          
            }

            driver.Quit();
        }
        public static void login_to(string login,string password,string url, IWebDriver chrome)
        {
            
        Console.WriteLine("Login:");
            Console.WriteLine(login);
            Console.WriteLine("Password:");
            Console.WriteLine(password);

            //open page
            chrome.Navigate().GoToUrl(url);

            //open loging page
            System.Threading.Thread.Sleep(1000);
            chrome.Navigate().GoToUrl(url);



            //login to profile
            IWebElement login_bar = chrome.FindElement(By.Name("login"));
            IWebElement password_bar = chrome.FindElement(By.Name("password"));

            if (login_bar.Displayed && password_bar.Displayed)
            {
                //Console.WriteLine("Element founded");


                for (int i = 0; i < login.Length; i++)
                {
                    login_bar.SendKeys(login[i].ToString());
                    System.Threading.Thread.Sleep(250);

                }
                //Console.WriteLine("Element founded");


                for (int i = 0; i < password.Length; i++)
                {
                    password_bar.SendKeys(password[i].ToString());
                    System.Threading.Thread.Sleep(250);

                }
                password_bar.SendKeys(Keys.Enter);
                System.Threading.Thread.Sleep(1500);


                //Joinin' to game
                WebDriverWait wait = new WebDriverWait(chrome, TimeSpan.FromSeconds(10));
                
                IReadOnlyCollection<IWebElement> link_on_page = wait.Until(i => i.FindElements(By.XPath("//div[contains(@class, 'c-btn enter-game')]")));
                //clicking at element
                link_on_page.ElementAt(0).Click();
                
                System.Threading.Thread.Sleep(2000);

#region zmiana_interfejsu
                IReadOnlyCollection<IWebElement> open_config = wait.Until(i => i.FindElements(By.XPath("//div[contains(@widget-name,'config')]")));
                //clicking at element
                open_config.ElementAt(0).Click();
                System.Threading.Thread.Sleep(500);
                IReadOnlyCollection<IWebElement> open_old_interface = wait.Until(i => i.FindElements(By.XPath("//div[contains(@class,'button green small change-interface-btn')]")));
                //clicking at element
                
                open_old_interface.ElementAt(0).Click();
                #endregion endregion

                //attak mob with id:
                
                
               


            }
            else
            {

                Console.WriteLine("Couldn 't log to game");
            }



            Thread.Sleep(10000);
            
        }

        static void attack(string mob_name, IWebDriver chrome)
        {
            
            Random rnd = new Random();
            WebDriverWait wait = new WebDriverWait(chrome, TimeSpan.FromSeconds(10));
            Actions action = new Actions(chrome);
            //Moving hero
            if (rnd.Next(100) == 1)
            {
                action.KeyDown(Keys.ArrowRight).Perform();
                System.Threading.Thread.Sleep(350);
                action.KeyUp(Keys.ArrowRight).Perform();
                Console.Write("Move");
            }
            //Moving hero
            else if (rnd.Next(100) == 1)
            {
                action.KeyDown(Keys.ArrowLeft).Perform();
                System.Threading.Thread.Sleep(350);
                action.KeyUp(Keys.ArrowLeft).Perform();
                Console.Write("Move");
            }
            //Refreshing page
            else if (rnd.Next(100) == 5 )
            {
                chrome.Navigate().Refresh();
                Console.Write("Refresh");
            }
            
            
            
            
            mob_name= "//div[contains(@id,'"+mob_name +"')]";
            
            IReadOnlyCollection<IWebElement> searched_mob = wait.Until(i => i.FindElements(By.XPath(mob_name)));
            //clicking at element
            try { 
                searched_mob.ElementAt(0).Click();
                System.Threading.Thread.Sleep(1000);
                try
                {
                    IReadOnlyCollection<IWebElement> auto_battle = wait.Until(i => i.FindElements(By.XPath("//div[contains(@id,'autobattleButton')]")));
                    auto_battle.ElementAt(0).Click();
                    System.Threading.Thread.Sleep(1000);
                }
                catch(Exception ex) {
                    Console.Write("Bez Auto walki ");
                }
                try
                {
                    IReadOnlyCollection<IWebElement> close_battle = wait.Until(i => i.FindElements(By.XPath("//div[contains(@id,'battleclose')]")));
                    close_battle.ElementAt(0).Click();
                    System.Threading.Thread.Sleep(1000);

                    Console.WriteLine("");
                    licznik_bić++;
                    Console.WriteLine("Bicie "+licznik_bić);
                }
                catch (Exception ex)
                {
                    Console.Write("Bez zamykania walki ");
                }

            }
            catch(Exception ex)
            {
                
                Console.Write("|");
                //Console.WriteLine("Czekanie na: "+mob_name);
                
            }
            Thread.Sleep(5000);
        }

        
        
    }
}
