// This program is a part of NT mudlib

/*********************<   i2d.h     >*********************
#define MUD                     0
#define STREAM                  1
#define DATAGRAM                2
#define STREAM_BINARY           3
#define DATAGRAM_BINARY         4
//-----------------------------------------------
#define I2D_MUD_SERVER          ({"113.31.21.157", 5004})
#define MUDLIST_UPDATE_INTERVAL 600
#define REFRESH_INCOMING_TIME   3*60*60
//----------------------λԪ������-------------------------
#define GB_CODE                 1       // gbվ��
#define ANTI_AD                 2       // ����������վ��
#define IGNORED                 4       // ����վ������Ϣվ��
#define SHUTDOWN                8       // �رյ�վ��
#define ONLINE                  16      // ������վ��
#define DISCONNECT              32      // ʧȥ��ϵ��վ��
#define ENCODE_CONFIRM          64      // ϵͳ�Զ��ж�gb/big5���վ��
***********************************************************/
#define MUD_GROUP    "�������"
#define MUD_ENCODING    "GB"
#define MUD_HOST_NAME    "hy.21sun.net"
#define MUD_LOCATION    "china"



#include <ansi.h>
#include <i2d.h>
#include <socket_err.h>
#include <origin.h>
#include <mudlib.h>


inherit F_DBASE;

#define NCH_CHANNEL(x) CHANNEL_D->channel_broadcast("nch", "I2D ���飺"+(string)x)

nosave string my_address;
nosave string localhost = "59.37.59.254";      // mud��ip��ַ
nosave int udp_port = 1897;       // mud��udp�˿�

mapping mudlist=([]);
nosave mapping incoming_mudlist=([]);
string save_path = "/data/network/";

int udp_socket,refresh_limit=time(),debug;

int query_refresh_limit() { return refresh_limit; }
mapping query_mudlist() { return mudlist; }
mapping query_incoming_mudlist() { return incoming_mudlist; }

// prototype
varargs string SAVE_PATH(string name,int flag);
varargs string *fetch_mudname(string arg,int flag);
string get_mud_name(mapping info);
int compare_mud_info(mapping info);

void receive_mudlist_request(mapping info);
void receive_mudlist_answer(mapping info);
void receive_ping_request(mapping info);
void receive_ping_answer(mapping info);
void receive_gchannel_msg(mapping info);
void receive_shutdown(mapping info);
void receive_gwiz_msg(mapping info);
void receive_warning(mapping info);
void receive_startup(mapping info);
void receive_gtell(mapping info);
void receive_affirmation(mapping info);
void receive_support_request(mapping info);
void receive_support_answer(mapping info);
void receive_locate_request(mapping info);
void receive_locate_answer(mapping info);
void receive_rwho_answer(mapping info);
void receive_rwho_request(mapping info);


void send_ping_request(string target, int port);
void send_mudlist_request(string target, int port);
void read_callback(int socket,string info,string address);
void send_shutdown(string target, int port);
void send_startup(string targ,int port);
varargs void send_warning(string targ,int port,string msg,string fakehost);
void refresh_ping_buffer();
void refresh_buffers();
protected void set_mudlist(string name,mapping info);
protected void set_incoming_mudlist(string name,mapping info);
protected void resolve_callback(string addr, string resolved, int key);

//-------------------------------------------------------------------------------------------
nosave mapping service_handler = ([
    "mudlist_q" :       (: receive_mudlist_request :),
    "mudlist_a" :       (: receive_mudlist_answer :),
    "ping_q" :          (: receive_ping_request :),
    "ping_a" :          (: receive_ping_answer :),
    "gchannel" :        (: receive_gchannel_msg :),
    "shutdown" :        (: receive_shutdown :),
    "gwizmsg" :         (: receive_gwiz_msg :),
    "warning" :         (: receive_warning :),
    "startup" :         (: receive_startup :),
    "gtell"     :       (: receive_gtell :),
    "affirmation_a":    (: receive_affirmation :),
    "support_q" :       (: receive_support_request :),
    "support_a" :       (: receive_support_answer :),
    "locate_q" :        (: receive_locate_request :),
    "locate_a" :        (: receive_locate_answer :),
    "rwho_a" :          (: receive_rwho_answer :),
    "rwho_q" :          (: receive_rwho_request :),

]);
nosave mapping ping_buffer=([]);
nosave mapping affirmation_buffer=([]);
nosave mapping rwho_buffer=([]);
nosave mapping gtell_buffer=([]);
nosave mapping msg_buffer=([]);
//-------------------------------------------------------------------------------------------

#define GTELL_B         1
#define PING_B          2
#define AFFIRMATION_B   3
#define RWHO_B          4

void restore()
{
        restore_object(SAVE_PATH("i2d"));
}

int save()
{
        return save_object(SAVE_PATH("i2d"));
}


int check_dns_fake(string name)
{
        return sizeof(fetch_mudname(name))-1;
}

// �Զ����� incoming_mudlist �� mudlist
protected void refresh_incoming()
{
        string name;
        mapping info;
        foreach(name , info in incoming_mudlist)
        if(info["CONNECTION"] > (REFRESH_INCOMING_TIME/MUDLIST_UPDATE_INTERVAL)-8 )
        {
                map_delete(info,"CONNECTION");
                mudlist[name]=info;
                map_delete(incoming_mudlist,name);
        }
        foreach( name,info in mudlist)
        if( info["HOSTADDRESS"]!=my_address && info["HOSTADDRESS"]!=localhost && ((time()-info["LASTESTCONTACT"]> 259200) ||
                (time()-info["LASTESTCONTACT"]>5*60*60 && check_dns_fake(info["NAME"])>0 ) ))
                map_delete(mudlist,name);
        incoming_mudlist=([]);
        refresh_limit=time();
        save();
}

void delete_mudlist(string mud)
{
        map_delete(mudlist,mud);
        save();
}

void add_incoming_mudlist(string address, int port)
{
        send_ping_request(address, port);
        send_mudlist_request(address, port);
}

void send_all_shutdown()
{
        string mud;
        mapping info;
        // ȡ�� mudlist ��������Ѷ
        if( mapp(mudlist) )
                foreach(mud, info in mudlist)
                send_shutdown(
                    info["HOSTADDRESS"],
                    info["PORTUDP"]
                );

        // ȡ�� incoming_mudlist ������Ѷ
        if( mapp(incoming_mudlist) )
                foreach(mud, info in incoming_mudlist)
                send_shutdown(
                    info["HOSTADDRESS"],
                    info["PORTUDP"]
                );
}

