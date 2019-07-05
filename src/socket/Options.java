package socket;

public enum Options {

    SO_DEBUG , SO_BROADCAST , SO_REUSEADDR , SO_KEEPALIVE , SO_LINGER , 
    SO_OOBINLINE , SO_SNDBUF , SO_RCVBUF , SO_DONTROUTE , SO_RCVLOWAT , SO_RCVTIMEO , SO_SNDLOWAT ,
    SO_SNDTIMEO , IP_ADD_MEMBERSHIP , IP_BLOCK_SOURCE , IP_DROP_MEMBERSHIP , IP_DROP_SOURCE_MEMBERSHIP ,
    IP_MULTICAST_IF , IP_MULTICAST_LOOP , IP_MULTICAST_TTL , IP_UNBLOCK_SOURCE ,
    MCAST_BLOCK_SOURCE , MCAST_JOIN_GROUP , MCAST_JOIN_SOURCE_GROUP , MCAST_LEAVE_GROUP , MCAST_LEAVE_SOURCE_GROUP ,
    MCAST_UNBLOCK_SOURCE ;

    public int getOption () {

        switch (this) {

            case SO_DEBUG:
                return so_debug();
            case SO_BROADCAST:
                return so_broadcast();
            case SO_REUSEADDR:
                return so_reuseaddr();
            case SO_KEEPALIVE:
                return so_keepalive();
            case SO_LINGER:
                return so_linger();
            case SO_OOBINLINE:
                return so_oobinline();
            case SO_SNDBUF:
                return so_sndbuf();
            case SO_RCVBUF:
                return so_recvbuf();
            case SO_DONTROUTE:
                return so_dontroute();
            case SO_RCVLOWAT:
                return so_rcvlowat();
            case SO_RCVTIMEO:
                return so_rcvtimeo();
            case SO_SNDLOWAT:
                return so_sndlowat();
            case SO_SNDTIMEO:
                return so_sndtimeo();
            case IP_ADD_MEMBERSHIP:
                return ip_add_membership();
            case IP_BLOCK_SOURCE:
                return ip_block_source();
            case IP_DROP_MEMBERSHIP:
                return ip_drop_membership();
            case IP_DROP_SOURCE_MEMBERSHIP:
                return ip_drop_source_membership();
            case IP_MULTICAST_IF:
                return ip_multicast_if();
            case IP_MULTICAST_LOOP:
                return ip_multicast_loop();
            case IP_MULTICAST_TTL:
                return ip_multicast_ttl();
            case IP_UNBLOCK_SOURCE:
                return ip_unblock_source();
            case MCAST_BLOCK_SOURCE:
                return mcast_block_source();
            case MCAST_JOIN_GROUP:
                return mcast_join_group();
            case MCAST_JOIN_SOURCE_GROUP:
                return mcast_join_source_group();
            case MCAST_LEAVE_GROUP:
                return mcast_leave_group();
            case MCAST_LEAVE_SOURCE_GROUP:
                return mcast_leave_source_group();
            case MCAST_UNBLOCK_SOURCE:
                return mcast_unblock_source();
            
            default:
                return -1;

        }
    }


    private native int so_debug();

    private native int so_broadcast();

    private native int so_reuseaddr();

    private native int so_keepalive();

    private native int so_linger();

    private native int so_oobinline();

    private native int so_sndbuf();

    private native int so_recvbuf();

    private native int so_dontroute();

    private native int so_rcvlowat();

    private native int so_rcvtimeo();

    private native int so_sndlowat();

    private native int so_sndtimeo();

    private native int ip_add_membership();

    private native int ip_block_source();
    
    private native int ip_drop_membership();

    private native int ip_drop_source_membership();

    private native int ip_multicast_if();

    private native int ip_multicast_loop();

    private native int ip_multicast_ttl();

    private native int ip_unblock_source();

    private native int mcast_block_source();

    private native int mcast_join_group();

    private native int mcast_join_source_group();

    private native int mcast_leave_group();

    private native int mcast_leave_source_group();

    private native int mcast_unblock_source();

}