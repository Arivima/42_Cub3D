42Roma
--------------------------------------------------------------------------------------------------------------------------------
Projet_name:    Cub3D
Team_members:   avilla-m, gdi-lore

Subject:        './Cub3D_en.subject.pdf'
Correction:     './Cub3D_correction.pdf'
Grade:          125%
Bonus:          collision, doors, mouse rotation, sprite, minimap
Extra:          levels, game flow, textured floor, win with collectibles, die with enemies, gif animation, textured background
--------------------------------------------------------------------------------------------------------------------------------

How to play:    .exe

Game sreens:    0           mandatory project
                1           opening gif screen to bonus part
                2           Earth level
                3           transition gif screen to next level
                4           Moon level
                5           game over gif screen
                6           game won screen
                7           credits

Game controls:  'W'         move forward
                'S'         move backward
                'A'         move left
                'D'         move right
                'left arr'  rotate view to left
                'right arr' rotate view to right
                'ENTER'     open and close doors (need to be in adjacent bloc, facing the door)
                'SPACE BAR' enter bonus part
                'ESC'       close the window
                'red cross' close the window

Game rules:     5 collectibles to next level or to win, collision with enemy = death

Make rules:     make            compiles if objects modified
                make fclean     cleans all objects and executables
                make re         cleans objects and re-compiles objects and .h, including libraries
                make bis        re-compiles objects and .h, not libraries
                make run        make bis + executes with the right arguments
                make norme      check for norm errors only in relevant folders, only lists errors
                make sanitize   make with sanitize flag, for debugging
                linux make rules are commented

How to update visuals:
./maps:         the map can be changed, updated with textures, colors, map structure can be changed
./files:        here to change the textures of the game levels:
                Any updated texture has to be copied into these:
                background_earth (must be 1920 * 1080)
                background_moon (must be 1920 * 1080)
                wall_earth
                wall_moon
                door_mandatory
                door_earth
                door_moon
                floor_earth
                floor_moon
                collectible_mandatory
                collectible_earth
                collectible_moon
                enemy_mandatory
                enemy_earth
                enemy_moon
                .png image were converted to .xpm, added to ./files and path added to "# define IMG_FILES" in ./include/cub3D.h + enum e_picture_list updated at the right position

How to update project parameters:
                Go the .h and update there
