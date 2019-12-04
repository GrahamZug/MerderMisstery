#ifndef __GAMELOOPCPP__
#define __GAMELOOPCPP__

#include "gameloop.hpp"

// Add some vars to be used below
std::string mapImgPath = "Art/MapSamples/SampleMap.png";
std::string playerImgPath = "Art/Player/PlayerSpriteSheet.png";
std::string interactImgPath = "Art/Messages/interact.png";
const int NPC_NUM = 12;
const int WORLD_OBJECT_NUM = 4;
const int PERSONALITY_TRAITS = 5;

//NPC Constants
const int NPC_WIDTH = 60;
const int NPC_HEIGHT = 88;

int npcdiscuss = 0;
bool discussbool = false;

NPClite* npcToNPClite(NPClite* town, NPC* npcs){
	for(int i = 0; i < NPC_NUM; i++){
		town[i].name = npcs[i].getName();
		for(int j = 0; j < PERSONALITY_TRAITS; j++){
			town[i].personality[j] = (npcs[i].getPersonality(j) + 100)/2; 
		}
	}
	return town;
}

// Return the seed so we can use it later if necessary
std::string simTown(NPClite *town, NPC* npcs, std::string seed){
  int seedint = -1;

  if(seed.compare("") == 0){ // If you don't have one, we'll just use the time
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string time_str(buffer);

    seed = time_str;
  }

  const char *seedCharray = seed.c_str();
  int i;
  for(i = 0; i < seed.length(); i++){
    seedint = ((seedCharray[i] * seedint) % M) + 1;
  }

  // Dunno if it has to be positive, but may as well.
  if(seedint < 1) seedint = (-1 * seedint) + 1;
  // There's literally only one case where this'd be an issue, so yannow
  if(seedint < 1) seedint = 1;

  int goodKill = 0;
	while(goodKill == 0){
		NPClite jarrett("Dennis", MERCHANT); //0
		NPClite kim("Dennis", MERCHANT); //1
		NPClite pope("Dennis", MERCHANT); //2
		NPClite gaben("Dennis", MERCHANT); //3
		NPClite marie("Dennis", WORKER); //4
		NPClite lary("Dennis", WORKER); //5
		NPClite luigi("Dennis", WORKER); //6
		NPClite albert("Dennis", WORKER); //7
		NPClite dennis("Dennis", MAYOR); //8
		NPClite helen("Dennis", POLICE); //9
		NPClite merge("Dennis", INNKEEPER); //10
		NPClite sigmund("Dennis", PRIEST); //11
		town[0] = jarrett;
		town[1] = kim;
		town[2] = pope;
		town[3] = gaben;
		town[4] = marie;
		town[5] = lary;
		town[6] = luigi;
		town[7] = albert;
		town[8] = dennis;
		town[9] = helen;
		town[10] = merge;
		town[11] = sigmund;
		npcToNPClite(town, npcs);
	        simulation(town, seedint);
    // Removing the goodMurder stuff for now, since it's causing weird issues
    //if(goodMurder(town))
      goodKill = 1;
	}

  return seed;
}

