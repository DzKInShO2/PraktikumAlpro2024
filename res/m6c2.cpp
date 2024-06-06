#include <iostream>
using namespace std;

/* Karena tidak diberikan menggunakan
 * "enum" atau pre-processor jadi akan
 * digunakan const int sebagai penggantinya.
 */

/*
 * PSUEDO-ENUMS
 */

/* Game State */
const int GAME_STATE_PLAYING = 0; // When game is playing
const int GAME_STATE_LOSE = 1; // When game is lose
const int GAME_STATE_WIN  = 2; // When game is win

/*
 * STRUCTS
 */

/*
 *  Monster Struct,
 *  Manage monster's health,
 *  attack, defense and sprite
 */
struct Monster {
    int cur_health;
    int max_health;
    int attack;
    int defense;

    int turn;

    string name;
    string sprite;
};

/*
 * Item Struct,
 * Manage item
 */
struct Item {
    int health;
    int attack;
    int defense;

    string name;
};

/*
 * Player Struct,
 * Store player information
 */
struct Player {
    int health;
    int attack;
    int defense;

    int item_id;
    int turn;

    string name;
};

/*
 * Room Struct,
 * Store Room's Information
 */
struct Room {
    int monster_id;
    int item_id;

    bool has_branch;
    int prev;
    int next[2];

    string name;
};

/*
 * Game Struct,
 * Managing game related
 * aka all things!
 */
struct Game {
    int state;

    Player players[2];
    Monster monsters[2];
    Item items[2];

    Room rooms[7];
    int current_room_id;
};


/* 
 * FUNCTIONS
 */

/*
 * Create padding/character filled
 * string
 */
string strpad(int n, char c = ' ')
{
    string pad = "";
    for (int i = 0; i < n; ++i) pad += c;
    return pad;
}

/*
 * Get String Length
 */
int strlen(const string& text)
{
    if (text[0] == '\0') return 0;
    int len = 0;
    while (text[++len] != '\0') {}
    return len;
}

/*
 * Reverse string,
 * modify the original
 */
void strrev(string& text)
{
    string s;
    for (int i = strlen(text) - 1; i >= 0; --i)
        s += text[i];
    text = s;
}

/*
 * Create String From Integer
 */
string strint(int n)
{
    string s = "";

    while (n > 0) {
        s += (char)((n % 10) + 48);
        n /= 10.0f;
    }
    strrev(s);
    return s;
}

/*
 * Make Uppercase,
 * keep original
 * create new string
 */
string strup(string text)
{
    for (int i = 0; i < strlen(text); ++i)
        if (text[i] > '`' && text[i] < '{')
            text[i] -= 32;
    return text;
}

/* 
 * Draw Centered text
 */
void center_draw(const string& text,
                        int width = 51,
                        const string& border = "| |")
{
    string lpad = strpad(width/2 - strlen(border)
                            - (strlen(text)/2));
    string rpad = strpad(45 - (strlen(lpad) + strlen(text)));
    cout << border << lpad << text << rpad << border << endl;
}

void pause()
{
    cout << "Press any key to continue..." << endl;
    string arg; getline(cin, arg);
}

/*
 * Draw Bar
 */
void bar_draw()
{
    cout << "|+|=============================================|+|" << endl;
}

/*
 * Draw Map
 */
void map_draw(int room_id)
{
    cout << "                          (#)                      \n"
            "                           |                       \n"
            "                           |                       \n"
            "                          (#)                      \n"
            "                           |                       \n"
            "                           |                       \n"
            "                          (#)                      \n"
            "                          / \\_                     \n"
            "                         /     \\_                   \n"
            "                        /       (#)                \n"
            "                (#)---(#)        |                 \n"
            "                                /                  \n"
            "                               |                   \n"
            "                                \\                  \n"
            "                                (@)                \n";
    int line = 4, column = 28;

    switch (room_id) {
        case 1:
            line = 7;
        break;
        case 2:
            line = 10;
        break;
        case 3:
            line = 14;
            column = 24;
        break;
        case 4:
            line = 14;
            column = 18;
        break;
        case 5:
            line = 13;
            column = 34;
        break;
        case 6:
            line = 18;
            column = 34;
        break;
    }

    cout << "\e7";
    cout << "\33[" << line <<";" << column << "H!";
    cout << "\e8";
}

void item_info(const Item& item)
{
    if (item.health != 0) 
        center_draw("Health " +
            string{(item.health > 0 ? "Increased By " : "Decreased By ")}
            + strint(item.health));
    if (item.attack != 0)
        center_draw("Attack " +
            string{(item.attack > 0 ? "Increased By " : "Decreased By ")}
            + strint(item.attack));
    if (item.defense != 0)
        center_draw("Defense " +
            string{(item.defense > 0 ? "Increased By " : "Decreased By ")}
            + strint(item.defense));
}

