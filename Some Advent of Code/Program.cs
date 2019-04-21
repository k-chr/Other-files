using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;
namespace ConsoleApp2{

    public static class lph{
        public static KeyValuePair<long, long> findMax(this Dictionary<long, long[]> dicc){
            long key = 0, max = 0, iMax = 0;
            foreach(long k in dicc.Keys){
                long tmp = dicc[k].Max();
                if (tmp > max) {
                    key = k;
                    max = tmp;
                    iMax = Array.FindIndex(dicc[k], i => i == max);
                } 
            }
            return new KeyValuePair<long, long>(key, iMax);
        }
    }
    public static class hlp
    {
        public static string ArrayToString(this Array a){
            List<string> lst = new List<string>();
            for(int i = 0; i < a.Length; ++i){
                lst.Add(Convert.ToString(a.GetValue(i)));
            }
            return string.Join(",", lst.ToArray());
        }
    }
    class Program{
        static void Main(string[] args){
            Dictionary<long, long[]> haha = new Dictionary<long, long[]>();
            Dictionary<long, long> ahah = new Dictionary<long, long>();
            DateTime curr = new DateTime(1000, 1, 1);
            var allLines = File.ReadAllLines("C:\\Users\\Kamil\\source\\repos\\ConsoleApp2\\ConsoleApp2\\index.txt");
            Array.Sort(allLines);
            int start = 0, stop = 0;
            long maxId = 0, id = 0;
            long[] tmp = new long[60], occ = null;
            foreach (string line in allLines) {
                Regex r1 = new Regex(@"(?<=\[)[^\]]*"), r2 = new Regex(@"(?<=#)[^\s]*");
                Match d_match = r1.Match(line), s_match = r2.Match(line);
                string[] date = d_match.ToString().Split(' ', '-', ':');
                if (s_match.Success) { 
                    id = Convert.ToInt32(s_match.ToString());
                    if (ahah.Keys.All(k => k != id)) ahah.Add(id, 0);
                    if (haha.Keys.All(k => k != id)){
                        occ = new long[60];
                        for (int i = 0; i < 60; occ[i] = 0, ++i);
                        haha.Add(id, occ);
                    }
                }
                if (line.Contains("asleep")){
                    start = Convert.ToInt32(date[4]);
                }
                if (line.Contains("wakes")){
                    stop = Convert.ToInt32(date[4]);
                    for(int i = start; i < stop; ++i){
                        haha[id][i] += 1;
                    }
                    ahah[id] += stop - start;
                }
            }
            var key = ahah.Values.Max();
            maxId = ahah.FirstOrDefault(x=> x.Value == key).Key;
            var ert = haha[maxId];
            long max2 = ert.Max();
            var max32 = haha.findMax();
            
            Console.WriteLine(Convert.ToString(Array.FindIndex(ert, k => k == max2) * maxId)); //first part
            Console.WriteLine(Convert.ToString(max32.Key * max32.Value)); //second part
        }
    }
}
