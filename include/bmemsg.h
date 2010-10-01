/*
 * $Id: bme_extmsg.h 2395 2009-12-16 07:08:34Z matthalm $
 *
 * Definitions of BME external messages.
 */

#ifndef _BME_EXTMSG_H
#define _BME_EXTMSG_H

#ifdef TESTSERVER
 #include "bme_isa_def.h"

 #ifndef TRUE
  #define TRUE          1
 #endif

 #ifndef EM_MON_ADC_LOCK_SUPPORT
  #define EM_MON_ADC_LOCK_SUPPORT       TRUE
 #endif

 #ifndef EM_FEA_FAST_ADC_ALIGNMENT
  #define EM_FEA_FAST_ADC_ALIGNMENT     TRUE
 #endif

 #ifndef EM_FTD_ENABLE
  #define EM_FTD_ENABLE                        TRUE
 #endif

 typedef uint8 adc_channels_t;

#else
 #include "em/hal/em_hal.h"
 #include "em/cha/em_cha_main.h"
#endif

/*** Client request and reply messages ****************************************/

/* Measurement mode definitions */
typedef enum {
  EM_SRV_MEASUREMENT_MODE_STOPPED,
  EM_SRV_MEASUREMENT_MODE_250MS,
  EM_SRV_MEASUREMENT_MODE_1S,
  EM_SRV_MEASUREMENT_MODE_5S
} EM_SRV_MEASUREMENT_MODE_TYPE;

/* Measurement action request element */
struct emsg_measurement_req_elem {
    uint8	type;
    uint8	period;
};

/* Measurement action request */
struct emsg_measurement_req {
    uint16	type, subtype;
    uint32	measurement_action;
    uint8	channel_count;
    struct	emsg_measurement_req_elem data[0];
};

/* Charger info request */
struct emsg_charger_info_req {
    uint16	type, subtype;
    uint32	flags;
};

/* Charger info reply */
struct emsg_charger_info_reply {
    uint32	zero;
    uint32	flags;
    uint8	status;
    uint8	charger_type;
    uint16	voltage;
    uint16	current;
    uint16	reserved;
};

union emsg_charger_info {
    struct emsg_charger_info_req	request;
    struct emsg_charger_info_reply	reply;
};


/* Control write request */
struct emsg_control_write_req {
    uint16			type, subtype;
    em_cha_ctrl_info_type	ctrl;
};


/* Control read request */
struct emsg_control_read_req {
    uint16	type, subtype;
    uint32     flags;
    em_cha_ctrl_info_type	ctrl;
};

/* Control read reply */
struct emsg_control_read_reply {
    uint32			zero;
    em_cha_ctrl_info_type	ctrl;
};

union emsg_control_read {
    struct emsg_control_read_req	request;
    struct emsg_control_read_reply	reply;
};


/* Battery info request */
struct emsg_battery_info_req {
    uint16	type, subtype;
    uint32	flags;
};

/* Battery info reply */
struct emsg_battery_info_reply {
    uint32	zero;
    uint32	flags;
    uint16	bat_type;
    uint16	nominal_capa;
    uint16	temp;
    uint16	voltage;
    uint16	voltage_tx_on;
    uint16	voltage_tx_off;
    uint16	voltage_pwm_on;
    uint16	voltage_pwm_off;
    uint16	generation;
    uint16	voltage_sh_chk;
};

union emsg_battery_info {
    struct emsg_battery_info_req	request;
    struct emsg_battery_info_reply	reply;
};


/* Charging info request */
struct emsg_charging_info_req {
    uint16	type, subtype;
    uint32	flags;
};

/* Charging info reply */
struct emsg_charging_info_reply {
    uint32	zero;
    uint32	flags;
    uint8	state;
    uint8	mode;
    uint16	reserved;
};

union emsg_charging_info {
    struct emsg_charging_info_req	request;
    struct emsg_charging_info_reply	reply;
};


/* Monitoring info request */
struct emsg_monitoring_info_req {
    uint16	type, subtype;
    uint32	flags;
};

