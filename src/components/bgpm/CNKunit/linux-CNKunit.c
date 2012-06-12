/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/** 
 * @file    linux-CNKunit.c
 * CVS:     $Id$
 * @author  Heike Jagode
 *          jagode@eecs.utk.edu
 * Mods:	<your name here>
 *			<your email address>
 * BGPM / CNKunit component 
 * 
 * Tested version of bgpm (early access)
 *
 * @brief
 *  This file has the source code for a component that enables PAPI-C to 
 *  access hardware monitoring counters for BG/Q through the bgpm library.
 */


#include "linux-CNKunit.h"

/* Declare our vector in advance */
papi_vector_t _CNKunit_vector;

/*****************************************************************************
 *******************  BEGIN PAPI's COMPONENT REQUIRED FUNCTIONS  *************
 *****************************************************************************/

/*
 * This is called whenever a thread is initialized
 */
int
CNKUNIT_init( hwd_context_t * ctx )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_init\n" );
#endif
	
	( void ) ctx;
	return PAPI_OK;
}


/* Initialize hardware counters, setup the function vector table
 * and get hardware information, this routine is called when the 
 * PAPI process is initialized (IE PAPI_library_init)
 */
int
CNKUNIT_init_substrate( int cidx )
{  
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_init_substrate\n" );
#endif

	_CNKunit_vector.cmp_info.CmpIdx = cidx;
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_init_substrate cidx = %d\n", cidx );
#endif
	
	return ( PAPI_OK );
}


/*
 * Control of counters (Reading/Writing/Starting/Stopping/Setup)
 * functions
 */
int
CNKUNIT_init_control_state( hwd_control_state_t * ptr )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_init_control_state\n" );
#endif

	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;
	
	this_state->EventGroup = Bgpm_CreateEventSet();
	CHECK_BGPM_ERROR( this_state->EventGroup, "Bgpm_CreateEventSet" );
	
	return PAPI_OK;
}


/*
 *
 */
int
CNKUNIT_start( hwd_context_t * ctx, hwd_control_state_t * ptr )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_start\n" );
#endif
	( void ) ctx;
	int retval;
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;
	
	retval = Bgpm_Apply( this_state->EventGroup ); 
	CHECK_BGPM_ERROR( retval, "Bgpm_Apply" );

	/* Bgpm_Apply() does an implicit reset; 
	 hence no need to use Bgpm_ResetStart */
	retval = Bgpm_Start( this_state->EventGroup );
	CHECK_BGPM_ERROR( retval, "Bgpm_Start" );
	
	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_stop( hwd_context_t * ctx, hwd_control_state_t * ptr )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_stop\n" );
#endif
	( void ) ctx;
	int retval;
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;
	
	retval = Bgpm_Stop( this_state->EventGroup );
	CHECK_BGPM_ERROR( retval, "Bgpm_Stop" );
	
	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_read( hwd_context_t * ctx, hwd_control_state_t * ptr,
		   long_long ** events, int flags )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_read\n" );
#endif
	( void ) ctx;
	( void ) flags;
	int i, numEvts;
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;
	
	numEvts = Bgpm_NumEvents( this_state->EventGroup );
	if ( numEvts == 0 ) {
#ifdef DEBUG_BGPM
		printf ("Error: ret value is %d for BGPM API function Bgpm_NumEvents.\n", numEvts );
#endif
		//return ( EXIT_FAILURE );
	}
		
	for ( i = 0; i < numEvts; i++ )
		this_state->counts[i] = _common_getEventValue( i, this_state->EventGroup );

	*events = this_state->counts;
	
	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_shutdown( hwd_context_t * ctx )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_shutdown\n" );
#endif
	( void ) ctx;
	return ( PAPI_OK );
}


/* This function sets various options in the substrate
 * The valid codes being passed in are PAPI_SET_DEFDOM,
 * PAPI_SET_DOMAIN, PAPI_SETDEFGRN, PAPI_SET_GRANUL * and PAPI_SET_INHERIT
 */
int
CNKUNIT_ctl( hwd_context_t * ctx, int code, _papi_int_option_t * option )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_ctl\n" );
#endif
	( void ) ctx;
	( void ) code;
	( void ) option;
	return ( PAPI_OK );
}



/*
 *
 */
int
CNKUNIT_update_control_state( hwd_control_state_t * ptr,
						   NativeInfo_t * native, int count,
						   hwd_context_t * ctx )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_update_control_state: count = %d\n", count );
