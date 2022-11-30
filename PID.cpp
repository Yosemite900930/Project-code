void Motor::pid() {
    /***Parameter***/
	double P = 5000;
	double I = 5;
	double D = 350;
	
	/***Measurement***/
	rps = (double) v_angular / 360 * 1000 / t_measure;

	/*** Control Speed ***/
	err = goal-rps;
	rps_aft = rps;
	proportion = (double) P * err;
	integral += (double) I * err * t_measure / 1000;
	differential = (double) -1 * D * (double) (rps_aft - rps_bef) / t_measure* 1000;
	cycle += proportion + integral + differential;
    
    /***Output***/
}
