#include "poll_lookup.h"

/*
 * Takes a datestring of the format YYYY-MM-DD and strips the leading 0's from
 *it
 * e.g. 2010-01-01 will return "2010-1-1"
 *
 * Also edits the variables you provide for year, month, day to return those!
 */
char* strip_date(char* datestr) {
	// Break datestring
	const char split[] = "-";
	char* token = strtok(datestr, split);
	char* newdate = malloc(sizeof(char) * MAX_SIZE_DATESTR); // YYYY-MM-DD + \0
	if (!newdate) { // malloc fail
		return NULL;
	}

	// Year, month, day
	int cols[COL_DAY + 1];

	int c = 0;
	while (token != NULL) {
		if (c >= 3) {
			fprintf(stderr, "Incorrect date format.\n");
			break;
		}
		cols[c] = atoi(token);
		token = strtok(NULL, split);
		c++;
	}
	snprintf(newdate, MAX_SIZE_DATESTR, "%d-%d-%d", cols[COL_YEAR], cols[COL_MONTH], cols[COL_DAY]);
	return newdate;
}