// ��ʱ���� mud ��Ѷ
//protected void update_info()
void update_info()
{
        string mud;
        mapping info;
        // ȡ�� mudlist ��������Ѷ
        if( mapp(mudlist) )
                foreach(mud, info in mudlist)
                send_ping_request(
                    info["HOSTADDRESS"],
                    info["PORTUDP"]
                );
        // ȡ�� incoming_mudlist ������Ѷ
        if( mapp(incoming_mudlist) )
                foreach(mud, info in incoming_mudlist)
                send_ping_request(
                    info["HOSTADDRESS"],
                    info["PORTUDP"]
                );
        refresh_buffers();
        // �� REFRESH_INCOMING_TIME �����ʱ�䵽�Զ�������������� mud
        if( time()- refresh_limit > REFRESH_INCOMING_TIME )
        {
                refresh_incoming();

                // �ٴ�ȡ�� incoming_mudlist
                foreach(string t, mapping d in mudlist)
                send_mudlist_request(d["HOSTADDRESS"],d["PORTUDP"]);
        }

        // ��ʱ MUDLIST_UPDATE_INTERVAL �����һ����Ѷ
        //call_out((: update_info :),MUDLIST_UPDATE_INTERVAL);
        SCHEDULE_D->set_event(MUDLIST_UPDATE_INTERVAL, 1, this_object(), "update_info");
}

// һ��ʼ���ⱻ���� , ��û����� :Q
void create()
{
        seteuid(getuid());
        // ȡ�� save ����������
        restore();
        resolve( query_host_name(), "resolve_callback" );
        // ��ʼ�� UDP port
        if( (udp_socket = socket_create(DATAGRAM, (: read_callback :) )) < 0 )
        {
                NCH_CHANNEL("UDP socket created fail.\n");
                error("Unable to create UDP socket.\n");
        }
        while( EEADDRINUSE==socket_bind(udp_socket, udp_port) )
                udp_port++;

        NCH_CHANNEL("��ʼ����� , ʹ�� UDP port: "+udp_port);
        refresh_buffers();
        // ���ж�ʱ���µĺ�ʽ
        refresh_ping_buffer();
        // �ͳ� startup
        foreach(string mud,mapping info in mudlist)
        {
                mudlist[mud]["STATUS"]&=~ENCODE_CONFIRM;
                send_startup(info["HOSTADDRESS"],info["PORTUDP"]);
        }

        // �ͳ� ping Ҫ��� server
        //send_ping_request(I2D_MUD_SERVER[0],I2D_MUD_SERVER[1]);
        // ��Ԥ�� server ȡ�� mudlist
        //send_mudlist_request(I2D_MUD_SERVER[0],I2D_MUD_SERVER[1]);
        // ��ץһ�� incoming_mudlist
        foreach(string t, mapping d in mudlist)
        send_mudlist_request(d["HOSTADDRESS"],d["PORTUDP"]);
        // ��ʼ���ڸ�����Ѷ
        evaluate((: update_info :));
}

// destruct �� simul_efun ���� call ���
int remove()
{
        send_all_shutdown();
        socket_close(udp_socket);
        return save();
}

public void mud_shutdown()
{
        send_all_shutdown();
        socket_close(udp_socket);
        save();
}

protected void resolve_callback(string addr, string resolved, int key)
{
        my_address = resolved;
}

// UDP port �ս����Ķ������Ⱦ�����
protected void read_callback(int socket,string info,string address)
{
        string *infoclip,title,datas;
        mixed handler;
        mapping infomap=([]);

#ifdef __PACKAGE_ANSI__
        info=ansi(info);
#endif
        if( debug) NCH_CHANNEL( sprintf( "socket %d\ninfo %s\naddress %s", socket, info, address ));
        // �������ʽ�Ƿ���ȷ
        if(!sscanf(info,"@@@%s@@@%*s",info)) return;
        // ��һ����ר���� service ����
        infoclip = explode(info,"||");
        // ��վ�޷�����ķ����������
        if(!infoclip || undefinedp(handler = service_handler[infoclip[0]]) )
        {
                NCH_CHANNEL(sprintf("Unknow I2 service %s from %s ",infoclip[0],address));
                return;
        }
        // �� string -> mapping �Ա����´���
        foreach(string data in infoclip)
        if( sscanf(data, "%s:%s", title, datas)==2 ) infomap[title] = datas;
        // �����ʹ� package �� IP ��¼�� mapping info ��
        sscanf(address, "%s %*s", address);
        if( (address+"" == my_address || address+"" == localhost)&& infomap["PORTUDP"]==udp_port+"" )
                return;
        infomap["HOSTADDRESS"] = address;
        if(debug) NCH_CHANNEL(sprintf("�յ�%s\n%O\n",address,info));
        // ������ service ר�õ� function
        evaluate(handler,infomap);

}

// �ͳ�ѶϢ�õĺ�ʽ
void send_udp(string targ, mixed port, string service, mapping info)
{
        int socket;
        string title,data,msg;
        string mudname;

        // ����������û�еķ���
        if( undefinedp(service_handler[service]) )
        {
                NCH_CHANNEL("Unknow Service.");
                error("Invalid intermud Services.\n");
        }

        // ���������ϸ��Լ�.
        //NCH_CHANNEL(sprintf("ip:%s port:%s services:%s",targ,port,service));
        //NCH_CHANNEL(sprintf("%O",typeof(port)));
        if( (targ == my_address || targ == localhost) && port == udp_port )
                //      if( service!="ping_a" && service!="ping_q" )
                return;


        // ���� socket �Կ�ʼ����
        socket = socket_create(DATAGRAM, "read_callback");
        if( !socket ) return;

        // �� mapping -> string
        msg = service;
        if( mapp(info) ) {
                foreach(title, data in info) {
                        if( !stringp(title) || !stringp(data) ) continue;
                        msg += sprintf("||%s:%s",title,data);
                }
        }
        mudname = targ+":"+port;
        /*
        if( !undefinedp(mudlist[mudname]) && ( (mudlist[mudname]["STATUS"]& GB_CODE) || ( !undefinedp(mudlist[mudname]["ENCODING"]) && lower_case(mudlist[mudname]["ENCODING"])=="gb") ))
                //if( (mudlist[mudname]["STATUS"]& GB_CODE) || ( !undefinedp(mudlist[mudname]["ENCODING"]) && lower_case(mudlist[mudname]["ENCODING"])=="gb") )
                msg = (string)LANGUAGE_D->toGB(msg);
        */
        if( !undefinedp(mudlist[mudname]) && ( /*!(mudlist[mudname]["STATUS"]& GB_CODE) ||*/ ( !undefinedp(mudlist[mudname]["ENCODING"]) && lower_case(mudlist[mudname]["ENCODING"])=="big5") ))
                msg = (string)LANGUAGE_D->toBig5(msg);  // ת����big5�뷢����Ϣ

        // �ͳ�ѶϢ.
        socket_write(socket, "@@@" + msg + "@@@", targ + " " + port);
        // debug msg
        if(debug) NCH_CHANNEL(sprintf("�ͳ���%s:\n%s\n"+HIY+"%O\n"+NOR,targ,port+"",msg));
        // �رմ�����ϵ� socket
        socket_close(socket);


}
// �� mapping package ��ȡ�� mud name
string get_mud_name(mapping info)
{
        return info["HOSTADDRESS"]+":"+info["PORTUDP"];
}

