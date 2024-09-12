using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

namespace StuCF
{
    class Program
    {
        internal class Blog
        {
            public int id { get; set; }
            public string name { get; set; }

            public virtual List<string> tags { get; set; }
        }
        internal class Post
        {
            public int id { get; set; }
            public string title { get; set;  }
            public string content { get; set;  }

            public int blogId { get; set; }
        }
        internal class BloggingContext : DbContext
        {
            public DbSet<Blog> blogs { get; set; }
            public DbSet<Post> posts { get; set; }
        static void Main(string[] args)
        {
        }
    }
}
