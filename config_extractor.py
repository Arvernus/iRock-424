from SCons.Script import Import
import json
import os

# Importiere die env-Variable von PlatformIO
Import("env")

# Prüfe, ob es sich um eine CI-Umgebung handelt
is_ci = os.getenv("CI") is not None or os.getenv("GITHUB_ACTIONS") is not None

# Pfad zur project.json Datei
project_json_path = os.path.join(os.getcwd(), "project.json")

# Datei öffnen und JSON Daten laden
with open(project_json_path, "r") as file:
    project_data = json.load(file)

# Version und HW_NAME auslesen
version = project_data.get("version", "unknown")
hw_name = project_data.get("name", "unknown")

# Wenn es sich nicht um eine CI-Umgebung handelt, hänge "-dev" an die Version an
if not is_ci:
    version += "-dev"

# Build-Flags hinzufügen
env.Append(CPPDEFINES=[
    ('SW_VERSION', version),
    ('HW_NAME', hw_name)
])
