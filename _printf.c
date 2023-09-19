#include <main.h>

#define BUFFER_SIZE 1024

void outputBuffer(char buffer[], int *buffIndex);

/**
 * _printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...);
{
    int i, totalPrinted = 0, printedChars = 0;
    int flags = 0, width = 0, precision = 0, size = 0, buffIndex = 0;
    va_list args;
    char outputBuffer[BUFFER_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            outputBuffer[buffIndex++] = format[i];
            if (buffIndex == BUFFER_SIZE)
                outputBuffer(outputBuffer, &buffIndex);
            printedChars++;
        }
        else
        {
            outputBuffer(outputBuffer, &buffIndex);
            
            flags = getFlags(format, &i);
            width = getWidth(format, &i, args);
            precision = getPrecision(format, &i, args);
            size = getSize(format, &i);
            ++i;
            totalPrinted = handlePrint(format, &i, args, outputBuffer, flags, width, precision, size);
            if (totalPrinted == -1)
            {
                va_end(args);
                return (-1);
            }
            printedChars += totalPrinted;
        }
    }

    outputBuffer(outputBuffer, &buffIndex);

    va_end(args);

    return (printedChars);
}

/**
 * outputBuffer - Prints the contents of the output buffer if it exists
 * @buffer: Array of characters.
 * @buffIndex: Index at which to add the next character, represents the length.
 */
void outputBuffer(char buffer[], int *buffIndex)
{
    if (*buffIndex > 0)
    {
        ssize_t bytes_written = write(1, &buffer[0], *buffIndex);
        if (bytes_written == -1)
        {
            perror("write"); 
            *buffIndex = 0;  
        }
        else
        {
            *buffIndex = 0;  
        }
    }
}

