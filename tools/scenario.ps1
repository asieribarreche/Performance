$proceso = Start-Process -FilePath 'C:\Program Files (x86)\HP\LoadRunner\bin\wlrun.exe' -ArgumentList "-TestPath C:\Globe\12_Local\Vueling\Fase_2\Performance\scenario\Scenario.lrs -Run" -PassThru
$proceso.WaitForExit()

#"c:\Program Files\Mercury\LoadRunner\bin\AnalysisUI.exe" -RESULTPATH C:\Temp\30users\30users.lrr -TEMPLATENAME WinResTemplate

$proceso2 = Start-Process -FilePath 'C:\Program Files (x86)\HP\LoadRunner\bin\AnalysisUI.exe' -ArgumentList "-RESULTPATH C:\Globe\12_Local\Vueling\Fase_2\Performance\results\result\result.lrr -TEMPLATENAME Vueling_template" -PassThru
$proceso2.WaitForExit()

& Add-Type -A System.IO.Compression.FileSystem
[IO.Compression.ZipFile]::CreateFromDirectory('C:\Globe\12_Local\Vueling\Fase_2\Performance\results\result', 'C:\Globe\12_Local\Vueling\Fase_2\Performance\results\result.zip')
[IO.Compression.ZipFile]::CreateFromDirectory('C:\Globe\12_Local\Vueling\Fase_2\Performance\results\result\HTML_report', 'C:\Globe\12_Local\Vueling\Fase_2\Performance\html_report\html_report.zip')