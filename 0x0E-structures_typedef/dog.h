#ifndef DOG_H
#define DOG_H

/**
 * struct dog - This struct represents a dog, with a name, age, and owner.
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's ower
 *
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif /* DOG_H */
