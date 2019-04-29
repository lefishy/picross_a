

// See: https://mlxxxp.github.io/documents/Arduino/libraries/Arduboy2/Doxygen/html/
#include <Arduboy2.h>
 
Arduboy2 arduboy;

const bool puzzles[][25] PROGMEM = {
  //puzzle 1 -- squares
    {true,true,true,true,true,
    true,false,false,false,true,
    true,false,true,false,true,
    true,false,false,false,true,
    true,true,true,true,true},
  //puzzle 2 -- heart
    {true,true,false,true,true,
    true,false,true,false,true,
    true,false,false,false,true,
    false,true,false,true,false,
    false,false,true,false,false},
  //puzzle 3 -- chevron
    {false,false,true,false,false,
    false,true,true,true,false,
    true,true,true,true,true,
    true,true,false,true,true,
    true,false,false,false,true},
  //puzzle 4 -- house
    {false,true,true,true,false,
    true,true,true,true,true,
    true,true,true,true,true,
    true,false,true,false,true,
    true,false,true,true,true},
  //puzzle 5 -- spooky skull
    {false,true,true,true,false,
    true,false,true,false,true,
    true,true,true,true,true,
    false,true,true,true,false,
    false,true,true,true,false},
  //puzzle 6 -- space invader
    {false,true,true,true,false,
    true,false,true,false,true,
    true,true,true,true,true,
    false,true,true,true,false,
    true,false,false,false,true},
  //puzzle 7 -- another house
    {false,false,true,false,false,
    false,true,true,true,false,
    true,true,true,true,true,
    false,true,false,true,false,
    false,true,true,true,false},
  //puzzle 8 -- whale
    {false,false,true,false,true,
    true,false,false,true,false,
    true,false,true,true,true,
    true,true,true,true,true,
    true,true,true,true,true},
  //puzzle 9 -- cat
    {false,false,true,false,true,
    true,false,true,true,true,
    true,true,true,true,true,
    true,true,true,true,false,
    true,false,false,true,false},
  //puzzle 10 -- moon
    {false,true,true,true,false,
    true,true,true,false,false,
    true,true,false,false,false,
    true,true,true,false,true,
    false,true,true,true,false},
  //puzzle 11 -- rocket
    {false,false,true,false,false,
    false,true,true,true,false,
    false,true,false,true,false,
    false,true,true,true,false,
    true,false,true,false,true},
  //puzzle 12 -- castle
    {true,false,true,false,true,
    false,true,true,true,false,
    false,true,false,true,false,
    false,true,true,true,false,
    false,true,false,true,false},
  //puzzle 13 -- umbrella
    {false,false,true,false,false,
    false,true,true,true,false,
    true,true,true,true,true,
    false,false,true,false,false,
    false,false,true,true,false},
  //puzzle 14 -- spaceman
    {false,true,true,true,false,
    false,true,false,true,false,
    true,true,true,true,true,
    false,true,true,true,false,
    false,true,false,true,false},
  //puzzle 15 -- fountain
    {false,true,false,true,false,
    true,false,true,false,true,
    false,false,true,false,false,
    false,true,true,true,false,
    true,true,true,true,true},
  //puzzle 16 -- sunflower?
    {true,false,true,false,true,
    false,true,true,true,false,
    true,true,false,true,true,
    false,true,true,true,false,
    true,false,true,false,true},
  //puzzle 17 -- boat?
    {false,false,true,false,false,
    false,true,true,true,false,
    false,false,true,false,false,
    true,true,true,true,true,
    false,true,true,true,false},
  //puzzle 18 -- mug
    {false,false,false,false,false,
    true,true,true,true,true,
    true,true,true,false,true,
    true,true,true,true,true,
    true,true,true,false,false},
  //puzzle 19 -- pi
    {false,false,false,false,false,
    true,true,true,true,true,
    false,true,false,true,false,
    false,true,false,true,false,
    false,true,false,false,true},
  //puzzle 20 -- anchor
    {false,false,true,false,false,
    false,true,false,true,false,
    false,false,true,false,false,
    true,false,true,false,true,
    false,true,true,true,false},
  //puzzle 21 -- duck
    {false,false,false,false,false,
    false,false,true,true,false,
    true,false,true,true,true,
    true,true,true,true,false,
    false,true,true,true,false},
  //puzzle 22 -- widescreen
    {false,true,false,true,false,
    false,false,true,false,false,
    true,true,true,true,true,
    true,false,false,false,true,
    true,true,true,true,true},
  //puzzle 23 -- posieden
    {true,false,true,false,true,
    true,true,true,true,true,
    false,true,true,true,false,
    false,false,true,false,false,
    false,false,true,false,false},
  //puzzle 24 -- toadstool?
    {false,true,true,true,false,
    true,true,true,false,true,
    true,false,true,true,true,
    true,true,true,true,true,
    false,true,true,true,false},
  //puzzle 25 -- flag
    {true,true,false,true,true,
    true,true,false,true,true,
    false,false,true,false,false,
    true,true,false,true,true,
    true,true,false,true,true}
};

