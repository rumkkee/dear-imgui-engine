# Tic Tac Toe w/ Human and AI player modes

# Getting it to run
Half my trouble with this project was getting it to run for the first time, post-fork.
I was getting some warnings about how inheritance was being read by the compiler. 
After asking Graeme, I switched my compiler from g++ to a Microsoft one (MSVC 14.29 x64 from Visual Studio 2019), and ensured I set c++20 as my project's standard.

# Todos
The Todos for implementing TicTacToe.cpp were really clear. I had the most trouble remembering the matrix setup in c++. 
Specifically, declaring the variable and assigning values to it on the same line. I eventually just looked it up and we were good.

# Adding Buttons to let the user choose their Playmode
My goal for playmode selection was to have two choices available at the start of each game. Once the first player makes a move, the options disappear, so the mode becomes locked until the match's end.
This wasn't too hard once I understood that the UI is re-rendered every frame, so having a conditional like "render these buttons only if the board is a clean slate" was all i needed.
<br><br>
I checked out the demo project to understand how to handle button clicks. It's essentially `if(button("button name")){ do thing; }`

That piece of code both renders the button, and allows for something to happen when its clicked.
