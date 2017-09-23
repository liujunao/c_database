#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main();

void wellcome_system_ui();
void close_system_ui();
void main_system_ui();
void display_all_ui();
void add_information_ui();
void find_information_ui();
void revise_information_ui();

void write_a_struct(struct people * temp);
int read_a_struct(struct people* temp);
struct people* scanf_a_struct(struct people* temp);
void add_information();
void print_f(struct people* temp);
void print_all_database();
void find_name(char name[20]);
void find_information();
void find_name_result();
int find_database_number();

void revise_information();
void revise_information_result();
void revise_by_name(char name_r[20], float run, float walk);
void write_a_struct_again(struct people * temp);

struct people
{
	char name[20];
	float run;
	float walk;
};