/* Monitoring info reply */
struct emsg_monitoring_info_reply {
    uint32	zero;
    uint32	flags;
    uint8	batt_power;
    uint8	reserved;
    uint8	batt_max_num_bars;
    uint8	batt_bars;
    uint16	batt_capa;
    uint16	batt_time;
    uint8	batt_max_audio_bars;
    uint8	batt_audio_bars;
    uint16	reserved2;
};

union emsg_monitoring_info {
    struct emsg_monitoring_info_req	request;
    struct emsg_monitoring_info_reply	reply;
};


/* Set monitoring voltage request */
struct emsg_monitoring_voltage_req {
    uint16	type, subtype;
    uint16	voltage_level;
    uint16	reserved;
};


/* ADC read request */
struct emsg_adc_read_req {
    uint16	type, subtype;
    uint8	channel;
    uint8	num_reads;
    uint16	reserved;
};

/* ADC read reply */
struct emsg_adc_read_reply {
    uint32	zero;
    int32	result;
};

union emsg_adc_read {
    struct emsg_adc_read_req	request;
    struct emsg_adc_read_reply	reply;
};


/* ADC unit read request */
struct emsg_adc_unit_req {
    uint16	type, subtype;
    uint8	channel;
    uint8	num_reads;
    uint16	reserved;
};

/* ADC unit read reply */
struct emsg_adc_unit_reply {
    uint32	zero;
    int32	result;
};

union emsg_adc_unit {
    struct emsg_adc_unit_req	request;
    struct emsg_adc_unit_reply	reply;
};


/* Write ADC calibration data request */
struct emsg_adc_cal_write_req {
    /* Fixed part, must be sent first and atomically */
    uint16	type, subtype;
    uint8	num_data;
    uint8	action;
    /* num_data elements follow */
};


/* Read ADC calibration data request */
struct emsg_adc_cal_read_req {
    uint16	type, subtype;
    uint8	action;
    /* The channel number may be also one of "pseudo-channel" IDs:
       EM_ADC_MAIN_CAL (to get calibration data for AD converter), or
       EM_ADC_ALL_CAL (to get calibration data for all channels */
    uint8 channel;
};

/* Structure of 'ADC channel calibration data' element */
struct adc_chan_cal_data_elem {
    em_hal_adc_cal_data_str_t	cdata;
    uint8		alg;
    uint8		reserved;
    uint16		parameter1;		/* Usually reference_voltage */
};

/* Read ADC calibration data reply */
struct emsg_adc_cal_read_reply {
    uint8	num_data;
    /* num_data elements follow */
    struct adc_chan_cal_data_elem accd[0];
};

union emsg_adc_cal_read {
    struct emsg_adc_cal_read_req	request;
    struct emsg_adc_cal_read_reply	reply;
};


/* PSM feature request */
struct emsg_psm_feature_req {
    uint16	type, subtype;
    uint8	state;
};


/* PSM read request */
struct emsg_psm_read_req {
    uint16	type, subtype;
    uint32	flags;
};

/* PSM read reply */
struct emsg_psm_read_reply {
    uint32	zero;
    uint32	flags;
    uint16	bat_current;
    uint16	phone_current;
    uint16	discharge_amount;
    uint8	cs_act_state;
    uint8	cs_act_protocol;
    uint8	cs_idle_activity;
    uint8	reserved;
    uint16	batmon4_phone_state;
    uint16	feature_counter;
    uint32	activity;
};

union emsg_psm_read {
    struct emsg_psm_read_req	request;
    struct emsg_psm_read_reply	reply;
};

/* PSM internal write request */
struct emsg_psm_internal_write_req {
    uint16     type, subtype;
    uint8      device;
    uint8      activity_level;
};

#if (EM_MON_ADC_LOCK_SUPPORT == TRUE)
/* Set/lock ADC unit calibration data request */
struct emsg_srv_adc_unit_lock_req {
    uint16	type, subtype;
    adc_channels_t channel;
    byte	action;
    int16	value;
};

#endif

#if (EM_FEA_FAST_ADC_ALIGNMENT == TRUE)

/* ADC tuning request element */
struct adc_tune_req_elem {
    uint8	chan_id;
    uint8	num_samples;
    int16	trigger_level;
};