// �� mud name ����Ϊ�ڼ�������
int get_info_level(string mudname)
{
        if( member_array(mudname,keys(mudlist))==-1)
        {
                if(member_array(mudname,keys(incoming_mudlist))==-1)
                        return -1;
                else    return 0;
        }
        else return 1;
}

void analyze_mud_info(mapping info)
{
        int info_level=get_info_level(get_mud_name(info));

        switch(info_level) {
        case -1: set_incoming_mudlist(get_mud_name(info),info);break;
        case  0: set_incoming_mudlist(get_mud_name(info),info);break;
        case  1: set_mudlist(get_mud_name(info),info);break;
        }
}
// ���ڴ󲿷ֺ�ʽ, ���� Mud �Ƿ�Ϊ��ͨ����֤, ��δ��֤�� pin_q
int compare_mud_info(mapping info)
{
        string mudname=get_mud_name(info);
        int level=get_info_level(mudname);

        if( level < 1 )
                send_ping_request(info["HOSTADDRESS"],info["PORTUDP"]);
        else if( mudlist[mudname]["STATUS"] &(SHUTDOWN | DISCONNECT))
        {
                mudlist[mudname]["STATUS"]&=(~(SHUTDOWN | DISCONNECT));
                mudlist[mudname]["STATUS"]|=ONLINE;
        }
        return level;
}

// �趨 or ���� mudlist ��Ѷ
protected void set_mudlist(string name,mapping info)
{
        mapping map;
        string t,d;

        // �� IPADDRESS:PORT �� index , ��ֹ fake , �����ϲ����򵲵�
        if( sscanf(name, "%*d.%*d.%*d.%*d:%*d") != 5 ) return;
        // ��û�д˼� mud ����? ��ӽ�mudlist
        if( undefinedp(map = mudlist[name]) )
        {
                // ���� mudname
                mudlist[name] = info;
                // ��ʼ�� mud STATUS
                mudlist[name]["STATUS"]=0;
                return;
        }

        // �Ѵ�������,������Ѷ ...
        foreach(t, d in info) mudlist[name][t]=d;

}
// �趨 or ���� incoming mudlist ��Ѷ
protected void set_incoming_mudlist(string name,mapping info)
{
        mapping map;
        string t,d;

        if( sscanf(name, "%*d.%*d.%*d.%*d:%*d") != 5 ) return;
        if( undefinedp(map = incoming_mudlist[name]) )
        {
                incoming_mudlist[name] = info;
                incoming_mudlist[name]["CONNECTION"]=1;
                return;
        }

        // ������Ѷ
        foreach(t, d in info) incoming_mudlist[name][t]=d;
        // ÿ�θ�����Ѷ���߻�Ӧ���� + 1
        incoming_mudlist[name]["CONNECTION"]+=1;
}

// ����ݴ���
void refresh_buffers()
{
        rwho_buffer=([]);
        gtell_buffer=([]);
        affirmation_buffer=([]);
        //refresh_ping_buffer();
        msg_buffer=([]);
}

/********************************************************************************************
 * ��������趨�ڲ�״���Ĺ�ͨ��ʽ..                                                         *
 ********************************************************************************************/

// SAVE_PATH ������ flag , �����Ը��� SAVE_PATH
varargs string SAVE_PATH(string name,int flag)
{
        if(!flag) return save_path+name;
        else
        {
                save_path = name;
                save();
                return "SAVE_PATH "+save_path+" updated successfully.\n";
        }
}

void debug()
{
        if( !debug ) debug = 1;
        else debug = 0;
}

//--------------------------------------------------------------------------------------------
// Status ϵ��
//--------------------------------------------------------------------------------------------

// ��"ip:port"��Ѱ�� mud data
mixed fetch_data(string name)
{
        int level;
        level = get_info_level(name);
        switch(level){
        case -1: return 0;
        case 1: return mudlist[name];
        case 0: return incoming_mudlist[name];
        }
        return 0;
}

// ��Ӣ����Ѱ�ҵǼ��� , ���ط��ϵ�����
varargs string *fetch_mudname(string arg,int flag)
{
        mapping info;
        string name,*result=({});
        if( flag ) arg=lower_case(arg);
        foreach(name , info in (mudlist+incoming_mudlist))
        if(!flag)
        {
                if( arg==info["NAME"] )
                        result+=({name});
        }
        else    if( strsrch(lower_case(info["NAME"]),arg)!=-1 )
                result+=({name});
        return result;
}
// �� mud ip ��Ѱ�ҵǼ��� , ���ط�������
varargs string *fetch_mudip(string arg)
{
        mapping info;
        string name,*result=({}),ip;
        //if( flag ) arg=lower_case(arg);
        foreach(name , info in (mudlist+incoming_mudlist))
        {
                sscanf(name,"%s:%*s",ip);
                if( arg == ip )
                        result+=({name});
        }
        return result;
}

// �趨 mudlist ��� mud �趨
int set_status(string mud,int num)
{
        int level;
        level = get_info_level(mud);
        if(level!=1 ) return 0;

        if( num > 0)
        {
                // �Ѿ��д����趨
                if(mudlist[mud]["STATUS"] & num)
                        return 0;
                else mudlist[mud]["STATUS"]+=num;
        }
        else
        {       // �Ѿ��д����趨
                if(!mudlist[mud]["STATUS"]&num)
                        return 0;
                else mudlist[mud]["STATUS"]-=(-num);
        }
        NCH_CHANNEL(sprintf("%s (%s) �������� [%d]",mudlist[mud]["NAME"],mud,num));
        save();
        return 1;
}

void add_buffer(string mudname,int kind)
{
        //if(get_info_level(mudname)<1)
        //      return;
        switch(kind)
        {
        case GTELL_B:
                if(undefinedp(gtell_buffer[mudname]))
                        gtell_buffer[mudname]=1;
                else
                        gtell_buffer[mudname]++;
                break;
        case PING_B:
                if(undefinedp(ping_buffer[mudname]))
                        ping_buffer[mudname]=({1,time()});
                else
                {
                        ping_buffer[mudname][0]++;
                        ping_buffer[mudname][1]=time();
                }
                break;
        case RWHO_B:
                if(undefinedp(rwho_buffer[mudname]))
                        rwho_buffer[mudname]=1;
                else
                        rwho_buffer[mudname]++;
                break;
        case AFFIRMATION_B:
                if(undefinedp(affirmation_buffer[mudname]))
                        affirmation_buffer[mudname]=1;
                else
                        affirmation_buffer[mudname]++;
        }
}

