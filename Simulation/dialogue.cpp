#include "simulation.cpp"

const int DIALOGUE_OPTION_COUNT = 36;
const int NUMBER_OF_STATES = 9;
const int DIALOGUE_OPTIONS_PER_STATE = 4;
const int CHOOSE_NPC_MODE = 1;


enum dishonesty{
	LITERALLY_CANNOT_LIE = 5,
	SOMEWHAT_DISHONEST = 25,
	VERY_DISHONEST = 50,
	EXTREMELY_DISHONEST = 75,
};

enum stateOptions{
	INITIAL_STATE,
	NEXT_INITIAL_STATE,
	NPCS1,
	NPCS2,
	NPCS3,
	NPCS4,
	ACTION1,
	ACTION2,
	ACTION3,
};

enum dialogueOptions{
	NPC0,
	NPC1,
	NPC2,
	NPC3,
	NPC4,
	NPC5,
	NPC6,
	NPC7,
	NPC8,
	NPC9,
	NPC10,
	NPC11,
	HOWFEEL,
	WHENSEEN,
	HEARD,
	DONEWITH,
	WHATLIKE,
	MOSTRECENT,
	FILLER,
};

class dialogueOption{
	public:
		int nextTag;
		int tag;
		std::string option;

	dialogueOption(){
		nextTag = -1;
		tag = -1;
		option = "Graham programmed me wrong - so now I am saying this.";
	}

	dialogueOption(std::string words, int identifier, int nextIdentifier){
		nextTag = nextIdentifier;
		tag = identifier;
		option = words;
	}
	~dialogueOption();
};

class dialogueOptionList{
	public:
		dialogueOption** options;
	
	dialogueOptionList(){
		options = new dialogueOption*[DIALOGUE_OPTIONS_PER_STATE];
		options[0] = new dialogueOption("Graham programmed me wrong - so now I am saying this.",-1,-1);
		options[1] = new dialogueOption("Graham programmed me wrong - so now I am saying this.",-1,-1);
		options[2] = new dialogueOption("Graham programmed me wrong - so now I am saying this.",-1,-1);
		options[3] = new dialogueOption("Graham programmed me wrong - so now I am saying this.",-1,-1);
	}
	
	dialogueOptionList(dialogueOption* zero, dialogueOption* one, dialogueOption* two, dialogueOption* three){ //constructor
		options = new dialogueOption*[DIALOGUE_OPTIONS_PER_STATE];
		options[0] = zero;
		options[1] = one;
		options[2] = two;
		options[3] = three;
}
	dialogueOption getOption(int choice){
		return *options[choice];
	}
	
	void printState(){
		for(int i = 0; i < DIALOGUE_OPTIONS_PER_STATE; i++)
			std::cout << i << ") " << options[i]->option << "\n";
	}
	

};

/*dialogueOption* dialogueHash(int key){
		

	switch(key){
		case INITIAL:
		return new dialogueOption(q1, q2, q3, nextInitial);
	}
}*/

std::string response(int option){
	switch(option){

	}
}

