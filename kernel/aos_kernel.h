#ifndef _AOS_KERNEL_H_
#define _AOS_KERNEL_H_

/*************************************************************************************************/

typedef enum
{
  AOS_ERR_NONE          = 0,
  AOS_ERR_UNKNOWN

} aos_err_t;

/*************************************************************************************************/

typedef enum
{
  AOS_TASK_READY        = 0,
  AOS_TASK_BLOCKED,
  AOS_TASK_RUNNING

} aos_task_state_t;

/*************************************************************************************************/

typedef struct
{
  aos_sp_t            *stack_pointer;
  uint32_t            *stack_start;
  uint32_t             stack_size;

  void                (*entry)(void *);
  void                *arg;

  aos_task_state_t    state;
  uint8_t             priority;
  uint32_t            delay_ticks;

} aos_task_t;

/*************************************************************************************************/

typedef struct
{
  aos_task_t          tasks[AOS_CFG_MAX_TASKS];
  uint32_t            tasks_used;

} aos_kernel_t;

#endif
