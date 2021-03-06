////////////////////////////////////////////

// Generates Log Files

////////////////////////////////////////////

#include <stdio.h>
#include <time.h>

const char MESSAGELOG_LOCATION[] = "/usr/share/led_display/logging/message_history.log";
const char ERRORLOG_LOCATION[] =  "/usr/share/led_display/logging/error_history.log";
const char DEBUGLOG_LOCATION[] = "/usr/share/led_display/logging/debug_messages.log";
const char LASTMESSAGE_LOCATION[] = "/usr/share/led_display/logging/last_message.log";

int add_message_log(char* message)
{
   FILE *MessageFile;
   time_t rawtime;
   struct tm * timeinfo;

   time ( &rawtime);
   timeinfo = localtime (&rawtime);
   MessageFile=fopen(MESSAGELOG_LOCATION, "a");
   fprintf(MessageFile, "Time: %s \tSuccessful Message: \'%s\'\n", asctime(timeinfo), message);
   printf("Message Sent:\'%s\'\n", message);
   fclose(MessageFile);
}

int add_error_log(char* message)
{
   FILE *ErrorFile;
   time_t rawtime;
   struct tm * timeinfo;

   time ( &rawtime);
   timeinfo = localtime (&rawtime);
   ErrorFile=fopen(ERRORLOG_LOCATION, "a");
   fprintf(ErrorFile, "Time: %s \tError Message: %s\n", asctime (timeinfo), message);
   //printf("Error: %s\n", message);
   fclose(ErrorFile);
   add_debug_log(message);
}

int add_last_message(char* message)
{
   FILE *LastFile;
   time_t rawtime;
   struct tm * timeinfo;

   time ( &rawtime);
   timeinfo = localtime (&rawtime);
   LastFile = fopen(LASTMESSAGE_LOCATION, "w");
   fprintf(LastFile, "Time: %s\t %s\n", asctime (timeinfo), message);
   fclose(LastFile);
}

int add_debug_log(char* message)
{
   FILE *DebugFile;
   time_t rawtime;
   struct tm * timeinfo;

   time ( &rawtime);
   timeinfo = localtime (&rawtime);
   DebugFile = fopen(DEBUGLOG_LOCATION, "a");
   fprintf(DebugFile, "Time: %s \tDebug Message: %s\n", asctime (timeinfo),message);
   printf("Debug: %s\n", message);
   fclose(DebugFile);
}