// Has to return the seed because we'll need it later
std::string init(NPC *npcs, SDL_Renderer *renderer, WorldObject *worldObjects, std::string seed, NPClite *town){
  // Runs the simulation. I know, it looks so innocuous. Kinda nifty, right?

  // Set up the front end NPCs
  //   Presumably this is where the backend info will be pushed to the front end
  // lust, loyal, wrath => green, blue, red
  // MarketPeople at the Market
  npcs[0].initSprite("Benedict", "Art/NPCs/Blacksmith.bmp", BROWN, GRAY, BLACK,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 1796, 1108);
  npcs[1].initSprite("Liam", "Art/NPCs/Jeweler.bmp", WHITE, GRAY, BLACK,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 1866, 1108);
  npcs[2].initSprite("Michael", "Art/NPCs/FishMonger.bmp", GREEN, DARK_BLUE, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 1936, 1108);
  npcs[3].initSprite("Kyle", "Art/NPCs/Farmer.bmp", LIGHT_GREEN, BLUE, ORANGE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2006, 1108);

  // Workers in the factory
  npcs[4].initSprite("David", "Art/NPCs/Worker1.bmp", ORANGE, DARK_BLUE, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2420, 748);
  npcs[5].initSprite("Erick", "Art/NPCs/Worker2.bmp", ORANGE, LIGHT_BLUE, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2490, 748);
  npcs[6].initSprite("Frank", "Art/NPCs/Worker3.bmp", ORANGE, BLACK, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2560, 748);
  npcs[7].initSprite("Gail", "Art/NPCs/Worker4.bmp", ORANGE, LIGHT_BLUE, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2630, 748);

  // Administrators in the town hall
  npcs[8].initSprite("Henry", "Art/NPCs/Mayor.bmp", WHITE, GRAY, DARK_GREEN,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 990, 482);
  npcs[9].initSprite("Isaac", "Art/NPCs/Fuzz.bmp", WHITE, DARK_BLUE, ORANGE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 1358, 685);

  // Barkeep at the bar
  npcs[10].initSprite("Jake", "Art/NPCs/Barkeep.bmp", LIGHT_RED, GRAY, WHITE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 1431, 1452);

  // Church Person at the Church
  npcs[11].initSprite("Charles", "Art/NPCs/Vicar.bmp", WHITE, WHITE, PURPLE,
                      renderer, NPC_WIDTH, NPC_HEIGHT, 2248, 1670);

  // Weapons
  worldObjects[0].initObject("Art/Merder Objects/bat.png", renderer, 960, 855, 100, 50, 5, 5, 100, 50);
  worldObjects[1].initObject("Art/Merder Objects/Hammer_1.png", renderer, 1371, 1660, 50, 80, 5, 5, 50, 80);
  worldObjects[2].initObject("Art/Merder Objects/Pickaxe_1.png", renderer, 2158, 1760, 80, 80, 5, 5, 80, 80);
  worldObjects[3].initObject("Art/Merder Objects/butcher_knife.png", renderer, 2510, 855, 80, 80, 0, 0, 70, 70);
  seed = simTown(town, npcs, seed);
  std::cout << "Your seed is: " << seed << std::endl;

  // Make one of them a ghost
  int i;
  for(i = 0; i < 12; i++){
    if(town[i].isDead){
      npcs[i].ghostThisNPC();
    }
  }

  return seed;
}