dialogueOptionList* initializeOptions(NPClite* town){
	
	dialogueOption* o0 = new dialogueOption("Who dislikes X?", HOWFEEL, NPCS1);
	dialogueOption* o1 = new dialogueOption("When was the last time you saw X?", WHENSEEN, NPCS1);
	dialogueOption* o2 = new dialogueOption("What is the gossip about X?",HEARD, NPCS1);
	dialogueOption* o4= new dialogueOption("Who has X...?", DONEWITH, ACTION1);
	dialogueOption* o5= new dialogueOption("What is X like?", WHATLIKE, NPCS1);
	dialogueOption* o6= new dialogueOption("What is X's profession?", MOSTRECENT, NPCS1);
	
	dialogueOption* t0 = new dialogueOption(town[0].name, NPC0, INITIAL_STATE);
	dialogueOption* t1 = new dialogueOption(town[1].name, NPC1, INITIAL_STATE);
	dialogueOption* t2 = new dialogueOption(town[2].name, NPC2, INITIAL_STATE);
	dialogueOption* t3 = new dialogueOption(town[3].name, NPC3, INITIAL_STATE);
	dialogueOption* t4 = new dialogueOption(town[4].name, NPC4, INITIAL_STATE);
	dialogueOption* t5 = new dialogueOption(town[5].name, NPC5, INITIAL_STATE);
	dialogueOption* t6 = new dialogueOption(town[6].name, NPC6, INITIAL_STATE);
	dialogueOption* t7 = new dialogueOption(town[7].name, NPC7, INITIAL_STATE);
	dialogueOption* t8 = new dialogueOption(town[8].name, NPC8, INITIAL_STATE);
	dialogueOption* t9 = new dialogueOption(town[9].name, NPC9, INITIAL_STATE);
	dialogueOption* t10 = new dialogueOption(town[10].name, NPC10, INITIAL_STATE);
	dialogueOption* t11 = new dialogueOption(town[11].name, NPC11, INITIAL_STATE);

	dialogueOption* a0 = new dialogueOption("Asked for distance from?", ASKFORDISTANCE, NPCS1);
	dialogueOption* a1 = new dialogueOption("Flirted with?", FLIRT, NPCS1);
	dialogueOption* a2 = new dialogueOption("Dated?", DATE, NPCS1);
	dialogueOption* a3 = new dialogueOption("Done things you can't do in CS1666 to?", SEX, NPCS1);
	dialogueOption* a4 = new dialogueOption("Broken up with?", BREAKUP, NPCS1);
	dialogueOption* a5 = new dialogueOption("Looked at, as if plotting theft?", ENVY, NPCS1);
	dialogueOption* a6 = new dialogueOption("Robbed?", ROB, NPCS1);
	dialogueOption* a7 = new dialogueOption("Verbally fought?", VERBALFIGHT, NPCS1);
	dialogueOption* a8 = new dialogueOption("Physically fought?", PHYSICALFIGHT, NPCS1);

	dialogueOption* n1 = new dialogueOption("NEXT", FILLER, NEXT_INITIAL_STATE);
	dialogueOption* n2 = new dialogueOption("NEXT", FILLER, INITIAL_STATE);	
	
	dialogueOption* nNPC1 = new dialogueOption("NEXT", FILLER, NPCS2);
	dialogueOption* nNPC2 = new dialogueOption("NEXT", FILLER, NPCS3);
	dialogueOption* nNPC3 = new dialogueOption("NEXT", FILLER, NPCS4);
	dialogueOption* nNPC4 = new dialogueOption("NEXT", FILLER, NPCS1);

	dialogueOption* nA1 = new dialogueOption("NEXT", FILLER, ACTION2);
	dialogueOption* nA2 = new dialogueOption("NEXT", FILLER, ACTION3);
	dialogueOption* nA3 = new dialogueOption("NEXT", FILLER, ACTION1);
	
	
	dialogueOption** options = new dialogueOption*[DIALOGUE_OPTION_COUNT];

	options[0] = o0;
	options[1] = o1;
	options[2] = o2;
	options[3] = n1;
	options[4] = o4;
	options[5] = o5;
	options[6] = o6;
	options[7] = n2;

	options[8] = t0;
	options[9] = t1;
	options[10] = t2;
	options[11] = nNPC1;
	options[12] = t3;
	options[13] = t4;
	options[14] = t5;
	options[15] = nNPC2;
	options[16] = t6;
	options[17] = t7;
	options[18] = t8;
	options[19] = nNPC3;	
	options[20] = t9;
	options[21] = t10;
	options[22] = t11;
	options[23] = nNPC4;
	options[24] = a0;
	options[25] = a1;
	options[26] = a2;
	options[27] = nA1;
	options[28] = a3;
	options[29] = a4;
	options[30] = a5;
	options[31] = nA2;
	options[32] = a6;
	options[33] = a7;
	options[34] = a8;
	options[35] = nA3;
	
	
	dialogueOptionList* globalList = new dialogueOptionList[NUMBER_OF_STATES];
	
	for(int i = 0; i < NUMBER_OF_STATES; i++)	
		globalList[i] = dialogueOptionList(options[i*DIALOGUE_OPTIONS_PER_STATE],options[i*DIALOGUE_OPTIONS_PER_STATE+1],options[i*DIALOGUE_OPTIONS_PER_STATE+2],options[i*DIALOGUE_OPTIONS_PER_STATE+3]);
	
	return globalList;
}
std::string eventConverterDialogue(int event){
	switch(event){
		case CDATE:
			return "was being romantic with";
		case FLIRT:
			return "was flirting with";
		case INTRODUCE:
			return "was getting to know";
		case DATE:
			return "had just started dating";
		case BREAKUP:
			return "had just broken up with";
		case SEX:
			return "was doing things you can't talk about in CS1666 with";
		case SOCIALIZE:
			return "has chatted with";
		case ENVY:
			return "has glared, as if plotting theft, at";
		case ROB:
			return "has been accused of robbery by";
		case VERBALFIGHT:
			return "got into a shouting match with";
		case PHYSICALFIGHT:
			return "was throwing hands with";
		case LIE:
			return "was telling a story to";
		case ASKFORDISTANCE:
			return "was asking for distance from";
		}
	return "performed an unperformable action on";
}

