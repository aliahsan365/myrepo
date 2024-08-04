# Ruta base donde se buscarán carpetas vacías
$basePath = "C:\git\myrepo"

# Función para agregar .gitkeep en carpetas vacías
function Add-GitKeep {
    param (
        [string]$path
    )

    # Obtener todas las carpetas recursivamente
    $directories = Get-ChildItem -Path $path -Directory -Recurse

    foreach ($directory in $directories) {
        # Verificar si la carpeta está vacía
        if (-not (Get-ChildItem -Path $directory.FullName)) {
            # Ruta del archivo .gitkeep
            $gitkeepPath = Join-Path -Path $directory.FullName -ChildPath ".gitkeep"
            # Crear el archivo .gitkeep
            New-Item -Path $gitkeepPath -ItemType File -Force | Out-Null
            Write-Output "Creado .gitkeep en $($directory.FullName)"
        }
    }
}

# Llamar a la función con la ruta base
Add-GitKeep -path $basePath

Write-Output "Proceso completado."