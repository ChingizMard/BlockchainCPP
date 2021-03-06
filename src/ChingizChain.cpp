#include "Block.h"
#include "ChingizChain.h"
#include <iostream>
#include <vector>

//Static Variables
std::vector<Block> ChingizChain::blockchain;
int ChingizChain::difficulty = 4;

bool ChingizChain::checkValidity()
{
    Block currentBlock;
    Block previousBlock;
    std::string target(difficulty, '0'); 

    for (unsigned int i = 1; i < blockchain.size(); i++){
        currentBlock = blockchain[i];
        previousBlock = blockchain[i-1];

        //Check if current block is valid
        if (currentBlock.getHash() != currentBlock.calculateHash()){
            std::cout << "Wrong block hash." << std::endl;
            std::cout << currentBlock.getHash() << std::endl;
            std::cout << currentBlock.calculateHash() << std::endl;
            return false;
        }

        //Compare previous block hash
        if (previousBlock.getHash() != currentBlock.getPreviousHash()){
            std::cout << "Wrong previous block hash." << std::endl;
            return false;
        }

        //Check if the block is mined
        if(currentBlock.getHash().substr( 0, difficulty) != (target)) {
            std::cout << "This block hasn't been mined" << std::endl;
            return false;
		}
    }
  
    return true;
}