/* Start ADC tuning request */
struct emsg_adc_tune_req {
    uint16	type, subtype;
    uint8	reserved;
    uint8	num_states;
    uint16	state_trans_timer_val;
    uint16	timeout_timer_val;
    /* num_states elements follow */
    struct adc_tune_req_elem reqarr[0];
};

/* ADC tuning reply element */
struct adc_tune_reply_elem {
    uint16	status;
    uint16	chan_id;
    int16	meas_val;
};

/* ADC tuning reply */
struct emsg_adc_tune_reply {
    uint8	num_blocks;
    /* num_blocks elements follow */
    struct adc_tune_reply_elem replyarr[0];
};

union emsg_adc_tune {
    struct emsg_adc_tune_req	request;
    struct emsg_adc_tune_reply	reply;
};

#endif


#if (EM_FEA_THERMOMETER_ENABLED == TRUE)
/* Thermo request */
struct emsg_thermo_req {
    uint16	type, subtype;
};

/* Thermo reply */
struct emsg_thermo_reply {
    uint32	zero;
    uint32	result;
    uint8	status;
    uint8	reserved[3];
};

union emsg_thermo {
    struct emsg_thermo_req	request;
    struct emsg_thermo_reply	reply;
};
#endif


#if (EM_FEA_POWER_MANAGEMENT_ENABLED == TRUE)
/* Power request */
struct emsg_power_req {
    uint16		type, subtype;
    uint8		consumer;
    uint8		state;
    uint16		reserved;
};

/* Power reply */
struct emsg_power_reply {
    uint32	zero;
    uint8	status;
    uint8	reserved[3];
};

union emsg_power {
    struct emsg_power_req	request;
    struct emsg_power_reply	reply;
};
#endif


#if (EM_FTD_ENABLE == TRUE)

/* FTD information request */
struct emsg_ftd_data_req {
    uint16	type, subtype;
    uint32	flags;
};

/* FTD information reply */
struct emsg_ftd_data_reply {
    uint32	zero;
    uint32	flags_reserved;
    uint32	result;
};

/* FTD bulk information data reply */
struct emsg_ftd_bulk_data_reply {
    uint32	zero;
    uint32	flags;
    uint8	status;
    uint16	instant_v_bat;
    uint32	remain_stby_mins;
    uint16	no_bat_low_warnings;
    uint8	misc_flags_mask1;
    uint16	check_v_bat;
    uint16	warn_interval_cnt;
    uint16	dmf_out_voltage;
    uint16	bm4_init_v_bat;
    uint16	time_per_bar_min;
    uint16	v_bat_1st_bat_low;
    uint32	avg_phone_curr_ua;
    int16	last_cha_amount;
    uint16	lowest_v_txoff;
    uint16	lowest_v_txon;
    int16	largest_dv;
    uint8	batt_bar_log_mask;
    uint8	prev_batt_bar_lev;
    uint8	batt_low_reason;
    /* Added 21.6.05 */
    uint8	cs_state;
    uint8	num_bat_bars;
    uint16	bat_type;
    int16	bat_temp;
    uint16	bat_capacity;
    uint16	bat_imp;
    uint16	bat_full_thres;
    uint16	bat_low_thres;
    uint16	mon_alg_adj;
    uint16	mon_param_errors;
    uint32	curr_mon_est2;
};

/* FTD bulk information data2 reply */
struct emsg_ftd_bulk_data2_reply {
    uint32	zero;
    uint32	flags;
    uint32	elapsed_time;
    uint16	txoff_volt;
    uint16	txon_volt;
    uint8	power_state;
    uint8	mon_flags2;
    uint8	mon_flags3;
    uint8	cha_method;
    uint16	last_v_model_mv;
    uint16	phi0_mv;
    int16	delta_phi0_mv;
    uint8	cha_mode;
    uint8	prev_cha_mode;
    uint8	chr_type;
    uint8	prev_chr_type;
    int16	cha_inst_bat_volt;
    uint8	num_chr_checks;
    uint8	chr_rec_state;
    uint32	inst_chr_current;
    uint16	cha_time;
    uint16	avg_chr_volt;
    uint16	chr_current;
    uint8	bat_full;
    uint8	hw_pwm_val;
    uint8	sw_pwm_val;
    uint8	reserved1;
    int16	vbat_osv;
    int16	vbat_csv;
};

