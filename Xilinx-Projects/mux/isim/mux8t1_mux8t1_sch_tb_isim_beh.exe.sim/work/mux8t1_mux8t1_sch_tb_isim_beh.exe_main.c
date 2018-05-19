/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_00000000003510477262_2316096324_init();
    unisims_ver_m_00000000000236260522_2449448540_init();
    unisims_ver_m_00000000002123152668_0970595058_init();
    work_m_00000000002283089487_0428177693_init();
    work_m_00000000002641524035_1242829049_init();
    work_m_00000000002492742186_3447656629_init();
    work_m_00000000004004586486_2794103582_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004004586486_2794103582");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
