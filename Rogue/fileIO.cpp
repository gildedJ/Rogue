#include "fileIO.h"

#include "SDL_rwops.h"

#include <memory>

char* readEntireFile(const char* filename)
{
  SDL_RWops* file = SDL_RWFromFile(filename, "rb");
  if (file == NULL)
  {
    printf("Unable to open tilemap file: %s", filename);
    return nullptr;
  }
  Sint64 fileSize = SDL_RWsize(file);
  char* fileData = (char*)malloc(fileSize + 1);

  Sint64 totalRead = 0;
  Sint64 bytesRead = 1;
  char* buffer = fileData;
  while (totalRead < fileSize && bytesRead != 0)
  {
    bytesRead = SDL_RWread(file, buffer, 1, (fileSize - totalRead));
    totalRead += bytesRead;
    buffer += bytesRead;
  }
  SDL_RWclose(file);
  if (totalRead != fileSize)
  {
    free(fileData);
    printf("Failed to read file: %s", filename);
    return nullptr;
  }
  fileData[totalRead] = '\0';
  return fileData;
}