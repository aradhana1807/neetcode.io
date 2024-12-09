# Script to delete exe files in root and any other folders in the directory
import os

def delete_exe_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.exe'):
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")

# Specify the directory
directory = os.path.dirname(__file__)
delete_exe_files(directory)
