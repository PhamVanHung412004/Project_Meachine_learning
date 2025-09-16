import pandas
import yaml
from typing import (
    Dict,
    Any
)

class Path_File:
    def __init__(self, path : str) -> None:
        self.__path = path

    @property
    def get_path(self) -> str:
        return self.__path

class Read_File_CSV(Path_File):
    def __init__(self, path : str) -> None:
        super().__init__(path)

    def read_file(self) -> pandas.DataFrame | str:
        try:
            return pandas.read_csv(self.get_path)
        except FileNotFoundError as e:
            return str(e)  

class Read_File_Yaml(Path_File):
    def __init__(self, path : str) -> None:
        super().__init__(path)

    def read_file(self) -> str | Dict[str, Any]:
        try:
            with open(self.get_path, "r", encoding="utf-8") as file:
                data : Dict[str, str] = yaml.safe_load(file)
                return data
        except FileNotFoundError as e:
            return str(e) 