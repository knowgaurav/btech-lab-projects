{
"cmd": ["g++.exe",
 "-std=c++17", "${file}",
  "-o",
   "${file_base_name}.exe",
    "&&" ,
     "${file_base_name}.exe"],
"shell":true,
"working_dir":"$file_path",
"selector":"source.cpp"
}