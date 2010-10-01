/*
 * $Id: client_ipc.h 1988 2009-06-22 15:05:05Z spiiroin $
 *
 * Definitions for client/server IPC.
 */

#ifndef _CLIENT_IPC
#define _CLIENT_IPC

#include <stdarg.h>

#define BME_SRV_SOCK_PATH	"/tmp/.bmesrv"
#define BME_SRV_COOKIE		"BMentity"
#define BME_SRV_MAX_REQUEST	512
#define BME_SRV_CONN_TIMEOUT	1		/* seconds */

/* System message codes (not related to battery management) */
#define	BME_SYSMSG_GET_PID	 0x8000
#define BME_SYSMSG_PROXY_OPEN    0x8001
#define BME_SYSMSG_PROXY_CLOSE   0x8002
#define BME_SYSMSG_PROXY_GETTIME 0x8003

/*
 * Additional (non-system) message codes used by BME.
 * They must not overlap with constants from em_isi.h
 */
#define BME_AUXMSG_TEST_MODE_CTRL	0x40	// Test mode control
#define BME_AUXMSG_FTD_REQ		0x41	// FTD information request
#define BME_AUXMSG_FTD_BULK_REQ		0x42	// FTD bulk information request
#define BME_AUXMSG_FTD_BULK_REQ2	0x43	// FTD bulk information request2
#define BME_AUXMSG_FTD_BULK_REQ3	0x44	// FTD bulk information request3

#define BME_AUXMSG_EM_USB_MODE		0x48	// EM USB mode control

/* Test mode on/off */
#define ACC_TEST_MODE_OFF		0
#define ACC_TEST_MODE_ON		1

/* Flags for EM FTD bulk data request */
#define EM_FTD_REQ_FLAG_STATUS			1
#define EM_FTD_REQ_FLAG_INST_BAT_VOLT		2
#define EM_FTD_REQ_FLAG_REMAIN_STBY_MINUTES	4
#define EM_FTD_REQ_FLAG_NUMBER_BAT_LOW_WARN	8
#define EM_FTD_REQ_FLAG_MISC_MON_INT_FLAGS1	0x10
#define EM_FTD_REQ_FLAG_CALC_VOLT_LEVEL		0x20
#define EM_FTD_REQ_FLAG_WARN_COUNT		0x40
#define EM_FTD_REQ_FLAG_DMF_BAT_VOLT		0x80
#define EM_FTD_REQ_FLAG_BAT_BOOT_VOLT		0x100
#define EM_FTD_REQ_FLAG_CALC_BAT_BAR		0x200
#define EM_FTD_REQ_FLAG_VOLT_AT_FIRST_BAT_LOW	0x400
#define EM_FTD_REQ_FLAG_CURRENT_MON_EST1	0x800
#define EM_FTD_REQ_FLAG_CHARGED_AMOUNT		0x1000
#define EM_FTD_REQ_FLAG_POWEROFF_LOG_RESERVED	0x2000	// Not supported yet
#define EM_FTD_REQ_FLAG_LOWEST_V_TXOFF		0x4000
#define EM_FTD_REQ_FLAG_LOWEST_V_TXON		0x8000
#define EM_FTD_REQ_FLAG_LARGEST_DV		0x10000
#define EM_FTD_REQ_FLAG_BATT_BAR_LOG_MASK	0x20000
#define EM_FTD_REQ_FLAG_PREV_BATT_BAR_LEV	0x40000
#define EM_FTD_REQ_FLAG_BATT_LOW_REASON		0x80000
/* Added 21.6.05 */
#define EM_FTD_REQ_FLAG_CS_STATE		0x100000
#define EM_FTD_REQ_FLAG_NUM_OF_BAT_BARS		0x200000
#define EM_FTD_REQ_FLAG_BAT_TYPE		0x400000
#define EM_FTD_REQ_FLAG_CURRENT_BAT_TEMP	0x800000
#define EM_FTD_REQ_FLAG_BAT_CAPACITY		0x1000000
#define EM_FTD_REQ_FLAG_BAT_IMP			0x2000000
#define EM_FTD_REQ_FLAG_BAT_FULL_THRES		0x4000000
#define EM_FTD_REQ_FLAG_BAT_LOW_THRES		0x8000000
#define EM_FTD_REQ_FLAG_MON_ALG_ADJ		0x10000000
#define EM_FTD_REQ_FLAG_PARAM_ERRORS		0x20000000
#define EM_FTD_REQ_FLAG_CURRENT_MON_EST2	0x40000000

