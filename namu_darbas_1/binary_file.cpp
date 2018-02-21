#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "binary_file.h"
#include "helpers.h"


Connection *database_open(const char* filename) {
	Connection *conn = new Connection;
	if(!conn) die("Memory error");

    conn->db = new Database;
	if(!conn->db) die("Memory error");

	conn->file = fopen(filename, "r+");
	if (!conn->file) {
        printf("Failed to open the file, creating a new one\n");
        conn->file = fopen(filename, "w+");
    }

	if(conn->file) {
		// load database from file
		int rc = fread(conn->db, sizeof(Database), 1, conn->file);

        conn->db->rows = new Address*[conn->db->capacity];

        for (int i = 0; i < conn->db->capacity; i++) {
            conn->db->rows[i] = new(Address);
        }

        for (int i = 0; i < conn->db->capacity; i++) {
            rc = fread(conn->db->rows[i], sizeof(Address), 1, conn->file);
        }

		// if database is loaded unsuccessfully
		if (rc != 1) {
			printf("Failed to load database\n");
			if (choice("Would you like to create a new one?\n")) {
				conn->file = fopen(filename, "w");
                database_create(conn);
                database_write(conn);
			}
		}
	} 


	return conn;
}


void database_create(Connection *conn) {

    conn->db->capacity = CHUNK_SIZE;
    conn->db->size = 0;
    conn->db->rows = new Address*[conn->db->capacity];

    for (int i = 0; i < conn->db->capacity; i++) {
        conn->db->rows[i] = new Address;
    }
}

void database_write(Connection *conn) {
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);
	if (rc != 1) die("Failed to write database");

    for (int i = 0; i < conn->db->capacity; i++) {
        rc = fwrite(conn->db->rows[i], sizeof(Address), 1, conn->file);
    }

	rc = fflush(conn->file);
	if (rc == -1) die("Cannot flush database");
}


void database_close(Connection *conn) {
	if (conn) {
		if (conn->file) fclose(conn->file);

        for (int i = 0; i < conn->db->capacity; i++) {
            free(conn->db->rows[i]);
        }
		free(conn->db->rows);
		free(conn->db);
		free(conn);
	}
}