/*
 * Use an item on player
 */
void item_use(const Item& item, Player& player)
{
    player.health += item.health;
    player.attack += item.attack;
    player.defense += item.defense;

    player.item_id = -1;

    cout << "\33[H\33[2J";
    bar_draw();
    center_draw(player.name + " Used " + item.name);
    item_info(item);
    bar_draw();
    pause();
}

/*
 * Initialize players,
 * monsters, items, and rooms
 */
Game *game_create()
{
    Game *game = new Game;
    game->state = GAME_STATE_PLAYING;
    game->current_room_id = 0;

    game->players[0] = { 
        1000, 150, 30,
        -1, 1,
        "Holil"
    };
    game->players[1] = {
        1000, 100, 75,
        -1, 1,
        "Gilang",
    };

    game->monsters[0] = {
        950, 950,
        140, 10, 1,
        "Phoenix",
        "\t\t    ///,        ////\n"
        "\t\t    \\ /,      / .>.\n"
        "\t\t     \\  /,   _/` /.\n"
        "\t\t      \\_ /_/  /.\n"
        "\t\t       \\_/  .<\n"
        "\t\t       /<<<<\\\\\n"
        "\t\t      /,)^>>.\\\\\n"
        "\t\t      (/   \\\\ /\\\\\\\n"
        "\t\t           //  ```` \n"
        "\t\t          ((``"
    };
    game->monsters[1] = {
        5000, 5000,
        350, 50, 1,
        "Leviathan",
        "\n"
        "\t\t         ,--._____,-.\n"
        "\t\t       ,___\\.--.,.--./\n"
        "\t\t    ((__@@/ /         \\\n"
        "\t\t   (.`\\@@/ / (|)' '(|) \\\n"
        "\t\t  *'@@ /|''\\--,:___:,--/\n"
        "\t\t/ @,--/|(~~`\\_ V   V _/\n"
        "\t\t|\"---< | \\    \\\\ _ //\n"
        "\t\t|>----<\\ @)    ;~~~;\n"
        "\t\t\\(>-----<\\@\")"
    };

    game->items[0] = {
        6999,
        0,
        0,
        "Health Potion"
    };
    game->items[1] = {
        0,
        6999,
        0,
        "Attack Potion"
    };

    game->rooms[0] = {
        -1, -1,    // Monster and Item
        false,     // Has Branch?
        -1,        // Previous Room
        { 1, -1 }, // Next Room(s)
        "000"
    };
    game->rooms[1] = {
        -1, -1,    // Monster and Item
        false,     // Has Branch?
        0,         // Previous Room
        { 2, -1 }, // Next Room(s)
        "111"
    };
    game->rooms[2] = {
        -1, -1,   // Monster and Item
        true,     // Has Branch?
        1,        // Previous Room
        { 3, 5 }, // Next Room(s)
        "222"
    };
    game->rooms[3] = {
        0, 0,      // Monster and Item
        false,     // Has Branch?
        2,         // Previous Room
        { 4, -1 }, // Next Room(s)
        "Skyreach Isle" 
    };
    game->rooms[4] = {
        -1, 1,      // Monster and Item
        false,      // Has Branch?
        3,          // Previous Room
        { -1, -1 }, // Next Room(s)
        "333" 
    };
    game->rooms[5] = {
        -1, -1,    // Monster and Item
        false,     // Has Branch?
        2,         // Previous Room
        { 6, -1 }, // Next Room(s)
        "555"
    };
    game->rooms[6] = {
        1, -1,     // Monster and Item
        false,      // Has Branch?
        5,          // Previous Room
        { -1, -1 }, // Next Room(s)
        "Abyssia Ocean"
    };

    return game;
}

/*
 * Destroy game when finished or lose
 */
void game_destroy(Game *game)
{
    delete game;
}

/*
 * Draw game to the screen
 */