void sub_buffer(string mudname,int kind)
{
        //if(get_info_level(mudname)<1)
        //      return;
        switch(kind)
        {
        case GTELL_B:
                if(undefinedp(gtell_buffer[mudname]))
                        return;
                else
                {
                        gtell_buffer[mudname]--;
                        if(gtell_buffer[mudname]<1)
                                map_delete(gtell_buffer,mudname);
                }

                break;
        case PING_B:
                if(undefinedp(ping_buffer[mudname]))
                        return;
                else
                {
                        ping_buffer[mudname][0]--;
                        if( ping_buffer[mudname][0] < 1)
                                map_delete(ping_buffer,mudname);
                }
                break;
        case RWHO_B:
                if(undefinedp(rwho_buffer[mudname]))
                        return;
                else
                {
                        rwho_buffer[mudname]--;
                        if( rwho_buffer[mudname] < 1)
                                map_delete(ping_buffer,mudname);
                }
                break;
        case AFFIRMATION_B:
                if(undefinedp(affirmation_buffer[mudname]))
                        return;
                else
                {
                        affirmation_buffer[mudname]--;
                        if(affirmation_buffer[mudname]<1)
                                map_delete(affirmation_buffer,mudname);
                }
        }
}

int test_buffer(string mudname,int kind)
{
        switch(kind){
        case GTELL_B:
                if( !undefinedp(gtell_buffer[mudname]) ) return 1;
                break;
        case PING_B:
                if( !undefinedp(ping_buffer[mudname]) ) return 1;
                break;
        case RWHO_B:
                if( !undefinedp(rwho_buffer[mudname]) ) return 1;
                break;
        case AFFIRMATION_B:
                if( !undefinedp(affirmation_buffer[mudname]) ) return 1;
                break;
        }
        return 0;
}
/********************************************************************************************
 * �ɴ˴���ʼ , ���¾�Ϊ���ַ������                                                        *
 ********************************************************************************************/

//--------------------------------------------------------------------------------------------
// Ping ϵ��
//--------------------------------------------------------------------------------------------
/* Intermud2 ping_q �����ʽ
        ([
                "NAME":         (string)�� Mud ����·����[��ѡ]
                                �ɵ� DNS_MASTER ���������ͬ�� DNS_FAKE.
                "PORTUDP":      (int)(����󶼻ᱻ����string)
                                ���mud��intermud2 daemon ������ udp port.
        ])

    Intermud2 ping_a �����ʽ
        ([
                "NAME":         (string)�� Mud ����·����
                "MUDGROUP":     (string)��·Ⱥ��?
                "HOST":         (string)Mud ��������?(����û��, ��ƿһ��)
                "LOCATION":     (string)���ڵ�?
                "MUDLIB":       (string)mudlib, �������Eastern Stories���ղ��� es channel.
                "VERSION":      (string)mudlib �汾?
                "ENCODING":     (string)���뷽ʽ�� BIG5/GB,
                "USERS":        (int) users
                "PORTUDP":      (int) UDP port,
        ])
*/


// ping_buffer ������������Ҫ�� ping request
// ���ⱻ save �˷���Դ���� nosave


// ���� Ping Ҫ��
void send_ping_request(string target, int port)
{
        send_udp(target, port, "ping_q", ([
                "NAME":         INTERMUD_MUD_NAME,
                "PORTUDP":      ""+fetch_variable("udp_port"),
            ]));
        //if(get_info_level(target+":"+port)>0)
        add_buffer(target+":"+port,PING_B);
        NCH_CHANNEL("�ͳ� PING Ҫ�� " + target + ":" + port + "��");
}

void refresh_ping_buffer()
{
        string t;
        int *d;
        // �ٴ�ִ�д˺�ʽʱ��Ҫ�� callout ������
        remove_call_out("refresh_ping_buffer");

        foreach(t,d in ping_buffer)
        if(time()-d[1] > 90)
        {
                int flag;
                //NCH_CHANNEL("peer...."+sprintf("%O%O\n",t,mudlist[t]["STATUS"]));
                if( get_info_level(t)==1 && !(mudlist[t]["STATUS"]&SHUTDOWN))
                {

                        mudlist[t]["STATUS"]&=(~ONLINE);
                        mudlist[t]["STATUS"]|=DISCONNECT;

                        // 2 hr�ڲ�����վһֱ ping -.-
                        if( time() - mudlist[t]["LASTESTCONTACT"] < 60*60*2 )
                                flag=1;
                }
                map_delete(ping_buffer,t);
                if( flag )
                {
                        send_ping_request(mudlist[t]["HOSTADDRESS"],mudlist[t]["PORTUDP"]);
                        flag=0;
                }
        }
        call_out("refresh_ping_buffer",60);
}

// �յ� ping request
void receive_ping_request(mapping info)
{
        int port;

        // UDP_PORT ��ʽ����
        if( undefinedp(info["PORTUDP"]) || !sscanf(info["PORTUDP"],"%d",port) ) return;
        // ������� mudlist �ﻹû�д� mud , ����ҲҪ������ ping.
        if( (info["HOSTADDRESS"]==localhost || info["HOSTADDRESS"]==my_address) && port == fetch_variable("udp_port") )
                return;
        if(get_info_level(get_mud_name(info))<0)
                compare_mud_info(info); // ����ping
        // �ͳ� PING Answer
        send_udp(info["HOSTADDRESS"], port, "ping_a",
            ([
                "NAME":         INTERMUD_MUD_NAME,      // mudlib.h �ж���
                "MUDNAME":      CHINESE_MUD_NAME,
                "MUDGROUP":     MUD_GROUP,
                "HOST":         MUD_HOST_NAME,
                "LOCATION":     MUD_LOCATION,
                "DRIVER":       __VERSION__,
                "MUDLIB":       MUDLIB_NAME,
                "VERSION":      MUDLIB_VERSION_NUMBER,
                "ENCODING":     MUD_ENCODING,
                "USERS":        ""+sizeof(users()),
                "PORTUDP":      ""+fetch_variable("udp_port"),
                "PORT":         ""+__PORT__,
            ]));

        NCH_CHANNEL("�յ� PING Ҫ�� , �ͳ���Ӧ�� "+info["HOSTADDRESS"]+":"+port+" .");
}

// �յ� PING ��Ӧ
void receive_ping_answer(mapping info)
{
        int status;

        string mudname=get_mud_name(info);
        // ��Ҫ��Է��� ping ��?
        if( !test_buffer(mudname,PING_B) )
        {
                //if( !sscanf(info["PORTUDP"],"%*d") ) return;
                NCH_CHANNEL("�յ����� Ping Answer From: "+info["HOSTADDRESS"]+":"+info["PORTUDP"]+" [ "+info["NAME"]+" ] ");

                if(get_info_level(mudname)<1)
                        receive_ping_request(info); // ����ping

                send_warning(info["HOSTADDRESS"],info["PORTUDP"],"\aWe didn't ask for this ping request.","Sorry,");
                //compare_mud_info(info);
                return;
        }
        //if(get_info_level(mudname)>0)
        sub_buffer(mudname,PING_B);
        info["LASTESTCONTACT"]=time();
        analyze_mud_info(info);
        if( get_info_level(mudname) == 1)
        {
                if( mudlist[mudname]["STATUS"] &(SHUTDOWN | DISCONNECT))
                        mudlist[mudname]["STATUS"]&=(~(SHUTDOWN | DISCONNECT));
                mudlist[mudname]["STATUS"]|=ONLINE;
        }
        NCH_CHANNEL("�յ� "+info["HOSTADDRESS"]+" �ͻص� PING ANSWER .");
}