/* FTD bulk information data3 reply */
struct emsg_ftd_bulk_data3_reply {
    uint32	zero;
    uint32	flags;
    uint16	conf_bat_footprint;
    uint16	conf_min_current;
    uint16	conf_bat_safety_level;
    uint16	conf_bat_empty_level;
    uint8	conf_bat_bars;    
};

union emsg_ftd_data {
    struct emsg_ftd_data_req	request;
    struct emsg_ftd_data_reply	reply;
};

union emsg_ftd_bulk_data {
    struct emsg_ftd_data_req		request;
    struct emsg_ftd_bulk_data_reply	reply;
    struct emsg_ftd_bulk_data2_reply	reply2;
    struct emsg_ftd_bulk_data3_reply	reply3;
};

#endif


/* Test mode request */
struct auxmsg_test_mode_req {
    uint16	type, subtype;
    uint8	onoff;
};

/* USB charge mode request */
struct auxmsg_usb_charge_mode_req {
    uint16	type, subtype;
    uint8	mode;
    uint8	reserved[3];
};

/* This union combines all possible messages */
union bme_ext_messages {
    union emsg_charger_info	charger_info;
    union emsg_charging_info	charging_info;
    union emsg_battery_info	battery_info;
    union emsg_monitoring_info	monitoring_info;
    struct emsg_monitoring_voltage_req set_monitoring_voltage;
    union emsg_control_read	ctrl_read;
    struct emsg_control_write_req ctrl_write;
    union emsg_adc_read		adc_raw_read;
    union emsg_adc_unit		adc_unit_read;
    union emsg_adc_cal_read	adc_cal_read;
    struct emsg_adc_cal_write_req adc_cal_write;
    struct emsg_psm_feature_req psm_feature;
    union emsg_psm_read		psm_read;
    struct emsg_psm_internal_write_req psm_write;
#if (EM_MON_ADC_LOCK_SUPPORT == TRUE)
    struct emsg_srv_adc_unit_lock_req adc_unit_lock;
#endif
#if (EM_FEA_FAST_ADC_ALIGNMENT == TRUE)
    union emsg_adc_tune		adc_tune;
#endif
#if (EM_FEA_POWER_MANAGEMENT_ENABLED == TRUE)
    union emsg_power		power;
#endif
#if (EM_FEA_THERMOMETER_ENABLED == TRUE)
    union emsg_thermo		thermo;
#endif
#if (EM_FTD_ENABLE == TRUE)
    union emsg_ftd_bulk_data	ftd_data;
#endif
    struct auxmsg_test_mode_req	aux_test;
    struct emsg_measurement_req measurement;
    struct auxmsg_usb_charge_mode_req usb_charge_mode;
};

/*** Indication messages ******************************************************/

/* EM info indication */
struct emsg_info_ind {
    uint16	type, subtype;
    uint32	flags;
    uint8	charger_status;
    uint8	charging_state;
    uint8	charging_mode;
    uint8	batt_max_num_bars;
    uint8	batt_bars_data;
    uint8	batt_power_data;
    uint16      batt_idletime;
    uint16      batt_usetime;
};

/* EM monitoring voltage indication */
struct emsg_mon_voltage_ind {
    uint16	type, subtype;
    uint16	voltage;
    uint16	reserved;
};

/* Temperature indication */
struct emsg_thermo_ind {
    uint16	type, subtype;
    uint32	result;
    uint8	status;
    uint8	reserved[3];
};

/* Function to send Maemo-specific indications */
void bme_info_ext_ind(uint16 indication);

/* Maemo specific message types */
#define BMEIPC_INFO_EXT_IND 0x100

/* Maemo specific indication flags */
#define BMEIPC_FLAG_POSITIVE_RATE              0x0001  /* ---------------1 */

/* Maemo specific indications */
struct emsg_info_ext_ind {
    uint16      type, subtype;
    uint32      flags;
    uint8       positive_rate;
};

#endif
