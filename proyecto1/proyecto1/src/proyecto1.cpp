#include "proyecto1.h"
#include <fstream>
#include <stdlib.h> 


BinaryTree maestros;
CircularList cursos;
doubleLinkedList edificios;
arrayList dias;

void writeTextFile(std::string file_path, std::string content){
  std::ofstream myfile;
  myfile.open (file_path+".dot");
  myfile << content;
  myfile.close();
}



static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

void build_decoding_table() {

  decoding_table = (char*) malloc(256);

  for (int i = 0; i < 64; i++)
    decoding_table[(unsigned char) encoding_table[i]] = i;
}

char *base64_encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length) {

  *output_length = 4 * ((input_length + 2) / 3);

  char *encoded_data = (char*) malloc(*output_length);
  if (encoded_data == NULL) return NULL;

  unsigned int i , j;
  for (i = 0, j = 0; i < input_length;) {

    uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

    uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
  }

  for (int i = 0; i < mod_table[input_length % 3]; i++)
    encoded_data[*output_length - 1 - i] = '=';

  return encoded_data;
}


std::string ReadFile(const char *name)
{
  FILE *file;
  unsigned char *buffer;
  char *lobi;

  //Open file
  file = fopen(name , "rb");
  if (!file)
    {
      fprintf(stderr, "Unable to open file %s", name);
      return "error";
    }

  //Get file length
  fseek(file, 0, SEEK_END);
  long int fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  //Allocate memory
  buffer=(unsigned char*)malloc(fileLen+1);
  if (!buffer)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return "error";
    }

  
  //Read file contents into buffer
  fread(buffer, fileLen, 1, file);
  size_t output_length = 0;
  lobi = base64_encode(buffer, fileLen, &output_length);

  return (std::string) lobi;

  //printf("%s\n", lobi);
  FILE *fp;
	fp = fopen ( "salida.txt", "w+" );
	//if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	fputs(lobi,fp);
	fclose ( fp );

  fclose(file);
  //insert_blob(buffer);
  free(buffer);
}


std::string practica1::newProfessor(const Data& data){
        maestros.add(data);
        return "ok";
}

std::string practica1::newCourse(const curso& data){
  try
  {
    Professor* enlazar = maestros.get(data.catedratico);
    Data newCourseData;
    newCourseData.id = data.codigo;
    newCourseData.name = data.curso;
    cursos.add(newCourseData);
    enlazar->setCurso(cursos.get(newCourseData.id));
    return "ok";
  }
  catch(const std::exception& e){
    return "error al agregar";
  }
}

std::string practica1::newBuilding(const Data& data){
  edificios.add(data);
  return "ok";
}

std::string practica1::getGraphic( const std::string& choice)
{
    std::string result;
    if(choice == "arbol")
    {
      writeTextFile(choice, maestros.getGraphic());
      if (system(NULL)) system("dot -Tpng arbol.dot -o arbol.png");
      else exit (EXIT_FAILURE);
      return ReadFile("/home/xavi/-EDD-Proyecto1_2019/proyecto1/arbol.png");

    }else if(choice == "cursos"){
      writeTextFile(choice, cursos.getGraphic());
      if (system(NULL)) system("dot -Tpng cursos.dot -o cursos.png");
      else exit (EXIT_FAILURE);
      return ReadFile("/home/xavi/-EDD-Proyecto1_2019/proyecto1/cursos.png");
    }else if(choice == "edificios"){
      result = edificios.getGraphic();
      writeTextFile(choice, result);
      return result;
    }else if(choice == "dias"){
      result = dias.getGraphic();
      writeTextFile(choice, result);
      return result;
    }
    return "opcion invalida";
}

std::string practica1::newDay(const deuxData& data)
{
  dias.add(data);
  return "ok";
}