//--------------------------------------------------------------------------------------------
// Mudlist ϵ��
//--------------------------------------------------------------------------------------------


// �ͳ� Mudlist ѶϢר�õĺ�ʽ -.-
void send_mudlist_udp(string targ, int port,string info)
{
        int socket;

        // ���������ϸ��Լ�.
        if( (targ == my_address || targ == localhost) && port == fetch_variable("udp_port") ) return;

        // ���� socket �Կ�ʼ����
        socket = socket_create(DATAGRAM, "read_callback");
        if( !socket ) return;

        // �ͳ�ѶϢ.
        socket_write(socket, "@@@mudlist_a||" + info + "@@@\n", targ + " " + port);
        // �رմ�����ϵ� socket
        socket_close(socket);
}

// �յ��Է���Ӧ�� mudlist �б�
void receive_mudlist_answer(mapping info)
{
        string name,clip;

        foreach(name,clip in info)
        {
                string *prop_list;
                mapping mudinfo=([]);
                if( strsrch(clip,"NAME")==-1 ) continue;

                prop_list=explode(clip,"|")-({""});
                foreach(string prop in prop_list) {
                        string t, d;
                        if( sscanf(prop, "%s:%s", t, d)==2 ) mudinfo[t] = d;
                }
                // �յ�û���嵥�ϵ� mud ���� ping Ҫ��
                //if(mudinfo["HOSTADDRESS"]!=my_address && mudinfo["HOSTADDRESS"]!=localhost && mudinfo["HOSTADDRESS"]!=fetch_variable("udp_port") )
                if( get_info_level(get_mud_name(mudinfo))<1 )
                        compare_mud_info(mudinfo); // ����ping
        }

        NCH_CHANNEL("�յ� "+info["HOSTADDRESS"]+" �ͻص� Mudlist Answer.");
}

// Ҫ��Է����� mudlist �б�
void send_mudlist_request(string targ, int port)
{
        send_udp(targ, port, "mudlist_q", ([
                "NAME":INTERMUD_MUD_NAME,
                "HOSTADDRESS":  fetch_variable("my_address"),
                "PORTUDP":      "" + fetch_variable("udp_port"),
                "USERS":        "" + sizeof(users()),
            ]));
}

// �յ�Ҫ���ͳ� mudlist �б�
void receive_mudlist_request(mapping info)
{
        string name;
        mapping mudinfo;
        int i=1;
        if(!info["PORTUDP"]) return;
        if(get_info_level(get_mud_name(info))<1) return;

        foreach(name,mudinfo in mudlist)
        {
                // û�м�ʱ��Ӧ�ľ��п��ܲ���, ���ͳ�����������·����
                if(!(mudinfo["STATUS"]&ONLINE)) continue;
                i++;
                send_mudlist_udp(info["HOSTADDRESS"],info["PORTUDP"],
                    sprintf("%d:|NAME:%s|HOST:%s|HOSTADDRESS:%s|PORT:%s|PORTUDP:%s|USERS:%s",
                                i,mudinfo["NAME"],mudinfo["HOST"],mudinfo["HOSTADDRESS"],mudinfo["PORT"],mudinfo["PORTUDP"],mudinfo["USERS"])

                );
        }
        NCH_CHANNEL("�յ� "+info["HOSTADDRESS"]+":"+info["PORTUDP"]+" �� Mudlist Request ����Ӧ֮.");
}

//--------------------------------------------------------------------------------------------
// Shutdown ϵ��
//--------------------------------------------------------------------------------------------

void send_shutdown(string target, int port)
{
        send_udp(target, port, "shutdown",
            ([
                "NAME":INTERMUD_MUD_NAME,
                "PORTUDP":""+fetch_variable("udp_port"),
            ]));

        NCH_CHANNEL("�ͳ� Shutdown ѶϢ�� " + target + ":" + port + "��");
}

void receive_shutdown(mapping info)
{
        if( compare_mud_info(info)==1 )
        {
                string name=get_mud_name(info);

                mudlist[name]["STATUS"]&=(~(ONLINE|DISCONNECT));
                mudlist[name]["STATUS"]|=SHUTDOWN;
        }
        NCH_CHANNEL("�յ��� "+info["HOSTADDRESS"]+":"+info["PORTUDP"]+" ���� Shutdown ѶϢ.");
}

//--------------------------------------------------------------------------------------------
// Gchannel ϵ��
//--------------------------------------------------------------------------------------------


void compare_last_msg(string mudname,string last_msg,string sender)
{
        if( undefinedp(msg_buffer[mudname]) || (msg_buffer[mudname][0]!=last_msg && msg_buffer[mudname][3]!=sender ))
        {
                //if( undefinedp(msg_buffer[mudname]) || msg_buffer[mudname][2] >= time()+15 )
                msg_buffer[mudname]=({ last_msg,1,time(),sender });

        }       else {
                if(msg_buffer[mudname][0]==last_msg || msg_buffer[mudname][3]==sender)
                        msg_buffer[mudname][1]++;
                msg_buffer[mudname][2]=time();
                msg_buffer[mudname][3]=sender;
        }

        if( msg_buffer[mudname][1] > 100 )
        {
                set_status(mudname,ANTI_AD);
                NCH_CHANNEL("��[ " + fetch_data(mudname)["MUDNAME"] +"] ���� ANTI_AD ������");
        }
}

/*
class channel_class
{
        int level, number;
        string msg;
        mapping extra;
}

int accept_channel(string channel)
{
        class channel_class ch;
        mapping channels = load_object(CHANNEL_D)->query_chann();
        //mapping channels=fetch_variable("channels",load_object(CHANNEL_D));

        if( !undefinedp(channels[channel]) && !undefinedp((ch=channels[channel])->extra["intermud"]) )
                return 1;
}
*/

