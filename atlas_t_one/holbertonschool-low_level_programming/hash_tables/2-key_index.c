#include "hash_tables.h"
/**
 * key_index - Gets index of a key in the hash array.
 * @key: Key to be hashed.
 * @size: The size of the array of the hash table
 * 
 * Return: The index where the key should be put in the array
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size){
    unsigned long int hash_value = hash_djb2(key);
    unsigned long int index = hash_value % size;
    return(index);
}