#endif
	( void ) ctx;
	int retval, index, i;
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;
	
	// Delete and re-create BGPM eventset
	_common_deleteRecreate( &this_state->EventGroup );
		
	// otherwise, add the events to the eventset
	for ( i = 0; i < count; i++ ) {
		index = ( native[i].ni_event & PAPI_NATIVE_AND_MASK & PAPI_COMPONENT_AND_MASK ) + OFFSET;
		
		native[i].ni_position = i;
		
#ifdef DEBUG_BGQ
		printf("CNKUNIT_update_control_state: ADD event: i = %d, index = %d\n", i, index );
#endif
		
		/* Add events to the BGPM eventGroup */
		retval = Bgpm_AddEvent( this_state->EventGroup, index );
		CHECK_BGPM_ERROR( retval, "Bgpm_AddEvent" );
	}
	
	return ( PAPI_OK );
}


/*
 * This function has to set the bits needed to count different domains
 * In particular: PAPI_DOM_USER, PAPI_DOM_KERNEL PAPI_DOM_OTHER
 * By default return PAPI_EINVAL if none of those are specified
 * and PAPI_OK with success
 * PAPI_DOM_USER is only user context is counted
 * PAPI_DOM_KERNEL is only the Kernel/OS context is counted
 * PAPI_DOM_OTHER  is Exception/transient mode (like user TLB misses)
 * PAPI_DOM_ALL   is all of the domains
 */
int
CNKUNIT_set_domain( hwd_control_state_t * cntrl, int domain )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_set_domain\n" );
#endif
	int found = 0;
	( void ) cntrl;

	if ( PAPI_DOM_USER & domain )
		found = 1;

	if ( PAPI_DOM_KERNEL & domain )
		found = 1;

	if ( PAPI_DOM_OTHER & domain )
		found = 1;

	if ( !found )
		return ( PAPI_EINVAL );

	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_reset( hwd_context_t * ctx, hwd_control_state_t * ptr )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_reset\n" );
#endif
	( void ) ctx;
	int retval;
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ptr;

	/* we can't simply call Bgpm_Reset() since PAPI doesn't have the 
	 restriction that an EventSet has to be stopped before resetting is
	 possible. However, BGPM does have this restriction. 
	 Hence we need to stop, reset and start */
	retval = Bgpm_Stop( this_state->EventGroup );
	CHECK_BGPM_ERROR( retval, "Bgpm_Stop" );
	
	retval = Bgpm_ResetStart( this_state->EventGroup );
	CHECK_BGPM_ERROR( retval, "Bgpm_ResetStart" );

	return ( PAPI_OK );
}


/*
 * PAPI Cleanup Eventset
 *
 * Destroy and re-create the BGPM / CNKunit EventSet
 */
int
CNKUNIT_cleanup_eventset( hwd_control_state_t * ctrl )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_cleanup_eventset\n" );
#endif
	
	CNKUNIT_control_state_t * this_state = ( CNKUNIT_control_state_t * ) ctrl;
		
	// create a new empty bgpm eventset
	// reason: bgpm doesn't permit to remove events from an eventset; 
	// hence we delete the old eventset and create a new one
	_common_deleteRecreate( &this_state->EventGroup ); // HJ try to use delete() only
	
	return ( PAPI_OK );
}


/*
 * Native Event functions
 */
int
CNKUNIT_ntv_enum_events( unsigned int *EventCode, int modifier )
{
#ifdef DEBUG_BGQ
//	printf( "CNKUNIT_ntv_enum_events\n" );
#endif
	int cidx = PAPI_COMPONENT_INDEX( *EventCode );

	switch ( modifier ) {
	case PAPI_ENUM_FIRST:
		*EventCode = PAPI_NATIVE_MASK | PAPI_COMPONENT_MASK( cidx );

		return ( PAPI_OK );
		break;

	case PAPI_ENUM_EVENTS:
	{
		int index = ( *EventCode & PAPI_NATIVE_AND_MASK & PAPI_COMPONENT_AND_MASK ) + OFFSET;

		if ( index < CNKUNIT_MAX_COUNTERS ) {
			*EventCode = *EventCode + 1;
			return ( PAPI_OK );
		} else
			return ( PAPI_ENOEVNT );

		break;
	}
	default:
		return ( PAPI_EINVAL );
	}
	return ( PAPI_EINVAL );
}


/*
 *
 */
int
CNKUNIT_ntv_name_to_code( char *name, unsigned int *event_code )
{
#ifdef DEBUG_BGQ
	printf( "CNKUNIT_ntv_name_to_code\n" );
#endif
	int ret;
	
	/* Return event id matching a given event label string */
	ret = Bgpm_GetEventIdFromLabel ( name );
	
	if ( ret <= 0 ) {
#ifdef DEBUG_BGPM
		printf ("Error: ret value is %d for BGPM API function '%s'.\n",
				ret, "Bgpm_GetEventIdFromLabel" );
#endif
		return PAPI_ENOEVNT;
	}
	else if ( ret < OFFSET || ret > CNKUNIT_MAX_COUNTERS ) // not a CNKUnit event
		return PAPI_ENOEVNT;
	else
		*event_code = ( ret - OFFSET ) | PAPI_NATIVE_MASK | PAPI_COMPONENT_MASK( _CNKunit_vector.cmp_info.CmpIdx ) ;
	
	return PAPI_OK;
}