// �յ� gchannel ѶϢ
void receive_gchannel_msg(mapping info)
{
        string msg,id,mudname,str;
        int status;

        // һ������Ҫ�е���λ
        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["USRNAME"])
            ||  undefinedp(info["CHANNEL"])
            ||  undefinedp(msg = info["MSG"])
        )   return;
        // ȥ�����һ�� \n
        if(msg[<1..<0] == "\n") msg[<1..<0] = "";
        // ������վ���ҹԹ��Ŷӻ� ping :Q
        if( compare_mud_info(info)<1 ) return;

        mudname = get_mud_name(info);
        // �趨 id
        //id = info["USRNAME"] + "@"+ ((mudlist[mudname=get_mud_name(info)]["MUDNAME"])||"")+HBGRN"-"+mudlist[mudname]["NAME"]+"-"NOR;
        id = info["USRNAME"];
        // �������� name ?
        if( info["CNAME"] ) id = info["CNAME"] + "(" + id + ")";
        // �Ƿ�Ϊ Emote ?
        if( !undefinedp(info["EMOTE"]) )
                set("channel_id", id);

        mudname = get_mud_name(info);
        status = fetch_data(get_mud_name(info))["STATUS"];

        // ϵͳ�Զ�ʶ��gb/big5��վ��
        if( !(status & ENCODE_CONFIRM) && strlen(msg) > 20 )
        {
                string mud_ip_port = info["HOSTADDRESS"]+":"+info["PORTUDP"];
                int con = LANGUAGE_D->encode_conjecture(msg);

                if( con >= 0 && con <= 15 ) mudlist[mud_ip_port]["STATUS"]|=GB_CODE;
                else if( con > 30 ) mudlist[mud_ip_port]["STATUS"]&=~GB_CODE;

                if( con != -1 ) mudlist[mud_ip_port]["STATUS"]|=ENCODE_CONFIRM;
        }

        if( status & IGNORED )  // ��������������Ϣվ�㣬��������������Ƶ��
        {
                if( info["EMOTE"] ) delete("channel_id");
                return;
        }

        if( !(status & GB_CODE) && ((status & ENCODE_CONFIRM) || (!undefinedp(mudlist[mudname]["ENCODING"]) && lower_case(mudlist[mudname]["ENCODING"])=="big5")) )

        {
                //id  = (string)LANGUAGE_D->toGB(msg);;
                msg = (string)LANGUAGE_D->toGB(msg);
        }

        if( status & ANTI_AD ) info["CHANNEL"]="ad";
        if( info["CHANNEL"]!="ad" )
        compare_last_msg(mudname,info["MSG"],id);

        // ������ CHANNEL_D ����
        // ��Ϊ������NTlib��mud����ֱ����CHANNEL_D->do_channel(this_object(), info["CHANNEL"], msg, info["EMOTE"]);�滻���µ�����
        CHANNEL_D->do_channel(this_object(), info["CHANNEL"], msg, info["EMOTE"]);
/*
        //if( !(status & ANTI_AD) && accept_channel(info["CHANNEL"]) )
        if( accept_channel(info["CHANNEL"]) || info["CHANNEL"] == "ad") // ��վCHANNEL_Dӵ�����Ƶ������Ƶ��
        {
                str = (info["EMOTE"]?("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+ msg): ("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+ id+"��"+msg));
                CHANNEL_D->channel_broadcast(info["CHANNEL"], str);
        }
        else // �ŵ�����otherƵ����ʾ
        {
                str = (info["EMOTE"]?("["+info["CHANNEL"]+"] "+"{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+msg):("["+info["CHANNEL"]+"] {"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+id+"��"+msg));
                CHANNEL_D->channel_broadcast("other", str);
        }
*/
        if( info["EMOTE"] ) delete("channel_id");
}

// ���� gchannel ѶϢ
void send_gchannel_msg(string channel, string id, string name, string msg, int emoted)
{
        mapping info,mudinfo;
        string t;

        if(msg[<1..<0] == "\n") msg[<1..<0] = "";

        msg = replace_string(msg, "|", "|\033[1m");
        msg = replace_string(msg, "@", "@\033[1m");
        info = ([
            "NAME":         INTERMUD_MUD_NAME,
            "PORTUDP":      "" + fetch_variable("udp_port"),
            "USRNAME":      id,
            "CNAME":        name,
            "CHANNEL":      channel,
            "ENCODING":     MUD_ENCODING,
            "MSG":          msg
        ]);


        if( emoted ) info["EMOTE"] = "YES";

        foreach(t, mudinfo in (mudlist+incoming_mudlist))
        send_udp(mudinfo["HOSTADDRESS"], mudinfo["PORTUDP"],"gchannel", info);
}


//--------------------------------------------------------------------------------------------
// Gwizmsg ϵ��
//--------------------------------------------------------------------------------------------

/*
info = ([
                "NAME" : INTERMUD_MUD_NAME,
                "PORTUDP" : "" + fetch_variable("udp_port"),
                "WIZNAME" : id,
                "CNAME" : name,
                "CHANNEL" : ch,
                "ENCODING" : CHARACTER_SET,
                "GWIZ" : msg,
        ]);

*/
void receive_gwiz_msg(mapping info)
{
        string msg,id,mudname;
        int status;

        // һ������Ҫ�е���λ
        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["WIZNAME"])
            ||  undefinedp(info["CHANNEL"])
            ||  undefinedp(msg = info["GWIZ"])
        )   return;
        // ȥ�����һ�� \n
        if(msg[<1..<0] == "\n") msg[<1..<0] = "";
        // ������վ���ҹԹ��Ŷӻ� ping :Q
        if( compare_mud_info(info)<1 ) return;

        // �趨 id
        id = info["WIZNAME"];
        //id = info["WIZNAME"] + "@" + info["NAME"];
        // �������� name ?
        if( info["CNAME"] ) id = info["CNAME"] + "(" + id + ")";

        // �Ƿ�Ϊ Emote ?
        if( !undefinedp(info["EMOTE"]) )
                set("channel_id", id);
        // GB ת�� ?
        mudname=get_mud_name(info);

        status = fetch_data(mudname)["STATUS"];

        if( !(status & ENCODE_CONFIRM) && strlen(msg) > 20 )
        {
                string mud_ip_port = info["HOSTADDRESS"]+":"+info["PORTUDP"];
                int con = LANGUAGE_D->encode_conjecture(msg);

                if( con >= 0 && con <= 15 ) mudlist[mud_ip_port]["STATUS"]|=GB_CODE;
                else if( con > 30 ) mudlist[mud_ip_port]["STATUS"]&=~GB_CODE;

                if( con != -1 ) mudlist[mud_ip_port]["STATUS"]|=ENCODE_CONFIRM;
        }

        /*
        if( status & IGNORED ) // ��������������Ϣվ�㣬��������������Ƶ��
        {
                if( info["EMOTE"] ) delete("channel_id");
                return;
        }
        */

        if( !(status & GB_CODE) && ((status & ENCODE_CONFIRM) || (!undefinedp(mudlist[mudname]["ENCODING"]) && lower_case(mudlist[mudname]["ENCODING"])=="big5")) )
        {
                // id = (string)LANGUAGE_D->toGB(id);
                msg = (string)LANGUAGE_D->toGB(msg);
        }

        // ��Ϊ������NTlib��mud����ֱ����CHANNEL_D->do_channel(this_object(), info["CHANNEL"], msg, info["EMOTE"]);�滻���µ�����
        CHANNEL_D->do_channel(this_object(), info["CHANNEL"], msg, info["EMOTE"]);
