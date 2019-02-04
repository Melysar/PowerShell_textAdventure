using module '.\player.psm1'

Class Fighter : Player
{
    ###########################################################################
    # Methods
    makeWarrior()
    {
        $this.characterName = "Fighter " + $this.characterName
    }
}