std::string eventConverterAskEvent(int event){
	switch(event){
		case FLIRT:
			return "has flirted with";
		case INTRODUCE:
			return "knows";
		case DATE:
			return "has dated";
		case BREAKUP:
			return "has broken up with";
		case SEX:
			return "has done thing you can't talk about in CS1666 with";
		case ENVY:
			return "has glared, as if plotting theft, at";
		case ROB:
			return "has been accused of robbery by";
		case VERBALFIGHT:
			return "has gotten into a shouting match with";
		case PHYSICALFIGHT:
			return "thrown hands with";
		case LIE:
			return "was telling a story to";
		case ASKFORDISTANCE:
			return "has asked for distance from";
		}
	return "performed an unperformable action on";
}

std::string getTime(int time){
	if((CLOCK - time) < 4)
		return "a few hours ago.";
	if((CLOCK - time) < 8)
		return "yesterday.";
	if((CLOCK - time) < 12)
		return "two days ago.";
	return "more than two days ago.";
}
std::string doneWith(NPClite* town, int npc, int beingInterrogated, int event){
	std::string action = "";	
	if(town[beingInterrogated].observations.getSize()){	
		for(int i = 0; i < town[beingInterrogated].observations.getSize(); i++){
			if(event == ASKFORDISTANCE || event == ENVY || event == ROB){	
				if(!town[beingInterrogated].observations.getMemory(i)->npcName1.compare(town[npc].name))
					action = action + " " + town[beingInterrogated].observations.getMemory(i)->npcName2;
			} 
		}
	}
}
std::string howFeel(NPClite* town, int npc, int beingInterrogated){
	std::string dislike = "";
	bool nobody = true;
	for(int i = 0; i < TOWN_SIZE; i++){
		if(hasDoneEventMutual(town,INTRODUCE,beingInterrogated,i) && town[i].relationships[npc] < 0){			
			if(nobody){
				if(i != beingInterrogated){
					nobody = false;			
					dislike = dislike + town[i].name;
				}else if (town[beingInterrogated].personality[DISHONESTY] < VERY_DISHONEST){
					nobody = false;
					dislike = dislike + "I";
				}
			}
			else if(i != beingInterrogated)			
				dislike = dislike + " and " + town[i].name;
			else if (town[beingInterrogated].personality[DISHONESTY] < VERY_DISHONEST){
				dislike = dislike + " and I";
			}
		}
	}
	dislike = dislike + " dislike(s) " + town[npc].name + ".\n";
	if(nobody)
		dislike = "I don't know anyone who dislikes " + town[npc].name + ".\n";
	return dislike;
}

