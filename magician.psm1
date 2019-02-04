using module '.\player.psm1'

Class Magician : Player
{
    makeMagician()
    {
        $this.characterName = "Magician " + $this.characterName
    }
}