void game_draw(const Game& game)
{
    cout << "\33[H\33[2J";
    bool no_monster = !(game.rooms[game.current_room_id].monster_id > -1);
    if (no_monster) {
        bar_draw();
        center_draw("Room : " + game.rooms[game.current_room_id].name);
    } else {
        center_draw("There's monster here...");
    }
    bar_draw();

    if (no_monster) {
        map_draw(game.current_room_id);
        if (game.rooms[game.current_room_id].item_id > -1) {
            const Item& item = game.items[game.rooms[game.current_room_id].item_id];
            bar_draw();
            center_draw("You found an item");
            center_draw(item.name);
            item_info(item);
            bar_draw();
            cout << strpad(8) << "Who's gonna take it?" << endl;
            cout << strpad(8) << " * " << game.players[0].name << endl;
            cout << strpad(8) << " * " << game.players[1].name << endl;
        } else {
            const Room& room = game.rooms[game.current_room_id];
            bar_draw();
            center_draw("There's nothing here...");
            bar_draw();
            if (room.next[0] != -1) {
                if (room.has_branch) {
                    cout << strpad(8) << "Choose next room..."
                         << endl;
                    cout << strpad(8) << "1. "
                         << game.rooms[room.next[0]].name
                         << endl;
                    cout << strpad(8) << "2. "
                         << game.rooms[room.next[1]].name
                         << endl;
                } else {
                    cout << strpad(8) << "Go next room = "
                         << game.rooms[room.next[0]].name
                         << endl;
                }
            } else {
                center_draw("There are no other room forward...");
                bar_draw();
            }
            cout << strpad(8) << "Go back" << endl;
        }
    } else {
        const Monster& monster = game.monsters[game.rooms[game.current_room_id].monster_id];
        cout << monster.sprite << endl;
        bar_draw();
        center_draw(monster.name);
        bar_draw();
        center_draw(strint(monster.max_health) + " : " + strint(monster.cur_health));
        center_draw("Atk : " + strint(monster.attack));
        center_draw("Def : " + strint(monster.defense));
        center_draw("Turn : " + strint(monster.turn));
        bar_draw();
        /* Player's Health */
        cout << "| |" << game.players[0].name + " : " + strint(game.players[0].health);
        cout << strpad(45 -(strlen(game.players[0].name + " : " + strint(game.players[0].health))
                            + strlen(strint(game.players[1].health) + " : " + game.players[1].name)));
        cout << strint(game.players[1].health) + " : " + game.players[1].name << "| |" << endl;
        /* Player's Attack */
        cout << "| |" << "Atk : " + strint(game.players[0].attack);
        cout << strpad(45 -(strlen("Atk : " + strint(game.players[0].attack))
                            + strlen(strint(game.players[1].attack) + " : Atk")));
        cout << strint(game.players[1].attack) + " : Atk" << "| |" << endl;
        /* Player's Defense */
        cout << "| |" << "Def : " + strint(game.players[0].defense);
        cout << strpad(45 -(strlen("Def : " + strint(game.players[0].defense))
                            + strlen(strint(game.players[1].defense) + " : Def")));
        cout << strint(game.players[1].defense) + " : Def" << "| |" << endl;
        /* Player's Turn */
        cout << "| |" << "Turn : " + strint(game.players[0].turn);
        cout << strpad(45 -(strlen("Turn : " + strint(game.players[0].turn))
                            + strlen(strint(game.players[1].turn) + " : Turn")));
        cout << strint(game.players[1].turn) + " : Turn" << "| |" << endl;

        /* Player's Turn Arrow */
        cout << "\e7";
        int turn = (game.players[0].turn + game.players[1].turn) % 2;
        if (turn == 0) {
            cout << "\33[21;" << (7 + strlen(game.players[0].name
                                    + strint(game.players[0].health))) << "H<==";
        } else if(turn == 1) {
            cout << "\33[21;" << (41 - strlen(game.players[0].name
                                    + strint(game.players[0].health))) << "H==>";
        }

        cout << "\e8";
        bar_draw();
        cout << strpad(8) << "1. Attack\n";
        cout << strpad(8) << "2. Heal\n";
        cout << strpad(8) << "3. Item\n";
    }
}

/*
 * Handle game events
 * like input, etc..
 */