std::string heard(NPClite* town, int npc, int beingInterrogated){
	if(npc == beingInterrogated)
		return "People usually don't gossip about me.";
	std::string lastMemory = "I don't know any gossip about " + town[npc].name;
	int event = -1;
	Event* e = new Event();

	for(int i = town[beingInterrogated].hearSay.getSize(); i > -1; i--){
		if(wasInvolvedInEvent(town,town[beingInterrogated].hearSay.getMemory(i),npc)){
			event = town[beingInterrogated].hearSay.getMemory(i)->event;
			e = town[beingInterrogated].hearSay.getMemory(i);
			break;
		}
	}

	if(event != -1){
		lastMemory = "I heard " + e->npcName1 + " was " + eventConverterDialogue(event) + " " + e->npcName2 + ".";		
	}
	return lastMemory;
}

std::string whenSeen(NPClite* town, int npc, int beingInterrogated){
	std::string lastMemory = "I can't remember when I last saw " + town[npc].name;
	int event = -1;
	int eventTime = -1;
	Event* e = new Event();
	bool wasObservation = false;
	for(int i = town[beingInterrogated].memories.getSize(); i > -1; i--){
		if(wasInvolvedInEvent(town,town[beingInterrogated].memories.getMemory(i),npc)){
			event = town[beingInterrogated].memories.getMemory(i)->event;
			eventTime = town[beingInterrogated].memories.getMemory(i)->time;
			e = town[beingInterrogated].memories.getMemory(i);
			break;
		}
	}
	for(int i = town[beingInterrogated].observations.getSize(); i > -1; i--){
		if(wasInvolvedInEvent(town,town[beingInterrogated].observations.getMemory(i),npc) && town[beingInterrogated].observations.getMemory(i)->time > eventTime){
			event = town[beingInterrogated].observations.getMemory(i)->event;
			eventTime = town[beingInterrogated].observations.getMemory(i)->time;
			e = town[beingInterrogated].observations.getMemory(i);
			wasObservation = true;
			break;
		}
	}
	if(event != -1){
	if(!e->npcName1.compare(town[beingInterrogated].name)){
		lastMemory = ". I was " + eventConverterDialogue(event) + " " + e->npcName2 + ". That was " + getTime(eventTime);
	return lastMemory;		
	}
	if(!e->npcName2.compare(town[beingInterrogated].name)){
		lastMemory = e->npcName1 + " was " + eventConverterDialogue(event) + " me. That was " + getTime(eventTime);
	return lastMemory;	
	}
		lastMemory = e->npcName1 + " was " + eventConverterDialogue(event) + " " + e->npcName2 + ". That was " + getTime(eventTime);
	}
	return lastMemory;
}

int getNPC(NPClite* town, dialogueOptionList* globalOptionList, int dialogueState, int input){
	globalOptionList[dialogueState].printState(); //THIS NEEDS TO BE BLIT'D TO THE SCREEN
	std::cin >> input;//EDIT THIS IN THE ACTUAL IMPLEMENTATION
	while(input % 4 == 3){
		dialogueState = globalOptionList[dialogueState].options[input]->nextTag;
		globalOptionList[dialogueState].printState(); //THIS NEEDS TO BE BLIT'D TO THE SCREEN
		std::cin >> input;//EDIT THIS IN THE ACTUAL IMPLEMENTATION
			}
	return globalOptionList[dialogueState].options[input]->tag;
}

