// This program is a part of NT MudLIB
#define INTERMUD2_D         "/adm/daemons/intermud2_d"

#define PLAYER               0
#define TEACHER              1
#define IMMORTAL             2
#define WIZARD               4

#define CHAT                 (1<<0)        //����
#define RUMOR                (1<<1)        //ҥ��
#define MESS                 (1<<2)        //����
#define WIZ                  (1<<3)        //��ʦ
#define SYS                  (1<<4)        //ϵͳ
#define NCH                  (1<<5)        //���
#define NEWS                 (1<<6)        //����
#define SOS                  (1<<7)        //����
//#define GWIZ                 (1<<8)        //������ʦ
#define OTHER                (1<<9)        //����
#define AD                   (1<<10)       //���
#define FAMILY               (1<<11)       //����
#define WAR                  (1<<12)       //ս��
#define TCH                  (1<<13)       //����
#define PARTY                (1<<14)       //����
#define STOCK                (1<<15)       //��Ʊ
#define AUC                  (1<<16)       //����
#define DEBUG                (1<<17)       //����
#define COMBAT		     (1<<18)	   //ս��
#define GROUP		     (1<<19)       //����
#define SPORT		     (1<<20)	   //�˶�

#define SPECIAL_NPC     ({ "/adm/npc/youxun" })

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>
#include <localtime.h>

inherit F_DBASE;

#define DEFAULT_REFUSE  ( NCH | OTHER | AD )

class channel_class
{
        int level, number;
        string msg;
        mapping extra;
}

mapping channels;
mapping users;
nosave int water_number;
mapping query_chann() { return channels; }

nosave string msg_log;
nosave int log_from;

