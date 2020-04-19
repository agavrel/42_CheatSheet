# 42 School Cheat Sheet by [agavrel](https://www.github.com/agavrel)

## :two_hearts: *Intended for 42 alumni, current students and candidates*

> Truth can only be found in one place: the code. – *Robert C. Martin, Clean Code: A Handbook of Agile Software Craftsmanship*



---
## Introduction to 42

> 42 is more than just a disruptive educational model and coding school. What makes us unique and a major player in the tech world are the defining characteristics of the 42 culture. Every element of 42 shows our culture, from the students, to the curriculum structure and content, to the $0 tuition and innovative admissions process.

That's right, the school is FREE, originally funded and founded in Paris by generous philanthropist billionaire [Xaviel Niel](https://en.wikipedia.org/wiki/Xavier_Niel)

> *“Nevertheless, C retains the basic philosophy that programmers know what they are doing; it only requires that they state their intentions explicitly.”* ― Brian W. Kernighan, The C Programming Language

Most of the entrance exam and early cursus is done in C language.  

C is indeed one of the best language to understand the basis of programming: Conditions {if, elseif, else}, loops {while, do while, for}, pointers and memory allocation. C will hence act as an educational tool to develop your skill.

Later on you can specialize in other languages: Python will suit data scientists and devops, javascript for frontend developers and C# for those looking for a career in finance.

---
## What you will learn

> "When you say 'I wrote a program that crashed Windows,' people just stare at you blankly and say 'Hey, I got those with the system, for free.'" ― Linus Torvalds

In Short: You will create magic and learn to do what Muggles were only able to do accidentally.

---
## For Candidates: About the "Piscine"
The piscine is the entrance exam that consists of **4 weeks fully dedicated at coding**, solving exercises and submitting group and solo projects.  

Although the school advise you to "come as you are", and this is what I did, it does certainly help to prepare beforehand.  


---
### 0x00 Guidelines to succeed

**It does not matter if you fail a project, an exam or a day as long as you keep striving**. Someone who has never been interested before in Computer Science would never be able to complete everything in time, yet he will not prevent from being successful.

