# Asegura el uso correcto de nombres de meses
Add-Type -AssemblyName System.Globalization

# Rango de años a crear
$startYear = 2012
$endYear = (Get-Date).Year
$currentMonth = (Get-Date).Month

# Ruta base
$basePath = "C:\git\myrepo"

Write-Output "Creando carpetas desde $startYear hasta $endYear"

for ($year = $startYear; $year -le $endYear; $year++) {
    $yearPath = Join-Path -Path $basePath -ChildPath $year.ToString()

    # Crear carpeta del año si no existe
    if (-not (Test-Path -Path $yearPath)) {
        Write-Output "Creando carpeta del año: $year"
        New-Item -Path $yearPath -ItemType Directory | Out-Null
    }

    # Solo crear meses hasta el actual si es el año actual
    $maxMonth = if ($year -eq $endYear) { $currentMonth } else { 12 }

    for ($month = 1; $month -le $maxMonth; $month++) {
        $monthName = [System.Globalization.CultureInfo]::CurrentCulture.DateTimeFormat.GetMonthName($month)
        $monthPath = Join-Path -Path $yearPath -ChildPath $monthName

        if (-not (Test-Path -Path $monthPath)) {
            Write-Output " → Creando carpeta: $monthName en $year"
            New-Item -Path $monthPath -ItemType Directory | Out-Null
        }
    }
}

Write-Output "✅ Carpetas creadas exitosamente."
