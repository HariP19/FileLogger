#include "save_file.h"


Vec3<float> Fr_des[4]= { {0.000000, -0.000000, 39.662805},  //Unitree A1
                            {0.000000, -0.000000, 39.662805},    
                            {0.000000, -0.000000, 21.356895},
                            {0.000000, -0.000000, 21.356895}};

int main()
{
    printf("saving vector...\n");
    SaveFileManager<float> saveFileManager("test", "/log/");
    saveFileManager.saveValue("Desired contact force");
    saveFileManager.saveVector(Fr_des[2]);
    // saveValue("\nDesired contact Force", "/log/", "result_2");
    // saveVector(Fr_des[2], "/log/", "result_2");

    return 0;
}