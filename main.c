// Welcome to the Aban source code.
// I hope you have fun here.

// Forward decelerations of essential subroutines.

// Initialize Operating System module.
int os_init(const int argc, const char *argv[]);
// Initialize Memory Manager module.
int mm_init(const int argc, const char *argv[]);
// Initialize Process Manager module.
int pc_init(const int argc, const char *argv[]);

// Shutdown Operating System module.
void os_exit();
// Shutdown Memory Manager module.
void mm_exit();
// Shutdown Process Manager module.
void pc_exit();

// If there is an error this subroutine calls before exiting application.
void os_error(int error_code, char *error_msg);
// Order Process Manager module to run processes.
int pc_run();

// Emergency subroutine in case of an error.
int main_emergency_exit(int error_code);

// An Aban application starts here.
int main(const int argc, const char *argv[])
{
    // To store subroutines returned value as an error code.
    static int err = 0;

    // Initializations.
    // 1) Call the initialization subroutine.
    // 2) Store returned value in 'err' variable.
    // 3) Check 'err' variable for error.
    // 4) If 'err' is not 0, that means there is an error.
    // 5) If there is an error, call emergency_exit(err) and exit application.
    err = os_init(argc, argv);
    if (err != 0)
    {
        return main_emergency_exit(err);
    }
    err = mm_init(argc, argv);
    if (err != 0)
    {
        return main_emergency_exit(err);
    }
    err = pc_init(argc, argv);
    if (err != 0)
    {
        return main_emergency_exit(err);
    }
    // End of Initializations.

    // Run process subroutine. Main loop of application.
    err = pc_run();
    // Check if there is an error, exit application with error code.
    if (err != 0)
    {
        return main_emergency_exit(err);
    }

    // Call shutdown subroutines to shutdown essential modules.
    pc_exit();
    mm_exit();
    os_exit();

    // Exit successfully. 'err' should be 0;
    return err;
}

// Emergency subroutine in case of an error.
int main_emergency_exit(int error_code)
{
    // Ask operating system module to apply an error.
    os_error(error_code, "An Error Ocurred!");
    // Call exit subroutines to shutdown essential modules.
    pc_exit();
    mm_exit();
    os_exit();
    // Return error code.
    return error_code;
}