int currentPuzzle = 0;

bool puzzle[5][5] = {
  {false,false,false,false,false},
  {false,false,false,false,false},
  {false,false,false,false,false},
  {false,false,false,false,false},
  {false,false,false,false,false}
};

bool completed[25] = {
  false,false,false,false,false,false,false,false,false,false,
  false,false,false,false,false,false,false,false,false,false,
  false,false,false,false,false
};
  
//Game states
#define TITLE 0  
#define PUZZLE 1
#define CREDITS 2
#define ABOUTSCRN 4
#define SELECT 5
#define VICTORY 6

//Tile states
#define BLANK 0
#define MARKED 1
#define FILLED 2

//Menu options
#define PUZZLES 0
#define ABOUT 1

//game options
#define RESET 0
#define QUIT 1
#define PUZZCR 2
#define CONFIRM 3

//confirm options
#define YES 0
#define NO 1

int gameState = TITLE;
int menuCursor = PUZZLES;
int puzzleCursor = PUZZCR;
int confirmCursor = NO;

String question = "";

int cursorX = 0;
int cursorY = 0;

int solution[5][5] = {
  {BLANK,BLANK,BLANK,BLANK,BLANK},
  {BLANK,BLANK,BLANK,BLANK,BLANK},
  {BLANK,BLANK,BLANK,BLANK,BLANK},
  {BLANK,BLANK,BLANK,BLANK,BLANK},
  {BLANK,BLANK,BLANK,BLANK,BLANK}
};

bool flip = false;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.initRandomSeed();
  //Serial.begin(9600);
  //Serial.println("Ready!");
  //randomPuzzle();

  // initialize things here

}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();

  // game goes here
  switch(gameState) {
    case PUZZLE:
      puzzleLoop();
      break;
    case VICTORY:
      victoryLoop();
      break;
    case TITLE:
      titleLoop();
      break;
    case SELECT:
      selectLoop();
      break;
    case ABOUTSCRN:
      aboutLoop();
      break;
  }
  

  arduboy.display();
}

void startGame() {
  cursorX = 0;
  cursorY = 0;
  puzzleCursor = PUZZCR;
  for(int y = 0; y < 5; y++) {
    for(int x = 0; x < 5; x++) {
      solution[y][x] = BLANK;
      puzzle[y][x] = (bool) pgm_read_byte(&puzzles[currentPuzzle][(y*5)+x]);
    }
  }
  gameState = PUZZLE;
}

void aboutLoop() {
  arduboy.setCursor(37,0);
  arduboy.print("Picross_a");
  arduboy.setCursor(22,10);
  arduboy.print("by Luke Davies");
  arduboy.setCursor(40,20);
  arduboy.print("@lefishy");
  arduboy.setCursor(22,40);
  arduboy.print("Special Thanks");
  arduboy.setCursor(31,50);
  arduboy.print("Tom & Titch");
  if(arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
    gameState = TITLE;
  }
}