### My guess on the success criteria
* **0x00 Come as you are** ... or forget this shit and prepare with [subject on github](https://github.com/Binary-Hackers/42_Subjects/tree/master/01_Piscines/C/EN), courtesy of my friend binary hacker.

* **0x01 Prepare to nail the exams** on the 4 exams session, knowing that the 3 firsts exams are limited in term of how far you can go and it is not a big deal to miss the first 3 exams as the most important is IMHO the maximum level you can reach. **Succeeding the first 4 exercises (36 pts)** should be enough to make sure you quality.

* **0x02 Get an acceptable percentage of review from peers** (probably 80% is enough, but you would get 90 to 97% if you are nice). *Don't be too nice, but don't be a dick with [vim .swp files](https://lmgtfy.com/?q=What+is+the+purpose+of+swap+files%3F) and .DS_Store*.

>  [.DS_Store](https://en.wikipedia.org/wiki/.DS_Store) – The name of a file in the Apple OS X operating system for storing custom attributes of a folder such as the position of icons or the choice of a background image. These files are created when you manipulate your files with the [Finder GUI](https://en.wikipedia.org/wiki/Graphical_user_interface).

* **0x03 The logging time has no or very little influence**, I know it as a fact for seeing people constantly logged in (but slacking) failing the piscine and students barely present being accepted. However the more time you spend in 42 school will certainly directly influence your skills and positively impact other related topics

* **0x04 It is strongly recommended to succeed at least one group project**, especially the first one that is really easy.

* **0x05 There is a special and unique achievement awarded to the most helpful/smart student.** This achievement does not show up on the student profile until he asks for it.

* **0x06 Be aware of the different rules** : Many things are forbidden like declaring and assigning a variable in the same line, using printf or using for loops. The daily assignment must be pushed on git before Day + 1 at 11pm42.

* **0x07 You can sleep in the school during the selection** - *I recommended you to not do it, you will have very poor sleep.* - If you still go for it here is a list of essential items you should bring: **a toothpaste, a toothbrush, a soap and a towel on top of your phone, charger and mattress. Oh and a credit card also, unless you prefer to bring 10kg of cookies**

#### :star: List of Essential Items

:sleeping_bed: Mattress or equivalent and Pillow  
:electric_plug: Phone charger  
:iphone: Phone  
:droplet: Toothpaste and Toothbrush  
:bathtub: Soap and 2-4 Towels  
:money_mouth_face: Credit Card  
:heart: Kleenex  

---
### 0x01 Things to prepare

#### First by installing a C compiler on your computer
* On Windows it is a bit tricky, you will have to install [Mingw](http://www.mingw.org/)
* On Linux it is pretty straightforward since it is only installed and if not ```apt-get``` will make it easy.
* On MAC it is not much more difficult, google how to do it.

You should then try to recode basic C functions

#### ft_putchar

*A minimalist c program that will puzzle beginners, write it in a file named a.c and create a.out with ```gcc a.c && ./a.out```*

The following program will print a char by making use of [write](http://man7.org/linux/man-pages/man2/write.2.html)

```c
#include <unistd.h>

void	ft_putchar(char c) // void because the function does not return any value, it writes directly, char is the type of the variable c that is given as parameter to the function ft_putchar by the main function.
{
	write(1, &c, 1);			// ssize_t write(int fd, const void *buf, size_t count); or in human language: write count letters of buf (which is a pointer) to fd (if fd = 1 this is your terminal, stdout)
}

int	main(void) {
	ft_putchar(42);				// will print a star
	// ft_putchar(42 + '0');	// will only print 4
	// ft_putchar("4");			// will not work, you are using " instead of ', so C language think it is a char array.
	return 0;
}
```

Once you understand well how to print a character, you should try to return the length of many together (it is called a [string](https://en.wikipedia.org/wiki/String_(computer_science)))

#### ft_strlen

```c
#include <unistd.h>

int		ft_strlen(char *str) {
	int i = 0;					// set variable i to 0
	while (str[i] != NULL)		// while the char array does not reach a NULL character
		i++;					// increment i, equivalent of i = i + 1;

	return i;					// return i variable to the caller function
}

int main(void) {
	int i = ft_strlen("Duck Tales");	// declare i, call the function ft_strlen, and assign its output to i
	printf("%d", i); // remember that it is forbidden to submit a function with printf during the Piscine
	return 0;
}
```
*NB: remember that it is forbidden to submit a function with printf during the Piscine*

#### ft_putstr

Then print a whole string by recoding the libc function 'puts':
```c
#include <stdio.h> // header for puts

int main(void) {
	puts("Duck Tales");
	return 0;
}
```

This can be achieve by using and index that starts on the first character and is progressively incremented until NULL as string are NULL terminated:
```c
#include <unistd.h>

void	ft_putstr(char *str) {
	int i = 0;

	while(str[i] != NULL)
		write(1, &str[i++], 1);
}
```

Along with the main function slightly modified to make use of your code:
```c
int main(void) {
	ft_putstr("Duck Tales");
	return 0;
}
```

You can also use only the pointer since you do not care of the return value (the function type being void)
```c
#include <unistd.h>

void	ft_putstr(char *str) {
	while(*str)
		write(1, s++, 1);
}
```

Or even use the length of the string to print the whole string at once, hence avoiding many *[system calls](https://en.wikipedia.org/wiki/System_call) (write)* that are costly for the program execution:

```c
void	ft_putstr(char *str) {
	write(1, str, ft_strlen(str));
}
```
*NB: You have to include ft_strlen in the same file AND above the function to make it work.*

Next you should **study the different concepts in programming**, especially spend time understanding the different [C data types](https://en.wikipedia.org/wiki/C_data_types), [the concept of pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming)) and [arrays](https://en.wikipedia.org/wiki/Array_data_type), because it is what you have been using up to now and it will only get more complicated.


---
## For Accepted Students: 42 Projects Guides

> "Do what you think is interesting, do something that you think is fun and worthwhile, because otherwise you won’t do it well anyway." ― *Brian W. Kernighan*

|Name|Track|Hashtags|What you will learn|
|-|-|-|-|
|Fillit|General|Architecture, Parsing, Algo|[Description from a student](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)|
|Printf|Algorithm|Architecture, Parsing, utf-8|[UTF-8 Conversion table](https://en.wikipedia.org/wiki/UTF-8)<br>[Variadic Function](https://en.wikipedia.org/wiki/Variadic_function)|
|Filler|Algorithm|Parsing, Algo, Bot|42 forums have good threads on this project|
|Lem-In|Algorithm|Parsing, Algo, Chained-Lists|[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)|
|Corewar|Algorithm|Architecture, parsing, disassembler, virus, VM|[About the original Game](https://en.wikipedia.org/wiki/Core_War)|
|LS|System|Parsing, Recursion, Chained-Lists|[The Good Old Manual](http://man7.org/linux/man-pages/man1/ls.1.html)|
|Minishell|System|Environment Variables, Shell|[Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)|
|Malloc|System|Algo, Memory, HashCollision|[The Good Old Manual](http://man7.org/linux/man-pages/man3/malloc.3.html)|
|FDF|Computer Graphics|Parsing, Creativity|[Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm), [Use of Graphics Library](https://en.wikipedia.org/wiki/Graphics_library), [Trigonometry](https://en.wikipedia.org/wiki/Trigonometry), [Rotations](https://en.wikipedia.org/wiki/Rotation_(mathematics)), [3D Projection](https://en.wikipedia.org/wiki/3D_projection), [ARGB Color Space](https://en.wikipedia.org/wiki/RGBA_color_space)|
|Fractol|Computer Graphics|Fractals, Mathematics, ARGB, HUV|[Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)|
|Wolfenstein 3d|Computer Graphics|Raytracing, Rotation|[About the original Wolfenstein 3d](https://en.wikipedia.org/wiki/Wolfenstein_3D)|
|NmOtool|System|Symbol Table, .dll .so|[Implement List the symbols in a .so file](https://stackoverflow.com/questions/34732/how-do-i-list-the-symbols-in-a-so-file)
|LibftAsm|System|x86 Assembly Instructions|[Refer to the Intel Bible](https://software.intel.com/en-us/articles/intel-sdm)

---
### Choosing your Path

**How to choose your specialization**
There are currently 4 main branches: [Infographics](https://en.wikipedia.org/wiki/Infographic), Algorithms, System and Web.
All branchs are interesting and you should try to explore each branch's initial project:
* If you are aiming to work in the video game industry and like Mathematics then you should go for **Infographics**. Remember that this path is tough and not necessarily as rewarding as the other ones, but you will have the luxury to work in the video game industry.
* **Algorithm branch** is/was mainly based on flawless parsing and not so much on algorithm quality. Fortunately with the nomination of Benny as the head of the Pedagogy there will be more efforts to reward smart algorithms. Algorithms is the best one if you want to join a prestigious company like Google
* **System** is the best for those who like security, network and how computers truly work since you will have to ultimately recode your own operating system.
* **Web** is good for those who like to build websites, perhaps mobile app as well (react native) and want to become a freelancer.

---
## Curated list of recommended Manuals, Books, Videos, Blog Articles and Tutorials

*Only petty thieves would google "torrent" or "pdf" keywords, real Gentlemen would purchase a digital copy*

### 0x00 C Knowledge

> "C is quirky, flawed, and an enormous success." ― *[Dennis Ritchie, Creator of the C language](https://en.wikipedia.org/wiki/Dennis_Ritchie)*

Title | How Interesting | Author
---|---|---
**[The C Programming Language 2nd Ed Subsequent Edition](https://www.goodreads.com/book/show/515601.The_C_Programming_Language)** | :two_hearts: | *by Brian Kernighan and Dennis Ritchie*
**[Are Global Variables Bad](https://stackoverflow.com/questions/484635/are-global-variables-bad)** | :star: | *StackOverFlow*
**[Obscure C Features](https://multun.net/obscure-c-features.html)** | :star::star::star::star::star: | *[by Multun](https://github.com/multun)*
**[Characters, Symbols and the UTF-8 Miracle - Computerphile](https://www.youtube.com/watch?v=MijmeoH9LT4)** | :star::star::star::star: | *by Tom Scott*
**[Automatic Vectorization](https://www.codingame.com/playgrounds/283/sse-avx-vectorization/autovectorization)** | :star::star::star::star: | *[by Marchete](https://github.com/marchete)*
**[Writing Solid Code](http://cs.brown.edu/courses/cs190/2008/documents/restricted/Writing%20Solid%20Code.pdf)** | :star::star::star::star: | *by Steve Maguire*
**[The Practice of Programing](http://index-of.co.uk/Etc/The.Practice.of.Programming.-.B.W..Kernighan..pdf)** | :star::star::star: | *by Brian W. Kernighan and Rob Pike*
**[Duff's Device](http://www.lysator.liu.se/c/duffs-device.html)** | :star::star::star: | *by Tom Duff*

### 0x01 Algorithm

Title | How Interesting | Author
---|---|---
**[A curated list of Awesome Competitive Programming](https://codeforces.com/blog/entry/23054)** | :star::star::star: | *by Inishan (Jasmine Chen)*
**[Nailing the Coding Interview](https://github.com/agavrel/Nailing-the-Coding-Interview)** | :kr: | *by Antonin Gavrel*
**[A tour of the top 5 sorting algorithms with Python code](https://medium.com/@george.seif94/a-tour-of-the-top-5-sorting-algorithms-with-python-code-43ea9aa02889)** | :star::star: | *by George Seif*


### 0x02 Bits

> "The word bit is a contraction of binary digit that was coined by the statistician John Tukey in the mid 1940s." ― *Brian W. Kernighan, D Is for Digital*

Title | How Interesting | Author
---|---|---
**[Hacker's Delight](https://doc.lagout.org/security/Hackers%20Delight.pdf)** | :two_hearts: | *by Henry S. Warren Jr.*
**[Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)** | :two_hearts: | *by Sean Eron Anderson*
**[De Bruijn Sequence](https://www.chessprogramming.org/De_Bruijn_Sequence)** | :star::star:


### 0x03 Network

> I would tell you a joke about UDP but I’m afraid you wouldn’t get it.

Title | How Interesting | Author
---|---|---
**[Next Generation Kernel Network Tunnel - WireGuard](https://www.wireguard.com/papers/wireguard.pdf)** | :two_hearts: | by JA Donenfeld |
**[TCP Meltdown](https://www.youtube.com/watch?v=AAssk2N_oPk)** | :star::star: | *by Computerphile*
**[Onion Routing](https://www.youtube.com/watch?v=QRYzre4bf7I)** | :star::star::star::star: | *by Computerphile*


### 0x04 Hacking & Security

> "Never underestimate the determination of a kid who is time-rich and cash-poor." ― *Cory Doctorow, Little Brother*

Title | How Interesting | Author
---|---|---
**[Smashing The Stack For Fun And Profit](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)** | :two_hearts: | *by Aleph One*
**[Breaking the x86 Instruction Set](https://www.youtube.com/watch?v=KrksBdWcZgQ)** | :star::star::star::star::star: | *[by Domas](https://github.com/xoreaxeaxeax)*
**[Buffer Overflow, Race Condition, Input Validation, Format String](http://www.cis.syr.edu/~wedu/Teaching/cis643/schedule.html)** | :star::star::star::star: | *by Wenliang (Kevin) Du*
**[Secure Programming HOWTO](https://dwheeler.com/secure-programs/Secure-Programs-HOWTO.pdf)** | :star::star::star: | *by David A. Wheeler*
**[Efficiently Generating Python Hash Collisions](https://www.leeholmes.com/blog/2019/07/23/efficiently-generating-python-hash-collisions/)** | :star::star:
**[Stochastic Process Wikipedia](https://en.wikipedia.org/wiki/Stochastic_process)** | :star::star:
**[Gimli: a cross-platform permutation](https://eprint.iacr.org/2017/630.pdf)** | :star::star:
**[LiveOverflow](https://www.youtube.com/channel/UClcE-kVhqyiHCcjYwcpfj9w)** | :star::star:


### 0x05 Computer Graphics

Title | How Interesting | Author
---|---|---
**[Fast Inverse Square Root](https://en.wikipedia.org/wiki/Fast_inverse_square_root)** | :two_hearts: | attributed to John Carmack (Quake III)
**[3d Fractal Flame Wisps](https://tigerprints.clemson.edu/cgi/viewcontent.cgi?article=2704&context=all_theses)** | :star::star::star: | *[by Yujie Shu](https://www.semanticscholar.org/author/Yujie-Shu/11523322)*
**[Geometry Caching Optimizations in Halo 5](https://www.youtube.com/watch?v=uYAjUOlEgwI)** | :star::star::star: | *by Zabir Hoque and Ben Laidlaw*
**[Exponentiation by Squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)**  | :star: | *Wikipedia*
**[Light and Shadows in Graphics](https://www.youtube.com/watch?v=LUjXAoP5GG0)** | :star::star: | *by John Chapman*
**[Screen Space Ambient Occlusion Tutorial](http://john-chapman-graphics.blogspot.com/2013/01/ssao-tutorial.html)** | :star::star: | *by John Chapman*


### 0x06 Computer Vision & AI

Title | How Interesting | Author
---|---|---
**[OpenCV Tutorial](https://docs.opencv.org/2.4/opencv_tutorials.pdf)** | :star::star::star:


### 0x07 In-Depth C++ Optimization

> "C++ is a horrible language. It's made more horrible by the fact that a lot of substandard programmers use it, to the point where it's much much easier to generate total and utter crap with it" ― *Linus Torvalds 2007*

Title | How Interesting | Author
---|---|---
**[C++ Features](https://github.com/AnthonyCalandra/modern-cpp-features)**
**[Optimizing software in C++](https://www.agner.org/optimize/optimizing_cpp.pdf)** | :two_hearts: | *by Agner Fog*
**[Intel Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)** *[What is it](https://en.wikipedia.org/wiki/Intrinsic_function)* | :star::star::star::star: | *Intel*
**["Low Latency C++ for Fun and Profit"](https://www.youtube.com/watch?v=BxfT9fiUsZ4)** | :star::star::star::star: | *by Carl Cook*
**[Why I Created C++](https://www.youtube.com/watch?v=JBjjnqG0BP8)** | :star::star::star: | *Bjarne Stroustrup*
**[CppCon 2018 “High-Radix Concurrent C++”](https://www.youtube.com/watch?v=75LcDvlEIYw)** | :star::star::star: | *Olivier Giroux*


### 0x08 In-Depth Assembly Optimization

> "People say that you should not micro-optimize. But if what you love is micro-optimization... that's what you should do." ― *Linus Torvalds*

Title | How Interesting | Author
---|---|---
**[Optimizing subroutines in assembly x86 language](https://www.agner.org/optimize/optimizing_assembly.pdf)** | :two_hearts: | *by Agner Fog*
**[Intel® 64 and IA-32 architectures software developer’s manual](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-1-2a-2b-2c-2d-3a-3b-3c-3d-and-4)** | :two_hearts: | *Intel*
**[The Art of Assembly Language](http://www.staroceans.org/kernel-and-driver/The.Art.of.Assembly.Language.2nd.Edition.pdf)** | :star::star: | *by Randal Hyde*
**[GDB Tutorial](https://www.cs.cmu.edu/~gilpin/tutorial/)** | :star::star: | *by Andrew Gilpin*
**[Tips for Golfing in x86/x64 Bytecode](https://codegolf.stackexchange.com/questions/132981/tips-for-golfing-in-x86-x64-machine-code)** | :star::star::star: | *by StackExchange*


### 0x09 Functional Programing *[submitted by Leonard Marquez](https://github.com/keuhdall)*

> "A monad is just a monoid in the category of endofunctors, what's the problem?" ― *James Iry*

Title | How Interesting | Author
---|---|---
**[Learn You a Haskell for Great Good!](http://learnyouahaskell.com/chapters)** | :two_hearts: | *by Miran Lipovača*
**[Functors, Applicatives, And Monads In Pictures](http://adit.io/posts/2013-04-17-functors,_applicatives,_and_monads_in_pictures.html)** | :two_hearts: | *by Aditya Bhargava*
**[Category Theory course by Bartosz Milewski](https://www.youtube.com/watch?v=I8LbkfSSR58&list=PLbgaMIhjbmEnaH_LTkxLI7FMa2HsnawM_)** | :star::star::star::star::star: | *by Bartosz Milewski*
**[Wise Man's Haskell](https://andre.tips/wmh/)** | :star::star::star::star: | *by Andre Popovitch*
**[Real World Haskell](http://book.realworldhaskell.org/read/)** | :star::star::star: | *by Bryan O'Sullivan*
**[Martin Odersky's Scala course](https://www.coursera.org/learn/progfun1)** | :star::star: | *by Martin Odersky*


### 0x0A Misc

> "Everyone knows that debugging is twice as hard as writing a program in the first place. So if you're as clever as you can be when you write it, how will you ever debug it?" ― *Brian W. Kernighan*

Title | How Interesting | Author
---|---|---
**[A Super Mario 64 decompilation](https://github.com/agavrel/sm64)** | :star::star::star::star::star: | *by a bunch of clever folks*
**[Vim 101 Quick Movement](https://medium.com/usevim/vim-101-quick-movement-c12889e759e0)** | :star::star::star:star: | *Alex R. Young*
**[Math for Game Programmers: Dark Secrets of the RNG](https://www.youtube.com/watch?v=J5qnnxFoBss)** | :star::star::star: | *by Shay Pierce*
**[Why Java Suck](https://tech.jonathangardner.net/wiki/Why_Java_Sucks)** | :star: | *by Jonathan Gardner*
**[XOR Linked List – A Memory Efficient Doubly Linked List](http://en.wikipedia.org/wiki/XOR_linked_list)** | :star: | *Wikipedia* 
**[XOR Linked List – C Implementation](https://stackoverflow.com/questions/3531972/c-code-for-xor-linked-list)** | :star: | *StackOverFlow*


---
## Common Beginner Mistakes

> "Experience is the name everyone gives to their mistakes." – *[Oscar Wilde](https://en.wikipedia.org/wiki/The_Picture_of_Dorian_Gray)*

---
### 0x00 Array overflow

In C the index of an array starts at 0. Because C does not perform boundary checking when using arrays, if you access outside the bounds of a stack based array it will just access another part of already allocated stack space, like in this example:

```c
#include <stdio.h>
void    somefunction3(void)
{
    int a[5];

    printf("%d\n", a[5]);
}
```
In this example, 5 is the size of the array and if you try to access it it will overflow. Remember that the maximum array index you can ever access is its size minus 1.

I would suggest to use as much as possible a const :
```c
#include <stdio.h>

void    somefunction3(void)
{
	const int len = 5;
	int a[len] = {1,3,5,7,9};
	for (int i = 0; i < len; i++) // safe
		printf("%d\n", a[i]);
}
```

---
### 0x01 Segmentation Fault

> "There are two ways to write error-free programs; only the third one works." – *Alan J. Perlis*

*Many potential reasons for this...*


---
### Loop segfault
One common mistake is that you had declared a loop and either:

#### Forgot to increment the counter

```c
int i = 0;

while (i < 10)
{
	write(1, &i + '0', 1);
	// but where is i++ ?
}
```

#### Correct way

```c
int i = 0;

while (i < 10)
{
	write(1, &i + '0', 1);
    	i++;
}
```

#### Forgot the exit condition:

```c
int somevariable = 0;
while (42) // always True ! You will be 42 for life ;)
{
    // call to some stuff that never succeed to set someVariable to 1;
    if (somevariable == 1) // make sure that somevariable will equal 1 at some point.
        break ;
}
```

#### Used an assignation = instead of a boolean expression != == <= >=

```c
#include <stdio.h>

int main(void) {
	unsigned int x = 10;

	while (--x != 0)
	{
		printf("0 0 0 1 0 1 0 1 0 ");
		if (x = 1) {			// oopsie !!
			printf("* ");
			x--;
		}
	}
	return 0;
}
```
PS: will you be able to fix this code ?

Also classic with lists:  you have a loop and its crucial condition that allows the function to return, but used an assignation instead of comparison
```c
int i = 0;

while (list)
{
    if (list = NULL) // You want to use if (list == NULL)
        return i;
    i++;
    list=list->next;
}
return -1; // will always return -1
```

#### Quizz: What will print this loop ?

```c
unsigned char c = 0;

while (c < 150)
{
	write(1, &c, 1);
	c++;
}
```

> "Talk is cheap. Show me the code." ― Linus Torvalds


#### Accessing the next link in a chained-list without checking the current one

Another example with linked-lists
```c
typedef struct  s_list {
      void      *data;
      t_list    *next;
 }              t_list;

/*
** function to go 2 links further in a chained-list
*/

void somefunction(t_list *list)
{
    if (list->next != NULL)
    {
        list = list->next->next;
    }
}
```

if the current link of list is null you will get a segfault. The correct way is to always check the current link before the next one:
```c
void somefunction(t_list *list)
{
    if (list && list->next) // if both list and list->next exist
    {
        list = list->next->next;
    }
}
```

#### Accessing an index in a loop for program with either graphics or a board game
```c
int somefunction(int y_max, int x_max, int array[y_max][x_max]);
{
    int y;
    int x;

    y  = 0;
    while (y < y_max)
    {
        x = 0;
        while (x < x_max)
        {
            if (array[y][x-1] > array[y][x]) // don't you see there is a problem ?
            {
                array[y][x] = array[y][x-1];
            }
            if (array[y+1][x] > array[y][x]) // don't you see there is another problem ?
            {
                array[y][x] = array[y+1][x];
            }
        }

    }
}
```

These lines should be corrected the following way:
```c
if (x > 0 && array[y][x-1] > array[y][x])
if (y < y_max - 1 && array[y+1][x] > array[y][x]) // strictly inferior to last possible index which is y_max - 1,
// you may also write y <= y_max - 2
```

You may also notice that we can even do better by changing the starting value of x or the exit condition of the y loop **in the case that we were to check only one of the two if conditions.**
```c
x = 1;
while (y < y_max - 1)
```

---
### 0x01 Modifying value of a local variable given as function parameter

Local variable value are allocated on the stack, which is cleaned once you exit the function.
```c
void increment_a(int a)
{
    a++; // it will have no effect
}

int solve(void)
{
    int a = 5;

    increment_a(a);
}
```

Hence if you want to modify a value you either have to use a pointer to the memory address:
```c
void increment_a(int *a)
{
    *a++;
}

int solve(void)
{
    int a = 5;

    increment_a(&a);
}
```

or return the local value:
```c
int increment_a(int a)
{
    return a+1;
}

int solve(void)
{
    int a = 5;

    a = increment_a(a);
}
```

### 0x02 Unprotected malloc

Do NOT leave a malloc unprotected:
```c
int allocate_memory(void)
{
    int *matrix;

    matrix = malloc(sizeof(int) * 9))

    return matrix;
}

int somefunction(void)
{
	int *matrix;

	matrix = allocate_memory();
}
```

Protect both the malloc **and its return value**:
It is not good enough to protect the malloc in the callee function (the function called) if the returned value is not also protected in the caller function (the function 'above')
```c
int allocate_memory(void)
{
	int *matrix;

	if (!(matrix = malloc(sizeof(int) * 9))) // this is short for matrix = malloc(sizeof(int) * 9; if (matrix == NULL)
		return NULL;   // the malloc is now protected,

	return matrix;
}

int somefunction(void)
{
	int *matrix;

	if ((matrix = allocate_memory()) == NULL) // the return value is also protected
        	exit(); // note that often you can't or don't want to use exit() and will need to return 0 along all the functions up to the main function.
	free(matrix);
}
```

---
### 0x03 Freeing memory that has already been fred

In the previous example, if you don't need the variable matrix anymore you can free it.  

However do not attempt to free twice or to free a stack based variable:
```c
free(matrix);
free(matrix)
```


---
### 0x04 Do Not use global variables

> "Theory and practice sometimes clash. And when that happens, theory loses.  
Every single time." ― Linus Torvalds

Global variables are forbidden in 42 School except for a few exceptions, see this interesting article: [Are Global Variables Bad](https://stackoverflow.com/questions/484635/are-global-variables-bad)
However many students, me including, found a way to circumvent this interdiction: you first declare a structure in the header that will contain all our variables:

> "Don’t comment bad code—rewrite it." ― *Brian W. Kernighan, The Elements of Programming Style*

```c
typedef struct s_env
{
    int a;
    int b;
    int c[4];
    // ... other variables you may need
}           t_env;
```
And then using it the following way in the program:
```c
void somefunction2(t_env *env)
{
    env->b = 2;
}

void somefunction(t_env *env)
{
    env->a = 1;

    somefunction2(env);
}

int main(void)
{
    t_env env;

    somefunction(&env);

    printf("%d\n", env.a);
    printf("%d\n", env.b);
}
```

This is "legal" in 42 (it is not a global variable, it is a structure passed along functions), it "works", but it is a very poor architecture choice. It is okay for beginner to do this but as your skill grows you should find more clever ways to architecture your programs.


---
### 0x05 VLA - Variable Length Arrays

The following example is a VLA and this is bad for many reasons, the most critical being that the memory is allocated on the stack which has a limited size.
```c
int somefunction(int y, int x, int array[y][x]);
```
[Waiter! There's a VLA in my C!](http://ayekat.ch/blog/vla)


---
### 0x06 Using ft_ prefix for all functions

*ft_* should only be added to functions you want to re-use through different projects (and add to your personal library, the libft project) not for specific program functions.


---
### 0x07 [Usage of Sequence Point](https://en.m.wikipedia.org/wiki/Sequence_point)
```
#include <unistd.h>

int main()
{
	int i = 0; 
	i = (i++);
	write(1, &i + '0', 1);

	return 0;
}
```
Guess what will be printed.


---
## Good practices

Now some guidelines that should hopefully help your coding style

> “Don’t comment bad code, rewrite it.” Brian W. Kernighan, The Elements of Programming Style


---
### 0x00 Using structure for basic items

If you are using coordinates it might be interesting to create a structure 'point' or 'coord'

```c
typedef struct s_point
{
    int y;
    int x;
}           t_point;

void somefunction(void){
    t_point p;

    p.x = 2;
    p.y = 5;

    //alternatively:  p = {5, 2};
}
```

---
### 0x01 Naming conventions

I once met a developer who was using hp and mp instead of x and y for coordinates.  
It was surely funny, original and a very good reference to JRPG... but it was not suitable name.  
The function name should always be:
* In English, forget about chauvinism!
* At least 5 letters. It is okay to have shorter exceptionally for well-known variables like int index -> int i, temporary -> tmp and pointer -> ptr.
* Self-explanatory: build_graph instead of graph or build_it
* For long name use either camel case (saveClientConfig) or snake case (save_client_config) and stick to one style.

---
### 0x02 Using flags for projects' options
For each project you will often have to parse flag input. In Linux the flag usually come after a '-' and allow for extra functionalities.
It is quite useful know how you can store such critical information into only 4 bytes *which is sizeof(integer)*
```c
static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int			get_flags(char *s, int *flags)
{
	int		n;

	while (*(++s))
	{
		if ((n = ft_strchr_index("alRrtdG1Ss", *s)) == -1)
			return (0);
		*flags |= (1 << n);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int	i;

	int flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && av[i][2])
			return (i + 1);
		if (!get_flags(av[i], &flags))
			return (-1);
	}
	return (i);
}
```

The a flag will be on bit 1, l on bit 2, R on bit 4, r on bit 8 etc.
You can then test if the flag was on by using the following:
```c
#define FLAG_A  0b001
#define FLAG_L  0b010
#define FLAG_RR 0b100

#include <stdio.h>

void    somefunction(int *flags)
{
	if (flags & FLAG_A)
		printf("Flag a is set!\n");    
}
```

You can unset a flag by clearing the corresponding bit the following way:
```c
void    somefunction2(int *flags)
{
	flags &= ~FLAG_A;
}
```

> "Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live." – *John Woods*

A more readable (aka: better) approach suggested by Nicolas Iragne from 42 is to declare a struct using bitfield:

```c
struct 	flags_t
{
	int a : 1;
	int b : 1;
	int c : 1;
	//etc
}

#include <stdio.h>

int	main(void) {
	struct flags_t flags = {0};
	t.a = 1;
	if (t.a)
		write(1, "flag a is set\n", 14);
	return 0;
}
```
PS: Of course rename flags' name with more meaningful


### 0x03 Using gcc flags for Makefile
```
gcc -Wall -Wextra -Werror -O2
```
* O2 will improve performance  ##Create a new repository on the command line
* pedantic is not requested but is a good one to check ISO C compliance

> Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions, and some other programs that do not follow ISO C and ISO C++. For ISO C, follows the version of the ISO C standard specified by any -std option used.


You can read the details about each flag on [gccgnu website](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)

### 0x04 Using preprocessor DEBUG macros

You can improve the performance of your program by using what we call preprocessor macros
```
#include <unistd.h>

#define DEBUG true

int main(void) {
	if (DEBUG)
		write(1, 42, 1);
	return 0;
}
```

### 0x04 Setting up a new Git Repository using CLI (command line interface)

It can be done easily using the following command line:  
```
reponame='docker'
mkdir $reponame
touch README.md
git init
git add README.md
git commit -m "[INIT] First commit"
git remote add origin git@github.com:agavrel/$reponame.git
git push -u origin master
```

### 0x05 [Run Commands in Background](https://linuxize.com/post/how-to-run-linux-commands-in-background/) (could be used to recompile automatically each time .c are saved)

You can have multiple processes running in the background at the same time with ```&``` after the command.  
However the background process will continue to write messages to the terminal from which you invoked the command.  

To suppress the stdout and stderr messages use the following syntax:  
```
command > /dev/null 2>&1 &
```

```>/dev/null 2>&1``` means redirect ```stdout``` to ```/dev/null``` and ```stderr``` to ```stdout```

Use the jobs utility to display the status of all stopped and background jobs in the current shell session:
```
jobs -l
```
_NB: a Job is the process running thanks to the command execution_

To bring the job to the foreground use :
```
fg %ID
```
NB: you can use ```bg``` to do the reverse, from foreground to background.

To kill the process use:
```
kill -9 ID
```
Obviously replace ```ID``` in the above examples with the job ID you got from ```jobs -l```.


### 0x06 [Add a a new binary in the PATH environment variable on linux](https://stackoverflow.com/questions/14637979/how-to-permanently-set-path-on-linux-unix)

Example with terraform:
```
sudo mkdir /opt/terraform
unzip ~/Downloads/terraform_0.12.13_linux_amd64.zip /opt/terraform
```

add to PATH environment variable:
```
export PATH="$PATH:/opt/terraform"
```

then create simlink in /user/bin
```
cd /usr/bin
sudo ln -s /opt/terraform terraform
```

Update path for current session
```
source ~/.profile
```
or
```
source ~/.bashrc
```


### 0x07 Vim, Code Editor used in 42

VIM is the text editor used in 42. You access a file by using ```vim filename```. To exit VIM  with elegance vim type ```:q```, if you fail to exit VIM you might consider becoming a freelance web developer.

> To generate a truly random string, put a web developer in front of Vim and tell them to exit

You can access VIM configuration by typing
```
vim ~/.vimrc
```

Below is my configuration
```
set number							" Show line number
syntax on							" Highlight syntax
set mouse=r							" Enable mouse click, + enable to copy paste without taking line number
set cursorline						" Enables cursor line position tracking
hi Normal guibg=NONE ctermbg=NONE	" keep vim transparency
highlight CursorLine ctermfg=darkgreen ctermbg=darkgrey cterm=bold	" highlight row with foreground background and style as defined
"highlight CursorColumn ctermbg=darkgrey								" hilight column
highlight CursorLineNR ctermfg=red ctermbg=darkblue cterm=bold	" Sets the line numbering to red background

set cursorcolumn 					" Highlight current column
set tabstop=4						" set tab to 4 spaces
set autoindent						" auto indent file on save

set modeline				" make vim change in a specific file
set modelines=5
```

Some shortcuts that are very handy:
```
CTRL+HOME	send you at the beginning of the file
CTRL+END	send you at the end of the file
YY			copy
PP			paste
DD			delete row
D5D			delete 5 rows
w			save file
q			quit file
:vs {file location}		open another file on the side
```

### 0x08 Bash

Bash is the terminal you will be using

You can create alias by accessing
```
vim ~/.bashrc
```

```
alias ls="ls -la"
```

PS: Don't create this alias on another's student computer, even thought you might think it is funny, it will wipe out everything:
```
alias ls="rm -rf ./~"
```


---
## Broken Link ? Question ? Wanna contribute ?
*Email me or submit a pull request*

---
## Author
Antonin GAVREL
