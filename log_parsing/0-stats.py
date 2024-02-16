#!/usr/bin/python3

import sys
import signal

# Define signal handler to catch keyboard interruption
def signal_handler(sig, frame):
    print_statistics()
    sys.exit(0)

# Function to print statistics
def print_statistics():
    print("Total file size:", total_file_size)
    for code in sorted(status_codes.keys()):
        print(f"{code}: {status_codes[code]}")

# Initialize variables
total_file_size = 0
status_codes = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0

# Register the signal handler
signal.signal(signal.SIGINT, signal_handler)

try:
    # Process input line by line
    for line in sys.stdin:
        line_count += 1
        # Split the line by space
        parts = line.split()
        if len(parts) >= 7:
            # Extract status code and file size
            status_code = parts[-2]
            file_size = int(parts[-1])
            # Update total file size
            total_file_size += file_size
            # Update status code count
            if status_code.isdigit():
                status_codes[int(status_code)] += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_statistics()
            print()

except KeyboardInterrupt:
    # If interrupted by keyboard, print final statistics
    print_statistics()
