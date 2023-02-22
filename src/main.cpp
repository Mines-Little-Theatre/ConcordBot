#include <iostream>
#include <string>

#include <dpp/dpp.h>

#include "cluster.h"
#include "dispatcher.h"
#include "intents.h"
#include "util.h"

int main(int argc, const char** argv){
    if(argc != 2){
        std::cerr << "Usage: ConcordBot [tokenEnvKey]" << std::endl;
        return -1;
    }
    
    std::string token;
    const bool tokenResult = getEnvValue(argv[1], token);


    if(!tokenResult){
        std::cerr << "Failed to read API key from: " << argv[1] << std::endl;
        return -1;
    }


    uint64_t intents = dpp::i_default_intents | dpp::i_message_content;


    dpp::cluster concordbot(token, intents);

    concordbot.on_log(dpp::utility::cout_logger());

    concordbot.on_message_create([&concordbot] (const dpp::message_create_t& event){
            if(event.msg.author.is_bot()){
                return;
            }

            // need non const message
            std::string message = event.msg.content;

            bool containsConcord = false, containsUpdate = false, containsLicense = false;

            processMessage(message, containsConcord, containsUpdate, containsLicense);


            if(containsConcord && containsUpdate && containsLicense){
                event.reply("No.", false);
                return;
            }

            if(containsConcord && containsUpdate){
                event.reply(chooseRandomAutoReply(), false);
                return;
            }

            if(containsConcord){

                concordbot.message_add_reaction(event.msg, chooseRandomReaction());
            }


    });

    concordbot.start(dpp::st_wait);


}