/*
 *
 */
int
CNKUNIT_ntv_code_to_name( unsigned int EventCode, char *name, int len )
{
#ifdef DEBUG_BGQ
	//printf( "CNKUNIT_ntv_code_to_name\n" );
#endif
	int index;
	
	index = ( EventCode & PAPI_NATIVE_AND_MASK & PAPI_COMPONENT_AND_MASK ) + OFFSET;

	if ( index >= MAX_COUNTERS )
		return PAPI_ENOEVNT;

	strncpy( name, Bgpm_GetEventIdLabel( index ), len );
	//printf("----%s----\n", name);
	
	if ( name == NULL ) {
#ifdef DEBUG_BGPM
		printf ("Error: ret value is NULL for BGPM API function Bgpm_GetEventIdLabel.\n" );
#endif
		return PAPI_ENOEVNT;
	}
	
	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_ntv_code_to_descr( unsigned int EventCode, char *name, int len )
{
#ifdef DEBUG_BGQ
	//printf( "CNKUNIT_ntv_code_to_descr\n" );
#endif
	int retval, index;
	
	index = ( EventCode & PAPI_NATIVE_AND_MASK & PAPI_COMPONENT_AND_MASK ) + OFFSET;
	
	retval = Bgpm_GetLongDesc( index, name, &len );
	CHECK_BGPM_ERROR( retval, "Bgpm_GetLongDesc" );						 
	
	return ( PAPI_OK );
}


/*
 *
 */
int
CNKUNIT_ntv_code_to_bits( unsigned int EventCode, hwd_register_t * bits )
{
#ifdef DEBUG_BGQ
	//printf( "CNKUNIT_ntv_code_to_bits\n" );
#endif
	
	return ( PAPI_OK );
}


/*
 *
 */
papi_vector_t _CNKunit_vector = {
	.cmp_info = {
				 /* default component information (unspecified values are initialized to 0) */
				 .name = "$Id: linux-CNKunit.c,v 1.2 2011/03/18 21:40:22 jagode Exp $",
				 .version = "$Revision: 1.2 $",
				 .CmpIdx = 0,
				 .num_cntrs = CNKUNIT_MAX_COUNTERS,
				 .num_mpx_cntrs = PAPI_MPX_DEF_DEG,
				 .default_domain = PAPI_DOM_USER,
				 .available_domains = PAPI_DOM_USER | PAPI_DOM_KERNEL,
				 .default_granularity = PAPI_GRN_THR,
				 .available_granularities = PAPI_GRN_THR,
		
				 .hardware_intr_sig = PAPI_INT_SIGNAL,
				 .hardware_intr = 1,
				 .kernel_multiplex = 0,

				 /* component specific cmp_info initializations */
				 .fast_real_timer = 0,
				 .fast_virtual_timer = 0,
				 .attach = 0,
				 .attach_must_ptrace = 0,
				 
				 }
	,

	/* sizes of framework-opaque component-private structures */
	.size = {
			 .context = sizeof ( CNKUNIT_context_t ),
			 .control_state = sizeof ( CNKUNIT_control_state_t ),
			 .reg_value = sizeof ( CNKUNIT_register_t ),
			 .reg_alloc = sizeof ( CNKUNIT_reg_alloc_t ),
			 }
	,
	/* function pointers in this component */
	.init = CNKUNIT_init,
	.init_substrate = CNKUNIT_init_substrate,
	.init_control_state = CNKUNIT_init_control_state,
	.start = CNKUNIT_start,
	.stop = CNKUNIT_stop,
	.read = CNKUNIT_read,
	.shutdown = CNKUNIT_shutdown,
	.cleanup_eventset = CNKUNIT_cleanup_eventset,
	.ctl = CNKUNIT_ctl,

	.update_control_state = CNKUNIT_update_control_state,
	.set_domain = CNKUNIT_set_domain,
	.reset = CNKUNIT_reset,

	.ntv_name_to_code = CNKUNIT_ntv_name_to_code,
	.ntv_enum_events = CNKUNIT_ntv_enum_events,
	.ntv_code_to_name = CNKUNIT_ntv_code_to_name,
	.ntv_code_to_descr = CNKUNIT_ntv_code_to_descr,
	.ntv_code_to_bits = CNKUNIT_ntv_code_to_bits,
	.ntv_bits_to_info = NULL,
};