void game_update(Game* game)
{
    while (true) {
        cout << ">>>>> ";
        string arg;
        getline(cin >> ws, arg);

        if (game->rooms[game->current_room_id].monster_id > -1) {
            int turn = (game->players[0].turn + game->players[1].turn) % 2;
            int monster_id = game->rooms[game->current_room_id].monster_id;
            bool valid = false;

            if (arg == "1") {
                if (turn == 0 && (game->players[0].turn) % 3 == 0) {
                    game->monsters[monster_id].cur_health -= (game->players[0].attack * 2);
                    cout << "\33[H\33[2J"; bar_draw();
                    center_draw(game->players[0].name + " Used Skill");
                    center_draw("\'ATK * 2 = 2ATK\'");
                    bar_draw(); pause();
                    cout << "\33[H\33[2J"; bar_draw();
                    center_draw(game->players[0].name);
                    center_draw("Deal Double Damage to " + game->monsters[monster_id].name);
                    bar_draw(); pause();
                } else {
                    game->monsters[monster_id].cur_health -= (game->players[turn].attack
                                                      - game->monsters[monster_id].defense);
                }
                valid = true;
            }
            if (arg == "2") {
                game->players[turn].health += 50;
                valid = true;
            }
            if (arg == "3") {
                if (game->players[turn].item_id != -1) {
                    item_use(game->items[game->players[turn].item_id],
                             game->players[turn]);
                    valid = true;
                } else {
                    cout << "\33[H\33[2J"; bar_draw();
                    center_draw(game->players[turn].name + " Has No Item!");
                    bar_draw(); pause();
                }
            }
            if (!valid) break;

            int saved_health = 0;
            if (turn == 1 && game->players[1].turn % 3 == 0) {
                saved_health = game->players[1].health;
            }

            if (game->monsters[monster_id].turn % 5 == 0) {
                for (int i = 0; i < 2; ++i)
                    game->players[i].health -= game->monsters[monster_id].attack;
                cout << "\33[H\33[2J"; bar_draw();
                center_draw(game->monsters[monster_id].name + " Used Skill");
                center_draw("\'Equals Under the Sky!\'");
                bar_draw(); pause();
                cout << "\33[H\33[2J"; bar_draw();
                center_draw(game->monsters[monster_id].name);
                center_draw("Deal Damages To All Players!");
                bar_draw(); pause();
            } else {
                game->players[turn].health -= (game->monsters[monster_id].attack
                                    - game->players[turn].defense);
                cout << "\33[H\33[2J";
                bar_draw();
                center_draw(game->monsters[monster_id].name + " Attacked " + game->players[turn].name);
                bar_draw();
                pause();
            }

            if (turn == 1 && game->players[1].turn % 3 == 0) {
                game->players[1].health = saved_health;

                cout << "\33[H\33[2J"; bar_draw();
                center_draw(game->players[1].name + " Used Skill");
                center_draw("\'Ih Apaan Sih!\'");
                bar_draw(); pause();
                cout << "\33[H\33[2J"; bar_draw();
                center_draw(game->players[1].name);
                center_draw("Ignore All Damage!");
                bar_draw(); pause();
            }

            game->players[turn].turn++;
            game->monsters[monster_id].turn++;

            if (game->monsters[monster_id].cur_health <= 0) {
                cout << "\33[H\33[2J";
                bar_draw();
                center_draw("Congratulations!");
                center_draw(game->monsters[monster_id].name + " Has Been Slayed!");
                bar_draw();

                game->rooms[game->current_room_id].monster_id = -1;
                game->players[0].turn = game->players[1].turn = 1;
                pause();

                for (int i = 0; i < 2; ++i)
                    game->players[i].health += 200;

                if (monster_id == 1)
                    game->state = GAME_STATE_WIN;
            }

            for (int i = 0; i < 2; ++i) 
                if (game->players[i].health <= 0)
                    game->state = GAME_STATE_LOSE;
            break;
        }

        if (game->rooms[game->current_room_id].item_id > -1) {
            bool found = false;
            for (int i = 0; i < 2; ++i)
                if (strup(game->players[i].name)
                    == strup(arg)) {
                    if (game->players[i].item_id == -1) {
                        game->players[i].item_id = game->rooms
                            [game->current_room_id].item_id;
                        game->rooms[game->current_room_id].item_id = -1;
                        found = true;
                        break;
                    } else {
                        cout << game->players[i].name
                             << "'s Inventory is full!"
                             << endl;
                    }
                }
            if (found) break;
            cout << "Player not found!" << endl;
            continue;
        }

        if (!game->rooms[game->current_room_id].has_branch) {
            if (arg == "go" || arg == "next") {
                if (game->rooms[game->current_room_id].next[0] == -1) {
                    break;
                }
                game->current_room_id = game->rooms[game->current_room_id].next[0];
                break;
            }
        } else {
            if (arg == "1") {
                game->current_room_id = game->rooms[game->current_room_id].next[0];
                break;
            }
            else if (arg == "2") {
                game->current_room_id = game->rooms[game->current_room_id].next[1];
                break;
            }
        }

        if (arg == "back" &&
            game->rooms[game->current_room_id].prev != -1) {
            game->current_room_id = game->rooms[game->current_room_id].prev;
            break;
        }
        break;
    }

    if (game->state == GAME_STATE_LOSE) {
        cout << "\33[H\33[2J";
        bar_draw();
        center_draw("One of you is dead");
        center_draw("LOSE");
        bar_draw();
        pause();
        game_destroy(game);
        game = game_create();
    }
}

/*
 * Entry Point
 */
int main()
{
    Game* game = game_create();
    
    while (game->state == GAME_STATE_PLAYING ||
           !(game->state == GAME_STATE_WIN)) {
        game_draw(*game);
        game_update(game);
    }
    game_destroy(game);

    cout << "\33[H\33[2J";
    bar_draw();
    center_draw("Congratulations!");
    center_draw("You've finished the game!");
    bar_draw();
    pause();
    return 0;
}
