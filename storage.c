/*
    Implementation of the storage data structure and its associated 
    functions defined in storage.h.
*/

#include "storage.h"

Storage* storage_create(void){
    Storage* new_storage = malloc(sizeof(Storage));

    if (new_storage == NULL) return NULL;

    new_storage->functions_array = NULL;
    new_storage->functions_array_size = 0;

    return new_storage;
}

void storage_destroy(Storage *storage){
    free(storage);
}

int storage_add_function(Storage *storage, function_pointer_t function){
    if (storage->functions_array == NULL) storage->functions_array = malloc(sizeof(function_pointer_t));
    else storage->functions_array = realloc(storage->functions_array, sizeof(function_pointer_t)*(storage_get_size(storage) + 1));
    if (storage->functions_array == NULL || storage == NULL || function == NULL) return -1;

    storage->functions_array_size += 1;
    size_t i;
    for(i = 0; i < storage->functions_array_size-1; i++);
    storage->functions_array[i] = function;
    
    return 0;
}


char *(*storage_get_function(Storage *storage, size_t index))(const char *){
    if (!storage || index >= storage->functions_array_size) {
        return NULL;
    }
    return storage->functions_array[index];
}


size_t storage_get_size(Storage *storage){
    if (!storage) {
        return 0;
    }
    return storage->functions_array_size;
}

char **storage_execute_all(Storage *storage, const char *input) {
    if(storage == NULL || input == NULL) return NULL;
    char **string_array = malloc(sizeof(char*) * storage->functions_array_size);
    if(string_array == NULL) return NULL;
    string_array[0] = storage->functions_array[0](input);
    for(size_t i = 1; i < storage->functions_array_size; i++) {
        string_array[i] = storage->functions_array[i](string_array[i-1]);
    }
    return string_array;
}

