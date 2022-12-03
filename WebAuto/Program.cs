using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
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
            //Checking chrome version
            IWebDriver chrome = new ChromeDriver();


            //go to adres url
            string url = "https://pl.wikipedia.org/wiki/Wikipedia:Strona_g%C5%82%C3%B3wna\"";
            chrome.Navigate().GoToUrl(url);

            //find element named search
            IWebElement element = chrome.FindElement(By.Name("search"));

            if (element.Displayed)
            {
                Console.WriteLine("Element founded");

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

                for (int i = 0; i<write_text.Length; i++)
                {
                    element.SendKeys(write_text[i].ToString());
                System.Threading.Thread.Sleep(250);

            }
                element.SendKeys(Keys.Enter);

            }
            else
            {

                Console.WriteLine("Element NOT found");
            }

            

            Thread.Sleep(6000);


            chrome.Quit();
            
            Console.WriteLine("aaa");
        
        
        
        
        
        }
    }
}
