function readNarration([string]$filePath)
{
    Get-Content $filePath | Write-Host
}