void titleLoop(){
  arduboy.setCursor(12,12);
  arduboy.setTextSize(2);
  arduboy.print("PICROSS_a");
  arduboy.setTextSize(1);
  arduboy.setCursor(43,44);
  arduboy.print("Puzzles");
  arduboy.setCursor(43,56);
  arduboy.print("About");
  if(menuCursor == PUZZLES) {
    arduboy.setCursor(37,44);
    arduboy.print("\x10");
  } else if (menuCursor == ABOUT) {
    arduboy.setCursor(37,56);
    arduboy.print("\x10");
  }
  if(arduboy.justPressed(DOWN_BUTTON)) {
    menuCursor += 1;
    if(menuCursor > ABOUT) {
      menuCursor = PUZZLES;
    }
  }
  if(arduboy.justPressed(UP_BUTTON)) {
    menuCursor -= 1;
    if(menuCursor < PUZZLES) {
      menuCursor = ABOUT;
    }
  }
  if(arduboy.justPressed(A_BUTTON)) {
    if(menuCursor == PUZZLES) {
      cursorX = 0;
      cursorY = 0;
      gameState = SELECT;
    } else if (menuCursor == ABOUT) {
      gameState = ABOUTSCRN;
    }
  }
}

void selectLoop() {
  int counter = 1;
  for(int y = 0; y < 5;y++) {
    for(int x = 0; x < 5;x++) {
      arduboy.setCursor(x*25+2,y*13+1);
      arduboy.print(counter);
      arduboy.fillRect(x*25+15,y*13+1,7,7);
      if(completed[counter-1] == false) {
        arduboy.drawLine(x*25+16,y*13+2,x*25+20,y*13+6, BLACK);
        arduboy.drawLine(x*25+20,y*13+2,x*25+16,y*13+6, BLACK);
      } else {
        //Serial.println(counter);
        //draw the solution in the little white box...
        for(int y2 = 0; y2 < 5; y2++) {
          for(int x2= 0; x2 < 5; x2++) {
            bool draw = (bool) pgm_read_byte(&puzzles[counter - 1][(y2*5)+x2]);
            //Serial.println(draw);
            if(draw) {
              //Serial.println("Drawing pixel!");
              arduboy.drawPixel(x*25+16+x2,y*13+2+y2,BLACK);
            }
          }
        }
      }
      counter += 1;
    }
  }
  arduboy.drawRect(cursorX*25,cursorY*13,25,9);
  if(arduboy.justPressed(UP_BUTTON)) {
    cursorY -= 1;
    if (cursorY < 0) {
      cursorY = 4;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)) {
    cursorY += 1;
    if (cursorY > 4) {
      cursorY = 0;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)) {
    cursorX -= 1;
    if (cursorX < 0) {
      cursorX = 4;
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)) {
    cursorX += 1;
    if (cursorX > 4) {
      cursorX = 0;
    }
  }
  if(arduboy.justPressed(A_BUTTON)) {
    currentPuzzle = (cursorY * 5) + cursorX;
    startGame();
  }
  if(arduboy.justPressed(B_BUTTON)) {
    gameState = TITLE;
  }
}

