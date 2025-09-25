# Tic Tac Toe w/ Human and Basic AI player modes

## Getting it to run
Half my trouble with this project was getting it to run for the first time, post-fork.
I was getting some warnings about how inheritance was being read by the compiler. 
After asking Graeme, I switched my compiler from g++ to a Microsoft one (MSVC 14.29 x64 from Visual Studio 2019), and ensured I set c++20 as my project's standard.

## Todos
The Todos for implementing TicTacToe.cpp were really clear. I had the most trouble remembering the matrix setup in c++. 
Specifically, declaring the variable and assigning values to it on the same line. I eventually just looked it up and we were good.

## Adding Buttons to let the user choose their Playmode
My goal for playmode selection was to have two choices available at the start of each game. Once the first player makes a move, the options disappear, so the mode becomes locked until the match's end.
This wasn't too hard once I understood that the UI is re-rendered every frame, so having a conditional like "render these buttons only if the board is a clean slate" was all i needed.
<br><br>
I checked out the demo project to understand how to handle button clicks. It's essentially `if(button("button name")){ do thing; }`

That piece of code both renders the button, and allows for something to happen when its clicked.

## Update to Game.cpp and Game.h
In order to make my "vs Human" button work, I decided to make a function called removeAIPlayer(int) in the Game class that inverts the actions of setAIPlayer(int). I then call this new function whenever the "vs Human" button gets pressed.

# AI Player uses Negamax for decision making
After following along Graeme's in-class demo on Negamax, my AI could make moves, but not the best ones. So I reviewed Coding Train's [video on Minimax](https://www.youtube.com/watch?v=trKjYdBASyQ) to see where I went wrong. By the gods I spent a good 1.5 hrs reviewing that 25 min video. I then asked Graeme for help, and with time we found what made my AI quirky. The most finicky fix to catch was that I mistyped one value in a matrix for checking win conditions.
