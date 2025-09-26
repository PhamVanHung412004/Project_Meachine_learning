from read_file import (
    Read_File_CSV,
    Read_File_Yaml
)
from pathlib import Path
from typing import Dict
import pandas
import tensorflow as tf
import tensorflow_data_validation as tfdv
from sklearn.model_selection import train_test_split
from tensorflow_metadata.proto.v0 import schema_pb2

path_file_yaml : str = str(Path(__file__).parent / "config.yaml")

def main() -> None:
    data_config : Dict[str, str] = Read_File_Yaml(path_file_yaml).read_file()
    path_file_csv : str = data_config["path_file_csv"]
    dataset: pandas  = Read_File_CSV(path_file_csv).read_file()

    length_dataset : int = len(dataset)
    
    
    train : int = length_dataset * 80
    val : int = length_dataset * 20


    data_train = dataset.iloc[ : train]

    print(dataset)
main()