string *info =
({
    ({
        TCH,
        "tch",
        PLAYER,
        HIY "��"NOR HIW"��ʦ"NOR HIY"��"NOR,
        ([
                "msgcolor"      : NOR HIW
        ]),
    }),
    ({
        WAR,
        "war",
        PLAYER,
        BLU "��"HIB"ս��"NOR BLU"��"NOR,
        ([
                "msgcolor"      : NOR HIR,
                "noemote"       : 1,
        ]),
    }),
    ({
        CHAT,
        "chat",
        PLAYER,
        CYN "��"HIC"����"NOR CYN"��"NOR,
        ([
                "msgcolor"      : NOR HIC,
        ]),
    }),
    ({
        RUMOR,
        "rumor",
        PLAYER,
        MAG "��"NOR HIM"ҥ"NOR MAG"��"NOR HIM"��"NOR,
        ([
                "wizlevel"      : 1,
                "msgcolor"      : NOR HIM,
        ])
    }),
    ({
        MESS,
        "mess",
        PLAYER,
        HIG "��"HIR"����"NOR HIG"��"NOR,
        ([
                "time"          : 1,
                "msgcolor"      : NOR HIG,
                "notalk"        : 1,
        ])
    }),
    ({
        WIZ,
        "wiz",
        IMMORTAL,
        YEL "��"HIY"��ʦ"NOR YEL"��"NOR,
        ([
                "msgcolor"      : NOR HIG,
                "nameraw"       : 1,
        ]),
    }),
    ({
        SYS,
        "sys",
        WIZARD,
        RED "��"RED"ϵ"NOR RED"ͳ"NOR RED"��"NOR,
        ([
                "time"          : 1,    // ��ʾʱ��
                "msgcolor"      : NOR RED,
        ]),
    }),
    ({
        NCH,
        "nch",
        WIZARD,
        BLU "��"NOR HIB"���"NOR BLU"��"NOR,
        ([
                "time"          : 1,
                "msgcolor"      : NOR HIB,
                //"listener"    : ({ get_object(INTERMUD2_D) });
        ]),
    }),
    ({
        DEBUG,
        "debug",
        WIZARD,
        WHT "��"NOR HIW"����"NOR WHT"��"NOR,
        ([
                "time"          : 1,
                "msgcolor"      : NOR HIW,
        ]),
    }),
    ({
        NEWS,
        "news",
        PLAYER,
        GRN "��"HIG"��"NOR GRN"��"HIG"��"NOR,
        ([
                "time"          : 1,
                "nameraw"       : 1,
                "msgcolor"      : NOR YEL,
                "notalk"        : 1,
        ]),
    }),
    ({
        //GWIZ ����ĵط������
        256,
        "gwiz",
        WIZARD,
        GRN "��"HIG"����%T"NOR GRN"��"NOR,
        ([
                "nameraw"       : 1,
                "msgcolor"      : NOR HIG,
                "intermud"      : INTERMUD2_D,
                "channel"       : "CREATOR",
                "subchannel"    : 1,
                "newtitle"      : (: stringp($1) ? "-"+$1 : "" :),
        ]),
    }),
    ({
        OTHER,
        "other",
        PLAYER,
        CYN "��"NOR CYN"δ֪%T"NOR CYN"��"NOR,
        ([
                "msgcolor"      : NOR CYN,
                "intermud"      : INTERMUD2_D,
                "channel"       : "",
                "subchannel"    : 1,
                "newtitle"      : (: stringp($1) ? ("-"+HIG+$1+NOR) : "" :),
        ]),
    }),
    ({
        AD,
        "ad",
        PLAYER,
        WHT "��"NOR HIW"���" NOR WHT"��"NOR,
        ([
                "nameraw"       : 1,
                "noemote"       : 1,
                "msgcolor"      : NOR HIW,
        ]),
    }),
    ({
        FAMILY,
        "family",
        PLAYER,
        HIW"��"NOR"%T"NOR HIW"��"NOR,
        ([
                "msgcolor"      : NOR HIG,
                "subchannel"    : 1,
                "filter"        : (: $1->query_family() == (stringp($2) ? $2 : $2->query_family()) || wiz_level($1) > 1 :),
                "newtitle"      : (: (stringp($1) ? $1 : $1->query_family()) || "������":),
        ]),
    }),
    ({
        PARTY,
        "party",
        PLAYER,
        HIW"��"NOR"%T"NOR HIW"��"NOR,
        ([
                "msgcolor"      : NOR HIG,
                "subchannel"    : 1,
                "filter"        : (: $1->query_bunch() == (stringp($2) ? $2 : $2->query_bunch()) || wiz_level($1) > 1 :),
                "newtitle"      : (: (stringp($1) ? $1 : $1->query_bunch()) || "�ް���":),
        ]),
    }),
    ({
        STOCK,
        "stock",
        PLAYER,
        YEL "��"NOR HIY"��"NOR YEL"��" NOR HIY"��"NOR,
        ([
                "time"          : 1,
                "nameraw"       : 1,
                "msgcolor"      : NOR HIR,
        ]),
    }),
    ({
        AUC,
        "auc",
        PLAYER,
        BLU "��"NOR HIB"����" NOR BLU"��"NOR,
        ([
                "time"          : 1,
                "notalk"        : 1,
                "msgcolor"      : NOR HIY,
        ]),
    }),
    ({
    	COMBAT,
	"combat",
	PLAYER,
        HIR "��"NOR RED"ս"HIR"��" NOR HIR"��"NOR,
	([
	        "time"	        : 1,
	        "notalk"	: 1,
                "msgcolor"      : NOR HIR,
	]),
    }),
    ({
	SOS,
	"sos",
	PLAYER,
        HIG "��"NOR HIR"����" NOR HIG"��"NOR,
	([
	        "msgcolor"      : NOR HIR,
	        "nameraw"       : 1,
	]),
    }),
    ({
	GROUP,
	"gt",
	PLAYER,
	HIW"��"NOR WHT"%T"HIW"��"NOR,
	([
	        "msgcolor"      : NOR HIW,
	        "subchannel":	1,
                "filter"        : (: query_temp("battle/team_name", $1) == (stringp($2) ? $2 : query_temp("battle/team_name", $2)) || wiz_level($1) > 1 :),
                "newtitle"      : (: (stringp($1) ? $1 : query_temp("battle/team_name", $1)) || "�޶���":),
	]),
    }),
     ({
        SPORT,
	"sport",
	PLAYER,
	WHT "��"NOR HIW"��"NOR WHT"��" NOR HIW"��"NOR,
	([
	        "msgcolor"      : NOR HIW,
	        "time"	:	1,
	        "notalk"	:	0,
	]),
    }),
});

nosave mapping replace_word = ([
        "������":       "******",
        "���":         "******",
        "��ı�":       "******",
        "�����":       "******",
        "��ĸ���":     "******",
        "������":       "******",
        "ɵ��":         "******",
]);

