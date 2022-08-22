using Internal;
using System.Linq;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace Abid
{
    class confusion
    {
        public static async void Main(string[] args)
        {
            IEnumerable<Task> tasks = Enumerable.Range(0, 2)
                .Select(_ => Task.Run(() => Console.Write("*")));
            await Task.WhenAll(tasks);
            Console.Write($"{tasks.Count()} stars!");
        }
    }
}