void gameloop(SDL_Event e, bool *quit, const Uint8 *keyState, SDL_Renderer* renderer, bool farnan, std::string seed, int player_x, int player_y, int itemList[4]){
    // Initialize world texture, player texture, and camera
    SDL_Texture *bg = loadFiles(mapImgPath, renderer);
    SDL_Texture *interactPromptingTex = loadFiles(interactImgPath, renderer);
    Player *player = new Player(playerImgPath, renderer, player_x, player_y);
    SDL_Rect cam = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    NPClite town[12];

    // Create the NPCs (offloaded for brevity)
    NPC npcs[NPC_NUM];
    WorldObject worldObjects[WORLD_OBJECT_NUM];
    init(npcs, renderer, worldObjects, seed, town);

    // Used for framerate independence
    int curr_time = 0;
    int last_time = 0;
    float time_change;
    int frames_rendered = 0;
    int fr_timer = 0;

    // Allocate buildings
    CyanBuilding cBuilding;   // West (Town Hall)
    BlueBuilding bBuilding;   // East (Factory)
    GreenBuilding gBuilding;  // South East (Church)
    YellowBuilding yBuilding; // South West (Residences?)
    RedBuilding rBuilding;    // North  (Murder *Ominous music playing*)
  //PurpleBuilding pBuilding; // Central (Courtyard)
    

    // Collision dectction variables
    SDL_Rect collide;
    SDL_Rect convCollide;
    int hasCollided = 0;
    int hasSolved = 0;
    //Enter Game Loop
    while(!(*quit)) {
        //SDL time and delta value
        last_time = curr_time;
        curr_time = SDL_GetTicks();
        time_change = (curr_time - last_time) / 500.0f;
        frames_rendered++;
        fr_timer += (curr_time - last_time);
        if(fr_timer >= 1000){
          std::cout << "fps: " << frames_rendered << std::endl;
          fr_timer = 0;
          frames_rendered = 0;
        }
        hasCollided = 0;
        //Really would rather export this to an event handling file
        while(SDL_PollEvent(&e) != 0)
        {
            //Quit application
            if(e.type == SDL_QUIT)
                (*quit) = true;
        }

        // Get the Keyboard State
        keyState = SDL_GetKeyboardState(NULL);

        // Open Chat room
        if (keyState[SDL_SCANCODE_C])
            enter_chat(e, &(*quit), keyState, renderer);

        // Open the inventory
        if (keyState[SDL_SCANCODE_I])
            open_inventory(e, &(*quit), keyState, renderer, itemList);

        //Talk to an NPC
        if (keyState[SDL_SCANCODE_X] && discussbool)
            hasSolved = enter_discussion(e, &(*quit), keyState, renderer, &(npcs[npcdiscuss]));

        // Quit may have changed during the dialogue, so it's best to check 
        if (*quit) {
            if (hasSolved == 0) {
                std::fstream save;
                save.open("save.txt", std::fstream::out);
                save << seed << "\n" << player->positionPNG.x << "\n" << player->positionPNG.y << "\n";
                save << itemList[0] << "\n" << itemList[1] << "\n" << itemList[2] << "\n" << itemList[3] << "\n";
                save.close();
            } else {
                remove("save.txt");
            }
            return;
        }

        //Move Player
        player->move(time_change, keyState, farnan);

        //Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Renders the background
        renderTexture(renderer, bg, cam, 0, 0, cam.w, cam.h, true);

        //render npcs
        int i=0;
        int indiscusscollider = 0;

        // check for collisions
        // Loop through twice to accomidate corner sections where the player may collide with 2 objects
        for (int axisI = 0; axisI < 2; axisI++){
          // Check NPC Collisions
          for(i = 0; i < NPC_NUM; i++){
              if (npcs[i].NPCCollider.checkCollision(&(player->positionPNG), &collide)){
                  hasCollided = 2;
              }
          }
          //Check building collisions
          if (cBuilding.checkCollision(&(player->positionPNG), &collide)) {
              hasCollided = 3;
          }
          if (bBuilding.checkCollision(&(player->positionPNG), &collide)) {
              hasCollided = 3;
          }
          if (gBuilding.checkCollision(&(player->positionPNG), &collide)) {
              hasCollided = 3;
          }
          if (yBuilding.checkCollision(&(player->positionPNG), &collide)) {
              hasCollided = 3;
          }
          if (rBuilding.checkCollision(&(player->positionPNG), &collide)) {
              hasCollided = 3;
          }
          if(hasCollided){
            player->alterPosition(&collide);
          } else {
            axisI = 2;
          }
          hasCollided = 0;
        }

        //render NPC's and check for conversation
        for(i = 0; i < NPC_NUM; i++){
            npcs[i].renderToScreen(renderer, time_change, cam);
            if (npcs[i].NPCConversationCollider.checkCollision(&(player->positionPNG), &convCollide)){
                int w, h;
                SDL_QueryTexture(interactPromptingTex, NULL, NULL, &w, &h);
                // Just pass in collide as a dummy arg, we don't use it
                renderTexture(renderer, interactPromptingTex, collide, 10, 10, w, h, false);
                npcdiscuss = i;
                indiscusscollider = true;
            }
        }

        if (itemList[0] == 0) {
            worldObjects[0].renderToScreen(renderer, cam);
        }
        if (itemList[1] == 0) {
            worldObjects[1].renderToScreen(renderer, cam);
        }
        if (itemList[2] == 0) {
            worldObjects[2].renderToScreen(renderer, cam);
        }
        if (itemList[3] == 0) {
            worldObjects[3].renderToScreen(renderer, cam);
        }

        //Check if we need to pick up some items
        if (worldObjects[0].checkCollision((&player->positionPNG), &collide)) {
            itemList[0] = 1;
        }
        if (worldObjects[1].checkCollision((&player->positionPNG), &collide)) {
            itemList[1] = 1;
        }
        if (worldObjects[2].checkCollision((&player->positionPNG), &collide)) {
            itemList[2] = 1;
        }
        if (worldObjects[3].checkCollision((&player->positionPNG), &collide)) {
            itemList[3] = 1;
        }

        // Only can discuss if we're within range
        discussbool = indiscusscollider;

        setCameraPosition(&cam, player->positionPNG);

        // Render Player
        player->render(renderer, &cam);

        // Check Collisions
        player->collision(renderer, keyState);

        //Update Screen
        SDL_RenderPresent(renderer);
    }
}

#endif
