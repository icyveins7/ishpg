#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3* DB;
        char* messageError;

            // Open a database connection on the filesystem
                if (sqlite3_open("test.db", &DB)) {
                        std::cerr << "Error opening DB" << std::endl;
                                return -1;
                                    }

                                        // SQL command to create a table
                                            const char* sql = "CREATE TABLE IF NOT EXISTS person(ID INT PRIMARY KEY, NAME TEXT);";
                                                
                                                    // Execute the SQL statement
                                                        if (sqlite3_exec(DB, sql, nullptr, nullptr, &messageError) != SQLITE_OK) {
                                                                std::cerr << "Error creating table: " << messageError << std::endl;
                                                                        sqlite3_free(messageError);
                                                                            } else {
                                                                                    std::cout << "Table created successfully in 'test.db'" << std::endl;
                                                                                        }

                                                                                            // Close the database connection
                                                                                                sqlite3_close(DB);
                                                                                                    return 0;
                                                                                                    }
