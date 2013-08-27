

#ifndef CallbackFunctions__H___
#define CallbackFunctions__H___


#include <errno.h>
#include <libxio.h>
#include "cJXCtx.h"
#include "Utils.h"
#include "cJXSession.h"


/*
 * this callback is called by xio library once a server recieves new session request.
 * @cb_prv_data: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_new_session_callback(struct xio_session *session,
		struct xio_new_session_req *req,
		void *cb_prv_data);

/*
 * this callback is called by xio library once server finishes sending a msg.
 * @cb_prv_data: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_msg_send_complete_callback(struct xio_session *session,
		struct xio_msg *msg,
		void *cb_prv_data);
/*
 * this callback is called by xio library once a server/client recieves new msg.
 * @cb_prv_data: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_msg_callback(struct xio_session *session,
		struct xio_msg *msg,
		int more_in_batch,
		void *cb_prv_data);
/*
 * this callback is called by xio library once there is msg error.
 * @conn_user_context: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_msg_error_callback(struct xio_session *session,
            enum xio_status error,
            struct xio_msg  *msg,
            void *conn_user_context);
/*
 * this callback is called by xio library once a client recieves notice that a session is established
 * with the server.
 * @cb_prv_data: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_session_established_callback(struct xio_session *session,
		struct xio_new_session_rsp *rsp,
		void *cb_prv_data);
/*
 * this callback is called by xio library once a server/client recieve session event.
 * @cb_prv_data: represents class implementing Contexable interface. For example: cJXServer, cJXSession.
 * Contexable holds pointer to cJXCtx class. Through it we can access buffer which is shared with Java.
 */
int on_session_event_callback(struct xio_session *session,
		struct xio_session_event_data *event_data,
		void *cb_prv_data);

void doneEventCreating(cJXCtx *ctx);



#endif // ! CallbackFunctions__H___
