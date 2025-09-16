from read_file import (
    Read_File_CSV,
    Read_File_Yaml
)
from pathlib import Path
from typing import Dict
import pandas 

path_file_yaml : str = str(Path(__file__).parent / "config.yaml")
# path_file_csv : str = str(Path(__file__).parent / "dataset/")



def main() -> None:
    data_config : Dict[str, str] = Read_File_Yaml(path_file_yaml).read_file()
    path_file_csv : str = data_config["path_file_csv"]
    dataset: pandas  = Read_File_CSV(path_file_csv).read_file()
    print(dataset)

 

main()
