  // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
ɽ·���ۣ�һ·���ɡ���ʯ���������������ֻ��һ��ƽ̹�ľ�ʯ��ǰͻ
�����γ�һ��������յ�Σ�ң��Ա�ɢ�����һЩʯ�飬���˶�������ۿ��ճ���
�����⿴�����ƺ�������Ľ������ʣ�¶���ƺ�ɽͷǡ�������ɵ�����Լ�ɼ�һ��
����¥���ɽ�����ɹְأ��е�����ӥ�����չ�ᣬ�е�����Ů��ͤͤ��������
��ʤ�ա�
LONG
        );
    set("exits", ([
                "southwest" : __DIR__"diezhang",
                "northwest" : __DIR__"feilong",
                "westup" : __DIR__"qingliangf",	
                "east" : __DIR__"shizi",
        ]));
    set("outdoors", "huangshan");
        set("coor/x",-630);
    set("coor/y",-510);
        set("coor/z",30);
        setup();
} 
void init() {
    add_action("do_sitdown", "sitdown");
    add_action("do_standup", "standup");
} 
int do_standup(){
    object me;
    me = this_player();
    if(me->is_busy()) {
        return notify_fail("������æ��\n");
    }
    if(me->is_fight()) {
        return 0;
    }
    if(!me->query_temp("watch_sunrise")) {
        return 0;
    }
    me->set_temp("watch_sunrise", 0);
    message_vision("$Nվ��������\n", me);
    return 1;
} 
int do_sitdown(string arg) {
        object me, who;
        mixed *local;
        int dayTime, j; 
        me = this_player();
        if(me->is_busy()) {
                return notify_fail("������æ!\n");
        }
        if(me->is_fight()) {
                return notify_fail("ս���������飬������\n");
        } 
    if(me->query_temp("watch_sunrise")) {
        return notify_fail("���Ѿ�������ѽ��\n");
    }
    message_vision("$N���˿�ʯͷ����������������\n", me);
    me->set_temp("watch_sunrise", 1);
    if(random(2)==0) {
            return notify_fail("ɽ�����µĿ������㾫��һ��\n");
        } else {
                //local = NATURE_D->get_current_time();
                dayTime = random(1200);
                if(dayTime < 240) {
                return notify_fail("����һƬ��ڣ�������ž���ҹ�ж������š�\n");
                } else if (dayTime > 1080) {
                return notify_fail("��ʱ�����ĳ�������ڼž���ҹ�д�����Զ��\n");
                } else if (dayTime > 290 && dayTime < 360) {
                    return notify_fail("��ɫ��΢�������紵������ȫ����\n");
                } else {
                    tell_object(me, "ɽ�У��ž���ҹ������һ����ζ����ͷ��\n");
                    remove_call_out("sun_rise");
                    call_out("sun_rise", 300 - dayTime, random(2), 0);
            }
        }
        return 1;
} 
void sun_rise(int sunrise, int sunrise_stage) {
    object *inv, *watchers;
    int i, j; 
    remove_call_out("sun_rise");
        inv = all_inventory();
        watchers = filter_array(inv, (: interactive($1) && $1->query_temp("watch_sunrise") :));
    if(sunrise_stage == 0 && random(10) > 2) {
        message("vision", HIW"����һƬ����ãã����ʲôҲ���������\n"NOR, watchers);
    } else if(sunrise == 0) {
        switch(sunrise_stage) {
            case 0:
                message("vision", RED"\nһ���ɫ�Ĺ�â������ɽ������������ʱ����ҫ�ۣ����к�ǿ����Ⱦ����\n"NOR, watchers);
                message("vision", RED"ɽ�͵Ķ�������Ⱦ�ɺ�ɫ�� \n\n"NOR, watchers);
                        call_out("sun_rise", 5, 0, 1);
                break;
            case 1:
                message("vision", HIR"\n�ۺ�ɫ��̫�������Ĵ�ɽ�ͺ�����ɽ�Ⱥ�Ȼ����������\n"NOR, watchers);
                message("vision", HIR"���������ֵ�ɽ��ֹ�˽�����һȺȺ����Զ�������ڳ��������һ����鶯��ԶӰ��\n"NOR, watchers);
                call_out("sun_rise", 5, 0, 2);
                break;
            case 2:
                message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), watchers);
                message("vision", HIY"\n̫������Ծ���ڷ���֮�ϣ����ﶼ��������һ�㵭���Ľ�ɫ�� \n"NOR, watchers);
                j = random(12);
                if (j == 1) {
                    message("vision", HIR"\n��ɽ���Ķž黨Ҳ�����˵����Ľ�ɫ������ϼ���������������ʵ���ɫ��\n"NOR, watchers);
                    message("vision", HIR"����ʧ������ʵ������\n"NOR, watchers);
                    for(i=0; i<sizeof(watchers); i++) {
                        if (!watchers[i]->query("����B/��ɽ_�ճ�")) {
                                watchers[i]->set("����B/��ɽ_�ճ�",1+random(10));
                        }
                        message_vision("$N����վ��������\n", watchers[i]);
                        watchers[i]->set_temp("watch_sunrise", 0);
                    }
                } else {
                    for(i=0; i<sizeof(watchers); i++) {
                        message_vision("$N����վ��������\n", watchers[i]);
                        watchers[i]->set_temp("watch_sunrise", 0);
                    }
                }
                break;
                default:
                        return notify_fail("something wrong\n");
        }
    } else {
        switch(sunrise_stage) {
            case 0:
                message("vision", RED"\nãã�������õĴ󺣰��̿�������Զ�����������ĵط���ǳǳ��͸��õ����ɫ��\n"NOR, watchers);
                message("vision", RED"��ɫ�������죬���ܽ����ɢ������ \n"NOR, watchers);
                call_out("sun_rise", 5, 1, 1);
                break;
            case 1:
                message("vision", HIR"\n���õĺ�ϼ�ϣ�����������һ�ߺ�����Բ����ɲʱ���ƺ���Ⱦ�����һƬ�貵�\n"NOR, watchers);
                message("vision", HIR"��졣�Ƴ��������������ɴ�������\n"NOR, watchers);
                call_out("sun_rise", 5, 1, 2);
                break;
            case 2:
                message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), watchers);
                message("vision", HIR"\nһ�ֺ��ո�����������õ��ƺ��ϣ����ν���ƽϢ������ʱ�任����죬ǳ�죬�ۺ��ɫ�ʡ�\n"NOR, watchers);
                message("vision", HIR"������ɢȥ��������ϼ��׺����ʡ�\n"NOR, watchers);
                j = random(12);
                if (j == 4) {
                    message("vision", HIR"\n�����ɫ��ӳ��ɽ�ϰ�ɫ�Ļ�ѩ����һ��˵�����Ĵ������������\n"NOR, watchers);
                    for(i=0; i<sizeof(watchers); i++) {
                        if (!watchers[i]->query("����B/��ɽ_�ճ�")) {
                                watchers[i]->set("����B/��ɽ_�ճ�", 1+random(10));
                        }
                        message_vision("\n$N����վ��������\n", watchers[i]);
                        watchers[i]->set_temp("watch_sunrise", 0);
                    }
                } else {
                    for(i=0; i<sizeof(watchers); i++) {
                        message_vision("\n$N����վ��������\n", watchers[i]);
                        watchers[i]->delete_temp("watch_sunrise");
                    }
                }
                break;
                default:
                        return notify_fail("something wrong.\n");
        }
    }
} 
int valid_leave(object who,string dir) {
        if(who->query_temp("watch_sunrise")) {
                return notify_fail("���������أ������뿪����\n");
        }
        return 1;
}      