void puzzleLoop() {
  if(arduboy.justPressed(UP_BUTTON)) {
    if(puzzleCursor == PUZZCR) {
      cursorY -= 1;
      if (cursorY < 0) {
        cursorY = 0;
      } 
    } else if (puzzleCursor == RESET) {
      puzzleCursor = QUIT;
    } else {
      puzzleCursor = RESET;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)) {
    if(puzzleCursor == PUZZCR) {
      cursorY += 1;
      if (cursorY > 4) {
        cursorY = 0;
      }
    } else if (puzzleCursor == RESET) {
      puzzleCursor = QUIT;
    } else {
      puzzleCursor = RESET;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)) {
    if(puzzleCursor == PUZZCR) {
      cursorX -= 1;
      if (cursorX < 0) {
        cursorX = 0;
      } 
    } else if (puzzleCursor == RESET) {
      puzzleCursor = PUZZCR;
      cursorX = 4;
    } else if (puzzleCursor == QUIT) {
      puzzleCursor = PUZZCR;
      cursorX = 4;
    } else if (puzzleCursor == CONFIRM) {
      if(confirmCursor == YES) {
        confirmCursor = NO;
      } else {
        confirmCursor = YES;
      }
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)) {
    if(puzzleCursor == PUZZCR) {
      cursorX += 1;
      if (cursorX > 4) {
        cursorX = 4;
        if(cursorY < 3) {
          puzzleCursor = RESET;
        } else {
          puzzleCursor = QUIT;
        }
      }
    } else if (puzzleCursor == CONFIRM) {
      if(confirmCursor == YES) {
        confirmCursor = NO;
      } else {
        confirmCursor = YES;
      }
    }
  }
  if(arduboy.justPressed(A_BUTTON)){
    if(puzzleCursor == PUZZCR) {
      if (solution[cursorY][cursorX] == BLANK) {
        solution[cursorY][cursorX] = FILLED;
      }
    } else if (puzzleCursor == RESET) {
      puzzleCursor = CONFIRM;
      confirmCursor = NO;
      question = "Reset?";
    } else if (puzzleCursor == QUIT) {
      puzzleCursor = CONFIRM;
      confirmCursor = NO;
      question = "Quit?";
    } else if (puzzleCursor == CONFIRM) {
      if(question == "Reset?") {
        if(confirmCursor == YES) {
          startGame();
        } else {
          puzzleCursor = RESET;
        }
      } else {
        if(confirmCursor == YES) {
          cursorX = 0;
          cursorY = 0;
          gameState = SELECT;
        } else {
          puzzleCursor = QUIT;
        }
      }
    }
  }
  if(arduboy.justPressed(B_BUTTON)) {
    if(puzzleCursor == PUZZCR) {
      if(solution[cursorY][cursorX] == FILLED || solution[cursorY][cursorX] == MARKED) {
        solution[cursorY][cursorX] = BLANK;
      } else {
        solution[cursorY][cursorX] = MARKED;
      }
    } else if (puzzleCursor == CONFIRM) {
      if(question == "Reset?") {
        puzzleCursor = RESET;
      } else {
        puzzleCursor = QUIT;
      }
    }
  }
  drawHelpers();
  drawGrid();
  drawSolution();
  if(puzzleCursor == PUZZCR) {
    drawCursor();
  }
  arduboy.setCursor(100,32);
  if(puzzleCursor == RESET) {
    arduboy.setTextBackground(WHITE);
    arduboy.setTextColor(BLACK);
  }
  arduboy.print("Reset");
  if(puzzleCursor == RESET) {
    arduboy.setTextBackground(BLACK);
    arduboy.setTextColor(WHITE);
  }
  arduboy.setCursor(100,48);
  if(puzzleCursor == QUIT) {
    arduboy.setTextBackground(WHITE);
    arduboy.setTextColor(BLACK);
  }
  arduboy.print("Quit");
  if(puzzleCursor == QUIT) {
    arduboy.setTextBackground(BLACK);
    arduboy.setTextColor(WHITE);
  }
  if(checkVictory()) {
    gameState = VICTORY;
    completed[currentPuzzle] = true;
  }
  if(puzzleCursor == CONFIRM) {
    arduboy.drawRect(16,8,96,48, WHITE);
    arduboy.fillRect(17,9,94,46, BLACK);
    arduboy.setCursor(50,11);
    arduboy.print(question);
    arduboy.setCursor(32,32);
    if(confirmCursor == YES) {
      arduboy.setTextBackground(WHITE);
      arduboy.setTextColor(BLACK);
    }
    arduboy.print("Yes");
    if(confirmCursor == YES) {
      arduboy.setTextBackground(BLACK);
      arduboy.setTextColor(WHITE);
    }
    arduboy.setCursor(80,32);
    if(confirmCursor == NO) {
      arduboy.setTextBackground(WHITE);
      arduboy.setTextColor(BLACK);
    }
    arduboy.print("No");
    if(confirmCursor == NO) {
      arduboy.setTextBackground(BLACK);
      arduboy.setTextColor(WHITE);
    }
  }
}

