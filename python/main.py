import subprocess
from pathlib import Path

current_dir = Path(__file__).resolve().parent
print(current_dir)
project_dir = current_dir.parent
print(project_dir)
build_dir = project_dir / "build"
print(build_dir)
trianglen_path = build_dir / "Triangle_n"
print(trianglen_path)
print()


result = subprocess.run(
    f"{trianglen_path} 35 0.75 1 0.1 4",
    shell=True,
    capture_output=True,
    text=True)


# print("Response:", result.stdout)
# print("Errors:", result.stderr)
# print("Exit code:", result.returncode)
print(result.stdout)