int valid_channel(int level, string channel)
{
        foreach(string *data in info)
        {
                if( data[1] == channel && level >= atoi(data[2]) )
                        return 1;
        }

        return 0;
}

varargs int do_channel(object me, string channel, string msg, mixed raw)
{
        int t,emote,internal_flag,name_raw;
        object *fit_users;
        class channel_class ch;
        string channel_title, idname, send_msg, time, my_id, my_idname, color, subchannel;
        string lfn;
        mixed lt;

        if( !channel || channel == "" || !me ) return 0;

        if( query("chblk_on", me) )
                return notify_fail("�������Ƶ�����ر��ˣ�Ψһ�İ취���������������ͶƱ��ͨ��\n");

        if( me->is_chatter() )
                return notify_fail("�������Ŀǰ����ʹ�ø���Ƶ����\n");

        if( userp(me) && me->ban_say(1) ) return 0;

        // ����Ƿ�Ϊ����ָ��
        if( channel[<1] == '*' ) { emote = 1; channel = channel[0..<2]; }

        if( sscanf(channel, "gwiz-%s", subchannel) ) channel = "gwiz";

        if( !classp(ch = channels[channel]) ) return 0;

        // player broadcasting need consume jing
        if( userp(me) && !wizardp(me) && channel == "rumor" &&
            !objectp(present("rumor generator", me)) )
                if( query("jing", me)>50 )
                        me->add("jing",-random(36));
                else
                        return notify_fail("���Ѿ�û����ɢ��ҥ���ˣ�\n");

        if( query("doing", me) == "scheme"){
                if( query("jing", me)<100 )
                        return notify_fail("�����ڵľ��񲻼ã���һ����ɡ�\n");
                addn("jing", -50, me);
        }

        if( channel == "family" && interactive(me) && !wizardp(me) && !query("family", me) )
                return notify_fail(pnoun(2, me)+"��δ�����κ����ɡ�\n");

        if( channel == "party" && interactive(me) && !wizardp(me) && !query("bunch", me) )
                return notify_fail(pnoun(2, me)+"��δ�����κΰ��ɡ�\n");

        if( channel == "tch" && interactive(me) && !wizardp(me) && !query("viremploy", me) )
                return notify_fail(pnoun(2, me)+"�������ֵ�ʦ���޷�ʹ�ø�Ƶ����\n");

        my_id = me->query_id(1); // ������ɫ
        name_raw = ch->extra["nameraw"];
        my_idname = me->query_idname(name_raw); // �Ƿ��װ�˱���

        // ������Ƶ�����, �������Ƶ������
        if( ch->extra["subchannel"] )
                if( msg && sscanf(msg, "[%s] %s", subchannel, msg) ) internal_flag=1;
        // ��鱾Ƶ��֮�����滻Ƶ����
        if( ch->extra["newtitle"] )
        {

                channel_title = replace_string(ch->msg, "%T", evaluate(ch->extra["newtitle"], stringp(raw) ? raw : (wizardp(me)||previous_object(1)==find_object(INTERMUD2_D)) ? subchannel || me : me));
        }
        else
                channel_title = ch->msg;

        // ������ʹ����, ����Ƶ��ע��
        if( interactive(me) && !(ch->number & users[me]) )
        {
                if( wiz_level(my_id) < ch->level ) return 0;

                users[me] |= ch->number;
                set("channels", query("channels",me) | ch->number, me);
                tell(me, "���� "+channel_title+" Ƶ����\n");

                if( !msg ) return 1;
        }

        // ��û������ѶϢ
        msg = msg || (emote ? "����������ḻ��" : "..." );

        // ���ID, NAME
        idname = my_idname || query("channel_id", me) || "NO_IDNAME";
        if( channel == "rumor" && idname == "NO_IDNAME" ) idname = "";

        // ���������ʹ�ñ�Ƶ����Ƶ��ʹ����
        fit_users = keys(filter(users, (: $(ch->number) & $2 :)));
        fit_users -= ({ 0 });

        // ��鱾Ƶ����ʹ��֮��������
        if( ch->extra["filter"] )
        {
                if( sizeof(fit_users) )
                        fit_users = filter(fit_users, ch->extra["filter"], stringp(raw) ? raw : (wiz_level(me) > 1 ? subchannel || me : me));
        }


        // ����Ƶ������ʾʱ����
        if( ch->extra["time"] == 1 )
                time = HIW+ctime(time())[11..15]+NOR" ";
        else if( ch->extra["time"] == 2 )
                time = HIW+ctime(TIME_D->query_game_time())[11..15]+NOR" ";
        else
                time = "";

        // ��ʹ�ñ���ģʽ
        if( emote )
        {
                string verb, arg;
                if( ch->extra["noemote"] )
                        return notify_fail("���Ƶ����֧�ֱ��鶯�ʡ�\n");
                verb = msg;
                sscanf(msg, "%s %s", verb, arg);

                if( EMOTE_D->is_emote(verb) )
                        msg = EMOTE_D->do_emote(me, verb, arg, 1) || (idname + msg);
                else
                        msg = idname + msg;
        }

        // ����Ƶ�����趨�ض�ѶϢ��ɫ
        if( ch->extra["msgcolor"] )
        {
                color = ch->extra["msgcolor"];
/*
                msg = remove_ansi(msg);
                idname = remove_ansi(idname);
*/
        }
        else
                color = "";

        // ����ϴӫĻ����Ϊ
        if( undefinedp(raw) && previous_object() != this_object() && me->is_character() )
        {
                int nowtime = time();

                if( nowtime - query_temp("lastchat/time", me) < 1 )
                {
                        if( addn_temp("lastchat/warning", 1, me) > 100 )
                        {
                                tell(me, "����"+pnoun(2, me)+"�����ظ����Բ��Ϸ���Ƶ�����Զ��������������Զ�����"+pnoun(2, me)+"��ָ��ܡ�\n");
                                set("cmdlimit", 30, me);
                                CHANNEL_D->channel_broadcast("sys", me->query_idname()+"�����ظ����Բ��Ϸ���Ƶ�����Զ��������������Զ�����ָ���ٶȡ�\n");
                        }
                        return notify_fail("����Ƶ��������������ѶϢ��\n");
                }
                if( query_temp("lastchat/msg", me) == msg && nowtime - query_temp("lastchat/time", me) < 300 )
                {
                        if( addn_temp("lastchat/repeattimes", 1, me) > 5 )
                        {
                                if( addn_temp("lastchat/warning", 1, me) > 100 )
                                {
                                        tell(me, "����"+pnoun(2, me)+"�����ظ����Բ��Ϸ���Ƶ�����Զ��������������Զ�����"+pnoun(2, me)+"��ָ��ܡ�\n");
                                        set("cmdlimit", 30, me);
                                        CHANNEL_D->channel_broadcast("sys", me->query_idname()+"�����ظ����Բ��Ϸ���Ƶ�����Զ��������������Զ�����ָ���ٶȡ�\n");
                                }
                                return notify_fail("����Ƶ����������������ͬѶϢ��\n");
                        }
                }
                else
                {
                        set_temp("lastchat/msg", msg, me);
                        delete_temp("lastchat/repeattimes", me);
                }

                set_temp("lastchat/time", nowtime, me);
        }
        // ����޷��� News Ƶ������
        if( ch->extra["notalk"] )
        {
                if( !wizardp(me) && interactive(me) )
                {
                        return notify_fail("����޷�ʹ�����Ƶ�����ԡ�\n");
                }
        }
        // ��������Ƶ��
        if( ch->extra["intermud"] && interactive(me) )
        {
                string intermud_msg = msg;
                if( emote ) intermud_msg = replace_string(msg, my_idname, my_idname[0..<2] + "@NT)");

                if( channel == "gwiz" )
                        ch->extra["intermud"]->send_gwiz_msg(subchannel, capitalize(me->query_id(1)), me->query_name(), intermud_msg, emote);
                else
                if((!internal_flag && subchannel!="") || ( internal_flag && member_array(subchannel,keys(channels))==-1 ))
                        ch->extra["intermud"]->send_gchannel_msg(subchannel, capitalize(me->query_id(1)), me->query_name(), intermud_msg, emote);
                else         subchannel="վ��";
        }

        // ���д�ѶϢ������������, send_msg = Ƶ������ + ѶϢ
        if( !undefinedp(raw) || emote )
                send_msg = channel_title+time+color;
        else
                send_msg = channel_title+time+color+idname+"��"+color;


        // �������ִ�
        send_msg = send_msg + msg + NOR + (noansi_strlen(msg) > 0 && remove_ansi(msg)[<1] == '\n' ? "" : "\n");


        // replace string
        foreach(string a , string b in replace_word)
        send_msg=replace_string(send_msg,a,b);

        // replace ansi for %^RED%^
	//send_msg = replace_usa_ansi(send_msg);

        fit_users -= ({ 0 });
        // ʹ����Ȩ�޴���, �ȼ��ߵ���˵����ֱ����ʾ����
        if( ch->extra["wizlevel"] && me->is_character() )
        {
                int my_level = wiz_level(my_id);
                string level_send_msg;
                object *level_fit_users;

                level_fit_users = filter(fit_users, (: wizardp($1) && $(my_level) <= wiz_level($1) :));
                if( random(50) || wizardp(me) || !userp(me) )
                        switch(query("env/rumor", me))
                {
                case 1:
                        {
                                string random_idname;
                                object* fit_users_without_wiz = filter_array(fit_users, (: !wizardp($1) :));

                                if( !sizeof(fit_users_without_wiz) )
                                        random_idname = fit_users[random(sizeof(fit_users))]->query_idname();
                                else
                                        random_idname = fit_users_without_wiz[random(sizeof(fit_users_without_wiz))]->query_idname();

                                level_send_msg = replace_string(send_msg, my_idname, "["+my_idname+"]-��ð��" + random_idname );
                                send_msg = replace_string(send_msg, my_idname, "��ð��" + random_idname );
                                break;
                        }
                case 2:
                        {
                                if( undefinedp(query_temp("rumor_serial",me)) )
                                {
                                        water_number += 1 + random(50);
                                        set_temp("rumor_serial", water_number,me);
                                }
                                level_send_msg = replace_string(send_msg, my_idname, "["+my_idname+"]-"+(query("gender", me) == "����"?"Mr.":"Miss")+  query_temp("rumor_serial",me) );
                                send_msg = replace_string(send_msg, my_idname, (query("gender", me) == "����"?"Mr.":"Miss")+  query_temp("rumor_serial",me));

                                break;
                        }
                default:
                        level_send_msg = replace_string(send_msg, my_idname, "["+my_idname+"]-ĳ��(Someone.)");
                        send_msg = replace_string(send_msg, my_idname, "ĳ��(Someone.)");
                        break;
                }
                else
                {

                        level_send_msg = replace_string(send_msg, my_idname, "["+my_idname+"]-�����"+my_idname);
                        send_msg = replace_string(send_msg, my_idname, "�����"+my_idname);
                }

                fit_users -= level_fit_users;

                // Ȩ���㹻֮ʹ����
                //tell(level_fit_users, level_send_msg, CHNMSG);
                tell(level_fit_users, level_send_msg, "channel:"+channel); // ֧��tomud

                level_fit_users->add_msg_log(channel, level_send_msg);
                SPECIAL_NPC->receive_report(me, channel);
        }

        //tell(fit_users, send_msg, CHNMSG);
        tell(fit_users, send_msg, "channel:"+channel); // ֧��tomud

        if( userp(me) && random(100) < 20 )
        {
                addn("active", 1, me);
                tell_object(me, HIY "\n��������ӻԾ������Ц�������������磬�ر�Ϊ�����ӻ�Ծֵһ�㡣\n" NOR);
        }

        fit_users->add_msg_log(channel, send_msg);

        if( arrayp(ch->extra["listener"]) )
        {
                ch->extra["listener"] -= ({ 0 });
                if( sizeof(ch->extra["listener"]) )
                        ch->extra["listener"]->relay_channel(me, channel, msg);
        }

        switch(channel)
        {
        case "msg":
                break;
        case "chat":
        case "family":
        case "party":
        case "rumor":
        case "war":
        case "gwiz":
        case "sos":
        case "wiz":
                if( !stringp(msg_log) ) msg_log = "";

                t = time();
                msg_log += sprintf(" %s\n%s",
                                log_time(),filter_color(send_msg));
                if( strlen(msg_log) > 8000 || t - log_from > 900 ) {
                        lt = localtime(t);

                        lfn = sprintf("channel/%d-%d-%d", lt[LT_YEAR],
                              lt[LT_MON] + 1, lt[LT_MDAY]);
                        assure_file(LOG_DIR + lfn);
                        log_file(lfn, msg_log);
                        msg_log = "";
                        log_from = t;
                }
                break;
        default:
                break;
        }
        return 1;
}