/*
        if( status & ANTI_AD ) // �������վ��
        {
                info["CHANNEL"]="ad"; // �ѶԷ�����Ƶ���ĳɹ��Ƶ��
                CHANNEL_D->channel_broadcast(info["CHANNEL"], info["EMOTE"]?("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+ msg):("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+ id+"��"+msg));

                if( info["EMOTE"] ) delete("channel_id");
                return;
        }

        // ������ CHANNEL_D ����
        CHANNEL_D->channel_broadcast("gwiz","["+info["CHANNEL"]+"] "+(info["EMOTE"]?("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+msg):("{"+HBGRN+mudlist[mudname]["NAME"]+NOR+"} "+ id+"��"+msg)));
*/
        if( info["EMOTE"] ) delete("channel_id");

        //NCH_CHANNEL("�յ� gwizmsg "+info["CHANNEL"]+" ѶϢ");
}
void send_gwiz_msg(string channel, string id, string name, string msg, int emoted)
{
        mapping info,mudinfo;
        string t;

        if(msg[<1..<0] == "\n") msg[<1..<0] = "";
        msg = replace_string(msg, "|", "|\033[1m");
        msg = replace_string(msg, "@", "@\033[1m");
        info = ([
            "NAME":         INTERMUD_MUD_NAME,
            "PORTUDP":      "" + fetch_variable("udp_port"),
            "WIZNAME":      id,
            "CNAME":        name,
            "CHANNEL":      channel,
            "ENCODING":     MUD_ENCODING,
            "GWIZ":          msg,
        ]);
        if( emoted ) info["EMOTE"] = "YES";

        foreach(t, mudinfo in (mudlist+incoming_mudlist))
        send_udp(mudinfo["HOSTADDRESS"], mudinfo["PORTUDP"],"gwizmsg", info);
}

//--------------------------------------------------------------------------------------------
// Warning ϵ��
//--------------------------------------------------------------------------------------------

void receive_warning(mapping info)
{
        string msg;

        if(compare_mud_info(info)<1)
                return;

        msg=sprintf("�� %s(%s) ��֪�ľ���: %s �� %s",info["NAME"],info["HOSTADDRESS"],info["MSG"],info["FAKEHOST"]);

        send_warning(info["HOSTADDRESS"],info["PORTUDP"],
            sprintf("Thank For Your Warning [%s], we have loged it , and will try to solve it soon :).",msg));

        //log_file("static/intermud2", "[warn]"+msg);
        NCH_CHANNEL(msg);
}

varargs void send_warning(string targ,int port,string msg,string fakehost)
{
        send_udp(targ, port, "warning",
            ([
                "NAME":INTERMUD_MUD_NAME,
                "PORTUDP":""+fetch_variable("udp_port"),
                "MSG":msg,
                "FAKEHOST":fakehost?fakehost:"",
            ]));

}

//--------------------------------------------------------------------------------------------
// Startup ϵ��
//--------------------------------------------------------------------------------------------

// �ͳ� startup ,  �������Ͼ��� ping ��, �ͻ����ľͺ�.
void send_startup(string targ,int port)
{
        send_udp(targ, port, "startup",
            ([
                "NAME":INTERMUD_MUD_NAME,
                "PORTUDP":""+fetch_variable("udp_port"),
            ]));
        // �Է��յ� startup ��� ping_a
        add_buffer(targ+":"+port,PING_B);
        //NCH_CHANNEL("�ͳ� startup ѶϢ�� " + targ + ":" + port + "��");
}

void receive_startup(mapping info)
{
        receive_ping_request(info);
        NCH_CHANNEL("�յ��� "+info["HOSTADDRESS"]+":"+info["PORTUDP"]+" ���� startup ѶϢ.");
}

//--------------------------------------------------------------------------------------------
// affirmation_a ϵ��
//--------------------------------------------------------------------------------------------


void add_affirmation_buffer(mapping info,string service)
{
        string name=get_mud_name(info);

        service=lower_case(service);

        if(!undefinedp(affirmation_buffer[name+"-"+service]) )
                affirmation_buffer[name+"-"+service]++;
        else affirmation_buffer[name+"-"+service]=1;
}

void receive_affirmation(mapping info)
{
        string name=get_mud_name(info);
        object ob;

        if(compare_mud_info(info)<1)
                return;
        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["WIZTO"])
            ||  undefinedp(info["MSG"])
            ||  undefinedp(info["MSG"])
        )   return;

        if( undefinedp(affirmation_buffer[name+"-"+info["TYPE"]]))
        {

                send_warning(info["HOSTADDRESS"],info["PORTUDP"],
                    "Affirmation warning : Your mud send unrequest Affirmation_a Please improve it.");
                NCH_CHANNEL(sprintf("Unrequest affirmation answer from %s:%s(%s)   \n%O\n",info["HOSTADDRESS"],info["PORTUDP"]+"",info["NAME"],info));
                return ;

        }
        affirmation_buffer[name+"-"+info["TYPE"]]--;
        if( !ob=find_player(info["WIZTO"]) )
        {
                send_warning(info["HOSTADDRESS"],info["PORTUDP"],
                    "Affirmation warning : No such user or he is offlin now.");
                return;
        }
        if( info["MSG"][<1..<0] != '\n' ) info["MSG"] += "\n";

        tell_object(ob, sprintf(GRN "[ %s ] %s[%s] ������ ��%s\n"NOR,undefinedp(info["TYPE"])?" ":info["TYPE"],capitalize(info["WIZFROM"]),name,info["MSG"] ));

}

void send_affirmation(string targ,int port, string to,string msg, string type)
{
        mapping info;
        info = ([
            "NAME" : INTERMUD_MUD_NAME,
            "PORTUDP" : "" + fetch_variable("udp_port"),
            "WIZFROM" : type+"@"+INTERMUD_MUD_NAME,
            "WIZTO"     : to,
            "TYPE" : type,
            "MSG" : msg,
        ]);
        send_udp(targ,port,"affirmation_a",info);
        //NCH_CHANNEL("send affirmation msg to "+to+"@"+targ+":"+port);
}

//--------------------------------------------------------------------------------------------
// Gtell ϵ��
//--------------------------------------------------------------------------------------------



void receive_gtell(mapping info)
{
        string name=get_mud_name(info);
        object ob;

        if(compare_mud_info(info)<1)
                return;
        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["WIZTO"])
            ||  undefinedp(info["WIZFROM"])
            ||  undefinedp(info["MSG"])
        )   return;
        if( !test_buffer(name,GTELL_B))
        {
                if(time()-gtell_buffer[name] < 1)
                {
                        send_affirmation(info["HOSTADDRESS"],info["PORTUDP"],info["WIZFROM"],
                            "Gtell warning : Your mud send too many GTELL request in the same time , Please try again later.","gtell");
                        //NCH_CHANNEL(sprintf("%s[%s:%s] gtell ̫Ƶ�� , ignore",info["NAME"],info["HOSTADDRESS"],info["PORTUDP"]));
                        return ;
                }
        }
        gtell_buffer[name]=time();

        if( !ob=find_player(info["WIZTO"]) )
        {
                send_affirmation(info["HOSTADDRESS"],info["PORTUDP"],info["WIZFROM"],
                    "GTELL warning : No such user or he is offlin now.","gtell");
                return;
        }
        if( info["MSG"][<1..<0] != '\n' ) info["MSG"] += "\n";
        if( undefinedp(info["CNAME"]) )
                tell_object(ob, sprintf(GRN "%s@%s(%s) �����㣺%s"NOR,capitalize(info["WIZFROM"]),info["NAME"],name,info["MSG"] ));
        else    tell_object(ob, sprintf(GRN "%s(%s@%s[%s]) �����㣺%s"NOR,info["CNAME"],capitalize(info["WIZFROM"]),info["NAME"],name,info["MSG"] ));

        send_affirmation(info["HOSTADDRESS"],info["PORTUDP"],info["WIZFROM"],
            "GTELL Respond : "+info["WIZTO"]+" has received your message.","gtell");

}

