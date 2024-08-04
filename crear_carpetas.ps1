# Rango de años a crear
$startYear = 2012
$endYear = 2024

# Ruta base donde se crearán las carpetas
$basePath = "C:\git\myrepo"

# Crear la estructura de carpetas
for ($year = $startYear; $year -le $endYear; $year++) {
    # Ruta para el año
    $yearPath = Join-Path -Path $basePath -ChildPath $year

    # Crear carpeta del año si no existe
    if (-not (Test-Path -Path $yearPath)) {
        New-Item -Path $yearPath -ItemType Directory | Out-Null
    }

    # Crear carpetas de los meses dentro del año
    for ($month = 1; $month -le 12; $month++) {
        $monthName = [CultureInfo]::CurrentCulture.DateTimeFormat.GetMonthName($month)
        $monthPath = Join-Path -Path $yearPath -ChildPath $monthName

        # Crear carpeta del mes si no existe
        if (-not (Test-Path -Path $monthPath)) {
            New-Item -Path $monthPath -ItemType Directory | Out-Null
        }
    }
}

Write-Output "Carpetas creadas exitosamente."