void register_relay_channel(string channel)
{
        class channel_class ch;
        object ob;
        ob = previous_object();
        ch = new(class channel_class);

        if( undefinedp(channels[channel]) || !ob )
                return;
        if( !classp(ch = channels[channel]) )
                return;

        if( arrayp(ch->extra["listener"]) ) {
                if( member_array(ob, ch->extra["listener"]) >= 0 )
                        return;
                ch->extra["listener"] += ({ ob });
        }
        else    ch->extra["listener"] = ({ ob });
}

/* ע��Ƶ�� */
nomask void register_channel(object me, int channel)
{
        if( !channel ) return;
        if( undefinedp(users[me]) ) users[me] = channel;
        else users[me] |= channel;
}

/* �Ƴ�ע�� */
nomask void remove_register(object me, int channel)
{
        if( !channel ) return;
        users[me] ^= channel;
        if( users[me] == 0 ) map_delete(users, me);
}

/* ֱ���Ƴ�һλʹ���� */
nomask void remove_user(object me)
{
        map_delete(users, me);
}

/* �����������ע��Ƶ�� */
nomask void reset_all_register()
{
        users = allocate_mapping(0);
        filter_array( users(), (: register_channel($1, query("channels",$1)) :) );
}

nomask varargs string *query_channel_users(string channel, int flag)
{
        class channel_class ch;
        string *res = allocate(0);

        if( undefinedp(ch = channels[channel]) ) return res;
        foreach(object ob, int i in users)
        {
                if( !flag && (i & ch->number) ) res += ({ ob });
                if( flag && !(i & ch->number) ) res += ({ ob });
        }
        return res;
}

