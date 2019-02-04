Class Player
{
    ###########################################################################
    # Variables
    [string]$characterName
    [int]$level = 1
    [int]$health
    [int]$strength
    [int]$dexterity
    [int]$constitution
    [int]$intelligence
    [int]$wisdom
    [int]$charisma

    ###########################################################################
    # Constructors
    Player()
    {
        $this.characterName = ""
        $this.strength = 10
        $this.dexterity = 10
        $this.constitution = 10
        $this.intelligence = 10
        $this.wisdom = 10
        $this.charisma = 10
    }

    Player([string]$playerName, [int]$strength, [int]$dexterity, [int]$constitution, [int]$intelligence, [int]$wisdom, [int]$charisma)
    {
        $this.characterName = $playerName
        $this.strength = $strength
        $this.dexterity = $dexterity
        $this.constitution = $constitution
        $this.intelligence = $intelligence
        $this.wisdom = $wisdom
        $this.charisma = $charisma
    }

    ###########################################################################
    # Methods
    [int]statGen()
    { 
        $diceRolls = 0,0,0,0
        $stat = 0

        for ($i = 0; $i -lt 4; $i++)
        {
            $diceRolls[$i] = Get-Random -Minimum 1 -Maximum 6
        }
        
        $diceRolls = $diceRolls | Sort-Object -Descending
        $diceRolls[3] = 0

        foreach ($roll in $diceRolls)
        {
            $stat += $roll
        }

        return $stat
    }

    [void]assignStat([int]$stat)
    {
        Write-Host "0`t`t`t1`t`t`t2`t`t`t`t3`t`t`t`t4`t`t5"
        Write-Host "-`t`t`t-`t`t`t-`t`t`t`t-`t`t`t`t-`t`t-"
        Write-Host "Strength`tDexterity`tConstitution`tIntelligence`tWisdom`tCharisma"
        $option = Read-Host -Prompt "Assign to Stat"

        switch ($option)
        {
            0
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.strength = $stat
                }
            }

            1
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.dexterity = $stat
                }
            }

            2
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.constitution = $stat
                }
            }

            3
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.intelligence = $stat
                }
            }

            4
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.wisdom = $stat
                }
            }

            5
            {
                if ($stat -eq 0)
                {
                    Write-Host -BackgroundColor Red "Chosen Stat is $stat"
                    Start-Sleep -Seconds 5
                }
                else
                {
                    $this.charisma = $stat
                }
            }
        }
    }

    [void]displayCharacter()
    {
        $displayHealth = "Health: " + $this.health
        $displayLevel = "level: " + $this.level
        $spacer = 24
        
        Write-Host $this.characterName
        
        for ($i = 0; $i -lt 24; $i++)
        {
            Write-Host "=" -NoNewline
        }
        Write-Host ""

        #Display Health and Level
        Write-Host $displayHealth -NoNewline
        $spacer -= $displayHealth.Length + $displayLevel.Length
        for ($i = 0; $i -lt $spacer; $i++)
        {
            Write-Host " " -NoNewline
        }
        Write-Host $displayLevel

        #Stats
        for ($i = 0; $i -lt 24; $i++)
        {
            Write-Host "=" -NoNewline
        }
        Write-Host ""
        Write-Host "Strength `t`t : `t " $this.strength
        Write-Host "Dexterity `t`t : `t " $this.dexterity
        Write-Host "Constitution `t : `t " $this.constitution
        Write-Host "Intelligence `t : `t " $this.intelligence
        Write-Host "Wisdom `t`t`t : `t " $this.wisdom
        Write-Host "Charisma `t`t : `t " $this.charisma
        Write-Host `n
    }

    createCharacter()
    {
        $name = ""
        $stats = 0,0,0,0,0,0
        $option = 0
        $size = 0

        #Input Character Name
        $name = Read-Host -Prompt "Input Character Name"
        $this.characterName = $name

        #Random Stat Gen
        for ($i = 0; $i -lt 6; $i++)
        {
            $stats[$i] = $this.statGen()
        }

        #Stat Assignment
        
        while (($size = $stats | Measure-Object -Sum | Select-Object -ExpandProperty Sum) -ne 0)
        {
            Clear-Host
            $this.displayCharacter()

            Write-Host "0`t1`t2`t3`t4`t5"
            Write-Host "-`t-`t-`t-`t-`t-`t"
            foreach ($stat in $stats)
            {
                Write-Host $stat`t -NoNewline
            }
            Write-Host `n`n

            $option = Read-Host -Prompt "Select Stat"
            Switch ($option)
            {
                0
                {
                    $this.assignStat(($stats[$option]))
                    $stats[$option] = 0
                }

                1
                {
                    $this.assignStat($stats[$option ])
                    $stats[$option] = 0
                }
                
                2
                {
                    $this.assignStat($stats[$option])
                    $stats[$option] = 0
                }

                3
                {
                    $this.assignStat($stats[$option])
                    $stats[$option] = 0              
                }

                4
                {
                    $this.assignStat($stats[$option])
                    $stats[$option] = 0
                }

                5
                {
                    $this.assignStat($stats[$option])
                    $stats[$option] = 0              
                }
            }
        }

        #Calculate Health
        $this.health = $this.constitution * 1.5
    }
}