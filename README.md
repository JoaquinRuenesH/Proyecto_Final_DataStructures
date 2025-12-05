# Graph-Based Exploration Game Engine - Data Structures Project

A flexible, text-based dungeon crawler game engine built in C++ featuring graph-based map exploration, turn-based combat, and custom data structure implementations. The core system is theme-agnostic and supports any custom scenario through configuration files. Included themes: Batman (Gotham City) and Spider-Man (NY) variants.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Data Structures](#data-structures)
- [Game Mechanics](#game-mechanics)
- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Creating Custom Themes](#creating-custom-themes)
- [File Formats](#file-formats)
- [Class Documentation](#class-documentation)
- [Algorithms](#algorithms)
- [Authors](#authors)

---

## Overview

This is a final project for the Data Structures and Algorithms course that implements a **theme-agnostic exploration game engine**. The core architecture separates game logic from content, allowing you to create unlimited scenarios by simply writing map and monster configuration files.

### Core Engine Features:
- **Graph-based map system** with weighted edges representing distances between locations
- **Turn-based combat system** with heroes fighting enemies
- **Custom data structure implementations** (LinkedList, Queue, Graph)
- **Pathfinding algorithms** (BFS, Dijkstra's Algorithm)
- **Save game functionality** with stat export
- **Fully customizable content** through text-based configuration files

### Included Example Themes:
- **Batman Theme**: Navigate Gotham City locations (Arkham Asylum, The Batcave, etc.) and defeat iconic Batman villains
- **Spider-Man Theme**: Navigate NY City locations (Times Square, The Art Gallery, etc.) and defeat iconic Spider-Man villains
- **Your Own**: Create any theme you want - fantasy dungeons, sci-fi space stations, horror mansions, etc.

---

## Features

### Core Gameplay
- Explore interconnected locations represented as a weighted graph
- Encounter enemies with varying difficulty and spawn probabilities
- Turn-based combat with attack, defense, and special abilities
- Reward system for defeating enemies
- Win condition: reach the treasure location
- Game state persistence and statistics export

### Technical Features
- **Theme-agnostic architecture**: Game engine completely separated from content
- **Easy customization**: Create new scenarios by editing text files (no code changes needed)
- Template-based generic data structures
- Graph algorithms for pathfinding and exploration
- Probabilistic enemy encounters
- Combat system with hero abilities and cooldowns
- File-based configuration for maps and monsters
- Dynamic memory management with proper cleanup

---

## Project Structure

```
Proyecto_Final_DataStructures/
│
├── main.cpp                          # Entry point - initializes and runs the game
│
├── Core Game Systems
│   ├── Execution.h / Execution.tpp   # Game initialization, file loading, stat export
│   ├── GameSave.h / GameSave.tpp     # Game state management, movement, combat triggers
│   ├── CombatSystem.h / CombatSystem.tpp  # Turn-based combat logic
│
├── Game Entities
│   ├── Hero.h / Hero.tpp             # Hero class with stats and abilities
│   ├── Monster.h / Monster.tpp       # Monster class with stats and spawn probability
│   ├── Square.h / Square.tpp         # Graph node representing a location
│
├── Data Structures
│   ├── Graph.h / Graph.tpp           # Adjacency list graph with BFS/Dijkstra
│   ├── LinkedList.h / LinkedList.tpp # Singly linked list template
│   ├── Queue.h / Queue.tpp           # Queue for BFS traversal
│   ├── Node.h / Node.tpp             # Generic node for linked structures
│
├── Game Data Files
│   ├── mapBatman.txt                 # Gotham City Batman map configuration
│   ├── mapSpiderMan.txt              # NY Spider-Man map configuration
│   ├── monstersBatman.txt            # Batman villain roster
│   ├── monstersSpiderMan.txt         # Spider-Man villain roster
│   ├── finalStats.txt                # Exported game statistics (generated)
│
├── Documentation
│   ├── README.md                     # This file
│   └── Exploration Videogame Gotham's Map.pdf  # Visual map reference
│   └── NYCSpiderManMap.pdf  # Visual map reference
```

---

## Data Structures

### Custom Implementations

#### 1. **Node** (`Node.h`, `Node.tpp`)
- **Purpose**: Generic node for linked data structures
- **Template Type**: `T` - data type stored in node
- **Key Methods**:
  - `getData()` / `setData()`: Access/modify node data
  - `getNext()` / `setNext()`: Manage node links

#### 2. **LinkedList** (`LinkedList.h`, `LinkedList.tpp`)
- **Purpose**: Singly linked list for dynamic collections
- **Template Type**: `T` - element type
- **Key Methods**:
  - `pushFront(val)`: Add element to front (O(1))
  - `getNode(val)`: Find node by value (O(n))
  - `elementAt(index)`: Access by index (O(n))
  - `getSize()`: Count elements (O(n))
  - `printLL()`: Display all elements
- **Usage**: Store adjacency lists, neighbors, defeated monsters

#### 3. **Queue** (`Queue.h`, `Queue.tpp`)
- **Purpose**: FIFO queue for BFS traversal
- **Template Type**: `T` - element type
- **Key Methods**:
  - `enqueue(val)`: Add to rear (O(1))
  - `dequeue()`: Remove from front (O(1))
  - `isEmpty()`: Check if empty (O(1))
  - `clear()`: Empty the queue (O(n))
- **Usage**: BFS graph traversal in pathfinding

#### 4. **Graph** (`Graph.h`, `Graph.tpp`)
- **Purpose**: Weighted undirected graph representing the game map
- **Template Type**: `T` - vertex identifier type (string)
- **Key Components**:
  - Adjacency list representation using `LinkedList<Square<T>*>`
  - Stores treasure location and monster assignments
- **Key Methods**:
  - `addSquare(name)`: Add vertex/location
  - `addEdge(v1, v2, weight)`: Connect locations with distance
  - `addMonster(square, monster)`: Assign monster to location
  - `addTreasure(square)`: Mark treasure location
  - `cheatBFS(start)`: BFS traversal from start to treasure
  - `dijkstra(start)`: Shortest path from start to treasure
- **Usage**: Represents the entire game world

---

## Game Mechanics

### Map Exploration
- Player moves between connected squares (graph vertices)
- Each move consumes a turn and may trigger encounters
- View available neighbors before moving
- Cheat codes available: BFS shortest path view, Dijkstra fastest path view

### Combat System
- **Turn Order**: Hero attacks first, then monster counterattacks
- **Damage Calculation**: `damage = attacker.ATK - defender.DEF`
- **Hero Abilities**:
  - **Cooldown Ability**: Special attack (limited uses)
  - **Temporary Upgrade**: Stat boost for one combat
- **Victory Conditions**:
  - Defeat monster: gain reward points, unlock movement
  - Lose combat: game over
- **Monster Encounters**: Probabilistic based on monster spawn rates

### Progression
- Defeat monsters to earn reward points
- Upgrade hero stats between encounters
- Track defeated monsters (stored in LinkedList)
- Reach the treasure square to win
- Game exports final statistics to `finalStats.txt`

---

## Installation & Compilation

### Prerequisites
- C++11 or later compiler (g++, clang++)
- macOS, Linux, or WSL on Windows

### Compilation

```bash
# Navigate to project directory
cd "/Users/escuela/Documents/Tercer Semestre IRS/Estructura de Datos/Proyecto_Final_DataStructures"

# Compile with g++
g++ main.cpp -o main
```

## Usage

### Running the Game

```bash
# Run with selected map
./main

# Output will guide you through:
# 1. Game initialization
# 2. Map loading from mapBatman.txt
# 3. Monster roster loading from monstersBatman.txt
# 4. Interactive gameplay prompts
```

### Gameplay Commands
During execution, the game will prompt you to:
- **View neighbors**: See connected locations
- **Move to location**: Enter location index
- **Fight enemies**: Automatic when encountered
- **Use abilities**: Prompted during combat
- **View stats**: After every move
- **Get hints**: Using keywords "showdijkstra" and "showbfs"

### Switching Themes

The game engine loads any theme by specifying the monster and map files:

```cpp
// In main.cpp, change the file names:

// Batman theme (Gotham City)
execution.start("monstersBatman.txt", "mapBatman.txt");

// Spider-Man theme
execution.start("monstersSpiderMan.txt", "mapSpiderMan.txt");

// Your custom theme
execution.start("monstersMyTheme.txt", "mapMyTheme.txt");
```

No other code changes needed! The engine adapts to any content you provide.

---

## Creating Custom Themes

You can create **unlimited scenarios** without modifying any C++ code. Just create two configuration files following the formats below.

### Quick Start: Create Your Own Theme

1. **Design your world**: Sketch locations and connections
2. **Create monsters file**: `monstersYourTheme.txt` (CSV format)
3. **Create map file**: `mapYourTheme.txt` (graph structure)
4. **Update main.cpp**: Point to your new files
5. **Compile and play!**

### Example Custom Themes

#### Fantasy RPG Theme
```
monstersFantasy.txt → Dragon, Goblin, Orc, Dark Wizard
mapFantasy.txt → Enchanted Forest, Dragon's Lair, Dark Castle, Village
```

#### Sci-Fi Space Theme
```
monstersSci-Fi.txt → Alien Warrior, Robot Guard, Mutant, AI Core
mapSci-Fi.txt → Engine Room, Command Bridge, Airlock, Cargo Bay
```

#### Horror Mansion Theme
```
monstersHorror.txt → Ghost, Vampire, Zombie, Demon
mapHorror.txt → Basement, Library, Attic, Graveyard
```

### Theme Design Tips
- **Locations**: 8-15 squares work well for gameplay balance
- **Connections**: Create multiple paths (avoid linear progression)
- **Enemy Difficulty**: Use probability (0.3-1.0) to control challenge
- **Treasure Placement**: Put it 4-6 edges from start for optimal gameplay
- **Balance**: Ensure ATK/DEF values create winnable but challenging fights

---

## File Formats

### Monster/Enemy File Format
**Filename**: Any name (e.g., `monsters[Theme].txt`)  
**Format**: CSV with header row

```csv
id,name,HP,ATK,DEF,probability,reward
1,Killer Croc,100,10,15,0.9,2
2,Harley Queen,100,50,45,0.85,5
3,The Joker,100,90,90,1,0
```

**Column Descriptions**:
- **id**: Unique integer identifier (1, 2, 3, ...)
- **name**: Enemy display name (any string, spaces allowed)
- **HP**: Health points (recommended: 50-150)
- **ATK**: Attack damage (recommended: 10-100)
- **DEF**: Defense/damage reduction (recommended: 10-90)
- **probability**: Spawn chance when entering location (0.0 to 1.0)
  - `1.0` = always appears (boss fights)
  - `0.5` = 50% chance to spawn
  - `0.3` = rare encounter
- **reward**: Points awarded to hero on defeat (0 for bosses, 1-10 for others)

**Design Guidelines**:
- Create 5-15 different enemies per theme
- Final boss should have `probability = 1.0` and `reward = 0`
- Balance: Early enemies ~30 ATK, late enemies ~70+ ATK
- Use probability to control difficulty curve

---

### Map File Format
**Filename**: Any name (e.g., `map[Theme].txt`)  
**Format**: Three sections (counts, vertices, edges)

```
10                          # Line 1: Total number of locations/squares
13                          # Line 2: Total number of connections/edges
The Sewers,1                # Lines 3+: Square name, enemy ID
The Playground,2
The City Hall,3
...
The Batcave,-1              # Starting location (use -1 for no enemy)
The Batcave,The Sewers,1    # After all squares: Edges (location1,location2,weight)
The Batcave,The Playground,7
...
```

**Section 1: Counts**
- Line 1: Integer - number of locations
- Line 2: Integer - number of edges

**Section 2: Vertices/Locations**
- Format: `LocationName,EnemyID`
- **LocationName**: Any string (spaces allowed, avoid commas)
- **EnemyID**: Matches `id` from monster file
  - Use `-1` for starting location (must be safe)
  - Use `id` to assign a specific enemy
  - Treasure location is defined by being the last square listed

**Section 3: Edges/Connections**
- Format: `Location1,Location2,Weight`
- **Weight**: Distance/cost (1-10 recommended, integer)
- Edges are **undirected** (bidirectional by default)
- Connect each location to 2-4 neighbors for best gameplay

**Design Guidelines**:
- **Start**: First square with `-1` as enemy ID
- **Treasure**: Last square in the vertices list
- **Balance**: Avoid dead-ends (every square should have 2+ neighbors)
- **Difficulty curve**: Place weaker enemies closer to start, bosses near treasure
- **Paths**: Create multiple routes to encourage exploration

### Statistics Export (`finalStats.txt`)
Auto-generated after game completion (any theme):
```
Hero: Batman
Final HP: 85
Enemies Defeated: Killer Croc, Harley Queen
Moves Taken: 12
Result: Victory
```

This file captures gameplay statistics regardless of theme.

---

## Class Documentation

### `Execution`
**Purpose**: Game controller and file loader

**Key Methods**:
- `start(monstersFile, mapFile)`: Initialize and run game
- `uploadMonsters(filename)`: Parse monster CSV
- `uploadMap(filename)`: Parse map configuration
- `exportStats(player)`: Write game results to file

---

### `GameSave<T>`
**Purpose**: Manages current game state and player actions

**Key Methods**:
- `move(index)`: Move to neighbor by index
- `move(name)`: Move to neighbor by name
- `showNeighbors()`: Display available moves
- `fightMonster()`: Trigger combat if monster present
- `treasureCheck()`: Check win condition
- `printDijkstra()`: Show easiest path to treasure (based on edge weight)
- `printCheatBFS()`: Show shortest path to treasure
- `saveCurrentGameStatus()`: Persist game state
- `isGameOver()`: Check if game ended

---

### `Hero`
**Purpose**: Player character with stats and inventory

**Attributes**:
- `id`, `name`: Identification
- `HP`, `ATK`, `DEF`: Combat stats
- `rewardPoints`: Currency from victories
- `coolDownAbility`, `temporaryUpgrade`: Ability states
- `monstersDefeated`: LinkedList of defeated enemies

**Key Methods**:
- Getters/setters for all attributes
- `displayInfo()`: Print hero stats

---

### `Monster`
**Purpose**: Enemy/adversary entity with spawn probability (theme-agnostic)

**Attributes**:
- `id`, `name`: Identification (name can be any enemy type)
- `HP`, `ATK`, `DEF`: Combat stats
- `probability`: Encounter chance (0.0-1.0)
- `reward`: Points awarded to hero on defeat

**Key Methods**:
- Getters/setters for all attributes
- `displayInfo()`: Print enemy stats

**Note**: Despite the class name, this represents any enemy type depending on your theme (monsters, villains, aliens, robots, etc.)

---

### `CombatSystem`
**Purpose**: Turn-based battle logic

**Key Methods**:
- `fight()`: Run combat loop until conclusion
- `turns()`: Execute rounds until conclusion (round = hero + monster attack)
- `herosTurn()`: Hero attack phase
- `monstersTurn()`: Monster counterattack
- `upgrade()`: Apply permanent stat increases
- `useCoolDownAbility()`: Activate special attack
- `useTemporaryUpgrade()`: Apply temporary buff

---

### `Square<T>`
**Purpose**: Graph vertex representing a game location (theme-agnostic)

**Attributes**:
- `name`: Location identifier (adapts to any theme)
- `visited`, `visitedBFS`: Traversal tracking
- `monster`: Assigned enemy (nullptr if none)
- `treasure`: Win condition flag
- `neighbors`: LinkedList of adjacent squares
- `encounterProbability`: Chance of enemy spawn

**Key Methods**:
- `setMonster()`, `getMonster()`: Enemy assignment
- `setTreasure()`, `isTreasure()`: Treasure flag
- `setVisited()`, `isVisited()`: Movement tracking

---

### `Graph<T>`
**Purpose**: Game world representation and pathfinding

**Key Methods**:
- `addSquare(name)`: Create new location
- `addEdge(v1, v2, weight, directed)`: Connect locations
- `addMonster(square, monster)`: Place enemy
- `addTreasure(square)`: Set win location
- `cheatBFS(start)`: Breadth-first traversal display
- `dijkstra(start)`: Shortest path to treasure

---

## Algorithms

### Breadth-First Search (BFS)
- **File**: `Graph.tpp` → `cheatBFS()`
- **Purpose**: Explore all reachable locations from start and recreate the shortest path to the treasure
- **Complexity**: O(V + E)
- **Data Structure**: Queue for frontier
- **Output**: Prints traversal order
- **Game Use**: "Cheat code" to reveal map layout

### Dijkstra's Shortest Path
- **File**: `Graph.tpp` → `dijkstra()`
- **Purpose**: Find optimal path from start to treasure
- **Complexity**: O((V + E) log V) with priority queue (simplified here)
- **Output**: Prints shortest distances and path
- **Game Use**: "Cheat code" to show optimal route

### Combat Resolution
- **File**: `CombatSystem.tpp` → `fight()`, `turns()`
- **Logic**:
  1. Hero attacks: `monsterHP -= max(0, heroATK - monsterDEF)`
  2. Check monster defeat
  3. Monster counterattacks: `heroHP -= max(0, monsterATK - heroDEF)`
  4. Check hero defeat
  5. Repeat until one side reaches 0 HP
- **Special Cases**: Abilities modify ATK/DEF

---

## Authors

- Ricardo Morán Ávila (A01661056)
- Joaquín Ruenes Hernández (A01661196)
- **Course**: Data Structures and Algorithms (TC1031)
- **Semester**: Third Semester
- **B.S.**: Robotics and Digital Systems Engineering
- **Institution**: Instituto Tecnológico y de Estudios Superiores de Monterrey Campus Ciudad de México 
- **Repository**: [JoaquinRuenesH/Proyecto_Final_DataStructures](https://github.com/JoaquinRuenesH/Proyecto_Final_DataStructures)

---

## Notes

### Architecture
- **Theme-agnostic design**: The entire game engine is content-independent. All theme-specific elements (location names, enemy names, stats) are loaded from configuration files.
- **No hardcoded content**: You can create any scenario without touching C++ code - just edit the `.txt` files.
- All template implementations are in `.tpp` files included by headers
- Memory management uses raw pointers with manual `delete` - ensure proper cleanup
- The graph is represented as an adjacency list for efficient neighbor queries

### Technical Details
- Enemy encounters use probabilistic spawning based on `probability` attribute
- The game uses `srand(time(nullptr))` for randomness (consider upgrading to `<random>` for better distribution)
- Class names (`Monster`, `Hero`) are generic terms - interpret them contextually based on your theme

---

## Known Issues & Future Improvements

### Current Limitations
- First random number may cluster around 0.6 due to `srand(time())` granularity
  - **Fix**: Use `std::mt19937` with `std::chrono::high_resolution_clock`
- No graphical interface (text-based only)
- Limited save/load functionality (only final stats export)

### Potential Enhancements
- **Content-side** (no code needed):
  - Create more example themes (fantasy, sci-fi, horror, historical, etc.)
  - Design larger, more complex maps
  - Create difficulty variants (easy/normal/hard theme packs)
  
- **Engine-side** (code enhancements):
  - Implement priority queue for optimized Dijkstra's algorithm
  - Add multiple heroes with different abilities
  - Implement item/inventory system
  - Add more complex combat mechanics (elemental damage, status effects)
  - Create a GUI using SFML or Qt
  - Add multiplayer support
  - Implement A* pathfinding for smarter enemy AI
  - Support for directed edges (one-way passages)
  - Dynamic enemy scaling based on hero level

---

## License

This project is an academic assignment for educational purposes.

---

**Last Updated**: December 2025