nomask int query_default_channel(string id)
{
        int default_channel=0, level = wiz_level(id);
        foreach( string name, class channel_class ch in channels )
        {
                if( level < ch->level ) continue;
                default_channel |= ch->number;
        }
        return default_channel &~ DEFAULT_REFUSE;
}

nomask varargs mixed query_using_channel(object user, int flag)
{
        int channel = users[user];
        string using_channel = "";
        string *using_ch = ({});

        if( channel )
                foreach( string name, class channel_class ch in channels )
                if( channel & ch->number )
                {
                        if( flag ) using_ch += ({ name });
                        else using_channel += " "+name;
                }

        if( flag ) return using_ch;
        return using_channel == "" ? "��" : using_channel;
}

varargs void channel_broadcast(string channel, string msg, mixed arg)
{
        switch(channel)
        {
        case "family":
                msg = NOR GRN"����"+HIG+"���� "NOR+msg; break;
        case "party":
                msg = NOR CYN"����"+HIC+"���� "NOR+msg; break;
        default: break;
        }

        if( undefinedp(arg) )
                do_channel(this_object(), channel, msg, 1);
        else if( objectp(arg) )
                do_channel(arg, channel, msg, 1);
        else
                do_channel(this_object(),channel, msg, arg);

}

varargs void announce(object me, string msg)
{
        shout("\n\a"HIR + (objectp(me) ? me->query_idname() + HIR"����":"") + "ϵͳ���� ("HIW + ctime(time()) + NOR + HIR")��\n\n"NOR + msg + NOR"\n\n");
}


void create()
{
        class channel_class ch;

        if( clonep() ) destruct(this_object());

        seteuid(getuid());
        set("channel_id", "Ƶ������");

        channels = allocate_mapping(0);
        users = allocate_mapping(0);
        water_number = 10000;
        foreach( mixed *c in info )
        {
                ch = new(class channel_class);
                ch->number     = atoi(c[0]);
                ch->level      = atoi(c[2]);
                ch->msg        = c[3];
                ch->extra      = c[4];
                channels[c[1]] = ch;
        }
        reset_all_register();

}


string query_name()
{
        return "Ƶ��ϵͳ(CHANNEL_D)";
}
