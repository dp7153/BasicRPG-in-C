# BasicRPG-in-C

A game in the terminal, which includes save game, some rudimentary settings, an inventory sistem and randomisation.

The game is a turn based fighting game, where the player starts in a tavern but can earn coins by defeating enemies and buy randomized weapons from the shop. Some weapons can be gained for a bargain but the player must be mindful, since the weapons break after a certain number of attacks.

At the beginning the player chooses the difficulty of the save, which will decide, how much HP the player has and how many attacks in a row the enemy can make, after which the player decides if they want a permadeath save and then the player can name their save file and they begin with only their fists and a certain number of HP.
When going into the battle, the opponents are randomized, from their name, to the number of HP and the weapon they wield. So at times it might be easy to defeat an enemy and at times it might be nigh impossible.
But from every successful fight, the player will gain coins, which can be used in the shop to buy some new weapons, which are randomized and continue on their quest to rid become the greatest fighter.

The game works on Ubuntu 18.04 and is compiled using gcc.
