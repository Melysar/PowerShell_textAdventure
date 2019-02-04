using module 'C:\Users\1500856269A\Documents\Powershell\player.psm1'
using module 'C:\Users\1500856269A\Documents\Powershell\fighter.psm1'
using module 'C:\Users\1500856269A\Documents\Powershell\magician.psm1'
using module 'C:\Users\1500856269A\Documents\Powershell\functions.psm1'

$player;

Clear-Host

readNarration('C:\Users\1500856269A\Documents\Powershell\narration\introduction.txt')
Write-Host "`n"

$name = Read-Host -Prompt "What is your name traveler?"
Write-Host "`n"

Clear-Host
readNarration('C:\Users\1500856269A\Documents\Powershell\narration\introduction_1.txt')
Write-Host "`n"
Start-Sleep -Seconds 5

$classOption = Read-Host -Prompt "Enter Option (1 or 2)"
Switch ($classOption)
{
    1
    {
        $player = [Fighter]::new()
        $player.createCharacter()
        $player.makeWarrior()
    }
    2
    {
        $player = [Magician]::new()
        $player.createCharacter()
        $player.makeMagician()
    }
}

Clear-Host
$player.displayCharacter()