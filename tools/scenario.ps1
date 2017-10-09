#Write-Host "Num Args:" $args.Length;
#foreach ($arg in $args)
#{
#  Write-Host "Arg: $arg";
#}

#parametros: 
# ruta al escenario
# ruta a resultados
$ruta_escenario = "C:\Globe\12_Local\Vueling\Fase_2\VSTS_Agent\_work\2\s\CI\Vueling\scenarios"
$ruta_resultados = "C:\Globe\12_Local\Vueling\Fase_2\VSTS_Agent\_work\2\s\CI\Vueling\results"


param([string]$ruta_escenario, [string]$ruta_resultados)
Write-Host "Ruta al escenario: $ruta_escenario"
Write-Host "Ruta a resultados: $ruta_resultados"

$proceso = Start-Process -FilePath 'C:\Program Files (x86)\HP\LoadRunner\bin\wlrun.exe' -ArgumentList "-TestPath $ruta_escenario\Scenario.lrs -Run" -PassThru
$proceso.WaitForExit()

#"c:\Program Files\Mercury\LoadRunner\bin\AnalysisUI.exe" -RESULTPATH C:\Temp\30users\30users.lrr -TEMPLATENAME WinResTemplate

$proceso2 = Start-Process -FilePath 'C:\Program Files (x86)\HP\LoadRunner\bin\AnalysisUI.exe' -ArgumentList "-RESULTPATH $ruta_restulados\result.lrr -TEMPLATENAME Vueling_template" -PassThru
$proceso2.WaitForExit()

& Add-Type -A System.IO.Compression.FileSystem
[IO.Compression.ZipFile]::CreateFromDirectory($ruta_resultados'\result', $ruta_resultados'\result.zip')
[IO.Compression.ZipFile]::CreateFromDirectory($ruta_resultados'\result\HTML_report', $ruta_resultados'\html_report\html_report.zip')
