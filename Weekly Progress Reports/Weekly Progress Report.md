# SynthBuddy Weekly Progress Report
#Report date: 2024-10-17

## Last Week (time in hours)
	Team Review
		- We began to generate potential project ideas and discuss the best way to set up a collaboration site. A definitive project has already been chosen but generating additonal projects to "pick" is a bit more tricky then expected.
	Eric Sanman
		- Began to set up collaboration site and look into using KiCad (3)
	Chuong Vo
		- Began researching the best processor to use for the project and the differences between arduino microcontrollers and Atmel microcontrollers (2)
	Sierra Buckley
		- watching kicad videos and becoming familiar with it (2)
		- researching effects pedals for our design (2)
	Chris Crider
	
##Next Week
	Team Plan
		- Set up the collaboration site and finalize the proposal for three different projects and choose one.
		- Begin to brainstorm ideas and write the Product Design Specification
	Eric Sanman
		- Become more familiar with Kicad and Markdown (3)
		- Begin to create a preliminary Class-D amplifier design in KiCad (4)
	Chuong Vo
		- Finalize research of microcontrollers and report findings to team (2)
		- Choose a microcontrollers and begin research on potential libraries that could be used to for the synthesizer (2)
	Sierra Buckley
		- choose filters to design, model in LTspice (4)
	Chris Crider
	
##Blocked
	Eric Sanman
		- none
	Chuong Vo
		- Nothing blocked
	Sierra Buckley
		- none
	Chris Crider
	
	
# PWM Hybrid Synth Weekly Progress Report
#Report date: 2024-10-24

## Last Week (time in hours)
	Team Review
		- The collaboration site was officially launched and the three projects, pick one assignment was submitted
		- Work began on the Product Design Specification after a group meeting on 10-17-24 with good progress being made but it is still being written up.
	Eric Sanman
		- Created collaboration site
        - Gave team a basic introduction and overview of Git
        - Continued to work on Class-D amplifier design in KiCad (finalize layout, ground stiching, etc.) (4)
        - Select and order parts for amplifier from DigiKey (2)
        - Ordered Class-D amplifier from OSH Park (.5)
	Chuong Vo
		- Finalized microcontroller research and chose the best option to use for the Synth project (an ESP32 WRoom using Arduino) (2)
		- Began to looking into Arduino libaries for PWM and signal generation(1)
	Sierra Buckley
		- chose filters to design, modeled in LTspice (4)
		- git tutorial from Eric :) (1)
		- also sick (?)
	Chris Crider
	
##Next Week
	Team Plan
		- Set up the collaboration site and finalize the proposal for three different projects and choose one.
		- Begin to brainstorm ideas and write the Product Design Specification
		- Begin assembling Breadboard Prototype
	Eric Sanman
		- Receive board from OSH Park and parts from DigiKey
        - Begin built & test of Class-D amplifier
        - Work with the team on integrating other modules in KiCad
	Chuong Vo
		-Finalize research of Arduino libaries for PWM/Signal Generation (2)
		-Begin to watch tutorials to understand KiCad usage (2)
		-Begin making a basic schematic for the ESP32 (1)
	Sierra Buckley
		- Redo work on PDS, block diagrams (2)
		- get healthy (?)
	Chris Crider
	
##Blocked
	Eric Sanman
		- Wait for amplifier board to arrive
        - Wait for parts to arrive
	Chuong Vo
		-Nothing blocked
	Sierra Buckley
		- none
	Chris Crider
	
	
# PWM Hybrid Synth Weekly Progress Report
#Report date: 2024-10-31

## Last Week (time in hours)
	Team Review
		-The product design Specification was completed and added to both Canvas and Git
		-Work Began on a Design Matrix and AHP Methodologies to officially pick a project
		-Design work began on Kikad for the priliminary schematic of the synthesizer.
		-Began Testing individual circuit modules to ensure design works
	Eric Sanman
		- Received boards from OSH Park (0)
        - Received parts from DigiKey (0)
        - Try to build one amplifier (4)
        - Amplifier works great, but the input rolls-off low freq. too qucikly. Making adjustments to component values on board (1)
        - Update KiCad design based off of flaws (DC input, inductors wrong footprints), update schematic values (1)
	Chuong Vo
		-Finished watching Kikad tutorial Video (2)
		-Began to model seperate schematics on Kikad based on the chosen effects that the synthesizer can perform (1.5)
		-Began to write Arduino code for the PWM function (1)
	Sierra Buckley
		- redid PDS and block diagrams (2)
		- started breadboarding effects (2)
		- kicad adjustments (2)
		- team effort on BOM (2)
	Chris Crider
	
