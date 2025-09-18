#include "Application.h"
#include "imgui/imgui.h"
#include "classes/TicTacToe.h"

namespace ClassGame {
        //
        // our global variables
        //
        TicTacToe *game = nullptr;
        bool gameOver = false;
        int gameWinner = -1;

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        void GameStartUp() 
        {
            game = new TicTacToe();
            game->setUpBoard();
            //game->setAIPlayer(1);
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        void RenderGame() 
        {
                ImGui::DockSpaceOverViewport();

                ImGui::ShowDemoWindow();

                if (!game) return;
                if (!game->getCurrentPlayer()) return;
                
                ImGui::Begin("Settings");
                ImGui::Text("Current Player Number: %d", game->getCurrentPlayer()->playerNumber());
                ImGui::Text("Current Board State: %s", game->stateString().c_str());
                if(game->stateString() == game->initialStateString()){
                    ImGui::Text("Game Mode Selector:"); ImGui::SameLine();
                    if(ImGui::Button("vs Human") && game->gameHasAI()){
                        game->removeAIPlayer(1);
                    }
                    
                    ImGui::SameLine();
                    if(ImGui::Button("vs AI")){
                        game->setAIPlayer(1);
                    }
                }
                
                ImGui::Text("Current Mode: "); ImGui::SameLine(); ImGui::Text(game->_gameOptions.AIPlayer ? "AI" : "Human");

                if (gameOver) {
                    ImGui::Text("Game Over!");
                    ImGui::Text("Winner: %d", gameWinner);
                    if (ImGui::Button("Reset Game")) {
                        game->stopGame();
                        game->setUpBoard();
                        gameOver = false;
                        gameWinner = -1;
                    }
                }
                ImGui::End();

                ImGui::Begin("GameWindow");
                game->drawFrame();
                ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
            Player *winner = game->checkForWinner();
            if (winner)
            {
                gameOver = true;
                gameWinner = winner->playerNumber();
            }
            if (game->checkForDraw()) {
                gameOver = true;
                gameWinner = -1;
            }
            // else if(game->gameHasAI()){
            //     if(game->getCurrentPlayer()->playerNumber() == 1){
            //         game->updateAI();
            //     }
            // }
        }
}