/* Flags for EM FTD bulk request2 */
#define EM_FTD_REQ2_FLAG_EST_TX_OFF		1
#define EM_FTD_REQ2_FLAG_EST_TX_ON		2
#define EM_FTD_REQ2_FLAG_BAT_POW_IND		4
#define EM_FTD_REQ2_FLAG_MISC_MON_INT_FLAGS2	8
#define EM_FTD_REQ2_FLAG_MISC_MON_INT_FLAGS3	0x10
#define EM_FTD_REQ2_FLAG_MON_VOLT		0x20
#define EM_FTD_REQ2_FLAG_ELAPSED_TIME		0x40
#define EM_FTD_REQ2_FLAG_PHI_VARIABLE		0x80
#define EM_FTD_REQ2_FLAG_DELTA_PHI_VARIABLE	0x100
#define EM_FTD_REQ2_FLAG_CHA_METHOD		0x200
#define EM_FTD_REQ2_FLAG_PRESENT_CHA_MODE	0x400
#define EM_FTD_REQ2_FLAG_PREVIOUS_CHA_MODE	0x800
#define EM_FTD_REQ2_FLAG_PRESENT_CHR_TYPE	0x1000
#define EM_FTD_REQ2_FLAG_PREVIOUS_CHR_TYPE	0x2000
#define EM_FTD_REQ2_FLAG_CHA_INST_BAT_VOLT	0x4000
#define EM_FTD_REQ2_FLAG_NUMBER_CHR_CHECKS	0x8000
#define EM_FTD_REQ2_FLAG_CHR_REC_STATE		0x10000
#define EM_FTD_REQ2_FLAG_INST_CHR_CURRENT	0x20000
#define EM_FTD_REQ2_FLAG_BAT_FULL		0x40000
#define EM_FTD_REQ2_FLAG_CHA_TIME		0x80000
#define EM_FTD_REQ2_FLAG_AVERAGE_CHR_VOLT	0x100000
#define EM_FTD_REQ2_FLAG_CALC_CHR_CURRENT	0x200000
#define EM_FTD_REQ2_FLAG_HW_PWM_VALUE		0x400000
#define EM_FTD_REQ2_FLAG_SW_PWM_VALUE		0x800000
#define EM_FTD_REQ2_FLAG_OS_PWM_BAT_VOLT	0x1000000
#define EM_FTD_REQ2_FLAG_CS_PWM_BAT_VOLT	0x2000000

/* Flags for EM FTD bulk request3 */
#define	EM_FTD_REQ3_FLAG_CONF_BAT_FOOTPRINT	1
#define	EM_FTD_REQ3_FLAG_CONF_BAT_BARS		2
#define	EM_FTD_REQ3_FLAG_CONF_MIN_CURRENT	4
#define	EM_FTD_REQ3_FLAG_CONF_BAT_SAFETY_LEVEL	8
#define	EM_FTD_REQ3_FLAG_CONF_BAT_EMPTY_LEVEL	0x10

/*** General messages *********************************************************/

/* Generic message */
typedef struct {
    uint16	type, subtype;
} tBMEmsgGeneric;

/* Server PID reply */
typedef struct {
    uint32	zero;
    uint32	pid;
} tBMEreplyServerPID;

typedef union {
    tBMEmsgGeneric request;
    tBMEreplyServerPID reply;
} tBMEmsgServerPID;


/*** Function prototypes ******************************************************/

/* Client-side functions */
int bme_connect(void);
int bme_get_server_pid(void);
void bme_disconnect(void);
int bme_write(const void *msg, int bytes);
int bme_read(void *msg, int bytes);
int bme_send_get_reply(const void *smsg, int sbytes,
		       void *rmsg, int rbytes, int *rbytes_act);
int bme_packet_write(int fd, const void *msg, int bytes);
int bme_packet_read(int fd, void *msg, int bytes);

int bme_cookie_write(int fd, const char *cookie);
int bme_cookie_read(int fd, const char *cookie);

void bme_set_logging_function(void (*fn)(int,const char *,va_list));

#endif
