# ChessGameConsole
A console game of chess that follows blitz chess rules.

This game that I created follows blitz chess rules. In other words, there is no need for either player to say check or checkmate; the game simply ends when either king is taken. 
Since the game is on the console, the player enters his/her moves using algebraic notation. For example, "e2e4" moves the pawn on "e2" to "e4", which is a typical starting move 
in the game of chess. After each move is entered, if the move is valid, it will be printed as characters on the console; if not, the user is requested to enter a different move. Also, a White kingside castle is specified as "e1g1", and a black queenside castle is specified as "e8c8". There is no notion of capture in the notation, and there is no 'x' required (simply list the starting square and ending square). Similarly, for promotion, simply list the starting and ending square, and you'll later be prompted for the type of piece to promote to.

To run this game, after cloning the repository simply open it with Visual Studio. Then, use Visual Studio's "Start without debugging option" while on "main.cpp" to run the game. Alternatively, open the Visual studio solution, and you should be able to start the project without debugging starting from the "main.cpp" file.