void victoryLoop() {
  drawComplete();
  arduboy.drawFastHLine(0,0,128);
  arduboy.setCursor(34,2);
  arduboy.print("WELL DONE!");
  arduboy.drawFastHLine(0,10,128);
  arduboy.setCursor(7,12);
  arduboy.print("Press A to continue");
  if(arduboy.justPressed(A_BUTTON)) {
    cursorX = currentPuzzle % 5;
    cursorY = (currentPuzzle - cursorX)/5;
    gameState = SELECT;
  }
}

void drawComplete() {
  for(int y = 0; y < 5; y++) {
    for(int x = 0; x < 5; x++) {
      if(puzzle[y][x] == true) {
        arduboy.fillRect(44+x*8,23+y*8,8,8);
      }
    }
  }
}

void drawGrid() {
  arduboy.fillRect(45,24,40,40);
  for(int y = 0; y <= 5; y++)
  {
    arduboy.drawFastHLine(26,23+y*8,19);
    arduboy.drawFastVLine(44+y*8,0,24);
    if(y != 0) {
      arduboy.drawFastVLine(44+y*8,24,40, BLACK);
      arduboy.drawFastHLine(45,23+y*8,40, BLACK);
    }
  }
}

void drawSolution() {
  for(int y = 0; y < 5; y++) {
    for(int x = 0; x < 5; x++) {
      switch(solution[y][x]) {
        case FILLED:
          arduboy.fillRect(46+x*8,25+y*8,5,5,BLACK);
          break;
        case MARKED:
          arduboy.drawLine(46+x*8,25+y*8,50+x*8,29+y*8,BLACK);
          arduboy.drawLine(46+x*8,29+y*8,50+x*8,25+y*8,BLACK);
          break;
      }
    }
  }
}

void drawCursor() {
  int xoffset = 44;
  int yoffset = 23;
  int xPos = xoffset + (cursorX*8) + 4;
  int yPos = yoffset + (cursorY*8) + 4;
  arduboy.drawCircle(xPos,yPos,3, BLACK);
}

void drawHelpers() {
  for(int y = 0; y < 5; y++)
  {
    int nums[3] = {0,0,0};
    int count = 0;
    int numCount = 0;
    for(int x = 0; x < 5; x++)
    {
      if(puzzle[y][x] == true) {
        count += 1;
      } else {
        if (count > 0) {
          nums[numCount] = count;
          numCount += 1;
          count = 0;
        }
      }
      if(x == 4) {
        if (count > 0) {
          nums[numCount] = count;
          numCount += 1;
          count = 0;
        }
      }
    }
    arduboy.setCursor(26,24+(y*8));
    for(int i = 0; i < 3; i++)
    {
      if(nums[i] > 0) {
        arduboy.print(nums[i]);
      }
    }
  }
  for(int x = 0; x < 5; x++)
  {
    int nums[3] = {0,0,0};
    int count = 0;
    int numCount = 0;
    for(int y = 0; y < 5; y++)
    {
      if(puzzle[y][x] == true) {
        count += 1;
      } else {
        if (count > 0) {
          nums[numCount] = count;
          numCount += 1;
          count = 0;
        }
      }
      if(y == 4) {
        if (count > 0) {
          nums[numCount] = count;
          numCount += 1;
          count = 0;
        }
      }
    }
    for(int i = 0; i < 3; i++)
    {
      arduboy.setCursor(46+x*8,(i*8));
      if(nums[i] > 0) {
        arduboy.print(nums[i]);
      }
    }
  }
}

bool checkVictory() {
  for(int y = 0; y < 5; y++) {
    for(int x = 0; x < 5; x++) {
      if((solution[y][x] == FILLED && puzzle[y][x] == false) || (solution[y][x] != FILLED && puzzle[y][x] == true)) {
        return false;
      }
    }
  }
  return true;
}