##Next Week
	Team Plan
		-Finalize the Preliminary Schematic and have all team members check off schematic
		-Finalize Testing of individual modules and begin to combine into a singular circuit for testing
		-Begin to clean up Preliminary schematic and transition it into a Final Schematic
		-Begin creating a PCB layout based off of schematic
	Eric Sanman
		- Work with other team members on integrating parts into the schematic
        - Clean up and add descriptions to modules in KiCad
        - Check titleblocks
        - Find footprints for all parts
	Chuong Vo
		-Finish modeling the Effect schematics for the synthesizer and connect them all together before sending them over to Eric for quality assurance(2)
		-Continue to write Arduino code (1)
		-Create and fill out a Gantt Chart for the Project scheadule (2)
	Sierra Buckley
		- continue kicad adjustments with new additions with team (2)
		- team effort on BOM (2)
		- continue breadboarding effects (2)
	Chris Crider
	
##Blocked
	Team Blocks
		-Deciding how in fleshed out each of the effects for the Synth should be and the cost/return of doing more or less complex effects.
	Eric Sanman
		- Nothing
	Chuong Vo
		-Nothing blocked
	Sierra Buckley
	Chris Crider
	
	
# PWM Hybrid Synth Weekly Progress Report
#Report date: 2024-11-7

## Last Week (time in hours)
	Team Review
		-Finalized Schematic with Team Member sign off and added to both Git and Canvas
		-Combined all modules into one circuit and tested the combined circuit, uploading the Breadboard Prototype onto Git and Canvas 
		-Completed and signed off on ongoing project scheadule via Gantt Chart which was uploaded to both Git and Canvas
		-Began looking into surface mount components to be used on PCB
		
	Eric Sanman
        - Worked on adding fancier formatting to the schematics (1)
        - Generating priliminary board layout design for whole system (3)
        - Helped debug circuits (2)
	Chuong Vo
		- Create and fill out a Gantt Chart for the Project schedule (3)
		- Create ESP32 circuit and begin Testing Code (2)
	
	Sierra Buckley
	
	Chris Crider
	
	
##Next Week
	Team Plan
		-Begin work on compiling together components onto a Bill of Materials
		-Finalize the circuit connections and compose a L0 and L1 Functional Decomposition
		-Begin to clean up CAD layout and add component traces
	Eric Sanman
        - Work on enhancing the layout in KiCad, adding:
            - Mounting holes
            - Cleaner amp routing
            - Add LEDs to board
            - Update schematic based on testing changes
            - Fix pin header, power jack, and inductor footprints
	Chuong Vo
		- Compile Bill of Materials and match components to Schmatic/PCB Layout (3)
		- Finalize and Test ESP32 Code (3)
		
	Sierra Buckley
	
	Chris Crider
	
	
##Blocked
	Team Blocks
		-
	Eric Sanman
		- Nothing
	Chuong Vo
		- Nothing Blocked
		- Finding components that are in stock and ship quickly
		
	Sierra Buckley
	
	Chris Crider
	
# PWM Hybrid Synth Weekly Progress Report
#Report date: 2024-11-14 

## Last Week (time in hours)
	Team Review
		- The Functional Decomposition and Bill of Materials were finalized and added to both Canvas and Git.
		- The initial CAD was updated with components being put into place and traces were put into place. 
		
	Eric Sanman
        - Generated ESP32 pin tracking sheet for assisiting programming
        - Tested and Debugged ESp32 Code and circuit (4)
		
	Chuong Vo
		- Compile Bill of Materials and match components to Schmatic/PCB Layout (4)
		- Finalize and Test ESP32 Code with respective circuit (3)
	
	Sierra Buckley
	
	Chris Crider
	
	
##Next Week
	Team Plan
		- Finalize the CAD Schematic by adding finishing touches to the traces and ensure the correct components are used
		- Get Designed Reviewed by two other teams and review the designs of the two teams
		- Place PCB order at Osh Park
		- Wait in Anticipation

	Eric Sanman
	
	Chuong Vo
		- Provide Design review comments for other groups and get Schematic and PCB design reviewed (2.5)
		- Verify Final Schematic and PCB design and sign off on completion (2)
	Sierra Buckley
	
	Chris Crider
	
	
##Blocked
	Team Blocks
		-
	Eric Sanman
		-
	Chuong Vo
		- Nothing Blocked
		
	Sierra Buckley
	
	Chris Crider