int send_gtell(string targ,int port,string my_id,string my_cname,string targ_id,string msg)
{
        mapping info;
        info = ([
            "NAME" : INTERMUD_MUD_NAME,
            "PORTUDP" : "" + fetch_variable("udp_port"),
            "WIZFROM" : my_id,
            "WIZTO"     : targ_id,
            "CNAME" : my_cname,
            "MSG" : msg,
        ]);
        add_affirmation_buffer(mudlist[targ+":"+port],"gtell");
        send_udp(targ,port,"gtell",info);

        NCH_CHANNEL(sprintf("%s send gtell msg to %s@%s:%s",my_id,targ_id,targ,port+""));
        return 1;
}

//--------------------------------------------------------------------------------------------
// Support ϵ��
//--------------------------------------------------------------------------------------------

//void send_support_answer(string targ,int port,)

void receive_support_request(mapping info)
{
        string answer;

        if(compare_mud_info(info)<1)
                return;

        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["CMD"])
            ||  undefinedp(info["ANSWERID"])
        )   return;

        if( info["CMD"]="tcp" )
                answer="no";
        else
        {
                string cmd=info["CMD"];
                if( undefinedp(service_handler[cmd]) )
                        answer="no";
                else answer = "yes";
        }

        if( answer="yes" )
        {
                send_udp(info["HOSTADDRESS"],info["PORTUDP"],"support_a",([
                        "NAME" : INTERMUD_MUD_NAME,
                        "PORTUDP" : "" + fetch_variable("udp_port"),
                        "CMD" : info["CMD"]+(!undefinedp(info["PARAM"]) ? "||PARAM:"+info["PARAM"] : ""),
                        "ANSWERID" : info["ANSWERID"],
                        "SUPPORTED" : "yes",
                    ]));
        } else
        {
                send_udp(info["HOSTADDRESS"],info["PORTUDP"],"support_a",([
                        "NAME" : INTERMUD_MUD_NAME,
                        "PORTUDP" : "" + fetch_variable("udp_port"),
                        "CMD" : info["CMD"]+(!undefinedp(info["PARAM"]) ? "||PARAM:"+info["PARAM"] : ""),
                        "ANSWERID" : info["ANSWERID"],
                        "NOTSUPPORTED" : "yes",
                    ]));
        }
}


//--------------------------------------------------------------------------------------------
// Locate ϵ��
//--------------------------------------------------------------------------------------------

void receive_locate_request(mapping info)
{
        string answer;

        if(compare_mud_info(info)<1)
                return;

        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["ASKWIZ"])
            ||  undefinedp(info["TARGET"])
        )   return;

        if( find_player(lower_case(info["TARGET"])) )
                answer="YES";
        else answer="NO";

        send_udp(info["HOSTADDRESS"],info["PORTUDP"],"locate_a",([
                "NAME" : INTERMUD_MUD_NAME,
                "PORTUDP" : "" + fetch_variable("udp_port"),
                "TARGET" : info["TARGET"],
                "ASKWIZ" : info["ASKWIZ"],
                "LOCATE" : answer,
            ]));
}

void send_locate_request(string my_name,string t_name)
{
        string t;
        mapping mudinfo;

        foreach(t, mudinfo in (mudlist+incoming_mudlist))
        send_udp(mudinfo["HOSTADDRESS"],mudinfo["PORTUDP"],"locate_q",([
                "NAME" : INTERMUD_MUD_NAME,
                "PORTUDP" : "" + fetch_variable("udp_port"),
                "TARGET" : t_name,
                "ASKWIZ" : my_name,
            ]));
}

void receive_locate_answer(mapping info)
{
        object ob;
        if(compare_mud_info(info)<1)
                return;

        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["LOCATE"])
            ||  undefinedp(info["ASKWIZ"])
            ||  undefinedp(info["TARGET"])
        )   return;

        switch(info["TARGET"])
        {
        case "NO":return;
        case "YES":
                if( ob = find_player(lower_case(info["ASKWIZ"])))
                        tell_object(ob,sprintf("%s was located on %s [%s:%s] now.\n",info["TARGET"],info["NAME"],info["HOSTADDRESS"],info["PORTUDP"]));
                else return;
        }
        NCH_CHANNEL("�յ� locate_answer");
}



//--------------------------------------------------------------------------------------------
// RWho ϵ��
//--------------------------------------------------------------------------------------------



void receive_rwho_request(mapping info)
{
        string str;
        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["ASKWIZ"])
        )   return;

        if(compare_mud_info(info)<1)
                return;

        str = "/cmds/usr/who.c"->who(0, info["VERBOSE"] ? "-l": "-i");

        send_udp(info["HOSTADDRESS"],info["PORTUDP"],"rwho_a",([
                "NAME" : INTERMUD_MUD_NAME,
                "PORTUDP" : "" + fetch_variable("udp_port"),
                "ASKWIZ" : info["ASKWIZ"],
                "RWHO"  : str,
            ]));
}

void receive_rwho_answer(mapping info)
{
        object ob;
        string mudname=get_mud_name(info);

        if( undefinedp(info["NAME"])
            ||  undefinedp(info["PORTUDP"])
            ||  undefinedp(info["ASKWIZ"])
            ||  undefinedp(info["RWHO"])
        )   return;

        if( !test_buffer(mudname,RWHO_B) )
        {
                compare_mud_info(info);
                return;
        }else sub_buffer(mudname,RWHO_B);

        if(!ob=find_player(info["ASKWIZ"]))
                return;
        tell_object(ob, info["RWHO"]+"\n");
}

varargs void send_rwho_request(string ip,int port,string player,string arg)
{
        if(arg)
                send_udp(ip,port,"rwho_q",([
                        "NAME" : INTERMUD_MUD_NAME,
                        "PORTUDP" : "" + fetch_variable("udp_port"),
                        "ASKWIZ" : player,
                        "VERBOSE": arg,
                    ]));
        else
                send_udp(ip,port,"rwho_q",([
                        "NAME" : INTERMUD_MUD_NAME,
                        "PORTUDP" : "" + fetch_variable("udp_port"),
                        "ASKWIZ" : player,
                    ]));
        add_buffer(ip+":"+port,RWHO_B);
}

string query_name()
{
        return "INTERMUD2 ϵͳ(INTERMUD2_D)";
}