int main(){
	unsigned int seed = time(NULL);
	srand(seed);
	if(SEED)
		std::cout << "Seed: " << seed << "\n";
	//townies
	NPClite jarrett("Jarrett Billingsley", MAYOR); //0
	NPClite kim("Kim Cardassian", POLICE); //1
	NPClite pope("Pope Benedict IX", PRIEST); //2
	NPClite gaben("Gabe Newall", INNKEEPER); //3
	NPClite marie("Marie Curie", MERCHANT); //4
	NPClite lary("Lary the Qcumber", MERCHANT); //5
	NPClite luigi("Luigi", MERCHANT); //6
	NPClite albert("Albert Einstein", MERCHANT); //7
	NPClite dennis("Dennis Preger", WORKER); //8
	NPClite helen("Helen of Troy", WORKER); //9
	NPClite merge("Marge Simpzon", WORKER); //10
	NPClite sigmund("Sigmund Frued", WORKER); //11
	NPClite town[TOWN_SIZE] = {jarrett, kim, pope, gaben, marie, lary, luigi, albert, dennis, helen, merge, sigmund};

	bool murder = false;

	while(!murder){
		if(CLOCK%4 == 0){
			wakeUp(town);
			}
		tick(town);
		if(didMurder(town))
				break;
		if(CLOCK == 200){
			std::cout<<"\nThe members of the town are too kind. No one was murdered. \n";
			murder = true;
		}
	}
	if(SEED){	
		std::cout << "Seed: " << seed << "\n";
	}
	if(EVENT_MODE){
		for(int i = 0; i < TOWN_SIZE; i++){
			for(int j = 0; j < town[i].memories.getSize(); j++)
				printEvent(town[i].memories.getMemory(j));
		std::cout << "\n";
		}
	}
	if(HEARSAY_MODE){
		for(int i = 0; i < TOWN_SIZE; i++){
			for(int j = 0; j < town[i].hearSay.getSize(); j++)
				printEvent(town[i].hearSay.getMemory(j));
		std::cout << "\n";
		}
	}
	if(OBSERVATION_MODE){
		for(int i = 0; i < TOWN_SIZE; i++){
			for(int j = 0; j < town[i].observations.getSize(); j++)
				printEvent(town[i].observations.getMemory(j));
		std::cout << "\n";
		}
	}
	dialogueOptionList* globalOptionList = initializeOptions(town);	
	int dialogueState = INITIAL_STATE;
	int npcBeingInterrogated = 0;
	int input = -1;
	int currentQuestion = -1;
	int currentNPC = -1;
	while(npcBeingInterrogated != -1){
		if(CHOOSE_NPC_MODE){
			std::cout << "\n" << "Who to Interrogate?" << "\n";
			for(int i = 0; i < TOWN_SIZE; i++)
				std::cout << i << ") " << town[i].name << "\n";
			std::cin >> npcBeingInterrogated;
		}
		input = -1;
		globalOptionList[dialogueState].printState(); //THIS NEEDS TO BE BLIT'D TO THE SCREEN
		while(input < 0 || input > 3){
			std::cin >> input;//EDIT THIS IN THE ACTUAL IMPLEMENTATION			
		}
		int tag = globalOptionList[dialogueState].options[input]->tag;
		dialogueState = globalOptionList[dialogueState].options[input]->nextTag;
		std::string output = "";
		if(tag == HOWFEEL){
			int npc = getNPC(town,globalOptionList,dialogueState,input);
			output = howFeel(town, npc, npcBeingInterrogated);			
		}
		if(tag == WHENSEEN){
			int npc = getNPC(town,globalOptionList,dialogueState,input);
			output = whenSeen(town,npc,npcBeingInterrogated);	
		}
		if(tag == HEARD){
			int npc = getNPC(town,globalOptionList,dialogueState,input);
			output = heard(town,npc,npcBeingInterrogated);
		}
		if(tag == DONEWITH){
			int npc = getNPC(town,globalOptionList,dialogueState,input);
			output = doneWith(town,npc,npcBeingInterrogated,3);	
		}
			std::cout << output;
			dialogueState = globalOptionList[dialogueState].options[input]->nextTag; 
	}	
	return 0;
}
