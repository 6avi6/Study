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

namespace WebAuto
{
    
    internal class Program
    {
        
        static void Main(string[] args)
        {

            
            string url = "https://www.margonem.pl/";
            string login = "adusiek";
            string password ="Adam123.";

            

            login_to(login, password,url);


            

            





        }
        public static void login_to(string login,string password,string url)
        {
            IWebDriver chrome = new ChromeDriver();
        Console.WriteLine("Login:");
            Console.WriteLine(login);
            Console.WriteLine("Password:");
            Console.WriteLine(password);


            chrome.Navigate().GoToUrl(url);


            // WebDriverWait wait = new WebDriverWait(chrome, TimeSpan.FromSeconds(10));
            //IReadOnlyCollection<IWebElement> link_on_page = wait.Until(i => i.FindElements(By.XPath("//a[@class ='fw-bold']")));
            //clicking at element
            // link_on_page.ElementAt(0).Click
            // 
            System.Threading.Thread.Sleep(1000);
            chrome.Navigate().GoToUrl(url);



            //find element named search
            IWebElement login_bar = chrome.FindElement(By.Name("login"));
            IWebElement password_bar = chrome.FindElement(By.Name("password"));

            if (login_bar.Displayed && password_bar.Displayed)
            {
                Console.WriteLine("Element founded");


                for (int i = 0; i < login.Length; i++)
                {
                    login_bar.SendKeys(login[i].ToString());
                    System.Threading.Thread.Sleep(250);

                }
                Console.WriteLine("Element founded");


                for (int i = 0; i < password.Length; i++)
                {
                    password_bar.SendKeys(password[i].ToString());
                    System.Threading.Thread.Sleep(250);

                }
                password_bar.SendKeys(Keys.Enter);
                System.Threading.Thread.Sleep(1500);



                WebDriverWait wait = new WebDriverWait(chrome, TimeSpan.FromSeconds(10));
                IReadOnlyCollection<IWebElement> link_on_page = wait.Until(i => i.FindElements(By.XPath("//div[contains(@class, 'c-btn enter-game')]")));
                //clicking at element
                link_on_page.ElementAt(0).Click();

                System.Threading.Thread.Sleep(2000);

                //clicking at element

                /*
                //writing to element
                element.SendKeys("Milówka");
                element.SendKeys(Keys.Enter);

                //Searching element
                WebDriverWait wait = new WebDriverWait(chrome, TimeSpan.FromSeconds(10));
                IReadOnlyCollection<IWebElement> link_on_page = wait.Until(i => i.FindElements(By.XPath("//a[@title='Milówka (województwo małopolskie)']")));
                //clicking at element
                link_on_page.ElementAt(0).Click();

                System.Threading.Thread.Sleep(2000);


                //Writing letter by letter in field
                string write_text = "Golce";
                element = chrome.FindElement(By.Name("search"));

                for (int i = 0; i < write_text.Length; i++)
                {
                    element.SendKeys(write_text[i].ToString());
                    System.Threading.Thread.Sleep(250);

                }*/


            }
            else
            {

                Console.WriteLine("Couldn 't log to game");
            }



            Thread.Sleep(10000);
            chrome.Quit();
        }
    }
}
